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
        int n, m; cin >> n >> m;
        vector<ll> val(n), tar(n);
        vector<vector<int>> adj(n);
        ll diff[2] = {0}, val_sum = 0, tar_sum = 0;
        bool bipartite = true;
        vector<bool> vis(n, false);
        vector<int> col(n, -1);

        for (int i = 0; i < n; i++){
            ll x; cin >> x; val_sum += x;
            val[i] = x;
        }
        for (int i = 0; i < n; i++){
            ll x; cin >> x; tar_sum += x;
            tar[i] = x;
        }
        for (int i = 0; i < m; i++){
            int x, y; cin >> x >> y; x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        if ((val_sum - tar_sum) % 2){
            cout << "NO\n"; continue;
        }

        function<void(int, int)> dfs = [&](int v, int c){
            diff[c] += (tar[v] - val[v]);
            vis[v] = true;
            col[v] = c;
            for (auto u : adj[v]){
                if (vis[u] && c == col[u]){
                    bipartite = false; break;
                }
                if (vis[u]) continue;
                dfs(u, c^1);
            }
        };

        dfs(0, 0);

        if (!bipartite || diff[0] == diff[1]){
            cout << "YES\n"; continue;
        }
        cout << "NO\n"; 
    }
}

