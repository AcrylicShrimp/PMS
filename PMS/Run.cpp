
/*
	2017.03.30
	Created by AcrylicShrimp.
*/

#include "Splitter.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

namespace PMS
{
	int main()
	{
		using namespace std::literals;

		std::vector<Parsing::ErrorInfo> sErrorList;
		auto sTokenList{Parsing::Splitter::splitAll(U"'dsada'"s, sErrorList)};

		system("pause");

		return 0;
	}
}