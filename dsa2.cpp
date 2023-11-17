#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int partition(vector<int> &arr, int l, int h) {
    int pivot = arr[l];
    int i = l;
    int j = h;
    while (i < j) {
        while (arr[i] <= pivot && i < h) {
            i++;
        }
        while (arr[j] >= pivot && j > l) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

int getrandompivot(int l, int h) {
    return l + rand() % (h - l + 1);
}

int random_partition(vector<int> &arr, int l, int h) {
    int randomindex = getrandompivot(l, h);

    swap(arr[l], arr[randomindex]);
    int pivot = arr[l];
    int i = l + 1;
    int j = h;
    while (i <= j) { // Change here: Use <= instead of <
        while (arr[i] <= pivot && i <= h) { // Change here: Use <= instead of <
            i++;
        }
        while (arr[j] >= pivot && j > l) {
            j--;
        }
        if (i <= j) { // Change here: Use <= instead of <
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void rquicksort(vector<int> &arr, int l, int h) {
    if (l < h) {
        int pindex = random_partition(arr, l, h);
        rquicksort(arr, l, pindex - 1);
        rquicksort(arr, pindex + 1, h);
    }
}

void quicksort(vector<int> &arr, int l, int h) {
    if (l < h) {
        int pindex = partition(arr, l, h);
        quicksort(arr, l, pindex - 1);
        quicksort(arr, pindex + 1, h);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array to be sorted: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    rquicksort(v, 0, n - 1);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}



/*
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int partition(vector<int> &arr, int l, int h) {
    int pivot = arr[l];
    int i = l;
    int j = h;
    while (i < j) {
        while (arr[i] >= pivot && i < h) { // Change here: Use >= instead of <=
            i++;
        }
        while (arr[j] <= pivot && j > l) { // Change here: Use <= instead of >=
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

int getrandompivot(int l, int h) {
    return l + rand() % (h - l + 1);
}

int random_partition(vector<int> &arr, int l, int h) {
    int randomindex = getrandompivot(l, h);

    swap(arr[l], arr[randomindex]);
    int pivot = arr[l];
    int i = l + 1;
    int j = h;
    while (i <= j) { // Change here: Use <= instead of <
        while (arr[i] >= pivot && i <= h) { // Change here: Use >= instead of <=
            i++;
        }
        while (arr[j] <= pivot && j > l) { // Change here: Use <= instead of >=
            j--;
        }
        if (i <= j) { // Change here: Use <= instead of <
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void rquicksort(vector<int> &arr, int l, int h) {
    if (l < h) {
        int pindex = random_partition(arr, l, h);
        rquicksort(arr, l, pindex - 1);
        rquicksort(arr, pindex + 1, h);
    }
}

void quicksort(vector<int> &arr, int l, int h) {
    if (l < h) {
        int pindex = partition(arr, l, h);
        quicksort(arr, l, pindex - 1);
        quicksort(arr, pindex + 1, h);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array to be sorted: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    rquicksort(v, 0, n - 1);
    cout << "The sorted array in descending order is: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}








*/