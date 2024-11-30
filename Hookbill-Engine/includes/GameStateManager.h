#pragma once
#include <core.h>
#include <Logger.h>
#include <vector>

namespace HookBill
{
    class GameState;

    class HOOKBILL_API GameStateManager
    {
    public:
        GameStateManager();

        void AddGameState(GameState &gameState);
        void Update();
        void SetNextState(int initState);
        void ShutDown();
        void ReloadState();
        bool HasGameEnded() { return (state == State::EXIT); }

    private:
        enum class State
        {
            START,
            LOAD,
            UPDATE,
            UNLOAD,
            SHUTDOWN,
            EXIT,
        };

        std::vector<GameState *> gameStates;
        State state;
        GameState *currGameState;
        GameState *nextGameState;
    };

}