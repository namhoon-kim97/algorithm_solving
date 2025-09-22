import java.util.*;
class Solution {
    List<Integer> preorder = new ArrayList<>();
    List<Integer> postorder = new ArrayList<>();
    class Node{
        int x,y,idx;
        Node left, right;
        Node(int x, int y, int idx){
            this.x = x;
            this.y = y;
            this.idx = idx;
        }
        
    }
    
    public int[][] solution(int[][] nodeinfo) {
        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < nodeinfo.length; i++){
            nodes.add(new Node(nodeinfo[i][0],nodeinfo[i][1], i+1));
        }
        nodes.sort((a,b) -> {
            if (a.y == b.y) return Integer.compare(a.x,b.x);
            return Integer.compare(b.y,a.y);
        });
        
        Node root = nodes.get(0);
        for (int i = 1; i < nodes.size(); i++) {
            insert(root, nodes.get(i));
        }
        
        preOrder(root);
        postOrder(root);
            
        int[][] answer = new int[2][nodeinfo.length];
        for (int i = 0; i < nodeinfo.length; i++){
            answer[0][i] = preorder.get(i);
            answer[1][i] = postorder.get(i);
        }
        
        return answer;
    }
    
    void insert(Node parent, Node child){
        if (child.x < parent.x){
            if (parent.left == null) parent.left = child;
            else insert(parent.left, child);
        } else {
            if (parent.right == null) parent.right = child;
            else insert(parent.right, child);
        }
    }
    
    void preOrder(Node cur){
        if (cur == null) return;
        preorder.add(cur.idx);
        preOrder(cur.left);
        preOrder(cur.right);
    }
    void postOrder(Node cur){
        if (cur == null) return;
        postOrder(cur.left);
        postOrder(cur.right);
        postorder.add(cur.idx);
    }
}