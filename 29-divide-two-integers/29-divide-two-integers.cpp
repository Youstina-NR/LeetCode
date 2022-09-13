class Solution {
public:
    int divide(int dividend, int divisor) {
        int s = 1;
        if(dividend < 0 && divisor < 0)
            s = 1;
        else if(dividend < 0 || divisor < 0)
            s = -1;
        
        long long q = 0;
        long long d1 = labs(dividend);
        long long d2 = labs(divisor);
        if(d2 == 1)
        {
            if(d1 == 2147483648)
                s == -1 ? q = dividend : q = d1-1 ;
            else 
                q = d1*s;
            return q;    
        }
        long long temp = 0;
        for(int i = 31 ; i>=0 ;i-- )
        {
            if(temp + (d2 << i) <= d1)
            {
                q |= (1LL <<i);
                temp += (d2<<i);
            }
        }
        
        return q*s;
    }
};