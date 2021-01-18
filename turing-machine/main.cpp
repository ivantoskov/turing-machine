//
//  main.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include <iostream>
#include "machine.hpp"

void execute() {
    std::string tapeStr;
    std::cout << "Enter a tape: ";
    getline (std::cin, tapeStr);
    
    TuringMachine tm;
    Tape tape = Tape(tapeStr);
    tm.addTape(tape);
    
    std::string fileName;
    std::cout << "Load transitions from a text file: ";
    getline (std::cin, fileName);
    tm.readTransitions(fileName);
    tm.setStartState(START_STATE);
    std::cout << "Input tape: " << std::endl;
    tm.print();
    std::cout << "Transitions: " << std::endl;
    tm.run();
    if (tm.isFinishedSuccessfully()) {
        std::cout << "Turing machine successfully reached ACCEPT state." << std::endl;
        tm.saveTapes("tapes1.txt");
    } else {
        std::cout << "Turing machine reached REJECT state." << std::endl;
    }
    std::cout << "Output tape: " << std::endl;
    tm.print();
}

int main(int argc, const char * argv[]) {
    
    //execute();

    
//     Accepts the language { aⁿbⁿcⁿ | n ≥ 1 }, which is
//     a's followed by b's then c's of the same length.
//     e.g. "aabbcc", "aaabbbccc", "aaaabbbbcccc", ...
    
//    TuringMachine tm;
//    tm.readTapes("three-equal-lengths-tapes.txt");
//    tm.readTransitions("three-equal-lengths.txt");
//    tm.setStartState(START_STATE);
//
//    tm.print();
//    tm.run();
//    tm.print();
//
//
//    //
//    // Composition of two Turing machines
//    //
//    TuringMachine tm3;
//    Tape t3 = Tape("001001");
//    tm3.addTape(t3);
//    tm3.readTransitions("tm3.txt");
//
//    TuringMachine tm4;
//    tm4.readTransitions("tm4.txt");
//
//    tm3.compose(tm4);
//
//    tm3.print();
//    tm3.run();
//    tm3.print();
    //
    // Multitape Turing machine
    //
//    TuringMachine tm;
//
//    tm.readTapes("multitape-tapes.txt");
//    tm.readTransitions("multitape-transitions.txt");
//
//    tm.print();
//    tm.run();
//    tm.toSingleTape();
//    tm.print();
//    tm.saveTapes("multitape-output.txt");
    
//    //
//    // Branching Turing machines
//    //
//    TuringMachine tm3;
//    tm3.readTransitions("ndtm.txt");
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
