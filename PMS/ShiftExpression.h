
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_SHIFT_EXPRESSION_H

#define _CLASS_PMS_PARSING_SHIFT_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class ShiftExpression final
	{
	public:
		ShiftExpression() = delete;
		ShiftExpression(const ShiftExpression &sSrc) = delete;
		ShiftExpression(ShiftExpression &&sSrc) = delete;
		~ShiftExpression() = delete;
		
	public:
		ShiftExpression &operator=(const ShiftExpression &sSrc) = delete;
		ShiftExpression &operator=(ShiftExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif