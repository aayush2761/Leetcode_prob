class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string resultedBinaryNumber="";
        while(n>0){
            if(n&1)resultedBinaryNumber.push_back('1');
            else resultedBinaryNumber.push_back('0');
            n>>=1;
        }
        // Pad with zeros to make it 32 bits
        while(resultedBinaryNumber.size() < 32) {
            resultedBinaryNumber.push_back('0');
        }
        uint32_t resultNumber=0;
        for(int i = 0; i < 32; i++) {
            if(resultedBinaryNumber[i] == '1') resultNumber += (1 << (31 - i));
        }
        return resultNumber;
    }
};