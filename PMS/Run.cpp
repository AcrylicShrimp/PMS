
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
		
		sSpliter.addRegexKeyword(U"^[+-]0[bB][01]+"s, 0);														//2���� ���� ����
		sSpliter.addRegexKeyword(U"^[+-]0[xX][0123456789abcdefABCDEF]+"s, 0);									//16���� ���� ����
		sSpliter.addRegexKeyword(U"^[+-]?[0123456789]+"s, 0);													//10���� ���� ����
		sSpliter.addRegexKeyword(U"^[+-]?(?:[0123456789]*\\.)?[0123456789]+(?:[eE][+-]?[0123456789]+)?"s, 0);	//10���� �Ǽ� ����

		system("pause");

		return 0;
	}
}