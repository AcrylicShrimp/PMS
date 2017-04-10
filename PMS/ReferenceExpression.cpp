
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#include "ReferenceExpression.h"

namespace PMS::Parsing
{
	bool ReferenceExpression::generateInstruction(TokenIndexer sTokenIndexer, Runtime::Executable &sExecutable, ErrorList &sErrorList)
	{
		if (!sTokenIndexer.isMatch(TokenType::Keyword_Ref))
			return false;


	}
}