/*
 * min_heap.cpp
 *
 *  Created on: Aug 16, 2026
 *      Author: floresa
 */

#include "min_heap.h"

class Node
{
   private:
      char data;
      uint32_t count;

   public:
      Node(char d, uint32_t c)
      {
         data = d;
         count = c;
      }

      char getData(void)
      {
         return data;
      }

      uint32_t getValue(void)
      {
         return count;
      }
};

void MinHeap::insert(char c)
{
   std::cout << c;
}
