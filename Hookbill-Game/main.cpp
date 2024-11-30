#include "Hookbill.h"
#include <iostream>

int main()
{
  HookBill::Engine &instance = HookBill::Engine::Instance();
  instance.Init("Im NooB",1920,1080);
  while (!instance.HasGameEnded())
  {
    instance.update();
  }
}
