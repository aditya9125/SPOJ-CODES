#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename type>
type gcd(type A,type B)
{
	if(B==0)	return A;	else return gcd(B, A % B);
}

int main()
{

	ios_base::sync_with_stdio(false);

//ifstream cin("/home/aditya/Documents/ip");
int t;
cin>>t;

while(t--)
{
	int B;
	cin>>B;

	string A;
	cin>>A;

	int s=0;

	if(B==0)
	{
		cout<<A<<"\n";
		continue;
	}

	for(int i=0;i<A.size();i++)
	{
		s=  s*10 +  (A[i]-'0');
		s%= B;

	}

	cout<<gcd(B,s)<<"\n";		///now s is in range

}

}

