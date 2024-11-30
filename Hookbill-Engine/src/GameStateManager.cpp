#include <GameState.h>
#include "GameStateManager.h"
#include "ImGuiHelper.h"
#include<GLFW/glfw3.h>
#include"Engine.h"
namespace HookBill
{
      
    GameStateManager::GameStateManager()
    {
        state = State::START;
        currGameState = nullptr;
        nextGameState = nullptr;
       
    }

    void GameStateManager::AddGameState(GameState &gameState)
    {
        gameStates.push_back(&gameState);
    }

    void GameStateManager::Update()
    {
        switch (state)
        {
        case State::START:
            if (gameStates.empty() == true)
            {
                HOOKBILL_ERROR("There is no Level !!");
                state = State::SHUTDOWN;
            }
            nextGameState = gameStates[0];
            state = State::LOAD;
           
            break;

        case State::LOAD:
            currGameState = nextGameState;
            HOOKBILL_DEBUG("Load" + currGameState->GetName());
            state = State::UPDATE;
            break;

        case State::UPDATE:
             ImGuiHelper::Begin();
            if (currGameState != nextGameState)
            {
                HOOKBILL_DEBUG("Update" + currGameState->GetName());
                state = State::UNLOAD;
            }

            // Create a window called "My First Tool", with a menu bar.
             glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
             glClear(GL_COLOR_BUFFER_BIT);
             currGameState->Update();
             currGameState->Draw();
             currGameState->ImGuiDraw();
             
       
            ImGui::Begin("Simple Menu");
            ImGui::Text("Welcome to the Simple ImGui Menu!");
            ImGui::End();
            ImGuiHelper::End(Engine::GetWindow().window);
           
            break;

        case State::UNLOAD:
            HOOKBILL_INFO("Unload" + currGameState->GetName());
            currGameState->Unload();
            if (nextGameState == nullptr)
            {
                state = State::SHUTDOWN;
            }
            else
            {
                state = State::LOAD;
            }
            break;

        case State::SHUTDOWN:
            state = State::EXIT;
           
            break;

        case State::EXIT:
            break;
        }
    }

    void GameStateManager::SetNextState(int initState)
    {
        nextGameState = gameStates[initState];
    }

    void GameStateManager::ShutDown()
    {
        nextGameState = nullptr;
    }

    void GameStateManager::ReloadState()
    {
        state = State::UNLOAD;
    }

}