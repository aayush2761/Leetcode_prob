#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int u, vector<int>& parent) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank, vector<int>& size) {
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);
        if(parent_u == parent_v) return;

        // attach smaller rank tree under bigger one
        if(rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
        else if(rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
            rank[parent_u]++;
        }
    }

    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        int n = nums.size();
        vector<int> parent(n), rank(n, 0), size(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;

        unordered_map<int,int> valToIndex;

        for(int i = 0; i < n; i++) {
            if(valToIndex.count(nums[i])) continue;

            if(valToIndex.count(nums[i] - 1)) {
                unionSet(i, valToIndex[nums[i] - 1], parent, rank, size);
            }

            if(valToIndex.count(nums[i] + 1)) {
                unionSet(i, valToIndex[nums[i] + 1], parent, rank, size);
            }

            valToIndex[nums[i]] = i;
        }

        int maxSize = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i) { // root
                maxSize = max(maxSize, size[i]);
            }
        }
        return maxSize;
    }
};
