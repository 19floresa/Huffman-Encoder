/*
 * hash_map.cpp
 *
 *  Created on: Sep 12, 2026
 *      Author: floresa
 */

#include <cmath>
#include "hash_map.h"

HashMap::HashMap(void)
{
   total_nodes = 0;
   total_buckets = 32;
   buckets = std::vector<Node_t>(total_buckets);
}

void HashMap::insert(std::string s, uint32_t c)
{
   const uint64_t hash   = fnv_1a_hash(s);
   const uint32_t bucket = calculate_bucket(hash);
   if (buckets[bucket].count == 0)
   {
      // Found empty node!
      insertNode(bucket, s, c);
   }
   else
   {
      // Find empty Node (linear probe)
      // Search right side of hash map.
      uint32_t i;
      for (i = bucket; i < total_buckets; i++)
      {
         if (insertNode(i, s, c))
         {
            break;
         }
      }

      // Search left side of hash map.
      if (i == total_buckets)
      {
         for (i = 0; i < bucket; i++)
         {
            if (insertNode(i, s, c))
            {
               break;
            }
         }
      }
   }

   if (!isBalanced())
   {
      rebalance();
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
   float current_load_factor = static_cast<float>(total_nodes) / total_buckets;
   return (current_load_factor - LOAD_FACTOR) < EPSILON;
#undef LOAD_FACTOR
#undef EPSILON
}

/**
 * Rebalance hash table by creating a new hash table and reinserting old nodes.
 */
void HashMap::rebalance(void)
{
   total_buckets <<= 2;
   const std::vector<Node_t> old_buckets = buckets;
   const std::vector<Node_t> new_buckets(total_buckets);
   buckets = new_buckets;
   for (Node_t bucket: old_buckets)
   {
      insert(bucket.data, bucket.count);
   }
}

/**
 * Insert node into the specified node.
 */
bool HashMap::insertNode(uint32_t i, std::string s, uint32_t c)
{
   if (buckets[i].count == 0)
   {
      buckets[i].data  = s;
      buckets[i].count = c;
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
