//start your code here
//got the swap and sort methods from:
//https://www.geeksforgeeks.org/c-program-for-bubble-sort/
//as well as help for printing the array
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

struct IntArray {

	int Length;
	int *DataPTR;

};

enum EXIT_CODES {

	INVALID_POINTER = -1,
	BAD_DATA = -2
};


struct IntArray *mallocIntArray(int size) { //NEED TWO MALLOC CALLS

	struct IntArray *returnValue = (struct IntArray*) malloc(sizeof(struct IntArray)); //allocate 1 structure on the heap
	returnValue->Length = size; //initialize size value
	returnValue->DataPTR =  (int*) malloc (sizeof(int) * size); //alocate N*integers on the heap
	return returnValue;
}


void IntArray_Free(struct IntArray **ptr)
{
	
	for(int i=0; i < (*ptr)->Length; i++)			// un-init all memory to 0's.
	{
		(*ptr)->DataPTR[i] = 0;
	}
	free((*ptr)->DataPTR);			// de-allocate the array of integers.
	(*ptr)->DataPTR =0;			// set the pointer to null.
	(*ptr)->Length =0;			// set the size to 0.
	free((*ptr));				// free the struct pointer.
	(*ptr) = 0;				// set value of the passed in pointer to null.
	

}


int ParseInt(char *data,int length)
{
	int position =0;			// variable to keep track of current index.
	char item =0;				// value at the current index.
	int value =0;		// final value to return.
	int negative=0;				// flag for signed values.

	if(data == NULL)
	{
		fprintf(stderr,"Invalid Data Pointer.\n");
		exit(INVALID_POINTER);
	}
	if(data[position] == '-')		// check for optional signed value, do not inc
	{
		negative = -1;			// set the flag and increment the index.
		position++;
	}else if(data[position] == '+')
	{
		position++;// do nothing, + has no operation when consumed. 
	}
	for(; position < length; position++)		// loop through all of the characters.
	{
		item = data[position];			// get the current char in the array.

		switch(item)
		{
		case '0':
			value = value * 10;	 // shift answer left,
			value = value;
			break;				// augment with 0.
		case '1':
			value = value * 10;   // shift answer left
			value = value + 1;   // augment by 1
			break;
		case '2':
                        value = value * 10;   // shift answer left
                        value = value + 2;   // augment by 2
                        break;
		case '3':
                        value = value * 10;   // shift answer left
                        value = value + 3;   // augment by 3
                        break;
		case '4':
                        value = value * 10;   // shift answer left
                        value = value + 4;   // augment by 4
                        break;
		case '5':
                        value = value * 10;   // shift answer left
                        value = value + 5;   // augment by 5
                        break;
		case '6':
                        value = value * 10;   // shift answer left
                        value = value + 6;   // augment by 6
                        break;
                case '7':
                        value = value * 10;   // shift answer left
                        value = value + 7;   // augment by 7
                        break;
                case '8':
                        value = value * 10;   // shift answer left
                        value = value + 8;   // augment by 8
                        break;
                case '9':
                        value = value * 10;   // shift answer left
                        value = value + 9;   // augment by 9
                        break;
		case '\r':				// return, newline, and end of line, do nothing.
		case '\n':
		case 0:
			break;
		case ' ':
		default:				// all other input is an error.
			fprintf(stderr,"Error/Invalid Data input:%c\n",item);
			exit(BAD_DATA);
			break;
		}
	}
	if(negative == -1)					// take the 2's compliment of the bin number.
	{
		value = value * negative;
	}
	return value;
}

int readInt(FILE *ptr) {

        char buffer[BUFFER_SIZE];                       // local array to store characters.
        int i = 0;
        for(i=0; i < BUFFER_SIZE;i++)          // zero the array.
        {
                buffer[i] =0;
        }

        char c = 0;
        i = 0;
        do
        {
                c=getc(ptr);
                buffer[i++] = c;
        }
        while((c != EOF) && (c != '\n'));

        return ParseInt(buffer,strlen(buffer));
}

int readIntArray(struct IntArray *array){

	for(int i = 0; i < array->Length; i++) {

          printf("\nEnter int:");
          int temp = readInt(stdin);
          array->DataPTR[i] = temp;
        }
}

void swap(int *xp, int *yp) {
	
	//swap inputs values stored at the xp and yp pointers
//	printf("world");
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
	
}


void sortIntArray(struct IntArray *array) {

	for(int i = 0; i < array->Length-1; i++) { 
		for(int j = i+1; j < array->Length; j++ ) {
			if (array->DataPTR[i] > array->DataPTR[j]); {
				swap(&(array->DataPTR[i]), &(array->DataPTR[j]));	
			}

		}
	}


}


void printIntArray(struct IntArray *array) { //prints array "[1,3,4,5,6]"
	
	printf("[ ");
	//loop through each item and print the elements in the array
	for(int i = array->Length - 1; i >= 0; i--) {
		printf("%d ", array->DataPTR[i]);
	}
	printf("]\n");
}


int main(void) {

	int count;
	fprintf(stdout, "Enter length of array: "); 	 //local variable to store count
	count = readInt(stdin);
	struct IntArray *test = mallocIntArray(count);	//allocate a IntArray of size count
	readIntArray(test);
	sortIntArray(test);
	printIntArray(test);

	IntArray_Free(&test);
	return 0;
}
