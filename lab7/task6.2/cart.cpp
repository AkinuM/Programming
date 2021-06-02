#include "album.cpp"
using namespace std;

class cart {
	vector<composition> compositions;
	vector<album> albums;
	int price = 0;

public:
	vector<composition> *getCompositions() {
		return &compositions;
	}

	vector<album> *getAlbums() {
		return &albums;
	}

	int *getPrice() {
		return &price;
	}
};