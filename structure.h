// linked list
struct listNode;

// binary search tree with the parent node leading to a linked list
struct bstNode;

// bst and linked list insert function, bst insert part based from Week 04 Workshop
struct bstNode *bstInsert(struct bstNode *parent_node, char **data);

// free tree function, code partially based from Week 04 Workshop
void freeTree(struct bstNode *parent_node);