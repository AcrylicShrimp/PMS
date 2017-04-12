
/*
	2017.04.12
	Created by AcrylicShrimp.
*/

#include "Directive.h"

namespace PMS::Parse
{
	Directive::Directive()
	{
		//TODO : Place your implementation of default constructor here.
		
	}
	
	Directive::Directive(const Directive &sSrc)
	{
		//TODO : Place your implementation of copy constructor here.
		
	}
	
	Directive::Directive(Directive &&sSrc)
	{
		//TODO : Place your implementation of move constructor here.
		
	}
	
	Directive::~Directive()
	{
		//TODO : Place your implementation of destructor here.
		
	}
	
	/*
		TODO : Place your other constructors here.
	*/
	
	
	Directive &Directive::operator=(const Directive &sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of copy assignment operator here.
		
		
		return *this;
	}
	
	Directive &Directive::operator=(Directive &&sSrc)
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