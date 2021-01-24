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
void run_stack();

// global variables
int TEXT_SEG_LENGTH = 13;
int DATA_SEG_LENGTH = 4;
int text_memory[13];
int data_memory[4];
std::stack<int> myStack;


// main method
int main () {
    cout << "\n*** NATALIE EICHORN - STACK MACHINE SIMULATOR ***\n\n";
    //--------------------------------------
    // load the values into main memory
    //--------------------------------------
    load("stackCode.txt");

    //--------------------------------------
    // run the stack
    //--------------------------------------
    run_stack();

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

// runs functions of the stack
void run_stack() {
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
        int toPush;

        switch(op) {
            case 1 : //PUSH
                toPush = read_data(address);
                myStack.push(toPush);
                break;
            case 2 : //POP
                cout << "TOP OF STACK = " << myStack.top() << endl;
                break;
            case 3 : // ADD
                num = myStack.top();
                myStack.pop();

                num2 = myStack.top();
                myStack.pop();  

                sum = num + num2;

                myStack.push(sum);
                break;
            case 4 : // MULT
                num = myStack.top();
                myStack.pop();

                num2 = myStack.top();
                myStack.pop();

                product = num * num2;

                myStack.push(product);                
                break;
            case 5 : // END
                user_mode=false;
                break;
            default :
                cout << "Program Running...";
        }
        index++;
    }
}