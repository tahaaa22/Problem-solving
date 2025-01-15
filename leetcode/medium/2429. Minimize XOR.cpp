class Solution {
    private:
    void SetBit(int &bit, int currentbit) {bit |= 1<<currentbit;}
    bool IsSet(int bit, int current) {return bit & (1<<current);}
    void UnsetBit(int &bit, int currentbit) {bit &= ~(1<<currentbit);}

public:
    int minimizeXor(int num1, int num2) {
        int result = num1;
        int resultbits = __builtin_popcount(result);
        int num2bits = __builtin_popcount(num2);
        int currentbit = 0;
        while(resultbits > num2bits)
        {
            if(IsSet(result, currentbit)) 
            {
                UnsetBit(result, currentbit);
                resultbits--;
            }
            currentbit++;
        }
        currentbit =0;
        while(resultbits < num2bits)
        {
            if(!IsSet(result, currentbit))
            {
                SetBit(result, currentbit);
                resultbits++;
            }
            currentbit++;
        }
        return result;
    }
};