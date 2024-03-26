#include <iostream>
#include <string>
using namespace std;


class Block
{
	//cout operator to display the blocks
	friend ostream& operator << (ostream&, Block&);

private:
	int startID;
	int totalBytes;

public:
	Block(int ID = 0, int tB = 0)
	{
		startID = ID;
		totalBytes = tB;
	}

	//condition for checking if size required by program is under the given value
	bool operator >= (int sizeRequired)
	{
		return (totalBytes >= sizeRequired);
	}

	//condition for checking if size required by program is above the given value
	bool operator <= (int sizeRequired)
	{
		return (totalBytes <= sizeRequired);
	}

	//condition for checking if size of current block is equal to the startID of the next block
	bool operator == (int sizeRequired)
	{
		return (totalBytes == sizeRequired);
	}

	//returns startID of the block
	int operator*()
	{
		return startID;
	}

	//updates the currently pointed block of the pool
	void operator = (Block& b)
	{
		startID = b.startID;
		totalBytes = b.totalBytes;
	}
};

//cout operator to display the blocks
ostream& operator << (ostream& out, Block& b)
{
	out << "ID: " << b.startID << " -> Size: " << b.totalBytes << endl;
	return out;
}


template <class T>
class List
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void InsertAtStart(T d)
	{
		Node* temp = new Node;
		temp->data = d;
		temp->next = head;

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}

		else
			head = temp;

		size++;
	}

	void InsertAtEnd(T d)
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

		size++;
	}

	//inserts new block in the sorted pool before the block which has a greater startID than its startID
	void Insert(Node* temp1, Node* temp2)
	{
		Node* temp3 = head;
		Node* temp4 = temp3;
		int count = 0;

		while (temp3 != temp2->next)
		{
			if (temp3 == temp2)
			{
				temp4->next = temp1;
				temp1->next = temp3;
				size++;
				break;
			}

			temp3 = temp3->next;
			count++;

			if (count > 1)
				temp4 = temp4->next;
		}
	}

	//deletes the program entered by the user by sending programID as parameter
	bool Delete(const char* d)
	{
		//count and temp2 used for pointing to the block before the currently pointed block
		int count = 0;
		Node* temp = head;
		Node* temp2 = temp;

		while (temp != nullptr)
		{
			if (temp->data == d)
			{
				//condition for checking if programID is at the first block
				if (temp == head)
				{
					head = head->next;
					delete temp;
					size--;
					return 1;
				}

				//condition for checking if programID is at the last block
				else if (temp == tail)
				{
					tail = temp2;
					tail->next = nullptr;
					delete temp;
					size--;
					return 1;
				}

				//condition for checking if programID is at a random block
				else
				{
					temp2->next = temp->next;
					delete temp;
					size--;
					return 1;
				}
			}

			temp = temp->next;
			count++;
			if (count > 1)
				temp2 = temp2->next;
		}
		return 0;
	}

	//gets the startID of a block using first fit strategy
	int firstFit(int sizeRequired)
	{
		Node* temp = tail;
		return *(temp->data);
	}

	//gets the startID of a block using best fit strategy
	int bestFit(int programSize, int sizeRequired)
	{
		Node* temp = head;
		int startID = sizeRequired;
		while (temp != nullptr)
		{
			if (temp->data >= programSize && temp->data <= startID)
				startID = *(temp->data); //operator overloaded (in the block class) to return startID of a block and assign it to startID
			temp = temp->next;
		}
		return startID;
	}

	void UpdatePoolBlock(int& startID, int programMemory, int& memorySize)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (startID == *(temp->data)) //finds the block of the pool which has to be updated
				break;
			temp = temp->next;
		}

		startID += programMemory;
		memorySize -= programMemory;

		Block tempBlock(startID, memorySize); //sets updated values of the currently pointed block of the pool after insertion of a program
		temp->data = tempBlock; //assigns the updated values to the currently pointed block of the pool
	}

	//adds new blocks to the pool after deletion of a program and sorts the updated pool
	List<Block> UpdatePool(List<Block> pool)
	{
		Node* temp1 = head;
		Node* temp2 = pool.head;
		Node* temp3 = pool.tail;

		while (temp1 != nullptr)
		{
			if (*(temp1->data) > *(temp3->data))
				pool.InsertAtEnd(temp1->data); //if startID of a deleted program is greater than the startID of the current block in pool then insert deleted program startID at the end

			else if (*(temp1->data) < *(temp2->data))
				pool.InsertAtStart(temp1->data); //if startID of a deleted program is less than the startID of the current block in pool then insert deleted program startID at the start

			else
			{
				while (temp2 != nullptr)
				{
					if (*(temp1->data) > *(temp2->data))
						temp2 = temp2->next;

					else
					{
						pool.Insert(temp1, temp2); //inserts new block in the sorted pool before the block which has a greater startID than its startID
						break;
					}
				}
				break;
			}
			temp1 = temp1->next;
		}
		return pool;
	}

	//checks availability of the programID entered by the user
	bool findProgramID(const char* programID)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == programID) //operator overloaded (in the program class) to check equality of programID
				return 1;
			temp = temp->next;
		}
		return 0;
	}

	//gets the list of blocks for the program entered by the user
	List<Block> getProgramList(const char* programID)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == programID)
				return *(temp->data); //operator overloaded (in the program class) to return the list
			temp = temp->next;
		}
	}

	//updates the data members of a program which has multiple blocks
	void UpdateProgramMembers(const char* programID, int programMemory, List<Block> programList, Block eachProg)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == programID)
			{
				temp->data += programMemory; //accumulates total memory of a program
				programList.InsertAtEnd(eachProg); //adds the block of a program at the end of the list which was asked for further memory
				temp->data = programList; //gives progBlock (program class data member) the updated list
				//the += and = operators have been overloaded in program class
				break;
			}

			temp = temp->next;
		}
	}

	//prints the data through cout overloaded operators in both block and program class
	void print()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data;
			temp = temp->next;
		}
	}
};


class Program
{
	friend ostream& operator << (ostream&, Program&);

private:
	char* progID;
	int progSize;
	List<Block> progBlock;

public:
	Program(char* pID = 0, int pSize = 0, Block eachProg = 0)
	{
		progID = pID;
		progSize = pSize;
		progBlock.InsertAtEnd(eachProg);
	}

	//equality operator to check if programID entered by the user is available
	bool operator == (const char* pID)
	{
		if (*(progID + 1) == *(pID + 1))
			return 1;

		else
			return 0;
	}

	//returns the list of a specific program
	List<Block> operator*()
	{
		return progBlock;
	}

	//updates the total size of a specific program
	void operator += (int s)
	{
		progSize += s;
	}

	//updates the list of a specific program by adding multiple blocks
	void operator = (List<Block> b)
	{
		progBlock = b;
	}
};

//cout operator overloaded to display programID and size
ostream& operator << (ostream& out, Program& p)
{
	out << endl << p.progID << " -> Size: " << p.progSize << endl;
	p.progBlock.print();
	return out;
}


class MemoryManagement
{
private:
	List<Block> pool;
	List<Program> progs;
	int memorySize;
	bool strategy;

public:
	MemoryManagement(int m = 0, bool s = 0)
	{
		strategy = s;
		memorySize = m;
		poolBlock(0, memorySize);
	}

	//adds blocks to the pool
	void poolBlock(int startID, int bytes)
	{
		Block poolTemp(startID, bytes);
		pool.InsertAtEnd(poolTemp);
	}

	//the renamed GetMem function which adds programs in the memory by the user-entered strategy
	bool addProgram(char* programID, int programMemory)
	{
		
		if (programMemory <= memorySize)
		{
			if (progs.findProgramID(programID)) //adding new blocks to an already existing program
			{
				if (strategy == 0) //first fit
				{
					int startID = pool.firstFit(programMemory); //gets startID for first fit strategy
					Block eachProg(startID, programMemory);
					List<Block> programList = progs.getProgramList(programID);
					progs.UpdateProgramMembers(programID, programMemory, programList, eachProg);
					pool.UpdatePoolBlock(startID, programMemory, memorySize);
				}

				else //best fit
				{
					int startID = pool.bestFit(programMemory, memorySize); //gets startID for best fit strategy
					Block eachProg(startID, programMemory);
					List<Block> programList = progs.getProgramList(programID);
					progs.UpdateProgramMembers(programID, programMemory, programList, eachProg);
					pool.UpdatePoolBlock(startID, programMemory, memorySize);
				}
			}

			else //adding a completely new program
			{
				if (strategy == 0) //first fit
				{
					int startID = pool.firstFit(programMemory); //gets startID for first fit strategy
					Block eachProg(startID, programMemory);
					Program programTemp(programID, programMemory, eachProg);
					progs.InsertAtEnd(programTemp);
					pool.UpdatePoolBlock(startID, programMemory, memorySize);
				}

				else //best fit
				{
					int startID = pool.bestFit(programMemory, memorySize); //gets startID for best fit strategy
					Block eachProg(startID, programMemory);
					Program programTemp(programID, programMemory, eachProg);
					progs.InsertAtEnd(programTemp);
					pool.UpdatePoolBlock(startID, programMemory, memorySize);
				}
			}

			return 1;
		}

		else
			return 0;
	}

	//deletes a specific program and gives its blocks to the pool as it becomes free memory after deletion
	bool deleteProgram(char* programID)
	{
		if (progs.findProgramID(programID))
		{
			List<Block> programList = progs.getProgramList(programID); //gets list of the program
			pool = programList.UpdatePool(pool); //adds its blocks to the pool
			progs.Delete(programID); //deletes the program
			return 1;
		}

		else
			return 0;
	}

	//prints through the cout operators overloaded in block and program class
	void printPool()
	{
		pool.print();
	}

	void printProgs()
	{
		progs.print();
	}
};


//driver function
void MemoryManagementSystem()
{
	bool strategy, exe = true;
	int option = 0;
	long long int RAM;

	cout << "MEMORY MANAGEMENT SYSTEM\n------------------------\nEnter RAM size: ";
	cin >> RAM;

	//0 used for first fit / 1 used for best fit
	cout << "\n0. First fit\n1. Best fit\nChoose strategy: ";
	cin >> strategy;

	//creates one block of pool initially
	MemoryManagement simulator(RAM, strategy);

	//menu for the user
	cout << "\n1. Add program\n2. Delete program\n3. View available memory\n4. View current programs\n5. Exit Memory Management System\n------------------------\n";

	while (exe == true)
	{
		cout << "\nChoose option: ";
		cin >> option;

		if (option == 1)
		{
			char* programID = new char[3];
			int programMemory = 0;

			cout << "\nProgram ID: ";
			cin >> programID;

			cout << "Program Memory: ";
			cin >> programMemory;

			if (simulator.addProgram(programID, programMemory))
				cout << "\nProgram added\n";

			else
				cout << "\nMemory not available\n";
		}

		else if (option == 2)
		{
			char* programID = new char[3];
			cout << "\nProgram ID: ";
			cin >> programID;

			if (simulator.deleteProgram(programID))
				cout << "\nProgram deleted\n";

			else
				cout << "\nProgram ID not found\n";
		}

		else if (option == 3)
		{
			cout << "\nPool:\n";
			simulator.printPool();
		}

		else if (option == 4)
			simulator.printProgs();

		else if (option == 5)
		{
			exe = false;
			cout << "\nMemory Management System exited\n";
		}

		else
			cout << "Invalid input! Try again: ";
	}
}


int main()
{
	//driver function
	MemoryManagementSystem();
	return 0;
}
