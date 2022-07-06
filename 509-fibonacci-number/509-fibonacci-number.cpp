class Solution {
public:
    int fib(int n) {
        double phi =  1.618034;
        int res = (pow(phi,n) - pow(1-phi,n))/sqrt(5);
        return res;
    }
};