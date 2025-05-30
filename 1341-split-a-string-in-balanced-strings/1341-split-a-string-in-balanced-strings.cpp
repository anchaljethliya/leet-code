class Solution {
public:
    int balancedStringSplit(string s) {


       int n = s.size();
       if(n < 2){ //string length  atleast 2  
         return 0;
       }
    int  ans = 0; //for storing the substring
    int count1 =0;
    int count2 =0;
    for(int i =0 ;i<n ;i++){
       for(int j =i ;j<n ;j++){
          if(s[j]=='R') count1++;
          if(s[j]=='L')count2++;

          if(count1 == count2) ans++;
          break;
           
       }
    }

    return ans; 
        
    }
};