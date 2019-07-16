#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::to_string;
using std::string;
using std::ostream;
using std::istream;

class Games
{
	friend ostream& operator<<(ostream& out, Games& g);
	friend ofstream& operator<<(ofstream& out, const Games &g);
	friend ifstream& operator>>(ifstream& in, Games &g);

public:
	Games();
	Games(string gameName, double gamePrice, string gamePublisher, string gameGenre,int quantity);
	~Games();
	void setGameName(string gameName);
	void setGamePrice(double gamePrice);
	void setGamePublisher(string gamePublisher);
	void setGameGenre(string gameGenre);
	void setQuantity(int quantity);
	string getGameName()const;
	double getGamePrice() const;
	string getGamePublisher()const;
	string getGameGenre()const;
	int getQuantity()const;
	void displayGameInfo() const;
	bool operator==(string gName);

private:
	string gameName;
	double gamePrice;
	string gamePublisher;
	string gameGenre;
	int quantity;
};