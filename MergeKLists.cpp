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

class MergeKLists {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> q;  // 默认为大根堆
        for(ListNode* listNode: lists){
            if(listNode != nullptr) q.push(Node(listNode->val, listNode));
        }

        // 保护节点
        ListNode head;
        ListNode* last = &head;

        while(!q.empty()){
            Node node = q.top();
            q.pop();
            last->next = node.listNode;
            last = last->next;

            ListNode* p = node.listNode->next;
            if(p != nullptr) q.push(Node(p->val, p));
        }
        return head.next;
    }
};