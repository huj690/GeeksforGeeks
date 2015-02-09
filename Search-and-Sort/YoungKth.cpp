struct Node {
  int i; 
  int j;
  int val;
  Node(int i, int j, int val) : i(i), j(j), val(val) {}
};
struct cmp {
  bool operator() (Node a, Node b) {
      return a.val < b.val;
  }  
};
class Solution {
public:
    int getKthMatrix(vector<vector<int> > &matrix, int k) {
        if (matrix.empty() || k == 0) {
            return 0;
        }
        
        int row = matrix.size(), col = matrix[0].size();
        priority_queue<Node, vector<Node>, cmp> heap;
        unordered_set<int> visit;
        
        visit.insert(matrix[0][col - 1]);
        Node node(0, col - 1, matrix[0][col - 1]);
        heap.push(node);
        
        int cnt = 1, res = 0;
        while (cnt <= k) {
            auto top = heap.top();
            res = top.val;
            cnt++;
            heap.pop();
            
            int left_index = (top.i - 1) * col +  (top.j - 1), down_index = (top.i) * col + top.j;
            if (visit.count(left_index) <= 0 && top.j - 1 >= 0) {
                visit.insert(left_index); 
                Node left(top.i, top.j - 1, matrix[top.i][top.j - 1]);
                heap.push(left);
            }
            if (visit.count(down_index) <= 0 && top.i + 1 < row) {
                visit.insert(down_index);
                Node down(top.i + 1, top.j, matrix[top.i + 1][top.j]);
                heap.push(down);
            }
        }
        return res;
    }    
};
