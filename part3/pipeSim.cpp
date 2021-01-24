/*  NATALIE EICHORN
    COMP 4300
    PART 3 - PIPELINE
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;

// functions
void load(string fileName);
int get_data(int address);
void run_pipe();
void totals();

// global variables
int TEXT_SEG_LENGTH = 16;
int text_memory[16];
int accumRegister[32];

int total_NOPs = 0;
int total_instructions = 0;
int total_cycles = 0;

// main method
int main () {
    cout << "\n*** NATALIE EICHORN - PIPELINE, LAB 3C ***\n";

    //--------------------------------------
    // load the values into main memory
    //--------------------------------------
    load("lab3c.s");

    //--------------------------------------
    // run the pipeline
    //--------------------------------------
    run_pipe();

    //--------------------------------------
    // display results
    //--------------------------------------
    totals();

    cout << endl;
    return 0;
}


// load into memory
void load(string fileName) {
    int counter = 0;
    int tIndex = 0;

    ifstream infile(fileName);
    string line;

    while (getline(infile, line))
    {
        // casting string to int
        stringstream entry(line);
        int number = 0;
        entry >> number;

        // putting instructions into text_memory array
        if(counter < TEXT_SEG_LENGTH) {
            text_memory[tIndex] = number;
            tIndex++;
        }
        counter++;
    }
}


//returns the data address's value
int get_data(int address) {
    if(address == 2) {
        return 100;
    }
    else if (address == 3) {
        return 1000;
    }
    else {
        return address;
    }
}

// runs functions of the accumulator
void run_pipe() {
    int instruction;
    int op;
    int regD;
    int val2;
    int val3;
    int index = 0;
    
    while (index < TEXT_SEG_LENGTH) {
        instruction = text_memory[index];

        // gets operation for switch 
        op = instruction/1000000;

        // gets register destination
        regD = instruction%1000000;
        regD = regD / 10000;

        // gets value 2
        val2 = instruction%1000;
        val2 = val2/100;

        // gets value 3
        val3 = instruction%100;
    
        switch(op) {

            case 1 : // LI

                accumRegister[regD] = val3;
                
                total_instructions++;
                total_cycles += 5;
                
                break;

            case 2 : // BGE

                if (accumRegister[regD] >= accumRegister[val2]) {
                    index = index - 5;
                    total_NOPs++;
                }

                total_instructions++;
                total_cycles += 5;
                
                break;

            case 3 : // ADD

                accumRegister[regD] = accumRegister[val2] + get_data(accumRegister[val3]);
                
                total_instructions++;
                total_cycles += 5;
                
                break;

            case 4 : // SUB

                accumRegister[regD] = accumRegister[val2] - 1;

                total_instructions++;  
                total_cycles += 5; 
                
                break;

            case 5 : // NOP
                
                total_NOPs++;
                total_instructions++;
                total_cycles += 5;
                
                break;

            case 6 : // syscall

                total_instructions++;
                total_cycles += 5;
                
                break;

            default :
                cout << "Program Running...";
        }
        index++;
    }
    
}


void totals() {
    cout << "\nTOTAL INSTRUCTIONS = " << total_instructions << endl;
    cout << "TOTAL CYCLES = " << total_cycles << endl;
    cout << "TOTAL NOPS = " << total_NOPs << endl;
    
    double speedup = (8.0 * total_instructions)/total_cycles;

    cout << "SPEEDUP = " << speedup << endl;
}