// Problem link https://cses.fi/problemset/task/1643

#include <iostream>
#include <cmath>

int main(){
    int n;
    std::cin >> n;
    long long pre[n];
    std::cin >> pre[0];
    for(int i = 1; i < n ; i++){
        std::cin >> pre[i];
        pre[i] += pre[i - 1];
    }
    long long min = 0;
    long long max = pre[0];
    for(int i = 0; i < n; i++){
        max = fmax(max, pre[i] - min);
        min = fmin(min, pre[i]);
    }
    std::cout << max;

    return 0;
}