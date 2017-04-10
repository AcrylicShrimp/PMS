
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_ASSIGN_EXPRESSION_H

#define _CLASS_PMS_PARSING_ASSIGN_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class AssignExpression final
	{
	public:
		AssignExpression() = delete;
		AssignExpression(const AssignExpression &sSrc) = delete;
		AssignExpression(AssignExpression &&sSrc) = delete;
		~AssignExpression() = delete;
		
	public:
		AssignExpression &operator=(const AssignExpression &sSrc) = delete;
		AssignExpression &operator=(AssignExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif