#include "dict1.h"
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_STRING 128
#define BUFFER_SIZE 256
#define NUM_INFO 18 //number of given details
#define PU_TIME_ARRAY 15 // pick up time will be the element 15 in the data array

// struct of input

	/*
	Note: dataset is put into an array in the same order as in the headers file. Therefore:
    pick up location ID will ndata[][5]
    pick up time will be ndata[][15]
	*/





// main function
int main(int argc, char **argv){
	
	struct bstNode *parent = NULL;
	char ***data = NULL;
	char buffer[BUFFER_SIZE];
    int num_data = 0;
	int i;                  
	int count = 0;          // number of comparisons
    char* current_line;
	
    // open the file with the given filename for reading
    FILE *file = fopen(argv[1], "r");
    
	data = (char***) malloc(num_data*sizeof(char**));
	assert(data);
	
	current_line = fgets(buffer, BUFFER_SIZE, file);
	
	// getting data lines one by one
    while(current_line){
		
        // read the line, then allocate memory for data		
		
		data[num_data] = (char**) malloc(sizeof(char*));
		assert(data[num_data]);
		
		// looping of function strtok to assign the values to the data
		char* token = strtok(current_line, ",");
		i = 0;
		
		while (token){
			data[num_data][i] = (char*) malloc((MAX_STRING + 1)*sizeof(char));
			assert(data[num_data][i]);
			data[num_data][i] = token;
			token = strtok(NULL, ",");
			i++;
		}
		
		// add to bst node
        parent = bstInsert(parent, data[num_data]);
		
		
		// add 1 prepared space for data in case of a newline is scanned
		data = (char***) realloc(data, (num_data+1)*sizeof(char**));
		assert(data);
		
		// get line for the next value
		num_data++;
        current_line = fgets(buffer, MAX_STRING, file);
    }
    
	// open output file
	FILE *out_file = fopen(argv[2], "w");
    assert(out_file != NULL);
	
	//operate the search function
	search_key(argv[3], parent, out_file, count);

	// close the files and free spaces
    fclose(file);
    fflush(stdout);
	fclose(out_file);
	free_data(data, num_data);
	freeTree(parent);
	return 0;
}


// get the bstNode key string from the line
char* get_key(char* string){
		char* token = strtok(string, ",");
		char* key;
		int i = 0;
		
	// run the loop until key becomes the 16th element of the string, which is PU_Date_time
		while (i<=PU_TIME_ARRAY+1){
			key = token;
			token = strtok(NULL, ",");
			i++;
		}
	
	return key;
}



// search for the data recursively in the bst, given the search key
void search_key(char* input, struct bstNode *t, FILE *out_filename, int count) {

	if (t == NULL){
		not_found(input, out_filename, count);
	}
	
	if(strcmp(get_key(*(t->parent->ndata)), input)==0){
		stage_1_print(input, t->parent, out_filename, count);
	}
	
	if(strcmp(get_key(*(t->parent->ndata)), input) > 0){
		search_key(input, t->left, out_filename, count + 1);
	}
	
	else {
		search_key(input, t->right, out_filename, count + 1);
	}
}

// print out operation for stage 1, going through the linked list
void stage_1_print(char* input, struct listNode *node, FILE *out_filename, int count) {
	
	char* headers[]={VendorID,passenger_count,trip_distance,RatecodeID,store_and_fwd_flag,
				PULocationID,DOLocationID,payment_type,fare_amount,extra,mta_tax,tip_amount,
				tolls_amount,improvement_surcharge,total_amount,PUdatetime,DOdatetime,trip_duration
	};
	
	// loop in case of multiple data with same key
	while (node->next!=NULL) {
		
		fprintf(out_filename, "%s -->", input);
		
		// printing the informations one by one
		for (int i=0; i<=NUM_INFO; i++){
			
			if (i==PU_TIME_ARRAY){	
				// do nothing
			} else {
				fprintf(out_filename," %s: %s ||", headers[i], *(node->ndata)+i);	
			}
			
		}
		
		// end of info
		fprintf(out_filename, "\n");
		printf("%s -->", input);
		printf(" %d", count);
		node=node->next;
		
	}
}

// if no results are found
void not_found(char *input, FILE *out_filename, int count) {
	fprintf(out_filename, "%s -->", input);
	fprintf(out_filename, "NOTFOUND\n");
	printf("%s -->", input);
	printf(" %d", count);
}

// free data after use
void free_data(char ***ndata, int num_data){
	int i,j;
	for (j=0;j<num_data;j++){			
		for (i=0;i<=MAX_STRING;i++){
			free(ndata[j][i]);
		}
		free(ndata[j]);
	}
	free(ndata);
}

