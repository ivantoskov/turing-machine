//
//  main.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include <iostream>
#include "machine.hpp"

int main(int argc, const char * argv[]) {
    
    Tape t2 = Tape("01001");
    Transition transition1 = Transition("start", '1', '0', 'R', "t2");
    Transition transition2 = Transition("t2", '1', '0', 'R', "halt");
    
    TuringMachine tm2;
    tm2.addTape(t2);
    tm2.addTransition(transition1);
    tm2.addTransition(transition2);
    
    tm2.print();
    tm2.run();
    tm2.printTranstitons();
    tm2.print();
    

}
