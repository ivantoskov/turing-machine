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
#include <cassert>
#include "tape.hpp"
#include "transition.hpp"


class TuringMachine {
    
private:
    std::string currentState;
    Tape* tape;
    std::vector<Transition> transitions;
    Transition* currentTransition;
    
public:
    TuringMachine();
    TuringMachine(const TuringMachine&);
    
    void addTape(Tape&);
    void addTransition(const Transition&);
    void step();
    void run();
    void print();
    
    std::vector<Transition>& getTransitions();
    
    void printTranstitons();
    
};

#endif /* machine_hpp */
