class Solution {
public:

    void advanceLeftToRight(int& left, int& right, std::vector<int>& heights) {
        int originalLeft = left;
        left++;
        while(left < right and heights[left] <= heights[originalLeft]) {
            left++;
        }
    }

    void advanceRightToLeft(int& right, int& left, std::vector<int>& heights) {
        int originalRight = right;
        right--;
        while(right > left and heights[right] <= heights[originalRight]) {
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
