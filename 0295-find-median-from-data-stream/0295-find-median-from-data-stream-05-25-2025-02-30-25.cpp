class MedianFinder {
public:
    priority_queue<int>pq;
    MedianFinder() {
        pq = priority_queue<int>();
    }
    
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        vector<int>storageNums;
        int n= pq.size();
        double result=0;
        if(n&1){
            // for odd number 
            int req= n/2;
            while(req--){
                storageNums.push_back(pq.top());
                pq.pop();
            }
            result=1.0*pq.top();
        }
        else{
            int req= (n/2) -1;
            while(req--){
                storageNums.push_back(pq.top());
                pq.pop();
            }
            result= pq.top();
            storageNums.push_back(pq.top());
            pq.pop();
            result = (result + pq.top())/(2.0);

        }
        for(auto it : storageNums)pq.push(it);
        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */