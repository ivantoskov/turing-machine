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
#include "math.h"

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
    
    // Move the tape head left
    void moveLeft();
    
    // Move the tape head right
    void moveRight();
    
    char getCurrent() const;
    friend std::ostream& operator<<(std::ostream&, Tape&);

};

#endif /* tape_hpp */
