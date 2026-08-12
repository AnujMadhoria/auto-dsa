class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        multiset<char> bucket;
        for (int i = 0; i < s.size(); i++) {
            bucket.insert(s[i]);
        }

        for (int i = 0; i < t.size(); i++) {
            auto it = bucket.find(t[i]);
            if (it != bucket.end()) {
                bucket.erase(it);
            } else {
                return false;
            }
        }
        return true;
    }
};