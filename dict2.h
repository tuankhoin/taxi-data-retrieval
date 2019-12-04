// get the bstNode key string from the line
char* get_key(char* string);

// search for the data recursively in the bst, given the search key
void search_key(char* input, struct bstNode *t, FILE *out_filename, int count);

// print out operation for stage 2
void stage_2_print(char* input, struct bstNode *node, FILE *out_filename, int count);

// if no results are found
void not_found(char *input, FILE *out_filename, int count);

/*in-order traverse function for stage 2*/
void in_trv(char* input, struct bstNode *t, FILE *out_filename, int count);

// free data after use
void free_data(char ***ndata, int num_data);
