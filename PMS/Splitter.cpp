
/*
	2017.03.30
	Created by AcrylicShrimp.
*/

#include "Splitter.h"

namespace PMS::Parsing
{
	std::wregex Splitter::sBinaryInteger{L"^0[bB][01]+"};
	std::wregex Splitter::sHexadecimalInteger{L"^0[xX][0123456789abcdefABCDEF]+"};
	std::wregex Splitter::sDecimalInteger{L"^[0123456789]+"};
	std::wregex Splitter::sDecimalReal{L"^(?:(?:[0123456789]*\\.[0123456789]+)|(?:[0123456789]+\\.[0123456789]*)|(?:[0123456789]+))(?:[eE][+-]?[0123456789]+)?"};

	TokenList Splitter::splitAll(const std::wstring &sContent, ErrorList &sErrorList)
	{
		std::size_t nLine{1u};
		std::vector<SplitToken> sTokenList;

		auto iIndex{sContent.cbegin()};
		auto iEnd{sContent.cend()};

		while (nLine += Splitter::skipWhitespaces(iIndex, iEnd), iIndex != iEnd)
		{
			if (Splitter::tryMatchKeyword(iIndex, iEnd, L"/*", true))
			{
				for (auto nCurrentLine = nLine; !Splitter::tryMatchKeyword(iIndex, iEnd, L"*/", true); ++iIndex)
					if (iIndex == iEnd)
					{
						sErrorList.emplace_back(ErrorInfo{SplitToken{TokenType::Comment_Begin, nCurrentLine, L"/*"}, L"Unexpected end of file reached."});

						return sTokenList;
					}
					else if (*iIndex == L'\n')
						++nLine;

				continue;
			}
			else if (Splitter::tryMatchKeyword(iIndex, iEnd, L"//", true))
			{
				for (; iIndex != iEnd && *iIndex != L'\n'; ++iIndex);

				if (iIndex == iEnd)
					return sTokenList;

				++nLine;
				
				continue;
			}

			//Numeric literals.
			if (Splitter::tryParseNumericalLiteral(nLine, iIndex, iEnd, sTokenList))
				continue;

			//String literals.
			if (Splitter::tryParseStringLiteral(nLine, iIndex, iEnd, sTokenList, sErrorList))
				continue;

			//Operators
			if (*iIndex == L'+')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"++", TokenType::Plus_Double))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"+=", TokenType::Assign_Add))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"+", TokenType::Plus))
					continue;
			}
			else if (*iIndex == L'-')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"--", TokenType::Minus_Double))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"-=", TokenType::Assign_Subtract))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"->", TokenType::Arrow_Left))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"-", TokenType::Minus))
					continue;
			}
			else if (*iIndex == L'*')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"**=", TokenType::Assign_Power))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"**", TokenType::Asterisk_Double))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"*=", TokenType::Assign_Multiply))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"*", TokenType::Asterisk))
					continue;
			}
			else if (*iIndex == L'/')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"/=", TokenType::Assign_Divide))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"/", TokenType::Slash))
					continue;
			}
			else if (*iIndex == L'%')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"%=", TokenType::Assign_Modulo))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"%", TokenType::Percent))
					continue;
			}
			else if (*iIndex == L'!')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"!=", TokenType::Not_Equals))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"!", TokenType::Exclamation))
					continue;
			}
			else if (*iIndex == L'&')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"&&", TokenType::Ampersand_Double))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"&=", TokenType::Assign_And))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"&", TokenType::Ampersand))
					continue;
			}
			else if (*iIndex == L'|')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"||", TokenType::Vertical_Double))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"|=", TokenType::Assign_Or))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"|", TokenType::Vertical))
					continue;
			}
			else if (*iIndex == L'=')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"==", TokenType::Equals))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"=", TokenType::Assign))
					continue;
			}
			else if (*iIndex == L'<')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"<<=", TokenType::Assign_Shift_Left))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"<<", TokenType::Shift_Left))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"<=", TokenType::Less_Equals))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"<-", TokenType::Assign_Link))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"<", TokenType::Angle_Bracket_Open))
					continue;
			}
			else if (*iIndex == L'>')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L">>=", TokenType::Assign_Shift_Right))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L">>", TokenType::Shift_Right))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L">=", TokenType::Greater_Equals))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L">", TokenType::Angle_Bracket_Close))
					continue;
			}
			else if (*iIndex == L'^')
			{
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"^=", TokenType::Assign_Xor))
					continue;
				if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"^", TokenType::Circumflex))
					continue;
			}

			//혼밥하는 오퍼들 ㅉㅉ
			//여기! 글자 단 하나!
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"~", TokenType::Tilde))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"(", TokenType::Paren_Open))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L")", TokenType::Paren_Close))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"{", TokenType::Brace_Open))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"}", TokenType::Brace_Close))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"[", TokenType::Bracket_Open))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"]", TokenType::Bracket_Close))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L".", TokenType::Dot))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L",", TokenType::Comma))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L":", TokenType::Colon))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L";", TokenType::Semicolon))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"?", TokenType::Question))
				continue;

			//Keywords.
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"int", TokenType::Keyword_Int))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"real", TokenType::Keyword_Real))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"string", TokenType::Keyword_String))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"if", TokenType::Keyword_If))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"else", TokenType::Keyword_Else))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"for", TokenType::Keyword_For))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"repeat", TokenType::Keyword_Repeat))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"return", TokenType::Keyword_Return))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"break", TokenType::Keyword_Break))
				continue;
			if (Splitter::tryParseKeyword(nLine, iIndex, iEnd, sTokenList, L"continue", TokenType::Keyword_Continue))
				continue;

			if (*iIndex >= 256 || *iIndex >= L'a' && *iIndex <= L'z' || *iIndex >= L'A' && *iIndex <= L'Z' || *iIndex == L'_')
			{
				std::wstring sIdentifier{*iIndex};

				for (++iIndex; iIndex != iEnd && (*iIndex >= 256 || *iIndex >= L'a' && *iIndex <= L'z' || *iIndex >= L'A' && *iIndex <= L'Z' || *iIndex == L'_'); ++iIndex)
					sIdentifier += *iIndex;

				sTokenList.emplace_back(SplitToken{TokenType::Identifier, nLine, sIdentifier});

				continue;
			}

			sErrorList.emplace_back(ErrorInfo{SplitToken{TokenType::Unknown, nLine, std::wstring{1u, *iIndex++}}, L"Unexpected token."});
		}

		return sTokenList;
	}

	bool Splitter::isWhitespace(char32_t nCharacter)
	{
		switch (nCharacter)
		{
		case L' ':
		case L'\n':
		case L'\r':
		case L'\t':
			return true;

		default:
			return false;
		}
	}

	std::size_t Splitter::skipWhitespaces(Index &iIndex, const Index &iEnd)
	{
		std::size_t nLine{0u};

		for (; iIndex != iEnd && Splitter::isWhitespace(*iIndex); ++iIndex)
			if (*iIndex == L'\n')
				++nLine;

		return nLine;
	}

	bool Splitter::tryParseNumericalLiteral(std::size_t nLine, Index &iIndex, const Index &iEnd, TokenList &sTokenList)
	{
		switch (*iIndex)
		{
		case L'0':
		case L'1':
		case L'2':
		case L'3':
		case L'4':
		case L'5':
		case L'6':
		case L'7':
		case L'8':
		case L'9':
		case L'.':
			break;

		default:
			return false;
		}

		std::match_results<Index> sResult;

		if (std::regex_search(iIndex, iEnd, sResult, Splitter::sBinaryInteger) ||
			std::regex_search(iIndex, iEnd, sResult, Splitter::sHexadecimalInteger))
		{
			iIndex += sResult.length();
			sTokenList.emplace_back(SplitToken{TokenType::Literal_Int, nLine, sResult.str()});

			return true;
		}
		else if (std::regex_search(iIndex, iEnd, sResult, Splitter::sDecimalReal))
		{
			iIndex += sResult.length();
			sTokenList.emplace_back(SplitToken{TokenType::Literal_Real, nLine, sResult.str()});

			if (std::regex_match(sTokenList.back().sKeyword, Splitter::sDecimalInteger))
				sTokenList.back().eType = TokenType::Literal_Int;

			return true;
		}

		return false;
	}

	bool Splitter::tryParseStringLiteral(std::size_t nLine, Index &iIndex, const Index &iEnd, TokenList &sTokenList, ErrorList &sErrorList)
	{
		using namespace std::literals;

		if (*iIndex != L'\'')
			return false;

		auto sContent{L""s};
		Index iCurrent = iIndex + 1u;

		while (iCurrent != iEnd)
		{
			if (*iCurrent == L'\'')
			{
				iIndex = iCurrent + 1u;
				sTokenList.emplace_back(SplitToken{TokenType::Literal_String, nLine, sContent});
				return true;
			}
			else if (*iCurrent == L'\n')
			{
				iIndex = iCurrent;
				sTokenList.emplace_back(SplitToken{TokenType::Literal_String, nLine, sContent});
				sErrorList.emplace_back(ErrorInfo{SplitToken{TokenType::Literal_String, nLine, sContent}, L"Unexpected line-break."});

				return true;
			}

			//Case : Backslash - escape character.
			if (*iCurrent == L'\\')
			{
				++iCurrent;

				if (iCurrent == iEnd)
				{
					iIndex = iCurrent;
					sTokenList.emplace_back(SplitToken{TokenType::Literal_String, nLine, sContent});
					sErrorList.emplace_back(ErrorInfo{SplitToken{TokenType::Literal_String, nLine, sContent}, L"Unexpected end of file reached."});

					return true;
				}
				else if (*iCurrent == L'\n')
				{
					iIndex = iCurrent;
					sTokenList.emplace_back(SplitToken{TokenType::Literal_String, nLine, sContent});
					sErrorList.emplace_back(ErrorInfo{SplitToken{TokenType::Literal_String, nLine, sContent}, L"Unexpected line-break."});

					return true;
				}

				switch (*iCurrent)
				{
				case L'0':
					sContent += L'\0';
					break;

				case L'a':
					sContent += L'\a';
					break;

				case L'b':
					sContent += L'\b';
					break;

				case L'f':
					sContent += L'\f';
					break;

				case L'n':
					sContent += L'\n';
					break;

				case L'r':
					sContent += L'\r';
					break;

				case L't':
					sContent += L'\t';
					break;

				case L'v':
					sContent += L'\v';
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
		sTokenList.emplace_back(SplitToken{TokenType::Literal_String, nLine, sContent});
		sErrorList.emplace_back(ErrorInfo{SplitToken{TokenType::Literal_String, nLine, sContent}, L"Unexpected end of file reached."});

		return true;
	}

	bool Splitter::tryParseKeyword(std::size_t nLine, Index &iIndex, const Index &iEnd, TokenList &sTokenList, const wchar_t *pKeyword, TokenType eType)
	{
		auto iCurrent = iIndex;

		for (std::size_t nIndex = 0u; pKeyword[nIndex]; ++nIndex, ++iCurrent)
			if (iCurrent == iEnd || *iCurrent != pKeyword[nIndex])
				return false;

		iIndex = iCurrent;
		sTokenList.emplace_back(SplitToken{eType, nLine, pKeyword});

		return true;
	}

	bool Splitter::tryMatchKeyword(Index &iIndex, const Index &iEnd, const wchar_t *pKeyword, bool bMoveIterator)
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