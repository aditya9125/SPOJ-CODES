#include<bits/stdc++.h>

#define endl ("\n")
using namespace std;
int main()
{


	//ifstream cin("/home/aditya/Documents/ip");

	int t;
	cin>>t;
	while(t--)
	{

		double a,b,c,d;

		cin>>a>>b>>c>>d;

		double s= ( a+b+c +d)/2;

		double x= (s-a),y=(s-b),z=(s-c),w=(s-d);

		double A= x*y*z*w;

		cout<< setprecision(2)<<fixed<<sqrt(A)<<endl;

	}

}
