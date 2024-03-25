#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


void main()
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
	cout << "Text file:\n";
	fileData.open("Skill.txt");
	for (int i = 0; i < fileSize; i++)
	{
		getline(fileData, *(fileArray + i));
		cout << *(fileArray + i) << endl;
	}
	fileData.close();


	cout << "\nNames Array:\n";
	string* names = new string[fileSize];
	for (int i = 0; i < fileSize; i++)
	{
		for (int j = 0; fileArray[i][j] != ' '; j++)
			*(names + i) += fileArray[i][j];

		cout << *(names + i) << endl;
	}


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


	cout << "\nSkillset Array:\n";
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

		for (int k = 0; k < skillCount[i]; k++)
			cout << *(*(skill + i) + k) << ' ';

		cout << endl;
	}


	string input;
	cout << "\nEnter a skillset: ";
	cin >> input;
	cout << input << ": ";


	for (int i = 0; i < fileSize; i++)
		for (int j = 0; j < skillCount[i]; j++)
			if (input == skill[i][j])
			{
				cout << names[i] << "  ";
				break;
			}


	delete[] fileArray;
	delete[] names;
	delete[] skillCount;

	for (int i = 0; i < fileSize; i++)
		delete[] skill[i];
	delete[] skill;

	cout << endl;
}
