class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>map;

        for(int n: nums){
            map[n]++;
            if(map[n]>=2){
                return true;
            }
        }
        return false ;
    }
};