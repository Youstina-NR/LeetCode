class Solution {
public:
    int totalFruit(vector<int>& fruits) {
            
        vector<int>::iterator it;
        vector<pair<int,int>> V;
        vector<pair<int,int>>::iterator it1,it2;
        it = fruits.begin();
        int val = (*it);
        int c = 0;

        while(it != fruits.end())
        {
            while(it != fruits.end() && (*it) == val)
            {
                c++;
                it++;
            }
            V.push_back(make_pair(val,c));
            if(it != fruits.end())
            {
                val = (*it);
                c = 0;
            }
        }

        it1 = it2 = V.begin();
        set<int> S;
        it2++;
        int max = 0, k = 0;

        while(true)
        {

            while(it1 != V.end() && S.size() < 2 )
            {
                S.insert(it1->first);
                k += it1->second;
                it1++;
            }
            while(it1 != V.end() && S.find(it1->first) != S.end())
            {
                k += it1->second;
                it1++;
            }
            if(k > max)
                    max = k;

            if(it1 == V.end())
            {
                break;
            }
            else
            {
                S.clear();
                it1--;
                
                k = 0;
            }
            if(max == fruits.size())
                break;

        }

        return max;
    }
};