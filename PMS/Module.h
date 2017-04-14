
/*
	2017.04.11
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_RUNTIME_MODULE_H

#define _CLASS_PMS_RUNTIME_MODULE_H

#include "Executable.h"

#include <memory>
#include <string>
#include <unordered_map>
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
		List,

		Func,
		Module,

		Reference
	};

	union PMSData
	{
		int64_t nInt;
		double nReal;
		std::u32string *pString;
		std::vector<PMSEntity> *pList;
		PMSEntity *pReference;

		Executable *pFunc;
		Module *pModule;

		void *pRawValue;				//For copy.
	};

	struct alignas(16) PMSEntity
	{
		PMSEntityType eType;
		PMSData sData;
	};

	class Module
	{
	private:
		std::unordered_map<std::u32string, std::unique_ptr<Module>> sModuleMap;
		std::unordered_map<std::u32string, PMSEntity> sEntityMap;
		std::vector<std::unique_ptr<Executable>> sFunctionList;
		std::vector<PMSEntity> sLiteralList;
		std::vector<std::unique_ptr<std::u32string>> sStringLiteralList;
		
	public:
		Module();
		Module(const Module &sSrc);
		Module(Module &&sSrc);
		~Module();
		
	public:
		Module &operator=(const Module &sSrc);
		Module &operator=(Module &&sSrc);
		
	public:
		inline Module *addModule(const std::u32string &sModuleName);
		inline Module *findModule(const std::u32string &sModuleName);
		inline const Module *findModule(const std::u32string &sModuleName) const;
		inline void addEntity(const std::u32string &sEntityName, PMSEntity sEntity);
		inline bool findEntity(const std::u32string &sEntityName, PMSEntity &sEntity) const;
		inline Executable *addFunction(const std::u32string &sFunctionName);
	};

	inline Module *Module::addModule(const std::u32string &sModuleName)
	{
		return this->sModuleMap.emplace(sModuleName, std::make_unique<Module>()).first->second.get();
	}

	inline Module *Module::findModule(const std::u32string &sModuleName)
	{
		auto iIndex = this->sModuleMap.find(sModuleName);

		return iIndex != this->sModuleMap.cend() ? iIndex->second.get() : nullptr;
	}

	inline const Module *Module::findModule(const std::u32string &sModuleName) const
	{
		auto iIndex = this->sModuleMap.find(sModuleName);

		return iIndex != this->sModuleMap.cend() ? iIndex->second.get() : nullptr;
	}

	inline void Module::addEntity(const std::u32string &sEntityName, PMSEntity sEntity)
	{
		this->sEntityMap.emplace(sEntityName, sEntity);
	}

	inline bool Module::findEntity(const std::u32string &sEntityName, PMSEntity &sEntity) const
	{
		auto iIndex = this->sEntityMap.find(sEntityName);

		if (iIndex == this->sEntityMap.cend())
			return false;

		sEntity = iIndex->second;

		return true;
	}

	inline Executable *Module::addFunction(const std::u32string &sFunctionName)
	{
		this->sFunctionList.emplace_back(std::make_unique<Executable>());

		PMSEntity sEntity;
		sEntity.eType = PMSEntityType::Func;
		sEntity.sData.pFunc = this->sFunctionList.back().get();

		this->addEntity(sFunctionName, sEntity);

		return sEntity.sData.pFunc;
	}
}

#endif