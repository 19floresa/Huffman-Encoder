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

class Node
{
   private:
      char data;
      uint32_t count;

   public:
      Node(char d, uint32_t c);

      char getData(void);

      uint32_t getValue(void);
};

class MinHeap
{
   private:
      std::vector<Node>nodes;

   public:
      void insert(char c);
      void pop(void);
};

#endif /* INCLUDE_MIN_HEAP_H_ */
