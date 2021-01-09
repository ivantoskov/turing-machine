//
//  machine.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 20/12/2020.
//

#include "machine.hpp"

TuringMachine::TuringMachine() {
    this->currentState = "start";
}

TuringMachine::TuringMachine(const TuringMachine& other) {
    this->currentState = other.currentState;
    this->tape = other.tape;
    this->transitions = other.transitions;
}

void TuringMachine::addTape(Tape& tape) {
    this->tape = &tape;
}

void TuringMachine::addTransition(const Transition& transition) {
    this->transitions.push_back(transition);
}

void TuringMachine::step() {
    if (currentState == "halt") return;
    
    while (currentTransition->getReadSymbol() != tape->getCurrent()) {
        // TODO: Change head direction based on the command of the previous transition
        tape->moveRight();
    }
    
    if (currentTransition->getWriteSymbol() != '\0') {
        tape->write(currentTransition->getWriteSymbol());
    }
    
    currentState = currentTransition->getNextState();
        
    switch(currentTransition->getCommand()) {
        case 'R':
            tape->moveRight();
            break;
        case 'L':
            tape->moveLeft();
            break;
    }
}

void TuringMachine::run() {
    while (currentState != "" && currentState != "halt") {
        for (int i = 0; i < transitions.size(); i++) {
            currentTransition = &transitions[i];
            step();
        }
        currentState = "halt";
    }
    
}

void TuringMachine::print() {
    std::cout << *this->tape;
}

std::vector<Transition>& TuringMachine::getTransitions() {
    return this->transitions;
}

void TuringMachine::printTranstitons() {
    for (int i = 0; i < transitions.size(); i++) {
        std::cout << transitions[i];
    }
}
