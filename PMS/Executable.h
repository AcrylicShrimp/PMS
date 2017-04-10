
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
	enum class Instruction : uint8_t
	{
		CLEAR,
		VAL,
		CONST,
		ASGN,
		CAST,

		JMP,
		JZ,
		CALL,
		RET,

		ADD,
		SUB,
		MUL,
		POW,
		DIV,
		MOD,
		SIGN,

		EQ,
		NEQ,
		LE,
		LEQ,
		GT,
		GTQ,

		NOT,
		AND
	};

	using Executable = std::vector<Instruction>;
}

#endif