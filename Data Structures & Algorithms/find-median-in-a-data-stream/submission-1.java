class MedianFinder {

    PriorityQueue<Integer> firstHalf;
    PriorityQueue<Integer> secondHalf;

    public MedianFinder() {
        firstHalf = new PriorityQueue<>(Comparator.reverseOrder());
        secondHalf = new PriorityQueue<>();
    }
    
    public void addNum(int num) {
        if (firstHalf.isEmpty() || num < firstHalf.peek()) {
            firstHalf.add(num);
        } else {
            secondHalf.add(num);
        }

        if (firstHalf.size() >= secondHalf.size() + 2) {
            secondHalf.add(firstHalf.poll());
        }
        if (secondHalf.size() >= firstHalf.size() + 2) {
            firstHalf.add(secondHalf.poll());
        }
    }
    
    public double findMedian() {
        if (firstHalf.size() > secondHalf.size()) {
            return firstHalf.peek();
        }
        if (secondHalf.size() > firstHalf.size()) {
            return secondHalf.peek();
        }
        return (firstHalf.peek() + secondHalf.peek()) / 2.0;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */