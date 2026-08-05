# Best Time to Buy and Sell Stock

## Problem Description
Imagine you are tracking the price of a stock over a sequence of days, represented by an array where each element is the stock's price on that day. You want to maximize your overall profit by making a single transaction: buying the stock on one day and selling it on a different day in the future. Because you cannot travel back in time, the buy day must strictly come before the sell day. If no profit can be made (for example, if the stock price only goes down), you should perform no transactions and return `0`.

## Approach
The provided solution uses a highly efficient, single-pass greedy approach to find the maximum profit:

1. **Track the Minimum Price:** We maintain a variable `buyprice` to keep track of the lowest stock price seen so far. We initialize this to the price on the very first day (`prices[0]`).
2. **Track the Maximum Profit:** We maintain a variable `profit` initialized to `0` to store the maximum profit encounterable.
3. **Iterate and Update:** As we loop through the prices from the second day to the last:
   - If we find a price lower than our current `buyprice`, we update `buyprice` to this new price. This ensures we are always simulating a buy at the lowest historical point.
   - Otherwise, we calculate the potential profit if we were to sell at the current day's price (`prices[i] - buyprice`) and update `profit` if this value is greater than our previously recorded maximum profit.

By the end of the single iteration, `profit` holds the maximum achievable profit.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of days (the size of the `prices` array). We traverse the array exactly once, performing constant-time $\mathcal{O}(1)$ operations at each step.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The algorithm only uses two integer variables (`buyprice` and `profit`) regardless of the size of the input array.

## Edge Cases

- **Strictly Decreasing Prices:** If the stock price drops every day (e.g., `[5, 4, 3, 2, 1]`), a profit is impossible. In this scenario, `buyprice` will continually update to the lower price, the calculated profit at each step will remain `0`, and the algorithm will correctly return `0`.
- **Strictly Increasing Prices:** If the stock price rises every day (e.g., `[1, 2, 3, 4, 5]`), `buyprice` will lock onto the first element, and the profit will update daily until it reaches the maximum difference at the final element.
- **Single Day of Trading:** If the array contains only one price (e.g., `prices = [5]`), the loop does not execute, and the function correctly returns the initialized profit of `0`.