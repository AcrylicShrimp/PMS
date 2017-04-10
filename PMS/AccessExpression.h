
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_ACCESS_EXPRESSION_H

#define _CLASS_PMS_PARSING_ACCESS_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class AccessExpression final
	{
	public:
		AccessExpression() = delete;
		AccessExpression(const AccessExpression &sSrc) = delete;
		AccessExpression(AccessExpression &&sSrc) = delete;
		~AccessExpression() = delete;

	public:
		AccessExpression &operator=(const AccessExpression &sSrc) = delete;
		AccessExpression &operator=(AccessExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif