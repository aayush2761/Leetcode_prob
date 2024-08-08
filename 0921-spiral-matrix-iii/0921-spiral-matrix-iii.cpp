class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;

        int r=rStart, c= cStart;
        ans.push_back({r,c});
        
        int move=0,d=0;
        //  clockwise -> right,bottom,left,top
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while(ans.size()<rows*cols)
        {
            if(d%2==0) // 0 and 2
            { 
                move++;
            }

            for(int i=0;i<move;i++)
            {
                r+=dir[d][0];
                c+=dir[d][1];

                if(r>=0 && r<rows && c>=0 && c<cols)
                {
                    ans.push_back({r,c});
                }
            }

            d = (d+1)%4; // 0 to 3
        }
        return ans;
    }
};

// clockwise -> right,bottom,left,top


// like just imagine like that this is infinte matrix and you move to cell outside the boundary 


// just image it as submatrix of  a matrix 


// whirlpool -> it gradually increases it size 

// this spiral will increases its length step by step 

// (starting point)
// 1,2 -> this moves in 1 times ->right
// 2,3 -> this moves in 1 times -> bottom
// 3,5 -> this moves in 2 times -> left
// 5,7 -> this move in 2 times  -> top
// 7,9 -> this need to move in 3 times ->right
// 9,10 -> moves in 3 times -> bottom

//                 4 times -> left
//                 4 times -> top
//                 .
//                 .
//                 .
//                 .




// what is happening ?

// we can observer a pattern 


// 1) After every 2 direction, moves are increasing , it can be possible that cells can go out of boundary in any direction. so we will take only that cells in our answer which are inside the boundary 
 



// left -> r,c-1 -> (0,-1)
// right-> r,c+1 -> (0,1)
// top -> r-1,c -> (-1,0)
// bottom ->  r+1,c -> (1,0)

