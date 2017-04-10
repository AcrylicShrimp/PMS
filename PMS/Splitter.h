
/*
	2017.03.30
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_SPLITTER_H

#define _CLASS_PMS_PARSING_SPLITTER_H

#include <cstddef>
#include <cstdint>
#include <regex>
#include <string>
#include <vector>

namespace PMS::Parsing
{
	enum class TokenType : uint32_t
	{
		//Specials
		Unknown,
		EndOfFile,

		//Comments
		Comment_Begin,
		Comment_End,
		Comment_Line,

		//Arithmetic operators
		Plus,
		Minus,
		Plus_Double,
		Minus_Double,
		Asterisk,
		Asterisk_Double,
		Slash,
		Percent,

		//Logical operators
		Exclamation,
		Ampersand_Double,
		Vertical_Double,

		//Comparison operators
		Equals,
		Not_Equals,
		Less_Equals,
		Greater_Equals,

		//Bit operators
		Tilde,
		Ampersand,
		Circumflex,
		Vertical,
		Shift_Left,
		Shift_Right,

		//Assignment operators
		Assign,
		Assign_Add,
		Assign_Subtract,
		Assign_Multiply,
		Assign_Power,
		Assign_Divide,
		Assign_Modulo,
		Assign_Shift_Left,
		Assign_Shift_Right,
		Assign_And,
		Assign_Xor,
		Assign_Or,
		Assign_Link,

		//Parentheses
		Paren_Open,
		Paren_Close,
		Brace_Open,
		Brace_Close,
		Bracket_Open,
		Bracket_Close,
		Angle_Bracket_Open,
		Angle_Bracket_Close,

		//For Syntax
		Dot,
		Comma,
		Colon,
		Semicolon,
		Question,
		Arrow_Left,
		
		//Literals,
		Literal_Int,
		Literal_Real,
		Literal_String,

		//Keywords
		Identifier,
		Keyword_Int,
		Keyword_Real,
		Keyword_String,
		Keyword_List,
		Keyword_If,
		Keyword_Else,
		Keyword_For,
		Keyword_Repeat,
		Keyword_Return,
		Keyword_Break,
		Keyword_Continue
	};

	struct SplitToken
	{
		TokenType eType;
		std::size_t nLine;
		std::wstring sKeyword;
	};

	struct ErrorInfo
	{
		SplitToken sToken;
		std::wstring sMessage;
	};

	using TokenList = std::vector<SplitToken>;
	using ErrorList = std::vector<ErrorInfo>;

	class Splitter
	{
	private:
		using Index = std::wstring::const_iterator;

		static std::wregex sBinaryInteger;
		static std::wregex sHexadecimalInteger;
		static std::wregex sDecimalInteger;
		static std::wregex sDecimalReal;

	public:
		Splitter() = delete;
		Splitter(const Splitter &sSrc) = delete;
		Splitter(Splitter &&sSrc) = delete;
		~Splitter() = delete;
		
	public:
		Splitter &operator=(const Splitter &sSrc) = delete;
		Splitter &operator=(Splitter &&sSrc) = delete;
		
	public:
		static TokenList splitAll(const std::wstring &sContent, ErrorList &sErrorList);

	private:
		static bool isWhitespace(char32_t nCharacter);
		static std::size_t skipWhitespaces(Index &iIndex, const Index &iEnd);
		static bool tryParseNumericalLiteral(std::size_t nLine, Index &iIndex, const Index &iEnd, TokenList &sTokenList);
		static bool tryParseStringLiteral(std::size_t nLine, Index &iIndex, const Index &iEnd, TokenList &sTokenList, ErrorList &sErrorList);
		static bool tryParseKeyword(std::size_t nLine, Index &iIndex, const Index &iEnd, TokenList &sTokenList, const wchar_t *pKeyword, TokenType eType);
		static bool tryMatchKeyword(Index &iIndex, const Index &iEnd, const wchar_t *pKeyword, bool bMoveIterator = false);
	};
}

#endif