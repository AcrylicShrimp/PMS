
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_CONSTANT_EXPRESSION_H

#define _CLASS_PMS_PARSING_CONSTANT_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class ConstantExpression final
	{
	public:
		ConstantExpression() = delete;
		ConstantExpression(const ConstantExpression &sSrc) = delete;
		ConstantExpression(ConstantExpression &&sSrc) = delete;
		~ConstantExpression() = delete;
		
	public:
		ConstantExpression &operator=(const ConstantExpression &sSrc) = delete;
		ConstantExpression &operator=(ConstantExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif