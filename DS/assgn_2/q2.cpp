#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void PrintMap(char** roomMap, int xDim, int yDim, int xStart, int yStart)
{
	system("cls");

	for (int j = 0; j < yDim + 2; j++)
		cout << '-';
	cout << endl;

	for (int k = 0; k < xDim; k++)
	{
		cout << "<";
		for (int l = 0; l < yDim; l++)
		{
			if (k == xStart && l == yStart)
				cout << '*';

			else if (roomMap[k][l] == 'X')
				cout << "|";

			else
				cout << ' ';
		}
		cout << ">\n";
	}

	for (int j = 0; j < yDim + 2; j++)
		cout << '-';
	cout << endl;
}

char userMovement, coinToss;
int TreasureHunt(char** roomMap, int xDim, int yDim, int xStart, int yStart)
{
	//map key and menu for the user to move around the map
	cout << "\n1. U or u to move up\n2. D or d to move down\n3. L or l to move left\n4. R or r to move right\n5. Q or q to quit\n\nEnter your option: ";
	cin >> userMovement;

	while ((userMovement != 'q' && userMovement != 'Q') && (userMovement != 'u' && userMovement != 'U') && (userMovement != 'd' && userMovement != 'D') && (userMovement != 'l' && userMovement != 'L') && (userMovement != 'r' && userMovement != 'R'))
	{
		cout << "Invalid input! Try again: ";
		cin >> userMovement;
	}

	//returns 0 when the user presses q or Q
	if (userMovement == 'q' || userMovement == 'Q')
	{
		cout << "You quit!\n";
		return 0;
	}

	//controls actions of the user when it moves up in the map
	else if (userMovement == 'u' || userMovement == 'U')
	{
		//does not let the user move through the forbidden walls
		if (xStart == 0 || roomMap[xStart - 1][yStart] == 'X')
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart);
			TreasureHunt(roomMap, xDim, yDim, xStart, yStart);
		}

		//moves the user to the pathways
		else if (roomMap[xStart - 1][yStart] == '0')
		{
			PrintMap(roomMap, xDim, yDim, xStart - 1, yStart);

			//returns 1 if treasure is found and returns 1 to these conditions for printing the treasure path
			if (TreasureHunt(roomMap, xDim, yDim, xStart - 1, yStart) == 1)
			{
				cout << "(" << xStart - 1 << ", " << yStart << ")\n";
				return 1;
			}
		}

		//checks the presence of the devil
		else if (roomMap[xStart - 1][yStart] == 'D')
		{
			PrintMap(roomMap, xDim, yDim, xStart - 1, yStart);
			cout << "The devil ate you up!\n";
			return 0;
		}

		//checks the presence of Gasper
		else if (roomMap[xStart - 1][yStart] == 'G')
			return 2;

		//checks the Portal
		else if (roomMap[xStart - 1][yStart] == 'P')
		{
			PrintMap(roomMap, xDim, yDim, xStart - 1, yStart);
			cout << "You have entered the portal! Flip the coin (H or T): ";
			cin >> coinToss;

			while ((coinToss != 'H' && coinToss != 'h') && (coinToss != 'T' && coinToss != 't'))
			{
				cout << "Invalid input! Try again: ";
				cin >> coinToss;
			}

			if (coinToss == 'H' || coinToss == 'h')
				return 3;

			else
				return 4;
		}

		else if (roomMap[xStart - 1][yStart] == 'T')
		{
			PrintMap(roomMap, xDim, yDim, xStart - 1, yStart);
			cout << "You found the treasure!\n\nTreasure Path:\n(" << xStart - 1 << ", " << yStart << ")\n";
			return 1;
		}
	}

	//controls actions of the user when it moves down in the map
	else if (userMovement == 'd' || userMovement == 'D')
	{
		if (xStart == xDim - 1 || roomMap[xStart + 1][yStart] == 'X')
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart);
			TreasureHunt(roomMap, xDim, yDim, xStart, yStart);
		}

		else if (roomMap[xStart + 1][yStart] == '0')
		{
			PrintMap(roomMap, xDim, yDim, xStart + 1, yStart);

			if (TreasureHunt(roomMap, xDim, yDim, xStart + 1, yStart) == 1)
			{
				cout << "(" << xStart + 1 << ", " << yStart << ")\n";
				return 1;
			}
		}

		else if (roomMap[xStart + 1][yStart] == 'D')
		{
			PrintMap(roomMap, xDim, yDim, xStart + 1, yStart);
			cout << "The devil ate you up!\n";
			return 0;
		}

		else if (roomMap[xStart + 1][yStart] == 'G')
			return 2;

		else if (roomMap[xStart + 1][yStart] == 'P')
		{
			PrintMap(roomMap, xDim, yDim, xStart + 1, yStart);
			cout << "You have entered the portal! Flip the coin (H or T): ";
			cin >> coinToss;

			while ((coinToss != 'H' && coinToss != 'h') && (coinToss != 'T' && coinToss != 't'))
			{
				cout << "Invalid input! Try again: ";
				cin >> coinToss;
			}

			if (coinToss == 'H' || coinToss == 'h')
				return 3;

			else
				return 4;
		}

		else if (roomMap[xStart + 1][yStart] == 'T')
		{
			PrintMap(roomMap, xDim, yDim, xStart + 1, yStart);
			cout << "You found the treasure!\n\nTreasure Path:\n(" << xStart + 1 << ", " << yStart << ")\n";
			return 1;
		}
	}

	//controls actions of the user when it moves left in the map
	else if (userMovement == 'l' || userMovement == 'L')
	{
		if (roomMap[xStart][yStart - 1] == '0')
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart - 1);
			
			if (TreasureHunt(roomMap, xDim, yDim, xStart, yStart - 1) == 1)
			{
				cout << "(" << xStart << ", " << yStart - 1 << ")\n";
				return 1;
			}
		}

		else if (roomMap[xStart][yStart - 1] == 'X' || yStart == 0)
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart);
			TreasureHunt(roomMap, xDim, yDim, xStart, yStart);
		}

		else if (roomMap[xStart][yStart - 1] == 'D')
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart - 1);
			cout << "The devil ate you up!\n";
			return 0;
		}

		else if (roomMap[xStart][yStart - 1] == 'G')
			return 2;

		else if (roomMap[xStart][yStart - 1] == 'P')
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart - 1);
			cout << "You have entered the portal! Flip the coin (H or T): ";
			cin >> coinToss;

			while ((coinToss != 'H' && coinToss != 'h') && (coinToss != 'T' && coinToss != 't'))
			{
				cout << "Invalid input! Try again: ";
				cin >> coinToss;
			}

			if (coinToss == 'H' || coinToss == 'h')
				return 3;

			else
				return 4;
		}

		else if (roomMap[xStart][yStart - 1] == 'T')
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart - 1);
			cout << "You found the treasure!\n\nTreasure Path:\n(" << xStart << ", " << yStart - 1 << ")\n";
			return 1;
		}
	}

	//controls actions of the user when it moves right in the map
	else if (userMovement == 'r' || userMovement == 'R')
	{
		if (roomMap[xStart][yStart + 1] == '0')
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart + 1);
			
			if (TreasureHunt(roomMap, xDim, yDim, xStart, yStart + 1) == 1)
			{
				cout << "(" << xStart << ", " << yStart + 1 << ")\n";
				return 1;
			}
		}

		else if (roomMap[xStart][yStart + 1] == 'X' || yStart == yDim - 1)
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart);
			TreasureHunt(roomMap, xDim, yDim, xStart, yStart);
		}

		else if (roomMap[xStart][yStart + 1] == 'D')
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart + 1);
			cout << "The devil ate you up!\n";
			return 0;
		}

		else if (roomMap[xStart][yStart + 1] == 'G')
			return 2;

		else if (roomMap[xStart][yStart + 1] == 'P')
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart + 1);
			cout << "You have entered the portal! Flip the coin (H or T): ";
			cin >> coinToss;

			while ((coinToss != 'H' && coinToss != 'h') && (coinToss != 'T' && coinToss != 't'))
			{
				cout << "Invalid input! Try again: ";
				cin >> coinToss;
			}

			if (coinToss == 'H' || coinToss == 'h')
				return 3;

			else
				return 4;
		}

		else if (roomMap[xStart][yStart + 1] == 'T')
		{
			PrintMap(roomMap, xDim, yDim, xStart, yStart + 1);
			cout << "You found the treasure!\n\nTreasure Path:\n(" << xStart << ", " << yStart + 1 << ")\n";
			return 1;
		}
	}
}

int main()
{
	//reads text files and number of rooms from the haunted house text file
	ifstream hauntedHouse;
	hauntedHouse.open("hauntedhouse.txt");

	int numberOfRooms;
	hauntedHouse >> numberOfRooms;

	string roomName;
	string* rooms = new string[numberOfRooms];

	//stores room text files in an array for accessing them
	for (int i = 0; i < numberOfRooms; i++)
	{
		hauntedHouse >> roomName;
		rooms[i] = roomName;
	}

	hauntedHouse.close();

	//foundTreasure used for checking which room has the treasure
	//foundGasper used for teleporting the user to the room with the treasure
	//foundRandom used for teleporting user to random cells in a random room
	bool foundTreasure, foundGasper, foundRandom = false;

	ifstream roomAccess;
	int xDim, yDim, xStart, yStart, returnVal, randomRoom;
	char comma, mapValues;

	for (int j = 0; j < numberOfRooms; j++)
	{
		//stores room dimensions and starting positions in variables
		roomAccess.open(rooms[j]);
		roomAccess >> xDim >> comma >> yDim >> xStart >> comma >> yStart;

		//allocates a 2D array and stores the room map in it
		char** roomMap = new char* [xDim];
		for (int k = 0; k < xDim; k++)
			roomMap[k] = new char[yDim + 1];

		for (int k = 0; k < xDim; k++)
		{
			for (int l = 0; l < yDim; l++)
			{
				roomAccess >> mapValues;
				roomMap[k][l] = mapValues;
			}
			roomMap[k][yDim] = '\0';
		}

		//used for the Gasper to teleport user to the room with the treasure
		if (j > 0 && foundGasper == true)
		{
			foundTreasure = false;
			for (int k = 0; k < xDim; k++)
			{
				for (int l = 0; l < yDim; l++)
				{
					if (roomMap[k][l] == 'T')
					{
						foundTreasure = true;
						break;
					}
				}

				if (foundTreasure == true)
					break;
			}

			if (foundTreasure == false)
			{
				roomAccess.close();
				continue;
			}
		}

		//used for the Portal to teleport user to a random cell
		if (foundRandom == true)
		{
			srand(time(0));

			xStart = (rand() % xDim);
			yStart = (rand() & yDim);

			while (roomMap[xStart][yStart] != '0')
			{
				xStart = (rand() % xDim);
				yStart = (rand() % yDim);
			}

			foundRandom = false;
		}

		PrintMap(roomMap, xDim, yDim, xStart, yStart);
		returnVal = TreasureHunt(roomMap, xDim, yDim, xStart, yStart);

		//ends the game when the user quits or is eaten by the demon
		if (returnVal == 0)
			break;

		//ends the game when the user finds treasure and displays the room where the treasure was found
		else if (returnVal == 1)
		{
			cout << "Room " << j + 1 << endl;
			break;
		}

		//used for the Gasper to teleport user to the room with the treasure
		else if (returnVal == 2)
		{
			foundGasper = true;
			roomAccess.close();
			continue;
		}

		//used when the Portal lands head and sends the user to a random room
		else if (returnVal == 3)
		{
			foundGasper = false;

			srand(time(0));
			randomRoom = (rand() % numberOfRooms) + 1;

			while (randomRoom == (j + 1))
				randomRoom = (rand() % numberOfRooms) + 1;

			j = randomRoom - 2;
			foundRandom = true;
			roomAccess.close();
			continue;
		}

		//used when the Portal lands tail / quits game if the user is in the first room / sends user to the previous room otherwise
		else if (returnVal == 4)
		{
			foundGasper = false;

			if (j == 0)
			{
				cout << "You have been kicked out!\n";
				break;
			}

			else
			{
				j -= 2;
				roomAccess.close();
				continue;
			}
		}

		roomAccess.close();
	}

	return 0;
}
