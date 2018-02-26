class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> *dp = new vector<bool>[s.size()];
        for (int i = 0;i < s.size();i++) {
            for (int j = 0;j < s.size() - i;j++) {
                if (dict.find(s.substr(i, j + 1)) != dict.end())
                    dp[i].push_back(true);
                else
                    dp[i].push_back(false);
            }
        }
        vector<string> result; vector<string> words;
        output(s.size() - 1, s, result, words, dp);
        return result;
    }
    
    void output(int x, string s, vector<string> &result, vector<string> &words, vector<bool> *dp) {
        if (x == -1) {
            string sentence;
            for (int i = words.size() - 1;i >= 0;i--) {
                sentence+=words[i];
                if (i != 0) sentence += " ";
            }
            result.push_back(sentence);
        } else {
            for (int i = x;i >= 0;i--) { // 错误:for (int i = 0;i <= x;i--)
                if (dp[i][x - i]) {
                    words.push_back(s.substr(i, x - i + 1));
                    output(i - 1, s, result, words, dp);
                    words.pop_back();
                }
            }
        }
    }
};

/**
 *     0           1           2           3           4           5           6           7           8            9
 *0    c           ca          cat(1)      cats(1)     catsa       catsan      catsand     catsandd    catsanddo    catsanddog
 *1    a           at          ats         atsa        atsan       atsand      atsandd     atsanddo    atsanddog
 *2    t           ts          tsa         tsan        tsand       tsandd      tsanddo     tsanddog
 *3    s           sa          san         sand(1)     sandd       sanddo      sanddog
 *4    a           an          and(1)      andd        anddo       anddog
 *5    n           nd          ndd         nddo        nddog
 *6    d           dd          ddo         ddog
 *7    d           do          dog(1)
 *8    o           og
 *9    g
 */