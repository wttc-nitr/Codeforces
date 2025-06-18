/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vb vector<bool>
#define vi vector<int>
#define vc vector<char>
#define INF (1LL << 60)
#define inf (1 << 30)

// concepts: difference array n prefix sum

void solve(void) {
    int N, M, K; cin >> N >> M >> K;
    vector<ll> arr(N);

    for (auto &x : arr)
    	cin >> x;

    struct Operation {
    	int l, r, d;
    	Operation () : l(0), r(0), d(0) {}
    };

    vector<Operation> ops(M + 1);

    for (int i = 1; i <= M; i++) 
    	cin >> ops[i].l >> ops[i].r >> ops[i].d;
    
    vector<int> cnt_of_each_opr (M + 2);

    while (K-- > 0) {
    	int x, y; cin >> x >> y;
    	cnt_of_each_opr[x] += 1;
    	cnt_of_each_opr[y + 1] -= 1;
    }

    for (int i = 1; i < (int)cnt_of_each_opr.size(); i++)
    	cnt_of_each_opr[i] += cnt_of_each_opr[i-1];

    vector<ll> diff (N + 2); diff[1] = arr[0];

    for (int i = 1; i < (int)arr.size(); i++)
    	diff[i + 1] = arr[i] - arr[i-1];

    for (int i = 1; i <= M; i++) {
    	int cnt_op = cnt_of_each_opr[i];
    	int l = ops[i].l, r = ops[i].r;
    	ll total_delta = 1LL * ops[i].d * cnt_op;

    	diff[l] += total_delta;
    	diff[r + 1] -= total_delta;
    }

    for (int i = 1; i < (int)diff.size(); i++) {
    	diff[i] += diff[i-1];

    	if (i >= 1 && i <= N)
    		cout << diff[i] << ' ';
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int test_cases = 1; 
    while (test_cases-- > 0) {
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}	