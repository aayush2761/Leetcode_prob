class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> rowFlag(n, 1), colFlag(n, 1);
        long long res = 0, rowRemain = n, colRemain = n;
        int row = queries.size();

        for (int i = row - 1; i >= 0; --i) {
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];

            if (type == 0 && rowFlag[index]) {
                res += colRemain * val;
                rowFlag[index] = 0;
                rowRemain--;
            }
            if (type == 1 && colFlag[index]) {
                res += rowRemain * val;
                colFlag[index] = 0;
                colRemain--;
            }
        }

        return res;
    }
};


// n=8
// [[0,6,30094],[0,7,99382],[1,2,18599],[1,3,49292],[1,0,81549],[1,1,38280],[0,0,19405],[0,4,30065],[1,4,60826],[1,5,9241],[0,5,33729],[0,1,41456],[0,2,62692],[0,3,30807],[1,7,70613],[1,6,9506],[0,5,39344],[1,0,44658],[1,1,56485],[1,2,48112],[0,6,43384]]