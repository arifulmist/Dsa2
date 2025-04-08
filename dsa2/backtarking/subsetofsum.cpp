#include <iostream>
#include <vector>

using namespace std;

void sumOfSubsets(vector<int>& nums, int index, int sum, int target, vector<int>& subset) {
    if (sum == target) {
        for (int num : subset) cout << num << " ";
        cout << "\n";
        return;
    }
    if (index == nums.size() || sum > target) return;
    
    subset.push_back(nums[index]);
    sumOfSubsets(nums, index + 1, sum + nums[index], target, subset);
    subset.pop_back();
    
    sumOfSubsets(nums, index + 1, sum, target, subset);
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << "Enter target sum: ";
    cin >> target;

    vector<int> subset;
    sumOfSubsets(nums, 0, 0, target, subset);
    return 0;
}
