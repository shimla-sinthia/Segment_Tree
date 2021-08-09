// problem - https://www.codechef.com/problems/MULTQ3

// solution - https://www.codechef.com/viewsolution/49630350

// code
//Bismillah Hir Rehmanir Rahim
//Allah knows best
//#include<bits/stdc++.h>
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
#define f(i, a, n) for( i=a; i<n;i++)
#define ll long long
#define pi 3.141592653589793
#define vi              vector<ll>
#define si              set<ll>
#define pb              push_back
#define mp              make_pair
#define mod             1000000007
#define rr              return 0
#define ff              first
#define in              insert
#define ss              second
ll hash58 = 288230376151711717;
ll hash32 = 1610612741;
#define erase_unique(st)        st.erase(unique(st.begin(), st.end()),st.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
typedef pair<ll, ll> pii;
#define setbits(x)      __builtin_popcountll(x)
#define zrbits(x)       __builtin_ctzll(x)
#define unset_bit(x,inx) x = (x & ~(1ll<<(inx)))
#define deb(x)          cerr << #x << " = " << x << endl
#define set_bit(x, idx) x = x|1LL<<idx
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define toggle_bit(x, idx) x = x^(1LL<<idx)
inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> rordered_set;
#ifdef DEBUG
#define ok cerr << __LINE__ <<"is done "<<endl;
#else
#define ok 
#endif
#define ld long double
#define int ll

const int maxN = 100005;
struct node{

       ll a[3];
}seg[4 * maxN];

int lazy[4*maxN];
 
void build(int sii , int sss , int see)
{
	if(sss == see)
	{
	   seg[sii].a[0] = 1;
	   seg[sii].a[1] = 0;
	   seg[sii].a[2] = 0;
	   return;
	}

	int mid = (sss + see) / 2;
 
	build(2 * sii , sss , mid);
	build(2 * sii + 1 , mid + 1 , see);
 
	seg[sii].a[0] = seg[2*sii].a[0] + seg[2*sii+1].a[0];
	seg[sii].a[1] = seg[2*sii].a[1] + seg[2*sii+1].a[1];
	seg[sii].a[2] = seg[2*sii].a[2] + seg[2*sii+1].a[2];
}
void shift(int sii)
{
	int a = seg[sii].a[2];
	seg[sii].a[2] = seg[sii].a[1];
	seg[sii].a[1] = seg[sii].a[0];
	seg[sii].a[0] = a;
}

int query(int sii , int sss , int see , int qs , int qe)
{
	if(lazy[sii] != 0)
	{
		int dx = lazy[sii];
		lazy[sii] = 0;
              if(sss != see)
		{
                 lazy[2 * sii] += dx ;
                 lazy[2 * sii + 1] += dx;
              }
              dx %= 3;
		for(int i = 0; i < dx; i++)
              shift(sii);
	}
 
	if(sss > qe || see < qs) 
       return 0;
 
	if(sss >= qs && see <= qe)
	return seg[sii].a[0];
 
	int mid = (sss + see) / 2;
	return query(2 * sii , sss , mid , qs , qe) + query(2 * sii + 1 , mid + 1 , see , qs , qe);
}
 
void update(int sii , int sss , int see , int qs , int qe , int val)
{
	if(lazy[sii] != 0)
	{
		int dx = lazy[sii];
		lazy[sii] = 0;
              if(sss != see)
		{
                 lazy[2 * sii] += dx ;
                 lazy[2 * sii + 1] += dx;
              }
              dx %= 3;
		for(int i = 0; i < dx; i++)
              shift(sii);
	}
 
	if(sss > qe || see < qs) return;
 
	if(sss >= qs && see <= qe)
	{
		shift(sii);
		if(sss != see)
		{
			lazy[2 * sii]++;
			lazy[2 * sii + 1]++;
		}
		return;
	}
 
	int mid = (sss + see) / 2;
	update(2 * sii , sss , mid , qs , qe , val);
	update(2 * sii + 1 , mid+1 , see , qs , qe , val);
 
	seg[sii].a[0] = seg[2*sii].a[0] + seg[2*sii+1].a[0];
	seg[sii].a[1] = seg[2*sii].a[1] + seg[2*sii+1].a[1];
	seg[sii].a[2] = seg[2*sii].a[2] + seg[2*sii+1].a[2];
}
 
 
int32_t main()
{
   #ifndef DEBUG
   ios
   #endif
	int n , q , code , l , r , val;
	cin >> n >> q;
	build(1 , 1 , n);
 
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
			cin >> l >> r;
                     l++;
                     r++;
                     val = 1;
			update(1 , 1 , n , l , r , val);
		}
	}
       rr;
}
