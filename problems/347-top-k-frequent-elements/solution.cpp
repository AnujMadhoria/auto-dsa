class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>counter;
        for(int n: nums){
            counter[n]++;
        }
        vector<vector<int>>ref(nums.size()+1);
        for(auto entry: counter){
            ref[entry.second].push_back(entry.first);
        }
        vector<int>ans;
        for(int i=ref.size()-1; i>0;i--){
            for(int num: ref[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return {};
    }
};