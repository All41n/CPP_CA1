#pragma once
#include "targetver.h"
#include "Games.h"
#include "GameClass.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>
#include "windows.h"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::to_string;
using std::string;
using std::ostream;
using std::vector;
using std::ios;
using std::stringstream;

void displayGames(vector<Games> games)
{
	vector<Games>::iterator it;
	for (it = games.begin(); it != games.end(); ++it)
	{
		it->displayGameInfo();
	}
}

void saveToFile(string &fileName)
{
	ofstream outFile;
	outFile.open(fileName, ios::app);

	int options;
	cout << "How Many Gives Do You Wish to Save?: " << endl;
	cin >> options;

	string gName;
	double gPrice;
	string gPublisher;
	string gGenre;
	int quantity;
	for (int i = 1; i <= options; i++)
	{
		if (outFile)
		{
			cin.ignore();
			cout << "Game Name: " << endl;
			getline(cin, gName);
			outFile << gName << " ";

			cout << "Game Price: " << endl;
			cin >> gPrice;
			outFile << gPrice << " ";

			cin.ignore();
			cout << "Game Publisher: " << endl;
			getline(cin, gPublisher);
			outFile << gPublisher << " ";

			cout << "Game Genre: " << endl;
			getline(cin, gGenre);
			outFile << gGenre << " ";

			cout << "Quantity: " << endl;
			cin >> quantity;
			outFile << quantity << endl;
		}
		else
		{
			cout << "Unable To Open File";
		}
	}
}

vector<Games>loadToVector()
{
	ifstream fin("C:\\Users\\Allai\\OneDrive\\Documents\\C++\\CA1_Allain_Escobar\\CA1_Allain_Escobar\\games.txt");

	vector<Games> games;
	string gameName;
	double gamePrice;
	string gamePublisher;
	string gameGenre;
	int quantity;
	while (fin >> gameName >> gamePrice >> gamePublisher >> gameGenre >> quantity)
	{
		Games g(gameName, gamePrice, gamePublisher, gameGenre,quantity);
		games.push_back(g);
	}
	fin.close();
	return games;
}


vector<Games>findGames(vector<Games> &games)
{
	vector<Games>::iterator iter = games.begin();
	vector<Games> storeSearch;
	string search;

	cout << "Search By Game Name: " << endl;
	getline(cin, search);

	iter = find(games.begin(), games.end(), search);

	if (iter != games.end())
	{
		cout << *iter << endl << "is on position" << (iter - games.begin() + 1);
		storeSearch.push_back(*iter);
	}
	else
	{
		cout << search << " not found" << endl;
	}

return storeSearch;
}

void searchGames(vector<Games> &games)
{
	string search;
	cout << "Search By Game Or Publisher: " << endl;
	cin >> search;
	bool found = false;
	for (int i = 0; i < games.size(); i++)
	{
		if (games[i].getGameName() == search)
		{
			games[i].displayGameInfo();
			found = true;
		}
		else if (games[i].getGamePublisher() == search)
		{
			games[i].displayGameInfo();
			cout << "No games found." << endl;
			found = true;
		}	
	}
	if(!found)
	{
		cout << "No games found" << endl;
	}
}

void deleteFromFile()
{
	string line, name;
	double price;
	string publisher;
	string genre;
	int quantity;

	string search;
	cout << "Enter Game to be deleted" << endl;
	cin >> search;

	ifstream fileName;
	ofstream temp;

	fileName.open("C:\\Users\\Allai\\OneDrive\\Documents\\C++\\CA1_Allain_Escobar\\CA1_Allain_Escobar\\games.txt");
	temp.open("C:\\Users\\Allai\\OneDrive\\Documents\\C++\\CA1_Allain_Escobar\\CA1_Allain_Escobar\\temp.txt");
	
	int skip = 0;
	while (fileName >> name >> price >> publisher >> genre >> quantity)
	{
		if (search != name)
		{
			temp << name << ' ' << price << ' ' << publisher << ' ' << genre << ' ' << quantity <<  endl;
 		}
		if(search==name)
		{
			skip = 1;
		}
	}

	fileName.clear();
	fileName.seekg(0, ios::beg);
	fileName.close();
	temp.close();
	remove("games.txt");
	rename("temp.txt", "games.txt");
	system("pause");
}

void updateGames(vector<Games> &games)
{	
	ifstream iFile;
	iFile.open("C:\\Users\\Allai\\OneDrive\\Documents\\C++\\CA1_Allain_Escobar\\CA1_Allain_Escobar\\games.txt",ios::app);
	ofstream oFile;
	oFile.open("C:\\Users\\Allai\\OneDrive\\Documents\\C++\\CA1_Allain_Escobar\\CA1_Allain_Escobar\\temp.txt");
	string name;
	cout << "Search Game: " << endl;
	cin >> name;

	int option;
	string newName;
	double newPrice;
	string newPublisher;
	string newGenre;
	int quantity;
	for (int i = 0; i < games.size();i++)
	{
		if (name != games[i].getGameName())
		{
			oFile << games[i].getGameName() << ' ' << games[i].getGamePrice() << ' ' << games[i].getGamePublisher() << ' ' << games[i].getGameGenre() << endl;
		}

		if (name == games[i].getGameName())
		{
			do
			{
				cout << "======================" << endl;
				cout << "|1 - NAME             |" << endl;
				cout << "|2 - price            |" << endl;
				cout << "|3 - Publisher        |" << endl;
				cout << "|4 - Genre            |" << endl;
				cout << "|5 - Quantity         |" << endl;
				cout << "======================" << endl;
				cout << "Option:\t";
				cin >> option;
				switch (option)
				{
				case 0:
					cout << "Exiting" << endl;
					break;
				case 1:
					cout << "New Name: " << endl;
					cin >> newName;
					games[i].setGameName(newName);
					oFile << games[i].getGameName() << " ";
					oFile << games[i].getGamePrice() << " ";
					oFile << games[i].getGamePublisher() << " ";
					oFile << games[i].getGameGenre() << " ";
					break;
				case 2:
					cout << "New Price: " << endl;
					cin >> newPrice;
					games[i].setGamePrice(newPrice);
					oFile << games[i].getGameName() << " ";
					oFile << games[i].getGamePrice() << " ";
					oFile << games[i].getGamePublisher() << " ";
					oFile << games[i].getGameGenre() << " ";
					break;
				case 3:
					cout << "New Publisher: " << endl;
					cin >> newPublisher;
					games[i].setGamePublisher(newPublisher);
					oFile << games[i].getGameName() << " ";
					oFile << games[i].getGamePrice() << " ";
					oFile << games[i].getGamePublisher() << " ";
					oFile << games[i].getGameGenre() << " ";
					break;
				case 4:
					cout << "New Genre: " << endl;
					cin >> newPrice;
					games[i].setGameGenre(newGenre);
					oFile << games[i].getGameName() << " ";
					oFile << games[i].getGamePrice() << " ";
					oFile << games[i].getGamePublisher() << " ";
					oFile << games[i].getGameGenre() << " ";
					break;
				case 5:
					cout << "Update Stock: " << endl;
					cin >> quantity;
					games[i].setQuantity(quantity);
					oFile << games[i].getGameName() << " ";
					oFile << games[i].getGamePrice() << " ";
					oFile << games[i].getGamePublisher() << " ";
					oFile << games[i].getGameGenre() << " ";
					oFile << games[i].getQuantity() << "\n";
				default:
					cout << "Invalid Option" << endl;
					break;
				}
			} while (option != 0);
		}
	}
	iFile.clear();
	iFile.seekg(0, ios::beg);
	iFile.close();
	oFile.close();
	remove("games.txt");
	rename("temp.txt", "games.txt");
	system("pause");
}

void sortByAttribute(vector<Games> &games)
{
	int option;
	do
	{
		cout << "[0] - Exit" << endl;
		cout << "[1] - Sort By Name" << endl;
		cout << "[2] - Sort By Price" << endl;
		cout << "[3] - Sort By Publisher" << endl;
		cout << "[4] - Sort By Genre" << endl;
		cin >> option;
		switch (option)
		{
		case 0:
			cout << "Returning to Menu...." << endl;
			break;
		case 1:
			sort(games.begin(), games.end(), compareName);
			for (vector<Games>::iterator it = games.begin(); it != games.end(); it++)
			{
				it->displayGameInfo();
			}
			break;
		case 2:
			sort(games.begin(), games.end(), comparePrice);
			for (vector<Games>::iterator it = games.begin(); it != games.end(); it++)
			{
				it->displayGameInfo();
			}
			break;
		case 3:
			sort(games.begin(), games.end(), comparePublisher);
			for (vector<Games>::iterator it = games.begin(); it != games.end(); it++)
			{
				it->displayGameInfo();
			}
			break;
		case 4:
			sort(games.begin(), games.end(), compareGenre);
			for (vector<Games>::iterator it = games.begin(); it != games.end(); it++)
			{
				it->displayGameInfo();
			}
			break;
		default:
			cout << "Invalid Input" << endl;
			break;
		}
	} while (option != 0);
}

void setColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

