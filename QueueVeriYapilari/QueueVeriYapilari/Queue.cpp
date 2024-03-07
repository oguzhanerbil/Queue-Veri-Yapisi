#include <iostream>

using namespace std;

class QueueNode {
public:
	int data;
	// Bu deðiþken bir pointer deðiþkendir. QueueNode sýnýfýnýn adresini saklar.
	// & operatörü ile de adres alýnabilir.
	QueueNode* next;
	QueueNode(const int& data = 0,QueueNode* next = NULL) : data(data),next(next){}
};
class Queue {
	QueueNode* root;
	QueueNode* tail;
	int length;
	public:
		Queue() : root(NULL),tail(NULL), length(0) {}
		bool isEmpty()const { return root == NULL; }
		// Kuyruða kabul etme fonksiyonu
		void enqueue(const int& value) {
			if (isEmpty()) {
				root = new QueueNode(value);
				tail = root;
			}
			else {
				tail->next = new QueueNode(value);
				tail = tail->next;
			};
			length++;
		}
		void dequeue() {
			if (isEmpty()) {
				throw "Error : Queue::dequeue() for queue is empty";
			}
			QueueNode* tmp = root;
			if(root == tail){
				tail = tmp->next;
			}
			root = root->next;
			delete tmp;
			length--;
		}
		void print()const {
			QueueNode* tmp = root;
			while (tmp != NULL) {
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
			cout << endl;
		}
		int size()const {
			return length;
			/*
			QueueNode* tmp = root;
			int counter = 0;
			while (tmp != NULL) {
				counter++;
				tmp = tmp->next;
			}
			return counter;
			*/
		}

};
int main() {
	Queue q;
	cout << q.isEmpty() << endl;
	q.enqueue(10);
	cout << q.isEmpty() << endl;
	q.print();
	q.enqueue(3);
	q.print();
	q.dequeue();
	cout << q.isEmpty() << endl;
	q.print();
	q.dequeue();
	cout << q.isEmpty() << endl;
	q.enqueue(50);
	cout << q.isEmpty() << endl;
	q.print();

	return 0;
}