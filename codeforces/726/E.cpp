#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string pref;
    int pid = 0;
    pref += s[0];

    for (int i = 1; i < n; i++){
        if (s[i] > s[pid]) break;
        pref += s[i];
        if (s[i] == s[pid]) pid++;
        else pid = 0;
    }

    while (pid > 0) pref.pop_back(), pid--;
    for (int i = 0; i < k; i++) cout << pref[i % pref.size()];
}


