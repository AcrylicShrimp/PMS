
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#include "ValueExpression.h"

namespace PMS::Parsing
{
	bool ValueExpression::generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList)
	{
		if (sTokenIndexer.isMatch(TokenType::Identifier))
		{

			return true;
		}
	}
}