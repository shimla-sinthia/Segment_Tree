/* 2 types of query
1. 1 val(substracting val from all the elements from the array)
2. 2 l r K(Find K-th smallest elements from the range l to r (inclusive))
*/

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
#define mod             1000000007
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
#define maxheap                  priority_queue<ll>
#define minheap                  priority_queue<ll, vector<ll>, greater<ll>>
#define maxheap2                 priority_queue<pair<ll,ll>>
#define minheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>
inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
#define ordered_set             tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#ifdef DEBUG
#define ok cerr << __LINE__ <<"is done "<<endl;
#else
#define ok 
#endif
#define ld double
vector<int> seg[400055];
void build(int ci, int st, int end, pair<int, int>* B)
{
	if (st == end) {
		seg[ci].push_back(B[st].second);
		return;
	}

	int mid = (st + end) / 2;
	build(2 * ci + 1, st, mid, B);
	build(2 * ci + 2, mid + 1, end, B);
	merge(seg[2 * ci + 1].begin(), seg[2 * ci + 1].end(), seg[2 * ci + 2].begin(), seg[2 * ci + 2].end(),
		back_inserter(seg[ci]));
}
int query(int ci, int st, int end, int l, int r, int k)
{
	if (st == end)
		return seg[ci][0];
	int p = upper_bound(seg[2 * ci + 1].begin(),
						seg[2 * ci + 1].end(), r)
			- lower_bound(seg[2 * ci + 1].begin(),
						seg[2 * ci + 1].end(), l);

	int mid = (st + end) / 2;
	if (p >= k)
		return query(2 * ci + 1, st, mid, l, r, k);
	else
		return query(2 * ci + 2, mid + 1, end, l, r, k - p);
}
void solve() {
    ll n, q;
    cin >> n >> q;
    vi arr(n);
    f(i, 0, n ) cin >> arr[i];
	pair<int, int> B[n + 1];
	for (int i = 0; i < n; i++) {
		B[i] = {arr[i], i};
	}
	sort(B, B + n);
	build(0, 0, n - 1, B);
  ll sum = 0;
  while(q--)
  {
    ll ty, l, r, k;
    cin >> ty;
    if(ty == 1)
    {
      ll val;
      cin >> val;
      sum += val;
    }
    else
    {
      cin >> l >> r >> k;
       cout << arr[query(0, 0, n - 1, l - 1, r - 1, k)] - sum << endl;
    }
  }
	//cout << "3rd smallest element in range 3 to 7 is: "
		//<< arr[query(0, 0, n - 1, 2, 6, 3)] << "\n";
}
int32_t main()
{
  #ifndef DEBUG
   ios
   #else
   freopen("in", "r", stdin);
    //freopen("output.txt", "w", stdout);
   #endif
   int t=1;
   //cin>>t;
   int ct=0;
   while(t--)
   {
    solve();  
   }
  rr ;
}
