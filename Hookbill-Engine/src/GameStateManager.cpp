#include <GameState.h>
#include "GameStateManager.h"
#include "ImGuiHelper.h"
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
            break;

        case State::LOAD:
            currGameState = nextGameState;
            HOOKBILL_DEBUG("Load" + currGameState->GetName());
            state = State::UPDATE;
            break;

        case State::UPDATE:
            if (currGameState != nextGameState)
            {
                HOOKBILL_DEBUG("Update" + currGameState->GetName());
                state = State::UNLOAD;
            }

            ImGuiHelper::Begin();
            //ImGui::ShowDemoWindow();
            currGameState->Update();
            currGameState->Draw();
            currGameState->ImGuiDraw();
            ImGuiHelper::End();
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