// get the bstNode key string from the line
char* get_key(char* string);

// search for the data recursively in the bst, given the search key
void search_key(char* input, struct bstNode *t, FILE *out_filename, int count);

// print out operation for stage 1, going through the linked list
void stage_1_print(char* input, struct listNode *node, FILE *out_filename, int count);

// if no results are found
void not_found(char *input, FILE *out_filename, int count);

// free data after use
void free_data(char ***ndata, int num_data);
