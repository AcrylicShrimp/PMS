
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_FRONT_CREASE_EXPRESSION_H

#define _CLASS_PMS_PARSING_FRONT_CREASE_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class FrontCreaseExpression final
	{
	public:
		FrontCreaseExpression() = delete;
		FrontCreaseExpression(const FrontCreaseExpression &sSrc) = delete;
		FrontCreaseExpression(FrontCreaseExpression &&sSrc) = delete;
		~FrontCreaseExpression() = delete;
		
	public:
		FrontCreaseExpression &operator=(const FrontCreaseExpression &sSrc) = delete;
		FrontCreaseExpression &operator=(FrontCreaseExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif