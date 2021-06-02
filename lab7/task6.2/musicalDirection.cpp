#include "artist.cpp"
using namespace std;

class musicalDirection {
private:
	string name;
	string info;
	vector<artist> artists;

public:
	musicalDirection(string name, vector<artist> artists, string  info) {
		this->name = name;
		this->info = info;
		this->artists = artists;
	}

	string getName() {
		return name;
	}

	string getInfo() {
		return info;
	}

	vector<artist> getArtists() {
		return artists;
	}
};