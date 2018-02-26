class Solution {
public:
    int candy(vector<int> &ratings) {
        int inc = 0, dec = 0;
        int sum = ratings.size();
        for (int i = 1;i < ratings.size();i++) {
            if (ratings[i] > ratings[i-1]) {
                inc += 1;
                sum += inc;
                dec = 0;
            } else if (ratings[i] < ratings[i-1]) {
                for (; ratings[i] < ratings[i-1] && i < ratings.size();i++) {
                    dec += 1;
                    sum += dec;
                }
                sum -= inc > dec ? dec : inc;
                inc = 0;
                i--;
            } else {
                inc = 0;
                dec = 0;
            }
        }
        return sum;
    }
};