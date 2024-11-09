
struct node_t{
    int data;
    node_t* left;
    node_t* right;
};

node_t* CreateNode(int value);
void Insert(node_t* node, int value);
void Print (node_t* node);
void DestructNode(node_t* node);
void export_tree_to_dot(node_t* root, const char* filename);