class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        map<char, int> map;

        int count = t.length();
        int start = 0;
        int end = 0;
        int minLen = INT_MAX;
        int startIndex = 0;

        for (char c : t) {
            map[c]++;
        }

        while (end < s.length()) {
            if (map[s[end++]]-- > 0) {
                count--;
            }
            while (count == 0) {  // we get the valid window which contain all the t chars 

                if (end - start < minLen) { //storing the memory of current smallest we know 
                    minLen = end - start;
                    startIndex = start;
                }

                // Character we're removing
                char removedChar = s[start];

                // Check BEFORE increasing the map
                if (map[removedChar] == 0) {
                    count++;
                }

                // Put the character back into the requirement
                map[removedChar]++;

                // Move left
                start++;
            }
        }

        return  minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};