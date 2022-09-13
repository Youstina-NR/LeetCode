class Solution {
public:
    bool BFS(map<string,map<string,double>> M, string src, string goal,map<string,string>& parent)
{
    deque<string> Q;
    set<string> V;
    map<string,int> D;
    
    V.insert(src);
    Q.push_back(src);
    D[src] = 0;
    
    string n;
    map<string,map<string,double>>::iterator itM1;
    map<string,double>::iterator itM2;
    
    while(!Q.empty())
    {
        n = Q.front();
        Q.pop_front();
        itM1 = M.find(n);
        if(itM1 != M.end())
            for(itM2 =  itM1->second.begin(); itM2 != (itM1->second).end(); itM2++)
            {
                if(V.find(itM2->first) == V.end())
                {
                    V.insert(itM2->first);
                    D[itM2->first] = D[n]+1;
                    parent[itM2->first] = n;
                    Q.push_back(itM2->first);
                    
                    if(itM2->first == goal)
                        return true;
                }
            }
    }
    return false;
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
               vector<double> R;
        map<string,map<string,double>> M;
        map<string,map<string,double>>::iterator itM1;
        map<string,double>::iterator itM2;
        vector<double>::iterator itV = values.begin();
        vector<string>::iterator itE1,itE2 ;
        double res;
        
        
        map<string,string> parent;
        string p,c;
        
        for (vector<vector<string>>::iterator it = equations.begin() ; it != equations.end(); ++it)
        {
            itE1 = itE2 = (*it).begin();
            itE2++;
            if(M.find(*itE1) == M.end())
            {
                M.insert(make_pair((*itE1),map<string,double>()));
            }
            M[(*itE1)].insert(make_pair((*itE2),(*itV))); 
            
            if(M.find(*itE2) == M.end())
            {
                M.insert(make_pair((*itE2),map<string,double>()));
            }
            M[(*itE2)].insert(make_pair((*itE1),1/(*itV))); 
            
            itV++;
            
        }
        
        for (vector<vector<string>>::iterator it = queries.begin() ; it != queries.end(); ++it)
        {
            itE1 = itE2 = (*it).begin();
            itE2++;
            
            if(M.find(*itE1) == M.end() || M.find(*itE2) == M.end())
            {
                R.push_back(-1);
                continue;
            }
            
            if((*itE1) == (*itE2))
            {
                R.push_back(1);
                continue;
            }
            
            itM1 = M.find(*itE1);
            itM2 = (itM1->second).find(*itE2);
            if( itM2 != (itM1->second).end())
            {
                R.push_back(itM2->second);
                continue;
            }
            else
            {
                
                bool flag = BFS(M,(*itE1),(*itE2),parent);
                map<string,string>::iterator itP;
               
                
                if(flag)
                {
                    c = (*itE2);
                    p = parent[c];
                    res = 1.0;
                    while(true)
                    {
                        res *= M[p][c];
                        if(p == (*itE1))
                            break;
                        c = p;
                        p = parent[c];
                    }
                    R.push_back(res);
                    
                }
                else
                R.push_back(-1);
                
            }
            
            
            
            
        }
        
        
        return R;
        
    }
};