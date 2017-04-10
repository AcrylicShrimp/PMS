
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_POWER_EXPRESSION_H

#define _CLASS_PMS_PARSING_POWER_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class PowerExpression final
	{
	public:
		PowerExpression() = delete;
		PowerExpression(const PowerExpression &sSrc) = delete;
		PowerExpression(PowerExpression &&sSrc) = delete;
		~PowerExpression() = delete;

	public:
		PowerExpression &operator=(const PowerExpression &sSrc) = delete;
		PowerExpression &operator=(PowerExpression &&sSrc) = delete;

	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif