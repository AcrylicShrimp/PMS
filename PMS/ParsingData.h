
/*
	2017.04.13
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_PARSING_DATA_H

#define _CLASS_PMS_PARSING_PARSING_DATA_H

/*
	TODO : Place your include directives here.
*/
#include <utility>

namespace PMS::Parsing
{
	class ParsingData
	{
	private:
		/*
			TODO : Place your field declarations here.
		*/
		
		
	public:
		ParsingData();
		ParsingData(const ParsingData &sSrc);
		ParsingData(ParsingData &&sSrc);
		~ParsingData();
		/*
			TODO : Place your other constructors here.
		*/
		
		
	public:
		ParsingData &operator=(const ParsingData &sSrc);
		ParsingData &operator=(ParsingData &&sSrc);
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