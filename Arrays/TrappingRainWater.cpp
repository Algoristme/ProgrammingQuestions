// Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        stack<int> maxHtPos;
        int curr = 0;
        int vol = 0;
        while( curr < height.size()) {
            while(maxHtPos.size() > 0 && height[curr] > height[maxHtPos.top()]) {
                int top = maxHtPos.top();
                maxHtPos.pop();
                if(maxHtPos.size()==0) break;
                int distance = curr-maxHtPos.top()-1;
                int width = min(height[curr],height[maxHtPos.top()])-height[top];
                vol += (distance * width);                
            }
            maxHtPos.push(curr++);
        }
        return vol;
    }
};