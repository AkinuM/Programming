#include "checker.h"

void setChechers(checker *checkers[]) {
	int i = 0;
	for (int line = 0; line < 5; line++) {
		for (int column = 0; column < 9; column++) {
			float x = 27, y = 27;
			if (line < 2) {
				checkers[i] = new checker((float)(x + 126.2 * column), (float)(y + 126.2 * line), 0);
			}
			else if (line > 2) {
				checkers[i] = new checker((float)(x + 126.2 * column), (float)(y + 126.2 * line), 1);
			}
			else if (column == 4) {
				continue;
			}
			else if (column % 2 == 0) {
				checkers[i] = new checker((float)(x + 126.2 * column), (float)(y + 126.2 * line), 0);
			}
			else {
				checkers[i] = new checker((float)(x + 126.2 * column), (float)(y + 126.2 * line), 1);
			}
			i++;
		}
	}
}

void drawCheckers(checker *checkers[], RenderWindow *window) {
	for (int i = 0; i < 44; i++) {
		window->draw(*checkers[i]->getShape());
	}
}

void capture(checker *checkers[], RenderWindow *window, int i, int column, char sign, int *countRemoved, bool *endTurn) {
	if (sign == '-') {
		while (!*endTurn) {
			int j;
			for (j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if (column - *countRemoved - 1 < 0) {
					*endTurn = 1;
					break;
				}
				if (round((*checkers[j]->getX() - 27) / 126.2) == round(column - *countRemoved - 1) && *checkers[j]->getY() == *checkers[i]->getY()) {
					if (checkers[j]->getColor() != checkers[i]->getColor()) {
						checkers[j]->getShape()->setRadius(0);
						checkers[j]->getShape()->setOutlineThickness(0);
						window->draw(*checkers[j]->getShape());
						(*countRemoved)++;
						*checkers[j]->getInGame() = 0;
					}
					else {
						*endTurn = 1;
					}
					break;
				}
			}
			if (j == 44) {
				break;
			}
		}
		if (*countRemoved == 0) { 
			*endTurn = 0;
			while (!*endTurn) {
				int j;
				for (j = 0; j < 44; j++) {
					if (*checkers[j]->getInGame() == 0) {
						continue;
					}
					if (column + *countRemoved + 2 > 8) {
						*endTurn = 1;
						break;
					}
					if (round((*checkers[j]->getX() - 27) / 126.2) == round(column + *countRemoved + 2) && *checkers[j]->getY() == *checkers[i]->getY()) {
						if (checkers[j]->getColor() != checkers[i]->getColor()) {
							checkers[j]->getShape()->setRadius(0);
							checkers[j]->getShape()->setOutlineThickness(0);
							window->draw(*checkers[j]->getShape());
							(*countRemoved)++;
							*checkers[j]->getInGame() = 0;
						}
						else {
							*endTurn = 1;
						}
						break;
					}
				}
				if (j == 44) {
					break;
				}
			}
		}
	}
	else {
		while (!*endTurn) {
			int j;
			for (j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if (column + *countRemoved + 1 < 0) {
					*endTurn = 1;
					break;
				}
				if (round((*checkers[j]->getX() - 27) / 126.2) == round(column + *countRemoved + 1) && *checkers[j]->getY() == *checkers[i]->getY()) {
					if (checkers[j]->getColor() != checkers[i]->getColor()) {
						checkers[j]->getShape()->setRadius(0);
						checkers[j]->getShape()->setOutlineThickness(0);
						window->draw(*checkers[j]->getShape());
						(*countRemoved)++;
						*checkers[j]->getInGame() = 0;
					}
					else {
						*endTurn = 1;
					}
					break;
				}
			}
			if (j == 44) {
				break;
			}
		}
		if (*countRemoved == 0) { 
			*endTurn = 0;
			while (!*endTurn) {
				int j;
				for (j = 0; j < 44; j++) {
					if (*checkers[j]->getInGame() == 0) {
						continue;
					}
					if (column - *countRemoved - 2 > 8) {
						*endTurn = 1;
						break;
					}
					if (round((*checkers[j]->getX() - 27) / 126.2) == round(column - *countRemoved - 2) && *checkers[j]->getY() == *checkers[i]->getY()) {
						if (checkers[j]->getColor() != checkers[i]->getColor()) {
							checkers[j]->getShape()->setRadius(0);
							checkers[j]->getShape()->setOutlineThickness(0);
							window->draw(*checkers[j]->getShape());
							(*countRemoved)++;
							*checkers[j]->getInGame() = 0;
						}
						else {
							*endTurn = 1;
						}
						break;
					}
				}
				if (j == 44) {
					break;
				}
			}
		}
	}

}

void capture(checker *checkers[], RenderWindow *window, int i, char sign, int line, int *countRemoved, bool *endTurn) {
	if (sign == '-') {
		while (!*endTurn) {
			int j;
			for (j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if (line - *countRemoved - 1 < 0) {
					*endTurn = 1;
					break;
				}
				if (round((*checkers[j]->getY() - 27) / 126.2) == round(line - *countRemoved - 1) && *checkers[j]->getX() == *checkers[i]->getX()) {
					if (checkers[j]->getColor() != checkers[i]->getColor()) {
						checkers[j]->getShape()->setRadius(0);
						checkers[j]->getShape()->setOutlineThickness(0);
						window->draw(*checkers[j]->getShape());
						(*countRemoved)++;
						*checkers[j]->getInGame() = 0;
					}
					else {
						*endTurn = 1;
					}
					break;
				}
			}
			if (j == 44) {
				break;
			}
		}
		if (*countRemoved == 0) { 
			*endTurn = 0;
			while (!*endTurn) {
				int j;
				for (j = 0; j < 44; j++) {
					if (*checkers[j]->getInGame() == 0) {
						continue;
					}
					if (line + *countRemoved + 2 > 4) {
						*endTurn = 1;
						break;
					}
					if (round((*checkers[j]->getY() - 27) / 126.2) == round(line + *countRemoved + 2) && *checkers[j]->getX() == *checkers[i]->getX()) {
						if (checkers[j]->getColor() != checkers[i]->getColor()) {
							checkers[j]->getShape()->setRadius(0);
							checkers[j]->getShape()->setOutlineThickness(0);
							window->draw(*checkers[j]->getShape());
							(*countRemoved)++;
							*checkers[j]->getInGame() = 0;
						}
						else {
							*endTurn = 1;
						}
						break;
					}
				}
				if (j == 44) {
					break;
				}
			}
		}
	}
	else {
		while (!*endTurn) { 
			int j;
			for (j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if (line + *countRemoved + 1 > 4) {
					*endTurn = 1;
					break;
				}
				if (round((*checkers[j]->getY() - 27) / 126.2) == round(line + *countRemoved + 1) && *checkers[j]->getX() == *checkers[i]->getX()) {
					if (checkers[j]->getColor() != checkers[i]->getColor()) {
						checkers[j]->getShape()->setRadius(0);
						checkers[j]->getShape()->setOutlineThickness(0);
						window->draw(*checkers[j]->getShape());
						(*countRemoved)++;
						*checkers[j]->getInGame() = 0;
					}
					else {
						*endTurn = 1;
					}
					break;
				}
			}
			if (j == 44) {
				break;
			}
		}
		if (*countRemoved == 0) { 
			*endTurn = 0;
			while (!*endTurn) {
				int j;
				for (j = 0; j < 44; j++) {
					if (*checkers[j]->getInGame() == 0) {
						continue;
					}
					if (line - *countRemoved - 2 < 0) {
						*endTurn = 1;
						break;
					}
					if (round((*checkers[j]->getY() - 27) / 126.2) == round(line - *countRemoved - 2) && *checkers[j]->getX() == *checkers[i]->getX()) {
						if (checkers[j]->getColor() != checkers[i]->getColor()) {
							checkers[j]->getShape()->setRadius(0);
							checkers[j]->getShape()->setOutlineThickness(0);
							window->draw(*checkers[j]->getShape());
							(*countRemoved)++;
							*checkers[j]->getInGame() = 0;
						}
						else {
							*endTurn = 1;
						}
						break;
					}
				}
				if (j == 44) {
					break;
				}
			}
		}
	}
}

void capture(checker *checkers[], RenderWindow *window, int i, int line, int column, char sign1, char sign2, int *countRemoved, bool *endTurn) {
	if (sign1 == '-') {
		if (sign2 == '-') {
			while (!*endTurn) {
				int j;
				for (j = 0; j < 44; j++) {
					if (*checkers[j]->getInGame() == 0) {
						continue;
					}
					if (line - *countRemoved - 1 < 0 || column - *countRemoved - 1 < 0) {
						*endTurn = 1;
						break;
					}
					if (round((*checkers[j]->getY() - 27) / 126.2) == round(line - *countRemoved - 1) && round((*checkers[j]->getX() - 27) / 126.2) == round(column - *countRemoved - 1)) {
						if (checkers[j]->getColor() != checkers[i]->getColor()) {
							checkers[j]->getShape()->setRadius(0);
							checkers[j]->getShape()->setOutlineThickness(0);
							window->draw(*checkers[j]->getShape());
							(*countRemoved)++;
							*checkers[j]->getInGame() = 0;
						}
						else {
							*endTurn = 1;
						}
						break;
					}
				}
				if (j == 44) {
					break;
				}
			}
			if (*countRemoved == 0) { 
				*endTurn = 0;
				while (!*endTurn) {
					int j;
					for (j = 0; j < 44; j++) {
						if (*checkers[j]->getInGame() == 0) {
							continue;
						}
						if (column + *countRemoved + 2 > 8 || line + *countRemoved + 2 > 4) {
							*endTurn = 1;
							break;
						}
						if (round((*checkers[j]->getY() - 27) / 126.2) == round(line + *countRemoved + 2) && round((*checkers[j]->getX() - 27) / 126.2) == round(column + *countRemoved + 2)) {
							if (checkers[j]->getColor() != checkers[i]->getColor()) {
								checkers[j]->getShape()->setRadius(0);
								checkers[j]->getShape()->setOutlineThickness(0);
								window->draw(*checkers[j]->getShape());
								(*countRemoved)++;
								*checkers[j]->getInGame() = 0;
							}
							else {
								*endTurn = 1;
							}
							break;
						}
					}
					if (j == 44) {
						break;
					}
				}
			}
		}
		else {
			while (!*endTurn) { 
				int j;
				for (j = 0; j < 44; j++) {
					if (*checkers[j]->getInGame() == 0) {
						continue;
					}
					if (line - *countRemoved - 1 < 0 || column + *countRemoved + 1 > 8) {
						*endTurn = 1;
						break;
					}
					if (round((*checkers[j]->getY() - 27) / 126.2) == round(line - *countRemoved - 1) && round((*checkers[j]->getX() - 27) / 126.2) == round(column + *countRemoved + 1)) {
						if (checkers[j]->getColor() != checkers[i]->getColor()) {
							checkers[j]->getShape()->setRadius(0);
							checkers[j]->getShape()->setOutlineThickness(0);
							window->draw(*checkers[j]->getShape());
							(*countRemoved)++;
							*checkers[j]->getInGame() = 0;
						}
						else {
							*endTurn = 1;
						}
						break;
					}
				}
				if (j == 44) {
					break;
				}
			}
			if (*countRemoved == 0) { 
				*endTurn = 0;
				while (!*endTurn) {
					int j;
					for (j = 0; j < 44; j++) {
						if (*checkers[j]->getInGame() == 0) {
							continue;
						}
						if (column - *countRemoved - 2 < 0 || line + *countRemoved + 2 > 4) {
							*endTurn = 1;
							break;
						}
						if (round((*checkers[j]->getY() - 27) / 126.2) == round(line + *countRemoved + 2) && round((*checkers[j]->getX() - 27) / 126.2) == round(column - *countRemoved - 2)) {
							if (checkers[j]->getColor() != checkers[i]->getColor()) {
								checkers[j]->getShape()->setRadius(0);
								checkers[j]->getShape()->setOutlineThickness(0);
								window->draw(*checkers[j]->getShape());
								(*countRemoved)++;
								*checkers[j]->getInGame() = 0;
							}
							else {
								*endTurn = 1;
							}
							break;
						}
					}
					if (j == 44) {
						break;
					}
				}
			}
		}
	}
	else if (sign2 == '-') {
		while (!*endTurn) {
			int j;
			for (j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if (line + *countRemoved + 1 > 4 || column - *countRemoved - 1 < 0) {
					*endTurn = 1;
					break;
				}
				if (round((*checkers[j]->getY() - 27) / 126.2) == round(line + *countRemoved + 1) && round((*checkers[j]->getX() - 27) / 126.2) == round(column - *countRemoved - 1)) {
					if (checkers[j]->getColor() != checkers[i]->getColor()) {
						checkers[j]->getShape()->setRadius(0);
						checkers[j]->getShape()->setOutlineThickness(0);
						window->draw(*checkers[j]->getShape());
						(*countRemoved)++;
						*checkers[j]->getInGame() = 0;
					}
					else {
						*endTurn = 1;
					}
					break;
				}
			}
			if (j == 44) {
				break;
			}
		}
		if (*countRemoved == 0) { 
			*endTurn = 0;
			while (!*endTurn) {
				int j;
				for (j = 0; j < 44; j++) {
					if (*checkers[j]->getInGame() == 0) {
						continue;
					}
					if (column + *countRemoved + 2 > 8 || line - *countRemoved - 2 < 0) {
						*endTurn = 1;
						break;
					}
					if (round((*checkers[j]->getY() - 27) / 126.2) == round(line - *countRemoved - 2) && round((*checkers[j]->getX() - 27) / 126.2) == round(column + *countRemoved + 2)) {
						if (checkers[j]->getColor() != checkers[i]->getColor()) {
							checkers[j]->getShape()->setRadius(0);
							checkers[j]->getShape()->setOutlineThickness(0);
							window->draw(*checkers[j]->getShape());
							(*countRemoved)++;
							*checkers[j]->getInGame() = 0;
						}
						else {
							*endTurn = 1;
						}
						break;
					}
				}
				if (j == 44) {
					break;
				}
			}
		}
	}
	else {
		while (!*endTurn) { 
			int j;
			for (j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if (line + *countRemoved + 1 > 4 || column + *countRemoved + 1 > 8) {
					*endTurn = 1;
					break;
				}
				if (round((*checkers[j]->getY() - 27) / 126.2) == round(line + *countRemoved + 1) && round((*checkers[j]->getX() - 27) / 126.2) == round(column + *countRemoved + 1)) {
					if (checkers[j]->getColor() != checkers[i]->getColor()) {
						checkers[j]->getShape()->setRadius(0);
						checkers[j]->getShape()->setOutlineThickness(0);
						window->draw(*checkers[j]->getShape());
						(*countRemoved)++;
						*checkers[j]->getInGame() = 0;
					}
					else {
						*endTurn = 1;
					}
					break;
				}
			}
			if (j == 44) {
				break;
			}
		}
		if (*countRemoved == 0) { 
			*endTurn = 0;
			while (!*endTurn) {
				int j;
				for (j = 0; j < 44; j++) {
					if (*checkers[j]->getInGame() == 0) {
						continue;
					}
					if (column - *countRemoved - 2 < 0 || line - *countRemoved - 2 < 0) {
						*endTurn = 1;
						break;
					}
					if (round((*checkers[j]->getY() - 27) / 126.2) == round(line - *countRemoved - 2) && round((*checkers[j]->getX() - 27) / 126.2) == round(column - *countRemoved - 2)) {
						if (checkers[j]->getColor() != checkers[i]->getColor()) {
							checkers[j]->getShape()->setRadius(0);
							checkers[j]->getShape()->setOutlineThickness(0);
							window->draw(*checkers[j]->getShape());
							(*countRemoved)++;
							*checkers[j]->getInGame() = 0;
						}
						else {
							*endTurn = 1;
						}
						break;
					}
				}
				if (j == 44) {
					break;
				}
			}
		}
	}
}

void checkExtraMove(checker *checkers[], int i, int column, char sign, bool *extraMove) {
	if (sign == '-') {
		int k;
		for (k = 0; k < 44; k++) {
			if (*checkers[k]->getInGame() == 0) {
				continue;
			}
			if ((round((*checkers[k]->getX() - 27) / 126.2) == round(column - 1) && *checkers[k]->getY() == *checkers[i]->getY()) || round(column - 1) < 0) {
				break;
			}
		}
		if (k == 44) {
			for (int j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if ((round((*checkers[j]->getX() - 27) / 126.2) == round(column - 2) && *checkers[j]->getY() == *checkers[i]->getY() && checkers[j]->getColor() != checkers[i]->getColor()) || (round((*checkers[j]->getX() - 27) / 126.2) == round(column + 1) && *checkers[j]->getY() == *checkers[i]->getY() && checkers[j]->getColor() != checkers[i]->getColor())) {
					*extraMove = 1;
				}
			}
		}
	}
	else {
		int k;
		for (k = 0; k < 44; k++) {
			if (*checkers[k]->getInGame() == 0) {
				continue;
			}
			if ((round((*checkers[k]->getX() - 27) / 126.2) == round(column + 1) && *checkers[k]->getY() == *checkers[i]->getY()) || round(column + 1) > 8) {
				break;
			}
		}
		if (k == 44) {
			for (int j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if ((round((*checkers[j]->getX() - 27) / 126.2) == round(column - 1) && *checkers[j]->getY() == *checkers[i]->getY() && checkers[j]->getColor() != checkers[i]->getColor()) || (round((*checkers[j]->getX() - 27) / 126.2) == round(column + 2) && *checkers[j]->getY() == *checkers[i]->getY() && checkers[j]->getColor() != checkers[i]->getColor())) {
					*extraMove = 1;
				}
			}
		}
	}
}

void checkExtraMove(checker *checkers[], int i, char sign, int line, bool *extraMove) {
	if (sign == '-') {
		int k;
		for (k = 0; k < 44; k++) {
			if (*checkers[k]->getInGame() == 0) {
				continue;
			}
			if ((round((*checkers[k]->getY() - 27) / 126.2) == round(line - 1) && *checkers[k]->getX() == *checkers[i]->getX()) || round(line - 1) < 0) {
				break;
			}
		}
		if (k == 44) {
			for (int j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if ((round((*checkers[j]->getY() - 27) / 126.2) == round(line - 2) && *checkers[j]->getX() == *checkers[i]->getX() && checkers[j]->getColor() != checkers[i]->getColor()) || (round((*checkers[j]->getY() - 27) / 126.2) == round(line + 1) && *checkers[j]->getX() == *checkers[i]->getX() && checkers[j]->getColor() != checkers[i]->getColor())) {
					*extraMove = 1;
				}
			}
		}
	}
	else {
		int k;
		for (k = 0; k < 44; k++) {
			if (*checkers[k]->getInGame() == 0) {
				continue;
			}
			if ((round((*checkers[k]->getY() - 27) / 126.2) == round(line + 1) && *checkers[k]->getX() == *checkers[i]->getX()) || round(line + 1) > 4) {
				break;
			}
		}
		if (k == 44) {
			for (int j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if ((round((*checkers[j]->getY() - 27) / 126.2) == round(line - 1) && *checkers[j]->getX() == *checkers[i]->getX() && checkers[j]->getColor() != checkers[i]->getColor()) || (round((*checkers[j]->getY() - 27) / 126.2) == round(line + 2) && *checkers[j]->getX() == *checkers[i]->getX() && checkers[j]->getColor() != checkers[i]->getColor())) {
					*extraMove = 1;
				}
			}
		}
	}
}

void checkExtraMove(checker *checkers[], int i, int line, int column, char sign1, char sign2, bool *extraMove) {
	if (sign1 == '-') {
		if (sign2 == '-') {
			int k;
			for (k = 0; k < 44; k++) {
				if (*checkers[k]->getInGame() == 0) {
					continue;
				}
				if ((round((*checkers[k]->getY() - 27) / 126.2) == round(line - 1) && round((*checkers[k]->getX() - 27) / 126.2) == round(column - 1)) || round(line - 1) < 0 || round(column - 1) < 0) {
					break;
				}
			}
			if (k == 44) {
				for (int j = 0; j < 44; j++) {
					if (*checkers[j]->getInGame() == 0) {
						continue;
					}
					if ((round((*checkers[j]->getY() - 27) / 126.2) == round(line - 2) && round((*checkers[j]->getX() - 27) / 126.2) == round(column - 2) && checkers[j]->getColor() != checkers[i]->getColor()) || (round((*checkers[j]->getY() - 27) / 126.2) == round(line + 1) && round((*checkers[j]->getX() - 27) / 126.2) == round(column + 1) && checkers[j]->getColor() != checkers[i]->getColor())) {
						*extraMove = 1;
					}
				}
			}
		}
		else {
			int k;
			for (k = 0; k < 44; k++) {
				if (*checkers[k]->getInGame() == 0) {
					continue;
				}
				if ((round((*checkers[k]->getY() - 27) / 126.2) == round(line - 1) && round((*checkers[k]->getX() - 27) / 126.2) == round(column + 1)) || round(line - 1) < 0 || round(column + 1) > 8) {
					break;
				}
			}
			if (k == 44) {
				for (int j = 0; j < 44; j++) {
					if (*checkers[j]->getInGame() == 0) {
						continue;
					}
					if ((round((*checkers[j]->getY() - 27) / 126.2) == round(line - 2) && round((*checkers[j]->getX() - 27) / 126.2) == round(column + 2) && checkers[j]->getColor() != checkers[i]->getColor()) || (round((*checkers[j]->getY() - 27) / 126.2) == round(line + 1) && round((*checkers[j]->getX() - 27) / 126.2) == round(column - 1) && checkers[j]->getColor() != checkers[i]->getColor())) {
						*extraMove = 1;
					}
				}
			}
		}
	}
	else if (sign2 == '-') {
		int k;
		for (k = 0; k < 44; k++) {
			if (*checkers[k]->getInGame() == 0) {
				continue;
			}
			if ((round((*checkers[k]->getY() - 27) / 126.2) == round(line + 1) && round((*checkers[k]->getX() - 27) / 126.2) == round(column - 1)) || round(line + 1) > 4 || round(column - 1) < 0) {
				break;
			}
		}
		if (k == 44) {
			for (int j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if ((round((*checkers[j]->getY() - 27) / 126.2) == round(line + 2) && round((*checkers[j]->getX() - 27) / 126.2) == round(column - 2) && checkers[j]->getColor() != checkers[i]->getColor()) || (round((*checkers[j]->getY() - 27) / 126.2) == round(line - 1) && round((*checkers[j]->getX() - 27) / 126.2) == round(column + 1) && checkers[j]->getColor() != checkers[i]->getColor())) {
					*extraMove = 1;
				}
			}
		}
	}
	else {
		int k;
		for (k = 0; k < 44; k++) {
			if (*checkers[k]->getInGame() == 0) {
				continue;
			}
			if ((round((*checkers[k]->getY() - 27) / 126.2) == round(line + 1) && round((*checkers[k]->getX() - 27) / 126.2) == round(column + 1)) || round(line + 1) > 4 || round(column + 1) > 8) {
				break;
			}
		}
		if (k == 44) {
			for (int j = 0; j < 44; j++) {
				if (*checkers[j]->getInGame() == 0) {
					continue;
				}
				if ((round((*checkers[j]->getY() - 27) / 126.2) == round(line + 2) && round((*checkers[j]->getX() - 27) / 126.2) == round(column + 2) && checkers[j]->getColor() != checkers[i]->getColor()) || (round((*checkers[j]->getY() - 27) / 126.2) == round(line - 1) && round((*checkers[j]->getX() - 27) / 126.2) == round(column - 1) && checkers[j]->getColor() != checkers[i]->getColor())) {
					*extraMove = 1;
				}
			}
		}
	}
}

void makeMove(checker *checkers[], RenderWindow *window, int i, int line, int column, float checkerLine, float checkerColumn, bool *whoseTurn, bool *extraMove, int *countRemoved, char sign) {
	*checkers[i]->getX() = (float)(27 + 126.2 * column);
	*checkers[i]->getY() = (float)(27 + 126.2 * line);
	bool endTurn = 0;
	if (sign == '+') {
		if (line == (int)checkerLine) {
			if (column == (int)checkerColumn - 1) { 
				capture(checkers, window, i, column, '-', countRemoved, &endTurn); // cлева креста
			}
			else {
				capture(checkers, window, i, column, '+', countRemoved, &endTurn); // справа креста
			}
		}
		else if (line == (int)checkerLine - 1) { 
			capture(checkers, window, i, '-', line, countRemoved, &endTurn); // сверху креста
		}
		else {
			capture(checkers, window, i, '+', line, countRemoved, &endTurn); // снизу креста
		}
		if (*countRemoved != 0) {
			checkExtraMove(checkers, i, column, '-', extraMove);
			checkExtraMove(checkers, i, column, '+', extraMove);
			checkExtraMove(checkers, i, '-', line, extraMove);
			checkExtraMove(checkers, i, '+', line, extraMove);
			checkExtraMove(checkers, i, line, column, '-', '-', extraMove);
			checkExtraMove(checkers, i, line, column, '-', '+', extraMove);
			checkExtraMove(checkers, i, line, column, '+', '-', extraMove);
			checkExtraMove(checkers, i, line, column, '+', '+', extraMove);
		}
	}
	else {
		if (line == (int)checkerLine - 1) {
			if (column == (int)checkerColumn - 1) { 
				capture(checkers, window, i, line, column, '-', '-', countRemoved, &endTurn); // верхний левый угол звезды
				if (*countRemoved != 0) {
					checkExtraMove(checkers, i, column, '-', extraMove);
					checkExtraMove(checkers, i, column, '+', extraMove);
					checkExtraMove(checkers, i, '-', line, extraMove);
					checkExtraMove(checkers, i, '+', line, extraMove);
					checkExtraMove(checkers, i, line, column, '-', '-', extraMove);
					checkExtraMove(checkers, i, line, column, '-', '+', extraMove);
					checkExtraMove(checkers, i, line, column, '+', '-', extraMove);
					checkExtraMove(checkers, i, line, column, '+', '+', extraMove);
				}
			}
			else if (column == (int)checkerColumn) { 
				capture(checkers, window, i, '-', line, countRemoved, &endTurn); // сверху звезды
				if (*countRemoved != 0) {
					checkExtraMove(checkers, i, column, '-', extraMove);
					checkExtraMove(checkers, i, column, '+', extraMove);
					checkExtraMove(checkers, i, '-', line, extraMove);
					checkExtraMove(checkers, i, '+', line, extraMove);
				}
			}
			else {
				capture(checkers, window, i, line, column, '-', '+', countRemoved, &endTurn); // верхний правый угол звезды
				if (*countRemoved != 0) {
					checkExtraMove(checkers, i, column, '-', extraMove);
					checkExtraMove(checkers, i, column, '+', extraMove);
					checkExtraMove(checkers, i, '-', line, extraMove);
					checkExtraMove(checkers, i, '+', line, extraMove);
					checkExtraMove(checkers, i, line, column, '-', '-', extraMove);
					checkExtraMove(checkers, i, line, column, '-', '+', extraMove);
					checkExtraMove(checkers, i, line, column, '+', '-', extraMove);
					checkExtraMove(checkers, i, line, column, '+', '+', extraMove);
				}
			}
		}
		else if (line == (int)checkerLine) {
			if (column == (int)checkerColumn - 1) { 
				capture(checkers, window, i, column, '-', countRemoved, &endTurn); // слева звезды
			}
			else { 
				capture(checkers, window, i, column, '+', countRemoved, &endTurn); // справа звезды
			}
			if (*countRemoved != 0) {
				checkExtraMove(checkers, i, column, '-', extraMove);
				checkExtraMove(checkers, i, column, '+', extraMove);
				checkExtraMove(checkers, i, '-', line, extraMove);
				checkExtraMove(checkers, i, '+', line, extraMove);
			}
		}
		else {
			if (column == (int)checkerColumn - 1) { 
				capture(checkers, window, i, line, column, '+', '-', countRemoved, &endTurn); // нижний левый угол звезды
				if (*countRemoved != 0) {
					checkExtraMove(checkers, i, column, '-', extraMove);
					checkExtraMove(checkers, i, column, '+', extraMove);
					checkExtraMove(checkers, i, '-', line, extraMove);
					checkExtraMove(checkers, i, '+', line, extraMove);
					checkExtraMove(checkers, i, line, column, '-', '-', extraMove);
					checkExtraMove(checkers, i, line, column, '-', '+', extraMove);
					checkExtraMove(checkers, i, line, column, '+', '-', extraMove);
					checkExtraMove(checkers, i, line, column, '+', '+', extraMove);
				}
			}
			else if (column == (int)checkerColumn) {
				capture(checkers, window, i, '+', line, countRemoved, &endTurn); //снизу звезды
				if (*countRemoved != 0) {
					checkExtraMove(checkers, i, column, '-', extraMove);
					checkExtraMove(checkers, i, column, '+', extraMove);
					checkExtraMove(checkers, i, '-', line, extraMove);
					checkExtraMove(checkers, i, '+', line, extraMove);
				}
			}
			else {
				capture(checkers, window, i, line, column, '+', '+', countRemoved, &endTurn); // нижний правый угол звезды
				if (*countRemoved != 0) {
					checkExtraMove(checkers, i, column, '-', extraMove);
					checkExtraMove(checkers, i, column, '+', extraMove);
					checkExtraMove(checkers, i, '-', line, extraMove);
					checkExtraMove(checkers, i, '+', line, extraMove);
					checkExtraMove(checkers, i, line, column, '-', '-', extraMove);
					checkExtraMove(checkers, i, line, column, '-', '+', extraMove);
					checkExtraMove(checkers, i, line, column, '+', '-', extraMove);
					checkExtraMove(checkers, i, line, column, '+', '+', extraMove);
				}
			}
		}
	}
	if (!*extraMove) {
		if (checkers[i]->getColor() == 1) {
			checkers[i]->getShape()->setOutlineColor(Color(0, 0, 0));
		}
		else {
			checkers[i]->getShape()->setOutlineColor(Color(255, 255, 255));
		}
		*checkers[i]->getSelected() = 0;
		*whoseTurn = !*whoseTurn;
	}
	checkers[i]->updatePosition();
	window->draw(*checkers[i]->getShape());
}

int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(sf::VideoMode(1135, 630), "Fanorona", Style::Default, settings);
	Sprite field;
	Texture fieldTexture;
	fieldTexture.loadFromFile("fanorona.png", IntRect(0, 0, 1135, 630));
	field.setTexture(fieldTexture);
	checker *checkers[44];
	setChechers(checkers);
	bool whoseTurn = 1, extraMove = 0;
	Font endFont;
	endFont.loadFromFile("arial.ttf");
	Text end;
	end.setFont(endFont);
	end.setCharacterSize(150);
	end.setFillColor(Color::Red);
	end.setOutlineColor(Color::Red);
	end.setPosition(250, 150);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					Vector2i mouseCoordinates = Mouse::getPosition(window);
					int  i;
					for (i = 0; i < 44; i++) {
						if (*checkers[i]->getInGame() == 0) {
							continue;
						}
						if (*checkers[i]->getSelected() == 1) {
							if (extraMove) {
								int j;
								for (j = 0; j < 44; j++) {
									if (*checkers[j]->getInGame() == 0) {
										continue;
									}
									Vector2<float> tempCoordinates(*checkers[j]->getX(), *checkers[j]->getY());
									if (mouseCoordinates.x < tempCoordinates.x + 72 && mouseCoordinates.x > tempCoordinates.x && mouseCoordinates.y < tempCoordinates.y + 72 && mouseCoordinates.y > tempCoordinates.y) {
										break;
									}
								}
								if (j != 44) {
									break;
								}
								else {
									for (int line = 0; line < 5; line++) {
										for (int column = 0; column < 9; column++) {
											float x = 27, y = 27;
											float checkerColumn = (*checkers[i]->getX() - x) / (float)126.2;
											float checkerLine = (*checkers[i]->getY() - y) / (float)126.2;
											int countRemoved = 0;
											extraMove = 0;
											if (mouseCoordinates.x < x + 126.2 * column + 72 && mouseCoordinates.x > x + 126.2 * column && mouseCoordinates.y < y + 126.2 * line + 72 && mouseCoordinates.y > y + 126.2 * line) {
												if ((int)(checkerLine * 9 + checkerColumn) % 2 == 0) {
													if (line >= (int)checkerLine - 1 && line <= (int)checkerLine + 1 && column >= (int)checkerColumn - 1 && column <= (int)checkerColumn + 1) {
														makeMove(checkers, &window, i, line, column, checkerLine, checkerColumn, &whoseTurn, &extraMove, &countRemoved, '*');
													}
												}
												else if ((line == (int)checkerLine && column >= (int)checkerColumn - 1 && column <= (int)checkerColumn + 1) || (column == (int)checkerColumn && line >= (int)checkerLine - 1 && line <= (int)checkerLine + 1)) {
													makeMove(checkers, &window, i, line, column, checkerLine, checkerColumn, &whoseTurn, &extraMove, &countRemoved, '+');
												}
											}
											if (extraMove == 1) {
												break;
											}
										}
										if (extraMove == 1) {
											break;
										}
									}
									break;
								}
							}
							else {
								int j;
								for (j = 0; j < 44; j++) {
									if (*checkers[j]->getInGame() == 0) {
										continue;
									}
									Vector2<float> tempCoordinates(*checkers[j]->getX(), *checkers[j]->getY());
									if (mouseCoordinates.x < tempCoordinates.x + 72 && mouseCoordinates.x > tempCoordinates.x && mouseCoordinates.y < tempCoordinates.y + 72 && mouseCoordinates.y > tempCoordinates.y) {
										if (checkers[j]->getColor() == whoseTurn) {
											checkers[j]->getShape()->setOutlineColor(Color::Green);
											window.draw(*checkers[j]->getShape());
											*checkers[j]->getSelected() = 1;
											if (checkers[i]->getColor() == 1) {
												checkers[i]->getShape()->setOutlineColor(Color(0, 0, 0));
											}
											else {
												checkers[i]->getShape()->setOutlineColor(Color(255, 255, 255));
											}
											window.draw(*checkers[i]->getShape());
											*checkers[i]->getSelected() = 0;
											break;
										}
										else {
											break;
										}
									}
								}
								if (j != 44) {
									break;
								}
								else {
									for (int line = 0; line < 5; line++) {
										for (int column = 0; column < 9; column++) {
											float x = 27, y = 27;
											float checkerColumn = (*checkers[i]->getX() - x) / (float)126.2;
											float checkerLine = (*checkers[i]->getY() - y) / (float)126.2;
											int countRemoved = 0;
											if (mouseCoordinates.x < x + 126.2 * column + 72 && mouseCoordinates.x > x + 126.2 * column && mouseCoordinates.y < y + 126.2 * line + 72 && mouseCoordinates.y > y + 126.2 * line) {
												if ((int)(checkerLine * 9 + checkerColumn) % 2 == 0) {
													if (line >= (int)checkerLine - 1 && line <= (int)checkerLine + 1 && column >= (int)checkerColumn - 1 && column <= (int)checkerColumn + 1) {
														makeMove(checkers, &window, i, line, column, checkerLine, checkerColumn, &whoseTurn, &extraMove, &countRemoved, '*');
													}
												}
												else if ((line == (int)checkerLine && column >= (int)checkerColumn - 1 && column <= (int)checkerColumn + 1) || (column == (int)checkerColumn && line >= (int)checkerLine - 1 && line <= (int)checkerLine + 1)) {
													makeMove(checkers, &window, i, line, column, checkerLine, checkerColumn, &whoseTurn, &extraMove, &countRemoved, '+');
												}
											}
											if (*checkers[i]->getSelected() == 0) {
												break;
											}
										}
										if (*checkers[i]->getSelected() == 0) {
											break;
										}
									}
									break;
								}
							}
						}
					}
					if (i == 44) {
						for (int i = 0; i < 44; i++) {
							if (*checkers[i]->getInGame() == 0) {
								continue;
							}
							Vector2<float> tempCoordinates(*checkers[i]->getX(), *checkers[i]->getY());
							if (mouseCoordinates.x < tempCoordinates.x + 72 && mouseCoordinates.x > tempCoordinates.x && mouseCoordinates.y < tempCoordinates.y + 72 && mouseCoordinates.y > tempCoordinates.y && checkers[i]->getColor() == whoseTurn) {
								checkers[i]->getShape()->setOutlineColor(Color::Green);
								window.draw(*checkers[i]->getShape());
								*checkers[i]->getSelected() = 1;
								break;
							}
						}
					}
				}
			}
		}
		int countWhite = 0, countBlack = 0;
		for (int i = 0; i < 44; i++) {
			if (*checkers[i]->getInGame() == 1) {
				if (checkers[i]->getColor() == 0) {
					countBlack++;
				}
				else {
					countWhite++;
				}
			}
		}
		window.clear();
		window.draw(field);
		drawCheckers(checkers, &window);
		if (countBlack == 0) {
			end.setString("White win!");
			window.draw(end);
		}
		if (countWhite == 0) {
			end.setString("Black win!");
			window.draw(end);
		}
		window.display();
	}
	return 0;
}