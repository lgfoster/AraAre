/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "virtCPU.h"

int main()
{
    printf("I'll see if I can build this emulator\n");

    return 0;
}

/**
 * while(executedCyles < cyclesToExecute)
 * {
 *      opcode = memory[PC++];
 *      instruction = decode(opcode);
 *      execute(instruction);
 * }
 * 
 *  Functions to develop:
 *         decode(unsinged int)
 *         execute(instruction type)
 * 
 */