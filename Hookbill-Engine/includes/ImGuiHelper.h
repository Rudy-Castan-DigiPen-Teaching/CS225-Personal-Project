#pragma once
#include <core.h>
#include <Logger.h>

class GLFWwindow;

    namespace ImGuiHelper
    {
        void  Initialize(GLFWwindow*window);
         
        void  Begin();
        void  End();

    }
