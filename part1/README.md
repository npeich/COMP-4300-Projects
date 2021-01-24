Natalie Eichorn
903927934

PROGRAM CONTENTS :
- quadratic_eval.s = corrected assembly code with comments
- stackSim.cpp = simulated stack machine
- stackCode.txt = file with binray instructions, read by stackSim.cpp
- accumSim.cpp = simulated accumulator machine
- accumCode.txt = file with binray instructions, read by accumSim.cpp

HOW TO RUN PROGRAM :
- download and unzip contents of zip file
- compile stackSim.cpp using a g++ compliler
- compile accumSim.cpp using a g++ compliler
- run ./stackSim (the top of the stack will be printed)
- run ./accumSim (the register will be printed)

HOW THE PROGRAM RUNS :
- binary encoded instructions and data from stackCode.txt/accumCode.txt are read into main memory using load()
- main memory is simulated using 2 arrays, 1 for instructions (text_memory) and 1 for data (data_memory)
- for the accumulator, I used a register array and a storage array to mimic the ALU and accumulator register
- instructions are carried out using the run_stack() or run_accum() function
	- utilizes read_data() to get the value of the memory address
	- prints the top of the stack/data in register which is the answer to the quadratic equation (answer = 82)

HEADS UP/MISTAKES :
- I probably messed up the data types.  I was confused on how to implement them so I just did what I knew how to do based off of the project description.
- I did not need a write function since all my operations happened on the stack using the values of the addresses
	- Maybe I was supposed to create a 5th address to store the answers?? It wasn't clear to me
- Overall, I think that this is a dumbed down version of what was laid out in the description, but my program still represents what the project was intended to do. It reads encoded instructions and data, puts them into designated memory arrays, reads addresses to return their values, operates a simulated stack machine, and returns the correct value by using the given instructions. I understood the logic, just not how to represent it how it might've needed to be.