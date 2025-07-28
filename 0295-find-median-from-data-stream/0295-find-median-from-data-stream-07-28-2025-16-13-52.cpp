class MedianFinder {
public:
//min-max heap concept 
// max heap for the smaller element +1 size greater 
// min heap for larger elements 
    priority_queue<int,vector<int>,greater<int>>minHeap;
    priority_queue<int>maxHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // if(!maxHeap.empty() && maxHeap.top()<=num)max_heap.push(num);
        // else minHeap.push(num);
        // this will reult in wrog if decreasing order 
        if(maxHeap.empty()|| maxHeap.top()>num){
            maxHeap.push(num);
        }
        else minHeap.push(num);

        if(abs((int)maxHeap.size()-(int)minHeap.size())>1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(minHeap.size()>maxHeap.size()){
             maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size()!= maxHeap.size()) return maxHeap.top();
        return (minHeap.top() + maxHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */