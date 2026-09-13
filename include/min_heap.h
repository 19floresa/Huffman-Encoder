/*
 * min_heap.h
 *
 *  Created on: Aug 16, 2026
 *      Author: floresa
 */

#ifndef INCLUDE_MIN_HEAP_H_
#define INCLUDE_MIN_HEAP_H_

#include <vector>
#include <iostream>

typedef struct
{
   char data;
   uint32_t value;
} Node_t;

class MinHeap
{
   private:
     std::vector<Node_t> nodes = {};

   public:
      void insert(char d, uint32_t c);
      void pop(void);
};

#endif /* INCLUDE_MIN_HEAP_H_ */
