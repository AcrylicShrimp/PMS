
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_CALL_EXPRESSION_H

#define _CLASS_PMS_PARSING_CALL_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class CallExpression final
	{
	public:
		CallExpression() = delete;
		CallExpression(const CallExpression &sSrc) = delete;
		CallExpression(CallExpression &&sSrc) = delete;
		~CallExpression() = delete;
		
	public:
		CallExpression &operator=(const CallExpression &sSrc) = delete;
		CallExpression &operator=(CallExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif