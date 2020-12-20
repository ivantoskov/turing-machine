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
        
    char read() const;
    void write(char);
    void moveLeft();
    void moveRight();
    
    int getSize() const;
    char getCurrent() const;
    
    friend std::ostream& operator<<(std::ostream&, Tape&);
    
};

#endif /* tape_hpp */
