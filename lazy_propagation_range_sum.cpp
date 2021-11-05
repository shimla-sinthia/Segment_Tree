void build(ll node, ll start, ll end) {
        if(start == end) {
                seg[node] = a[start];
                return;
        }

        ll mid = (start + end) >> 1;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);

        seg[node] = (seg[2 * node + 1] + seg[2 * node + 2]);
}

void rangeUpdate(ll node, ll start, ll end, ll l, ll r, ll val) {
        if(lazy[node] != 0) {
                seg[node] += (end - start + 1) * lazy[node];
                if(start != end) {
                        lazy[2 * node + 1] += lazy[node];
                        lazy[2 * node + 2] += lazy[node];
                }
                lazy[node] = 0;
        }

        if(start > end || start > r || end < l) return;

        if(start >= l && end <= r) {
                seg[node] += (end - start + 1) * val;
                if(start != end) {
                        lazy[2 * node + 1] += val;
                        lazy[2 * node + 2] += val;
                }
                return;
        }

        ll mid = (start + end) >> 1;
        rangeUpdate(2 * node + 1, start, mid, l, r, val);
        rangeUpdate(2 * node + 2, mid + 1, end, l, r, val);
        seg[node] = (seg[2 * node + 1] + seg[2 * node + 2]);
}

ll lazySum(ll node, ll start, ll end, ll l, ll r) {
        if(start > end || start > r || end < l) return 0;

        if(lazy[node] != 0) {
                seg[node] += (end - start + 1) * lazy[node];
                if(start != end) {
                        lazy[2 * node + 1] += lazy[node];
                        lazy[2 * node + 2] += lazy[node];
                }
                lazy[node] = 0;
        }

        if(start >= l && end <= r) return seg[node];

        ll mid = (start + end) >> 1;
        ll left = lazySum(2 * node + 1, start, mid, l, r);
        ll right = lazySum(2 * node + 2, mid + 1, end, l, r);
        return (left + right);
}
