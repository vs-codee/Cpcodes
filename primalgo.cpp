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

const int N = 1e5;
int node,edg;
vector< pair < int , int > >Graph[N];

int start;
bool vertex[N]={0};
map< pair < int ,int > , int  > Vis;
set<pair < int ,int > >active;
int parent[N];

int find(int n)
{
	if(parent[n]==n)
	return n;
	return parent[n]=find(parent[n]);
}
void Union(int a,int b)
{
	int x=find(a);
	int y=find(b);
	if(x!=y)
	{
		parent[y]=x;	
	}
}

int ans=0;

void MST()
{
	iota(parent,parent+node+1,0);
	int node=1;
	priority_queue< pair <int , int > , vector<pair <int , int > >, greater<pair <int , int > > >q; 
	for(auto i:Graph[node])
	{
		q.push({i.sc,i.fr});
		Vis[{node,i.fr}]=1;
		Vis[{i.fr,node}]=1;
	}
	while(!q.empty())
	{
		int x=q.top().sc;
		int y=q.top().fr;
		q.pop();
		if(parent[node]!=parent[x])
		{
			// cout<<node<<" "<<x<<" "<<y<<ln;
			ans+=y;
			for(auto i:Graph[x])
			{
				if(!Vis[{x,i.fr}] and !Vis[{i.fr, x}])
				q.push({i.sc,i.fr});			
			}
			Union(node,x);
			node=x;
		}		
	}
}

void solve()
{
	cin>>node>>edg;
	for(int i=0;i<edg;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		Graph[u].pb(v,w);
		Graph[v].pb(u,w);
		start=u;
	}
	// MST();
	cout<<ans<<ln;
}


/* CODE ENDS HERE AND MAIN STARTS */

int32_t main()
{
	online();
	//TCI
	solve();
}