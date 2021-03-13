/*
Application : This is used in finding connected components of a graph


*/

class UnionFind {
    unordered_map<int,Node*> dataNode;

    struct Node {
        int data;
        int rank;
        Node *parent;
    };

    void makeSet(int data) {
        Node n = new Node();
        n->data = data;
        n->rank = 0;
        n->parent = n;
        dataNode[data] = n;
    }
    Node *findSet(int data) {
        Node *n = dataNode[data];
        if (n->parent != n) {
            n->parent = findSet(n->parent);
        }
        return n->parent;
    }

    void unionSet(int data1, int data2) {
        Node *parent1 = findSet(data1);
        Node *parent2 = findSet(data2);

        if (parent1 == parent2) {
            return;
        }
       
        if (parent1->rank >= parent2->rank) {
            parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank++ : parent1->rank;
            parent2->parent = parent1;
        } else {
            parent1->parent = parent2;
        }
    }
 
};

// In case of arrays or applications where simpler modelling is required..
class Problem {
    void API () {
        // Input represents separate entities on which union find is to be performed. They could be id's corresponding to different objects.
        // Size of input indicates nodes vary from 0 to input.size()-1
        vector<int> input = {0,1,2,3,4};

        UnionFind uf = new UnionFind();

        // Create makeSet first.. 
        uf.makeSet(input);

        // Perform UF provided some relation matrix for the input  
        if (/*condition*/) {
                int p1 = uf.findSet(data1);
                int p2 = uf.findSet(data2);
                
                uf.unionSet(data1,data2);
            }
        }
    }
};

class UnionFind {
    vector<int> parent;
    vector<int> rank;

    void makeSet(vector<int>& input) {
        parent.resize(input.size());
        for (auto i : input) {
            parent[i] = i;
        }
    }

    int findSet(int data) {
        if (parent[data] != data) {
            parent[data] = findSet(parent[data]);
        }
        return parent[data];
    }

    void unionSet(int data1, int data2) {
        int p1 = findSet(data1);
        int p2 = findSet(data2);

        if (p1 != p2) {
            if (rank[p1] >= rank[p2]) {
                parent[p2] = p1;
                rank[p1] = (rank[p1] == rank[p2]) ? rank[p1]++ : rank[p1];
            } else {
                parent[p1] = p2;
            }
        }
    }
};