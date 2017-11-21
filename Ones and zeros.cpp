///Status : Pending
///Remark :
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#include<bits/stdc++.h>
#define nl ("\n")
#define newl cout<<nl
using namespace std;


inline void FAST_IO(){ios_base::sync_with_stdio(false);}

int main()
{

	FAST_IO();

	#ifndef ONLINE_JUDGE
		//	ifstream cin("/home/aditya/Documents/ip");
	#endif
	//ofstream cout("/home/aditya/Documents/op");

		int t;	cin>>t;while(t--){


                int n;

                cin>>n;


                queue<ll> q;

				q.push(1);

				ll item;

                while(!q.empty())
                {

                   item= q.front();

				   q.pop();

                   if(item%n==0){

						break;
                   }

                   q.push(item*10);
                   q.push(item*10+1);
				}

				cout<<n<<" "<<item<<nl;

		}

}





