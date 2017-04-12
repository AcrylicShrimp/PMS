
/*
	2017.04.11
	Created by AcrylicShrimp.
*/

#include "Module.h"

namespace PMS::Runtime
{
	Module::Module()
	{
		//TODO : Place your implementation of default constructor here.
		
	}
	
	Module::Module(const Module &sSrc)
	{
		//TODO : Place your implementation of copy constructor here.
		
	}
	
	Module::Module(Module &&sSrc)
	{
		//TODO : Place your implementation of move constructor here.
		
	}
	
	Module::~Module()
	{
		//TODO : Place your implementation of destructor here.
		
	}
	
	Module &Module::operator=(const Module &sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of copy assignment operator here.
		
		
		return *this;
	}
	
	Module &Module::operator=(Module &&sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of move assignment operator here.
		
		
		return *this;
	}
}