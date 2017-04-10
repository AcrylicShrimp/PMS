
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_VALUE_EXPRESSION_H

#define _CLASS_PMS_PARSING_VALUE_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class ValueExpression final
	{	
	public:
		ValueExpression() = delete;
		ValueExpression(const ValueExpression &sSrc) = delete;
		ValueExpression(ValueExpression &&sSrc) = delete;
		~ValueExpression() = delete;
		
	public:
		ValueExpression &operator=(const ValueExpression &sSrc) = delete;
		ValueExpression &operator=(ValueExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif