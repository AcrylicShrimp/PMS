
/*
	2017.03.30
	Created by AcrylicShrimp.
*/

#include "Splitter.h"

#include <cstdlib>
#include <iostream>
#include <string>

namespace PMS
{
	int main()
	{
		using namespace std::literals;

		Parsing::Splitter sSpliter;
		const std::u32string sTestScript{U"123456789123456789"s};
		
		sSpliter.addRegexKeyword(U"^[+-]0[bB][01]+"s, 0);														//2진수 정수 패턴
		sSpliter.addRegexKeyword(U"^[+-]0[xX][0123456789abcdefABCDEF]+"s, 0);									//16진수 정수 패턴
		sSpliter.addRegexKeyword(U"^[+-]?[0123456789]+"s, 0);													//10진수 정수 패턴
		sSpliter.addRegexKeyword(U"^[+-]?(?:[0123456789]*\\.)?[0123456789]+(?:[eE][+-]?[0123456789]+)?"s, 0);	//10진수 실수 패턴

		system("pause");

		return 0;
	}
}