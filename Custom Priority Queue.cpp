#include <bits/stdc++.h>
using namespace std;
#define endl            "\n"
#define ff              first
#define ss              second
#define int             long long
#define pb              emplace_back
#define mp              make_pair
#define bs              binary_search
#define pqb             priority_queue<int>
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define test(x)         int x; cin>>x; while(x--)
void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int pow(int a, int b, int c)
{
	int res = 1;
	while (b > 0)
	{
		if (b % 2)
			res = (res * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}
	return res;
}
/*********************CODE BEGINS*******************/
struct camp
{
	int d;
	int t;
	int s;
};
bool cmp1(camp k1, camp k2)
{
	return (k1.d < k2.d);
}
struct camp1
{
	int t1;
	int s1;
};
struct cmp2
{
	bool operator()(camp1 const&a, camp1 const&b)
	{
		if (a.s1 == b.s1)
			return a.t1 < b.t1;
		else
			return a.s1 < b.s1;
	}
};
void ans()
{
	int num, k;
	cin >> num >> k;
	camp A[num + 1];
	for (int i = 0; i < num; i++)
		cin >> A[i].d >> A[i].t >> A[i].s;
	sort(A, A + num, cmp1);
	// for (int i = 1; i <= num; i++)
	// 	cout << A[i].d << " " << A[i].t << " " << A[i].s << endl;
	priority_queue<camp1, vector<camp1>, cmp2> pq;
	int k1 = 0;
	for (int i = 1; i <= k; i++)
	{
		while (A[k1].d == i)
		{
			camp1 temp;
			temp.t1 = A[k1].t;
			temp.s1 = A[k1].s;
			pq.push(temp);
			k1++;
		}
		if (pq.size() > 0)
		{
			camp1 temp = pq.top();
			pq.pop();
			temp.t1--;
			if (temp.t1 > 0)
				pq.push(temp);
		}
	}
	int sum = 0;
	while (!pq.empty())
	{
		camp1 temp = pq.top();
		sum += (temp.t1) * (temp.s1);
		pq.pop();
	}
	cout << sum << endl;
}
int32_t main()
{
	c_p_c();
	test(x)
	ans();
	return 0;
}