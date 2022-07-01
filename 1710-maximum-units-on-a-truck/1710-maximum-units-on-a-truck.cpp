class Solution {
public:
    static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
    {
        return (a.second > b.second);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> V;
        for(auto x : boxTypes)
        {
            V.push_back(make_pair(x[0],x[1]));
        }
        sort(V.begin(),V.end(),sortbysec);
        
        int res = 0, c = 0, i = 0, t;
        while( c < truckSize && i < V.size())
        {
            if(c + V[i].first <= truckSize)
            {
                c += V[i].first;
                res += (V[i].first * V[i].second);
            }
            else
            {
                t = truckSize - c;
                c = truckSize;
                res += t * V[i].second;
            }
            
            i++;
        }
        return res;
    }
};