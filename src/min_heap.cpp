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
void MinHeap::insert(Node_t node)
{
   uint32_t cur, parent;
   nodes.push_back(node);

   cur = nodes.size() - 1;
   while (cur != 0)
   {
      parent = (cur  - 1) / 2;
      if (nodes[parent].count > nodes[cur].count)
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
std::string MinHeap::pop(void)
{
   uint32_t cur, left, right, least;
   const std::string res = nodes[0].data;
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

         if ((left <= end) && (nodes[least].count > nodes[left].count))
         {
            least = left;
         }

         if ((right <= end) && (nodes[least].count > nodes[right].count))
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
 * Check if the heap is empty.
 */
bool MinHeap::isEmpty(void)
{
   return nodes.size() == 0;
}
