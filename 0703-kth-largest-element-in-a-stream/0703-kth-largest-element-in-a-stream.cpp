class KthLargest {
    private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int rank;
public:
    KthLargest(int k, vector<int>& nums) {
        rank = k;
        for(int it: nums){
            minHeap.push(it);
            if(minHeap.size()>rank) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>rank){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */