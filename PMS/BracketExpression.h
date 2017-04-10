
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_BRACKET_EXPRESSION_H

#define _CLASS_PMS_PARSING_BRACKET_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class BracketExpression final
	{
	public:
		BracketExpression() = delete;
		BracketExpression(const BracketExpression &sSrc) = delete;
		BracketExpression(BracketExpression &&sSrc) = delete;
		~BracketExpression() = delete;
		
	public:
		BracketExpression &operator=(const BracketExpression &sSrc) = delete;
		BracketExpression &operator=(BracketExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif