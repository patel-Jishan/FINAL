#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val):data(val), next(nullptr) {}
};


class LinkedList {
    Node* head;
public:
    LinkedList():head(nullptr) {}

    void insert(int val) {
        Node* newNode=new Node(val);
        if (!head)head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << val << " into linked list."<<endl;
    }

    void display() {
        if (!head) {
            cout << "Linked list is empty."<<endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size())
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}


int p(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; ++j)
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = p(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    LinkedList list;
    vector<int> array;
    int choice;

    do {
        cout << "--- Menu ---"<<endl;
        cout << "1. Insert into Linked List"<<endl;
        cout << "2. Display Linked List"<<endl;
        cout << "3. Enter Array"<<endl;
        cout << "4. Merge Sort"<<endl;
        cout << "5. Quick Sort"<<endl;
        cout << "6. Display Array"<<endl;
        cout << "7. Binary Search"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to insert: ";
                cin >> val;
                list.insert(val);
                break;
            }
            
            case 2:
                list.display();
                break;
            case 3: {
                int n;
                cout << "Enter size of array: ";
                cin >> n;
                array.resize(n);
                cout << "Enter array elements:\n";
                for (int i = 0; i < n; ++i) cin >> array[i];
                break;
            }
            case 4:
                mergeSort(array, 0, array.size() - 1);
                cout << " Merge Sort."<<endl;
                break;
            case 5:
                quickSort(array, 0, array.size() - 1);
                cout << "Quick Sort."<<endl;
                break;
            case 6:
                cout << "Array: ";
                for (int val : array) cout << val << " ";
                cout << endl;
                break;
            case 7: {
                int key;
                cout << "Enter value to search: ";
                cin >> key;
                int result = binarySearch(array, key);
                if (result != -1)
                    cout << "Value found at index: " << result << endl;
                else
                    cout << "Value not found."<<endl;
                break;
            }
            case 0:
                cout << "Exiting program."<<endl;
                break;
            default:
                cout << "Invalid choice."<<endl;
        }
    } while (choice != 0);

}