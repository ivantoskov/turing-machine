//
//  machine.hpp
//  turing-machine
//
//  Created by Ivan Toskov on 20/12/2020.
//

#ifndef machine_hpp
#define machine_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <regex>
#include <sstream>
#include "tape.hpp"
#include "transition.hpp"

class TuringMachine {
    
private:
    Tape* tape;
    std::string currentState;
    std::vector<Transition> transitions;
    Transition* currentTransition;
    Transition* previousTransition;
    bool isFinished;
    
public:
    TuringMachine();
    TuringMachine(const TuringMachine&);
    
    // Add a tape to Turing machine
    void addTape(Tape&);
    
    // Add transition to Turing machine
    void addTransition(Transition&);
    
    // Execute one step
    void step();
    
    // Execute all steps
    void run();
    
    // Print tape(s)
    void print();
    
    // Print all transitions
    void printTransitions();
    
    // Read Turing machine transtions from text file
    void readFromFile(const std::string&);
    
    // Returns true if Turing machine has reached "halt" state
    bool isFinishedSuccessfully();
};

#endif /* machine_hpp */
