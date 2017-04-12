
/*
	2017.04.12
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSE_CONSTANT_DIRECTIVE_H

#define _CLASS_PMS_PARSE_CONSTANT_DIRECTIVE_H

/*
	TODO : Place your include directives here.
*/
#include <utility>

namespace PMS::Parse
{
	class ConstantDirective
	{
	private:
		/*
			TODO : Place your field declarations here.
		*/
		
		
	public:
		ConstantDirective();
		ConstantDirective(const ConstantDirective &sSrc);
		ConstantDirective(ConstantDirective &&sSrc);
		~ConstantDirective();
		/*
			TODO : Place your other constructors here.
		*/
		
		
	public:
		ConstantDirective &operator=(const ConstantDirective &sSrc);
		ConstantDirective &operator=(ConstantDirective &&sSrc);
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