# COMP-4300-Projects
Projects from Comp 4300 - Computer Architecture

By : Natalie Eichorn

Auburn University, Fall 2020

Projects were completed in COMP 4300 - Computer Architecture.

Programs written in C++ and assembly language.


# Part 1:
- binary encoded instructions and data from stackCode.txt/accumCode.txt are read into main memory using load()
- main memory is simulated using 2 arrays, 1 for instructions (text_memory) and 1 for data (data_memory)
- for the accumulator, I used a register array and a storage array to mimic the ALU and accumulator register
- instructions are carried out using the run_stack() or run_accum() function
	- utilizes read_data() to get the value of the memory address
	- prints the top of the stack/data in register which is the answer to the quadratic equation (answer = 82)
  
  
# Part 2:
- encoded instructions from palindrome.s are read by gprSim.cpp
- main memory is simulated using an array and instructions are put into memory
- based on the encoded instructions that are in the memory, the switch performs the program.
- the word is determined to be a palindrome or to not be a palindrome
- total instructions, total calculations, and speed up is calculated
- (more detailed notes are in the program comments) 


# Part 3: 
- encoded instructions from lab3c.s are read by pipeSim.cpp
- main memory is simulated using an array and instructions are put into memory
- based on the encoded instructions that are in the memory, the switch performs the program.
- total instructions, total calculations, total NOPs, and speed up is calculated
- (more detailed notes are in the program comments)
