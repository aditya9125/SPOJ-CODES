#include<bits/stdc++.h>

using namespace std;

vector<int> flag,pos,isprime;

const int n=int(1e6);




int main()
{


	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif

	flag=vector<int>(n,1);
	pos=vector<int>(n);

	isprime=vector<int>(101,1);


	for(int i=2;i*i<=100;i++)
	{
        if(isprime[i])
        {
            for(int j=i*i;j<=100;j+=i)
            {
				isprime[j]=0;
			}
		}
	}


	vector<int> ex;


	for(int i=11;i<=100;i++) if(isprime[i]) ex.push_back(i);

	for(int i=0;i<ex.size();i++)
    {

        int I= ex[i]*ex[i]*ex[i];

        for(int J=I; J<=n;J+=I)
		{
            flag[J-1]=0;
        }

    }


    for(int i=2;i<=10;i++)
    {

        int I= i*i*i;

        for(int J=I; J<=n;J+=I)
		{
            flag[J-1]=0;
        }

    }

	int k=0;

    for(int i=0;i<n;i++)
    {
		if(flag[i]){

            pos[i]=k++;
		}

    }

//    for(int i=0;i<50;i++) {cout<<flag[i]<<" ";}



    int t,test;

    cin>>t;

    test=t;

    while(t--)
    {
		cout<<"Case "<<test-t<<": ";
        int x;

        cin>>x;

        if(!flag[x-1])	cout<<"Not Cube Free\n";
        else cout<<pos[x-1]+1<<'\n';
	}


}
