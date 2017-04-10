
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_AND_BIT_EXPRESSION_H

#define _CLASS_PMS_PARSING_AND_BIT_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class AndBitExpression final
	{
	public:
		AndBitExpression() = delete;
		AndBitExpression(const AndBitExpression &sSrc) = delete;
		AndBitExpression(AndBitExpression &&sSrc) = delete;
		~AndBitExpression() = delete;
		
	public:
		AndBitExpression &operator=(const AndBitExpression &sSrc) = delete;
		AndBitExpression &operator=(AndBitExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif