/****************************************************************************
 File name:  Heap.c
 Author:     chadd williams
 Date:       Nov 16, 2023
 Class:      CS 300
 Assignment: In Class Function Pointer Lab
 Purpose:    Practice with arrays, function pointers
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1024

// TODO 1: Build a typedef for a function pointer that will accept two
// integers and return a bool

// typedef 


typedef struct Heap {
	int aData[SIZE];
	int itemsInHeap;

	// TODO 2: add a function pointer to the Heap struct using the
	// type defined in TODO 1

} Heap;



// TODO 0: Write the functions greaterThanInt() and lessThanInt() that
// each accept two integers and return a bool to indicated if the 
// left int is greaterThan/lessThan the right int.
// bool greaterThanInt (int left, int right);
// bool lessThanInt (int left, int right);



 
/****************************************************************************
 Function:    	swap
 
 Description: 	Swap the two ints pointed to by the parameters

 Parameters:  	pLeft - pointer to an int
 								pRight - pointer to an int
 
 Returned:    	None
 ****************************************************************************/
void swap (int *pLeft, int *pRight)
{
	int tmp = *pLeft;

	*pLeft = *pRight;

	*pRight = tmp;
}

/****************************************************************************
 Function:    	parent
 
 Description: 	Calculate the parent of an index in a complete binary tree

 Parameters:  	index - the child index

 Returned:    	int - the parent index
 ****************************************************************************/
int parent(int index)
{
	return (index - 1) / 2;
}

/****************************************************************************
 Function:    	shiftUp
 
 Description: 	Heap shift up, move psHeap->aData[psHeap->itemsInHeap] up
								if necessary

 Parameters:  	psHeap - the heap

 Returned:    	None
 ****************************************************************************/
void shiftUp(Heap *psHeap)
{
	int index = psHeap->itemsInHeap;


	// TODO 5: Use the function pointer in the Heap struct to do the
	// comparison in the while test rather than hard coding <

	while ( index > 0 && psHeap->aData[parent(index)] < psHeap->aData[index])
	{
		swap (& (psHeap->aData[parent(index)]), &(psHeap->aData[index]));
		index = parent(index);
	}
}

/****************************************************************************
 Function:    	insertItem
 
 Description: 	Insert item into the heap

 Parameters:  	psHeap - the heap
								item - the int to insert

 Returned:    	None
 ****************************************************************************/
void insertItem (Heap *psHeap, int item)
{
	
	if (psHeap->itemsInHeap < SIZE)
	{
		psHeap->aData[psHeap->itemsInHeap] = item;
	}

	shiftUp(psHeap);
	++psHeap->itemsInHeap;
}

/****************************************************************************
 Function:    	printHeap
 
 Description: 	Print the heap in index order

 Parameters:  	psHeap - the heap

 Returned:    	None
 ****************************************************************************/
void printHeap(Heap *psHeap)
{
	for (int i = 0; i < psHeap->itemsInHeap; ++i)
	{
		printf ("%d - ", psHeap->aData[i]);
	}
}


/****************************************************************************
 Function:    	createHeap
 
 Description: 	Initailize the Heap

 Parameters:  	psHeap - the heap

 Returned:    	None
 ****************************************************************************/
void createHeap(Heap *psHeap)

	// TODO 3: Add a function pointer parameter to createHeap and store
	// that function pointer in the Heap struct.
{
	psHeap->itemsInHeap = 0;
}

/****************************************************************************
 Function:    	main
 
 Description: 	Test the Heap

 Parameters:  	None

 Returned:    	EXIT_SUCCESS
 ****************************************************************************/
int main()
{
	Heap sHeap;
	const int DATA_SIZE = 10;
	int aTheData[] = { 1, 3, 5, 7, 9, 8, 6, 4, 2, 0};


	// TODO 4: Update the createHeap function call to 
	// pass the function lessThanInt as the function pointer

	createHeap (&sHeap);

	for (int i = 0; i < DATA_SIZE; ++i)
	{
		insertItem (&sHeap, aTheData[i]);
	}

	printHeap (&sHeap);

	printf ("\n\n");


	// TODO 6: Uncomment the code below and then pass
	// greaterThanInt as the function pointer to createHeap

/*
	createHeap (&sHeap);

	for (int i = 0; i < DATA_SIZE; ++i)
	{
		insertItem (&sHeap, aTheData[i]);
	}

	printHeap (&sHeap);

	printf ("\n\n");
*/




	return EXIT_SUCCESS;
}