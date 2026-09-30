class Solution {
public:

    void advanceLeftToRight(int& left, int& right, std::vector<int>& heights) {
        int originalWater = heights[left];
        left++;
        while(left < right and heights[left] <= originalWater) {
            left++;
        }
    }

    void advanceRightToLeft(int& right, int& left, std::vector<int>& heights) {
        int originalWater = heights[right];
        right--;
        while(right > left and heights[right] <= originalWater) {
            right--;
        }
    }

    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxWater = 0;
        int currentWater = 0;
	
        while (left < right) {
            currentWater = (right - left) * std::min(heights[left], heights[right]);
            if (currentWater > maxWater) {
                maxWater = currentWater;
            }
            if (heights[left] < heights[right]) {
                advanceLeftToRight(left, right, heights);
            } else if (heights[left] > heights[right]) {
                advanceRightToLeft(right, left, heights);
            } else if (heights[left] == heights[right]) {
                advanceLeftToRight(left, right, heights);
                advanceRightToLeft(right, left, heights);
            }
        }
        return maxWater;
    }
};
