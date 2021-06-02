#pragma once

#include <string>
using namespace std;

class composition {
private:
	string name;
	string artistName;
	string text;
	int price;

public:
	composition(string name, string artistName, int price, string text) {
		this->name = name;
		this->artistName = artistName;
		this->price = price;
		this->text = text;
	}

	string getName() {
		return name;
	}

	int getPrice() {
		return price;
	}

	string getArtistName() {
		return artistName;
	}

	string getText() {
		return text;
	}
};