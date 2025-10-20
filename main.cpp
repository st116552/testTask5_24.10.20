#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<vector<int>> readTriangle() {
    vector<vector<int>> triangle;
    string str;
    int num;
    
    while (getline(cin, str)) {
        if (str.empty()) break;
        stringstream inp(str);
        vector<int> level;
        while (inp >> num) {
            level.push_back(num);
        }
        triangle.push_back(level);
    }
    
    return triangle;
}


int countMinPathSum(vector<vector<int>>& triangle) {
    vector<vector<int>> minPathSum;
    vector<vector<char>> prev;
    int n = triangle.size();
    
    for (int i = 0; i < n; i++) {
        prev.push_back(vector<char>(i + 1));
        minPathSum.push_back(triangle[i]);
    }
    
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < i + 1; j++) {
            if (minPathSum[i + 1][j] <= minPathSum[i + 1][j + 1]) {
                minPathSum[i][j] = minPathSum[i][j] + minPathSum[i + 1][j];
                prev[i][j] = 'l';
            } else {
                minPathSum[i][j] = minPathSum[i][j] + minPathSum[i + 1][j + 1];
                prev[i][j] = 'r';
            }
        }
    }
    
    cout << "path: ";
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cout << triangle[i][tmp] << " ";
        if (prev[i][tmp] != 'l') tmp = tmp + 1;
    }
    cout << endl;
    
    return minPathSum[0][0];
}

int main() {
    vector<vector<int>> triangle = readTriangle();
    cout << countMinPathSum(triangle) << endl;
    return 0;
}
