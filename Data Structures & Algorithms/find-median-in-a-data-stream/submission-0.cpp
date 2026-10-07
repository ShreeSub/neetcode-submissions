class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int>maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        maxheap.push(num);
        if(!maxheap.empty() && !minheap.empty() && maxheap.top()>minheap.top() || (maxheap.size()>minheap.size()+1))
        {
            int maxval = maxheap.top();
            maxheap.pop();
            minheap.push(maxval);
        }
        if(minheap.size()>maxheap.size()+1)
        {
            int minval = minheap.top();
            minheap.pop();
            maxheap.push(minval);

        }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size())
        {
            return (maxheap.top()+minheap.top())/2.0;
        }
        return maxheap.size()>minheap.size()?maxheap.top()*1.0:minheap.top()*1.0;
    }
};
