
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
		std::u32string sKeyword;
	};

	struct ErrorInfo
	{
		SplitToken sToken;
		std::u32string sMessage;
	};

	class Splitter
	{
	private:
		static std::basic_regex<char32_t> sBinaryInteger;
		static std::basic_regex<char32_t> sDecimalInteger;
		static std::basic_regex<char32_t> sHexadecimalInteger;
		static std::basic_regex<char32_t> sDecimalReal;

	public:
		Splitter() = delete;
		Splitter(const Splitter &sSrc) = delete;
		Splitter(Splitter &&sSrc) = delete;
		~Splitter() = delete;
		
	public:
		Splitter &operator=(const Splitter &sSrc) = delete;
		Splitter &operator=(Splitter &&sSrc) = delete;
		
	public:
		static std::vector<SplitToken> splitAll(const std::u32string &sContent, std::vector<ErrorInfo> &sErrorList);

	private:
		static bool isWhitespace(char32_t nCharacter);
		static std::size_t skipWhitespaces(std::u32string::const_iterator &iIndex, const std::u32string::const_iterator &iEnd);
		static bool tryParseNumericalLiteral(std::size_t nLine, std::u32string::const_iterator &iIndex, const std::u32string::const_iterator &iEnd, std::vector<SplitToken> &sTokenList);
		static bool tryParseStringLiteral(std::size_t nLine, std::u32string::const_iterator &iIndex, const std::u32string::const_iterator &iEnd, std::vector<SplitToken> &sTokenList, std::vector<ErrorInfo> &sErrorList);
		static bool tryParseKeyword(std::size_t nLine, std::u32string::const_iterator &iIndex, const std::u32string::const_iterator &iEnd, std::vector<SplitToken> &sTokenList, const char32_t *pKeyword, TokenType eType);
		static bool tryMatchKeyword(std::u32string::const_iterator &iIndex, const std::u32string::const_iterator &iEnd, const char32_t *pKeyword, bool bMoveIterator = false);
	};
}

#endif