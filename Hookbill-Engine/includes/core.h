// My Goal if anyone add this header file use my engine code
#pragma once
#include<vector>
#include<string>

#ifdef HOOKBILL_EXPORT
#ifdef _MSC_VER
#define HOOKBILL_API __declspec(dllexport)
#else
#define HOOKBILL_API __attribute__((visibility("default")))

#endif

#else
#ifdef _MSC_VER
#define HOOKBILL_API __declspec(dllimport)
#else
#define HOOKBILL_API
#endif

#endif

#define HookBill_ASSERT assert

#if defined(__clang__) || defined(__gcc__)
#define HOOOKBill_STATIC_ASSERT _Static_assert
#else
#define HOOKBill_STATIC_ASSERT static_assert
#endif

#define HOOKBILL_DELETE(ptr) if (ptr != nullptr) { delete (ptr); ptr = nullptr; }

