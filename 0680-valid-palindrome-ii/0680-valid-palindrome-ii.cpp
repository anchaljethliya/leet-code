class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                int a1 = i, b1 = j-1;
                int a2 = i+1, b2 = j;
                bool f = true;
                while(a1 < b1) {
                    if(s[a1] != s[b1]) {
                        f = false;
                        break;
                    }
                    a1++;
                    b1--;
                }

                if(f) return true;
                
                while(a2 < b2) {
                    if(s[a2] != s[b2]) {
                        return false;
                    }

                    a2++;
                    b2--;
                }

                return true;
            }
        }

        return true;
    }
};