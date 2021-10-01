#include "RemoveDirt.h"

VS_EXTERNAL_API(void)
VapourSynthPluginInit(VSConfigPlugin configFunc, VSRegisterFunction registerFunc, VSPlugin *plugin) {
  configFunc("dev.setsugen.vsremovedirt", "rdvs", "RemoveDirt VapourSynth Port", VAPOURSYNTH_API_VERSION, 1, plugin);
  registerFunc(
    "SCSelect",
    "input:clip;"
    "sceneBegin:clip;"
    "sceneEnd:clip;"
    "globalMotion:clip;"
    "dfactor:float:opt;",
    SCSelectCreate, 0, plugin
  );
  registerFunc(
    "RestoreMotionBlocks",
    "input:clip;"
    "restore:clip;"
    "neighbour:clip:opt;"
    "neighbour2:clip:opt;"
    "alternative:clip:opt;"
    "gmthreshold:int:opt;"
    "mthreshold:int:opt;"
    "noise:int:opt;"
    "noisy:int:opt;"
    "dist:int:opt;"
    "tolerance:int:opt;"
    "dmode:int:opt;"
    "pthreshold:int:opt;"
    "cthreshold:int:opt;"
    "grey:int:opt;",
    RestoreMotionBlocksCreate, 0, plugin
  );
  registerFunc(
    "DupBlocks",
    "input:clip;"
    "gmthreshold:int:opt;"
    "mthreshold:int:opt;"
    "noise:int:opt;"
    "noisy:int:opt;"
    "dist:int:opt;"
    "tolerance:int:opt;"
    "dmode:int:opt;"
    "pthreshold:int:opt;"
    "cthreshold:int:opt;"
    "grey:int:opt;",
    DupBlocksCreate, 0, plugin
  );
}
