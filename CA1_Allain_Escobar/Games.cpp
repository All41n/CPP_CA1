#include "stdafx.h"
#include "targetver.h"
#include "GameLibrary.h"
#include "Games.h"
#include "Snakes.h"
#include "GameClass.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>

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

bool isLoggedIn()
{
	string username, password, un, pw;
	cout << "Username: " << endl;
	cin >> username;
	cout << "Password: " << endl;
	cin >> password;

	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
	{
		return true;
		//menu();
	}
	else
	{
		return false;
	}
}

 void menu()
{
	vector<Games> games;//Main Vector Containers
	vector<Games> gamesFinder;//using find stl::find algorithm
	vector<Games> fromFile;//Loading From File;
	vector<Games> storedDelete;
	vector<Games> shopping;
	vector<Games> storeShopping;
	static string fileName ="games2.txt";

	int options;
	do {
		setColor(2);
		cout << endl;
		cout << "0 - Exit App" << endl;
		cout << "1 - Load & Display Details" << endl;
		cout << "2 - Enter Game Details" << endl;
		cout << "3 - Search Games" << endl;
		cout << "4 - Search Using Find Algorithm" << endl;
		cout << "5 - Delete Game" << endl;
		cout << "6 - Print Sort" << endl;
		cout << "7 - Update Games" << endl;
		cout << "8 - Play Simple Snakes" << endl;
		cout << "Enter Options:\t";
		cin >>options;
		cin.ignore(1000, '\n');
		switch (options)
		{
		case 0:
			cout << "Exiting.." << endl;
			break;
		case 1:
			games = loadToVector();
			for (int i = 0; i < games.size(); i++)
			{
				cout << games[i];
			}
			break;
		case 2:
			saveToFile(fileName);
			break;
		case 3:
			searchGames(games);
			break;
		case 4:
			gamesFinder = findGames(games);
			break;
		case 5:
			deleteFromFile();
			break;
		case 6:
			sortByAttribute(games);
			break;
		case 7:
			updateGames(games);
			break;
		case 8:
			snakes();
			break;
		default:
			cout << "Invalid Option" << endl;
			break;
		}
	} while (options != 0);
}

 int main()
 {
	 int choice;
	 setColor(3);
	 cout << "======================" << endl;
	 cout << "|1 - Register        |" << endl;
	 cout << "|2 - Login(User)     |" << endl;
	 cout << "======================" << endl;
	 cout << "Option:\t";
	 cin >> choice;
	 do
	 {
		 switch (choice)
		 {
		 case 1:
		 {
			 string username, password;
			 cout << "Enter Username" << endl;
			 cin >> username;

			 cout << "Enter Password" << endl;
			 cin >> password;

			 ofstream file;
			 file.open(username + ".txt");
			 file << username << endl << password;
			 file.close();
			 main();
			 break;
		 }
		 case 2:
		 {
			 bool status = isLoggedIn();
			 if (!status)
			 {
				 cout << "Unable to login" << endl;
				 system("PAUSE");
				 main();
				 return 0;
			 }
			 else
			 {
				 cout << "Login Success" << endl;
				 system("PAUSE");
				 menu();
				 cout << endl;
				 return 1;
			 }
		 }
		 }
	 } while (choice != 0);
 }
