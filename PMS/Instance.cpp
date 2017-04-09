
/*
	2017.04.09
	Created by AcrylicShrimp.
*/

#include "Instance.h"

namespace PMS::Runtime
{
	Instance::Instance()
	{
		//TODO : Place your implementation of default constructor here.
		
	}
	
	Instance::Instance(const Instance &sSrc)
	{
		//TODO : Place your implementation of copy constructor here.
		
	}
	
	Instance::Instance(Instance &&sSrc)
	{
		//TODO : Place your implementation of move constructor here.
		
	}
	
	Instance::~Instance()
	{
		//TODO : Place your implementation of destructor here.
		
	}
	
	/*
		TODO : Place your other constructors here.
	*/
	
	
	Instance &Instance::operator=(const Instance &sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of copy assignment operator here.
		
		
		return *this;
	}
	
	Instance &Instance::operator=(Instance &&sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of move assignment operator here.
		
		
		return *this;
	}
	
	/*
		TODO : Place your other operator overloadings here.
	*/
	
	
	/*
		TODO : Place your member function definitions here.
	*/

}