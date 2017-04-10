
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_RANGE_EXPRESSION_H

#define _CLASS_PMS_PARSING_RANGE_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class RangeExpression final
	{
	public:
		RangeExpression() = delete;
		RangeExpression(const RangeExpression &sSrc) = delete;
		RangeExpression(RangeExpression &&sSrc) = delete;
		~RangeExpression() = delete;
		
	public:
		RangeExpression &operator=(const RangeExpression &sSrc) = delete;
		RangeExpression &operator=(RangeExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif