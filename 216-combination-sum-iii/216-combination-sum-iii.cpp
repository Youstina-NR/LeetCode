class Solution {
public:
    vector<vector<int>> res;
    vector<int> V;

    void getRes(int k, int n,int x,int cursum)
    {
        if(cursum == n && V.size() == k)
        {
            res.push_back(V);
            return;
        }
        else if(cursum > n || V.size()>=k )
            return;
        else if(V.size()>=1)
        {
            int s,e,minRSum;
            s = V[V.size()-1] + 1;
            e = V[V.size()-1] + k - V.size();
            minRSum = (e+s)*(e-s+1)/2;
            if(minRSum > n-cursum)
                return;
        }
        for(int i=x;i<=9;i++)
        {
            V.push_back(i);
            getRes(k,n,i+1,cursum+i);
            V.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         int minS = k*(k+1)/2;
        if( minS > n)
            return res;
        else if(minS == n)
        {
            vector<int> tmp;
            int sum = 0,i = 1;
            while(sum < n)
            {    
                tmp.push_back(i);
                sum += i;
                i++;
            }
            res.push_back(tmp);
            return res;
        }

        getRes(k,n,1,0);
        return res;
    }

};