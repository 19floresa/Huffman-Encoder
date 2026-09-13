/*
 * hash_map.h
 *
 *  Created on: Sep 12, 2026
 *      Author: floresa
 */

#ifndef INCLUDE_HASH_MAP_H_
#define INCLUDE_HASH_MAP_H_

#include <vector>
#include <string>
#include "node.h"

class HashMap
{
   private:
      std::vector<Node_t> buckets = {};
      uint32_t total_buckets = 0;
      uint32_t total_nodes = 0;
      uint64_t fnv_1a_hash(std::string s);
      uint32_t calculate_bucket(uint64_t hash);
      bool isBalanced(void);

   public:
      HashMap(void);
      void insert(std::string s);

};


#endif /* INCLUDE_HASH_MAP_H_ */
