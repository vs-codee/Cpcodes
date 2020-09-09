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
#define inf 1e10;
using namespace std;

void online()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
}
/* CODE STARTS HERE */

const int N = 1e5;

void buildtree(int *A, int s, int e, int *tree, int index)
{
	if (s == e)
	{
		tree[index] = A[s];
		return;
	}

	int mid = (s + e) / 2;
	buildtree(A, s, mid, tree, 2 * index);
	buildtree(A, mid + 1, e, tree, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int query(int *tree, int ss, int se, int qs, int qe, int index)
{
	// No Overlap
	if (qe<ss or qs>se)
	{
		return inf;
	}

	// Complete Overlap
	if (ss >= qs and se <= qe)
	{
		return tree[index];
	}


	int mid = (ss + se) / 2;
	int left = query(tree, ss, mid, qs, qe, 2 * index);
	int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
	return min(left, right);

}


void pointupdate(int *tree , int index, int i, int value,int ss, int se)
{
	if(i<ss or i>se)
		return;

	if(ss==se)
	{
		tree[index]+=value;
		return;
	}
	
		int mid=(ss+se)/2;
		pointupdate(tree, index*2, i, value, ss, mid);	
		pointupdate(tree, index*2+1, i ,value, mid+1, se);
		tree[index]=min(tree[2*index],tree[2*index+1]);
}

// void rangeupdate(int *tree, int ss ,int se, int l, int r, int value,int index)
// {
// 	if(l>se or r<ss)
// 		return;

// 	if(ss==se)
// 	{
// 		tree[index]+=value;
// 		return;
// 	}

// 	int mid=(ss+se)/2;
// 	rangeupdate(tree,ss,mid,l,r,value,2*index);
// 	rangeupdate(tree,mid+1,se,l,r,value,2*index+1);

// 	tree[index]=min(tree[2*index], tree[2*index+1]);
// 	return;

// }
void solve()
{
	int n;
	cin >> n;
	int q;
	cin >> q;
	int A[n];
	cinl cin >> A[i];
	int *tree = new int[4 * n + 1];
	buildtree(A, 0, n - 1, tree, 1);
	while (q--)
	{
		int x;
		cin>>x;
		if(x==2)
		{
			int l,r;
			cin>>l>>r;
			cout<<query(tree,0,n-1,--l,--r,1)<<ln;
		}
		else
		{
			int ind,value;
			cin>>ind>>value;
			ind--;
			pointupdate(tree,1,ind,value,0,n-1);
		}
	}
}


/* CODE ENDS HERE AND MAIN STARTS */

int32_t main()
{
	online();
	//TCI
	solve();
}