
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_CAST_EXPRESSION_H

#define _CLASS_PMS_PARSING_CAST_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class CastExpression final
	{
	public:
		CastExpression() = delete;
		CastExpression(const CastExpression &sSrc) = delete;
		CastExpression(CastExpression &&sSrc) = delete;
		~CastExpression() = delete;
		
	public:
		CastExpression &operator=(const CastExpression &sSrc) = delete;
		CastExpression &operator=(CastExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif