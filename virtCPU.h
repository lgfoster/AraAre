/**
 * @file virtCPU.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef VIRTCPU_H
#define VIRTCPU_H


#include <stdio.h>

typedef union
{
    __uint32_t w;
    __uint16_t x;           /* Access as a double 16 bit register*/
    
    struct
    {
        __uint8_t l, h;     /* Low and high bytes of register*/
        __uint16_t pad;     /* Little-endian padding */

    };

} i8080Reg;


struct i8080Context
{
    i8080Reg AF; /* Register AF (Accumulator + Flags) */
    i8080Reg BC; /* Register BC (B + C) */
    i8080Reg DE; /* Register DE (D + E) */
    i8080Reg HL; /* Register HL (H + L) */

    __uint16_t PC;      /* Program Counter */
    __uint16_t SP;      /* Stack Pointer */
    __uint32_t flagC;   /* Carry flag */
    __uint32_t flagZPS; /* Zero, Parity and Negative flags */
    __uint32_t flagAc;  /* Auxiliary Carry flag (4-bit carry) */

    __uint32_t halted;          /* CPU is in Halt state. */
    __uint32_t intEnabled;      /* Interrupts are enabled or disabled */
    __uint32_t intPending;      /* Stores if there is a pending interrupt */
    __uint16_t intAddress;      /* Stores the start address for the interrupt handling routine */
    __uint16_t NMIAddress;      /* Stores the start address for the NMI rutine */
    __uint32_t NMIPending;      /* Stores if there is a pending nmi */

    __uint8_t *mainMemory;      /* Pointer to the main memory */

    struct readMemoryHandler *readMemoryHandler;   /* List of memory handlers for reading */
    struct writeMemoryHandler *writeMemoryHandler; /* List of memory handlers for writing */
    struct readIOHandler *readIOHandler;           /* List of IO handlers for reading */
    struct writeIOHandler *writeIOHandler;         /* List of IO handlers for writing */
    
    __uint32_t numMemoryBanks;          /* Number of banks of memory (0 - 64) */
    void *pBankList;                /* List of pointers to the bank memory regions */

    __uint32_t cycleCount;              /* Number of executed cycles */
    __uint32_t opcodeStatistics[256];   /* Number of times an opcode has been executed */
    __uint32_t tracePC[256];            /* Stores the last 256 PCs */
    __uint32_t traceIndex;              /* Last entry in the PC trace buffer */
};


#endif /* VIRTCPU_H */