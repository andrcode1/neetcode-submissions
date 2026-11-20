class MedianFinder {
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, greater<int>> secondHalf;

public:
    MedianFinder() {}

    void addNum(int num) {
        firstHalf.push(num);
        if (!secondHalf.empty() && firstHalf.top() > secondHalf.top()) {
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }

        if (firstHalf.size() > secondHalf.size() + 1) {
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }
        if (secondHalf.size() > firstHalf.size() + 1) {
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
    }

    double findMedian() {
        if (firstHalf.size() > secondHalf.size()) {
            return firstHalf.top();
        }
        if (firstHalf.size() < secondHalf.size()) {
            return secondHalf.top();
        }
        return (firstHalf.top() + secondHalf.top()) / 2.0;
    }
};