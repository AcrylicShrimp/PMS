
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_ADD_EXPRESSION_H

#define _CLASS_PMS_PARSING_ADD_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class AddExpression final
	{
	public:
		AddExpression() = delete;
		AddExpression(const AddExpression &sSrc) = delete;
		AddExpression(AddExpression &&sSrc) = delete;
		~AddExpression() = delete;
		
	public:
		AddExpression &operator=(const AddExpression &sSrc) = delete;
		AddExpression &operator=(AddExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif