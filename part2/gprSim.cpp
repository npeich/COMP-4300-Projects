/*  NATALIE EICHORN
    COMP 4300
    PART 2 - MULIT CYCLE MACHINE
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
string get_char(int index);
void run_accum();
string is_palin();
string not_palin();
void totals();

// global variables
string word;
int substringPosition = 0;
int TEXT_SEG_LENGTH = 28;
int text_memory[28];
int accumRegister[32];
int wordIndex = 0;
bool test = false;


int total_instructions = 0;
int total_cycles = 0;

// main method
int main () {
    cout << "\n*** NATALIE EICHORN - MULTI CYCLE SIMULATOR ***\n\n";

    //--------------------------------------
    // ask user for word
    //--------------------------------------
    cout << "PLEASE ENTER A WORD: ";
    cin >> word;
    cout << "\n";

    //--------------------------------------
    // load the values into main memory
    //--------------------------------------
    load("palindrome.s");

    //--------------------------------------
    // run the accumulator
    //--------------------------------------
    run_accum();

    cout << endl;
    return 0;
}


// load into their memory
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
    return accumRegister[address];
}

//returns letter at spot
string get_char(int index) {
    char c = word.at(index);
    string s(1,c);
    return s;
}

// runs functions of the accumulator
void run_accum() {
    bool user_mode = true;
    int instruction;
    int op;
    int regD;
    int val2;
    int val3;
    int index = 0;
    int loopCounter = 0;
    int loopCounter2 = 0;
    int startingIndex = 0;
    string s1, s2;
    int halfWord = word.length()/2 + 1;
    
    while (user_mode) {
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

            case 1 : // ADDI / SUBI
                // SUBTRACTION
                if (val3/10 > 1) {
                    val3 = val3%10;
                    accumRegister[regD] = get_data(val2) - val3;
                    if (test) {
                        wordIndex--;
                    }
                }

                // ADDITION
                else {
                    accumRegister[regD] = accumRegister[regD] + 1;
                    if (test) {
                        startingIndex++;
                    }
                }

                total_instructions++;
                total_cycles += 6;
                break;

            case 2 : // b
                // EXIT
                if (val3 == 6) {
                    totals();
                    user_mode = false;
                }

                // LENGTH_LOOP
                if (val3 == 3) { 
                    if (loopCounter < word.length()-1) {
                        index -= 4;
                        wordIndex = accumRegister[5];
                    }
                    else {
                        index++;
                    }
                    loopCounter++;  
                }

                // TEST_LOOP
                if (val3 == 1) {
                    if (loopCounter2 < halfWord){
                        index -= 7;
                    }
                    loopCounter2++;
                }

                total_instructions++;
                total_cycles += 4;
                break;

            case 3 : // beq
                if (accumRegister[5] == word.length()) {
                    index += 3;
                }
                total_instructions++;
                total_cycles += 5;
                break;

            case 4 : // bge
                s1 = get_char(startingIndex);
                s2 = get_char(wordIndex);

                // IF CHARACTERS ARE EQUAL...
                if (s1.compare(s2)==0) {
                    // cout << "********* THEY MATCH *********" << endl;
                }

                test = true;

                total_instructions++;  
                total_cycles += 5;           
                break;

            case 5 : // bne
                s1 = get_char(startingIndex);
                s2 = get_char(wordIndex);

                // IF CHARACTERS ARE NOT EQUAL...
                if (s1.compare(s2)!=0) {
                    index +=7;
                }
                
                total_instructions++;
                total_cycles += 5;
                break;

            case 6 : // la
                // set $t1 to the start index of the word
                if (val3 == 20) {
                    accumRegister[regD] = 0;
                }
                // set $t2 to end index of the word
                if (val3 == 25) {
                    accumRegister[regD] = 0;
                }
                
                // is palindrome message
                if (val3 == 21) {
                    cout << is_palin() << endl;
                }

                // not palindrome message
                if (val3 == 22) {
                    cout << not_palin() << endl;
                }

                total_instructions++;
                total_cycles += 5;
                break;

            case 7 : // lb
                accumRegister[regD] = get_data(accumRegister[val2]);

                total_instructions++;
                total_cycles += 6;
                break;

            case 8 : // li
                accumRegister[regD] = get_data(accumRegister[val2]);

                total_instructions++;
                total_cycles += 3;
                break;

            case 9 : // SYSCALL
                total_instructions++;
                total_cycles += 8;
                break;

            default :
                cout << "Program Running...";
        }
        index++;
    }
}


string is_palin() {
    return "\"" + word + "\"" + " is a palindrome";
}

string not_palin() {
    return "\"" + word + "\"" + " is NOT a palindrome";
}

void totals() {
    cout << "\nTOTAL INSTRUCTIONS = " << total_instructions << endl;
    cout << "TOTAL CYCLES = " << total_cycles << endl;
    
    double speedup = (8.0 * total_instructions)/total_cycles;

    cout << "SPEEDUP = " << speedup << endl;
}