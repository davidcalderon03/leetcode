class SmallestInfiniteSet {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> removed;
    int n = 1;
    SmallestInfiniteSet() {
        pq.push(1);
    }
    
    int popSmallest() {
        int popped = pq.top();
        removed.insert(popped);
        pq.pop();
        pq.push(++n);
        return popped;
    }
    
    void addBack(int num) {
        if (removed.contains(num)) {
            pq.push(num);
            removed.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
