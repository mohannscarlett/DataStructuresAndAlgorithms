#include <stdio.h>
#include <stdlib.h>
/*
Mohann Scarlett
10/14/2021
Header File containing methods to manipulate possible buffers
*/

//create buffer structure
typedef struct BUFFER {
    int top;
    int counter;
    char data[];
} BUFFER;

BUFFER buff;
int bufferCreated = 0; // check if buffer has been made
int bufferInit = 0;//check if buffer has been initialized
int BUFF_SIZE = 0;// keep track of buffer size

//check buffer size
void size(char data[]){
	int size;
	for(int i = 0; i < buff.top; i++){
		size++;
	}
	puts(" ");
	printf("Size of the stack is : %d", size );
}

//check top element in buffer
char top(char data[]){
	for(int i = 0; i < BUFF_SIZE; i++){
		if(BUFF_SIZE - 1 == i){
			printf("Top of the stack is : %c", data[i]);
		return data[i];
		}
	}
}

//check if buffer is empty
void isEmpty(char data[]){
	if(bufferInit == 1){
		puts("\nStack is not empty");

	} else {
		puts("\nEmpty Stack");

	}
}

//initialize buffer
void initialize(){
    /*printf("\nPlease create buffer values (No more than %d)\n", BUFF_SIZE);
	 scanf("%s", &buff.data);*/
	 if(bufferCreated == 0){
	 	puts("Buffer has not been created yet");
	 }else{
	 printf("Buffer has been initialized!\n");
	 for(int i = 0; i <= buff.top; i++){
		printf("%c", buff.data[i]);
	}
     bufferInit = 1;
	 }
    
}
//create buffer
void createBuffer(){
	printf("Integer number of elements in buffer?: ");
    scanf("%d", &BUFF_SIZE);
    if(BUFF_SIZE <= 0){
    	puts("Not much can be done with a buffer of length 0. Program will terminate try again!");
    	exit(1);
	}
    buff.data[BUFF_SIZE];
    //buff= (int*)malloc( BUFF_SIZE * sizeof(int));
    printf("\nBuffer with size %d has been created!\n", BUFF_SIZE);
    bufferCreated = 1;
    initialize();
}
