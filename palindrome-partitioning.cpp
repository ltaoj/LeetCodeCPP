    /*
     *    a    ab    i = 1 dp[0][1] = 0
     *    b                dp[0][0] = 1 => partition(1, s, result, p, dp);
     *                                     i = 0 dp[1, 0] = 1
     */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        // 初始化状态表
        vector<bool>* dp = new vector<bool>[s.size()];
        for (int i = 0;i < s.size();i++) {
            for (int j = 0;j < s.size() - i;j++) {
                dp[i].push_back(isPalindrome(s.substr(i, j + 1)));
            }
        }
        
        vector<vector<string>> result;
        vector<string> p;
        partition(0, s, result, p, dp);
        return result;
        
    }
    
    void partition(int k, string s, vector<vector<string>> &result, vector<string> &p, vector<bool>* dp) {
        if (k == s.size()) {
            vector<string> temp(p);
            result.push_back(temp);
        } else {
            for (int i = 0;i < s.size() - k;i++) {
                if (dp[k][i]) {
                    p.push_back(s.substr(k, i + 1));
                    partition(k + i + 1, s, result, p, dp);
                    p.pop_back();
                }
            }
        }
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