///Status : AC
///Remark :
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#include<bits/stdc++.h>

#define nl ("\n")

using namespace std;
inline void FAST_IO(){ios_base::sync_with_stdio(false);}



int main()
{

	FAST_IO();

	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif

	//ofstream cout("/home/aditya/Documents/op");

	int t;	cin>>t;while(t--){


		ll n;



		cin>>n;

		if(n&1){ cout<<n<<nl; continue;}

		bitset<64> bset(n);


		int bits = floor(log2(n))+1;


		//for(int i=0;i<bits;i++) cout<<bset[i]<<" ";

/*
		string s="";

		for(int i=0;i<bits;i++) s+= ( (bset[i])?'1':'0');

		cout<<s<<nl;

*/

//		reverse(whole(s));

//		bitset<64> revset(s);

//		cout<<revset.to_ulong();

	//	cout<<nl<<" bits= "<<bits<<nl;

		bitset<64> rev;

		for(int i=0;i<bits;i++)
		{
			rev[i]= bset[bits-i-1];
		}

//		for(int i=0;i<bits;i++) cout<<rev[i]<<" ";

		cout<<rev.to_ulong()<<nl;





	}






}

