//
//  transition.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 20/12/2020.
//

#include "transition.hpp"

Transition::Transition(const std::string& currentState, const char read, const char write, const char command, const std::string& nextState) {
    this->currentState = currentState;
    this->read = read;
    this->write = write;
    this->command = command;
    this->nextState = nextState;
}

Transition::Transition(const Transition& other) {
    this->currentState = other.currentState;
    this->read = other.read;
    this->write = other.write;
    this->command = other.command;
    this->nextState = other.nextState;
}

char Transition::getReadSymbol() const {
    return read;
}

char Transition::getWriteSymbol() const {
    return write;
}

char Transition::getCommand() const {
    return command;
}

std::string Transition::getCurrentState() const {
    return currentState;
}

std::string Transition::getNextState() const {
    return nextState;
}

std::ostream& operator<<(std::ostream& out, Transition &transition) {
    out << transition.read << "{" << transition.currentState << "} -> " << transition.write << "{" << transition.nextState << "}" << transition.command << std::endl;
    return out;
}
