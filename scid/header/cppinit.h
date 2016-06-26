/*
 * cppinit.h
 *
 * Created: 6/11/2016 7:38:45 PM
 *  Author: Kunal Chowdhury
 */ 


#ifndef CPPINIT_H_
#define CPPINIT_H_



#include <stdlib.h>
#include "avr/io.h"

//__extension__ typedef int __guard __attribute__((mode (__DI__)));

void * operator new(size_t size, void * add);

void operator delete(void * ptr);

uint8_t** init_array( uint8_t row, uint8_t col) ;

void deallocate_array(uint8_t ** arr, int rows);

//int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);};

//void __cxa_guard_release (__guard *g) {*(char *)g = 1;};

//void __cxa_guard_abort (__guard *) {};

// TODO - should we check if we need the real address or something allocated
// by malloc - which maybe a bit dicey in case allocation didn't happen.


#endif /* CPPINIT_H_ */