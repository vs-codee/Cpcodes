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
#define vint vector<int>
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

const int N = 2e5 + 7;
vector<int >Graph[N];
bool Col[N];
map<int,bool>Vis;
int node, edg;

bool iscycle(int n)
{
	Vis[n] = 1;
	Col[n] = 1;
	for (auto i : Graph[n])
	{
		if (!Vis[i])
		{
			int x = iscycle(i);
			if (x)
				return true;
		}
		else
		{
			if (Col[i] == true)
				return true;
		}
	}
	Col[n] = 0;
	return 0;
}

void solve()
{
	vector<pair < int , int > >ans;
	cin >> node >> edg;
	vpair undir;
	bool help[N] = {0};
	for (int i = 1; i <= node; i++)
		Graph[i].clear();
	Vis.clear();
	vint v;
	run(edg)
	{
		int k;
		cin >> k;
		int x, y;
		cin >> x >> y;
		if (k == 1)
			Graph[x].pb(y),ans.pb(x, y);
		else
			v.pb(x), v.pb(y),undir.pb(x,y);
	}
	// cout<<"S:" <<ans.size()<<ln;
	int f = 0;
	for (auto i : v)
	{
		if (iscycle(i))
			f = 1;
	}

	if (f)
		{cout << "NO" << ln;return;}

	multimap<int,int>mp;
	cout<<"YES"<<ln;
	for (auto i : ans)
	{
		mp.insert({i.fr,i.sc});
		help[i.sc] = 1;
	}
	// cout<<undir.size()<<ln;

	for (auto i : undir)
	{
		int x = i.fr;
		int y = i.sc;
		if (help[x] == 1)
		{
			if(help[y]==0)
			{
				Graph[y].pb(x);
				ans.pb(y,x);				
			}
			else
			{
				z
			}
		}
		else
		{
			ans.pb(y,x);
		}
	}
	for (auto i : ans)
		cout << i.fr << " " << i.sc << ln;

}


/* CODE ENDS HERE AND MAIN STARTS */

int32_t main()
{
	online();
	TCI
	solve();
}