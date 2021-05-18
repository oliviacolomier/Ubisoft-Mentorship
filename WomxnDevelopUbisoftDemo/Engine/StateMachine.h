#pragma once
#include <memory>
#include <stack>
#include "State.h"


namespace state_space 
{
    typedef std::unique_ptr<State> StateRef;

    class StateMachine {
    public:
        StateMachine() { }
        ~StateMachine() { }

        void addState(StateRef newState, bool isReplacing = true);
        void removeState();
        // Run at start of each loop in Game.cpp
        void processStateChanges();

        StateRef& getActiveState();

    private:
        std::stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding, _isReplacing;
    };
}

