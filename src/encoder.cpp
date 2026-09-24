/*
 * encoder.c
 *
 *  Created on: Aug 16, 2026
 *      Author: floresa
 */

#include <iostream>
#include <fstream>
#include "encoder.h"
#include "hash_map.h"
#include "min_heap.h"

void HuffmanEncoder::encode(std::string filename)
{
   std::ifstream file(filename);
   char ch;
   while (file.get(ch))
   {
      std::cout << ch;
   }

   std::cout << std::endl;
}


