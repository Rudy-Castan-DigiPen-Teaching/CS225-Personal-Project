#pragma once
#include <core.h>
#include <Logger.h>
#include<imgui.h>
struct GLFWwindow;
namespace ImGuiHelper
{

    struct Viewport
    {
        int x = 0, y = 0;
        int width = 0, height = 0;
        bool operator==(const Viewport &) const = default;
    };

    void HOOKBILL_API Initialize(GLFWwindow *window);
    void HOOKBILL_API Begin();
    void HOOKBILL_API End();

}
