dict1: dict1.c structure.c
	gcc -Wall -o dict1 dict1.c structure.c -g
    
 
dict2: dict2.c structure.h
	gcc -Wall -o dict2 dict2.c structure.c -g    
