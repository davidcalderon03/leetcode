class RandomizedSet {
public:
    set<int> numbers;
    vector<int> vect;
    bool vect_valid = false;
        RandomizedSet() {
    }
    
    bool insert(int val) {
        if (numbers.contains(val)) {
            return false;
        } else {
            numbers.insert(val);
            if (vect_valid)
                vect.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if (!numbers.contains(val)) {
            return false;
        } else {
            numbers.erase(val);
            vect_valid = false;
            return true;
        }
    }
    
    int getRandom() {
        if (!vect_valid) {
            vect.clear();
            for (int x : numbers)
                vect.push_back(x);
            vect_valid = true;
        }
        int index = rand()%(numbers.size());
        return vect[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
