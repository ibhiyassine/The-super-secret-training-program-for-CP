//Problem link: https://cses.fi/problemset/task/1619
 
#include <bits/stdc++.h>


using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<pair<unsigned long long, unsigned long long>> timestamps(2*n, {0, 0});
    unsigned long long in, out;
    for(int i = 0; i < 2*n; i+=2){
        cin >> in >> out;
        timestamps[i] = {in, 1};
        timestamps[i + 1] = {out, -1};
    }
    sort(timestamps.begin(), timestamps.end());
    unsigned long long counter = 0, current = 0;
    for(const auto& x : timestamps){
        current = current + x.second;
        counter = max(counter, current);
    }
    cout << counter << endl;

    return 0;
}