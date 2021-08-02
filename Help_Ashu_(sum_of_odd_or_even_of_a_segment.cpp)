//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1///Bismillah Hir Rehmanir Rahim




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
#define int long long 

ll arr[100005];
pair<ll,ll>seg[400005];
//ll seg[400050];
void build_seg_tree(ll sii, ll sss, ll see)
{
   if(sss == see)
   {
      if(arr[see] % 2 == 0)
      seg[sii] = mp(0, 1); 
      else
      seg[sii] = mp(1, 0); 
      //arr[see];
      return;
   }
   ll mid = (sss + see) / 2;
   build_seg_tree(2*sii , sss , mid);
   build_seg_tree(2*sii+1 , mid+1 , see);
   seg[sii].ff = seg[2 * sii].ff + seg[2 * sii + 1].ff;
   seg[sii].ss = seg[2 * sii].ss + seg[2 * sii + 1].ss;
}
void update(ll sii, ll sss, ll see, ll qi)
{
  if(sss == see)
   {
      if(arr[see] % 2 == 1)
      seg[sii] = mp(0, 1); 
      else
      seg[sii] = mp(1, 0); 
      //arr[sss] = val;
      //arr[see];
      return;
   }
   ll mid = (sss + see) / 2;
   if(qi <= mid)
   update(2*sii , sss , mid, qi);
   else
   update(2*sii+1 , mid+1 , see, qi);

   seg[sii].ff = seg[2 * sii].ff + seg[2 * sii + 1].ff;
   seg[sii].ss = seg[2 * sii].ss + seg[2 * sii + 1].ss;
}
ll oddCount(ll sii, ll sss, ll see, ll qs, ll qe)
{
   if(qs > see || qe < sss)
   return 0;
   if(sss >= qs && see <= qe)
   return seg[sii].ff;
   ll mid = (sss + see) / 2;
   ll l = oddCount(2*sii , sss , mid , qs , qe);
   ll r = oddCount(2*sii+1 , mid+1 , see , qs , qe);
   return l + r;
   //return min(l , r);
}
ll evenCount(ll sii, ll sss, ll see, ll qs, ll qe)
{
   if(qs > see || qe < sss)
   return 0;
   if(sss >= qs && see <= qe)
   return seg[sii].ss;
   ll mid = (sss + see) / 2;
   ll l = evenCount(2*sii , sss , mid , qs , qe);
   ll r = evenCount(2*sii+1 , mid+1 , see , qs , qe);
   return l + r;
   //return min(l , r);
}
int32_t main()
{
   #ifndef DEBUG
   ios
   #endif
   int t=1;
   //cin >> t;
   int ct=0;
   while(t--)
   {
      ll n;
      cin >> n;
      for(int i = 1; i <= n; i++)
      cin >> arr[i];
      build_seg_tree(1, 1, n);
      ll q;
      cin >> q;

      while(q--)
      {
         ll type;
         cin >> type;
         if(type == 0)
         {
            ll idx, val;
            cin >> idx >> val;
            
            if(arr[idx] % 2 == val % 2)
            continue;
            else
            {
               //arr[idx] = val;
               update(1, 1, n, idx);
               arr[idx] = val;
            }
         }
         else if(type == 1)
         {
            ll l, r;
            cin >> l >> r;
            ll ans = evenCount(1, 1, n, l, r);
            cout << ans << endl;
         } 
         else
         {
            ll l, r;
            cin >> l >> r; 
            ll ans = oddCount(1, 1, n, l, r);
            cout << ans << endl;
         }
      }
   }
   rr;
}
