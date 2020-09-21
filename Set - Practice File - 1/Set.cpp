#include<iostream>
using namespace std;

#include"Set.h"


void createSet(int** set, int n)
{
	//creates an array for set
	if (set) {
		deallocateSet(set);
	}
	if (n > 0 && !set) {
		*set = new int[n];
		for (int i = 0; i < n; i++) {
			*set[i] = INT_MIN;
		}
	}
}
bool addElement(int* set, int* noe, int &capacity, int element)
{
	//adds an element in the set
	if (set && !searchElement(set, *noe, element))
	{
		if (!isFull(*noe, capacity))
		{
			set[*noe] = element;
			*noe += 1;
			return true;
		}
		else
		{
			reSize(&set, noe, &capacity, capacity * 2);
			set[*noe] = element;
			*noe += 1;
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool removeElement(int* set, int* noe, int &capacity, int element)
{
	//removes an element from the set
	if (!set) {
		return false;
	}
	int j = 0, n = *noe, p;
	p = searchElementPosition(set, *noe, element);
	if (p != -1)
	{
		set[p] = set[*noe - 1];
		*noe = *noe - 1;
		if (*noe == (capacity / 4)) {
			reSize(&set, noe, &capacity, capacity / 2);
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool searchElement(int* set, int noe, int element)
{
	//Check if an element is present in the set
	if (!set) {
		return false;
	}
	int i, pos;
	pos = searchElementPosition(set, noe, element);
	if (pos == -1)
		return false;
	else
		return true;
}
void displaySet(int* set, int noe)
{
	//Displays set on the screen
	if (set == NULL)
	{
		cout << "No Set Found!! " << endl;
	}
	else
	{
		cout << "{ ";
		for (int i = 0; i < noe; i++)
		{
			cout << set[i] << " , ";
		}
		cout << "}" << endl;
	}
}
int searchElementPosition(int* set, int noe, int element)
{
	//returns position of the element in array if present
	if (!set) {
		return false;
	}
	for (int i = 0; i < noe; i++)
	{
		if (set[i] == element)
		{
			return i;
		}
	}
	return -1;
}
bool isEmpty(int noe)
{
	//check if the set is empty
	if (noe == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isFull(int noe, int capacity)
{
	//Check if the set is full
	if (noe == capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int* calcIntersection(int* setA, int* setB, int setANOE, int setBNOE, int* newSetNoe, int* newSetCapcity)
{
	//Returns intersection of two sets
	if (!setA || !setB) {
		return nullptr;
	}
	int common = getCommonElements(setA, setB, setANOE, setBNOE);
	if (common != 0)
	{
		int* newSet;
		*newSetCapcity = (setANOE + setBNOE) - common;
		createSet(&newSet, *newSetCapcity);
		int i, j;
		for (i = 0; i < setBNOE; i++)
		{
			if (!searchElement(setA, setANOE, setB[i]))
			{
				newSet[*newSetNoe] = setB[i];
				*newSetNoe += 1;
			}
		}
		return newSet;
	}
}
int isSubset(int* setA, int* setB, int setANOE, int setBNOE)
{
	//Check if SetB is the subset of SetA or if SetB is the subset of  Set A
	if (!setA || !setB) {
		return -1;
	}
	int count = 0;
	count = getCommonElements(setA, setB, setANOE, setBNOE);
	if (count < setBNOE)
	{
		return 0;
	}
	else if (count < setANOE && count == setBNOE)
	{
		return 1;
	}
	else if (count == setANOE)
	{
		return 2;
	}
}
void reSize(int** setA, int* setANOE, int* setACapacity, int newSize)
{
	//Resizes the set Array
	int* newSet;
	createSet(&newSet, newSize);
	*setACapacity = newSize;
	for (int i = 0; i < *setANOE && i < newSize; i++)
	{
		newSet[i] = (*setA)[i];
	}
	
	deallocateSet(setA);
	*setA = newSet;
}
void displayPowerSet(int* set, int noe)
{
	//Displays power set of a set
								// (1<<j) = 1*(2^j)...
	int n = pow(2, noe);						// if( counter & (1<<j)) ???? this a binary shifting statement.
	cout << "Power Set of the set is:\n{ ";				// this statement compare the binary of counter and the next 1<<j statement bit by bit.
	for (int i = 0; i < n; i++)							// if the bit is set. it prints set[j]. for exp. for 3 elements set. 2^3=8. 3 bit binary.
	{													//	i , 4,2,1			(j , 1<<j)==> (0,1) and (1,2) and (2,4) for j=0,1,2.
														//	0 = 0 0 0	>>	no bit is set, nothing will  be print but empty set.
		for (int j = 0; j < noe; j++)					//	1 = 0 0 1	>>	bit 1 is set for j=0 so set[0] will be printed.		
		{												//	2 = 0 1 0	>>	bit 2 is set for j=1 so set[1] will be printed.
			if (i & (1 << j))							//	3 = 0 1 1	>>  bit 1 and 2 is set for j=0 and j=1 so set[0] and set[1] will be printed.
			{											//  4 = 1 0 0	>>	bit 3 is set for j=2 so set[2] will be printed.
				cout << set[j];							//	5 = 1 0 1	>>  in this way, set[0] and set[2] will be printed here.
			}											//  6 = 1 1 0	>>  set[1] and set[2] will be printed here.
		}												//  7 = 1 1 1	>>  set[0] , set[1] and set[2] will be printed here.
		cout << " , ";									// in this way, using binary shifting notation we will print the
	}													// power sets of a set because power set consists of all subsets of set A.
	cout << "}" << endl;								// No. of elements of Power set is = 2^(no. of elements of set).
}

void creatClone(int* sourceSet, int sourceNoe, int sourceCapacity, int** targetSet, int* targetNoe, int* targetCapacity)
{
	//Create Clone of source Set into Target Set
	*targetNoe = sourceNoe;
	*targetCapacity = sourceCapacity;
	createSet(targetSet, *targetCapacity);
	for (int i = 0; i < sourceNoe; i++)
	{
		(*targetSet)[i] = sourceSet[i];
	}
}

void deallocateSet(int** set)
{
	//Delete the Array Created For Set
	if (set) {
		delete[] * set;
		*set = NULL;

	}
}

int getCommonElements(int* setA, int* setB, int setANOE, int setBNOE)
{
	//Get the Number of Common Elements from Two Sets
	int common = 0;
	for (int i = 0; i < setANOE; i++)
	{
		for (int j = 0; j < setBNOE; j++)
		{
			if (setA[i] == setB[j])
			{
				common++;
			}
		}
	}
	return common;
}