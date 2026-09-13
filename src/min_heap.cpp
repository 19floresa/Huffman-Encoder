/*
 * min_heap.cpp
 *
 *  Created on: Aug 16, 2026
 *      Author: floresa
 */

#include "min_heap.h"

void MinHeap::insert(char d, uint32_t v)
{
   uint32_t cur, parent;
   const Node_t new_node = { .data = d, .value = v };
   nodes.push_back(new_node);

   cur = nodes.size() - 1;
   while (cur != 0)
   {
      parent = (cur  - 1) / 2;
      if (nodes[parent].value > nodes[cur].value)
      {
         const Node_t temp = nodes[parent];
         nodes[parent] = nodes[cur];
         nodes[cur] = temp;
      }
      else
      {
         // Found spot for node!
         break;
      }
      cur = parent;
   }
}

void MinHeap::pop(void)
{
   for (Node_t node: nodes)
   {
      std::cout << node.data << std::endl;
      //std::cout << node.value << std::endl;
   }
}
