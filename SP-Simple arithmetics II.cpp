typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#include<bits/stdc++.h>
#include<cmath>
#include<cstdlib> //for qsort
#include<cstdio>

#define rep(x,a,b) for(x=a;x<b;x++)
#define reptill(x,a,b) for(x=a;x<=b;x++)

#define scani(x) scanf("%d",&x)
#define scan2i(x,y) scanf("%d %d",&x,&y)
#define scan3i(x,y,z) scanf("%d %d %d",&x,&y,&z)

#define scanfl(x) scanf("%f",&x)
#define scanc(x) scanf("%c",&x)
#define scand(x) scanf("%lf",&x)

#define scanll(x) scanf("%lli",&x)
#define scan2ll(x,y) scanf("%lli %lli",&x,&y)
#define scan3ll(x,y) scanf("%lli %lli %lli",&x,&y,&z);

#define scanl(x) scanf("%ld",&x)
#define scans(x) scanf("%s",x)
#define printi(x) printf("%d\n",x)
#define printl(x) printf("%ld\n",x)
#define printll(x) printf("%lli\n",x)
#define printd(x) printf("%lf\n",x)
#define printfl(x) printf("%f\n",x)
#define printc(x) printf("%c\n",x)
#define prints(x) printf("%s\n",x);
#define sloop(x) loop(i,0,strlen(x)-1)
#define whole(x) x.begin(),x.end()
#define pb push_back
#define newl cout<<"\n"
#define F first
#define S second
#define FILL(A,value) memset(A,value,sizeof(A))

inline bool inc_range(int x,int y,int z) { return ((x>=y)&&(x<=z)); }
inline bool ex_range(int x,int y,int z) { return ((x>y)&&(x<z)); }
inline bool is_either(int x,int y,int z) { return ((x==y)||(x==z)); }

//maths
#define PI acos(-1)

#define INTmax numeric_limits<int>::max()
#define LLmax numeric_limits<ll>::max()
#define ULLmax numeric_limits<ull>::max()

#define INTmin numeric_limits<int>::min()


using namespace std;

template<typename type=int>
void get_arr(type a[],type n) {for(type i=0;i<n;i++) cin>>a[i];}

template<typename type=int>
void show_arr(type a[],type n=1) {for(type i=0;i<n;i++) cout<<a[i]<<" ";}

template<typename type=int>
inline type max3(type a,type b,type c){	 return max(max(a,b),c);}

inline void FAST_IO(){ios_base::sync_with_stdio(false);}

#define SIZE int(1e3)+1
#define MOD
#define debug
//#define Online_judge

bool isnum(string s)
{
	if(s.size()>1) return true;

	return !(s[0]=='-' or s[0]=='/' or s[0]=='+' or s[0]=='*' or s[0]=='%');
}

ll tonum(string s)
{
	ll ans=0;
	int i;
	rep(i,0,s.size())
	{
		ans=ans*10+(s[i]-'0');
	}
	return ans;
}

inline ll perform(ll a,char oprtr,ll c)
{

	switch(oprtr)
	{

		case '+':return (a+c);
		case '-':return (a-c);
		case '/':return (a/c);
		case '*':return (a*c);
		case '%':return (a%c);

	}


}
int main()
{
	FAST_IO();
	//ifstream cin("ip");

	int t;
	cin>>t;

	stack<char> stor;

	while(t--)
	{
		ll last=1,cnt=0;
		string str;
		while(true)
		{
				cin>>str;
				if(str=="=")
				   break;


			if(isnum(str))
			{
				//	cout<<str<<" is num "<<endl;
				++cnt;

				if(cnt==1) last=tonum(str);

				if(cnt==2)
				{					///a 	operation   b

					last=perform(last,stor.top(),tonum(str));
					stor.pop();

					cnt--;
				}


			}
			else stor.push(str[0]);

		}
		cout<<last<<"\n";
	}

}

