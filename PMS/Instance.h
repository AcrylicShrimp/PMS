
/*
	2017.04.09
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_RUNTIME_INSTANCE_H

#define _CLASS_PMS_RUNTIME_INSTANCE_H

#include <cstdint>
#include <deque>
#include <string>
#include <utility>
#include <vector>

namespace PMS::Runtime
{
	union PMSElement
	{
		int64_t nInt;
		double nReal;
		std::u32string *pString;
		std::vector<PMSElement> *pList;
		PMSElement *pReference;

		void *pRawValue;				//For copy.
	};

	enum class PMSType : uint32_t
	{
		Int,
		Real,
		String,
		List
	};

	using PMSStack = std::deque<std::pair<PMSElement, PMSType>>;

	class Instance
	{
	private:
		PMSElement sLHS;
		PMSElement sRHS;

		PMSStack sStack;

		
	public:
		Instance();
		Instance(const Instance &sSrc);
		Instance(Instance &&sSrc);
		~Instance();
		/*
			TODO : Place your other constructors here.
		*/
		
		
	public:
		Instance &operator=(const Instance &sSrc);
		Instance &operator=(Instance &&sSrc);
		/*
			TODO : Place your other operator overloadings here.
		*/
		
		
	public:
		/*
			TODO : Place your member function declarations here.
		*/
		

	private:
		void extractOne();
		void extractTwo();

	};
}

#endif