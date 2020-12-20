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

void TuringMachine::step(const Transition& transition) {
    for (int i = 0; i < this->tape->getSize() - 1; i++) {
        if (transition.getReadSymbol() == this->tape->getCurrent()) {
            //this->tape->write(transition.getWriteSymbol()[0]);
            
            if (transition.getCurrentState() == "increment") {
                this->tape->write(this->tape->getCurrent() + 1);
            }
            
            if (transition.getCurrentState() == "decrement") {
                this->tape->write(this->tape->getCurrent() - 1);
            }
            
            this->currentState = transition.getNextState();
            
            switch(this->transitions[i + 1].getCommand()[0]) {
                case 'R' :
                    this->tape->moveRight();
                    break;
                case 'L':
                    this->tape->moveLeft();
                    break;
            }
            
        } else {
            this->tape->moveRight();
        }
    }
}

void TuringMachine::run() {
    while(this->currentState != "" && this->currentState != "halt") {
        for (int i = 0; i <= this->transitions.size() - 1; i++) {
            step(this->transitions[i]);
        }
    }
}

void TuringMachine::print() {
    std::cout << *this->tape << std::endl;
}

std::vector<Transition>& TuringMachine::getTransitions() {
    return this->transitions;
}
