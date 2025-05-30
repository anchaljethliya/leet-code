class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for(int i = 0, n = position.size(); i < n; ++i){
            if(position[i] & 1) ++odd;
            else ++even;
        }
        return min(odd , even);   
    }
};