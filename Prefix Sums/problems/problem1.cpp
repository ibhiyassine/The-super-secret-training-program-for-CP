// Problem link: http://www.usaco.org/index.php?page=viewproblem2&cpid=595

#include <iostream>
#include <cmath>
#include <map>

int main(){
    long long N;
    std::cin >> N;
    long long cows[N];
    long long pre[N];
    for(int i = 0; i < N; i++){
        std::cin >> cows[i];
        if(i == 0)
            pre[0] = cows[0];
        else
            pre[i] = pre[i - 1] + cows[i];
    }
    std::map <int, int> remainders;
    int len = 0;
    for(int i = 0; i < N; i++){
        int remainder = pre[i] % 7;
        if(remainder == 0)
            len = fmax(len, i);
        else if (remainders.find(remainder) == remainders.end()){
            remainders.insert({remainder, i});
        }
        else
            len = fmax(len, i - remainders[remainder]);
    }
    std::cout << len << std::endl;

    return 0;
}