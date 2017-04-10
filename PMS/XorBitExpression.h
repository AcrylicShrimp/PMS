
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_XOR_BIT_EXPRESSION_H

#define _CLASS_PMS_PARSING_XOR_BIT_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class XorBitExpression final
	{
	public:
		XorBitExpression() = delete;
		XorBitExpression(const XorBitExpression &sSrc) = delete;
		XorBitExpression(XorBitExpression &&sSrc) = delete;
		~XorBitExpression() = delete;
		
	public:
		XorBitExpression &operator=(const XorBitExpression &sSrc) = delete;
		XorBitExpression &operator=(XorBitExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif