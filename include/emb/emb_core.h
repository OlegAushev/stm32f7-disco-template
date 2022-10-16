/**
 * @file emb_core.h
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once


#include "emb_def.h"


namespace emb {


inline void emptyFunction() {}
inline void invalidFunction() { while (true) {} }


class NonCopyable
{
public:
	NonCopyable() = default;
	NonCopyable(const NonCopyable& other) = delete;
	NonCopyable& operator=(const NonCopyable& other) = delete;
	virtual ~NonCopyable() = default;
};


} // namespace emb