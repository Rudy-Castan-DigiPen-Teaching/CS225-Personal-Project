#include"core.h"
#include"logger.h"
#include "Window.h"
#include"GameStateManager.h"
namespace HookBill
{

    class HOOKBILL_API Engine
    {
        public:
        static Engine &Instance()
        {
            static Engine instance;
            return instance;
        }
        
        void Init(std::string windowName,size_t WindowWidth, size_t WindowHeight);
        static Window& GetWindow() { return Instance().window_; }
        void Shutdown();
        void update();
        bool HasGameEnded();
       
        Window window_;
        GameStateManager gameStateManager;

        private:
        Engine()
        {

        }
        ~Engine()
        {

        }

       
       
      
    };

}