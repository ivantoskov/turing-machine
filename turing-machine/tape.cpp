//
//  tape.cpp
//  turing-machine
//
//  Created by Ivan Toskov on 09/12/2020.
//

#include "tape.hpp"

Tape::Tape(const std::string& str) {
    if (str[0] == DELIMITER) {
        std::stringstream ss(str);
        std::string item;
        while (getline(ss, item, DELIMITER)) {
            if (item.empty()) {
                continue;
            }
            multitape.push_back(Tape(item));
        }
        return;
    }
    init(str);
}

void Tape::init(const std::string& str) {
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

std::vector<Tape>& Tape::getMultitape() {
    return multitape;
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

