//https://codeforces.com/problemset/problem/961/E
#include<bits/stdc++.h>
using namespace std;
#define lll __int128_t
#define ll long long
#define int long long
#define FOR(i,a,b) for(ll i=a;i<(ll)b;i++)
#define FORr(i,a,b) for(ll i =a;i>=(ll)b;i--)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,n)
#define print(arr)  for(auto a: arr) cout << a<< " "; cout << endl;
#define case(i) cout << "Case " << i << ": ";
#define in(a) ll a; cin >> a;
#define inp(arr,n) vector<ll>arr(n); for(auto &a: arr) cin >> a;
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define f first
#define vll vector<ll>
#define s second
ll mod = 1e9 + 7;
#define pll pair<ll, ll>
#define set_bit(x, idx) x = x|(1LL<<idx)
ll dx[8] = {0,1,0,-1,1,-1,1,-1};
ll dy[8] = {-1,0,1,0,1,1,-1,-1};
#define toggle_bit(x, idx) x = x^(1LL<<idx)
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define endl "\n"
template<typename T> ostream& operator<<(ostream &os, const multiset<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const set<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define db long double
ll hash58 = 288230376151711717;
ll hash32 = 1610612741;
#ifdef DEBUG
#define ios
#define dbg(...) cerr << __LINE__ << " : " ;cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#define ok cerr << __LINE__ << " is done " << endl;
#else
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(...)
#define ok
#endif
const ll N = 2e5+10;
ll seg[4*N];
ll arr[N];

ll query(ll sii, ll sss, ll see, ll qs, ll qe)
{
   if(qs > see || qe < sss)
   return 0;
   if(sss >= qs && see <= qe)
   return seg[sii];
   ll mid = (sss + see) / 2;
   ll l = query(2*sii , sss , mid , qs , qe);
   ll r = query(2*sii+1 , mid+1 , see , qs , qe);
   return l+r;
}

void update(ll sii, ll sss, ll see, ll qi)
{
   if(sss==see)
   {
      seg[sii]=arr[sss];
      return ;
   }
   ll mid=(sss+see)/2;
   if(qi<=mid)
   {
      update(2*sii, sss, mid, qi);
   }
   else
   {
      update(2*sii+1, mid+1, see, qi);
   }
   seg[sii]= seg[sii*2]+ seg[sii*2+1];
}

vector<ll>st[200005], en[200005];


void solvetc(ll tt){
    in(n) inp(arr1, n)
    //BIT ashiq;
    for(int i = 1; i <= n; i++){
        ll age = arr1[i-1];
        arr1[i-1] -= i;
        arr1[i-1] = max(arr1[i-1], 0LL);
        ll end = arr1[i-1] + i+1;
        end = min(end, n+1);
        if(i+1 != end){
            st[i+1].pb(i);
            en[end].pb(i);
        }
        arr1[i-1] = age;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(auto a: st[i]){
           
            arr[a]++;
            update(1, 1, n, a);
        }
        for(auto a: en[i]){
   
            arr[a]--;
            update(1,1,n, a);
        }
        
        ans += query(1,1,n, 1, min(arr1[i-1], n));
    }
    cout << ans << endl;
}

int32_t main()
{
    ios ;
    //freopen("in", "r", stdin);
    ll nn = 1;
    //cin >> nn;
    rep(i, nn) solvetc(i+1);
}
