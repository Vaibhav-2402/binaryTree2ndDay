#include <iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>>& ans, int index, vector<int>& nums){
    //base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }
    // recursive call
    for(int i = index; i<nums.size(); i++){
        swap(nums[index], nums[i]);
        solve(ans, index+1, nums);
        //backtrack
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute (vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(ans, index, nums);
    return ans;
}

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    
    vector<vector<int>> solution = permute(nums);
      for (int i = 0; i < solution.size(); i++) {
        for (int j = 0; j < solution[i].size(); j++)
            cout << solution[i][j] << " ";
        cout << endl;
    }

    return 0;
}