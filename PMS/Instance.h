
/*
	2017.04.09
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_RUNTIME_INSTANCE_H

#define _CLASS_PMS_RUNTIME_INSTANCE_H

#include "Environment.h"
#include "Executable.h"

#include <cstdint>
#include <deque>
#include <string>
#include <utility>
#include <vector>

namespace PMS::Runtime
{
	using PMSStack = std::deque<PMSEntity>;

	class Instance
	{
	private:
		PMSEntity sLHS;
		PMSEntity sRHS;
		PMSStack sStack;
		const Environment &sEnvironment;
		
	public:
		Instance(const Environment &sNewEnvironment);
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