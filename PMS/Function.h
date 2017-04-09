
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_RUNTIME_FUNCTION_H

#define _CLASS_PMS_RUNTIME_FUNCTION_H

/*
	TODO : Place your include directives here.
*/
#include <utility>

namespace PMS::Runtime
{
	class Function
	{
	private:
		/*
			TODO : Place your field declarations here.
		*/
		
		
	public:
		Function();
		Function(const Function &sSrc);
		Function(Function &&sSrc);
		~Function();
		/*
			TODO : Place your other constructors here.
		*/
		
		
	public:
		Function &operator=(const Function &sSrc);
		Function &operator=(Function &&sSrc);
		/*
			TODO : Place your other operator overloadings here.
		*/
		
		
	public:
		/*
			TODO : Place your member function declarations here.
		*/
		
	};
}

#endif