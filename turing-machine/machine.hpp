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
#include "tape.hpp"
#include "transition.hpp"

class TuringMachine {
    
private:
    std::string currentState;
    Tape* tape;
    std::vector<Transition> transitions;
    
public:
    TuringMachine();
    TuringMachine(const TuringMachine&);
    
    void addTape(Tape&);
    void addTransition(const Transition&);
    void step(const Transition&);
    void run();
    void print();
    
    std::vector<Transition>& getTransitions();
    
};

#endif /* machine_hpp */
