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

typedef struct
{
   std::string data  = "";
   uint32_t    count = 0;
} Node_t;

#endif /* INCLUDE_NODE_H_ */
