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
    char read;
    std::string command;
    std::string currentState;
    std::string nextState;
    
public:
    Transition(const std::string&, const char, const std::string&, const std::string&);
    Transition(const Transition&);
    
    char getReadSymbol() const;
    std::string getCommand() const;
    std::string getCurrentState() const;
    std::string getNextState() const;
    
    friend std::ostream& operator<<(std::ostream&, Transition&);
    
};

#endif /* transition_hpp */