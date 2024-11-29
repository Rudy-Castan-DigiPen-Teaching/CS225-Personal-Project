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

  Viewport Begin()
  {
    HOOKBILL_ERROR("Begin");
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
   
      {
            const ImGuiDockNodeFlags   dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode | ImGuiDockNodeFlags_NoDockingInCentralNode;
            const ImGuiWindowFlags     window_flags    = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
            const ImGuiViewport* const main_viewport   = ImGui::GetMainViewport();
            const auto                 window_position = main_viewport->Pos;
            const auto                 window_size     = main_viewport->Size;
            ImGui::SetNextWindowPos(window_position);
            ImGui::SetNextWindowSize(window_size);
            ImGui::SetNextWindowViewport(main_viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
            ImGui::Begin("Main Window Dockspace", nullptr, window_flags);
            ImGui::PopStyleVar();
            ImGui::PopStyleVar(2);
            const ImGuiID dockspace_id = ImGui::GetID("Main Window Dockspace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

            // How to get central area : https://github.com/ocornut/imgui/issues/5921#issuecomment-1327801959
            // Central Node is the middle area where we want the main display to be
            const ImGuiDockNode* const node = ImGui::DockBuilderGetCentralNode(dockspace_id);
            if (node == nullptr) [[unlikely]]
                return Viewport{ 0, 0, static_cast<int>(window_size.x), static_cast<int>(window_size.y) };
            // the central node's position is relative to the monitor, so we need main viewport to turn relative to the window
            const int opengl_x = static_cast<int>((node->Pos.x - window_position.x) * static_cast<float>(environment::HorizontalDPIScale));                                  // convert relative to window x
            const int opengl_y = static_cast<int>((window_size.y - ((node->Pos.y - window_position.y) + node->Size.y)) * static_cast<float>(environment::VerticalDPIScale)); // convert relative to window x and then convert to opengl convention where 0,0 is bottom left
            const int opengl_w = static_cast<int>(node->Size.x * static_cast<float>(environment::HorizontalDPIScale));                                                       // width of central node is what we want
            const int opengl_h = static_cast<int>(node->Size.y * static_cast<float>(environment::VerticalDPIScale));                                                         // height of central node is what we want
            ImGui::End();                                                                                                                                                    // end main window docking
            return Viewport{ opengl_x, opengl_y, opengl_w, opengl_h };
        }


  }

  void End()
  {
    HOOKBILL_ERROR("End");
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }

}
