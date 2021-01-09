//
//  main.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include <iostream>
#include "machine.hpp"

int main(int argc, const char * argv[]) {
    
    Tape t1 = Tape("aaabbbccc");
    
    Transition tr1 = Transition("q1", 'a', 'x', 'R', "q2");
    Transition tr2 = Transition("q2", 'b', 'y', 'R', "q3");
    Transition tr3 = Transition("q3", 'c', 'z', 'L', "q4");
    Transition tr4 = Transition("q4", 'x', 'x', 'R', "q1");
    Transition tr5 = Transition("q1", 'a', 'x', 'R', "q2");
    Transition tr6 = Transition("q2", 'b', 'y', 'R', "q3");
    Transition tr7 = Transition("q3", 'c', 'z', 'L', "q4");
    Transition tr8 = Transition("q4", 'x', 'x', 'R', "q1");
    Transition tr9 = Transition("q1", 'a', 'x', 'R', "q2");
    Transition tr10 = Transition("q2", 'b', 'y', 'R', "q3");
    Transition tr11 = Transition("q3", 'c', 'z', 'R', "halt");
    
    
    TuringMachine tm;
    tm.addTape(t1);
    tm.addTransition(tr1);
    tm.addTransition(tr2);
    tm.addTransition(tr3);
    tm.addTransition(tr4);
    tm.addTransition(tr5);
    tm.addTransition(tr6);
    tm.addTransition(tr7);
    tm.addTransition(tr8);
    tm.addTransition(tr9);
    tm.addTransition(tr10);
    tm.addTransition(tr11);
        
    tm.print();
    tm.run();
    tm.printTranstitons();
    tm.print();

}
