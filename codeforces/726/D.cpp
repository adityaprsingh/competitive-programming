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
    int t=0; cin >> t;

    for (int tt = 1; tt <= t; tt++){
        ll n; cin >> n;
        if (n == 1){
            cout << "Bob" << nl; continue;
        }
        ll base = 2;
        while (base < n) base *= 4;
        if (base > n) base /= 4;

        if (base == n){
            cout << "Bob" << nl;
        }
        else{
            if ((n- base) & 1) cout << "Bob" << nl;
            else cout << "Alice" << nl;
        }
    }
}

