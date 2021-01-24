/*  NATALIE EICHORN
    COMP 4300
    PART 1 - STACK MACHINE
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;

// functions
void load(string fileName);
int read_data(int address);
void run_accum();

// global variables
int TEXT_SEG_LENGTH = 11;
int DATA_SEG_LENGTH = 4;
int text_memory[11];
int data_memory[4];
int accumRegister[1];
int store[2];


// main method
int main () {
    cout << "\n*** NATALIE EICHORN - ACCUMULATOR MACHINE SIMULATOR ***\n\n";
    //--------------------------------------
    // load the values into main memory
    //--------------------------------------
    load("accumCode.txt");

    //cout << read_data(200001) << endl;

    //--------------------------------------
    // run the stack
    //--------------------------------------
    run_accum();

    cout << endl;
    return 0;
}


// load .text and .data into their memory arrays
void load(string fileName) {
    int counter = 0;
    int tIndex = 0;
    int dIndex = 0;

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
        // putting data into data_memory array
        else {
            data_memory[dIndex] = number;
            dIndex++;
        }
        counter++;
    }
}


//returns the data address's value
int read_data(int address) {
    for(int i=0; i<DATA_SEG_LENGTH; i++) {
        int value = data_memory[i]%10;
        int data_address = data_memory[i]/10;
        // if the input address matches an address in the data_memory, its numerical value is returned
        if(data_address == address) {
            return value;
        }
    }
    return 0;
}

// runs functions of the accumulator
void run_accum() {
    bool user_mode = true;
    int instruction;
    int op;
    int address;
    int index = 0;
    
    while (user_mode) {
        instruction = text_memory[index];

        // gets instruction (PUSH/POP/ADD/MULT/END)
        op = instruction/1000000;
        // gets binary address
        address = instruction%1000000;

        int find_address;
        int num;
        int num2;
        int sum;
        int product;

        switch(op) {
            case 1 : //LOAD
                accumRegister[0] = read_data(address);
                break;
            case 2 : //STO
                //the address refers to the first storage spot
                if(address%10==0) {
                    store[0] = accumRegister[0];
                }
                //the address refers to the second storage spot
                else if(address%10==1) {
                    store[1] = accumRegister[0];
                }
                break;
            case 3 : // ADD
                //the address refers to the first storage spot
                if (address==300000) {
                    num = store[0];
                }
                //the address refers to the second storage spot
                else if (address==300001) {
                    num = store[1];
                }
                //the address refers to data
                else if (address/10==20000) {
                    num = read_data(address);
                }
                num2 = accumRegister[0];

                sum = num + num2;

                accumRegister[0] = sum;
                break;
            case 4 : // MULT
                //the address refers to the first storage spot
                if(address==300000) {
                    num = store[0];
                }
                //the address refers to the second storage spot
                else if(address==300001) {
                    num = store[1];
                }
                //the address refers to data
                else if(address/10==20000) {
                    num = read_data(address);
                }
                num2 = accumRegister[0];

                product = num * num2;

                accumRegister[0]=product;                
                break;
            case 5 : // END
                cout << "REGISTER = " << accumRegister[0] << endl;
                user_mode=false;
                break;
            default :
                cout << "Program Running...";
        }
        index++;
    }
}