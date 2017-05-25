# Cache-Simulator
Direct Mapping and 2-Way set associative mapping used with LRU and FIFO replacement techniques

This program simulates the interaction between cache and memory whenever a address is asked by the processor.

For running the program open your terminal in the root directory of the program and run below command - 
  ./runner.sh "INPUT FILE"
Where "INPUT FILE" can be any text file with hexadecimal addresses (depicting address in main memory).

The following inpur files are being already added in the input directory of project : 
./input/1024_input.txt
./input/2048_input.txt
./input/4096_input.txt
./input/8192_input.txt
./input/16384_input.txt

Running Command Example : "./runner.sh ./input/1024_input.txt"
Output Example : 
            LRU     FIFO
Direct : 0.705950 0.705950 
2-Way  : 0.708300 0.711350 
