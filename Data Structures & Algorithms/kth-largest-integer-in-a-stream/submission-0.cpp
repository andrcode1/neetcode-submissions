class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k_(k), largestMarks_(nums.begin(), nums.end()) {
        while (largestMarks_.size() > k) {
            largestMarks_.pop();
        }
    }

    int add(int val) {
        largestMarks_.push(val);
        if (largestMarks_.size() > k_) {
            largestMarks_.pop();
        }
        return largestMarks_.top();
    }

private:
    std::priority_queue<int, vector<int>, greater<int>> largestMarks_;
    int k_;
};