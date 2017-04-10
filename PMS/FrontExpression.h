
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_FRONT_EXPRESSION_H

#define _CLASS_PMS_PARSING_FRONT_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class FrontExpression final
	{
	public:
		FrontExpression() = delete;
		FrontExpression(const FrontExpression &sSrc) = delete;
		FrontExpression(FrontExpression &&sSrc) = delete;
		~FrontExpression() = delete;
		
	public:
		FrontExpression &operator=(const FrontExpression &sSrc) = delete;
		FrontExpression &operator=(FrontExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif