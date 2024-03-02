//atc problem : https://atcoder.jp/contests/abc343/tasks/abc343_f
// Bismillah Hir Rehmanir Rahim
// Allah knows best
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define gap ' '
#define mini -10000000000000000
#define endl '\n'
#define f(i, a, n) for (int i = a; i < n; i++)
#define int long long
#define ll long long
#define pi 3.141592653589793
#define vi vector<int>
#define si set<int>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rr return 0
#define ff first
#define in insert
#define ss second
int hash58 = 288230376151711717;
int hash32 = 1610612741;
#define erase_unique(st) st.erase(unique(st.begin(), st.end()), st.end())
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
#define setbits(x) __builtin_popcountll(x)
#define zrbits(x) __builtin_ctzll(x)
#define unset_bit(x, inx) x = (x & ~(1ll << (inx)))
#define set_bit(x, idx) x = x | 1LL << idx
#define check_bit(x, idx) min(x & (1LL << idx), 1LL)
#define toggle_bit(x, idx) x = x ^ (1LL << idx)
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int>>
#define maxheap2 priority_queue<pair<int, int>>
#define minheap2                                           \
    priority_queue<pair<int, int>, vector<pair<int, int>>, \
                   greater<pair<int, int>>>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x, y) uniform_int_distribution<int>(x, y)(rng)
inline int uceil(int a, int b) { return (a % b ? a / b + 1 : a / b); }
#define ordered_set                              \
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistics_node_update>
#ifdef DEBUG
#include "tpc.hpp"
#define ios
#define dbg(...)                                                   \
    {                                                              \
        cerr << __LINE__ << " : ";                                 \
        cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__); \
    }
#define ok tikkk
#else
#define ios                               \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
#define dbg(...)
#define ok
#endif
#define ld long double
#pragma GCC target("popcnt")
const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

vector<pair<int, int>> segTree;
pair<int, int> combine(pair<int, int> p1, pair<int, int> p2) {
    set<int> s;
    s.insert(p1.first);
    s.insert(p1.second);
    s.insert(p2.first);
    s.insert(p2.second);
    int m = *(s.rbegin());
    s.erase(--s.end());
    int sm = m;
    if (s.size()) sm = *(s.rbegin());
    return {m, sm};
}
void build(vector<int>& arr, int start, int end, int index) {
    if (start == end) {
        segTree[index] = {arr[start], arr[start]};
        return;
    }
    int mid = (start + end) / 2;
    int leftNode = 2 * index;
    int rightNode = 2 * index + 1;
    build(arr, start, mid, leftNode);
    build(arr, mid + 1, end, rightNode);
    segTree[index] = combine(segTree[leftNode], segTree[rightNode]);
}

void update(vector<int>& arr, int start, int end, int index, int pos,
            int value) {
    if (start == end) {
        arr[pos] = value;
        segTree[index] = {arr[pos], arr[pos]};
        return;
    }
    int mid = (start + end) / 2;
    int leftNode = 2 * index;
    int rightNode = 2 * index + 1;
    if (pos <= mid)
        update(arr, start, mid, leftNode, pos, value);
    else
        update(arr, mid + 1, end, rightNode, pos, value);
    segTree[index] = combine(segTree[leftNode], segTree[rightNode]);
}
pair<int, int> query(int start, int end, int index, int l, int r) {
    if (l <= start && end <= r) {
        return segTree[index];
    }
    if (l > end || r < start) {
        return {-1, -1};
    }
    int mid = (start + end) / 2;
    int leftNode = 2 * index;
    int rightNode = 2 * index + 1;
    pair<int, int> leftAnswer = query(start, mid, leftNode, l, r);
    pair<int, int> rightAnswer = query(mid + 1, end, rightNode, l, r);
    return combine(leftAnswer, rightAnswer);
}

void solve(int ct) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, ordered_set> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]].insert(i);
    }
    segTree.resize(4 * n + 1);
    build(a, 0, n - 1, 1);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p;
            cin >> p;
            --p;
            int x;
            cin >> x;
            m[a[p]].erase(p);
            m[x].insert(p);
            a[p] = x;
            update(a, 0, n - 1, 1, p, x);
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int key = a[l];
            int right = m[key].order_of_key(r + 1);
            int left = m[key].order_of_key(l);
            if ((right - left) == (r - l + 1))
                cout << 0 << '\n';
            else {
                pair<int, int> p = query(0, n - 1, 1, l, r);
                int key2 = p.second;
                int right2 = m[key2].order_of_key(r + 1);
                int left2 = m[key2].order_of_key(l);
                cout << right2 - left2 << '\n';
            }
        }
    }
}
int32_t main() {
    ios int t = 1;
    // cin>>t;
    for (int ct = 1; ct <= t; ct++) {
        solve(ct);
    }
    rr;
}
