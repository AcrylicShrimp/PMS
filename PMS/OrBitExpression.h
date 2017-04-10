
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_OR_BIT_EXPRESSION_H

#define _CLASS_PMS_PARSING_OR_BIT_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class OrBitExpression final
	{
	public:
		OrBitExpression() = delete;
		OrBitExpression(const OrBitExpression &sSrc) = delete;
		OrBitExpression(OrBitExpression &&sSrc) = delete;
		~OrBitExpression() = delete;
		
	public:
		OrBitExpression &operator=(const OrBitExpression &sSrc) = delete;
		OrBitExpression &operator=(OrBitExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif