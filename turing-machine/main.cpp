//
//  main.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include <iostream>
#include "machine.hpp"

int main(int argc, const char * argv[]) {
    
    // TODO: hash map - [q1: Transition]
    
    Tape t1 = Tape("aaabbbccc");
    
    TuringMachine tm;
    tm.readFromFile("tm.txt");
    tm.addTape(t1);

    tm.print();
    tm.run();
    tm.printTransitions();
    tm.print();
}
