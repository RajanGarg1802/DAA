#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int myHeap[MAX];
int sizeHeap = 0;

void heapInsert(int value) {
    if (sizeHeap == MAX) {
        cout << "Heap Overflow\n";
        return;
    }

    int i = sizeHeap;
    myHeap[i] = value;
    sizeHeap++;

    while (i != 0 && myHeap[(i - 1) / 2] < myHeap[i]) {
        swap(myHeap[i], myHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(int i) {
    int maxElement = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < sizeHeap && myHeap[leftChild] > myHeap[maxElement])
        maxElement = leftChild;

    if (rightChild < sizeHeap && myHeap[rightChild] > myHeap[maxElement])
        maxElement = rightChild;

    if (maxElement != i) {
        swap(myHeap[i], myHeap[maxElement]);
        heapify(maxElement);
    }
}

int deleteRoot() {
    if (sizeHeap <= 0) {
        cout << "Heap Underflow\n";
        return -1;
    }

    int root = myHeap[0];
    myHeap[0] = myHeap[sizeHeap - 1];
    sizeHeap--;

    heapify(0);

    return root;
}

void display() {
    for (int i = 0; i < sizeHeap; i++)
        cout << myHeap[i] << " ";
    cout << endl;
}

int main() {

    heapInsert(10);
    heapInsert(30);
    heapInsert(20);
    heapInsert(5);
    heapInsert(40);

    cout << "Heap after insertion:\n";
    display();

    cout << "Deleted root: " << deleteRoot() << endl;

    cout << "Heap after deletion:\n";
    display();

    return 0;
}
