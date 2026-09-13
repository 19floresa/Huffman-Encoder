/*
 * min_heap.h
 *
 *  Created on: Aug 16, 2026
 *      Author: floresa
 */

#ifndef INCLUDE_MIN_HEAP_H_
#define INCLUDE_MIN_HEAP_H_

#include <vector>
#include "node.h"

class MinHeap
{
   private:
     std::vector<Node_t> nodes = {};

   public:
      void insert(Node_t node);
      std::string pop(void);
      bool isEmpty(void);
};

#endif /* INCLUDE_MIN_HEAP_H_ */
