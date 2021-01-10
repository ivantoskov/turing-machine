//
//  tape.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include "tape.hpp"

Tape::Tape(const std::string& elements) {
    for (int i = (int)(elements.length() - 1); i >= 0; i--) {
        right.push_back(elements[i]);
    }
    current = this->right.back();
    right.pop_back();
    
    size = (int)elements.length();
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
        left.push_back(' ');
    }
    current = left.back();
    left.pop_back();
}

void Tape::moveRight() {
    left.push_back(current);
    if (right.empty()) {
        right.push_back(' ');
    }
    current = right.back();
    right.pop_back();
}

char Tape::getCurrent() const {
    return current;
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
    
    out << std::endl;
    
    return out;
}

