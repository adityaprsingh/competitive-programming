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

ll sx, sy;

ll shortest_path(ll x1, ll y1, ll x2, ll y2){
    ll ans = abs(x1 - x2) + abs(y1 - y2);
    ans += abs(sx - x1) + abs(sy - y1);
    ans += abs(sx - x2) + abs(sy - y2);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        ll n, m; cin >> n >> m >> sx >> sy;
        ll cx1 = 1, cy1 = 1, cx2 = n, cy2 = m;
        ll cx3 = 1, cy3 = m, cx4 = n, cy4 = 1;

        ll path1 = shortest_path(cx1, cy1, cx2, cy2);
        ll path2 = shortest_path(cx3, cy3, cx4, cy4);
        if (path1 < path2){
            cout << cx3 << " " << cy3 << " " << cx4 << " " << cy4 << nl;
        }
        else{
            cout << cx1 << " " << cy1 << " " << cx2 << " " << cy2 << nl;
        }
    }
}

