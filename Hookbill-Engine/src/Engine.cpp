#include"Engine.h"
namespace HookBill
{
   void Engine::Init(std::string WindowName, size_t WindowWidth, size_t WindowHeight)
   {
     HOOKBILL_INFO("Initialize Engine");
     window_.Init(WindowName,WindowWidth,WindowHeight);
   }
   
   void Engine::Shutdown()
   {
    


   }

   void Engine::update()
   {
      gameStateManager.Update();
      window_.Update();
   }

   bool Engine::HasGameEnded()
   {
      return /*gameStateManager.HasGameEnded() ||*/ window_.ShouldCloseWindow();
   }
   



}
