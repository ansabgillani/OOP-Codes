#include<iostream>
using namespace std;

void relativeSorting(int*& arr, int n) {
	int * result=new int [n];

	int j = 0; // index of result
	for (int i = 0; i < n; i++)
		if (arr[i] >= 0)
			result[j++] =arr[i];
	if (j == n || j == 0)
		return;

	for (int i = 0; i < n; i++)
		if (arr[i] < 0)
			result[j++] = arr[i];

	delete[]arr;
	arr = result;
}


int main()
{
	int n;
	cout << "Enter the Size of Array: ";
	cin >> n;
	int* arr;
	if (n > 0) {
		arr = new int[n];
		for (int i = 0; i < n; i++) {
			cout << "Enter the " << i << " Element: ";
			cin >> arr[i];
		}
		relativeSorting(arr, n);
		for (int i = 0; i < n; i++) {
			cout << arr[i] << "   ";
		}
	}
	return 0;
}
