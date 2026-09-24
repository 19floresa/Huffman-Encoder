/*
 * node.h
 *
 *  Created on: Sep 12, 2026
 *      Author: floresa
 */

#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_

#include <string>
#include <cstdint>

typedef struct Node_t
{
   std::string data  = "";
   uint32_t    count = 0;
   Node_t *    left  = nullptr;
   Node_t *    right = nullptr;
} Node_t;

#endif /* INCLUDE_NODE_H_ */
