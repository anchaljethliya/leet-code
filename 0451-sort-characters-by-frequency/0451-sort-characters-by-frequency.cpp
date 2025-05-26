class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        string ans;

        int hf=INT_MIN;
        for(char str:s){
            m[str]++;

            hf=max(hf,m[str]);
        }

        while(hf>0){
            for(auto pair : m){
                if(pair.second==hf){
                    ans+=string(hf,pair.first);
                }
            }
            hf--;
        }

        return ans;
    }
};