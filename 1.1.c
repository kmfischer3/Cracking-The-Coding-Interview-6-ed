/*
 ============================================================================
 Name        : 1.1.c
 Author      : Kristina Fischer
 Description : Solution 1.1 from Cracking the Coding Interview (v6)
 
 Problem : 	Implement an algorithm to determine if a string has all unique
		characters if you cannot use additional data structures
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int repeatedChars(char str[20]) {

        int ret = 0;

        int i;
        for (i = 0; i < strlen(str)-1; i++) {
                char c1 = str[i];

                int j;
                for (j = i+1; j < strlen(str); j++) {
                        char c2 = str[j];
                        if (c1 == c2) {
                                ret = 1;
                        }
                }
        }

        return ret;
}

int main(void) {
	
	char str[20];
	
	printf( "Enter a string (max 20 char) :");
	fgets( str, 20, stdin );
	if (strlen(str) > 1) {
		int i = repeatedChars(str);
		if ( i == 1 ) {
			printf("\n--That string has repeated char(s)\n");
		} else {
			printf("\n--That string does NOT have any repeated chars\n");
		}
	} else {
		printf("Empty string does not have any repeated chars.\n");
	}

	return EXIT_SUCCESS;
}
