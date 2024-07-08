// Problem link http://www.usaco.org/index.php?page=viewproblem2&cpid=1063

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<long, long>> cows(n, {0, 0});
    for(int i = 0; i < n; i++)
        cin >> cows[i].first >> cows[i].second;
    sort(cows.begin(), cows.end());
    //
    vector<vector<long long>> above(n, vector<long long>(n, 0));
    vector<vector<long long>> below(n, vector<long long>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            above[i][j] = ((j > 0)? above[i][j - 1]: 0);
            below[i][j] = ((j > 0)? below[i][j - 1]: 0);
            if(cows[i].second <= cows[j].second)
                above[i][j]++;
            if(cows[i].second >= cows[j].second)
                below[i][j]++;
        }
    }

    long long tot = 1;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(cows[i].second >= cows[j].second)
                tot += ((i > 0) ? (below[j][j] - below[j][i - 1]) * (above[i][j] - above[i][i - 1]): below[j][j] * above[i][j]);
            else
                tot += ((i > 0) ? (above[j][j] - above[j][i - 1]) * (below[i][j] - below[i][i - 1]): above[j][j] * below[i][j]);;
        }
    }

    cout << tot << endl;

    return 0;
}