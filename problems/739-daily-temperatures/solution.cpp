class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n,0);

        stack<int>stack;

        for(int i =0; i<n; i++){
            //first we check condition 
            while(!stack.empty() && temperatures[i]>temperatures[stack.top()]){
                int prev_index = stack.top();
                stack.pop();

                answer[prev_index]= i - prev_index;
            }
            stack.push(i);
        }
        return answer;
    }
};