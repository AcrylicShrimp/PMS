
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_MUL_EXPRESSION_H

#define _CLASS_PMS_PARSING_MUL_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class MulExpression final
	{
	public:
		MulExpression() = delete;
		MulExpression(const MulExpression &sSrc) = delete;
		MulExpression(MulExpression &&sSrc) = delete;
		~MulExpression() = delete;
		
	public:
		MulExpression &operator=(const MulExpression &sSrc) = delete;
		MulExpression &operator=(MulExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif