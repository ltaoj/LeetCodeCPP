/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /*UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL; // 看了好久的错误，忘了加这句。。。。
        UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
        visited.insert(make_pair(node, head));
        sta.push(node);
        
        while (!sta.empty()) {
            UndirectedGraphNode *root = sta.top();sta.pop();
            vector<UndirectedGraphNode *> lists;
            for (int i = 0;i < root->neighbors.size();i++) {
                map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator key = visited.find(root->neighbors[i]);
                if (key != visited.end()) {
                    lists.push_back(key->second);
                } else {
                    UndirectedGraphNode *newNode = new UndirectedGraphNode(root->neighbors[i]->label);
                    visited.insert(make_pair(root->neighbors[i], newNode));
                    sta.push(root->neighbors[i]);
                    lists.push_back(newNode);
                }
            }
            visited.find(root)->second->neighbors = lists;
        }
        return head;
    }*/
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        
        map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator key = visited.find(node);
        if (key != visited.end())
            return key->second;
        
        UndirectedGraphNode *cloneNode = new UndirectedGraphNode(node->label);
        visited.insert(make_pair(node, cloneNode));
        vector<UndirectedGraphNode *> lists;
        for (int i = 0;i < node->neighbors.size();i++) {
            lists.push_back(cloneGraph(node->neighbors[i]));
        }
        cloneNode->neighbors = lists;
        return cloneNode;
    }
    
private:
    stack<UndirectedGraphNode *> sta;
    map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
};