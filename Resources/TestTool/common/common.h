#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <wchar.h>
#include <wctype.h>


namespace TestCommon
{
	enum ExecutorsMode
	{
		TEST_ROP_CHAIN = 0x01,
        GET_REMOTE_FUNCTION_ADDRESS,
		NA,
	};

	inline const wchar_t* ExecutorModeToString(ExecutorsMode value)
	{
		switch (value)
		{
		case TEST_ROP_CHAIN:			     return L"Test ROP Chain";
        case GET_REMOTE_FUNCTION_ADDRESS:    return L"Get Remote Function Address";
		default:						     return L"[Unknown TestExecutor]";
		}
	}

	struct TestData
	{
		TestData() {};

		std::wstring testcaseFile;
		std::wstring fileToInject;
		std::wstring pidToInject;
		std::wstring channelID;
	};

	static const bool DEFAULT_VERBOSITY_STATUS = false;
	static const ExecutorsMode DEFAULT_EXECUTOR_MODE = ExecutorsMode::NA;
	static const std::wstring DEFAULT_DLL_TO_INJECT = L"testtoolagent.dll";
	static const std::wstring PRE_CHANNEL_TOKEN = L"TESTTOOLAGENTIPC_";

	typedef std::vector<unsigned char> ARRAYBYTE;

	static inline void Xtrace(LPCTSTR lpszFormat, ...)
	{
		va_list args;
		va_start(args, lpszFormat);
		int nBuf;
		TCHAR szBuffer[2048] = { 0 }; //fix this
		nBuf = _vsnwprintf_s(szBuffer, 2047, lpszFormat, args);
		::OutputDebugString(szBuffer);
		va_end(args);
	}
}


#endif