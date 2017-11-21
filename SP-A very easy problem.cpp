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

template<typename type>
type fastpow(type a, type b, type c) { type ans=1;  while(b != 0){ if(b%2 == 1) ans=(ans*a)%c;  a=(a*a)%c; b /= 2; } return ans; }


template<typename type>
type fastpow(type a, type b){ type ans=1;  while(b != 0){ if(b%2 == 1) ans=(ans*a);  a=(a*a); b /= 2; } return ans; }

#define SIZE int(1e3)+1
#define MOD
#define debug
//#define Online_judge
//ofstream cout("op");
string ans;

void print(int x)
{
//	cout<<"2(";
	ans+="2(";

	if(x==0 or x==1)
	{
//		cout<<x<<")";
		if(x) ans+="1)";
		else ans+="0)";

		return;
	}
	while(x){

		print(log2(x));

		x=x-fastpow(2,(int)log2(x));

		if(x)
			ans+="+";
		//cout<<"+";
	}
//	cout<<")";
ans+=")";

}


int main()
{
	FAST_IO();
	//ifstream cin("ip");
	ofstream cout("op");
	int pw ;
	int ip[]={137,1315,73,136,255,1384,16385};
	int indx=0;


while(indx<7)
{
	ans.erase(whole(ans));

	int x=ip[indx++];

	cout<<x<<"=";

	while(x){

		print(log2(x));

		x=x-fastpow(2,(int)log2(x));

		if(x)
		ans+="+";
		//cout<<"+";
	}

/*
	while(x & x-1){
	//flag=true;
	//cout<<log2(x);
	 pw=ll(log2(x));
	cout<<pw<<" ";

	x-=fastpow(ll(2),pw);

	}

	if((x & x-1) ==0)
	  cout<<log2(x)<<" ";
*/
    //cout<<ans<<"\n";

	string newans="";
	int i=0;
	while(i<ans.size())
	{

		if(i+4<=ans.size() and ans.substr(i,4).compare("2(1)")==0)
		   newans+="2",i+=4;
		   //cout<<"gottcha at i="<<i<<endl,newans+="2",cout<<"ans="<<ans<<"\n"<<"new="<<newans<<endl,i+=4;
		else newans+=ans.substr(i++,1);


	}

	cout<<newans<<"\n";
}

}
