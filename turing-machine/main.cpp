//
//  main.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include <iostream>
#include "machine.hpp"

int main(int argc, const char * argv[]) {
    
    //
    // Accepts the language { aⁿbⁿcⁿ | n ≥ 1 }, which is
    // a's followed by b's then c's of the same length.
    // e.g. "aabbcc", "aaabbbccc", "aaaabbbbcccc", ...
    //
    TuringMachine tm;
    Tape t1 = Tape("aaabbbccc");
    tm.addTape(t1);
    tm.readFromFile("three-equal-lengths.txt");
    tm.setStartState("q0");

    tm.print();
    tm.run();
    tm.print();

    //
    // Accepts the language { 01ⁿ0 | n ≥ 1 }, which is
    // n number of ones surrounded by two zeroes
    // e.g. "010", "011110", "0111110", ...
    //
    TuringMachine tm2;
    Tape t2 = Tape("0111111110");
    tm2.addTape(t2);
    tm2.readFromFile("zeroes-and-ones.txt");
    tm2.setStartState("q0");

    tm2.print();
    tm2.run();
    tm2.print();


    //
    // Composition of two Turing machines
    //
    TuringMachine tm3;
    Tape t3 = Tape("001001");
    tm3.addTape(t3);
    tm3.readFromFile("tm3.txt");

    TuringMachine tm4;
    tm4.readFromFile("tm4.txt");

    tm3.compose(tm4);

    tm3.print();
    tm3.run();
    tm3.print();
//    //
//    // Multitape Turing machine
//    //
//    TuringMachine tm;
//    Tape t1 = Tape("00001");
//    Tape t2 = Tape("11110");
//    Tape t3 = Tape("00100");
//    Transition tr1 = Transition("q0", "010", "XYZ", "RRR", "q1");
//    Transition tr2 = Transition("q1", "010", "ZYX", "RRL", "q2");
//    Transition tr3 = Transition("q2", "01Z", "00X", "RRR", "halt");
//    tm.addTape(t1);
//    tm.addTape(t2);
//    tm.addTape(t3);
//    tm.addTransition(tr1);
//    tm.addTransition(tr2);
//    tm.addTransition(tr3);
//
//    tm.print();
//    tm.run();
//    tm.print();
    
//    //
//    // Branching Turing machines
//    //
//    TuringMachine tm3;
//    tm3.readFromFile("ndtm.txt");
//
//    TuringMachine tm2;
//    Transition tr1 = Transition("q0", "0", "X", "R", "q1");
//    Transition tr2 = Transition("q1", "1", "Y", "R", "halt");
//    tm2.addTransition(tr1);
//    tm2.addTransition(tr2);
//
//    TuringMachine tm1;
//    Transition tr3 = Transition("q0", "0", "Y", "R", "q1");
//    Transition tr4 = Transition("q1", "1", "X", "R", "halt");
//    tm1.addTransition(tr3);
//    tm1.addTransition(tr4);
//
//    Tape tape3 = Tape("0100");
//    tm1.branch(tm3, tm2, tape3);
//    std::cout << tm2.isFinishedSuccessfully() << std::endl;
//    tm2.print();
//    tm3.print();
    
    
}
