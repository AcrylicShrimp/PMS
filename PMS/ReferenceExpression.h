
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_REFERENCE_EXPRESSION_H

#define _CLASS_PMS_PARSING_REFERENCE_EXPRESSION_H

#include "Executable.h"
#include "Instance.h"
#include "Splitter.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class ReferenceExpression final
	{
	public:
		ReferenceExpression() = delete;
		ReferenceExpression(const ReferenceExpression &sSrc) = delete;
		ReferenceExpression(ReferenceExpression &&sSrc) = delete;
		~ReferenceExpression() = delete;
		
	public:
		ReferenceExpression &operator=(const ReferenceExpression &sSrc) = delete;
		ReferenceExpression &operator=(ReferenceExpression &&sSrc) = delete;
		
	public:
		static bool generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList);
	};
}

#endif