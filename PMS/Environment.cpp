
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#include "Environment.h"

namespace PMS::Runtime
{
	Environment::Environment(const Environment &sSrc) :
		sLiteralList{sSrc.sLiteralList}
	{
		for (auto sEntity : this->sLiteralList)
			if (sEntity.eType == PMSEntityType::String)
				sEntity.sData.pString = new std::u32string(*sEntity.sData.pString);
	}

	Environment::Environment(Environment &&sSrc) :
		sLiteralList{std::move(sSrc.sLiteralList)}
	{
		//Empty.
	}

	Environment::~Environment()
	{
		for (auto sEntity : this->sLiteralList)
			if (sEntity.eType == PMSEntityType::String)
				delete sEntity.sData.pString;
	}

	Environment &Environment::operator=(const Environment &sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->~Environment();

		this->sLiteralList = sSrc.sLiteralList;

		for (auto sEntity : this->sLiteralList)
			if (sEntity.eType == PMSEntityType::String)
				sEntity.sData.pString = new std::u32string(*sEntity.sData.pString);

		return *this;
	}

	Environment &Environment::operator=(Environment &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->~Environment();

		this->sLiteralList = std::move(sSrc.sLiteralList);

		return *this;
	}

	void Environment::addLiteral(int64_t nIntLiteral)
	{
		PMSEntity sIntEntity;
		sIntEntity.eType = PMSEntityType::Int;
		sIntEntity.sData.nInt = nIntLiteral;

		this->sLiteralList.emplace_back(sIntEntity);
	}

	void Environment::addLiteral(double nRealLiteral)
	{
		PMSEntity sIntEntity;
		sIntEntity.eType = PMSEntityType::Real;
		sIntEntity.sData.nReal = nRealLiteral;

		this->sLiteralList.emplace_back(sIntEntity);
	}

	void Environment::addLiteral(const std::u32string &sStringLiteral)
	{
		PMSEntity sIntEntity;
		sIntEntity.eType = PMSEntityType::String;
		sIntEntity.sData.pString = new std::u32string(sStringLiteral);

		this->sLiteralList.emplace_back(sIntEntity);
	}
}