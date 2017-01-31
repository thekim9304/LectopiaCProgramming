#include "liststack.h"
#include <stdio.h>
#include <assert.h>

void printInt(DataType *p);

int main()
{
	Stack stL, stR;     /* 스택 생성*/
	FILE *fp;
	char data;
	int input, countOder, i;

	initStack(&stL);
	initStack(&stR);

	fp = fopen("c:\\data\\editor2.txt", "rt");
	assert(fp != NULL);

	while ((input = fgetc(fp)) != '\n')
		push(&stL, input);

	fscanf(fp, "%d", &countOder);

	while ((input = fgetc(fp)) != EOF){
		if (input != '\n'){
				switch (input) {
				case 'L':
					if (isStackEmpty(&stL) == TRUE)
						break;
					pop(&stL, &data);
					push(&stR, data);
					break;
				case 'D':
					if (isStackEmpty(&stR) == TRUE)
						break;
					pop(&stR, &data);
					push(&stL, data);
					break;
				case 'B':
					if (isStackEmpty(&stL) == TRUE)
						break;
					pop(&stL, &data);
					break;
				case 'P':
					fgetc(fp);
					input = fgetc(fp);
					push(&stL, input);
				};
		}
	}

	while (isStackEmpty(&stL) != TRUE)
	{
		pop(&stL, &data);
		push(&stR, data);
	}
	printStack(&stR, printInt);

	destroyStack(&stL);
	destroyStack(&stR);
}

void printInt(DataType *p)
{
	printf("%c", *p);
}