#if 0
#include<stdio.h>
#include<time.h>    // time()
#include<stdlib.h>  // rand(), srand()
void iteratorSelectionSort(int *ary, int n);
void recursiveSelectionSort(int *ary, int n);
void initArray(int *ary, int n), printArray(int *ary, int n);

int  main()
{
	int numberArray[10], arySize;
	arySize = sizeof(numberArray)/sizeof(numberArray[0]);
	srand((unsigned int) time(NULL));

	initArray(numberArray, arySize);
	iteratorSelectionSort(numberArray, arySize);
	printArray(numberArray, arySize);

	initArray(numberArray, arySize);
	recursiveSelectionSort(numberArray, arySize);
	printArray(numberArray, arySize);

	getchar();
	return 0;
}
void iteratorSelectionSort(int *ary, int n)
{
	int i, j, target, temp;

	for (i = 0; i < n - 1; i++)
	{
		target = i;
		for (j = i + 1; j < n; j++)
		{
			if (ary[target] > ary[j])
				target = j;
		}
		temp = ary[target];
		ary[target] = ary[i];
		ary[i] = temp;
	}
}
void recursiveSelectionSort(int *ary, int n)
{
	//int i, j, target, temp;
	int i;
	int target = 0;
	int temp;

	if (n == 1)
		return;
	for (i = 0; i<n; ++i) {
		if (ary[target] > ary[i])
			target = i;
	}
	temp = ary[target];
	ary[target] = ary[0];
	ary[0] = temp;
	recursiveSelectionSort(ary + 1, n - 1);
	/*
	target = i;

	for(j = i + 1; j < n; j++)
		if (ary[target] > ary[n - 1])
		{
			target = n - 1;

			temp = ary[target];
			ary[target] = ary[i];
			ary[i] = temp;
		}
		recursiveSelectionSort(ary + 1, --n);
		*/
}
void initArray(int *ary, int n)
{
	int i;
	for(i=0; i<n; ++i)
		ary[i] = rand() % 20 + 1;
}

void printArray(int *ary, int n)
{
	int i;
	printf("배열 내용 : ");
	for(i=0; i<n; ++i)
		printf("%4d", ary[i]);
	printf("\n");
}
#endif