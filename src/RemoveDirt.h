#pragma once

#include <emmintrin.h>
#include <vapoursynth/VSHelper.h>
#include <vapoursynth/VapourSynth.h>

#if defined(_MSC_VER)
#define _ALLOW_KEYWORD_MACROS
#define alignas(x) __declspec(align(x))
#define ALIGNED_ARRAY(decl, alignment) alignas(alignment) decl
#else
#define __forceinline inline
#define ALIGNED_ARRAY(decl, alignment) __attribute__((aligned(16))) decl
#endif

struct MotionDetectionData {
  uint8_t ALIGNED_ARRAY(noiselevel, 16)[16];
  uint8_t *blockproperties_addr;
  uint32_t threshold;
  int32_t pline;
  int32_t nline;
  int32_t motionblocks;
  uint8_t *blockproperties;
  int32_t linewidth;
  int32_t hblocks;
  int32_t vblocks;
  int32_t hblocksSSE2;
  bool remainderSSE2;
  int32_t linewidthSSE2;
  uint32_t (*blockcompare)(const uint8_t *p1, int32_t pitch1, const uint8_t *p2, int32_t pitch2, const uint8_t *noiselevel);
  void (*blockcompareSSE2)(const uint8_t *p1, const uint8_t *p2, int32_t pitch, const uint8_t *noiselevel);
};

struct MotionDetectionDistData {
  int32_t distblocks;
  uint32_t blocks;
  uint32_t tolerance;
  uint32_t *isum;
  int32_t dist;
  int32_t dist1;
  int32_t dist2;
  int32_t hint32_terior;
  int32_t vint32_terior;
  int32_t colinc;
  int32_t isumline;
  int32_t isuminc1;
  int32_t isuminc2;
  void (*processneighbours)(MotionDetectionDistData *);
  MotionDetectionData md;
};

struct PostProcessingData {
  int32_t linewidthUV;
  int32_t chromaheight;
  int32_t chromaheightm;
  int32_t pthreshold;
  int32_t cthreshold;
  int32_t loops;
  int32_t restored_blocks;
  int32_t (*vertical_diff_chroma)(const uint8_t *u, const uint8_t *v, int32_t pitch, const uint8_t *noiselevel);
  MotionDetectionDistData mdd;
};

struct RemoveDirtData {
  bool grey;
  bool show;
  PostProcessingData pp;
};

struct DupBlocksData {
  VSNodeRef *input;
  VSFrameRef *lf;
  const VSVideoInfo *vi;
  int32_t mthreshold;
  int32_t lfnr;
  RemoveDirtData rd;
};

// SCselect.cpp
void VS_CC SCSelectCreate(const VSMap *in, VSMap *out, void *userData, VSCore *core, const VSAPI *vsapi);

// RestoreMotionBlocks.cpp
void VS_CC RestoreMotionBlocksCreate(const VSMap *in, VSMap *out, void *userData, VSCore *core, const VSAPI *vsapi);

// DupBlocks.cpp
void VS_CC DupBlocksCreate(const VSMap *in, VSMap *out, void *userData, VSCore *core, const VSAPI *vsapi);

// utils.cpp
uint32_t gdiff(const uint8_t *sp1, int32_t spitch1, const uint8_t *sp2, int32_t spitch2, int32_t hblocks, int32_t incpitch, int32_t height);
void copyChroma(VSFrameRef *dest, const VSFrameRef *source, const VSVideoInfo *vi, const VSAPI *vsapi);

//RemoveDirtAVS.cpp
int32_t RemoveDirtProcessFrame(RemoveDirtData *rd, VSFrameRef *dest, const VSFrameRef *src, const VSFrameRef *previous, const VSFrameRef *next, const VSAPI *vsapi, const VSVideoInfo *vi);
void FillRemoveDirt(RemoveDirtData *rd, const VSMap *in, VSMap *out, const VSAPI *vsapi, const VSVideoInfo *vi);