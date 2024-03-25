#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;


class Skill
{
private:
	string** skill;
	int* skillCount;
	int person;

public:
	Skill()
	{
		person = 0;
		skillCount = new int[person];
		for (int i = 0; i < person; i++)
			*(skillCount + i) = 0;

		skill = new string* [person];
		for (int i = 0; i < person; i++)
			*(skill + i) = new string[skillCount[i]];

		for (int i = 0; i < person; i++)
			for (int j = 0; j < skillCount[i]; j++)
				*(*(skill + i) + j) = " ";
	}


	Skill(string** s, int* sc, int p)
	{
		person = p;
		skillCount = new int[person];
		for (int i = 0; i < person; i++)
			*(skillCount + i) = sc[i];

		skill = new string* [person];
		for (int i = 0; i < person; i++)
			*(skill + i) = new string[skillCount[i]];

		for (int i = 0; i < person; i++)
			for (int j = 0; j < skillCount[i]; j++)
				*(*(skill + i) + j) = *(*(s + i) + j);
	}


	Skill(Skill& sk)
	{
		person = sk.person;
		skillCount = new int[person];
		for (int i = 0; i < person; i++)
			*(skillCount + i) = sk.skillCount[i];

		skill = new string* [person];
		for (int i = 0; i < person; i++)
			*(skill + i) = new string[skillCount[i]];

		for (int i = 0; i < person; i++)
			for (int j = 0; j < skillCount[i]; j++)
				*(*(skill + i) + j) = *(*(sk.skill + i) + j);
	}


	void print()
	{
		for (int i = 0; i < person; i++)
		{
			for (int j = 0; j < skillCount[i]; j++)
				cout << *(*(skill + i) + j) << ' ';
			cout << endl;
		}
	}


	string** getSkill()
	{
		return skill;
	}


	int* getSkillCount()
	{
		return skillCount;
	}


	~Skill()
	{
		delete[] skillCount;

		for (int i = 0; i < person; i++)
			delete[] skill[i];
		delete[] skill;
	}
};


class Applicant
{
private:
	string* person;
	Skill skillPerson;
	int people;

public:
	Applicant()
	{
		people = 0;
		person = new string[people];

		for (int i = 0; i < people; i++)
			*(person + i) = " ";
	}


	Applicant(string* n, int p, string** s, int* sc) : skillPerson(s, sc, p)
	{
		people = p;
		person = new string[people];

		for (int i = 0; i < people; i++)
			*(person + i) = *(n + i);
	}


	Applicant(Applicant& app)
	{
		people = app.people;
		person = new string[people];

		for (int i = 0; i < people; i++)
			*(person + i) = *(app.person + i);
	}


	void print()
	{
		for (int i = 0; i < people; i++)
			cout << *(person + i) << endl;
	}


	void printSkill()
	{
		skillPerson.print();
	}


	string* getPerson()
	{
		return person;
	}


	int getSize()
	{
		return people;
	}


	string** getSkill()
	{
		return skillPerson.getSkill();
	}


	int* getSkillCount()
	{
		return skillPerson.getSkillCount();
	}


	~Applicant()
	{
		delete[] person;
	}
};


class Match
{
public:
	Match()
	{
		//cout << "\nMatch() called\n";
	}


	virtual void matches()
	{

	}


	~Match()
	{
		//cout << "\n~Match() called\n";
	}
};


class MatchAll : public Match
{
private:
	string* arr;
	int size;
	Applicant applicants;

public:
	MatchAll()
	{
		size = 0;
		arr = new string[size];
		for (int i = 0; i < size; i++)
			*(arr + i) = " ";
	}


	MatchAll(string* a, int sz, string* n, int f, string** sk, int* skC) : applicants(n, f, sk, skC)
	{
		size = sz;
		arr = new string[size];
		for (int i = 0; i < size; i++)
			*(arr + i) = *(a + i);
	}


	MatchAll(MatchAll& m)
	{
		size = m.size;
		arr = new string[size];
		for (int i = 0; i < size; i++)
			*(arr + i) = *(m.arr + i);
	}


	virtual void matches()
	{
		int* temp = applicants.getSkillCount();
		string** skillTemp = applicants.getSkill();
		bool flag = 0;
		int* store = new int[10];
		int index = 0;
		string* personTemp = applicants.getPerson();


		for (int i = 0; i < applicants.getSize(); i++)
		{
			for (int j = 0; j < temp[i]; j++)
			{
				for (int k = 0; k < size; k++)
				{
					if (arr[k] == skillTemp[i][j])
					{
						flag = 1;
						break;
					}

					else
						flag = 0;

					
				}
			}

			if (flag == 1)
			{
				store[index] = i;
				index++;
			}
		}

		for (int i = 0; i < index; i++)
			cout << personTemp[store[i]] << "  ";
	}


	~MatchAll()
	{
		delete[] arr;
	}
};


class MatchAny : public Match
{
private:
	string* arr;
	int size;
	Applicant applicants;

public:
	MatchAny()
	{
		size = 0;
		arr = new string[size];
		for (int i = 0; i < size; i++)
			*(arr + i) = " ";
	}


	MatchAny(string* a, int s, string* n, int f, string** sk, int* skC) : applicants(n,f,sk,skC)
	{
		size = s;
		arr = new string[size];
		for (int i = 0; i < size; i++)
			*(arr + i) = *(a + i);
	}


	MatchAny(MatchAny& m)
	{
		size = m.size;
		arr = new string[size];
		for (int i = 0; i < size; i++)
			*(arr + i) = *(m.arr + i);
	}


	virtual void matches()
	{
		int* temp = applicants.getSkillCount();
		string** skillTemp = applicants.getSkill();
		int* store = new int[10];
		int index = 0;
		bool flag = 0;
		string* personTemp = applicants.getPerson();


		for (int i = 0; i < applicants.getSize(); i++)
		{
			flag = 0;
			for (int j = 0; j < temp[i]; j++)
			{
				for (int k = 0; k < size; k++)
				{
					if (arr[k] == skillTemp[i][j])
					{
						flag = 1;
						store[index] = i;
						index++;
						break;
					}
				}

				if (flag == 1) break;
			}
		}

		for (int i = 0; i < index; i++)
			cout << personTemp[store[i]] << "  ";
	}


	~MatchAny()
	{
		delete[] arr;
	}
};


class MatchAtLeast : public Match
{
private:
	string* arr;
	int size;
	int limit;
	Applicant applicants;

public:
	MatchAtLeast()
	{
		limit = 0;
		size = 0;
		arr = new string[size];
		for (int i = 0; i < size; i++)
			*(arr + i) = " ";
	}


	MatchAtLeast(string* a, int s, int l, string* n, int f, string** sk, int* skC) : applicants(n, f, sk, skC)
	{
		limit = l;
		size = s;
		arr = new string[size];
		for (int i = 0; i < size; i++)
			*(arr + i) = *(a + i);
	}


	MatchAtLeast(MatchAtLeast& m)
	{
		limit = m.limit;
		size = m.size;
		arr = new string[size];
		for (int i = 0; i < size; i++)
			*(arr + i) = *(m.arr + i);
	}


	virtual void matches()
	{
		int* temp = applicants.getSkillCount();
		string** skillTemp = applicants.getSkill();
		int* store = new int[10];
		int index = 0;
		bool flag = 0;
		string* personTemp = applicants.getPerson();


		for (int i = 0; i < applicants.getSize(); i++)
		{
			flag = 0;
			for (int j = 0; j < temp[i]; j++)
			{
				for (int k = 0; k < size; k++)
				{
					if (arr[k] == skillTemp[i][j])
					{
						flag = 1;

						if (index <= limit)
						{
							store[index] = i;
							index++;
							break;
						}
					}
				}

				if (flag == 1) break;
			}
		}

		for (int i = 0; i < index; i++)
			cout << personTemp[store[i]] << "  ";
	}


	~MatchAtLeast()
	{
		delete[] arr;
	}
};


int main()
{
	int fileSize = 0;
	string fileRead;
	ifstream fileData, fileCount;


	fileCount.open("Skill.txt");
	while (!fileCount.eof())
	{
		getline(fileCount, fileRead);
		fileSize++;
	}
	fileCount.close();


	string* fileArray = new string[fileSize];
	fileData.open("Skill.txt");
	for (int i = 0; i < fileSize; i++)
		getline(fileData, *(fileArray + i));
	fileData.close();


	string* names = new string[fileSize];
	for (int i = 0; i < fileSize; i++)
		for (int j = 0; fileArray[i][j] != ' '; j++)
			*(names + i) += fileArray[i][j];


	int skillCountVar;
	int* skillCount = new int[fileSize];
	for (int i = 0; i < fileSize; i++)
	{
		skillCountVar = 0;

		for (int j = 0; fileArray[i][j] != '\0'; j++)
			if (fileArray[i][j] == ' ')
				skillCountVar++;

		skillCount[i] = skillCountVar;
	}


	string** skill = new string * [fileSize];
	for (int i = 0; i < fileSize; i++)
		*(skill + i) = new string[skillCount[i]];


	int fileIndex = 0, skillColumn;
	for (int i = 0; i < fileSize; i++)
	{
		skillColumn = 0;

		for (int j = 0; fileArray[i][j] != '\0'; j++)
			if (fileArray[i][j] == ' ')
			{
				fileIndex = j + 1;
				break;
			}

		for (fileIndex; fileArray[i][fileIndex] != '\0'; fileIndex++)
		{
			if (fileArray[i][fileIndex] == ' ')
			{
				skillColumn++;
				fileIndex++;
				*(*(skill + i) + skillColumn) = fileArray[i][fileIndex];
			}

			else
				*(*(skill + i) + skillColumn) += fileArray[i][fileIndex];
		}
	}


	Applicant a(names, fileSize, skill, skillCount);
	a.print();
	cout << endl;
	a.printSkill();


	string* search = new string[10];
	int matchCount;
	cout << "\nHow many skills would you match? ";
	cin >> matchCount;

	cout << "Enter search skills: \n";
	cin.ignore();
	for (int k = 0; k < matchCount; k++)
		getline(cin, search[k]);

	string* temp = new string[matchCount];
	for (int l = 0; l < matchCount; l++)
		temp[l] = search[l];


	delete[] search;
	Match* matchall = new MatchAll(temp, matchCount, names, fileSize, skill, skillCount);

	cout << "\nMatchAll: ";
	matchall->matches();

	cout << "\nMatchAny: ";
	Match* matchany = new MatchAny(temp, matchCount, names, fileSize, skill, skillCount);
	matchany->matches();

	cout << "\n\nHow many people would you match? ";
	int ask;
	cin >> ask;

	cout << "MatchAtLeast: ";
	Match* matchatleast = new MatchAtLeast(temp, matchCount, ask, names, fileSize, skill, skillCount);
	matchatleast->matches();

	delete[] fileArray;
	delete[] names;
	delete[] temp;

	for (int i = 0; i < fileSize; i++)
		delete[] skill[i];

	delete[] skill;
	delete[] skillCount;

	return 0;
}
