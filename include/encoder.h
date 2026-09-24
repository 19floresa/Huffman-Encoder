/*
 * encoder.h
 *
 *  Created on: Aug 16, 2026
 *      Author: floresa
 */

#ifndef INCLUDE_ENCODER_H_
#define INCLUDE_ENCODER_H_

#include "node.h"

class HuffmanEncoder
{
   private:
      Node_t encodedTree = {};
   public:
      void encode(std::string filename);
};


#endif /* INCLUDE_ENCODER_H_ */
