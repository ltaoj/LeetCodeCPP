class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int left = -1, right = s.size();
        while (right > left) {
            while ((left+1) <= s.size()-1 && !isAlphaNum(s.at(++left))) {}
            while ((right-1) >= 0 && !isAlphaNum(s.at(--right))) {}
            if (!same(s.at(left), s.at(right))) break;
        }
        return left >= right;
    }
    
    bool isAlphaNum(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    
    bool same(char c1, char c2) {
        if (c1 >= 'a' && c1 <= 'z') c1 += 'A' - 'a';
        if (c2 >= 'a' && c2 <= 'z') c2 += 'A' - 'a';
        return c1 == c2;
    }
};