//
//  main.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include <iostream>
#include "machine.hpp"

void execute() {

    TuringMachine tm;
    std::string fileName;
    std::cout << "Load machine from a text file: ";
    getline (std::cin, fileName);
    tm.loadMachine(fileName);
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

    
    // Accepts the language { aⁿbⁿcⁿ | n ≥ 1 }, which is
    // a's followed by b's then c's of the same length.
    // e.g. "aabbcc", "aaabbbccc", "aaaabbbbcccc", ...
        
//    TuringMachine tm;
//    tm.loadMachine("three-equal-lengths.txt");

//    tm.print();
//    tm.run();
//    std::cout << tm.isFinishedSuccessfully() << std::endl;
//    tm.print();
//
//
//    //
//    // Composition of two Turing machines
//    //
//    TuringMachine tm3;
//    tm3.loadMachine("tm3.txt");
//
//    TuringMachine tm4;
//    tm4.loadMachine("tm4.txt");

    //tm3.compose(tm4);

//    tm3.print();
//    tm3.run();
//    tm3.print();
    //
    // Multitape Turing machine
    //
//    TuringMachine tm;
//
//    tm.loadMachine("multitape.txt");
//
//    tm.print();
//    tm.run();
//    tm.toSingleTape();
//    tm.print();
//    tm.saveTapes("multitape-output.txt");
    
    //
    // Branching Turing machines
    //
    
//    TuringMachine tm1;
//    tm1.loadMachine("ndtm.txt");
//
//    TuringMachine tm2;
//    tm2.loadMachine("branch2.txt");
//    
//    TuringMachine tm3;
//    tm3.loadMachine("branch3.txt");
//
//    tm2.branch(tm3, tm1);
//    std::cout << tm2.isFinishedSuccessfully() << std::endl;
//    tm1.print();
//    tm3.print();
}
