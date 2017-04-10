
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#include "RangeExpression.h"

namespace PMS::Parsing
{
	bool RangeExpression::generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList)
	{
		if (!sTokenIndexer.isMatch(TokenType::Bracket_Open))
			return false;

		bool bFirstExclude = sTokenIndexer.isMatch(TokenType::Circumflex);

		

		if (sTokenIndexer.isMatch(TokenType::Bracket_Close))
			return true;
	}
}