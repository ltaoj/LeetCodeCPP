class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool>* dp = new vector<bool>[s.size()];
        for  (int i = 0;i < s.size();i++) {
            for (int j = 0;j < s.size() - i;j++) {
                dp[i].push_back(dict.find(s.substr(i, j+1)) != dict.end());
            }
        }
        vector<string> words, result;
        bool isSeg = false;
        output(s.size() - 1, s, isSeg, dp);
        return isSeg;
    }
    
private:
    void output(int k, string s, bool &isSeg, vector<bool>* dp) {
        if (k == -1) {
            isSeg = true;
            return;
        } else {
            for (int i = k;i >= 0;i--) {
                if (dp[i][k - i]) {
                    output(i - 1, s, isSeg, dp);
                }
            }
        }
    }
};