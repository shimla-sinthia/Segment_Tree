//https://www.hackerrank.com/contests/srbd-code-contest-2022-round-2-retake/challenges/time-pass

//Bismillah Hir Rehmanir Rahim
//Allah knows best
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using    namespace __gnu_pbds;
#define gap ' '
#define mini -10000000000000000
#define endl '\n'
#define f(i, a, n) for(int i=a; i<n;i++)
#define int long long
#define ll long long
#define pi 3.141592653589793
#define vi              vector<int>
#define si              set<int>
#define pb              push_back
#define mp              make_pair
#define mod             1000000007
#define rr              return 0
#define ff              first
#define in              insert
#define ss              second
int hash58 = 288230376151711717;
int hash32 = 1610612741;
#define erase_unique(st)  st.erase(unique(st.begin(), st.end()),st.end())
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
#define setbits(x)      __builtin_popcountll(x)
#define zrbits(x)       __builtin_ctzll(x)
#define unset_bit(x,inx) x = (x & ~(1ll<<(inx)))
#define set_bit(x, idx) x = x|1LL<<idx
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define toggle_bit(x, idx) x = x^(1LL<<idx)
#define maxheap                  priority_queue<int>
#define minheap                  priority_queue<int, vector<int>, greater<int>>
#define maxheap2                 priority_queue<pair<int,int>>
#define minheap2                 priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>
inline int uceil(int a,int b) {return (a % b ? a / b + 1 : a / b);}
#define ordered_set             tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#ifdef DEBUG
#include "tpc.hpp"
#define ios
#define dbg(...) {cerr << __LINE__ << " : " ;cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);}
#define ok tikkk
#else
#define ios {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define dbg(...) 
#define ok
#endif
#define ld long double
const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
/*
-this is 1 based segtree
-have a global vector named arr
*/
ll arr[1000006];
struct jinis
{
    //Use required attributes
    int mn = 0;

    //Default Values
    //jinis() : mn(0) {};
};

struct SegTree
{
    int N;
    vector<jinis> st;
    vector<bool> cLazy;
    vector<int> lazy;

    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
        fill(all(st), jinis{});
        cLazy.assign(4 * N + 5, false);
        lazy.assign(4 * N + 5, 0);
        build(1,1,n);
    }

    //Write reqd merge functions
    void merge(jinis &cur, jinis &l, jinis &r) 
    {
        cur.mn = (l.mn + r.mn);
    }
  
    //Handle lazy propagation appriopriately
    void propagate(int node, int L, int R)
    {
        if(L != R)
        {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node]; 
        }
        st[node].mn += (R - L + 1) * lazy[node];
        cLazy[node] = 0;
    }

    void build(int node, int L, int R)
    {
        if(L==R)
        {
            st[node].mn = arr[L];
            return;
        }
        int M=(L + R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        merge(st[node], st[node*2], st[node*2+1]);
    }

    jinis Query(int node, int L, int R, int i, int j)
    {
        if(cLazy[node])
        propagate(node, L, R);
        if(j<L || i>R)
            return jinis();
        if(i<=L && R<=j)
            return st[node];
        int M = (L + R)/2;
        jinis left=Query(node*2, L, M, i, j);
        jinis right=Query(node*2 + 1, M + 1, R, i, j);
        jinis cur;
        merge(cur, left, right);
        return cur;
    }

    jinis pQuery(int node, int L, int R, int pos)
    {
        if(cLazy[node])
        propagate(node, L, R);
        if(L == R)
            return st[node];
        int M = (L + R)/2;
        if(pos <= M)
            return pQuery(node*2, L, M, pos);
        else
            return pQuery(node*2 + 1, M + 1, R, pos);
    }  

    void Update(int node, int L, int R, int i, int j, int val)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(j<L || i>R)
            return;
        if(i<=L && R<=j)
        {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, val);
        Update(node*2 + 1, M + 1, R, i, j, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    void pUpdate(int node, int L, int R, int pos, int val)
    {
        if(cLazy[node])
        propagate(node, L, R);
        if(L == R)
        {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        if(pos <= M)
            pUpdate(node*2, L, M, pos, val);
        else
            pUpdate(node*2 + 1, M + 1, R, pos, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    jinis query(int pos)
    {
        return pQuery(1, 1, N, pos);
    }

    jinis query(int l, int r)
    {
        return Query(1, 1, N, l, r);
    }

    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }

    void update(int l, int r, int val)
    {
        Update(1, 1, N, l, r, val);
    }
};
void solve(int ct) {

    SegTree s1, s2;
    s1.init(1e6);
    s2.init(1e6);
    
    while(1)
    {
    ll ty;
    cin >> ty;
    if(ty == -1)
    return;
   
    if(ty == 1)
    {
        ll num;
        cin >> num;
        arr[num]++;
        s1.update(num, num, 1);
        s2.update(num, num, num);
    }
    else if(ty == 2)
    {
        ll num;
        cin >> num;
        if(arr[num])
        {
            arr[num]--;
            s1.update(num, num, -1);
            s2.update(num, num, -num); 
            cout << num << endl;  
        }
        else cout << -1 << endl;
    }
    else
    {
        ll num;
        cin >> num;
        ll l = 0, h = 1e6 + 2, mid, ans = -1, res = 0;
        while(l <= h)
        {
            mid = (l + h) / 2;
            jinis summ = s1.query(1, mid);
            if(summ.mn <= num)
            {
                ans = mid;
                l = mid + 1;
                res = summ.mn;
            }
            else h = mid - 1;
        }
        jinis ase = s2.query(1, ans);
        if(res < num)
        {
            l = 0; h = 1e6 + 2; ans = -1; ll res2 = 0;
            while(l <= h)
            {
                mid = (l + h) / 2;
                jinis summ = s1.query(1, mid);
                if(summ.mn > num)
                {
                ans = mid;
                h = mid - 1;
                res2 = num - res;
                }
                else l = mid + 1;
            }
            ase.mn += (ans * res2);
        }
        cout << ase.mn << endl;
    }
    }
}
int32_t main()
{
    ios
    int t=1;
    //cin>>t;
    
    for(int ct = 1; ct <= t; ct++){
        solve(ct);
    }
    rr;
}
