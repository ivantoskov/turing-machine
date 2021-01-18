//
//  machine.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 20/12/2020.
//

#include "machine.hpp"

TuringMachine::TuringMachine() {
    setStartState(START_STATE);
}

TuringMachine::TuringMachine(const TuringMachine& other) {
    this->currentState = other.currentState;
    this->tapes = other.tapes;
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
        currentState = REJECT;
        return;
    }
    
    std::cout << *next;
    currentState = next->getNextState();
    
    for (int i = 0; i < tapes.size(); i++) {
        if (next->getWriteSymbol()[i] != '\0') {
            tapes[i].write(next->getWriteSymbol()[i]);
        }

        switch(next->getCommand()[i]) {
            case RIGHT:
                tapes[i].moveRight();
                break;
            case LEFT:
                tapes[i].moveLeft();
                break;
            case STAND:
                break;
        }
    }
}

void TuringMachine::run() {
    
    std::string tapeString = tapes[0].getTapeString();
    if (tapeString[0] == DELIMITER) {
        tapes.erase(tapes.begin(), tapes.end());
        std::stringstream stream(tapeString);
        std::string tape;
        while (getline(stream, tape, DELIMITER)) {
            if (tape.empty()) {
                continue;
            }
            tapes.push_back(Tape(tape));
        }
        while (currentState != REJECT && currentState != ACCEPT) {
            step();
        }
        toSingleTape();
        return;
    }
    
    while (currentState != REJECT && currentState != ACCEPT) {
        step();
    }
}

void TuringMachine::print() {
    for (int i = 0; i < tapes.size(); i++) {
        std::cout << tapes[i] << std::endl;
    }
}

void TuringMachine::readTapes(const std::string& fileName) {
    std::ifstream input(fileName, std::ios::in);
    if (input.is_open()) {
        std::string line;
        while(getline(input, line)) {
            std::string tapeString;
            std::stringstream stream(line);
            stream >> tapeString;
            Tape tape = Tape(tapeString);
            addTape(tape);
        }
    }
    input.close();
}

void TuringMachine::readTransitions(const std::string& fileName) {
    std::ifstream input(fileName, std::ios::in);
    if (input.is_open()) {
        std::string line;
        std::regex expression("[{}(\\->)]");
        
        while (getline(input, line)){
            std::string replaced = std::regex_replace(line, expression, " ");
            
            std::string readSymbols, writeSymbols;
            std::string currentState, nextState;
            std::string command;
            
            std::stringstream stream(replaced);
            
            stream >> readSymbols >> currentState >> writeSymbols >> nextState >> command;
            
            Transition transition = Transition(currentState, readSymbols, writeSymbols, command, nextState);
            this->addTransition(transition);
        }
        
        input.close();
    }
}

void TuringMachine::saveTapes(const std::string fileName) {
    std::ofstream output;
    output.open(fileName, std::ios_base::app | std::ios_base::out);
        
    if (output.is_open()) {
        for (int i = 0; i < tapes.size(); i++) {
            output << tapes[i] << std::endl;
        }
            
        output.flush();
        output.close();
    }
}

bool TuringMachine::isFinishedSuccessfully() {
    return currentState == ACCEPT;
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

void TuringMachine::compose(TuringMachine& other) {
    std::vector<std::string> otherStates = other.getStates();
    
    for (int i = 0; i < this->getStates().size(); i++) {
        std::vector<Transition>& transitions = map[this->getStates()[i]];
        
        for (int j = 0; j < transitions.size(); j++) {
            Transition& transition = transitions[j];
            
            if (transition.getNextState() == ACCEPT) {
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

void TuringMachine::branch(TuringMachine& second, TuringMachine& third, Tape& inputTape) {
    third.addTape(inputTape);
    third.run();
    
    if (third.isFinishedSuccessfully()) {
        this->addTape(inputTape);
        this->run();
    } else {
        second.addTape(inputTape);
        second.run();
    }
}

void TuringMachine::toSingleTape() {
    if (tapes.size() == 1) {
        return;
    }
    
    std::stringstream stream("", std::ios_base::app | std::ios_base::out);
    
    for (int i = 0; i < tapes.size(); i++) {
        stream << DELIMITER;
        stream << tapes[i];
    }
    
    stream << DELIMITER;
    
    tapes.erase(tapes.begin(), tapes.end());
    Tape tape = Tape(stream.str());
    addTape(tape);
}
