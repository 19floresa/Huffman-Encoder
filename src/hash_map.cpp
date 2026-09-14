/*
 * hash_map.cpp
 *
 *  Created on: Sep 12, 2026
 *      Author: floresa
 */

#include <iostream>
#include <cmath>
#include "hash_map.h"

HashMap::HashMap(void)
{
   total_nodes = 0;
   total_buckets = 20;//32;
   buckets = std::vector<Node_t>(total_buckets);
}

void HashMap::insert(std::string s, bool print)
{
   const uint64_t hash   = fnv_1a_hash(s);
   const uint32_t bucket = calculate_bucket(hash);
   if (buckets[bucket].count == 0)
   {
      // Found empty node!
      insertNode(bucket, s, hash);
   }
   else
   {
      // Find empty Node (linear probe)
      // Search right side of hash map.
      uint32_t i;
      for (i = bucket; i < total_buckets; i++)
      {
         if (insertNode(i, s, hash))
         {
            break;
         }
      }

      // Search left side of hash map.
      if (i == total_buckets)
      {
         for (i = 0; i < bucket; i++)
         {
            if (insertNode(i, s, hash))
            {
               break;
            }
         }
      }
   }
//   std::cout << s << std::endl;
//   std::cout << "Hash:   " << hash << std::endl;
//   std::cout << "Bucket: " << bucket << std::endl;

   if (print)
   {
         int j = 0;
         for (Node_t bucket : buckets)
         {
            std::cout << "Index: " << j << std::endl;
            std::cout << "Data:  " << bucket.data << std::endl;
            std::cout << "Count: " << bucket.count << std::endl;
            j += 1;
         }
   }
}

/**
 * Map hash to a bucket.
 */
uint32_t HashMap::calculate_bucket(uint64_t hash)
{
   return hash % total_buckets;
}

/**
 * Hash function from: https://benhoyt.com/writings/hash-table-in-c/#hash-tables
 *
 * Other resources:
 *    https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
 *    https://toolkitbay.com/tools/encryption/fnv-1
 */
uint64_t HashMap::fnv_1a_hash(std::string s)
{
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL
   uint64_t hash = FNV_OFFSET;
   for (char c: s)
   {
      hash ^= (uint64_t)(unsigned char)c;
      hash *= FNV_PRIME;
   }
   return hash;
#undef FNV_OFFSET
#undef FNV_PRIME
}

/**
 * Check if their is still enough space before we need to rebuild
 * the hash map.
 *
 * Source: https://en.wikipedia.org/wiki/Hash_table
 */
bool HashMap::isBalanced(void)
{
#define LOAD_FACTOR 0.75f
#define EPSILON 1e-5f
#define ARE_FLOAT_EQUAL(a,b) std::fabs(a - b) < EPSILON
   const float current_load_factor = total_nodes / total_buckets;
   return ARE_FLOAT_EQUAL(current_load_factor, LOAD_FACTOR);
#undef LOAD_FACTOR
#undef EPSILON
#undef ARE_FLOAT_EQUAL
}

bool HashMap::insertNode(uint32_t i, std::string s, uint32_t hash)
{
   if (buckets[i].count == 0)
   {
      buckets[i].data  = s;
      buckets[i].count = 1;
      buckets[i].hash  = hash;
      total_nodes += 1;
      return true;
   }
   else if (buckets[i].data == s)
   {
      buckets[i].count += 1;
      return true;
   }
   return false;
}
