// Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=645

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
vector<pair<ll, ll>> cows;

pair<ll, ll> upd(pair<ll, ll> pre, ll b){
    return {min(pre.first, b), max(pre.second, b)};
}

ll search(){
    ll answer = 0;
    sort(cows.begin(), cows.end());
    vector<pair<ll, ll>> pref(n), suff(n);
    // Updating pref
    pref[0] = {cows[0].second, cows[0].second};
    for(int i = 1; i < n; i++){pref[i] = upd(pref[i - 1], cows[i].second);}
    // Updating suff
    suff[n - 1] = {cows[n - 1].second, cows[n - 1].second};
    for(int i = n - 2; i >= 0; i--){suff[i] = upd(suff[i + 1], cows[i].second);}
    // The big rectangle
    ll Big = (cows[n - 1].first - cows[0].first) * (pref[n - 1].second - pref[n - 1].first);
    for(int i = 0; i < n - 1; i++){
        ll first_rectangle  = (cows[i].first - cows[0].first) * (pref[i].second - pref[i].first);
        ll second_rectange = (cows[n - 1].first - cows[i + 1].first) * (suff[i + 1].second - suff[i + 1].first);
        answer = max(answer, Big - (first_rectangle + second_rectange));
    }
    return answer;


}


int main(){
    cin >> n;
    cows.resize(n);
    for(int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    ll answer = 0;
    answer = max(answer, search());
    for(auto& x: cows){swap(x.first, x.second);}
    answer = max(answer, search());

    cout << answer << endl;

    return 0;
}