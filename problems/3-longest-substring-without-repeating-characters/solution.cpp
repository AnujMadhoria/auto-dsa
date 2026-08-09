class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0;
        int maxLen=0;
        unordered_set<char> window;

        while(right<s.length()){
            if(window.find(s[right])==window.end()){
                window.insert(s[right]);
                int currLen= right-left+1;
                maxLen=max(maxLen,currLen);
                right++;
            }else{
                window.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};