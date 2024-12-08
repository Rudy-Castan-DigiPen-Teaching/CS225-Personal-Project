#include "ImGuiHelper.h"
#include<Environment.hpp>
#include<imgui.h>
#include<backends/imgui_impl_glfw.h>
#include<backends/imgui_impl_opengl3.h>
#include<imgui_internal.h>
#include<GLFW/glfw3.h>
namespace ImGuiHelper
{
  void Initialize(GLFWwindow *window)
  {
    HOOKBILL_ERROR("Initialize");
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    {
      ImGuiIO &io = ImGui::GetIO();
      io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
      io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    }
     ImGui_ImplGlfw_InitForOpenGL(window,true);
     ImGui_ImplOpenGL3_Init("#version 430");
     
  }

  void Begin()
  {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
   
  }

  void End(GLFWwindow*window)
  {
  
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    const ImGuiIO& io = ImGui::GetIO();
     if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(window);
        }
  }

}
