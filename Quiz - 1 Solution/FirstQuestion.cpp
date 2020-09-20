//#include<iostream>
//using namespace std;
//
//void swap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void sort(int * & arr, int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (arr[i] < arr[j])
//				swap(arr[i], arr[j]);
//		}
//	}
//}
//
//void minimumPair(int* arr, int n) {
//	if (n > 1) {
//		sort(arr, n);
//		cout << "Minimum Difference is: " << arr[1] - arr[0] << endl;
//		cout << "Minimum Pair is: " << arr[1] << "   " <<arr[0] << endl;
//	}
//}
//
//void maximumPair(int* arr, int n) {
//		sort(arr, n);
//		cout << "Maximum Difference is: " << arr[n-1] - arr[0] << endl;
//		cout << "Maximum Pair is: " << arr[n-1] << "   " << arr[0] << endl;
//}
//
//int main()
//{
//	int n;
//	cout << "Enter the Size of Array: ";
//	cin >> n;
//	int* arr;
//	if (n > 0) {
//		arr = new int[n];
//		for (int i = 0; i < n; i++) {
//			cout << "Enter the "<< i <<" Element: ";
//			cin >> arr[i];
//		}
//		minimumPair(arr, n);
//		maximumPair(arr, n);
//	}
//
//	
//	return 0;
//}
