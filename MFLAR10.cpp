
#include<bits/stdc++.h>
using namespace std;

int main()
{

	//ifstream cin("/home/aditya/Documents/ip");

	while(1)
	{
		string s;

		getline(cin,s);

		if(s[0]=='*') break;

		string S=" "+s;

		//cout<<"S is "<<S<<'\n';

		set<char> st;

		for(int i=1;i<S.size();i++){

            if(S[i-1]==' ') st.insert(S[i]);
		}

		set<char> stt;

		for(auto item:st) stt.insert(toupper(item));

		if(stt.size()==1) cout<<"Y\n";
		else cout<<"N\n";


	}


}
