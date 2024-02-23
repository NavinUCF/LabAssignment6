//Navin Singh COP 3502C
//Lab 6 2/23/2024
#include <stdio.h>
#include <stdlib.h>
//use binary search method this time recursively
int search(int numbers[], int low, int high, int value) 
{
	//if the recursion keeps happening to where the low is bigger than high, means the value is not in the array
	if(low<=high){
		//calculate the mid index to see if the value is at mid index
		int mid;
		mid = (low +high)/2;
		//if it is, simply return mid
		if(numbers[mid]==value)
			return mid;
		//else if the value is less than mid, it means value is in the index below mid, so search again with same low and mid-1 is new high
		else if(value<numbers[mid]){
			return search(numbers, low, mid-1, value);
		}
		//else if the value is greater than mid, value is in index above mid, so search with mid+1 is new low and high is kept the same
		else if(value>numbers[mid]){
			return search(numbers, mid+1, high, value);
		}
	}
	//base case 
	return -1;
	


	
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}