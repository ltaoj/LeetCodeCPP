class Solution {
public:
    // 使用额外O（n）的思路就是声明一个数组，大小为最长的那一行。
    // 将基于修改原数组的方式改变为记录在数组中
    // 当动态规划求解完毕后，res[0]就是所求的解
    int minimumTotal(vector<vector<int> > &triangle) {
        for (int i = triangle.size()-2;i >= 0;i--) {
            for (int j = 0;j < triangle[i].size();j++) {
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
