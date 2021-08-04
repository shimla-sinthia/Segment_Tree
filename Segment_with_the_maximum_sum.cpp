//https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A
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
#define f(i, a, n) for( i=a; i<n;i++)
#define ll long long
#define int ll
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
#define deb(x)          cout << #x << " = " << x << endl
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
ll arr[100005];
struct dataa {
    int sum, pref, suff, ans;
}seg[400005];

dataa combine(dataa l, dataa r) {
    dataa res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

dataa make_data(int val) {
    dataa res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0ll, val);
    return res;
}
void build_seg_tree(int sii, int sss, int see)
{
   if(sss == see)
   {
      seg[sii] = make_data(arr[sss]);
      return;
   }
   ll mid = (sss + see) / 2;

   build_seg_tree(2 * sii , sss , mid);
   build_seg_tree(2 * sii + 1 , mid + 1 , see);

   seg[sii] = combine(seg[sii * 2], seg[sii * 2 + 1]);
}
dataa query(ll sii, ll sss, ll see, ll qs, ll qe)
{
   if(qs > see || qe < sss)
   return make_data(0);

   if(sss >= qs && see <= qe)
   return seg[sii];

   ll mid = (sss + see) / 2;

   dataa l = query(2*sii , sss , mid , qs , qe);
   dataa r = query(2*sii+1 , mid+1 , see , qs , qe);
   return combine(l, r);
   //return min(l , r);
}

void update(int sii, int sss, int see, int qi, int new_val) {
    if (sss == see) {
        seg[sii] = make_data(new_val);
        return;
    } 
      int mid = (sss + see) / 2;
      if (qi <= mid)
         update(sii * 2, sss, mid, qi, new_val);
      else
         update(sii * 2 + 1, mid + 1, see, qi, new_val);
   seg[sii] = combine(seg[sii * 2], seg[sii * 2 + 1]);
}

int32_t main()
{
   #ifndef DEBUG
   ios
   #endif
   int t=1;
   //cin>>t;
   int ct=0;
   while(t--)
   {
      ll n, m;
      cin >> n >> m;
      for(int i = 1; i <= n; i++) cin >> arr[i];

      build_seg_tree(1 , 1 , n);
      dataa anss  = query(1, 1, n, 1, n);
      cout << anss.ans << endl;
      while(m--)
      {
         ll l, r;
         cin >> l >> r;
         l++;
         update(1, 1, n, l, r);
         anss  = query(1, 1, n, 1, n);
         cout << anss.ans << endl;
      }
   }
  rr;
}
