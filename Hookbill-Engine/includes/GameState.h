#pragma once
#include <core.h>
#include <string>
namespace HookBill
{
    class HOOKBILL_API GameState
    {
    public:
        virtual void Load()   = 0;
        virtual void Update() = 0;
        virtual void Draw()   = 0;
        virtual void ImGuiDraw()=0;
        virtual void Unload() = 0;
        virtual std::string GetName() = 0;
    };

}