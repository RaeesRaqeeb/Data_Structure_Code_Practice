#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PriorityTask {
public:
    string taskName;
    int priority;

    PriorityTask(string name, int prio) : taskName(name), priority(prio) {}
};

class PriorityQueue {
private:
    vector<PriorityTask> heap;

    // Helper function to maintain the heap property by "bubbling up"
    void heapifyUp(int index) {
        if (index <= 0) return;
        int parent = (index - 1) / 2;
        if (heap[index].priority > heap[parent].priority) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    // Helper function to maintain the heap property by "bubbling down"
    void heapifyDown(int index) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap.size() && heap[leftChild].priority > heap[largest].priority) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].priority > heap[largest].priority) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert a new task into the priority queue
    void insert(string taskName, int priority) {
        PriorityTask newTask(taskName, priority);
        heap.push_back(newTask);
        heapifyUp(heap.size() - 1);
    }

    // Remove and return the highest priority task from the priority queue
    PriorityTask extractMax() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        PriorityTask maxTask = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxTask;
    }

    // Return the highest priority task without removing it
    PriorityTask peek() const {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        return heap[0];
    }

    // Check if the priority queue is empty
    bool isEmpty() const {
        return heap.empty();
    }

    // Display the elements of the priority queue
    void display() const {
        for (const auto& task : heap) {
            cout << "Task: " << task.taskName << ", Priority: " << task.priority << endl;
        }
    }
};

int main() {
    PriorityQueue pq;

    // Insert tasks into the priority queue
    pq.insert("Task 1", 2);
    pq.insert("Task 2", 4);
    pq.insert("Task 3", 1);
    pq.insert("Task 4", 5);
    pq.insert("Task 5", 3);
    pq.insert("Task 6", 1);

    // Display the priority queue
    cout << "Priority Queue:" << endl;
    pq.display();

    // Extract the highest priority task
    cout << "\nExtracting highest priority task:" << endl;
    PriorityTask maxTask = pq.extractMax();
    cout << "Task: " << maxTask.taskName << ", Priority: " << maxTask.priority << endl;

    // Display the priority queue after extraction
    cout << "\nPriority Queue after extraction:" << endl;
    pq.display();

    return 0;
}