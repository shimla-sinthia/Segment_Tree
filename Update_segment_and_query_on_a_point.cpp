/*
Given an array. Apply 2 types of query. 
In type 1, update the range l to r with value, given l, r, value. 
In type2, output the value of the index l. 
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
ll seg[400050];
void build_seg_tree(ll sii, ll sss, ll see)
{
   if(sss == see)
   {
      seg[sii] = arr[see];
      return;
   }
   ll mid = (sss + see) / 2;
   build_seg_tree(2 * sii , sss , mid);
   build_seg_tree(2 * sii + 1 , mid + 1 , see);
   seg[sii] = (seg[2 * sii] + seg[2 * sii + 1]);
}
ll query(ll sii, ll sss, ll see, ll qs, ll qe)
{
   if(qs > see || qe < sss)
   return 0;
   if(sss >= qs && see <= qe)
   return seg[sii];
   ll mid = (sss + see) / 2;
   ll l = query(2 * sii , sss , mid , qs , qe);
   ll r = query(2 * sii + 1 , mid + 1 , see , qs , qe);
   return (l + r);
}
void update(ll sii, ll sss, ll see, ll qi, ll val)
{
   if(sss==see)
   {
      seg[sii] += val;
      return ;
   }
   ll mid = (sss + see) / 2;
   if(qi <= mid)
   {
     update(2 * sii, sss, mid, qi, val);
   }
   else
   {
      update(2*sii+1, mid+1, see, qi, val);
   }
   seg[sii] = (seg[sii*2] + seg[sii * 2 + 1]);
}
int main()
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
      cin >> n;
      for(int i = 1; i <= n; i++) cin >> arr[i];

      //build_seg_tree(1 , 1 , n);
      cin >> m;
      while(m--)
      {
         ll d;
         cin >> d;
         //l++;
         if(d == 1)
         {
            ll l, r , v;
            cin >> l >> r >> v;
            arr[l] += v;
          
            update(1, 1, n, l, v);
            arr[r + 1] -= v;
            update(1, 1, n, r + 1, -v);
         }
         else
         {
            ll ind;
            cin >> ind;
            ll ans  = query(1, 1, n, 1, ind);
            cout << arr[ind] + ans << endl;
         }
      }
   }
  rr;
}
