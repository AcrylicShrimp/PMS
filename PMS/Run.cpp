
/*
	2017.03.30
	Created by AcrylicShrimp.
*/

#include "Splitter.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	using namespace PMS;
	using namespace std::literals;

	std::wifstream sInput{L"test.pms", std::wifstream::in};

	if (!sInput.is_open())
		return -1;

	std::wstring sContent{std::istreambuf_iterator<wchar_t>{sInput}, std::istreambuf_iterator<wchar_t>{}};
	sInput.close();

	std::vector<Parsing::ErrorInfo> sErrorList;
	auto sTokenList{Parsing::Splitter::splitAll(sContent, sErrorList)};

	system("pause");

	return 0;
}