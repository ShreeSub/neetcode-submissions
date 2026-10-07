class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int>maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        maxheap.push(num);
        minheap.push(maxheap.top());//push the max element to minheap
        maxheap.pop();
        if(minheap.size()>maxheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size())
        {
            return (maxheap.top()+minheap.top())/2.0;
        }
        return maxheap.top();
    }
};
