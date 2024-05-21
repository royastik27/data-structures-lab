/**
 * Linked List
 * AUTHOR: Astik Roy
 * DATE:
**/

#include <stdio.h>

#define SIZE 100

void initialize_list(int info[], int link[], int * start, int * avail)
{
	int i;
	for(i = 0; i < SIZE - 1; ++i)
		link[i] = i + 1;

	link[i] = -1; /* Last node is linked with NULL */

	*start = -1;
	*avail = 0;

	return;
}

void insertAtFirst(int info[], int link[], int * start, int * avail, int item)
{
	if(*avail == -1)
	{
		printf("Overflow!\n");
		return;
	}

	int new = *avail;
	*avail = link[*avail];

	info[new] = item;

	link[new] = *start;
	*start = new;

	return;
}

void insertLoc(int info[], int link[], int * start, int * avail, int loc, int item)
{
	if(*avail == -1)
	{
		printf("Overflow\n");
		return;
	}

	int new = *avail;
	*avail = link[*avail];

	info[new] = item;

	if(loc == -1) /* Insert at first */
	{
		link[new] = *start;
		*start = new;
	}
	else
	{
		link[new] = link[loc];
		link[loc] = new;
	}

	return;
}

void delete(int info[], int link[], int * start, int * avail, int loc, int locp)
{
    if(*start == -1)
    {
        printf("Underflow\n");
        return;
    }

    if(locp == -1)
        *start = link[*start];
    else link[locp] = link[loc];

    link[loc] = *avail;
    *avail = loc;

    return;
}

int search(int info[], int link[], int start, int item)
{
	int ptr;

	for(ptr = start; ptr != -1; ptr = link[ptr])
	{
		if(item == info[ptr])
            return ptr;
	}

	return -1;
}

void traverse(int info[], int link[], int start)
{
	int ptr;

	printf("The list: ");

	for(ptr = start; ptr != -1; ptr = link[ptr])
		printf("%d ", info[ptr]);

	printf("\n");

	return;
}

int main()
{
	int info[SIZE], link[SIZE], start, avail;

	initialize_list(info, link, &start, &avail);

	insertAtFirst(info, link, &start, &avail, 10);
	insertAtFirst(info, link, &start, &avail, 20);
	insertAtFirst(info, link, &start, &avail, 30);

	traverse(info, link, start);

	delete(info, link, &start, &avail, search(info, link, start, 20), search(info, link, start, 30));

	traverse(info, link, start);

	return 0;
}
