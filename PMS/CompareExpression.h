
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_COMPARE_EXPRESSION_H

#define _CLASS_PMS_PARSING_COMPARE_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class CompareExpression final
	{
	public:
		CompareExpression() = delete;
		CompareExpression(const CompareExpression &sSrc) = delete;
		CompareExpression(CompareExpression &&sSrc) = delete;
		~CompareExpression() = delete;
		
	public:
		CompareExpression &operator=(const CompareExpression &sSrc) = delete;
		CompareExpression &operator=(CompareExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif