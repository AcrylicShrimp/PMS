
/*
	2017.04.13
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_PARSING_DATA_H

#define _CLASS_PMS_PARSING_PARSING_DATA_H

#include "Module.h"
#include "Splitter.h"
#include "TokenIndexer.h"

#include <utility>

namespace PMS::Parsing
{
	class ParsingData final
	{
	private:
		TokenIndexer sTokenIndexer;
		Runtime::Module *pCurrentModule;
		Runtime::Module *pModule;
		ErrorList *pErrorList;
		
	public:
		ParsingData() = default;
		ParsingData(const ParsingData &sSrc);
		~ParsingData() = default;
		
	public:
		ParsingData &operator=(const ParsingData &sSrc);
		
	public:
		inline TokenIndexer &indexer();
		inline const TokenIndexer &indexer() const;
		inline Runtime::Module *currentModule() const;
		inline Runtime::Module *module() const;
		inline ErrorList *errorList() const;
		inline void pushError(const std::wstring &sMessage);
		inline void pushError(const std::wstring &sMessage, TokenIndex iErrorIndex);
		inline void setCurrentModuleToGlobal();
		inline void setCurrentModuleToSubModule(const std::u32string &sSubModuleName);

		void makeParsingData(const TokenList &sTokenList, ErrorList &sErrorList, Runtime::Module &sTargetModule);
	};

	inline TokenIndexer &ParsingData::indexer()
	{
		return this->sTokenIndexer;
	}

	inline const TokenIndexer &ParsingData::indexer() const
	{
		return this->sTokenIndexer;
	}

	inline Runtime::Module *ParsingData::currentModule() const
	{
		return this->pCurrentModule;
	}

	inline Runtime::Module *ParsingData::module() const
	{
		return this->pModule;
	}

	inline ErrorList *ParsingData::errorList() const
	{
		return this->pErrorList;
	}

	inline void ParsingData::pushError(const std::wstring &sMessage)
	{
		this->pErrorList->emplace_back(ErrorInfo{SplitToken{*this->sTokenIndexer.current()}, sMessage});
	}

	inline void ParsingData::pushError(const std::wstring &sMessage, TokenIndex iErrorIndex)
	{
		this->pErrorList->emplace_back(ErrorInfo{SplitToken{*iErrorIndex}, sMessage});
	}

	inline void ParsingData::setCurrentModuleToGlobal()
	{
		this->pCurrentModule = this->pModule;
	}

	inline void ParsingData::setCurrentModuleToSubModule(const std::u32string &sSubModuleName)
	{
		auto pSubModule = this->pCurrentModule->findModule(sSubModuleName);

		this->pCurrentModule = pSubModule == nullptr ? this->pCurrentModule->addModule(sSubModuleName) : pSubModule;
	}
}

#endif