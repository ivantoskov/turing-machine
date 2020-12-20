//
//  transition.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 20/12/2020.
//

#include "transition.hpp"

Transition::Transition(const std::string& currentState, const char read, const std::string& command, const std::string& nextState) {
    this->currentState = currentState;
    this->read = read;
    this->command = command;
    this->nextState = nextState;
}

Transition::Transition(const Transition& other) {
    this->currentState = other.currentState;
    this->read = other.read;
    this->command = other.command;
    this->nextState = other.nextState;
}

char Transition::getReadSymbol() const {
    return this->read;
}

std::string Transition::getCommand() const {
    return this->command;
}

std::string Transition::getCurrentState() const {
    return this->currentState;
}

std::string Transition::getNextState() const {
    return this->nextState;
}

std::ostream& operator<<(std::ostream& out, Transition &transition) {
    out << transition.read << "{" << transition.currentState << "} -> " << (char)(transition.read + 1) << "{" << transition.nextState << "}" << transition.command;
    return out;
}
