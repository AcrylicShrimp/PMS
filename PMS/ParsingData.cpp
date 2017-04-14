
/*
	2017.04.13
	Created by AcrylicShrimp.
*/

#include "ParsingData.h"

namespace PMS::Parsing
{
	ParsingData::ParsingData(const ParsingData &sSrc) :
		iIndex{sSrc.iIndex},
		iEnd{sSrc.iEnd},
		pCurrentModule{sSrc.pCurrentModule},
		pModule{sSrc.pModule},
		pErrorList{sSrc.pErrorList}
	{
		//Empty.
	}

	ParsingData &ParsingData::operator=(const ParsingData &sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->iIndex = sSrc.iIndex;
		this->iEnd = sSrc.iEnd;
		this->pCurrentModule = sSrc.pCurrentModule;
		this->pModule = sSrc.pModule;
		this->pErrorList = sSrc.pErrorList;

		return *this;
	}

	void ParsingData::makeParsingData(const TokenList &sTokenList, ErrorList &sErrorList, Runtime::Module &sTargetModule)
	{
		this->iIndex = sTokenList.cbegin();
		this->iEnd = sTokenList.cend();
		this->pCurrentModule = this->pModule = &sTargetModule;
		this->pErrorList = &sErrorList;
	}
}