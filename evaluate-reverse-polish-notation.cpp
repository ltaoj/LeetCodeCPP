class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> sta;
        for (int i = 0; i < tokens.size();i++) {
            if (isDegital(tokens[i])) {
                stringstream ss;
                ss<<tokens[i];
                int temp;
                ss>>temp;
                sta.push(temp);
            } else {
                if (sta.size() < 2)
                    return 0;
                int num1 = sta.top();sta.pop();
                int num2 = sta.top();sta.pop();
                int result;
                if (tokens[i] == "+")
                    result = num2 + num1;
                else if (tokens[i] == "-")
                    result = num2 - num1;
                else if (tokens[i] == "*")
                    result = num2 * num1;
                else if (tokens[i] == "/")
                    result = num2 / num1;
                sta.push(result);
            }
        }
        return sta.top();
    }
    
    bool isDegital(string str) {
        for (int i = 0;i < str.size();i++) {
            if (str.at(i) == '-' && str.size() > 1)
                continue;
            if (str.at(i) > '9' || str.at(i) < '0')
                return false;
        }
        return true;
    }
};