
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_RUNTIME_ENVIRONMENT_H

#define _CLASS_PMS_RUNTIME_ENVIRONMENT_H

#include <cstdint>
#include <deque>
#include <string>
#include <utility>
#include <vector>

namespace PMS::Runtime
{
	struct alignas(16) PMSEntity;

	enum class PMSEntityType : uint32_t
	{
		Int,
		Real,
		String,
		List
	};

	union PMSData
	{
		int64_t nInt;
		double nReal;
		std::u32string *pString;
		std::vector<PMSEntity> *pList;
		PMSEntity *pReference;

		void *pRawValue;				//For copy.
	};

	struct alignas(16) PMSEntity
	{
		PMSEntityType eType;
		PMSData sData;
	};

	class Environment
	{
	private:
		std::vector<PMSEntity> sLiteralList;
		
	public:
		Environment() = default;
		Environment(const Environment &sSrc);
		Environment(Environment &&sSrc);
		~Environment();
		
	public:
		Environment &operator=(const Environment &sSrc);
		Environment &operator=(Environment &&sSrc);

	public:
		inline operator PMSEntity *();
		inline operator const PMSEntity *() const;
		
	public:
		void addLiteral(int64_t nIntLiteral);
		void addLiteral(double nRealLiteral);
		void addLiteral(const std::u32string &sStringLiteral);
	};

	inline Environment::operator PMSEntity *()
	{
		return this->sLiteralList.data();
	}

	inline Environment::operator const PMSEntity *() const
	{
		return this->sLiteralList.data();
	}
}

#endif