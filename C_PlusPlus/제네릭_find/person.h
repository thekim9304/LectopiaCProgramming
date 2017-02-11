#pragma once

#include <stdio.h>
#include <string.h>

typedef struct _person {
	char name[20];
	int age;
	char phoneNumber[15];
}Person;

void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *));
void inputPerson(Person *per, int count);