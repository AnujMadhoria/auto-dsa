# 560. Subarray Sum Equals K

## Problem Description

The problem asks us to find the total number of continuous segments (subarrays) within an array of integers that add up to a target value `k`. Because the array can contain negative numbers, zeros, and positive numbers, the running sum does not change monotonically, meaning a simple two-pointer or sliding window approach will not work. 

## Approach

The solution utilizes a **Prefix Sum** technique optimized with a **Hash Map** to find the target subarrays in linear time. 

1. **Prefix Sum Construction**: 
   We first construct a `prefixSum` array where `prefixSum[i]` represents the sum of all elements from index `0` to `i`. The sum of any subarray from index `j + 1` to `i` is given by the formula:
   $$\text{Subarray Sum} = \text{prefixSum}[i] - \text{prefixSum}[j]$$

2. **Finding the Target Subarrays**:
   To find a subarray that sums to $k$, we want to find indices $i$ and $j$ (where $j < i$) such that:
   $$\text{prefixSum}[i] - \text{prefixSum}[j] = k \implies \text{prefixSum}[j] = \text{prefixSum}[i] - k$$

3. **Hash Map Optimization**:
   As we iterate through the prefix sums, we use a hash map `mp` to keep track of the frequencies of all prefix sums encountered so far. For each index `i`:
   * **Direct Match**: If `prefixSum[i] == k`, it means the subarray starting from index `0` to `i` sums to $k$, so we increment our count.
   * **Complement Match**: We check if the value `prefixSum[i] - k` exists in our map. If it does, the frequency of this value tells us how many valid starting points $j$ exist that can be subtracted from the current prefix sum to yield exactly $k$. We add this frequency to our answer.
   * **Update Map**: Finally, we record the occurrence of the current `prefixSum[i]` in the hash map to make it available for future elements.

## Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$, where $N$ is the length of the input array `nums`. We traverse the array to construct the prefix sums, and then perform a single pass over the prefix sum array. Hash map lookups and insertions take $\mathcal{O}(1)$ time on average.
- **Space Complexity**: $\mathcal{O}(N)$ to store the `prefixSum` vector and the `unordered_map`, which can contain up to $N$ unique prefix sum values in the worst case.

## Edge Cases

- **Negative Numbers and Zeros**: The presence of negative numbers and zeros means prefix sums can decrease or remain constant. The hash map correctly tracks these because it stores the *frequency* of each prefix sum rather than just a boolean presence.
- **Subarrays of Length 1**: If a single element equals $k$, it is correctly handled by the `prefixSum[i] == k` check or by finding `prefixSum[i] - k` (which would be $0$) in the map if it occurred earlier.
- **No Valid Subarray**: If no subarray sums to $k$, the map searches will fail to find any matches, and the algorithm will correctly return `0`.