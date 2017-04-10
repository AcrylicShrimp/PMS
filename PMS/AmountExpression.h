
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_AMOUNT_EXPRESSION_H

#define _CLASS_PMS_PARSING_AMOUNT_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class AmountExpression final
	{
	public:
		AmountExpression() = delete;
		AmountExpression(const AmountExpression &sSrc) = delete;
		AmountExpression(AmountExpression &&sSrc) = delete;
		~AmountExpression() = delete;
		
	public:
		AmountExpression &operator=(const AmountExpression &sSrc) = delete;
		AmountExpression &operator=(AmountExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif