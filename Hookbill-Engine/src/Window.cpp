#include "Window.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ImGuiHelper.h"


    void Window::Init(std::string windowName, size_t width, size_t height)
    {
      Setup_OPENGL_window( windowName,width,height);
      ImGuiHelper::Initialize();
    }

    void Window::Update()
    {        
       
        ImGuiHelper::Begin();

        ImGuiHelper::End();


    }
    

    void Window::Setup_OPENGL_window(std::string windowName, size_t width, size_t height)
    {

    glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // glfw window creation
        window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
        if (window == NULL)
        {
            HOOKBILL_ERROR("Failed to create GLFW window");
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);
        if (glewInit() != GLEW_OK)
        {
            HOOKBILL_ERROR("GLEW initialization Failed!");
            glfwTerminate();
        }
    }


    void Window::Setup_ImGui()
    {
        //ImGuiHelper::Initialize(window);
    }


