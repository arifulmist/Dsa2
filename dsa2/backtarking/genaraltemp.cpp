#include<bits/stdc++.h>


using namespace std;

void backtrack(vector<int>& solution, int n, int level) {
    if (level == n) {
        for (int num : solution) cout << num << " ";
        cout << "\n";
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (find(solution.begin(), solution.end(), i) == solution.end()) {
            solution.push_back(i);
            backtrack(solution, n, level + 1);
            solution.pop_back();
        }
    }
}

int main() {
    int n = 3;
    vector<int> solution;
    backtrack(solution, n, 0);
    return 0;
}
