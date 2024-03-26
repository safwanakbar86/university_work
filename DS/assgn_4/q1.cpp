#include <iostream>
#include <vector>
#include <string>
using namespace std;


//Single Linked List for storing list of authors
template <class L>
class List
{
private:
	class Node
	{
	public:
		L data;
		Node* next;
	};
	Node* head;
	Node* tail;

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	void InsertAtEnd(L d)
	{
		Node* temp = new Node;
		temp->data = d;
		temp->next = nullptr;

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}

		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	//Updating author information
	void Update(L d, L t)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == t)
			{
				temp->data = d;
				return;
			}
			temp = temp->next;
		}
	}

	void Print()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->next == nullptr)
				cout << temp->data;

			else
				cout << temp->data << " - ";

			temp = temp->next;
		}
	}
};


//Library class to store book information
class Library
{
	friend ostream& operator << (ostream&, Library&);

private:
	int ISSN;
	string Title;
	int refCopies;
	int issCopies;
	string* authorsList;
	int numberOfAuthors;
	List<string> Authors;

public:
	Library(int issn = 0, string t = "", int r = 0, int i = 0, string* a = 0, int s = 0)
	{
		ISSN = issn;
		Title = t;
		refCopies = r;
		issCopies = i;

		numberOfAuthors = s;
		authorsList = new string[numberOfAuthors];
		for (int loop = 0; loop < numberOfAuthors; loop++)
			authorsList[loop] = a[loop];

		for (int loop = 0; loop < numberOfAuthors; loop++)
			Authors.InsertAtEnd(authorsList[loop]);
	}

	//Equality operator to check ISSN of a book
	bool operator == (int bookISSN)
	{
		return (ISSN == bookISSN);
	}

	//Greater than operator for sorting the linked list according to ISSN of a book
	bool operator > (Library& l)
	{
		return (ISSN > l.ISSN);
	}

	//Dereference operator to update book information
	void operator*()
	{
		int option;
		cout << "\nChange Book Title (1 or 0): ";
		cin >> option;

		if (option == 1)
		{
			cin.ignore();
			getline(cin, Title);
		}

		cout << "Change number of reference copies (1 or 0): ";
		cin >> option;

		if (option == 1)
			cin >> refCopies;

		cout << "Change number of issuable copies (1 or 0): ";
		cin >> option;

		if (option == 1)
			cin >> issCopies;

		cout << "Change author information (1 or 0): ";
		cin >> option;

		if (option == 1)
		{
			for (int loop = 0; loop < numberOfAuthors; loop++)
			{
				cout << "Change name of author " << loop + 1 << " (1 or 0): ";
				cin >> option;
				cin.ignore();

				if (option == 1)
				{
					string temp = authorsList[loop];
					getline(cin, authorsList[loop]);
					Authors.Update(authorsList[loop], temp);
				}
			}
		}
	}
};


//cout operator to display book information
ostream& operator << (ostream& out, Library& l)
{
	out << "ISSN: " << l.ISSN << "\nTitle: " << l.Title << "\nCopies available for reference books: " << l.refCopies << "\nCopies available for issuable books: " << l.issCopies << "\nAuthor(s): ";
	l.Authors.Print();
	return out;
}


template <class D>
class DList
{
private:
	class DNode
	{
	public:
		D data;
		DNode* next;
		DNode* prev;
	};
	DNode* head;
	DNode* tail;

public:
	DList()
	{
		head = new DNode;
		tail = new DNode;

		head->next = tail;
		tail->prev = head;

		head->prev = nullptr;
		tail->next = nullptr;
	}

	void InsertAtEnd(D d)
	{
		DNode* temp = new DNode;
		temp->data = d;

		temp->next = tail;
		temp->prev = tail->prev;

		tail->prev->next = temp;
		tail->prev = temp;

		//Sorting after insertion when more than one data has been inserted
		if (head->next != tail->prev)
			Sort();
	}

	//Sorting after insertion
	void Sort()
	{
		int swapVar;
		DNode* temp1;
		DNode* temp2 = tail;

		do
		{
			swapVar = 0;
			temp1 = head->next;

			while (temp1->next != temp2)
			{
				if (temp1->data > temp1->next->data)
				{
					DNode* temp = temp1;
					temp1 = temp1->next;
					temp1->prev = temp->prev;
					temp->next = temp1->next;
					temp->prev->next = temp1;
					temp->prev = temp1;
					temp1->next = temp;
					swapVar = 1;
				}
				temp1 = temp1->next;
			}
			temp2 = temp1;
		} while (swapVar);
	}

	bool CheckISSN(int bookISSN)
	{
		DNode* temp = head->next;
		while (temp != tail)
		{
			if (temp->data == bookISSN)
				return 1;
			temp = temp->next;
		}
		return 0;
	}

	//Reviewing book information according to ISSN
	bool Review(int bookISSN)
	{
		DNode* temp = head->next;
		while (temp != tail)
		{
			if (temp->data == bookISSN)
			{
				cout << temp->data << endl;
				return 1;
			}
			temp = temp->next;
		}
		return 0;
	}

	//Updating book information according to ISSN
	bool Update(int bookISSN)
	{
		DNode* temp = head->next;
		while (temp != tail)
		{
			if (temp->data == bookISSN)
			{
				*(temp->data);
				return 1;
			}
			temp = temp->next;
		}
		return 0;
	}

	//Deleting book information according to ISSN
	bool Delete(int bookISSN)
	{
		bool flag = false;
		DNode* temp = head->next;
		while (temp != tail)
		{
			if (temp->data == bookISSN)
			{
				flag = true;
				break;
			}
			temp = temp->next;
		}

		if (flag == true)
			if (temp != tail)
			{
				DNode* temp2 = temp;
				temp->prev->next = temp->next;
				temp = temp->next;
				temp->prev = temp2->prev;
				delete temp2;
			}
		return flag;
	}

	//Getting head->next and tail for printing occupied values in hash table
	DNode* getHeadNext()
	{
		return head->next;
	}

	DNode* getTail()
	{
		return tail;
	}

	void Print()
	{
		DNode* temp = head->next;
		while (temp != tail)
		{
			cout << temp->data << endl << endl;
			temp = temp->next;
		}
	}
};


template <class h>
class Hashing
{
private:
	vector<DList<Library>> hashTable;
	int capacity;
	float elements;

	//Rehashing in case of load factor crossing 0.5
	void DoubleCapacity()
	{
		vector<DList<Library>> tempTable(capacity);
		for (int i = 0; i < hashTable.size(); i++)
			tempTable[i] = hashTable[i];

		capacity *= 2;
		hashTable = vector<DList<Library>>(capacity);
		for (int i = 0; i < tempTable.size(); i++)
			hashTable[i] = tempTable[i];
	}

public:
	Hashing(int c = 10)
	{
		capacity = c;
		elements = 0.0;
		hashTable = vector<DList<Library>>(capacity);
	}

	//Hash function using a prime number
	int hashIndex(int key)
	{
		return (7 - (key % 7)) % capacity;
	}

	//Inserts book data in the hash index
	void Insert(h bookData, int bookISSN)
	{
		int index = hashIndex(bookISSN);
		hashTable[index].InsertAtEnd(bookData);
		elements++;

		//checks if load factor has crossed 0.5 for rehashing
		if (elements / capacity >= 0.5)
			DoubleCapacity();
	}

	bool CheckISSN(int bookISSN)
	{
		int index = hashIndex(bookISSN);
		return hashTable[index].CheckISSN(bookISSN);
	}

	bool Review(int bookISSN)
	{
		int index = hashIndex(bookISSN);
		return hashTable[index].Review(bookISSN);
	}

	bool Update(int bookISSN)
	{
		int index = hashIndex(bookISSN);
		return hashTable[index].Update(bookISSN);
	}

	bool Delete(int bookISSN)
	{
		int index = hashIndex(bookISSN);
		if (hashTable[index].Delete(bookISSN) == 1)
		{
			elements--;
			return 1;
		}

		else
			return 0;
	}

	void Print()
	{
		int x = 0;
		while (x != capacity)
		{
			if (hashTable[x].getHeadNext() != hashTable[x].getTail())
			{
				cout << "\nTable Index: " << x << endl << endl;
				hashTable[x].Print();
			}
			x++;
		}
	}
};


void libraryDatabase()
{
	Hashing<Library> hashing;
	cout << "LIBRARY DATABASE\n\n1. Create a book record\n2. Review a book record\n3. Update a book record\n4. Delete a book record\n5. Display hash table\n6. Exit\n";

	while (true)
	{
		int option;
		cout << "\nEnter your option: ";
		cin >> option;

		while (option < 1 || option > 6)
		{
			cout << "Invalid input! Try again: ";
			cin >> option;
		}

		if (option == 1)
		{
			int bookISSN, reference, issuable, authorSize;
			string bookTitle;

			cout << "\nBook ISSN: ";
			cin >> bookISSN;

			while (hashing.CheckISSN(bookISSN) == 1)
			{
				cout << "Enter a unique ISSN: ";
				cin >> bookISSN;
			}

			cin.ignore();
			cout << "Book Title: ";
			getline(cin, bookTitle);

			cout << "Number of books for reference: ";
			cin >> reference;

			cout << "Number of books for issuing: ";
			cin >> issuable;

			cout << "Number of authors: ";
			cin >> authorSize;

			cin.ignore();
			string* authors = new string[authorSize];
			for (int i = 0; i < authorSize; i++)
			{
				cout << "Author " << i + 1 << " Name: ";
				getline(cin, authors[i]);
			}

			Library bookData(bookISSN, bookTitle, reference, issuable, authors, authorSize);
			hashing.Insert(bookData, bookISSN);
		}

		else if (option == 2)
		{
			int bookISSN;
			cout << "Book ISSN to be reviewed: ";
			cin >> bookISSN;
			if (hashing.Review(bookISSN) != 1)
				cout << "\nISSN not found\n";
		}

		else if (option == 3)
		{
			int bookISSN;
			cout << "Book ISSN to be updated: ";
			cin >> bookISSN;
			if (hashing.Update(bookISSN) != 1)
				cout << "\nISSN not found\n";
		}

		else if (option == 4)
		{
			int bookISSN;
			cout << "Book ISSN to be deleted: ";
			cin >> bookISSN;
			if (hashing.Delete(bookISSN) != 1)
				cout << "\nISSN not found\n";
		}

		else if (option == 5)
			hashing.Print();

		else
			break;
	}
}


int main()
{
	libraryDatabase();
	return 0;
}
