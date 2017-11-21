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
#define newline cout<<"\n"
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
int main()
{
//	FAST_IO();
	ifstream cin("ip");

		int t,i;
		int cnt[9];
		vector<string> vs{"TTT", "TTH", "THT", "THH","HTT", "HTH", "HHT","HHH"};

		//for(auto item:vs) cout<<item<<" ";

		cin>>t;
		int k=t;

		while(t--)
		{
			int x;
			string s;

			cin>>x;
			cin>>s;

			FILL(cnt,0);

			rep(i,0,s.size()-2)
			{

				string temps=s.substr(i,3);

				for(int j=0;j<vs.size();j++)
				{
				  if(temps==vs[j])
				    cnt[j]++;

				}
	//			while()

			}

			cout<<k-t<<" ";

			rep(i,0,vs.size())
			{
				cout<<cnt[i]<<" ";
			}
			newline;
		}

}
