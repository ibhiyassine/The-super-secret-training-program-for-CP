// Problem link: http://www.usaco.org/index.php?page=viewproblem2&cpid=104

#include <iostream>
#include <algorithm>

int main(){
    int N, K;
    int l, r;
    std::cin >> N >> K;
    long long stacks[N] = {0};
    long long dif[N + 1] = {0};
    for(int i = 0; i < K; i++){
        std::cin >> l >> r;
        dif[l - 1]++;
        dif[r]--;
    }
    for(int i = 0; i < N; i++){
        if (i == 0){
            stacks[i] = dif[i];
        }
        else
            stacks[i] = stacks[i - 1] + dif[i];
    }
    std::sort(stacks, stacks + (sizeof(stacks)/sizeof(long long)));
    std::cout << stacks[N/2];

}