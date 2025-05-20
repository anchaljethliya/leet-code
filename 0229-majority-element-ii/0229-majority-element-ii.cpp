class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
          int num1=0,num2=0;
          int cnt1=0,cnt2=0;
          for(auto u:nums){
              if(u==num1){
                  cnt1++;
              }
              else if(u==num2){
                  cnt2++;
              }
              else if(cnt1==0){
                  cnt1++;
                  num1=u;
              }
              else if(cnt2==0){
                  cnt2++;
                  num2=u;
              }
              else{
                 cnt1--;
                 cnt2--;
              }
          }
          cnt1=0,cnt2=0;
          for(auto u:nums){
              if(u==num1) cnt1++;
              else if(u==num2) cnt2++;
          }
          vector<int>v;
          if(cnt1>nums.size()/3){
             v.push_back(num1);
          }
          if(cnt2>nums.size()/3){
              v.push_back(num2);
          }
          return v;
    }
};