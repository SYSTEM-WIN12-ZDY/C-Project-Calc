/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>
using namespace std;
typedef long long ll;


ll OperAddition(ll x,ll y)
{
	return x+y;
}
ll OperSubtraction(ll x,ll y)
{
	return x-y;
}
ll OperMultiplication(ll x,ll y)
{
	return x*y;
}
ll OperDivision(ll x,ll y)
{
	if(y==0) return -1;
	else if(x==0) return 0;
	else return x/y; 
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}
