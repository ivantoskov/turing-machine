//
//  main.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include <iostream>
#include "machine.hpp"

int main(int argc, const char * argv[]) {
    
    Tape t1 = Tape("05100001");
    std::cout << t1 << std::endl;
    t1.write('8');
    t1.moveRight();
    t1.write('6');
    t1.write('7');
    t1.moveLeft();
    t1.write('9');
    std::cout << t1 << std::endl;
}
