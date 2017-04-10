
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_RUNTIME_EXECUTABLE_H

#define _CLASS_PMS_RUNTIME_EXECUTABLE_H

#include <cstdint>
#include <utility>
#include <vector>

namespace PMS::Runtime
{
	enum class Command : uint16_t
	{
		ADD,
		SUB,
		MUL,
		POW,
		DIV,
		MOD,
		REF,
		PUSH,
		POP,
		CALL,
		CALL_C,

	};

	using Executable = std::vector<Command>;
}

#endif