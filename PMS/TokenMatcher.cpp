
/*
	2017.04.03
	Created by AcrylicShrimp.
*/

#include "TokenMatcher.h"

namespace PMS::Parsing
{
	TokenMatcher::TokenMatcher(const TokenMatcher &sSrc)
	{
		//TODO : Place your implementation of copy constructor here.
		
	}
	
	TokenMatcher::TokenMatcher(TokenMatcher &&sSrc)
	{
		//TODO : Place your implementation of move constructor here.
		
	}

	TokenMatcher &TokenMatcher::operator=(const TokenMatcher &sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of copy assignment operator here.
		
		
		return *this;
	}
	
	TokenMatcher &TokenMatcher::operator=(TokenMatcher &&sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of move assignment operator here.
		
		
		return *this;
	}

	void TokenMatcher::skipWhitespaces()
	{
		using namespace std::literals;

		static const auto sWhitespace{U" \n\r\t"s};
		static const auto nNoPos{std::u32string::npos};

		for (; this->iCurrent != this->iEnd && sWhitespace.find_first_of(*this->iCurrent) != nNoPos; ++this->iCurrent);
	}
	
	bool TokenMatcher::tryMatch(const std::u32string &sToken, bool bMoveCurrent = false)
	{
		this->skipWhitespaces();

		auto iIndex = this->iCurrent;

		for (auto iTokenIndex = sToken.cbegin(), iTokenEnd = sToken.cend(); iTokenIndex != iTokenEnd; ++iIndex, ++iTokenIndex)
			if (iIndex == this->iEnd || *iIndex != *iTokenIndex)
				return false;

		if (bMoveCurrent)
			this->iCurrent = iIndex;

		return true;
	}
}