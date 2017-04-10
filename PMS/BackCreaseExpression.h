
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_BACK_CREASE_EXPRESSION_H

#define _CLASS_PMS_PARSING_BACK_CREASE_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class BackCreaseExpression final
	{
	public:
		BackCreaseExpression() = delete;
		BackCreaseExpression(const BackCreaseExpression &sSrc) = delete;
		BackCreaseExpression(BackCreaseExpression &&sSrc) = delete;
		~BackCreaseExpression() = delete;
		
	public:
		BackCreaseExpression &operator=(const BackCreaseExpression &sSrc) = delete;
		BackCreaseExpression &operator=(BackCreaseExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif