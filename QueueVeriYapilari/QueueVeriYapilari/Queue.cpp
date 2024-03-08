#include <iostream>

using namespace std;

template<class T>
class QueueNode {
public:
	T data;
	// Bu deðiþken bir pointer deðiþkendir. QueueNode sýnýfýnýn adresini saklar.
	// & operatörü ile de adres alýnabilir.
	QueueNode<T>* next;
	QueueNode(const T& data = 0,QueueNode<T>* next = NULL) : data(data),next(next){}
};
template<class T>
class Queue {
	QueueNode<T>* root;
	QueueNode<T>* tail;
	int length;
	void makeEmpty() {
		while (!isEmpty())
			dequeue();
	}
	public:
		Queue() : root(NULL),tail(NULL), length(0) {}
		~Queue() { makeEmpty(); }
		Queue(const Queue<T>& rhs):Queue<T>() { *this = rhs; }
		Queue<T>& operator=(const Queue<T>& rhs) { return assign(rhs); }
		Queue<T>& assign(const Queue<T>& rhs) {
			makeEmpty();
			QueueNode<T>* tmp = rhs.root;
			while (tmp != NULL)
			{
				enqueue(tmp->data);
				tmp = tmp->next;
			}
			return *this;
		}
		bool isEmpty()const { return root == NULL; }
		// Kuyruða kabul etme fonksiyonu
		void enqueue(const T& value) {
			if (isEmpty()) {
				root = new QueueNode<T>(value);
				tail = root;
			}
			else {
				tail->next = new QueueNode<T>(value);
				tail = tail->next;
			};
			length++;
		}
		T front()const {
			if (isEmpty()) {
				throw "Error : Queue::front() for queue is empty";
			}
			return root->data;

		}
		T back() const {
			if (isEmpty()) {
				throw "Error : Queue::back() for queue is empty";
			
			}

			return tail->data;
		}
		void dequeue() {
			if (isEmpty()) {
				throw "Error : Queue::dequeue() for queue is empty";
			}
			QueueNode<T>* tmp = root;
			if(root == tail){
				tail = tmp->next;
			}
			root = root->next;
			delete tmp;
			length--;
		}
		void print()const {
			QueueNode<T>* tmp = root;
			while (tmp != NULL) {
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
			cout << endl;
		}
		int size()const {
			return length;
		}

};

class Musteri {
	string isim;
public:
	Musteri(const string& isim):isim(isim){}
	friend ostream& operator<<(ostream& out, Musteri& m) {
		out << m.isim;
		return out;
	}
};
int main() {
	Queue<Musteri> q;
	cout << q.isEmpty() << endl;
	q.enqueue(Musteri("Kemal"));
	q.enqueue(Musteri("Tekin"));
	q.enqueue(Musteri("Cihat"));
	cout << q.isEmpty() << endl;
	q.print();
	Musteri islemyapilacak = q.front();
	cout << islemyapilacak << endl;
	q.dequeue();
	islemyapilacak = q.front();
	q.print();

	cout << islemyapilacak << endl;
}