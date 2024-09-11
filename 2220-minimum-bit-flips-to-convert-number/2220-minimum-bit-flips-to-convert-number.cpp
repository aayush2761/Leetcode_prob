class Solution {
public:

    int minBitFlips(int start, int goal) {
        int flips=0;
        int num = start^goal;
        for(int num = start ^ goal; num; num >>= 1)
        if(num & 1) flips++;

        return flips;
    }
    
};


int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }

//************_______------- Bit Shifting ttraversal   ************_______-------


        //    num = 1100 (binary) → num & 1 = 0 (rightmost bit is 0) → no increment in flips.
    //    num >>= 1 → num = 0110 (binary) → num & 1 = 0 → no increment.
    //    num >>= 1 → num = 0011 (binary) → num & 1 = 1 (rightmost bit is 1) → flips++ (flips becomes 1).
    //    num >>= 1 → num = 0001 (binary) → num & 1 = 1 (rightmost bit is 1) → flips++ (flips becomes 2).
    //    num >>= 1 → num = 0000 (binary) → loop ends.






//************_______------- count number of different set bits using ampersand (&)   ************_______-------



//     int minBitFlips(int start, int goal) {
//         int flip=0;
//         int num = start^goal;
//         // trraverse
//         for(int i=0;i<30;i++){
//             if(num & 1 << i) flip++;
//         }
//         return flip;
//     }

//        //     Let’s say num = 13, which in binary is 00000000000000000000000000001101.
       
//        // i = 0: 1 << 0 = 00000001 → num & 00000001 = 00000001 → bit is 1 → flip++.
//        // i = 1: 1 << 1 = 00000010 → num & 00000010 = 00000000 → bit is 0 → no increment.
//        // i = 2: 1 << 2 = 00000100 → num & 00000100 = 00000100 → bit is 1 → flip++.
//        // i = 3: 1 << 3 = 00001000 → num & 00001000 = 00001000 → bit is 1 → flip++.