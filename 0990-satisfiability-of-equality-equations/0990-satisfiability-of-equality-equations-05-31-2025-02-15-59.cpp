class Solution {
public:

    int find(int u, vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]= find(parent[u],parent);
    }
    void unionSet(int a, int b,vector<int>&parent,vector<int>&rank){
        int parent_a= find(a,parent);
        int parent_b= find(b,parent);
        if(parent_a==parent_b) return;
        // rank cases 
        if(rank[parent_a]>rank[parent_b]){
            parent[parent_b]= parent_a;
        }
        else  if(rank[parent_a]<rank[parent_b]){
            parent[parent_a]= parent_b;
        }
        else{
            rank[parent_a]++;
            parent[parent_b]= parent_a;

        }
    }
    bool equationsPossible(vector<string>& e) {
        // dsu 
        // dono ka parent equal nahi hona chaiye jb unequal hai toh!!!!!
        const int max= 50;
        vector<int>parent(50),rank(50,0);
        for(int i=0;i<50;i++)parent[i]=i;
        // code 
        for(auto it : e){
            int a= it[0]-'a';
            int b= it[3]-'a';
            if(it[1]=='='){
            //    if(a<b) unionSet(a,b,parent,rank);
            //    else unionSet(b,a,parent,rank);
            unionSet(a,b,parent,rank);
            }
            // sath mein process nhi krna 
        }
        for(auto &it : e){
            int a= it[0]-'a';
            int b= it[3]-'a';
             if(it[1]=='!'){
                if(find(a, parent) == find(b, parent)) return false;
            }
        }
        return true;

    }
};