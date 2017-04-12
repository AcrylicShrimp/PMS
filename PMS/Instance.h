
/*
	2017.04.09
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_RUNTIME_INSTANCE_H

#define _CLASS_PMS_RUNTIME_INSTANCE_H

#include "Module.h"

#include <cstdint>
#include <deque>
#include <string>
#include <utility>
#include <vector>

namespace PMS::Runtime
{
	using PMSStack = std::deque<PMSEntity>;

	class Instance
	{
	private:
		PMSEntity sLHS;
		PMSEntity sRHS;
		PMSStack sStack;
		Module sGlobalModule;
		
	public:
		Instance() = default;
		Instance(const Instance &sSrc);
		Instance(Instance &&sSrc);
		~Instance() = default;
		
	public:
		Instance &operator=(const Instance &sSrc);
		Instance &operator=(Instance &&sSrc);
		
	public:
		void runInstance();

	private:
		inline void pushInt(int64_t nInt);
		inline void pushReal(double nReal);
		inline void pushString(const std::u32string sString);
		inline void makeList();
	};

	inline void Instance::pushInt(int64_t nInt)
	{
		PMSEntity sEntity;
		sEntity.eType = PMSEntityType::Int;
		sEntity.sData.nInt = nInt;

		this->sStack.emplace_back(sEntity);
	}

	inline void Instance::pushReal(double nReal)
	{
		PMSEntity sEntity;
		sEntity.eType = PMSEntityType::Real;
		sEntity.sData.nReal = nReal;

		this->sStack.emplace_back(sEntity);
	}

	inline void Instance::pushString(const std::u32string sString)
	{
		PMSEntity sEntity;
		sEntity.eType = PMSEntityType::Real;
		sEntity.sData.pString = ;

		this->sStack.emplace_back(sEntity);
	}

	inline void Instance::makeList()
	{

	}
}

#endif