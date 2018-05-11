package leetcode;

import java.util.HashSet;
import java.util.Set;

/**
 * 复杂度分析o(n)：HashSet查找的复杂度为o(1)
 */
public class LongestConsecutiveSequence {
    public int longestConsecutive(int[] num) {
        Set<Integer> dstcNum = new HashSet<>();
        // 首先将数字去重
        for (Integer i : num) {
            dstcNum.add(i);
        }

        int res = 0;
        for (Integer i : num) {
            // 如果set中不包含该数字，也就是数字已经从set中删除了，那么我们选取下一个数字
            if (!dstcNum.contains(i)) continue;

            dstcNum.remove(i);
            int prev = i - 1, post = i + 1;
            while (dstcNum.contains(prev)) {
                dstcNum.remove(prev--);
            }

            while (dstcNum.contains(post)) {
                dstcNum.remove(post++);
            }

            res = Math.max(res, post - prev - 1);
        }

        return res;
    }
}