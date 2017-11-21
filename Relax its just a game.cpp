#include <iostream>
using namespace std;

int main() {

	while(1)
	{


		int a,b;

		cin>>a>>b;

		if(a==-1 and b==-1) break;

		bool ans = (a==1 or b==1);


		if(ans){

			cout<<a<<"+"<<b<<"="<<(a+b);
		}
		else cout<<a<<"+"<<b<<"!="<<(a+b);

		cout<<"\n";


	}
	// your code goes here
	return 0;
}
