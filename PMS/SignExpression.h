
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_SIGN_EXPRESSION_H

#define _CLASS_PMS_PARSING_SIGN_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class SignExpression final
	{
	public:
		SignExpression() = delete;
		SignExpression(const SignExpression &sSrc) = delete;
		SignExpression(SignExpression &&sSrc) = delete;
		~SignExpression() = delete;
		
	public:
		SignExpression &operator=(const SignExpression &sSrc) = delete;
		SignExpression &operator=(SignExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif