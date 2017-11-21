#include<bits/stdc++.h>

using namespace std;




int main()
{


	cin.sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif

    int n,k;
    cin>>n;


    vector<int> v;

    int val;
    for(int i=0;i<n;i++)
    {
		cin>>val;
		v.push_back(val);
	}
	cin>>k;

	deque<int> dq;

	///first store the useful element among first k elements and obtain the maximum of them
	for(int i=0;i<k;i++)
	{

		while(!dq.empty() and v[i]>=v[dq.back()])
		 dq.pop_back();


		dq.push_back(i);
	}
	///Now traverse from i=k;

	for(int i=k;i<n;i++)
	{
		///first advance the left pointer ,to obtain the current window left pointer
		cout<<v[dq.front()]<<" ";

		while(!dq.empty() and dq.front()<=i-k)
		 dq.pop_front();
		 ///so far we have adjusted the left
		 ///Now add next element to obtain the current window

		while(!dq.empty() and v[i]>= v[dq.back()])
		  dq.pop_back();

		dq.push_back(i);///we have stored all the elements for the current window ,and we'll print the maximum of this window in the next iteration
	}

///to print aswer for last window
	cout<<v[dq.front()];

}






