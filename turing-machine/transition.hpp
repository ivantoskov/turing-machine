//
//  transition.hpp
//  turing-machine
//
//  Created by Ivan Toskov on 20/12/2020.
//

#ifndef transition_hpp
#define transition_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class Transition {
    
private:
    std::string read;
    std::string write;
    std::string command;
    std::string currentState;
    std::string nextState;
        
public:
    Transition(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    Transition(const Transition&);
    
    // Get the read symbol from transition
    std::string getReadSymbol() const;
    
    // Get the write symbol from transition
    std::string getWriteSymbol() const;
    
    // Get the command from transition 
    std::string getCommand() const;
    
    // Get the current state from transition
    std::string getCurrentState() const;
    
    // Get the next state from transition
    std::string getNextState() const;
    
    // Change the next state of transition
    void setNextState(const std::string&);
        
    friend std::ostream& operator<<(std::ostream&, Transition&);
};

#endif /* transition_hpp */
