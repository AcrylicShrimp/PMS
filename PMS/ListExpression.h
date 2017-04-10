
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_LIST_EXPRESSION_H

#define _CLASS_PMS_PARSING_LIST_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class ListExpression final
	{
	public:
		ListExpression() = delete;
		ListExpression(const ListExpression &sSrc) = delete;
		ListExpression(ListExpression &&sSrc) = delete;
		~ListExpression() = delete;
		
	public:
		ListExpression &operator=(const ListExpression &sSrc) = delete;
		ListExpression &operator=(ListExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif