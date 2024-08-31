#include <Windows.h>
#include <iostream>
int __stdcall EmptyFunction(int a1, int a2) 
{
    return 1;
}

typedef int (*FunctionPtr)();

int __stdcall XignCode_Initialize(wchar_t* a1, wchar_t* a2, int a3)
{
    printf("XignCode::Initialize - %ws, %ws, %d\n", a1, a2, a3);
    return 1;
}

int XignCode_uninitialize()
{
    printf("XignCode::uninitialize\n");
    return 1;
}

int XignCode_start_service()
{
    printf("_XignCode::start_service\n");
    return 1;
}

int XignCode_stop_service()
{
    printf("_XignCode::stop_service\n");
    return 1;
}

int XignCode_make_response(int a1, int a2, int a3, int a4)
{
	printf("XignCode::make_response\n");
	return 1;
}

int __stdcall _1_(FunctionPtr* a1, int a2)
{
    switch (a2) {
    case 1:
        *a1 = (FunctionPtr)XignCode_Initialize;
        break;
    case 2:
        *a1 = (FunctionPtr)XignCode_uninitialize;
        break;
    case 3:
        *a1 = (FunctionPtr)XignCode_start_service;
        break;
    case 4:
        *a1 = (FunctionPtr)XignCode_stop_service;
        break;
    case 6:
        *a1 = (FunctionPtr)XignCode_make_response;
        break;
    case 22:
    case 26:
        *a1 = (FunctionPtr)EmptyFunction;
        break;
    default:
        break;
    }
    return 0;
}
#pragma comment(linker, "/export:_1@1=_1_,@1")

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

