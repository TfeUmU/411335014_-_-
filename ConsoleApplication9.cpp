

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
void merge(vector<int>&arr, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = 0;
	vector<int>key;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			key.push_back(arr[i++]);
		else
			key.push_back(arr[j++]);

	}
	while (i <= mid) {
		key.push_back(arr[i++]);
	}
	while (j <= right) {
		key.push_back(arr[j++]);
	}
	for (int p = 0; p < key.size(); p++) {
		arr[left + p] = key[p];
	}
}
void DaC(vector<int>&arr,int left, int right) { //divide and conquer
	if (right <= left)
		return;
	int mid = (left + right) / 2;//divide
	DaC(arr, left, mid);
	DaC(arr, mid + 1, right);//conquer
	
	merge(arr, left, mid, right);

}
int main()
{
	string a;
	getline(cin, a);
	istringstream iss(a);
	vector<int>arr;
	int key;
	while (iss >> key)
		arr.push_back(key);   // 逐一存入

	DaC(arr, 0, arr.size() - 1);

	for (int x : arr)
		cout << x << " ";
	return 0;
}


// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
