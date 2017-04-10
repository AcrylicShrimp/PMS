
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_AND_EXPRESSION_H

#define _CLASS_PMS_PARSING_AND_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class AndExpression final
	{
	public:
		AndExpression() = delete;
		AndExpression(const AndExpression &sSrc) = delete;
		AndExpression(AndExpression &&sSrc) = delete;
		~AndExpression() = delete;
		
	public:
		AndExpression &operator=(const AndExpression &sSrc) = delete;
		AndExpression &operator=(AndExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif