import java.util.HashMap;

class Trie {
    public class Node{
        int count;
        HashMap<Character, Node> child;
        Node(){
            count = 0;
            child = new HashMap<Character, Node>();
        }
    }
    Node root;

    /** Initialize your data structure here. */
    public Trie() {
        // 空字典树
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Node curr = root;
        for(char ch: word.toCharArray()){
            if(!curr.child.containsKey(ch)){
                curr.child.put(ch, new Node());
            }
            curr = curr.child.get(ch);
        }
        curr.count++;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Node curr = root;
        for(char ch: word.toCharArray()){
            if(!curr.child.containsKey(ch)) return false;
            curr = curr.child.get(ch);
        }
        return curr.count > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Node curr = root;
        for(char ch: prefix.toCharArray()){
            if(!curr.child.containsKey(ch)) return false;
            curr = curr.child.get(ch);
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */