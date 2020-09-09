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
const int inf=1e9;
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

const int N = 1e5+2;
int node,edg;

vector< pair < int, int > > Graph[N];
int dist[N];

//   FINDS SHORTEST DISTANCE TO ALL NODES FROM n // 

void dijkstra(int n)
{
	for(int i=1;i<=node;i++)
		dist[i]=1e18;
	priority_queue< pair <int , int > , vector< pair <int , int > >, greater< pair <int , int > > >q;
	q.push({0,n});
	dist[n]=0;

	while(!q.empty())
	{
		int x= q.top().sc;
		q.pop();

		for(auto i:Graph[x])
		{
			if(dist[i.fr] > dist[x] + i.sc)
			{
				dist[i.fr] = dist[x] + i.sc;
				q.push({dist[i.fr] , i.fr});
			}			
		}
	}

}

// FINDS SHORTEST DISTANCE PATH FROM n TO DESTINATION //

int parent[N+1]={0};
int destination;
void dijkstrawithpath(int n)
{
	for(int i=1;i<=node;i++)
		dist[i]=1e18;
	priority_queue< pair <int , int > , vector<pair <int , int > >, greater<pair <int , int > > >q;
	q.push({0,n});
	dist[n]=0;

	while(!q.empty())
	{
		int x= q.top().sc;
		q.pop();

		for(auto i:Graph[x])
		{
			if(dist[i.fr] > dist[x] + i.sc)
			{
				dist[i.fr] = dist[x] + i.sc;
				q.push({dist[i.fr] , i.fr});
				parent[i.fr]=x;
			}			
		}
	}

	if(parent[destination]==0)
		cout<<-1<<ln;
	else
	{
		stack<int > ans;
		while(destination)
		{
			ans.push(destination);
			destination=parent[destination];
		}
		while(!ans.empty())
			cout<<ans.top()<<" " , ans.pop();

	}
}
void solve()
{		
	cin>>node>>edg;
	destination=node;
	while(edg--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		Graph[u].pb(v,w);
		Graph[v].pb(u,w);
	}
	dijkstra(1);
	run(node)
	{
		cout<<dist[i]<<" ";
	}
	cout<<ln;
}


/* CODE ENDS HERE AND MAIN STARTS */

int32_t main()
{
	online();
	//TCI
	solve();
}