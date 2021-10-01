# VapourSynth-removedirt

Port of RemoveDirt to Vapoursynth from [Avisynth](https://github.com/pinterf/RemoveDirt)

# Dependencies

No external deps!

# Usage

Please refer to Avisynth's [wiki](http://avisynth.nl/index.php/RemoveDirt)

# Compilation

I prefer doing it in VSCode, but

```bash
cmake --build ./build --config Release --target vsdpir -j 26 --
```

Keep in mind you'll have to set [VS_LIB_PATH](https://github.com/vapoursynth/vapoursynth) manually.