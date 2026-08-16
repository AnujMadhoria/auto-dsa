# Top K Frequent Elements

## Problem Description

Given an array of integers, find and return the $k$ most frequently occurring numbers. The final output can be returned in any order, and the problem guarantees that the top $k$ frequent elements are unique. The goal is to achieve a solution faster than the standard $O(n \log n)$ sorting threshold.

---

## Approach: Bucket Sort

The provided solution uses a **Bucket Sort** algorithm to achieve linear time complexity $O(n)$. 

1. **Frequency Mapping**: 
   We first traverse the input array `nums` to count the occurrences of each element using a hash map (`unordered_map<int, int> counter`), where the key is the number and the value is its frequency.

2. **Bucket Grouping**: 
   We initialize an array of buckets (`vector<vector<int>> ref`) of size `nums.size() + 1`. The index of this array represents the frequency of the elements. We iterate through our frequency map and place each number into the bucket corresponding to its frequency. For example, if the number `5` appears `3` times, it is pushed into `ref[3]`.

3. **Result Collection**: 
   Since we want the most frequent elements, we iterate through the bucket array backward (from the highest possible frequency `nums.size()` down to `1`). We collect elements from these buckets and append them to our result list until we have collected exactly $k$ elements.

---

## Code

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counter;
        for(int n : nums){
            counter[n]++;
        }
        
        vector<vector<int>> ref(nums.size() + 1);
        for(auto entry : counter){
            ref[entry.second].push_back(entry.first);
        }
        
        vector<int> ans;
        for(int i = ref.size() - 1; i > 0; i--){
            for(int num : ref[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return {};
    }
};
```

---

## Complexity Analysis

- **Time Complexity**: $\mathcal{O}(n)$
  - Building the frequency map takes $\mathcal{O}(n)$ time.
  - Distributing the unique elements into the bucket array takes $\mathcal{O}(u)$ time, where $u$ is the number of unique elements ($u \le n$).
  - Iterating through the buckets to gather the top $k$ elements takes $\mathcal{O}(n)$ time in the worst case.
  - Thus, the overall time complexity is linear, which is significantly better than the $\mathcal{O}(n \log n)$ sorting or $\mathcal{O}(n \log k)$ heap-based approaches.

- **Space Complexity**: $\mathcal{O}(n)$
  - The hash map stores at most $n$ unique elements.
  - The bucket array `ref` utilizes $\mathcal{O}(n)$ space to store lists of elements mapped to their frequencies.

---

## Edge Cases

- **$k$ equals the number of unique elements**: The algorithm naturally collects all elements from the buckets and terminates correctly once the result size reaches $k$.
- **All elements in the array are unique**: In this case, every element has a frequency of `1`. All elements will be placed in `ref[1]`. The nested loop will process them and return any $k$ elements.
- **All elements in the array are identical**: The single element will have a frequency of $n$ and will be placed in `ref[n]`. The loop will immediately find it and return it.
- **Negative numbers**: The hash map keys handle negative values seamlessly since standard integer hashing supports negative integers.