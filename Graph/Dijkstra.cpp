#define INF INT_MAX

struct Node {
    int index;
    int weight;
    Node(int i, int w) : index(i), weight(w) {};
};
struct AdjList {
    int index;
    vector<Node*> neighbors;
    AdjList(int x) : index(x) {};
};

class Solution {
public:
    vector<Node*> Dijkstra(vector<AdjList*> graph) {
        vector<Node*> key;
        if (graph.empty()) {
            return key;
        }
        // init
        key.push_back(new Node(0, 0));
        for (int i = 1; i < graph.size(); i++) {
            key.push_back(new Node(i, INF));
        }
        
        vector<bool> visited(graph.size(), false);
        int visit_cnt = 0;
        while (visit_cnt < graph.size()) {
            auto cur = getMinNode(visited, key);
            visited[cur->index] = true;
            visit_cnt++;
            
            auto nbs = graph[cur->index]->neighbors;
            for (auto x : nbs) {
                if (!visited[x->index]) {
                    key[x->index]->weight = (x->weight + cur->weight < key[x->index]->weight) 
                                    ? x->weight + cur->weight 
                                    : key[x->index]->weight;
                }
            }
        }
        return key;
    }
private:
    Node* getMinNode(vector<bool> visited, vector<Node*> key) {
        Node *min_node = NULL;
		int min_weight = INT_MAX;
        for (int i = 0; i < key.size(); i++) {
            if (!visited[i]) {
                if (key[i]->weight < min_weight) {
                    min_node = key[i];
                    min_weight = key[i]->weight;
                }
            }
        }
        return min_node;
    }
};



int main() 
{
	Solution s;
	vector<AdjList*> graph;
	for (int i = 0; i < 5; i++) {
		AdjList *adjlist = new AdjList(i);
		vector<Node*> nbs;
		switch(i) {
		case 0 : 
			nbs.push_back(new Node(1, 1));
			nbs.push_back(new Node(2, 1));
			break;
		case 1:
			nbs.push_back(new Node(0, 1));
			nbs.push_back(new Node(3, 2));
			nbs.push_back(new Node(4, 10));
			break;
		case 2:
			nbs.push_back(new Node(0, 1));
			nbs.push_back(new Node(4, 20));
			nbs.push_back(new Node(3, 9));
			break;
		case 3:
			nbs.push_back(new Node(1, 2));
			nbs.push_back(new Node(2, 9));
			nbs.push_back(new Node(4, 6));
			break;
		case 4:
			nbs.push_back(new Node(1, 10));
			nbs.push_back(new Node(2, 20));
			nbs.push_back(new Node(3, 6));
		}
		adjlist->neighbors = nbs;
		graph.push_back(adjlist);
	}
	auto res = s.Dijkstra(graph);
	for (auto x : res) {
		cout << x->index <<" " << x->weight << endl;
	}
}
