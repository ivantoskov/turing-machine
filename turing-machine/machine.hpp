//
//  machine.hpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#ifndef machine_hpp
#define machine_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

class Tape {
private:
    char current;
    std::vector<char> left;
    std::vector<char> right;
public:
    Tape(const std::string&);
    Tape(const Tape&);
        
    char read() const;
    void write(char);
    void moveLeft();
    void moveRight();
    friend std::ostream& operator<<(std::ostream&, Tape&);    
};


#endif /* machine_hpp */
