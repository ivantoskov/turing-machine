//
//  main.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include <iostream>
#include "machine.hpp"

int main(int argc, const char * argv[]) {
    
    Tape t1 = Tape("00110");
    std::cout << t1 << std::endl;
    
    Transition tr1 = Transition("increment", '1', "R", "halt");
    //Transition tr2 = Transition("decrement", '1', "R", "halt");

    TuringMachine tm;
    tm.addTape(t1);
    tm.addTransition(tr1);
    //tm.addTransition(tr2);
    tm.run();
    tm.print();
    
}
