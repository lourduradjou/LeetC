class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = -1;
        for(int i = 1; i < num.size()-1; i++) {
            if( num[i] == num[i-1] && num[i] == num[i+1] ) {
                ans = max(ans, num[i] - '0');
            }
        }
        return (ans == -1) ? "" : string(3, '0' + ans);
    }
};