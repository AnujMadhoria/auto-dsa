class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int rightEnd=height.size()-1;
        int leftEnd=0;

        while(leftEnd<rightEnd){
            maxArea=max(maxArea, (rightEnd-leftEnd)*min(height[leftEnd],height[rightEnd]));

            if(height[leftEnd]<=height[rightEnd]){
                leftEnd++;
            }
            else{
                rightEnd--;
            }
        }
        return maxArea;
    }
};