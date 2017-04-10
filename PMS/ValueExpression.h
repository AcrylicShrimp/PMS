
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_VALUE_EXPRESSION_H

#define _CLASS_PMS_PARSING_VALUE_EXPRESSION_H

#include "Instance.h"
#include "TokenIndexer.h"

namespace PMS::Parsing
{
	class ValueExpression
	{	
	public:
		ValueExpression() = delete;
		ValueExpression(const ValueExpression &sSrc) = delete;
		ValueExpression(ValueExpression &&sSrc) = delete;
		~ValueExpression() = delete;
		
	public:
		ValueExpression &operator=(const ValueExpression &sSrc) = delete;
		ValueExpression &operator=(ValueExpression &&sSrc) = delete;
		
	public:
		bool tryMatch();
	};
}

#endif