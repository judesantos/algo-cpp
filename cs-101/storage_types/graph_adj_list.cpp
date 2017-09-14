#include <iostream>
#include <map>
#include <list>
#include <memory.h>

using namespace std;

class graph {
    private:
        map<int, list<int> > nodes;

    public:

        void add(int adj, int val) {
            nodes[adj].push_back(val);
        }

        void bfs(int val, list<int>& result) {
            
            int n_nodes = nodes.size();
            bool visited[n_nodes];

            list<int>::iterator it;
            visited[val] = true;

            list<int> q;
            q.push_back(val);

            while(!q.empty()) {

                val = q.front();
                result.push_back(val);
                q.pop_front();
               
                list<int>& item = nodes[val];

                for (it = item.begin(); it != item.end(); ++it) {

                    if (!visited[*it]) {
                        visited[*it] = true;

                        q.push_back(*it);
                    }
                }
            }
        }

        void dfs_helper(int val, bool* visited, list<int>& result) {
            
            result.push_back(val);
            visited[val] = true;

            list<int>& item = nodes[val];
            list<int>::iterator it;

            for (it = item.begin(); it != item.end(); ++it) {

                val = *it;

                if (!visited[val]) {

                    dfs_helper(val, visited, result);
                }            
            }
        }

        void dfs(int val, list<int>& result) {

            int n_nodes = nodes.size();
            bool visited[n_nodes];

            memset(visited, false, n_nodes);

            dfs_helper(val, visited, result);
        }

        bool is_route(int n1, int n2) {

            bool found = false;
            int n_nodes = nodes.size();
            bool visited[n_nodes];

            memset(visited, false, n_nodes);

            list<int> q;

            q.push_back(n1);
            visited[n1] = true;

            while (!q.empty()) {

                n1 = q.front();
                q.pop_front();

                if (n1 == n2) {
                    found = true;
                    break;
                }

                list<int> item = nodes[n1];
                list<int>::iterator it;

                for (it = item.begin(); it != item.end(); ++it) {

                    n1 = *it;
                    
                    if (!visited[n1]) {
                        visited[n1] = true;
                        q.push_back(n1);
                    }
                }
            }

            return found;
        }

};


int main() {

    graph g;

    g.add(0, 1);
    g.add(0, 2);
    g.add(1, 2);
    g.add(2, 0);
    g.add(2, 3);
    g.add(3, 3);
    g.add(4, 3);

    list<int> t;
    g.bfs(2, t);

    list<int>::iterator it;

    cout << "BFS:" << endl;

    for (it = t.begin(); it != t.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "DFS:" << endl;

    t.clear();

    g.dfs(2, t);

    for (it = t.begin(); it != t.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "is route found for 0 and 3? " << (g.is_route(0, 3) ? "Yes" : "No") << endl;

    cout << "is route found for 2 and 4? " << (g.is_route(2, 4) ? "Yes" : "No") << endl;

    return 0;
}
