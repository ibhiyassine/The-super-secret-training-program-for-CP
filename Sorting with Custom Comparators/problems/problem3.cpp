// Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=967

#include <bits/stdc++.h>

using namespace std;

struct Cow{
    int weight;
    int pos; 
    int speed;
};

int main(){
    int cow_num, barn_pos;
    cin >> cow_num >> barn_pos;

    vector<Cow> cows(cow_num);
    int Total_weight = 0;
    for(Cow& cow: cows){
        cin >> cow.weight >> cow.pos >> cow.speed;
        Total_weight += cow.weight;
    }

    sort(cows.begin(), cows.end(), [](Cow& c1, Cow& c2){return c1.pos < c2.pos;});

    vector<Cow> left, right;
    for(const Cow& c: cows){
        if(c.speed == -1){
            left.push_back(c);
        }
        else{
            right.push_back(c);
        }
    }

    vector<pair<int, int>> weight_time;
    for(int c = 0; c < left.size(); c++){
        weight_time.push_back({left[c].pos, cows[c].weight});
    }
    for(int c = 0; c < right.size(); c++){
        weight_time.push_back({barn_pos - right[c].pos, cows[left.size() + c].weight});
    }
    
    sort(weight_time.begin(), weight_time.end(), [](const auto& a, const auto& b){return a.first < b.first;});

    int endTime;
    for(const auto& x: weight_time){
        Total_weight -= 2 * x.second;
        if(Total_weight <= 0){
            endTime = x.first;
            break;
        }
    }

    int meeting = 0;
    queue<int> leftSide;
    for(int c = 0; c < cow_num; c++){
        if (cows[c].speed == 1){
            leftSide.push(cows[c].pos);
        } else{
            while(!leftSide.empty() && leftSide.front() + 2*endTime < cows[c].pos){
                leftSide.pop();
            }
            meeting += leftSide.size();
        }
    }
    cout << meeting;

    return 0;
}