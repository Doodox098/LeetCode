class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        int* check = (int*)calloc(sizeof(int), 1000003);
        int n = nums.size();
        for(int i = 0; i < n; i++){
            check[nums[i] + 1] += 1;
            check[nums[i] + 2] += 1;
            check[nums[i]] += 1;
        }
        for(int i = 0; i < n; i++){
            if(check[nums[i] + 1] < 2)ans.push_back(nums[i]);
        }
        return ans;
    }
};
