/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int maxLinePoint = 0;
        int selfNum = 0;
        vector<double> vk;
        vector<int> vtime;
        if (points.size() < 3)
            return points.size();
        
        for (int i = 0;i < points.size();i++) {
            Point point = points[i];
            for (int j = 0;j < points.size();j++) {
                if (j == i) continue;
                // 计算斜率
                double k;
                if (points[j].x == point.x) { // 横坐标相等，如果重合，重复+1;否则不存在斜率的情况+1
                    if (points[j].y == point.y){
                        selfNum++;
                        continue;
                    } else {
                        k = 90 + point.x;
                    }
                } else
                    k = (points[j].y - point.y) * 1.0 / (points[j].x - point.x);
                int kIndex = findK(vk, k); // 查找map中是否已存在计算出的斜率
                if (kIndex == -1) {
                    vk.push_back(k);
                    vtime.push_back(1);
                } else {
                    vtime[kIndex] = vtime[kIndex] + 1;
                }
                
            }
            // 一条直线上的最大点个数为 与参照点重合的点的个数和其他不重合的最大点个数 和
            int max = maxTime(vtime) + selfNum;
            if (max > maxLinePoint)
                maxLinePoint = max;
            // 情况map，selfNum置为0
            vk.clear();vtime.clear();
            selfNum = 0;
        }
        return maxLinePoint;
    }
    
    int findK(vector<double> &vk, double k) {
        int index = -1;
        const float EPSINON = 0.00001;
        for (int i = 0;i < vk.size();i++) {
            if (abs(vk[i] - k) < EPSINON) {
                index = i;
                break;
            }
      
        }
        return index;
    }
    
    int maxTime(vector<int> &vtime) {
        int max = 0;
        for (int i = 0;i < vtime.size();i++) {
            if (vtime[i] > max)
                max = vtime[i];
        }
        return max + 1;
    }
};