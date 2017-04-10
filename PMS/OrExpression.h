
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_OR_EXPRESSION_H

#define _CLASS_PMS_PARSING_OR_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class OrExpression final
	{
	public:
		OrExpression() = delete;
		OrExpression(const OrExpression &sSrc) = delete;
		OrExpression(OrExpression &&sSrc) = delete;
		~OrExpression() = delete;

	public:
		OrExpression &operator=(const OrExpression &sSrc) = delete;
		OrExpression &operator=(OrExpression &&sSrc) = delete;

	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif