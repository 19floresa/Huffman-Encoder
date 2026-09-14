//============================================================================
// Name        : Huffman-Encoder.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include "encoder.h"
#include "decoder.h"
#include "min_heap.h"
#include "hash_map.h"

int main(void)
{
   HashMap hash_map;
   hash_map.insert("Hello World!");
   hash_map.insert("How are you?");
   hash_map.insert("I am good!");
   hash_map.insert("c");
   hash_map.insert("c");
   hash_map.insert("c");
   hash_map.insert("c");
   hash_map.insert("c");
   hash_map.insert("c");
   hash_map.insert("a");
   hash_map.insert("b");
   hash_map.insert("d");
   hash_map.insert("e");
   return 0;
}
