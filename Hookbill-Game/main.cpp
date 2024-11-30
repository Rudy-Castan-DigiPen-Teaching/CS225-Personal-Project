#include "Hookbill.h"
#include "TestLevel.h"
#include <iostream>

int main()
{
  HookBill::Splash splash;
  HookBill::Engine &instance = HookBill::Engine::Instance();
  instance.Init("Im NooB",1000,1080);

  instance.gameStateManager.AddGameState(splash);
  while (!instance.HasGameEnded())
  {
    instance.update();
  }
}
