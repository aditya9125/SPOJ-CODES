#include<bits/stdc++.h>

using namespace std;

template<typename type>
inline type max3(type a,type b,type c){	 return max(max(a,b),c);}


template<typename type>
inline type max4(type a,type b,type c,type d){	 return max(a,max3(b,c,d));}

int main()
{

	//FAST_IO();

	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif

	while(true)
	{

		int f,s,m,e,ff,ss,mm,ee;

		cin>>f>>s>>m>>e>>ff>>ss>>mm>>ee;

		if(f==-1) break;

		int x= max4(	ceil((double)f/ff),ceil((double)s/ss),ceil((double)m/mm),ceil((double)e/ee) );

		cout<<abs(f-x*ff)<<" "<<abs(s-x*ss)<<" "<<abs(m-x*mm)<<" "<<abs(e-x*ee)<<"\n";




	}

}
