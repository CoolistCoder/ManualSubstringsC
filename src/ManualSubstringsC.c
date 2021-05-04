#include <stdio.h>
#include <stdlib.h>

//demonstration of how to create a substring from a string in C

char* substring(const char* src, unsigned int start, unsigned int end); //creates a substring from a string

int main(void) {
	const int start = 5, end = 30;
	const char* mainstring = "This is a string that will be turned into a substring\n";
	printf("This program is to demonstrate how my substring function works\n");
	printf("The original string: %s", mainstring);
	printf("the substring will begin at character %i and end at character %i, with a null at %i:\n", start, end, end+1);
	char* substr = substring(mainstring, start, end);
	printf("The substring is: %s\n", substr);
	free(substr);

	printf("End of program\n");
	return EXIT_SUCCESS;
}

char* substring(const char* src, unsigned int start, unsigned int end){
	//pre-execution checks
	if (src == NULL){ //spit out a null if there was nothing put n
		return NULL;
	}
	if (start > end){ //start MUST come before end
		return NULL;
	}

	//first, get the length of the string
	unsigned int count = 0; 					//keeps count of the string
	char comparison = src[0]; 					//comparison character
	while (comparison != '\0'){
		comparison = src[count]; //iterate through each character to find the null
		count++;				//++ for each character, even the null
	}
	//once the null is found, we can begin using the count value to make determinations
	if (count == 0){ //string's empty, can't do anything
		return NULL;
	}
	if (end > count-1){ //beyond range, would cause an error if unattended
		return NULL;
	}
	if (start > count-1){ //the start is further than the end
		return NULL;
	}

	//if these checks have been taken care of, we can continue
	const int substr_len = end-start+1;
	count=0;
	char* substr = (char*) malloc(sizeof(char)*substr_len); //this substring will be exactly as long as we need it to be, +1 for null
	for (unsigned int i = start; i<end; i++){ //iterate through each character and copy it to the substr
		substr[count++] = src[i];
	}
	//at the end of the substring, place the null operator
	substr[substr_len-1] = '\0';

	return substr;

}









