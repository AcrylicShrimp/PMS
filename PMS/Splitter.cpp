
/*
	2017.03.30
	Created by AcrylicShrimp.
*/

#include "Splitter.h"

namespace PMS::Parsing
{
	std::basic_regex<char32_t> Splitter::sBinaryInteger{U"^[+-]0[bB][01]+"};
	std::basic_regex<char32_t> Splitter::sDecimalInteger{U"^[+-]?[0123456789]+"};
	std::basic_regex<char32_t> Splitter::sHexadecimalInteger{U"^[+-]0[xX][0123456789abcdefABCDEF]+"};
	std::basic_regex<char32_t> Splitter::sDecimalReal{U"^[+-]?(?:[0123456789]*\\.)?[0123456789]+(?:[eE][+-]?[0123456789]+)?"};

	std::vector<SplitToken> Splitter::splitAll(const std::u32string &sContent, std::vector<ErrorInfo> &sErrorList)
	{
		std::size_t nLine{0u};
		std::vector<SplitToken> sTokenList;

		auto iIndex{sContent.cbegin()};
		auto iEnd{sContent.cend()};

		while (nLine += Splitter::skipWhitespaces(iIndex, iEnd), iIndex != iEnd)
		{
			if (Splitter::tryMatchKeyword(iIndex, iEnd, U"/*", true))
			{
				for (auto nCurrentLine = nLine; !Splitter::tryMatchKeyword(iIndex, iEnd, U"*/", true); ++iIndex)
					if (iIndex == iEnd)
					{
						sErrorList.emplace_back(TokenType::Comment_Begin, nCurrentLine, U"/*", U"Unexpected end of file reached.");

						return sTokenList;
					}
					else if (*iIndex == U'\n')
						++nLine;
			}
			else if (Splitter::tryMatchKeyword(iIndex, iEnd, U"//", true))
			{
				for (; iIndex != iEnd && *iIndex != U'\n'; ++iIndex);

				if (iIndex == iEnd)
					return sTokenList;

				++nLine;
			}

			//Numeric literals.
			if (Splitter::tryParseNumericalLiteral(nLine, iIndex, iEnd, sTokenList))
				continue;

			//String literals.
			if (Splitter::tryParseStringLiteral(nLine, iIndex, iEnd, sTokenList, sErrorList))
				continue;

			//Operators
			if (*iIndex == U'+')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"++", TokenType::Plus_Double))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"+=", TokenType::Assign_Add))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"+", TokenType::Plus))
					continue;
			}
			else if (*iIndex == U'-')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"--", TokenType::Minus_Double))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"-=", TokenType::Assign_Subtract))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"->", TokenType::Arrow_Left))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"-", TokenType::Minus))
					continue;
			}
			else if (*iIndex == U'*')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"**=", TokenType::Assign_Power))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"**", TokenType::Asterisk_Double))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"*=", TokenType::Assign_Multiply))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"*", TokenType::Asterisk))
					continue;
			}
			else if (*iIndex == U'/')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"/=", TokenType::Assign_Divide))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"/", TokenType::Slash))
					continue;
			}
			else if (*iIndex == U'%')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"%=", TokenType::Assign_Modulo))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"%", TokenType::Percent))
					continue;
			}
			else if (*iIndex == U'!')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"!=", TokenType::Not_Equals))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"!", TokenType::Exclamation))
					continue;
			}
			else if (*iIndex == U'&')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"&&", TokenType::Ampersand_Double))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"&=", TokenType::Assign_And))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"&", TokenType::Ampersand))
					continue;
			}
			else if (*iIndex == U'|')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"||", TokenType::Vertical_Double))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"|=", TokenType::Assign_Or))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"|", TokenType::Vertical))
					continue;
			}
			else if (*iIndex == U'=')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"==", TokenType::Equals))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"=", TokenType::Assign))
					continue;
			}
			else if (*iIndex == U'<')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"<<=", TokenType::Assign_Shift_Left))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"<<", TokenType::Shift_Left))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"<=", TokenType::Less_Equals))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"<", TokenType::Angle_Bracket_Open))
					continue;
			}
			else if (*iIndex == U'>')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U">>=", TokenType::Assign_Shift_Right))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U">>", TokenType::Shift_Right))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U">=", TokenType::Greater_Equals))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U">", TokenType::Angle_Bracket_Close))
					continue;
			}
			else if (*iIndex == U'^')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"^=", TokenType::Assign_Xor))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"^", TokenType::Circumflex))
					continue;
			}

			//혼밥하는 오퍼들 ㅉㅉ
			//여기! 글자 단 하나!
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"~", TokenType::Tilde))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"(", TokenType::Paren_Open))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U")", TokenType::Paren_Close))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"{", TokenType::Brace_Open))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"}", TokenType::Brace_Close))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"[", TokenType::Bracket_Open))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"]", TokenType::Bracket_Close))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U".", TokenType::Dot))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U",", TokenType::Comma))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U":", TokenType::Colon))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U";", TokenType::Semicolon))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"?", TokenType::Question))
				continue;

			//Keywords.
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"int", TokenType::Keyword_Int))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"real", TokenType::Keyword_Real))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"string", TokenType::Keyword_String))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"if", TokenType::Keyword_If))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"else", TokenType::Keyword_Else))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"for", TokenType::Keyword_For))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"repeat", TokenType::Keyword_Repeat))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"return", TokenType::Keyword_Return))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"break", TokenType::Keyword_Break))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, U"continue", TokenType::Keyword_Continue))
				continue;

			if (*iIndex >= 256 || *iIndex >= U'a' && *iIndex <= U'z' || *iIndex >= U'A' && *iIndex <= U'Z' || *iIndex == U'_')
			{
				std::u32string sIdentifier{*iIndex};

				for (++iIndex; iIndex != iEnd && (*iIndex >= 256 || *iIndex >= U'a' && *iIndex <= U'z' || *iIndex >= U'A' && *iIndex <= U'Z' || *iIndex == U'_'); ++iIndex)
					sIdentifier += *iIndex;

				sTokenList.emplace_back(TokenType::Identifier, nLine, sIdentifier);

				continue;
			}

			sErrorList.emplace_back(TokenType::Unknown, nLine, *iIndex++, U"Unexpected token.");
		}

		return sTokenList;
	}

	bool Splitter::isWhitespace(char32_t nCharacter)
	{
		switch (nCharacter)
		{
		case U' ':
		case U'\n':
		case U'\r':
		case U'\t':
			return true;

		default:
			return false;
		}
	}

	std::size_t Splitter::skipWhitespaces(std::u32string::const_iterator &iIndex, const std::u32string::const_iterator &iEnd)
	{
		std::size_t nLine{0u};

		for (; iIndex != iEnd && Splitter::isWhitespace(*iIndex); ++iIndex)
			if (*iIndex == U'\n')
				++nLine;

		return nLine;
	}

	bool Splitter::tryParseNumericalLiteral(std::size_t nLine, std::u32string::const_iterator &iIndex, const std::u32string::const_iterator &iEnd, std::vector<SplitToken> &sTokenList)
	{
		switch (*iIndex)
		{
		case U'+':
		case U'-':
		case U'0':
		case U'1':
		case U'2':
		case U'3':
		case U'4':
		case U'5':
		case U'6':
		case U'7':
		case U'8':
		case U'9':
		case U'.':
			break;

		default:
			return false;
		}

		std::match_results<std::u32string::const_iterator> sResult;

		if (std::regex_search(iIndex, iEnd, sResult, Splitter::sBinaryInteger) ||
			std::regex_search(iIndex, iEnd, sResult, Splitter::sDecimalInteger) ||
			std::regex_search(iIndex, iEnd, sResult, Splitter::sHexadecimalInteger))
		{
			iIndex += sResult.length();
			sTokenList.emplace_back(TokenType::Literal_Int, nLine, sResult.str());
			return true;
		}
		else if (std::regex_search(iIndex, iEnd, sResult, Splitter::sDecimalReal))
		{
			iIndex += sResult.length();
			sTokenList.emplace_back(TokenType::Literal_Real, nLine, sResult.str());
			return true;
		}

		return false;
	}

	bool Splitter::tryParseStringLiteral(std::size_t nLine, std::u32string::const_iterator &iIndex, const std::u32string::const_iterator &iEnd, std::vector<SplitToken> &sTokenList, std::vector<ErrorInfo> &sErrorList)
	{
		using namespace std::literals;

		if (*iIndex != U'\'')
			return false;

		auto sContent{U""s};
		std::u32string::const_iterator iCurrent = iIndex + 1u;

		while (iCurrent != iEnd)
		{
			if (*iCurrent == U'\'')
			{
				iIndex = iCurrent + 1u;
				sTokenList.emplace_back(TokenType::Literal_String, nLine, sContent);
				return true;
			}
			else if (*iCurrent == U'\n')
			{
				iIndex = iCurrent;
				sTokenList.emplace_back(TokenType::Literal_String, nLine, sContent);
				sErrorList.emplace_back(TokenType::Literal_String, nLine, sContent, U"Unexpected line-break.");

				return true;
			}

			//Case : Backslash - escape character.
			if (*iCurrent == U'\\')
			{
				++iCurrent;

				if (iCurrent == iEnd)
				{
					iIndex = iCurrent;
					sTokenList.emplace_back(TokenType::Literal_String, nLine, sContent);
					sErrorList.emplace_back(TokenType::Literal_String, nLine, sContent, U"Unexpected end of file reached.");

					return true;
				}
				else if (*iCurrent == U'\n')
				{
					iIndex = iCurrent;
					sTokenList.emplace_back(TokenType::Literal_String, nLine, sContent);
					sErrorList.emplace_back(TokenType::Literal_String, nLine, sContent, U"Unexpected line-break.");

					return true;
				}

				switch (*iCurrent)
				{
				case U'0':
					sContent += U'\0';
					break;

				case U'a':
					sContent += U'\a';
					break;

				case U'b':
					sContent += U'\b';
					break;

				case U'f':
					sContent += U'\f';
					break;

				case U'n':
					sContent += U'\n';
					break;

				case U'r':
					sContent += U'\r';
					break;

				case U't':
					sContent += U'\t';
					break;

				case U'v':
					sContent += U'\v';
					break;

				default:
					sContent += *iCurrent;
					break;
				}

				++iCurrent;

				continue;
			}

			sContent += *iCurrent++;
		}

		iIndex = iCurrent;
		sTokenList.emplace_back(TokenType::Literal_String, nLine, sContent);
		sErrorList.emplace_back(TokenType::Literal_String, nLine, sContent, U"Unexpected end of file reached.");

		return true;
	}

	bool Splitter::tryParseKeyword(std::size_t nLine, std::u32string::const_iterator &iIndex, const std::u32string::const_iterator &iEnd, std::vector<SplitToken> &sTokenList, const char32_t *pKeyword, TokenType eType)
	{
		auto iCurrent = iIndex;

		for (std::size_t nIndex = 0u; pKeyword[nIndex]; ++nIndex, ++iCurrent)
			if (iCurrent == iEnd || *iCurrent != pKeyword[nIndex])
				return false;

		iIndex = iCurrent;
		sTokenList.emplace_back(eType, nLine, pKeyword);

		return true;
	}

	bool Splitter::tryMatchKeyword(std::u32string::const_iterator &iIndex, const std::u32string::const_iterator &iEnd, const char32_t *pKeyword, bool bMoveIterator)
	{
		auto iCurrent = iIndex;

		for (std::size_t nIndex = 0u; pKeyword[nIndex]; ++nIndex, ++iCurrent)
			if (iCurrent == iEnd || *iCurrent != pKeyword[nIndex])
				return false;

		if (bMoveIterator)
			iIndex = iCurrent;

		return true;
	}
}