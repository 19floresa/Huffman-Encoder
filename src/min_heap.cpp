/*
 * min_heap.cpp
 *
 *  Created on: Aug 16, 2026
 *      Author: floresa
 */

#include "min_heap.h"

/**
 * Insert item to the heap.
 */
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
         // Found new spot!
         break;
      }
      cur = parent;
   }
}

/**
 * Remove item from the heap;
 */
char MinHeap::pop(void)
{
   uint32_t cur, left, right, least;
   const char res = nodes[0].data;
   const uint32_t end = nodes.size() - 1;

   // Remove last element
   nodes[0] = nodes[end];
   nodes.pop_back();

   if (!nodes.empty())
   {
      cur = 0;
      while (cur != end)
      {
         left  = (cur * 2) + 1;
         right = (cur * 2) + 2;
         least = cur;

         if ((left <= end) && (nodes[least].value > nodes[left].value))
         {
            least = left;
         }

         if ((right <= end) && (nodes[least].value > nodes[right].value))
         {
            least = right;
         }

         if (least == cur)
         {
            // Found new spot!
            break;
         }
         else
         {
            const Node_t temp = nodes[cur];
            nodes[cur] = nodes[least];
            nodes[least] = temp;
            cur = least;
         }
      }
   }
   return res;
}

/**
 * Get the size of the heap.
 */
uint32_t MinHeap::size(void)
{
   return nodes.size();
}
