//#include<iostream>
//using namespace std;
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
//
//		cout << "Array after Shift Right is: ";
//		int temp = arr[n - 1];
//		for (int i = 1; i < n; i++) {
//			arr[i] = arr[i - 1];
//			cout << arr[i] << "  ";
//		}
//		arr[0] = arr[n - 1];
//		cout << arr[0] << endl;
//	}
//	return 0;
//}
