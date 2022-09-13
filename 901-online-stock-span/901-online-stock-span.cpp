class StockSpanner {
public:
    vector<pair<int,int>> V;
    StockSpanner() {
           
    }
    
    int next(int price) {
        //
        vector<pair<int,int>>::reverse_iterator rit ;
        rit = V.rbegin();
        int c = 1;
        while(rit != V.rend() && rit->first <= price)
        {  
            c += rit->second;
            rit++;
            V.pop_back();
        }
        V.push_back(make_pair(price,c));
        
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */