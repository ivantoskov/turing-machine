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
#include <fstream>
#include <regex>
#include <sstream>
#include <map>
#include "tape.hpp"
#include "transition.hpp"

class TuringMachine {
    
private:
    Tape* tape;
    std::string currentState;
    Transition* currentTransition;
    std::map<std::string, std::vector<Transition>> map;
    Transition* findTransition(const char&);
    
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
    
    // Read Turing machine transtions from text file
    void readFromFile(const std::string&);
    
    // Returns true if Turing machine has reached "halt" state
    bool isFinishedSuccessfully();
    
    // Get all transitions for a state
    std::vector<Transition>& getTransitions(const std::string);
    
    // Get all of the states
    std::vector<std::string> getStates();
    
    // Set the start state of Turing machine
    void setStartState(const std::string&);
    
};

#endif /* machine_hpp */
