//
//  machine.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 20/12/2020.
//

#include "machine.hpp"

TuringMachine::TuringMachine() {
    currentState = "q0";
}

TuringMachine::TuringMachine(const TuringMachine& other) {
    this->currentState = other.currentState;
    this->tape = other.tape;
}

void TuringMachine::addTape(Tape& tape) {
    tapes.push_back(tape);
}

void TuringMachine::addTransition(Transition& transition) {
    map[transition.getCurrentState()].push_back(transition);
}

void TuringMachine::step() {
    
    Transition* next = findTransition(tapes[0].read());
    
    if (next == nullptr) {
        currentState = "";
        return;
    }
    
    std::cout << *next;
    currentState = next->getNextState();
    
    if (tapes.size() == 1) {
        if (next->getWriteSymbol()[0] != '\0') {
            tapes[0].write(next->getWriteSymbol()[0]);
        }

        switch(next->getCommand()[0]) {
            case 'R':
                tapes[0].moveRight();
                break;
            case 'L':
                tapes[0].moveLeft();
                break;
        }
        return;
    }
    
    for (int i = 0; i < tapes.size(); i++) {
        if (next->getWriteSymbol()[i] != '\0') {
            tapes[i].write(next->getWriteSymbol()[i]);
        }

        switch(next->getCommand()[i]) {
            case 'R':
                tapes[i].moveRight();
                break;
            case 'L':
                tapes[i].moveLeft();
                break;
        }
    }
}

void TuringMachine::run() {
    while (currentState != "" && currentState != "halt") {
        step();
    }
}

void TuringMachine::print() {
    if (tapes.size() == 1) {
        std::cout << tapes[0] << std::endl;
        return;
    }
    
    for (int i = 0; i < tapes.size(); i++) {
        std::cout << tapes[i] << std::endl;
    }
    
}

void TuringMachine::readFromFile(const std::string& fileName) {
    std::ifstream input(fileName, std::ios::in);
    if (input.is_open()) {
        std::string line;
        std::regex expression("[{}(\\->)]");
        while (getline(input, line)){
            std::string replaced = std::regex_replace(line, expression, " ");
            
            std::string readSymbols, writeSymbols;
            std::string currentState, nextState;
            std::string command;
            
            std::stringstream ss(replaced);
            
            ss >> readSymbols >> currentState >> writeSymbols >> nextState >> command;
            
            Transition tr = Transition(currentState, readSymbols, writeSymbols, command, nextState);
            this->addTransition(tr);
        }
        input.close();
    }
}

bool TuringMachine::isFinishedSuccessfully() {
    return currentState == "halt";
}

std::vector<Transition>& TuringMachine::getTransitions(const std::string state) {
    return map[state];
}

std::vector<std::string> TuringMachine::getStates() {
    std::vector<std::string> states;
    for(std::map<std::string,std::vector<Transition>>::iterator it = map.begin(); it != map.end(); it++) {
      states.push_back(it->first);
    }
    return states;
}

Transition* TuringMachine::findTransition(const char& readSymbol) {
    std::vector<Transition>& transitions = map[currentState];
    Transition* found = nullptr;
    for (int i = 0; i < transitions.size(); i++) {
        if (readSymbol == transitions[i].getReadSymbol()[0]) {
            found = &transitions[i];
        }
    }
    return found;
}

void TuringMachine::setStartState(const std::string& state) {
    currentState = state;
}

void TuringMachine::compose(TuringMachine other) {
    std::vector<std::string> otherStates = other.getStates();
    for (int i = 0; i < this->getStates().size(); i++) {
        std::vector<Transition>& transitions = map[this->getStates()[i]];
        for (int j = 0; j < transitions.size(); j++) {
            Transition& transition = transitions[j];
            if (transition.getNextState() == "halt") {
                transition.setNextState(other.currentState);
            }
        }
    }
    
    for (int i = 0; i < otherStates.size(); i++) {
        std::vector<Transition>& otherTransitions = other.getTransitions(otherStates[i]);
        for (int j = 0; j < otherTransitions.size(); j++) {
            map[otherStates[i]].push_back(otherTransitions[j]);
        }
    }
}

void TuringMachine::toSingleTape() {
    if (tapes.size() == 1) {
        return;
    }
    
    std::stringstream ss("", std::ios_base::app | std::ios_base::out);
    
    for (int i = 0; i < tapes.size(); i++) {
        ss << '#';
        ss << tapes[i];
    }
    ss << '#';
    
    tapes.erase(tapes.begin(), tapes.end());
    Tape tape = Tape(ss.str());
    addTape(tape);
}
