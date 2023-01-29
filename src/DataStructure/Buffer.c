#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/*
Mohann Scarlett
10/14/2021
This program creates a buffer and asks the user to preform operations on it
*/


/*
struct buff elements from stack.h package
*/

//insert character into buffer LIFO
void insert(char data[]){
	printf("Insert Element (Only first value of string is counted): ");
	scanf("%s", &data[buff.top]);
	puts(" ");
	buff.top++;
	data[buff.top] = '|';
	printf("CURSOR:");
	for(int i = 0; i <= buff.top; i++){
		printf("%c", data[i]);
	}
}

//insert character into buffer LIFO
void deleteChar(char data[]){
	if(buff.top <= 0){
		buff.top = 0;
		printf("\nThere is no element to delete\n");
		for(int i = 0; i <= buff.top; i++){
		printf("%c", data[i]);
		}
		return;
	} 
	puts(" ");
	buff.top--;
	data[buff.top] = '|';
	printf("CURSOR:");
	for(int i = 0; i <= buff.top; i++){
		printf("%c", data[i]);
	}
}

//attempt to shift other buffer charactrs to the left to make cursor occupy new spot
void left(int k){
	if(buff.top <= 0){
		buff.top = 0;
		printf("\nCan't move to the left anymore\n");
		for(int j = 0; j <= buff.top; j++){
		printf("%c", buff.data[j]);
		}
		return;
	}
	char temp1;
	char temp2;
	puts(" ");
	buff.top - k;
	temp1 = buff.data[buff.top];
	buff.data[buff.top] = '|';
	int counter = 1;
	for(int i = buff.top; i < buff.top+k; i++){
		temp2 = buff.data[buff.top+counter];
		buff.data[buff.top+counter] = temp1;
		counter++;	
	}
	printf("CURSOR:");
	for(int i = 0; i <= buff.top; i++){
		printf("%c", buff.data[i]);
	
	}
}

//attempt to shift other buffer charactrs to the right to make cursor occupy new spot
void right(int k){
	char temp1;
	char temp2;
	puts(" ");
	buff.top + k;
	temp1 = buff.data[buff.top];
	buff.data[buff.top] = '|';
	int counter = 1;
	for(int i = buff.top; i < buff.top+k; i++){
		temp2 = buff.data[buff.top+counter];
		buff.data[buff.top+counter] = temp1;
		counter++;
	
	}
	printf("CURSOR:");
	for(int i = 0; i <= buff.top; i++){
		printf("%c", buff.data[i]);
	
	}
}

//get value of character at cursor
char get(){
	return buff.data[buff.top-1];
}


int main() {
	int choice; // variable for user to choose option on menu
	buff.top = 0; // variable to keep track of end of buffer
	buff.data[0] = '|'; // cursor for user at top of buffer
	int k;
	while(choice != 11){
		puts("\nStack & Buffer operations");
		puts("0: createBuffer");
		puts("1: Insert");
		puts("2: Delete");
		puts("3: Get");
		puts("4: Size");
		puts("5: Right");
		puts("6: Left");
		printf("7: Exit\nChoose option:  ");
		scanf("%d", &choice);
		switch(choice){
			//if a buffer has not been created, none of the other 6 options are available except exit
			case 0: 
			if(bufferCreated == 1){
				puts("\nBuffer has already been created!");
			} else {
			
				createBuffer();
 			}
 			
				break;
			case 1:
				if(bufferCreated == 0){
				puts("\nYou must first create a bufffer!");
				break;
			}
				insert(buff.data);
				break;
			case 2:
				if(bufferCreated == 0){
				puts("\nYou must first create a bufffer!");
				break;
			}
				deleteChar(buff.data);
				break;
			case 3:
				if(bufferCreated == 0){
				puts("\nYou must first create a bufffer!");
				break;
			}
				printf("\nCharacter at cursor position is: {%c}", get());
				break;
			case 4:
				if(bufferCreated == 0){
				puts("\nYou must first create a bufffer!");
				break;
			}	
				size(buff.data);
				break;
			case 5:
				if(bufferCreated == 0){
				puts("\nYou must first create a bufffer!");
				break;
			}	
				k = 0;
				scanf("%d", &k);
				left(k);
				break;
			case 6:
				if(bufferCreated == 0){
				puts("\nYou must first create a bufffer!");
				break;
			}	
				k = 0;
				scanf("%d", &k);				
				right(k);
				break;
			
			case 7:
				exit(1);
			default:
				printf("\nNot a valid option!!!\n");
		}
	}
}
