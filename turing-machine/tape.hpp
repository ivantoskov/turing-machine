//
//  tape.hpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#ifndef tape_hpp
#define tape_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "math.h"
#include "defs.hpp"

class Tape {
    
private:
    char current;
    std::vector<char> left;
    std::vector<char> right;
    int size;    
public:
    Tape(const std::string&);
    Tape(const Tape&);
        
    // Read the value of the element under the tape head
    char read() const;
    
    // Change the value of the element under the tape head
    void write(char);
    
    // Move tape head to the left
    void moveLeft();
    
    // Move tape head to the right
    void moveRight();
    
    // Get the raw tape string
    std::string getTapeString() const;
    
    friend std::ostream& operator<<(std::ostream&, Tape&);
};

#endif /* tape_hpp */
