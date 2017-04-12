
/*
	2017.04.09
	Created by AcrylicShrimp.
*/

#include "Instance.h"

namespace PMS::Runtime
{
	Instance::Instance(const Instance &sSrc) :
		sGlobalModule{sSrc.sGlobalModule}
	{
		//Empty.
	}
	
	Instance::Instance(Instance &&sSrc) :
		sGlobalModule{std::move(sSrc.sGlobalModule)}
	{
		//Empty.
	}
	
	Instance &Instance::operator=(const Instance &sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		this->sGlobalModule = sSrc.sGlobalModule;
		
		return *this;
	}
	
	Instance &Instance::operator=(Instance &&sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		this->sGlobalModule = std::move(sSrc.sGlobalModule);
		
		return *this;
	}
	
	void Instance::runInstance()
	{

	}
}