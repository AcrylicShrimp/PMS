
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#include "Executable.h"

namespace PMS::Runtime
{
	Executable::Executable()
	{
		//TODO : Place your implementation of default constructor here.
		
	}
	
	Executable::Executable(const Executable &sSrc)
	{
		//TODO : Place your implementation of copy constructor here.
		
	}
	
	Executable::Executable(Executable &&sSrc)
	{
		//TODO : Place your implementation of move constructor here.
		
	}
	
	Executable::~Executable()
	{
		//TODO : Place your implementation of destructor here.
		
	}
	
	/*
		TODO : Place your other constructors here.
	*/
	
	
	Executable &Executable::operator=(const Executable &sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of copy assignment operator here.
		
		
		return *this;
	}
	
	Executable &Executable::operator=(Executable &&sSrc)
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