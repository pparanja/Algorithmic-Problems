/*
About:
1. This algorithm figures out the breaking points in a graph. Also called as articulation points.
2. Applications :
    i. Used to figure out point-of-failure in network systems
    ii. Used to identify critical links in a system 
    iii. Identify critical components or critical relations in a graph
*/

class TarjansAlgorithm {
public:
    typedef unordered_map<int,int> mapIntInt;
    void DFS(int vertex, int time, vector<bool>& visited,
             mapIntInt& visitedTime, mapIntInt& lowTime,
             mapIntInt& parent, vector<vector<int>>& adjlist,
             vector<vector<int>>& cc) {
        
        visited[vertex] = true;
        visitedTime[vertex] = time;
        lowTime[vertex] = time;
        time++;
        
        bool isCritical = false;
        int childCount = 0;
        vector<int> ver;
 
        for (auto u : adjlist[vertex]) {
            if (parent[vertex] == u) continue;
            

            if (visited[u] == false) {
                childCount++;
                parent[u] = vertex;
                DFS(u, time, visited, visitedTime, lowTime, parent, adjlist, cc);
                
                if (visitedTime[vertex] < lowTime[u]) {
                    isCritical = true;
                    ver.push_back(u);
                } else {
                     lowTime[vertex] = min(lowTime[vertex], lowTime[u]);                   
                }              
            } else {
                lowTime[vertex] = min(visitedTime[u], lowTime[vertex]);
            }
        }
        
        if ((parent.find(vertex) == parent.end() && childCount >=2) ||
            (parent.find(vertex) != parent.end() && isCritical)) {
                for (int v : ver) {
                    cc.push_back(vector<int>{v, vertex});
                }
            }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        mapIntInt visitedTime;
        mapIntInt lowTime;
        mapIntInt parent;
        
        vector<vector<int>> cc;
        int time=0;
        vector<vector<int>> adjlist(n, vector<int>{});
        for (auto c : connections) {
            adjlist[c[0]].push_back(c[1]);
            adjlist[c[1]].push_back(c[0]);
        }

        DFS(0, time, visited, visitedTime,
            lowTime, parent, adjlist, cc);

        return cc;
    }


};