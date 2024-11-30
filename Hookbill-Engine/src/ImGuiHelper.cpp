#include "ImGuiHelper.h"
#include<Environment.hpp>
#include<imgui.h>
#include<backends/imgui_impl_glfw.h>
#include<backends/imgui_impl_opengl3.h>
#include<imgui_internal.h>

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
      ImGui_ImplOpenGL3_Init("#version 460");
     HOOKBILL_ERROR("Is this code excute?");
  }

  void Begin()
  {
    HOOKBILL_ERROR("Begin");
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    
   
   
  }

  void End()
  {
    HOOKBILL_ERROR("End");
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }

}
