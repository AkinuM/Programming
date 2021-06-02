#include "musicalDirection.cpp"
#include "cart.cpp"
#include <fstream>
using namespace std;



class mp3All {
private:
	vector<artist> allArtists;
	vector<composition> allCompositions;
	vector<album> allAlbums;
	vector<musicalDirection> allMusicalDirections;
	cart shopCart;
	ifstream fin;
	int countCompositions = 0;
	int countCompositionsSold = 0;
	int revenue = 0;

public:
	mp3All() {
		fin.open("data.txt");
	}

	void addCompositions() {
		string str;
		getline(fin, str);
		while (str != "#") {
			int i, tempPrice;
			string tempName, tempArtistName, tempText, strPrice;
			for (i = 0; str[i] != ' '; i++) {
				tempName += str[i];
			}
			for (i += 1; str[i] != ' '; i++) {
				tempArtistName += str[i];
			}
			for (i += 1; i < (int) str.size(); i++) {
				strPrice += str[i];
			}
			tempPrice = stoi(strPrice);
			getline(fin, str, '!');
			tempText = str;
			composition tempComposition(tempName, tempArtistName, tempPrice, tempText);
			allCompositions.push_back(tempComposition);
			countCompositions++;
			getline(fin, str);
			getline(fin, str);
		}
	}

	void addAlbums() {
		string str;
		getline(fin, str);
		while (str != "#") {
			string tempName, strComposition;
			vector<composition> tempCompositions;
			tempName = str;
			getline(fin, str);
			int i = 0;
			while (str[i] != '\0') {
				for (i; str[i] != ' ' && str[i] != '\0'; i++) {
					strComposition += str[i];
				}
				if (str[i] == ' ') {
					i++;
				}
				for (composition tempComposition : allCompositions) {
					if (tempComposition.getName() == strComposition) {
						tempCompositions.push_back(tempComposition);
					}
				}
			}
			album tempAlbum(tempName, tempCompositions);
			allAlbums.push_back(tempAlbum);
			getline(fin, str);
		}
	}

	void addArtists() {
		string str;
		getline(fin, str, '#');
		while (str != "#") {
			string strComposition, strAlbum, tempInfo;
			vector<composition> tempCompositions;
			vector<album> tempAlbums;
			int i = 0;
			while (str[i] != '\n') {
				for (i; str[i] != ' ' && str[i] != '\n' && str[i] != '\0'; i++) {
					strComposition += str[i];
				}
				for (composition tempComposition : allCompositions) {
					if (tempComposition.getName() == strComposition) {
						tempCompositions.push_back(tempComposition);
					}
				}
				if (str[i] == ' ') {
					i++;
				}
				else if (str[i] == '\0') {
					break;
				}
			}
			if (str[i] != '\0') {
				i++;
			}
			while (str[i] != '\0') {
				for (i; str[i] != ' ' && str[i] != '\0'; i++) {
					strAlbum += str[i];
				}
				if (str[i] == ' ') {
					i++;
				}
				for (album tempAlbum : allAlbums) {
					if (tempAlbum.getName() == strAlbum) {
						tempAlbums.push_back(tempAlbum);
					}
				}
			}
			getline(fin, str);
			getline(fin, str, '!');
			tempInfo = str;
			artist tempArtist(tempCompositions, tempAlbums, tempInfo);
			allArtists.push_back(tempArtist);
			getline(fin, str);
			getline(fin, str);
			if (str != "#") {
				string temp;
				getline(fin, temp, '#');
				str = str + '\n' + temp;
			}
		}
	}

	void addMusicalDirections() {
		string str;
		getline(fin, str);
		while (str != "#") {
			string tempName, strArtist, tempInfo;
			vector<artist> tempArtists;
			tempName = str;
			getline(fin, str);
			int i = 0;
			while (str[i] != '\0') {
				for (i; str[i] != ' ' && str[i] != '\0'; i++) {
					strArtist += str[i];
				}
				if (str[i] == ' ') {
					i++;
				}
				for (artist tempArtist : allArtists) {
					if (tempArtist.getName() == strArtist) {
						tempArtists.push_back(tempArtist);
					}
				}
			}
			getline(fin, str, '!');
			tempInfo = str;
			musicalDirection tempMusicalDirection(tempName, tempArtists, tempInfo);
			allMusicalDirections.push_back(tempMusicalDirection);
			getline(fin, str);
			getline(fin, str);
		}
	}

	vector<musicalDirection> getAllMusicalDirections() {
		return allMusicalDirections;
	}

	vector<artist> getAllArtists() {
		return allArtists;
	}

	vector<composition> getAllCompositions() {
		return allCompositions;
	}


	vector<album> getAllAlbums() {
		return allAlbums;
	}

	cart *getShopCart() {
		return &shopCart;
	}

	int *getCountCompositionsSold() {
		return &countCompositionsSold;
	}

	int *getRevenue() {
		return &revenue;
	}

	int getCountCompositions() {
		return countCompositions;
	}
};