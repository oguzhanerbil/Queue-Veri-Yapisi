#include <iostream>

using namespace std;

class QueueNode {
public:
	int data;
	// Bu de�i�ken bir pointer de�i�kendir. QueueNode s�n�f�n�n adresini saklar.
	// & operat�r� ile de adres al�nabilir.
	QueueNode* next;
	QueueNode(const int& data = 0,QueueNode* next = NULL) : data(data),next(next){}
};
class Queue {

	QueueNode* root;
	public:
		Queue() : root(NULL){}
		bool isEmpty()const { return root == NULL; }
		// Kuyru�a kabul etme fonksiyonu
		void enqueue(const int& value) {
			if (isEmpty()) 
				root = new QueueNode(value);
			else {
				QueueNode* tmp = root;
				while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = new QueueNode(value);
			}
			
		}

};
int main() {
	Queue q;
	cout << q.isEmpty() << endl;
	q.enqueue(10);
	cout << q.isEmpty() << endl;
	return 0;
}