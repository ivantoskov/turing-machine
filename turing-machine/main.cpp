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
    std::cout << "Input tape: \n";
    tm.print();
    std::cout << "Transitions: \n";
    tm.run();
    if (tm.isFinishedSuccessfully()) {
        std::cout << "Turing machine successfully reached ACCEPT state. \n";
        tm.saveTapes("tapes1.txt");
    } else {
        std::cout << "Turing machine reached REJECT state. \n";
    }
    std::cout << "Output tape: \n";;
    tm.print();
}

int main(int argc, const char * argv[]) {
    
    // execute();
    
    // Accepts the language { aⁿbⁿcⁿ | n ≥ 1 }, which is
    // a's followed by b's then c's of the same length.
    // e.g. "aabbcc", "aaabbbccc", "aaaabbbbcccc", ...
        
    TuringMachine tm;
    tm.loadMachine("three-equal-lengths.txt");

    tm.print();
    tm.run();
    tm.print();
}
