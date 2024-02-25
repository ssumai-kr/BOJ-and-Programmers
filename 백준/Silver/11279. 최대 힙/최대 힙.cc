#include <iostream>
#include <vector>
using namespace std;
template <class T>
class MaxHeap {
private:
    T* heap;          // 힙 배열
    int capacity;     // 힙의 용량
    int heapSize;     // 힙에 저장된 요소의 개수

public:
    MaxHeap(int initialCapacity = 10);
    ~MaxHeap();

    void Push(const T& e);
    void Pop();
    const T& Top() const;
    bool IsEmpty() const;
};

template <class T>
MaxHeap<T>::MaxHeap(int initialCapacity) : capacity(initialCapacity), heapSize(0) {
    heap = new T[capacity + 1]; // 인덱스 1부터 사용하기 위해 크기를 capacity + 1로 설정
}

template <class T>
MaxHeap<T>::~MaxHeap() {
    delete[] heap;
}

template <class T>
void MaxHeap<T>::Push(const T& e) {
    if (heapSize == capacity) {
        // 용량이 다 찼을 경우, 더 큰 크기의 배열로 확장
        T* newHeap = new T[2 * capacity + 1];
        for (int i = 1; i <= heapSize; ++i) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
        capacity = 2 * capacity;
    }

    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < e) {
        heap[currentNode] = heap[currentNode / 2];
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template <class T>
void MaxHeap<T>::Pop() {
    if (IsEmpty()) throw "Heap is empty. Cannot delete.";

    heap[1].~T();
    T lastE = heap[heapSize--];

    int currentNode = 1;
    int child = 2;
    while (child <= heapSize) {
        if (child < heapSize && heap[child] < heap[child + 1]) {
            child++;
        }
        if (lastE >= heap[child]) {
            break;
        }
        heap[currentNode] = heap[child];
        currentNode = child;
        child *= 2;
    }
    heap[currentNode] = lastE;
}

template <class T>
const T& MaxHeap<T>::Top() const {
    if (IsEmpty()) throw "Heap is empty.";
    return heap[1];
}

template <class T>
bool MaxHeap<T>::IsEmpty() const {
    return heapSize == 0;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    vector<int> results;
    MaxHeap<int> maxh(N);

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if (n == 0) {
            if (maxh.IsEmpty()) results.push_back(0);
            
            else {
                results.push_back(maxh.Top());
                maxh.Pop();
            }
        }
        else maxh.Push(n);
    }


    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << "\n";
    }
}