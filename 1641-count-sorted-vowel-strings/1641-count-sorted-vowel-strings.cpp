class Solution {
public:
    vector<int>V;
int sum;
void count(int n, int m)
    {
        if(n > 0)
        {
            for(int i = m ; i>1 ; i--)
            {
                sum++;
                count(n-1,i);  
            }
        }
        
        return ;
    }
    int countVowelStrings(int n) {
        if(n== 1)
            return 5;
        else
        {
            sum = 0;
            count(n,5);
            return sum+1;
        }
        
    }
};