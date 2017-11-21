#include <bits/stdc++.h>
using namespace std;
int main()
{

int t;

cin>>t;
//scanf("%d",&t);


while(t--)
{
    long long int n,c;

    cin>>n;
    //scanf("%lld",&n);

    int ans;

    if(n%2==0)
    {
        c=n/2 - 1;

        if(c%2==0)
            ans=c-1;
        else
			ans=c;
    }
    else
    {
		ans=(n/2);
    }


    if(ans<1) ans=1;

    cout<<ans<<'\n';

}
return 0;
}
