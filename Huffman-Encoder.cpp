//============================================================================
// Name        : Huffman-Encoder.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include "encoder.h"
#include "decoder.h"

int main(void)
{
   HuffmanEncoder huffman_encoder = HuffmanEncoder();
   huffman_encoder.encode("text/normal1.txt");
   return 0;
}
