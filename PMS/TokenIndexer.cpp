
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#include "TokenIndexer.h"

namespace PMS::Parsing
{
	TokenIndexer::TokenIndexer(const TokenList &sTokenList) :
		iCurrent{sTokenList.cbegin()},
		iEnd{sTokenList.cend()}
	{
		//Empty.
	}
	
	TokenIndexer::TokenIndexer(const TokenIndexer &sSrc) :
		iCurrent{sSrc.iCurrent},
		iEnd{sSrc.iEnd},
		sIndexStack{sSrc.sIndexStack}
	{
		//Empty.
	}
	
	TokenIndexer::TokenIndexer(TokenIndexer &&sSrc) :
		iCurrent{sSrc.iCurrent},
		iEnd{sSrc.iEnd},
		sIndexStack{std::move(sSrc.sIndexStack)}
	{
		//Empty.
	}
	
	TokenIndexer &TokenIndexer::operator=(const TokenIndexer &sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		this->iCurrent = sSrc.iCurrent;
		this->iEnd = sSrc.iEnd;
		this->sIndexStack = sSrc.sIndexStack;
		
		return *this;
	}
	
	TokenIndexer &TokenIndexer::operator=(TokenIndexer &&sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		this->iCurrent = sSrc.iCurrent;
		this->iEnd = sSrc.iEnd;
		this->sIndexStack = std::move(sSrc.sIndexStack);
		
		return *this;
	}
}