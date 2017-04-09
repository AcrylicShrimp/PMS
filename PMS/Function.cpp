
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#include "Function.h"

namespace PMS::Runtime
{
	Function::Function()
	{
		//TODO : Place your implementation of default constructor here.
		
	}
	
	Function::Function(const Function &sSrc)
	{
		//TODO : Place your implementation of copy constructor here.
		
	}
	
	Function::Function(Function &&sSrc)
	{
		//TODO : Place your implementation of move constructor here.
		
	}
	
	Function::~Function()
	{
		//TODO : Place your implementation of destructor here.
		
	}
	
	/*
		TODO : Place your other constructors here.
	*/
	
	
	Function &Function::operator=(const Function &sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of copy assignment operator here.
		
		
		return *this;
	}
	
	Function &Function::operator=(Function &&sSrc)
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