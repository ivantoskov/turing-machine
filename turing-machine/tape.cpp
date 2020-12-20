//
//  tape.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include "tape.hpp"

Tape::Tape(const std::string& elements) {
    for (int i = (int)(elements.length() - 1); i >= 0; i--) {
        this->right.push_back(elements[i]);
    }
    this->current = this->right.back();
    this->right.pop_back();
    
    this->size = (int)elements.length();
}

Tape::Tape(const Tape& other) {
    this->left = other.left;
    this->right = other.right;
    this->current = other.current;
}

char Tape::read() const {
    return this->current;
}

void Tape::write(char symbol) {
    this->current = symbol;
}

void Tape::moveLeft() {
    this->right.push_back(this->current);
    if (this->left.empty()) {
        this->left.push_back(' ');
    }
    this->current = this->left.back();
    this->left.pop_back();
}

void Tape::moveRight() {
    this->left.push_back(this->current);
    if (this->right.empty()) {
        this->right.push_back(' ');
    }
    this->current = this->right.back();
    this->right.pop_back();
}

int Tape::getSize() const {
    return this->size;
}

char Tape::getCurrent() const {
    return this->current;
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

