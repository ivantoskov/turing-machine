//
//  machine.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 20/12/2020.
//

#include "machine.hpp"

TuringMachine::TuringMachine() {
    currentState = "start";
    isFinished = false;
}

TuringMachine::TuringMachine(const TuringMachine& other) {
    this->currentState = other.currentState;
    this->tape = other.tape;
    this->transitions = other.transitions;
    this->isFinished = false;
}

void TuringMachine::addTape(Tape& tape) {
    this->tape = &tape;
}

void TuringMachine::addTransition(Transition& transition) {
    this->transitions.push_back(transition);
}

void TuringMachine::step() {
    if (currentState == "halt") return;
    
    while (currentTransition->getReadSymbol() != tape->getCurrent()) {
        
        if (currentTransition == &transitions[0]) {
                    tape->moveRight();
        }
        
        switch(previousTransition->getCommand()) {
            case 'R':
                tape->moveRight();
                break;
            case 'L':
                tape->moveLeft();
                break;
        }
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
            if (i > 0) {
                previousTransition = &transitions[i - 1];
            }
            step();
        }
        currentState = "halt";
    }
}

void TuringMachine::print() {
    std::cout << *this->tape;
}

void TuringMachine::printTransitions() {
    for (int i = 0; i < transitions.size(); i++) {
        std::cout << transitions[i];
    }
}

void TuringMachine::readFromFile(const std::string& fileName) {
    std::ifstream input(fileName, std::ios::in);
    if (input.is_open()) {
        std::string line;
        std::regex e("[{}(\\->)]");
        while (getline(input, line)){
            std::string replaced = std::regex_replace(line, e, " ");
            
            std::string readSymbols, writeSymbols;
            std::string currentState, nextState;
            std::string command;
            
            std::stringstream ss(replaced);
            
            ss >> readSymbols >> currentState >> writeSymbols >> nextState >> command;
            
            Transition tr = Transition(currentState, readSymbols[0], writeSymbols[0], command[0], nextState);
            this->addTransition(tr);
        }
        input.close();
    }
}

bool TuringMachine::isFinishedSuccessfully() {
    return currentState == "halt";
}
