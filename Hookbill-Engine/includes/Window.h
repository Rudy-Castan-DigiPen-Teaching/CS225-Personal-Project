#pragma once
#include "Core.h"
#include"Logger.h"
 class GLFWwindow;

    class HOOKBILL_API Window
    {
       public:
       void Init(std::string windowName,size_t width, size_t height);
       void Update();
       private:
       void Setup_OPENGL_window(std::string windowName, size_t width, size_t height);
       void Setup_ImGui();




       GLFWwindow*window;   
     
    };
