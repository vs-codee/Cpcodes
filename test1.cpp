/* Author VS_CODE */

#include<bits/stdc++.h>
#define int long long
#define TCI long long t;cin>>t;while(t--)
#define run(n) for(long long i=1;i<=n;i++)
#define cinl(n) for(long long i=0;i<n;i++)
#define ln "\n"
#define vpair vector< pair <long long , long long > >
#define fr first
#define sc second
#define pb emplace_back
#define vll vector<long long>
#define inf 0x3f3f3f3f3f3f3f3fLL
#define Point complex<int>
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

void solve()
{
	int n;
	cin>>n;
	int A[n];
	cinl(n ) cin>>A[i];
	string ans[n+1];
	char ch='b';
	for(int j=0;j<n+1;j++)
	{	
		char ch1=ch;	
		for(int i=0;i<55;i++)
		{
			ans[j]+=ch1;
			ch1++;
			if(ch1>'z')
				ch1='a';
		}
		ch++;
		if(ch>'z')
			ch='a';
	}	
	for(auto i:ans)
		cout<<i<<ln;
	cout<<ln;
	if(n==1)
	{
		int x=A[0];
		if(x!=0)
		{
			ch='a';
			for(int i=0;i<x;i++)
			{
				ans[0][i]=ch;
				ans[1][i]=ch;
				ch++;
				if(ch>'z')
					ch='a';
			}
		}		
	}
	else
	{
		cout<<"HELLO"<<ln;
		for(int i=0;i<n-1;i++)
		{
			int x=A[i];
			cout<<"X"<<x<<ln;
			ch='a';
			if(x==0)
				continue;
			else
			{				
				for(int k=0;k<x;k++)
				{
					ans[i][k]=ch;
					ans[i+1][k]=ch;
					ch++;
					if(ch>'z')
						ch='a';
				}
			}
		}
	}
	cinl(n+1)
	{
		cout<<ans[i]<<ln;
	}
}



/* CODE ENDS HERE AND MAIN STARTS */
int32_t main()
{
	online();
	TCI
	solve();
}