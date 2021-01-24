Natalie Eichorn
903927934

PROGRAM CONTENTS :
- palindrome.s = code produced from the example assembly program (decoded/explained below)
- gprSim.cpp = multi cycle machine
- results.txt = example values

HOW TO RUN PROGRAM :
- download and unzip contents of zip file
- compile gprSim.cpp using a g++ compliler
- run ./gprSim
- enter a word
- view results (whether or not it is a palindrome, IC, C, and speedup)

HOW THE PROGRAM RUNS :
- encoded instructions from palindrome.s are read by gprSim.cpp
- main memory is simulated using an array and instructions are put into memory
- based on the encoded instructions that are in the memory, the switch performs the program.
- the word is determined to be a palindrome or to not be a palindrome
- total instructions, total calculations, and speed up is calculated
- (more detailed notes are in the program comments)

DECODED PALINDROME.S :
- I created this code so my program could read in the instructions. Each instruction consists of 8 numbers. The first two are for the instruction, the second two are for the register destination, the third two are for either a register or a branch, and the fourth two are for either a register or value.

instruction
01 = ADDI / SUB
02 = b
03 = beqz
04 = bge
05 = bne
06 = la
07 = lb
08 = li
09 = syscall

registers
01 = a0
02 = a1
03 = v0
04 = t1
05 = t2
06 = t3
07 = t4

jumps
01 = test_loop
02 = end_length_loop
03 = length_loop
04 = is_palin
05 = not_palin
06 = exit