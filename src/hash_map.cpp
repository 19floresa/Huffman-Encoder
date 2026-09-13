/*
 * hash_map.cpp
 *
 *  Created on: Sep 12, 2026
 *      Author: floresa
 */

#include <iostream>
#include "hash_map.h"

HashMap::HashMap(void)
{
   total_size = 32;
   buckets = std::vector<Node_t>(total_size);
}

void HashMap::insert(std::string s)
{
   std::cout << s << std::endl;
   const uint64_t hash   = fnv_1a_hash(s);
   const uint32_t bucket = calculate_bucket(hash);
}

/**
 * Map hash to a bucket.
 */
uint32_t HashMap::calculate_bucket(uint64_t hash)
{
   return hash % total_size;
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
