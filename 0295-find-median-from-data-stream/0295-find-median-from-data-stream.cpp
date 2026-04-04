class MedianFinder {
public:
    priority_queue<int> left_queue;
    priority_queue<int, vector<int>, greater<int>> right_queue;
    MedianFinder() {}

    void addNum(int num) {
        if(left_queue.empty() || num<left_queue.top()){
            left_queue.push(num);
        }else{
            right_queue.push(num);
        }

        if( left_queue.size() > right_queue.size()+1){
            right_queue.push(left_queue.top());
            left_queue.pop();
        }else if(left_queue.size() < right_queue.size()){
            left_queue.push(right_queue.top());
            right_queue.pop();
        }
    }

        double findMedian() {
            if (left_queue.size() == right_queue.size()) {
                return (double)(left_queue.top() + right_queue.top()) / 2;
            }
            return left_queue.top();
        }
    };

    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */