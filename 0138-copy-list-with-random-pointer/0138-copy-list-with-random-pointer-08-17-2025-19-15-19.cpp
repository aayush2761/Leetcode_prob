/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // two pass approach 
        // first -> just crate the node and create the hash map 
        // second -> leverage the hashmap for pointing to the nodes 


        // base case 
        if(head==NULL) return nullptr;
        unordered_map<Node*, Node*>mp;
        // corner case can be a case but cant be also
        mp[NULL]= NULL;

        // first pass 
        Node* fPass= head;
        while(fPass){
            Node* copy = new Node(fPass->val);
            mp[fPass]= copy;
            fPass= fPass->next;
        }

        // second pass for the pointing to the nodes 
        Node* sPass= head;
        while(sPass){
            mp[sPass]->next= mp[sPass->next];
            mp[sPass]->random= mp[sPass->random];
            sPass=sPass->next;
        }
        return mp[head];
    }
};