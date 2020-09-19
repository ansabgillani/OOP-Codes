#include<iostream>
using namespace std;


void createSet(int * & set, int n);
bool addElement(int * & set, int & noe, int capacity, int element);
bool removeElement(int *& set, int& noe, int capacity, int element);
bool searchElement(int * set, int noe, int element);
void displaySet(int* set, int noe);
int searchElementPosition(int * set, int noe, int element);
bool isEmpty(int noe);
bool isFull(int noe, int capacity);
int* calcIntersection(int * setA, int * setB, int setANOE, int setBNOE, int* newSetNoe, int* newSetCapcity);
int isSubset(int * setA, int * setB, int setANOE, int setBNOE);
void reSize(int*& setA, int& setANOE, int& setACapacity, int newSize);
void displayPowerSet(int* set, int noe);
void creatClone(int* sourceSet, int sourceNoe, int sourceCapacity, int*& targetSet, int& targetNoe, int& targetCapacity);
void deallocateSet(int*& set);




int main() {

	int * setA;
	int capacity=10;
	int noe = 0;
		
	createSet(setA, capacity);


	return 0;
}





void createSet(int *& set, int n) {
	//Create the Array for set
	if (n > 0) {
		if (set != nullptr) {
			//TO DO
		}
		else {
			set = new int[n];
			for (int i = 0; i < n; i++) {
				set[i] = 0;
			}
		}
	}
	else {
		set = nullptr;
	}

}
bool addElement(int*& set, int& noe, int capacity, int element) {
	//Add element in set
	if (set == nullptr) {
		return false;
	}
	else {
		if (isFull(noe, capacity)) {
			return false;
		}
		else {
			if (searchElement(set, noe, element)) {
				return false;
			}
			else {
				if (noe == 0 && element == 0) {
					noe++;
					return true;
				}
				else {
					set[noe] = element;
					noe++;
					return true;
				}
			}
		}
	}
}

void swap(int & a, int & b) { //a=1 //b=1
	int temp = a; //temp=1
	a = b; //a=1
	b = temp; //b=1
	//a=1 b=1
}

bool removeElement(int*& set, int& noe, int capacity, int element) {
	//Remove element from set
	if (set == nullptr) {
		return false;
	}
	else{
		if (isEmpty(noe)) {
			return false;
		}
		else {
			if (searchElement(set, noe, element)) {
				//   [ 1 ] noe = 1
				int position = searchElementPosition(set, noe, element); //position =0
				noe--; //noe=0
				swap(set[noe], set[position]); //set[0] = 1   set[0]=1
				return true;
			}
			else {
				return false;
			}
		}
	}
}


bool searchElement(int* set, int noe, int element) {
	//search element in set
	if (set == nullptr) {
		return false;
	}
	else {
		if (isEmpty(noe)) {
			return false;
		}
		else {
			for (int i = 0; i < noe; i++) {
				if (set[i] == element) {
					return true;
				}
			}
			return false;
		}
	}
}
void displaySet(int* set, int noe) {
	//display contents of set
	if (set == nullptr || isEmpty(noe)) {
		cout << "\t\tSet Not Found\t\t" << endl;
	}
	else {
		cout << "Contents of Set Are: ";
		for (int i = 0; i < noe; i++) {
			cout << set[i] << " : ";
		}
		cout << endl;
	}
}
int searchElementPosition(int* set, int noe, int element) {
	//search element position from set
	if (set == nullptr) {
		return -1;
	}
	else {
		if (isEmpty(noe)) {
			return -1;
		}
		else {
			for (int i = 0; i < noe; i++) {
				if (set[i] == element) {
					return i;
				}
			}
			return -1;
		}
	}


}
bool isEmpty(int noe) {
	//check if empty
	if (noe == 0) {
		return true;
	}
	else return false;
}
bool isFull(int noe, int capacity) {
	//check if full
	if (noe == capacity) {
		return true;
	}
	else return false;
}
int* calcIntersection(int* setA, int* setB, int setANOE, int setBNOE, int* newSetNoe, int* newSetCapcity) {
	//returns intersection set of setA and setB
	int * intersection;
	int intersectionCapacity;
	int intersectionNOE = 0;
	// setANOE>setBNOE
	// setANOE<setBNOE
	// setANOE == setBNOE
	bool flag = false; //true if setANOE<setBNOE
	if (setANOE < setBNOE) {
		intersectionCapacity = setANOE;
		flag = true;
	}
	else {
		intersectionCapacity = setBNOE;
		flag = false;
	}
	createSet(intersection, intersectionCapacity); //{}
	if (flag) {
		for (int i = 0; i < setANOE; i++) {
			if (searchElement(setB, setBNOE, setA[i])) { //setA = {2,3,5,6} //setB = {1,2,3,4} 
				intersection[intersectionNOE] = setA[i]; //intersection = {2,3}     intersectionNOE = 2
				intersectionNOE++;
			}
		}
	}
	else {
		for (int i = 0; i < setBNOE; i++) {
			int element = setB[i];
			if (searchElement(setA, setANOE, element)) {
				intersection[intersectionNOE] = setB[i];
				intersectionNOE++;
			}
		}
	}
	return intersection;
}
int isSubset(int* setA, int* setB, int setANOE, int setBNOE) {
	//Checks if setA is subset of setB
}
void reSize(int*& setA, int& setANOE, int& setACapacity, int newSize) {
	//Increases or decreases the size of the set Array
}
void displayPowerSet(int* set, int noe) {
	//displays power set of set
														// (1<<j) = 1*(2^j)...
	int n = pow(2, noe);								// if( counter & (1<<j)) ???? this a binary shifting statement.
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
void creatClone(int* sourceSet, int sourceNoe, int sourceCapacity, int*& targetSet, int&targetNoe, int& targetCapacity) {
	//clones the current array for set
	if (sourceSet != nullptr) {
		targetCapacity = sourceCapacity;
		createSet(targetSet, targetCapacity);
		targetNoe = sourceNoe;
		for (int i = 0; i < sourceNoe; i++) {
			targetSet[i] = sourceSet[i];
		}
	}
}
void deallocateSet(int*& set) {
	//deletes and deallocates the memory used by set
}
