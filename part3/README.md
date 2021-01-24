Natalie Eichorn
903927934

PROGRAM CONTENTS :
- lab3c.s = code produced from the example assembly program (decoded/explained below)
- pipeSim.cpp = pipeline

HOW TO RUN PROGRAM :
- download and unzip contents of zip file
- compile gprSim.cpp using a g++ compliler
- run ./pipeSim
- view results (IC, C, NOPs, and speedup)

HOW THE PROGRAM RUNS :
- encoded instructions from lab3c.s are read by pipeSim.cpp
- main memory is simulated using an array and instructions are put into memory
- based on the encoded instructions that are in the memory, the switch performs the program.
- total instructions, total calculations, total NOPs, and speed up is calculated
- (more detailed notes are in the program comments)

RESULTS :
- TOTAL INSTRUCTIONS = 51
- TOTAL CYCLES = 255
- TOTAL NOPS = 8
- SPEEDUP = 1.6

DECODED lab3c.S :
- I created this code so my program could read in the instructions. Each instruction consists of 8 numbers. The first two are for the instruction, the second two are for the register destination, the third two are for either a register or a branch, and the fourth two are for either a register or value.

instruction
01 = li
02 = bge
03 = add
04 = sub
05 = nop
06 = syscall

registers
01 = $1
02 = $2
03 = $3
04 = $4
05 = $5