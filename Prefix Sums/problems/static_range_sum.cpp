// Problem link: https://judge.yosupo.jp/problem/static_range_sum

#include <iostream>

int main(){
    int N, Q;
    std::cin >> N >> Q;
    long long a[N];
    long long pre[N];
    for(int i = 0; i < N; i++){
        std::cin >> a[i];
        if(i == 0)
            pre[0] = a[0];
        else
            pre[i] = pre[i - 1] + a[i];
    }
    for(int i = 0; i < Q; i++){
        int l, r;
        std::cin >> l >> r;
        if(l == 0)
            std::cout << pre[r - 1] << std::endl;
        else 
            std::cout << pre[r - 1] - pre[l - 1] << std::endl;

    }



    return 0;
}