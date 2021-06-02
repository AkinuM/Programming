#pragma once

#include "composition.cpp"
#include <vector>
using namespace std;

class album {
private:
	string name;
	string artistName;
	int price = 0;
	vector<composition> compositions;

public:
	album(string name, vector<composition> compositions) {
		this->name = name;
		this->artistName = compositions[0].getArtistName();
		for (int i = 0; i < (int) compositions.size(); i++) {
			this->price += compositions[i].getPrice();
		}
		this->compositions = compositions;
	}

	int getPrice() {
		return price;
	}

	string getName() {
		return name;
	}

	vector<composition> getCompositions() {
		return compositions;
	}
};