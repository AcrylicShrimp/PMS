
/*
	2017.04.03
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_IF_STATEMENT_H

#define _CLASS_PMS_PARSING_IF_STATEMENT_H

#include "TokenMatcher.h"

#include <utility>

namespace PMS::Parsing
{
	class IfStatement
	{
	private:

		
	public:
		IfStatement() = default;
		IfStatement(const IfStatement &sSrc);
		IfStatement(IfStatement &&sSrc);
		~IfStatement() = default;
		
	public:
		IfStatement &operator=(const IfStatement &sSrc);
		IfStatement &operator=(IfStatement &&sSrc);
		
	public:
		
	};
}

#endif