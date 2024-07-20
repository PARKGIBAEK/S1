#pragma once

#if  defined(_DEBUG) && (defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__))
#pragma comment(lib, "ServerCore\\x64\\Debug\\ServerCore.lib")
#elif  defined(NDEBUG) && (defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__))
#pragma comment(lib, "ServerCore\\x64\\Release\\ServerCore.lib")
#endif

