#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cj(t) cout << "Case #" << t << ": "
#define nl "\n"

const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

ll powmod(ll x, ll y, ll md = mod){
    ll ret = 1;
    while (y > 0){
        if (y&1) ret = (ret*x) % md;
        x = (x*x) % md; y /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n; cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++){
            cin >> h[i];
        }
        sort(h.begin(), h.end());
        int min_diff = inf, start, end;

        for (int i = 1; i < n; i++){
            int diff = h[i] - h[i-1];
            if (diff < min_diff){
                start = i-1; end = i;
                min_diff = diff;
            }
        }

        vector<int> ans(n); ans[0] = h[start]; ans[n-1] = h[end];
        int nxt = 1;
        for (int i = end+1; i < n; i++){
            ans[nxt++] = h[i];
        }
        for (int i = 0; i < start; i++){
            ans[nxt++] = h[i];
        }

        for (auto x : ans) cout << x << " ";
        cout << nl;
    }
}

