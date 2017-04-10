
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_EXPRESSION_H

#define _CLASS_PMS_PARSING_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class Expression final
	{
	public:
		Expression() = delete;
		Expression(const Expression &sSrc) = delete;
		Expression(Expression &&sSrc) = delete;
		~Expression() = delete;
		
	public:
		Expression &operator=(const Expression &sSrc) = delete;
		Expression &operator=(Expression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif