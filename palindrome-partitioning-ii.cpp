class Solution {
public:
    /*
     *    p[i][j] = true 表示s.sustr(i, j)为回文
     *    dp[i] 表示从i到len-1最少的分割线数目
     *
     */
    int minCut(string s) {
        // 初始化状态表
        vector<int> dp(s.size(), 0);
        for (int i = 0;i < s.size();i++) {
            dp[i] = isPalindrome(s.substr(0, i+1)) ? 0 : i;
            if (dp[i] == 0)
                continue;
            for (int j = 1;j <= i;j++) {
                if (isPalindrome(s.substr(j, i-j+1)))
                    dp[i] = dp[i] <= dp[j-1]+1 ? dp[i] : dp[j-1]+1;
                else
                    dp[i] = dp[i] <= dp[j-1]+i-j+1 ? dp[i] : dp[j-1]+i-j+1;
            }
        }
        return dp[s.size() - 1];
    }
    
private:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (right > left) {
            if (s[left] != s[right])
                return false;
            left++;right--;
        }
        return true;
    }
};