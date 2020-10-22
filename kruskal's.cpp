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
#define pi pair<int,int>
#define vii vector<pair<int,int>> 
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

vector< pair< int ,int > > Graph[N];
int Parent[N];

int Find(int n)
{
	if(parent[n]==n)
	return n;
	return parent[n]=Find(parent[n]);
}
void Union(int a,int b)
{
	int x=Find(a);
	int y=Find(b);
	if(x!=y)
	{
		parent[y]=x;	
	}
}

struct Graph
{
	int a,b,w;
};


bool cmp(const Graph& A, const Graph& B)
{
	return A.w<B.w;
}
void solve()
{
	int node,edg;
	cin>>node>>edg;
	Graph V[edg];
	iota(parent,parent+node+1,0);
	for(int i=0;i<edg;i++)
	{
		cin>>V[i].a>>V[i].b>>V[i].w;
	}
	sort(V,V+edg,cmp);
	int cnt=0,ans=0;
	// for(auto i:V)
	// 	cout<<i.a<<" " << i.b<<" " << i.w<<ln;
	for(auto i:V)
	{
		if(Find(i.a)!=Find(i.b))
		{	
			cout<<i.w<<" "<<i.a<<" "<<i.b<<ln;		
			Union(i.a,i.b);		
			ans+=i.w;
		}		
	}	
	cout<<ans<<ln;



}


/* CODE ENDS HERE AND MAIN STARTS */

int32_t main()
{
	online();
	// TCI
	solve();
}
