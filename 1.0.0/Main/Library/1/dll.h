#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif
typedef long long ll;
/*
class DLLIMPORT DllClass
{
	public:
		DllClass();
		virtual ~DllClass();
		void OperAddition(ll x,ll y);
		void OperSubtraction(ll x,ll y);
		void OperMultiplication(ll x,ll y);
		void OperDivision(ll x,ll y);
};*/
extern "C"
{
	DLLIMPORT ll OperAddition(ll x,ll y);
	DLLIMPORT ll OperSubtraction(ll x,ll y);
	DLLIMPORT ll OperMultiplication(ll x,ll y);
	DLLIMPORT ll OperDivision(ll x,ll y);
} 

#endif
