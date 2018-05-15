class Solution {
public:
    // 保存结果
    vector<vector<string>> result;
    // 保存临时路径
    vector<string> temp_path;


    void resolve(string start, string end, map<string, vector<string>> &path) {
        temp_path.push_back(end);

        vector<string> neighbors = path[end];
        if (find(neighbors.begin(), neighbors.end(), start) != neighbors.end()) {
            temp_path.push_back(start);
            reverse(temp_path.begin(), temp_path.end());
            result.push_back(temp_path);
            reverse(temp_path.begin(), temp_path.end());
            temp_path.pop_back();
            return;
        }

        for (auto pneighbor = neighbors.begin();pneighbor != neighbors.end();++pneighbor) {
            resolve(start, *pneighbor, path);
            temp_path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> current_step, next_step;
        map<string, vector<string>> path;

        unordered_set<string> unvisited = dict;
        if (unvisited.count(start) > 0)
            unvisited.erase(start);

        current_step.insert(start);

        while (current_step.count(end) == 0 && unvisited.size() > 0) {
            for (auto pcur = current_step.begin();pcur != current_step.end();++pcur) {
                string cur = *pcur;
                for (int i = 0;i < start.length();++i) {
                    for (int j = 0;j < 26;j++) {
                        string tmp = cur;
                        if (tmp[i] == 'a' + j) continue;

                        tmp[i] = 'a' + j;
                        if (unvisited.count(tmp) > 0) {
                            next_step.insert(tmp);
                            path[tmp].push_back(cur);
                        }
                    }
                }
            }

            if (next_step.empty()) break;

            for (auto pnext = next_step.begin();pnext != next_step.end();++pnext) {
                unvisited.erase(*pnext);
            }

            current_step = next_step;
            next_step.clear();
        }

        if (path[end].size() > 0) {
            resolve(start, end, path);
        }

        return result;
    }
};
