
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_NOT_EXPRESSION_H

#define _CLASS_PMS_PARSING_NOT_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class NotExpression final
	{
	public:
		NotExpression() = delete;
		NotExpression(const NotExpression &sSrc) = delete;
		NotExpression(NotExpression &&sSrc) = delete;
		~NotExpression() = delete;
		
	public:
		NotExpression &operator=(const NotExpression &sSrc) = delete;
		NotExpression &operator=(NotExpression &&sSrc) = delete;

	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif