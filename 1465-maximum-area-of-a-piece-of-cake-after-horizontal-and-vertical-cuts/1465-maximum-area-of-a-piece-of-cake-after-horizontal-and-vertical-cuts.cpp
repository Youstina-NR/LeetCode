class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        verticalCuts.push_back(w);
        horizontalCuts.push_back(h);
        int maxH = horizontalCuts[0] , maxW = verticalCuts[0];
        int i = 1;
        while(i < horizontalCuts.size())
        {
            if(horizontalCuts[i] - horizontalCuts[i-1] > maxH)
                maxH = horizontalCuts[i] - horizontalCuts[i-1];
            i++;
        }
        i = 1;
        while(i < verticalCuts.size())
        {
            if(verticalCuts[i] - verticalCuts[i-1] > maxW)
                maxW = verticalCuts[i] - verticalCuts[i-1];
            i++;
        }
        return (1LL*maxW*maxH)%1000000007;
    }
};