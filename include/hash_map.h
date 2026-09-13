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
      const float load_factor = 0.60f;
      uint32_t total_size = 0;
      uint32_t hash_function(char c);
      float calculate_load_factor(void);

   public:
      HashMap(void);
      void insert(std::string s);

};


#endif /* INCLUDE_HASH_MAP_H_ */
