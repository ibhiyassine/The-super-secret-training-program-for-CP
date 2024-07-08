// Problem link: http://www.usaco.org/index.php?page=viewproblem2&cpid=919

#include <iostream>
#include <algorithm>

using namespace std;

long long grid[1005][1005];
int min_x = 1001, min_y = 1001, max_x = 0, max_y = 0;
int x1, x2, y1, y2;

int main(){
    long long n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        min_x = min(min_x, x1); min_y = min(min_y, y1); max_x = max(max_x, x2); max_y = max(max_y, y2);
        for(int j = x1; j < x2; j++){
            grid[j][y1]++;
            grid[j][y2]--;
        }
    }
    long long count = 0;

    for(int i = min_x; i < max_x; i++){
        for(int j = min_y; j < max_y; j++){
            if(j == min_y)
                continue;
            else
                grid[i][j] = grid[i][j - 1] + grid[i][j];
        }
    }
    for(int i = min_x; i < max_x; i++){
        for(int j = min_y; j < max_y; j++){
            if(grid[i][j] == k)
                count++;
        }
    }

    cout << count << endl;

    return 0;

}