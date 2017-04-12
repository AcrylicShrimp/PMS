
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
	public:
		Directive() = delete;
		Directive(const Directive &sSrc) = delete;
		Directive(Directive &&sSrc) = delete;
		~Directive() = delete;
		
	public:
		Directive &operator=(const Directive &sSrc) = delete;
		Directive &operator=(Directive &&sSrc) = delete;
		
	public:

	};
}

#endif