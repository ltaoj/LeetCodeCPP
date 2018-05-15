package leetcode;

import java.util.*;

/**
 * Created by ltaoj on 2018/05/11 21:40.
 *
 * @version : 1.0 算法复杂度过大
 */
public class WordLadderii {

    /**
     * 保存临时路径
     */
    LinkedList<String> tempPath = new LinkedList<>();

    /**
     * 保存结果路径
     */
    ArrayList<ArrayList<String>> result = new ArrayList<>();

    /**
     * @version 1
     * 判断两个字符串是否是邻居，如果两个字符串只有一个字符不同，那么认为是邻居，否则不是邻居
     * @param str1
     * @param str2
     * @return 如果是邻居，返回true，否则返回false
     */
    private boolean isNeighbor(String str1, String str2) {
        if (str1.length() != str2.length()) return false;

        boolean isNeighbor = false;

        for (int i =0;i < str1.length();i++) {
            if (str1.charAt(i) == str2.charAt(i)) continue;

            if (isNeighbor) {
                isNeighbor = false;
                break;
            }

            isNeighbor = true;
        }

        return isNeighbor;
    }

    /**
     * @version 1
     * dfs查找
     * @param neighbors
     * @param path 存储路径
     * @param cur
     * @param goal
     * @return 如果查找到，返回true，没找到返回false
     */
    @Deprecated
    private boolean dfsPath(Map<String, Set<String>> neighbors, ArrayList<String> path, String cur, String goal) {
        if (cur.equals(goal)) { // 已经找到可以结束
            path.add(cur);
            return true;
        }

        System.out.println(neighbors + " <-> " + cur + " <-> " + neighbors.get(cur));

        // 出现环或者孤立节点，查找失败
        if (path.contains(cur) || neighbors.get(cur) == null) return false;

        path.add(cur);
        // 当找到一条路径后即代表成功，bug
        for (String neighbor : neighbors.get(cur)) {
            if (!dfsPath(neighbors, path, neighbor, goal)) continue;
            return true;
        }

        return false;
    }

    /**
     * @version 1
     * @param start
     * @param end
     * @param dict
     * @return
     */
    /*public ArrayList<ArrayList<String>> findLadders(String start, String end, HashSet<String> dict) {
        // 1.构建邻接矩阵
        Map<String, Set<String>> neighbors = new HashMap<>();
        dict.add(start);
        dict.add(end);
        Iterator<String> iterator = dict.iterator();
        while (iterator.hasNext()) {
            String key = iterator.next();
            if (neighbors.containsKey(key)) continue;
            neighbors.put(key, new HashSet<>());

            for (String word : dict) {
                if (isNeighbor(key, word)) {
                    neighbors.get(key).add(word);
                }
            }
        }

        // 2.dfs查找, 结束条件为当前节点为目标节点或者当前节点已存在路径中
        ArrayList<ArrayList<String>> res = new ArrayList<>();
        int maxStep = Integer.MAX_VALUE;
        for (String word : dict) {
            // 首先找到开始节点
            if (!isNeighbor(start, word)) continue;

            ArrayList<String> path = new ArrayList<>();
            if (!dfsPath(neighbors, path, start, end)) continue;

            if (path.size() > maxStep) continue;

            if (path.size() < maxStep) {
                maxStep = path.size();
                res.clear();
                res.add(path);
                continue;
            }

            res.add(path);
        }

        return res;
    }*/

    /**
     * 根据反向邻接矩阵，求解最短路径集合
     * @version 2
     * @param start 开始节点
     * @param end 结束节点
     * @param path 反向邻接矩阵
     */
    private void resolve(String start, String end, HashMap<String, HashSet<String>> path) {

        tempPath.add(0, end);
        HashSet<String> neightbors = path.get(end);
        if (neightbors != null && neightbors.contains(start)) {
            tempPath.add(0, start);
            result.add(new ArrayList<>(tempPath));

            String realEnd = tempPath.getLast();
            tempPath.clear();
            tempPath.add(realEnd);
            return;
        }

        for (String neighbor : neightbors) {
            resolve(start, neighbor, path);
        }
    }

    /**
     * 定义：
     * 单词距离：两个相同长度的单词，对应位字母不同的个数表示两个单词的距离
     * 邻居：单词距离为1的两个单词互为邻居
     *
     * 算法思路：
     * @version 2
     * @param start
     * @param end
     * @param dict
     * @return
     */
    public ArrayList<ArrayList<String>> findLadders(String start, String end, HashSet<String> dict) {
        tempPath.clear();
        result.clear();

        HashSet<String> currentStep = new HashSet<>();
        HashSet<String> nextStep = new HashSet<>();

        // 反向邻接矩阵
        HashMap<String, HashSet<String>> path = new HashMap<>();

        final HashSet<String> unvisited = dict;
        // 需要把end加入未访问节点集合
        unvisited.add(end);

        if (unvisited.contains(start)) {
            unvisited.remove(start);
        }

        currentStep.add(start);

        while (!currentStep.contains(end) && unvisited.size() > 0) {
            // 对于当前层所有节点，从未访问集合中找到邻居，构建反向邻接矩阵
            for (String cur : currentStep) {
                char[] curChars = cur.toCharArray();
                for (int i = 0;i < start.length();i++) {
                    char ogc = curChars[i];
                    for (int j = 0;j < 26;j++) {
                        if (curChars[i] == 'a' + j) continue;

                        curChars[i] = (char) ('a' + j);
                        System.out.println(String.valueOf(curChars));
                        if (unvisited.contains(String.valueOf(curChars))) {
                            nextStep.add(String.valueOf(curChars));
                            HashSet<String> neighbor = path.get(String.valueOf(curChars));
                            if (neighbor == null) {
                                neighbor = new HashSet<>();
                                path.put(String.valueOf(curChars), neighbor);
                            }
                            neighbor.add(cur);
                        }
                    }

                    curChars[i] = ogc;
                }
            }

            // 如果下一层集合没有节点，肯定找不到路径，退出
            if (nextStep.isEmpty()) break;

            // 从未访问集合中移除下层节点
            for (String next : nextStep) {
                unvisited.remove(next);
            }

//            currentStep = nextStep;
            // 这里不能直接使用指针指向nextStep!!! 需要重新new or addAll
            currentStep.clear();
            currentStep.addAll(nextStep);
            nextStep.clear();
        }

        // 退出while循环后，邻接矩阵构建完毕,需要根据邻接矩阵求解路径
        if (path.containsKey(end))
            resolve(start, end, path);

        return result;
    }

    /**
     * @version 1
     * @param res
     */
    private void print(ArrayList<ArrayList<String>> res) {
        for (int i = 0;i < res.size(); i++) {
            ArrayList<String> path = res.get(i);
            for (int j = 0;j < path.size();j++) {
                System.out.printf(path.get(j) + " -> ");
            }
            System.out.print("\n");
        }
    }

    public static void main(String[] args) {
        WordLadderii demo = new WordLadderii();
        String start = "hit";
        String end = "cog";

        HashSet<String> dict = new HashSet<>();
        dict.add("hot");
        dict.add("dot");
        dict.add("dog");
        dict.add("lot");
        dict.add("log");

        long startTime = System.currentTimeMillis();
        ArrayList<ArrayList<String>> res = demo.findLadders(start, end, dict);
        long endTime = System.currentTimeMillis();
        demo.print(res);
        System.out.println((endTime - startTime) + "ms");
    }
}
