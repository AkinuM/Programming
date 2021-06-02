#pragma once

#include "album.cpp"
using namespace std;

class artist {
private:
	string name;
	string info;
	vector<composition> compositions;
	vector<album> albums;

public:
	artist(vector<composition> compositions, vector<album> albums, string  info) {
		this->name = compositions[0].getArtistName();
		this->info = info;
		this->compositions = compositions;
		this->albums = albums;
	}

	string getName() {
		return name;
	}

	string getInfo() {
		return info;
	}

	vector<album> getAlbums() {
		return albums;
	}

	vector<composition> getCompositions() {
		return compositions;
	}
};