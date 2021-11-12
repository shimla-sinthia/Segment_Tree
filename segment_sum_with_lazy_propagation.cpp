//https://lightoj.com/problem/horrible-queries


//Bismillah Hir Rehmanir Rahim
//Allah knows best
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using    namespace __gnu_pbds;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#define gap ' '
#include <bitset>
#define mini -10000000000000000
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define f(i, a, n) for(int i=a; i<n;i++)
#define ll long long
#define int long long
#define pi 3.141592653589793
#define vi              vector<ll>
#define si              set<ll>
#define pb              push_back
#define mp              make_pair
#define mod             998244353
#define rr              return 0
#define ff              first
#define in              insert
#define ss              second
ll hash58 = 288230376151711717;
ll hash32 = 1610612741;
#define erase_unique(st)        st.erase(unique(st.begin(), st.end()),st.end())
#define all(a) a.begin(), a.end()
typedef pair<ll, ll> pii;
#define setbits(x)      __builtin_popcountll(x)
#define zrbits(x)       __builtin_ctzll(x)
#define unset_bit(x,inx) x = (x & ~(1ll<<(inx)))
#define deb(x)          cout << #x << " = " << x << endl
#define set_bit(x, idx) x = x|1LL<<idx
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define toggle_bit(x, idx) x = x^(1LL<<idx)
inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
#define ordered_set             tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#ifdef DEBUG
#define ok cerr << __LINE__ <<"is done "<<endl;
#else
#define ok 
#endif
#define ld long double
const int maxN = 100005;
int ar[maxN];
int st[4 * maxN] , lazy[4 * maxN];
 
void build(int sii , int sss , int se)
{
	if(sss == se)
	{
		st[sii] = ar[sss];
		return;
	}
 
	int mid = (sss + se) / 2;
 
	build(2 * sii , sss , mid);
	build(2 * sii + 1 , mid + 1 , se);
 
	st[sii] = st[2 * sii] + st[2 * sii + 1];
}
 
int query(int sii , int sss , int se , int qs , int qe)
{
	if(lazy[sii] != 0)
	{
		int dx = lazy[sii];
		lazy[sii] = 0;
		st[sii] += dx * (se - sss + 1);
 
		if(sss != se)
		{
         lazy[2 * sii] += dx ;
         lazy[2 * sii + 1] += dx;
      }
	}
 
	if(sss > qe || se < qs) return 0;
 
	if(sss >= qs && se <= qe)
	return st[sii];
 
	int mid = (sss + se) / 2;
	return query(2 * sii , sss , mid , qs , qe) + query(2 * sii + 1 , mid + 1 , se , qs , qe);
}
 
void update(int sii , int sss , int se , int qs , int qe , int val)
{
	if(lazy[sii] != 0)
	{
		int dx = lazy[sii];
		lazy[sii] = 0;
		st[sii] += dx * (se - sss + 1);
 
		if(sss != se)
		{lazy[2*sii] += dx ;
       lazy[2*sii+1] += dx;}
	}
 
	if(sss > qe || se < qs) return;
 
	if(sss >= qs && se <= qe)
	{
		int dx = (se - sss + 1) * val;
		st[sii] += dx;
 
		if(sss != se)
		lazy[2 * sii] += val , lazy[2 * sii + 1] += val;
		return;
	}
 
	int mid = (sss + se) / 2;
	update(2 * sii , sss , mid , qs , qe , val);
	update(2 * sii + 1 , mid + 1 , se , qs , qe , val);
 
	st[sii] = st[2 * sii] + st[2 * sii + 1];
}
 
 
int32_t main()
{
    #ifndef DEBUG
   ios
   #else
   freopen("in", "r", stdin);
    //freopen("output.txt", "w", stdout);
   #endif
   ll t = 1;
   cin >> t;
 
  for(int j = 1; j <= t; j++)
   {
	int n , q , code , l , r , val;
	cin >> n >> q;

   //for(int i = 1; i <= n; i++) ar[i] = 0;
   for(int i = 1; i <= 4 * n + 5; i++) st[i] = 0;
   for(int i = 1; i <= 4 * n + 5; i++) lazy[i] = 0;

     //build(1 , 1 , n);
   cout << "Case " << j <<":"<< endl;
	while(q--)
	{
		cin >> code;
		if(code == 1)
		{
			cin >> l >> r;
         l++;
         r++;
         cout << query(1 , 1 , n , l , r) << endl;
		}
		else
		{
			cin >> l >> r >> val;
         l++;
         r++;
			update(1 , 1 , n , l , r , val);
         //for(int i = 0; i <= n; i++) deb(ar[i]);
		}
	}
   }
   rr;
}
