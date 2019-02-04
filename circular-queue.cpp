#include<vector>
#include<cassert>
#include "lest.hpp"

class MyCircularQueue {
  private:
    std::vector<int> _v;
    int _front, _rear, _capacity;

  public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : _front(-1), _rear(-1), _capacity(k) {
      _v.reserve(k); 
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) { 
      if(_front == -1 && _rear == -1) {
        _front = _rear = 0;
        _v[_rear] = value;
        return true;
      }
      if(isFull()) return false;

      _rear = (_rear + 1) % _capacity;
      _v[_rear] = value;
      return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
      if(isEmpty()) {
        return false;
      }
      if(_front == _rear){ 
        _front = _rear = -1;
        return true;
      }
      _front = (_front + 1) % _capacity; 
      return true;
    }

    /** Get the front item from the queue. */
    int Front() {
      if(_front < 0) return -1;
      return _v[_front]; 
    }

    /** Get the last item from the queue. */
    int Rear() {
      if(_rear < 0) return -1;
      return _v[_rear];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
      return _front == -1 && _rear == -1; 
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
      return (((_rear + 1) % _capacity) == _front);
    }
};

const lest::test tests[] = {
    CASE("queue success") {
      MyCircularQueue* circularQueue = new MyCircularQueue(3); // set the size to be 3
      EXPECT(circularQueue->enQueue(1));  // return true
      EXPECT(circularQueue->enQueue(2));  // return true
      EXPECT(circularQueue->enQueue(3));  // return true
      EXPECT(!circularQueue->enQueue(4));
      EXPECT(circularQueue->Rear() == 3);  // return 3
      EXPECT(circularQueue->isFull());  // return true
      EXPECT(circularQueue->deQueue());  // return true
      EXPECT(circularQueue->enQueue(4));  // return true
      EXPECT(circularQueue->Rear() == 4);  // return 4
    },
    CASE("queue return -1 for front() when queue empty") {
      MyCircularQueue * circularQueue = new MyCircularQueue(6);
      EXPECT(circularQueue->enQueue(6));
      EXPECT(circularQueue->Rear() == 6);
      EXPECT(circularQueue->Rear() == 6);
      EXPECT(circularQueue->deQueue());
      EXPECT(circularQueue->enQueue(5));
      EXPECT(circularQueue->Rear() == 5);
      EXPECT(circularQueue->deQueue());
      EXPECT(circularQueue->Front() == -1);
      EXPECT(!circularQueue->deQueue());
      EXPECT(!circularQueue->deQueue());
      EXPECT(!circularQueue->deQueue());
    }
};

int main(int argc, char** argv){ 
  return lest::run(tests, argc, argv);
}
