#pragma once

namespace environment
{
    inline int                FPS                = 0;
    inline unsigned long long FrameCount         = 0;
    inline double             DeltaTime          = 0; // seconds
    inline double             ElapsedTime        = 0; // seconds
    inline int                WindowWidth        = 0;
    inline int                WindowHeight       = 0;
    inline int                DisplayWidth       = 0;
    inline int                DisplayHeight      = 0;
    inline double             HorizontalDPIScale = 1.0;
    inline double             VerticalDPIScale   = 1.0;

#if !defined(__EMSCRIPTEN__) || defined(__EMSCRIPTEN_PTHREADS__)
#    define CAN_USE_THREADS
    constexpr bool CanUseThreads = true;
#else
    constexpr bool CanUseThreads = false;
#endif
}