//
//  machine.hpp
//  turing-machine
//
//  Created by Ivan Toskov on 20/12/2020.
//

#ifndef machine_hpp
#define machine_hpp

#include <stdio.h>
#include <fstream>
#include <regex>
#include <sstream>
#include <map>
#include "tape.hpp"
#include "transition.hpp"
#include "defs.hpp"

class TuringMachine {
    
private:
    std::vector<Tape> tapes;
    std::string currentState;
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
    
    // Read Turing machine transtions from a text file
    void readFromFile(const std::string&);
    
    // Returns true if Turing machine has reached "halt" state
    bool isFinishedSuccessfully();
    
    // Get all transitions for a state
    std::vector<Transition>& getTransitions(const std::string);
    
    // Get all Turing machine states
    std::vector<std::string> getStates();
    
    // Set the start state of Turing machine
    void setStartState(const std::string&);
    
    // Composition of two Turing machines
    void compose(TuringMachine&);
    
    // Converts multitape Turing machine to its eqivalent single tape Turing machine
    // Every multitape Turing machine has an equivalent single tape Turing machine
    void toSingleTape();
    
    // Branching of two Turing machines concerning a third
    void branch(TuringMachine&, TuringMachine&, Tape&);
    
};

#endif /* machine_hpp */
