//============================================================================
// Name        : Huffman-Encoder.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include "encoder.h"
#include "min_heap.h"

int main(void)
{
   MinHeap min_heap = MinHeap();
   min_heap.insert('e', 5);
   min_heap.insert('a', 1);
   min_heap.insert('b', 2);
   min_heap.insert('d', 4);
   min_heap.insert('c', 3);
   min_heap.pop();
	return 0;
}
