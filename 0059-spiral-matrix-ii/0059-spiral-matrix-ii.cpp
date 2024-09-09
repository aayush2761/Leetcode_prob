class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int s=1;
        int e=n*n;
         vector<vector<int>>res(n,vector<int>(n,-1));
         vector<vector<bool> > seen(n, vector<bool>(n, false));
    
    if (n == 0)
        return res;

    // Change in row index for each direction
    int dr[] = { 0, 1, 0, -1 };

    // Change in column index for each direction
    int dc[] = { 1, 0, -1, 0 };

    int r = 0, c = 0;

    int di = 0;

    // ListNode*temp=head;


    for (int i = 0; i < n * n; ++i) {

        // Add current element to result vector
        int t=-1;
        if(s<=e)  t= s;
        else break;
        // temp=temp->next;
        s++;

        res[r][c]=(t);

        seen[r][c] = true;

        int newR = r + dr[di];
        int newC = c + dc[di];

        if (0 <= newR && newR < n && 0 <= newC && newC < n
            && !seen[newR][newC]) {

           
            r = newR;

           
            c = newC;
        }
        else {

           
            di = (di + 1) % 4;

            
            r += dr[di];

            
            c += dc[di];
        }
    }

 
    return res;
    }
};