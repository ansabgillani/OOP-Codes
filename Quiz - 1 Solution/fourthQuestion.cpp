//#include<iostream>
//using namespace std;
//
//void swap(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void sort(int*& arr, int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (arr[i] < arr[j])
//				swap(arr[i], arr[j]);
//		}
//	}
//}
//
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
//			cout << "Enter the " << i << " Element: ";
//			cin >> arr[i];
//		}
//		sort(arr, n);
//		cout << "All Elements that have atleast 2 greater elements: ";
//		for (int i = 2; i < n; i++) {
//			cout << arr[i] << "   ";
//		}
//	}
//	return 0;
//}
