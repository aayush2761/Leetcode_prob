class RandomizedSet {
public:
    int n;
     vector<int>v;
     map<int,int>mp;
    RandomizedSet() {
        mp.clear();
        n=0;
    }
    
    bool insert(int val) {
        if(mp.find(val)!= mp.end()) return 0;
        v.push_back(val);
        n++;
        mp[val]= n-1;
        return 1;
    }
    
    bool remove(int val) {
        // take the element to the end of the vector 
        if(mp.find(val)==mp.end()) return 0;
        int index = mp[val];
        int lastelement = v.back();

        v[index] = lastelement;
        mp[lastelement] = index;

        v.pop_back();
        mp.erase(val);

        n--;
        return true;
    }
    
    int getRandom() {
        int randomIndex= rand()%n; // 0,1,2,3,---(n-1)
        return v[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */