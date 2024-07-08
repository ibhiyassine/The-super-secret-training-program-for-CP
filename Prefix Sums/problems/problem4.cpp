// Problem link https://cses.fi/problemset/task/1652

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main() {
    int n, q;
    string line;
    std::cin >> n >> q;
    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> presum(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        std::cin >> line;
        for (int j = 0; j < n; j++) {
            forest[i + 1][j + 1] = line[j] == '*';
            presum[i + 1][j + 1] = presum[i + 1][j] + presum[i][j + 1] - presum[i][j] + forest[i + 1][j + 1];
        }
    }

    for (int j = 0; j < q; j++) {
        int y1, x1, y2, x2;
        std::cin >> y1 >> x1 >> y2 >> x2;
        std::cout << presum[y2][x2] - presum[y1 - 1][x2] - presum[y2][x1 - 1] + presum[y1 - 1][x1 - 1] << std::endl;
    }

    return 0;
}