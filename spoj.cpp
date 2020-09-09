/* Author VS_CODE */

#include<bits/stdc++.h>
#define int long long 
#define TCI int t;cin>>t;while(t--)
#define run(n) for(int i=1;i<=n;i++)
#define cinl for(int i=0;i<n;i++)
#define ln "\n"
#define vpair vector< pair <int , int > >
#define fr first
#define sc second
#define pb emplace_back
#define vll vector<int>
using namespace std;

void online()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/* CODE STARTS HERE */

const int N = 1e6+2;

int divcount(int n)
{
	int cnt=0;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			if(i!=n/i) cnt+=2;
			else cnt++;
		}
	}
	if(n==1)
	cnt--;
	return cnt+2;
}


bitset<100000007>prime;
vll Primes;

void sieve()
{
	prime[0]=1;
	prime[1]=1;
	for(int i=2;i<=N;i++)
	{
		if(!prime[i])
		{
			Primes.pb(i);
			for(int j=i*2;j<=N;j+=i)
			{
				prime[j]=1;
			}
		}
	}
}


void solve()
{
	sieve();
	int n;
	cin>>n;
	if(prime[n]==0)
		cout<<2<<ln;
	else
	cout<<divcount(n)<<ln;
}


/* CODE ENDS HERE AND MAIN STARTS */

int32_t main()
{
	online();
	TCI
	solve();
}