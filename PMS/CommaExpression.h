
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_COMMA_EXPRESSION_H

#define _CLASS_PMS_PARSING_COMMA_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class CommaExpression final
	{
	public:
		CommaExpression() = delete;
		CommaExpression(const CommaExpression &sSrc) = delete;
		CommaExpression(CommaExpression &&sSrc) = delete;
		~CommaExpression() = delete;

	public:
		CommaExpression &operator=(const CommaExpression &sSrc) = delete;
		CommaExpression &operator=(CommaExpression &&sSrc) = delete;

	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif