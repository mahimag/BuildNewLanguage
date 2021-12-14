#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ultron.h"

void ultron_init(Ultron* ultron) {
    // an Ultron object has an integer array of size 32 that represents the memory of the computer.
    int memory[ULTRON_MEMORY_SIZE];
    for(int i=0; i< ULTRON_MEMORY_SIZE; i++){
        ultron->memory[i] = 0;
    }
    // it should initialize two integer variables to represent the program counter and accumulator register. Initialize both to 0. 
    ultron->pc = 0;
    ultron->ac = 0;
}

void ultron_dump(Ultron* ultron) {
    /*
    print out the contents of memory. For example, printing out the contents of an Ultron would print the following. The contents of location 0 is 1010, the contents of location 1 is 2010, and so on.
    */
    printf("PC: %d\n", ultron->pc);
    printf("AC: %d\n", ultron->ac);
    for(int i=0; i<ULTRON_MEMORY_SIZE; i++){
        printf(" %d %d\n", i, ultron_memory(ultron, i));
    }
}

int ultron_memory(Ultron* ultron, int location) { //value at memory
    return ultron->memory[location];
}

int ultron_accumulator(Ultron* ultron) {
    return ultron->ac;
}

int ultron_pc(Ultron* ultron) {
    return ultron->pc;
}

void ultron_load(Ultron* ultron, int size, int* instructions) {
    /*
    copy the size number of instructions from the array of integer instructions into Ultron's memory, starting at memory location 0.
    */
    for(int i = 0; i < size ; i++){
        ultron->memory[i] = *instructions;
        instructions++;
    }
}

/*
Operation is invalid: return -1
Your operation should only be one of the operation values listed in the constants above.
Operand outside the range of allowable memory: return -2.
Your operand should only be in the range of 0 to 31
Program counter outside the range of allowable memory: return -3
Your program counter should only be in the range of 0 to 31
*/
int ultron_run(Ultron* ultron) {
    int result = 0;
    int instruction = ultron->memory[ultron->pc]; // 1010
    int operation = instruction / 100; //10
    int operand = instruction % 100; //10
    while(operation != 43){
        
        if(operation == 10){
            //read value into A
            printf("? ");
            scanf("%d", &ultron->memory[operand]);
            ultron->pc += 1;
        }
        if(operation == 11 ){ //write
            printf("= %d\n", ultron->memory[operand]);
            ultron->pc += 1;
        }
        if(operation == 20 ){ //load
            ultron->ac = ultron->memory[operand];
            ultron->pc += 1;
        }
        if(operation == 21 ){ //store
            ultron->memory[operand] = ultron->ac;
            ultron->pc += 1;
        }
        if(operation == 30 ){ //add
            ultron->ac += ultron->memory[operand];
            ultron->pc += 1;
        }
        if(operation == 31 ){ //subtract
            ultron->ac -= ultron->memory[operand];
            ultron->pc += 1;
        }
        if(operation == 40 ){ //branch neg
            if(ultron->ac < 0){
                ultron->pc = operand;
            }
            else{
                ultron->pc += 1;
            }
        }
        if(operation == 43 ){ //halt
            return 0;
        }
        instruction = ultron->memory[ultron->pc]; // 1010
        operation = instruction / 100; //10
        operand = instruction % 100; //10
    }
    result = 0;
    printf("Result: %d\n", result);
    return result;
}