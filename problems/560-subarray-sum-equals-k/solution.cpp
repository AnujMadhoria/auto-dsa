class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size(), 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (prefixSum[i] == k) {
                ans++;
            }
            if (mp.find(prefixSum[i] - k) != mp.end()) {
                ans += mp[prefixSum[i] - k];
            }
            if (mp.find(prefixSum[i]) == mp.end()) {
                mp[prefixSum[i]] = 0;
            }
            mp[prefixSum[i]]++;
        }
        return ans;
    }
};
