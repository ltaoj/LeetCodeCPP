class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        for (int i = 1;i <= rowIndex;i++) {
            int last = res[0];
            for (int j = 1;j < i;j++) {
                int tmp = last;
                last = res[j];
                res[j] = tmp + res[j];
            }
        }
        return res;
    }
};
