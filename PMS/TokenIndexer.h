
/*
	2017.04.10
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_PMS_PARSING_TOKEN_INDEXER_H

#define _CLASS_PMS_PARSING_TOKEN_INDEXER_H

#include "Splitter.h"

#include <cstddef>
#include <deque>
#include <utility>

namespace PMS::Parsing
{
	using TokenIndex = TokenList::const_iterator;

	class TokenIndexer
	{
	private:
		TokenIndex iCurrent;
		TokenIndex iEnd;
		std::deque<TokenIndex> sIndexStack;

	public:
		TokenIndexer(const TokenList &sTokenList);
		TokenIndexer(const TokenIndexer &sSrc);
		TokenIndexer(TokenIndexer &&sSrc);
		~TokenIndexer() = default;

	public:
		TokenIndexer &operator=(const TokenIndexer &sSrc);
		TokenIndexer &operator=(TokenIndexer &&sSrc);

	public:
		inline TokenIndex &current();
		inline const TokenIndex &current() const;
		inline bool isRemain() const;
		inline bool isMatch(TokenType eTokenType, bool bMoveIterator = true);
		inline void moveNext();
		inline void moveNext(TokenIndex::difference_type nCount);
		inline void movePrev();
		inline void movePrev(TokenIndex::difference_type nCount);
		inline void pushCurrent();
		inline void popCurrent();
	};

	inline TokenIndex &TokenIndexer::current()
	{
		return this->iCurrent;
	}

	inline const TokenIndex &TokenIndexer::current() const
	{
		return this->iCurrent;
	}

	inline bool TokenIndexer::isRemain() const
	{
		return this->iCurrent != this->iEnd;
	}

	inline bool TokenIndexer::isMatch(TokenType eTokenType, bool bMoveIterator = true)
	{
		if (!this->isRemain() || this->iCurrent->eType != eTokenType)
			return false;

		++this->iCurrent;

		return true;
	}

	inline void TokenIndexer::moveNext()
	{
		++this->iCurrent;
	}

	inline void TokenIndexer::moveNext(TokenIndex::difference_type nCount)
	{
		this->iCurrent += nCount;
	}

	inline void TokenIndexer::movePrev()
	{
		--this->iCurrent;
	}

	inline void TokenIndexer::movePrev(TokenIndex::difference_type nCount)
	{
		this->iCurrent -= nCount;
	}

	inline void TokenIndexer::pushCurrent()
	{
		this->sIndexStack.emplace_back(this->iCurrent);
	}

	inline void TokenIndexer::popCurrent()
	{
		if (this->sIndexStack.empty())
			return;

		this->iCurrent = this->sIndexStack.back();
		this->sIndexStack.pop_back();
	}
}

#endif