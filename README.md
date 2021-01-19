# Turing machine
## Description
This program implements a multitape deterministic Turing machine in C++. The states and the transitions are stored in a map where the key is a state and the value is a vector of transitions for the given state.

The transition in the machine is set as follows:
```
<state> ::= { <string> }
<command> ::= L | R | S
<transition> ::= <symbol><state> -> <symbol><state><command>
```
The commands control the movement of the head, respectively left ```L```, right ```R```, or without change ```S```.

**Example:**
```
a{q0} -> x{q1}R
```

**If the symbol ```a``` is written on the tape (below the current position of the head) and the machine is in state ```q0```, replace ```a``` with ```x```, switch to state ```q1``` , and move the tape head to the ```right```.**

## Features
* Multitape deterministic Turing machine
* Converting mutitape Turing machine to its equivalent single tape turing machine
* Composition of two Turing machines
* Reading tape(s) and transitions from a text file and executing the machine

