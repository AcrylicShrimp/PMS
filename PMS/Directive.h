
/*
	2017.04.12
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSE_DIRECTIVE_H

#define _CLASS_PMS_PARSE_DIRECTIVE_H

/*
	TODO : Place your include directives here.
*/
#include <utility>

namespace PMS::Parse
{
	class Directive
	{
	private:
		/*
			TODO : Place your field declarations here.
		*/
		
		
	public:
		Directive();
		Directive(const Directive &sSrc);
		Directive(Directive &&sSrc);
		~Directive();
		/*
			TODO : Place your other constructors here.
		*/
		
		
	public:
		Directive &operator=(const Directive &sSrc);
		Directive &operator=(Directive &&sSrc);
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