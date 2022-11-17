class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums1 = nums;
        sort(nums1.begin(), nums1.end());
        int a = 0, b = size(nums) - 1;
        while(nums1[a] + nums1[b] != target){
            if(nums1[a] + nums1[b] > target){
                b--;
            }
            else a++;
        }
        int f = 0;
        a = nums1[a];
        b = nums1[b];
        for(int i = 0; i < size(nums) && f != 3; i++) {
            if(nums[i] == a && f != 1){
                a = i;
                f += 1;
                if(f == 2)
                    break;
                continue;
            }
            if(nums[i] == b && f != 2){
                b = i;
                f += 2;
                if(f == 1)
                    break;
            }
        }
        vector<int> ans = {a, b};
        return ans;
    }
};
