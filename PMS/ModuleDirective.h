
/*
	2017.04.12
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSE_MODULE_DIRECTIVE_H

#define _CLASS_PMS_PARSE_MODULE_DIRECTIVE_H

/*
	TODO : Place your include directives here.
*/
#include <utility>

namespace PMS::Parse
{
	class ModuleDirective
	{
	private:
		/*
			TODO : Place your field declarations here.
		*/
		
		
	public:
		ModuleDirective();
		ModuleDirective(const ModuleDirective &sSrc);
		ModuleDirective(ModuleDirective &&sSrc);
		~ModuleDirective();
		/*
			TODO : Place your other constructors here.
		*/
		
		
	public:
		ModuleDirective &operator=(const ModuleDirective &sSrc);
		ModuleDirective &operator=(ModuleDirective &&sSrc);
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