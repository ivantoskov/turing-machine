//
//  tape.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include "tape.hpp"

Tape::Tape(const std::string& str) {
    for (int i = (int)(str.length() - 1); i >= 0; i--) {
        right.push_back(str[i]);
    }
    current = this->right.back();
    right.pop_back();
    size = (int)str.length();
}

Tape::Tape(const Tape& other) {
    this->left = other.left;
    this->right = other.right;
    this->current = other.current;
}

char Tape::read() const {
    return current;
}

void Tape::write(char symbol) {
    current = symbol;
}

void Tape::moveLeft() {
    right.push_back(current);
    if (left.empty()) {
        left.push_back(BLANK_SYMBOL);
    }
    current = left.back();
    left.pop_back();
}

void Tape::moveRight() {
    left.push_back(current);
    if (right.empty()) {
        right.push_back(BLANK_SYMBOL);
    }
    current = right.back();
    right.pop_back();
}

std::string Tape::getTapeString() const {
    std::string tapeString;
    for (int i = (int)(left.size() - 1); i >= 0; i--) {
        int index = abs(i - (int)(left.size() - 1));
        tapeString += left[index];
    }
    
    tapeString += current;
    
    for (int i = (int)(right.size() - 1); i >= 0; i--) {
        tapeString += right[i];
    }
    
    return tapeString;
}

std::ostream& operator<<(std::ostream& out, Tape &tape) {
    
    for (int i = (int)(tape.left.size() - 1); i >= 0; i--) {
        int index = abs(i - (int)(tape.left.size() - 1));
        out << tape.left[index];
    }

    out << tape.current;

    for (int i = (int)(tape.right.size() - 1); i >= 0; i--) {
        out << tape.right[i];
    }
    
    return out;
}

