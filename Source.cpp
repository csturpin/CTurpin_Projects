#include<iostream>
#include<string>

using namespace std;

struct ListNode {
	string data;
	ListNode* next;
};

class WordList {
	ListNode *start = 0;
	int node_count = 0;
	bool reversed = false;

public:
	void add(string w) {
		ListNode *toadd = new ListNode;
		toadd->data = w;
		toadd->next = 0;

		if (!start) {
			start = toadd;
			return;
		}
		
		ListNode *place = start;
		ListNode *last = 0;
		
		if (!reversed) {
			while (place && place->data < toadd->data) {
				if (place->data == w)
					return;
				
				else {
					last = place;
					place = place->next;
				}
			}
		}

		else {
			while (place && place->data > toadd->data) {
				if (place->data == w)
					return;
				
				else {
					last = place;
					place = place->next;
				}
			}
		}

		if (place && place->data == w) {
			delete toadd;
			return;
		}

		if (last)
			last->next = toadd;

		if (!last)
			start = toadd;

		toadd->next = place;
	}
	
	void remove(string w) {
		ListNode *place = start;
		ListNode *prevPlace = start;

		if (!start)
			return;

		if (start->data == w) {
			start = start->next;
			delete place;
		}
		
		else {
			while (place && place->data != w) {
				prevPlace = place;
				place = place->next;
			}

			if (place->data == w) {
				prevPlace->next = place->next;
				delete place;
			}
		}
	}

	void print() {
		ListNode *place = start;
		cout << "[";
		
		while (place) {
			cout << place->data << ", ";
			place = place->next;
		}
		
		cout << "\b\b]\n";
	}

	int getLength() {
		int length = 0;
		ListNode *place = start;

		while (place) {
			place = place->next;
			length++;
		}

		return length;
	}

	int find(string w){
		int index = 0;
		ListNode *place = start;

		while (place) {
			if (place->data == w) {
				return index;
			}

			else {
				index++;
				place = place->next;
			}
		}

		return -1;
	}

	bool reverseList(){
		ListNode *prevPlace, *place, *nextPlace;
		prevPlace = 0;
		place = start;
		
		while (place) {
			nextPlace = place->next;
			place->next = prevPlace;
			prevPlace = place;
			place = nextPlace;
		}

		start = prevPlace;
		reversed = !reversed;

		return reversed;
	}

	~WordList() {
		ListNode *place = start, *next;
		
		while (place) {
			next = place->next;
			delete place;
			place = next;
		}
	}
};

int main() {
	WordList names;
	names.add("Gandalf");
	names.add("Frodo");
	names.add("Sam");
	names.add("Aragorn");
	names.add("Boromir");
	names.add("Pippin");
	names.add("Gimli");
	names.add("Legolas");
	names.add("Merry");
	names.print();

	cout << "\n";
	cout << "Gandalf: " << names.find("Gandalf") << endl;
	cout << "Aragorn: " << names.find("Aragorn") << endl;
	cout << "Sauron: " << names.find("Sauron") << endl;
	cout << "Gimli: " << names.find("Gimli") << endl;
	cout << "Legolas: " << names.find("Legolas") << endl;
	cout << "Saruman: " << names.find("Saruman") << "\n\n";

	cout << "Length: " << names.getLength() << endl;
	names.remove("Gimli");
	cout << "Length: " << names.getLength() << "\n\n";
	names.print();
	names.reverseList();
	names.print();
	names.add("Elrond");
	
	names.print();
	names.add("Elrond");
	names.add("Gandalf");
	names.print();
	names.reverseList();
	names.add("Galadriel");
	names.add("Galadriel");
	names.add("Aragorn");
	names.print();
	names.remove("Legolas");
	names.remove("Boromir");
	names.remove("Merry");
	names.print();
	cout << "\nLength: " << names.getLength() << "\n\n";

	system("pause");
	return 0;
}