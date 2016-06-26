/*
 * cppinit.cpp
 *
 * Created: 6/14/2016 10:54:02 AM
 *  Author: Ireena
 */ 

#include "header/inc.h"

void * operator new(size_t size, void * add)
{
	//void *p =nullptr;
	//switch(instance_num)
	//{
	//case 1:
	//p = (LCDDisplay *)add;
	//break;
	//
	//case 2:
	//return (coordinator *)add ;
	//break;
	//
	//default:
	//return add;
	//}
	
	return add;
	//return malloc(size);
}

//void * operator new[](size_t size, void* add)
//{
	//return add;
//}

void operator delete(void * ptr)

{
	free(ptr);
}


uint8_t** init_array( uint8_t rows, uint8_t cols)
{
	uint8_t** arr;
	arr = (uint8_t **)malloc(rows * sizeof(uint8_t *));
	for(int i = 0 ; i < rows ; i++)
	{
		arr[i] =  (uint8_t *)malloc(cols * sizeof(uint8_t));
		
	}
	return arr;
}

void deallocate_array(uint8_t ** arr, int rows)
{
	for(int i = 0; i < rows ; i++)
	{
		free(arr[i]);
		
	}
	free(arr);
}

