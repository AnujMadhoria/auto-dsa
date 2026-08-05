# 11. Container With Most Water

## Problem Description
Imagine a series of vertical lines plotted on a 2D graph at regular intervals. You need to choose any two lines to act as the walls of a container. The space between these two lines and the x-axis represents the container, which can hold water up to the height of the shorter of the two lines. The goal is to find the pair of lines that can hold the maximum volume of water, where the volume is calculated as the distance between the two lines multiplied by the height of the shorter line.

## Approach
This problem can be solved efficiently using the **Two-Pointer** technique coupled with a **Greedy** strategy:

1. **Initialization**: Place two pointers at the extreme ends of the array: `leftEnd` at the beginning (`0`) and `rightEnd` at the end (`height.size() - 1`).
2. **Area Calculation**: At each step, calculate the area formed between the two pointers. The width is the distance between the pointers (`rightEnd - leftEnd`), and the height is limited by the shorter of the two vertical lines (`min(height[leftEnd], height[rightEnd])`). Update the global `maxArea` if the current area is larger.
3. **Greedy Pointer Movement**: 
   - To find a container that could potentially hold more water, we must move one of our pointers. 
   - Since moving either pointer inward reduces the width of the container, we must try to maximize the height. 
   - If we move the pointer pointing to the taller line, the height of the container will still be limited by the shorter line, resulting in a strictly smaller area. Therefore, we always move the pointer pointing to the **shorter** line inward, hoping to find a taller line that compensates for the lost width.
4. **Termination**: Repeat this process until the two pointers meet.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the length of the `height` array. The algorithm uses a single pass, moving the two pointers toward each other until they meet.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. Only a few variables are used to keep track of the pointers and the maximum area.

## Edge Cases
- **Minimum Input Size ($n = 2$):** The loop runs exactly once, calculating the area between the only two available lines.
- **Equal Heights (e.g., `[1, 1]` or `[5, 5, 5]`):** When both lines have the same height, moving either pointer is safe. The algorithm defaults to moving `leftEnd` forward, which maintains correctness.
- **Monotonically Increasing/Decreasing Heights:** The pointers will systematically shrink from the shorter side, correctly identifying the optimal boundaries.
- **Lines of Zero Height:** If heights of $0$ are present, the area calculation correctly evaluates to $0$ without causing any division or index out-of-bounds errors.