#include <iostream>
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

	//Deleting book information according to ISSN
	void Delete(int bookISSN)
	{
		DNode* temp = head->next;
		while (temp != tail)
		{
			if (temp->data == bookISSN)
				break;
			temp = temp->next;
		}

		if (temp != tail)
		{
			DNode* temp2 = temp;
			temp->prev->next = temp->next;
			temp = temp->next;
			temp->prev = temp2->prev;
			delete temp2;
		}
	}

	void Print()
	{
		DNode* temp = head->next;
		while (temp != tail)
		{
			cout << temp->data << "   ";
			temp = temp->next;
		}
	}
};


template <class A>
class AVLTree
{
private:
	class ANode
	{
	public:
		A data;
		int index;
		ANode* left;
		ANode* right;
		int height;
	};
	ANode* root;
	DList<Library> linkedList;

public:
	AVLTree()
	{
		root = nullptr;
	}

	int getHeight(ANode* r)
	{
		if (r == nullptr)
			return -1;

		else
			return 1 + max(getHeight(r->left), getHeight(r->right));
	}

	void rotateLeft(ANode*& x)
	{
		ANode* y = x->right;
		x->right = y->left;
		y->left = x;

		x->height = 1 + max(getHeight(x->left), getHeight(x->right));
		y->height = 1 + max(x->height, getHeight(y->right));
		x = y;
	}

	void doubleRotateLeft(ANode*& x)
	{
		rotateRight(x->right);
		rotateLeft(x);
	}

	void rotateRight(ANode*& x)
	{
		ANode* y = x->left;
		x->left = y->right;
		y->right = x;

		x->height = 1 + max(getHeight(x->right), getHeight(x->left));
		y->height = 1 + max(x->height, getHeight(y->left));
		x = y;
	}

	void doubleRotateRight(ANode*& x)
	{
		rotateLeft(x->left);
		rotateRight(x);
	}

	void Insert(A d, int i)
	{
		Insert(root, d, i);
		linkedList.InsertAtEnd(d);
	}

	void Insert(ANode*& r, A d, int i)
	{
		if (r == nullptr)
		{
			r = new ANode;
			r->index = i;
			r->data = d;

			r->left = nullptr;
			r->right = nullptr;
			r->height = 0;
		}

		else
		{
			if (i < r->index)
			{
				Insert(r->left, d, i);

				if (getHeight(r->right) - getHeight(r->left) == 2)
				{
					if (i > r->left->index)
						rotateRight(r);

					else
						doubleRotateRight(r);
				}
			}

			else if (i > r->index)
			{
				Insert(r->right, d, i);

				if (getHeight(r->left) - getHeight(r->right) == -2)
				{
					if (i > r->right->index)
						rotateLeft(r);

					else
						doubleRotateLeft(r);
				}
			}

			r->height = 1 + max(getHeight(r->left), getHeight(r->right));
		}
	}

	//Function to ensure unique ISSN has been entered by the user
	bool CheckISSN(int bookISSN)
	{
		return CheckISSN(root, bookISSN);
	}

	bool CheckISSN(ANode* r, int bookISSN)
	{
		if (r != nullptr)
		{
			if (r->index == bookISSN)
				return true;
			CheckISSN(r->left, bookISSN);
			CheckISSN(r->right, bookISSN);
		}
	}

	//Reviewing book information in lg(n)
	bool Review(int bookISSN)
	{
		bool flag = false;
		Review(root, bookISSN, flag);
		return flag;
	}

	void Review(ANode* r, int bookISSN, bool& flag)
	{
		if (r != nullptr)
		{
			if (r->index == bookISSN)
			{
				cout << endl << r->data << endl;
				flag = true;
			}
			Review(r->left, bookISSN, flag);
			Review(r->right, bookISSN, flag);
		}
	}

	//Updating book information in lg(n)
	bool Update(int bookISSN)
	{
		bool flag = false;
		Update(root, bookISSN, flag);
		return flag;
	}

	void Update(ANode* r, int bookISSN, bool& flag)
	{
		if (r != nullptr)
		{
			if (r->index == bookISSN)
			{
				*(r->data);
				flag = true;
			}
			Update(r->left, bookISSN, flag);
			Update(r->right, bookISSN, flag);
		}
	}
	
	void Delete(int bookISSN)
	{
		Delete(root, bookISSN);
		linkedList.Delete(bookISSN);
	}

	void Delete(ANode*& r, int bookISSN)
	{
		ANode* p;

		if (r != nullptr)
		{
			if (bookISSN > r->index)
			{
				Delete(r->right, bookISSN);
				if (BalanceFactor(r) == 2)
				{
					if (BalanceFactor(r->left) >= 0)
						rotateRight(r);
					else
						doubleRotateRight(r);
				}
			}

			else
			{
				if (bookISSN < r->index)
				{
					Delete(r->left, bookISSN);
					if (BalanceFactor(r) == -2)
					{
						if (BalanceFactor(r->right) <= 0)
							rotateLeft(r);
						else
							doubleRotateLeft(r);
					}
				}

				else
				{
					if (r->right != nullptr)
					{
						p = r->right;

						while (p->left != nullptr)
							p = p->left;

						r->index = p->index;
						Delete(r->right, p->index);

						if (BalanceFactor(r) == 2)
						{
							if (BalanceFactor(r->left) >= 0)
								rotateRight(r);
							else
								doubleRotateRight(r);
						}
					}
					else
						r = r->left;
				}
			}
		}
	}
	
	int BalanceFactor(ANode* r)
	{
		int lh, rh;

		if (r == nullptr)
			return 0;

		if (r->left == nullptr)
			lh = 0;

		else
			lh = 1 + r->left->height;

		if (r->right == nullptr)
			rh = 0;

		else
			rh = 1 + r->right->height;

		return (lh - rh);
	}

	void Print()
	{
		Print(root);
	}

	void Print(ANode* r)
	{
		if (r != nullptr)
		{
			Print(r->left);
			cout << r->index << "   ";
			Print(r->right);
		}
	}
};


void libraryDatabase()
{
	AVLTree<Library> avlTree;
	cout << "LIBRARY DATABASE\n\n1. Create a book record\n2. Review a book record\n3. Update a book record\n4. Delete a book record\n5. Exit\n";

	while (true)
	{
		int option;
		cout << "\nEnter your option: ";
		cin >> option;

		while (option < 1 || option > 5)
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

			while (avlTree.CheckISSN(bookISSN) == 1)
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
			avlTree.Insert(bookData, bookISSN);
		}

		else if (option == 2)
		{
			int bookISSN;
			cout << "Book ISSN to be reviewed: ";
			cin >> bookISSN;
			if (avlTree.Review(bookISSN) != 1)
				cout << "\nISSN not found\n";
		}

		else if (option == 3)
		{
			int bookISSN;
			cout << "Book ISSN to be updated: ";
			cin >> bookISSN;
			if (avlTree.Update(bookISSN) != 1)
				cout << "\nISSN not found\n";
		}

		else if (option == 4)
		{
			int bookISSN;
			cout << "Book ISSN to be deleted: ";
			cin >> bookISSN;

			if (avlTree.CheckISSN(bookISSN) != 1)
				cout << "\nISSN not found\n";

			else
				avlTree.Delete(bookISSN);
		}

		else
			avlTree.Print();
	}
}


int main()
{
	libraryDatabase();
	return 0;
}
