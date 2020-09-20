#ifndef SET_H
#define SET_H

void createSet(int** set, int n);
bool addElement(int* set, int* noe, int &capacity, int element);
bool removeElement(int* set, int* noe, int &capacity, int element);
bool searchElement(int* set, int noe, int element);
void displaySet(int* set, int noe);
int searchElementPosition(int* set, int noe, int element);
bool isEmpty(int noe);
bool isFull(int noe, int capacity);
int* calcIntersection(int* setA, int* setB, int setANOE, int setBNOE, int* newSetNoe, int* newSetCapcity);
int isSubset(int* setA, int* setB, int setANOE, int setBNOE);
void reSize(int** setA, int* setANOE, int* setACapacity, int newSize);
void displayPowerSet(int* set, int noe);
void creatClone(int* sourceSet, int sourceNoe, int sourceCapacity, int** targetSet, int* targetNoe, int* targetCapacity);
void deallocateSet(int** set);
int getCommonElements(int* setA, int* setB, int setANOE, int setBNOE);


#endif