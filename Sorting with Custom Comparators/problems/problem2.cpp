// Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=645

#include <bits/stdc++.h>

using namespace std;
int n;
unsigned long long Big_Square;
unsigned long long Better_Square;

unsigned long long Areas(vector<vector<long long>> &positions_x, vector<vector<long long>> &positions_y){
    unsigned long long A1, A2, result = Big_Square;
    for(int i = 1; i < n; i++){
        // Calculating A1
        long long min_x = positions_x[0][0], max_x = positions_x[i - 1][0], min_y = positions_y[0][1], max_y = positions_y[i - 1][1];
        A1 = (max_y - min_y) * (max_x - min_x);
        // Calculating A2
        min_x = positions_x[i][0], max_x = positions_x[n - 1][0], min_y = positions_y[i][1], max_y = positions_y[n - 1][1];
        A2 = (max_y - min_y) * (max_x - min_x);
        // Calculating result
        result = min(result, (A1 + A2));
    }
    return result;


}


int main(){
    cin >> n;
    vector<vector<long long>> positions_x(n, vector<long long>(2, 0));
    vector<vector<long long>> positions_y(n, vector<long long>(2, 0));
    for(int i = 0; i < n; i++){
        cin >> positions_x[i][0] >> positions_x[i][1];
        positions_y[i][0] = positions_x[i][0]; positions_y[i][1] = positions_x[i][1];
    }
    sort(positions_x.begin(), positions_x.end());
    sort(positions_y.begin(), positions_y.end(), [](vector<long long> a, vector<long long> b){return a[1] < b[1];});
    long long min_x = positions_x[0][0], max_x = positions_x[n - 1][0], min_y = positions_y[0][1], max_y = positions_y[n - 1][1];
    Big_Square = (max_y - min_y) * (max_x - min_x);
    Better_Square = Areas(positions_x, positions_y);
    
    cout << Big_Square - Better_Square << endl;

    return 0;
}