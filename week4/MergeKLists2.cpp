/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #include<queue>

 struct Node{
    int key;
    ListNode* listNode;
    Node(int key, ListNode* listNode): key(key), listNode(listNode){};
 };

 bool operator < (const Node& a, const Node& b){
    //  a.key < b.key 大根堆
    //  a.key > b.key 小根堆
    return a.key > b.key;
 }

class BinaryHeap{
public:
    // 下标从1开始存时需要定义
    // BinaryHeap(){
    //     heap.push();
    // }

    bool empty(){
        return heap.empty();
    }

    void push(const Node& node){
        heap.push_back(node);
        // Heapify Up
        int curr = heap.size() - 1;
        while(curr > 0){
            int father = (curr - 1) / 2;
            if(heap[curr].key < heap[father].key){
                swap(heap[curr], heap[father]);
                curr = father;
            }else break;
        }
    }

    Node pop(){
        Node ans = heap[0]; // 堆顶
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        // Heapify Down
        int p = 0;
        int child = p*2 + 1;
        while(child < heap.size()){  // 非叶节点
            int otherChild = p*2 + 2;
            if(otherChild < heap.size() && heap[child].key > heap[otherChild].key) child = otherChild;
            if(heap[p].key > heap[child].key){  // 小根堆
                swap(heap[p], heap[child]);
                p = child;
                child = p*2 + 1;
            }else break;
        }
        return ans;
    }

private:
    // 数组实现二叉树
    vector<Node> heap;
};


class MergeKLists2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue<Node> q;  // 默认为大根堆
        BinaryHeap q;  // 使用自定义小根堆

        for(ListNode* listNode: lists){
            if(listNode != nullptr) q.push(Node(listNode->val, listNode));
        }

        // 保护节点
        ListNode head;
        ListNode* last = &head;

        while(!q.empty()){
            // Node node = q.top();
            // q.pop();
            Node node = q.pop();
            last->next = node.listNode;
            last = last->next;

            ListNode* p = node.listNode->next;
            if(p != nullptr) q.push(Node(p->val, p));
        }
        return head.next;
    }
};
