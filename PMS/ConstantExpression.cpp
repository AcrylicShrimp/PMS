
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#include "ConstantExpression.h"

namespace PMS::Parsing
{
	bool ConstantExpression::generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList)
	{
		if (sTokenIndexer.isMatch(TokenType::Literal_Int, false))
		{

		}
		else if (sTokenIndexer.isMatch(TokenType::Literal_Real, false))
		{

		}
		else if (sTokenIndexer.isMatch(TokenType::Literal_String, false))
		{

		}
		else
			return false;

		sTokenIndexer.moveNext();

		return true;
	}
}