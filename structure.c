#include "structure.h"

// linked list
struct listNode {
	struct listNode *head;
    struct listNode *next;
    char **ndata;
};


// binary search tree with the parent node leading to a linked list
struct bstNode {
    struct bstNode *left;
    struct bstNode *right;
    struct listNode *parent;
};


// bst and linked list insert function, bst insert part based from Week 04 Workshop
struct bstNode *bstInsert(struct bstNode *parent_node, char **data){
 
	struct bstNode **insertLocation = &parent_node;
	struct listNode *p;
	
    while(*insertLocation){
		
        if(strcmp(get_key(*data), get_key((*insertLocation)->parent->ndata) < 0 ) {			
            insertLocation = &((*insertLocation)->left);			
        } else {			
            insertLocation = &((*insertLocation)->right);			 
		}
		
    }
    
    *insertLocation = (struct bstNode *) malloc(sizeof(struct bstNode));
    assert(*insertLocation);
    
    (*insertLocation)->left = NULL;
    (*insertLocation)->right = NULL;
	
		
	// insertion to linked list for multiple files with same PUDateTime
	p = malloc(sizeof(struct listNode));
	(*insertLocation)->(*data) = *node;
	p->parent->ndata = *data;
	p->parent->next = *node;
	*node = p;
    return parent;

}


// free tree function, code partially based from Week 04 Workshop
void freeTree(struct bstNode *parent_node){
    
    if(! parent_node){
        return;
    }
	
    // free the bst nodes
    freeTree(parent_node->left);
    freeTree(parent_node->right);
	struct listNode *current;
	current = parent_node->head;
	
	// free the linked list nodes
	while(current){
        head=current;
        free(current->ndata);
        current=current->next;
        free(head);
    }
	
    free(parent->node);
	
}