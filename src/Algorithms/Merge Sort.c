#include<stdlib.h>
#include<stdio.h>
#include <time.h>
/*Mohann Scarlett
*991616041
*Friday, Dec 3, 2021
*Program to use an array while non-sorted to find distinct elements in the array, and the same again but while using a sorting algorithm on the array
*const int N is input size for array (Value assigned at Run-time)
*/


//Used for troubleshooting
/*void printArrayElements(int A[], int arrsize){
    for (int i = 0; i < arrsize; i++)
        printf("%d ", A[i]);
    puts(" ");
}*/

/*Function to sort an array A in ascending order
*@PARAM A Is the array that will be partitioned into halves, and rebuilt with the partitioned halves in order
*@PARAM minIndex is the lowest index in the array A
*@PARAM mid is the midpoint of array A
*@PARAM maxIndex is the highest index in the array A
*@RETURN void*/
void merge(int A[], int minIndex, int mid, int maxIndex){
    int sizeOfLeft = mid - minIndex + 1; //size of left temp array 
    int sizeOfRight =  maxIndex - mid; //size of right temp array 
  
    //Partition array A into temporary arrays
    int tempLeft[sizeOfLeft];// hold information from first half of A
	int tempRight[sizeOfRight]; // hold information from second half of A
  
    //insert information from first half of A to tempLeft
    for (int i = 0; i < sizeOfLeft; i++)
        tempLeft[i] = A[minIndex + i];
    
    //insert information from second half of A to tempRight
	for (int i = 0; i < sizeOfRight; i++)
        tempRight[i] = A[mid + 1+ i];
  
    //temporary arrays will be added to array A using indexes below
    int tempLeftIniIndex = 0; // Initial index of first subarray
    int tempRightIniIndex = 0; // Initial index of second subarray
    int k = minIndex; // Initial index of merged subarray
    
    /*While tempLeft and tempRight both have indexs to check over
    *If tempLeft holding the first half of A holds information starting from its starting index that is greater than  tempRight at its initial inndex
    *THEN add the information from tempLeft to array A at initial index of A
    *OTHERWISE do the opposite
	*/
    while (tempLeftIniIndex < sizeOfLeft && tempRightIniIndex < sizeOfRight){
        if (tempLeft[tempLeftIniIndex] <= tempRight[tempRightIniIndex]){
            A[k] = tempLeft[tempLeftIniIndex];
            tempLeftIniIndex++;
        }
        else{
            A[k] = tempRight[tempRightIniIndex];
            tempRightIniIndex++;
        }
        k++;
    }
    //If above loop ends before checking all indexs of tempLeft, check over the remaining and add them to A
    while (tempLeftIniIndex < sizeOfLeft){
        A[k] = tempLeft[tempLeftIniIndex];
        tempLeftIniIndex++;
        k++;
    }
  
    //If above loop ends before checking all indexs of tempRight, check over the remaining and add them to A
    while (tempRightIniIndex < sizeOfRight){
        A[k] = tempRight[tempRightIniIndex];
        tempRightIniIndex++;
        k++;
    }
}

/*Function to sort an array A in ascending order
*@PARAM A the array that will sorted/ordered using merge sort
*@PARAM minIndex is the lowest index in the array A
*@PARAM maxIndex is the highest index in the array A
*@RETURN void*/
void mergeSort(int A[], int minIndex, int maxIndex){
    if (minIndex < maxIndex){

        int mid = minIndex+(maxIndex-minIndex)/2;// midpoint of A
  
        //break down array A
        mergeSort(A, minIndex, mid);
        mergeSort(A, mid+1, maxIndex);
  
        merge(A, minIndex, mid, maxIndex);
    }
}

/*Function to find number of distinct elements in unsorted array
*@PARAM A is array that number of distinct values are being counted in
*@PARAM arrsize is the size of the array A
*@RETURN number of distinct elements in A*/
int findDistintValuesWithoutSort(int A[], int arrsize) {
		int duplicates = 0;
		int distinct = 0;
		for(int i = 0; i < arrsize; i++) {
			duplicates = 0;
			//check all elements in front of a[i] to see if a duplicate exists
			for(int j = i+1; j < arrsize; j++) {
				if(A[i] == A[j]) {
				duplicates++;	
				}
			}
			//check all elements behind of a[i] to see if a duplicate exists
			for(int j = i-1; j >= 0; j--) {
				if(A[i] == A[j]) {
				duplicates++;	
				}
			}
			if(duplicates == 0) {
				distinct++;
			}
		}
		return distinct;
	}
	
/*Function to find number of distinct elements in sorted array
*@PARAM A is array that number of distinct values are being counted in
*@PARAM arrsize is the size of the array A
*@RETURN number of distinct elements in A
*/
int findDistintValuesWithSort(int A[], int arrsize) {
		int distinct = 0;
		if(arrsize == 1){
			return 1;
		}
		mergeSort(A, 0, arrsize - 1);
		for (int i = 1; i < arrsize; i++) {
  		if ((A[i] != A[i - 1]) && (A[i] != A[i + 1])) {
    	distinct++;
  			}
		}
		return distinct;
	}


int main(){
	const int N; //INPUT size of array 
	puts("Please enter size of the array: ");
	scanf("%d", &N);
    int generateValues[N]; //Array with input size N
    
	//Initialize random values between 0 and N-1 for all indexs in array
	for(int i = 0; i < N; i++){
    generateValues[i] = (rand()%N+1); 
	}
  	
  	//Find all distinct elements in the array while unsorted and print the time taken to do this
    puts("\nDistinct element amount by unsorted algoirthm:");
    clock_t withoutSortedStartTime = clock(); //start time to find distinct elements without sort
    printf("%d\n\n", findDistintValuesWithoutSort(generateValues, N));
    clock_t withoutSortedEndTime = clock();//end time to find distinct elements without sort
    double seconds = (double)(withoutSortedEndTime - withoutSortedStartTime) / CLOCKS_PER_SEC; //Print time taken1
  
  	//Find all distinct elements in the array while using a sorting algorithm and print the time taken to do this
    puts("Distinct element amount by sorted algoirthm:");
	clock_t withSortedStartTime = clock(); //start time to find distinct elements with sort
	printf("%d\n\n", findDistintValuesWithSort(generateValues, N));
	clock_t withSortedEndTime = clock();//end time to find distinct elements with sort
	double secondsTwo = (double)(withSortedEndTime - withSortedStartTime) / CLOCKS_PER_SEC; //Print time taken
	
	printf("Time taken to find distinct elements with input size %d when array IS NOT sorted is: %.10lf seconds\n", N, seconds);
	printf("Time taken to find distinct elements with input size %d when array IS sorted is: %.10lf seocnds", N, secondsTwo);
}
