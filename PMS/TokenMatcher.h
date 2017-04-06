
/*
	2017.04.03
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_TOKEN_MATCHER_H

#define _CLASS_PMS_PARSING_TOKEN_MATCHER_H

#include <string>
#include <utility>

namespace PMS::Parsing
{
	class TokenMatcher
	{
	private:
		std::u32string sContent;
		std::u32string::const_iterator iCurrent;
		std::u32string::const_iterator iEnd;
		
	public:
		TokenMatcher() = default;
		TokenMatcher(const TokenMatcher &sSrc);
		TokenMatcher(TokenMatcher &&sSrc);
		~TokenMatcher() = default;
		
	public:
		TokenMatcher &operator=(const TokenMatcher &sSrc);
		TokenMatcher &operator=(TokenMatcher &&sSrc);
		
	public:
		inline std::u32string &content();
		inline const std::u32string &content() const;
		inline std::u32string::const_iterator &current();
		inline const std::u32string::const_iterator current() const;
		inline bool isEOF() const;

		void skipWhitespaces();
		bool tryMatch(const std::u32string &sToken, bool bMoveCurrent = false);
	};

	inline std::u32string &TokenMatcher::content()
	{
		return this->sContent;
	}

	inline const std::u32string &TokenMatcher::content() const
	{
		return this->sContent;
	}

	inline std::u32string::const_iterator &TokenMatcher::current()
	{
		return this->iCurrent;
	}

	inline const std::u32string::const_iterator TokenMatcher::current() const
	{
		return this->iCurrent;
	}

	inline bool TokenMatcher::isEOF() const
	{
		return this->iCurrent == this->iEnd;
	}
}

#endif