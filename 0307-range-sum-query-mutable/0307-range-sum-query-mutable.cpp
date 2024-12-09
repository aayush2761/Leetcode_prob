class SegmentTree {
private:
    const int DEFAULT_VALUE = 0;
    vector<int> st;
    int n;

public:
    // O(n) time | O(n) space
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        st = vector(4 * n, DEFAULT_VALUE);
        build(1, 0, n - 1, nums);
    }

    int build(int node, int segmentStart, int segmentEnd, vector<int>& nums) {
        if (segmentStart == segmentEnd) {
            st[node] = nums[segmentStart];
        } else {
            int mid = (segmentStart + segmentEnd) / 2;
            int nodeLeft = node * 2, nodeRight = node * 2 + 1;
            int leftSum = build(nodeLeft, segmentStart, mid, nums);
            int rightSum = build(nodeRight, mid + 1, segmentEnd, nums);
            st[node] = leftSum + rightSum;
        }
        return st[node];
    }

    // O(logn) time | O(logn) space
    int query(int queryStart, int queryEnd) {
        return query(1, 0, n - 1, queryStart, queryEnd);
    }

    int query(int node, int segmentStart, int segmentEnd, int queryStart, int queryEnd) {
        if (queryEnd < segmentStart or segmentEnd < queryStart) {
            return DEFAULT_VALUE;
        }
        if (queryStart <= segmentStart and segmentEnd <= queryEnd) {
            return st[node];
        }
        int mid = (segmentStart + segmentEnd) / 2;
        int nodeLeft = node * 2, nodeRight = node * 2 + 1;
        int leftQuery = query(nodeLeft, segmentStart, mid, queryStart, queryEnd);
        int rightQuery = query(nodeRight, mid + 1, segmentEnd, queryStart, queryEnd);
        return leftQuery + rightQuery;
    }

    // O(logn) time | O(logn) space
    void update(int index, int value) {
        update(1, 0, n - 1, index, value);
    }

    void update(int node, int segmentStart, int segmentEnd, int index, int newValue) {
        if (segmentStart == index and index == segmentEnd) {
            st[node] = newValue;
            return;
        }
        int mid = (segmentStart + segmentEnd) / 2;
        int nodeLeft = node * 2, nodeRight = node * 2 + 1;
        if (index <= mid) {
            update(nodeLeft, segmentStart, mid, index, newValue);
        } else {
            update(nodeRight, mid + 1, segmentEnd, index, newValue);
        }
        st[node] = st[nodeLeft] + st[nodeRight];
    }
};

class NumArray {
private:
    SegmentTree* st;

public:
    NumArray(vector<int>& nums) {
        st = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        st->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return st->query(left, right);
    }
};