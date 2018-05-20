#include<cstring>
#include<iostream>
#include<string>
#include<vector>
const int N = 10;
int GameBoard[N][N];
struct Point {
	int col;
	int row;
	Point(int r, int c) :row(r), col(c) {}
	bool operator==(const Point& elem) {
		return col == elem.col && row == elem.row;
	}
};

class GamePlayer {
public:
	virtual Point getPosition() const = 0;
	virtual std::vector<Point>allowedMoves() = 0;
	virtual bool wins(Point) = 0;
};

class Knight :public GamePlayer {
	Point currPos;
	bool isCorrect(int r,int c) {
		if (r < 0 || r >= N) return false;
		if (c < 0 || c >= N) return false;
		if (GameBoard[r][c] == 0) return true;
	}
public:
	Point getPosition() const override {
		return currPos;
	}
	std::vector<Point> allowedMoves() override {
		std::vector<Point> result;
		if (isCorrect(currPos.row+1, currPos.col)) {
			Point temp(currPos.row + 1, currPos.col);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row - 1, currPos.col)) {
			Point temp(currPos.row -1 , currPos.col);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row + 1, currPos.col+1)) {
			Point temp(currPos.row + 1, currPos.col+1);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row + 1, currPos.col -1)) {
			Point temp(currPos.row + 1, currPos.col-1);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row-1, currPos.col+1)) {
			Point temp(currPos.row - 1, currPos.col+1);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row - 1, currPos.col - 1)) {
			Point temp(currPos.row + 1, currPos.col);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row , currPos.col + 1)) {
			Point temp(currPos.row + 1, currPos.col);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row , currPos.col-1 )) {
			Point temp(currPos.row + 1, currPos.col);
			result.push_back(temp);
		}
	}
	bool wins(Point p) {
		std::vector<Point> temp = allowedMoves();
		for (Point elem : temp) {
			if(elem == p) return true;
		}
		return false;
	}
};
class SeaMonster :public GamePlayer {
//“Œ¬¿ ≈ ÃÕŒ√Œ √–≈ÿÕŒ!!!!
	Point currPos;
	bool isCorrect(int r, int c) {
		if (r < 0 || r >= N) return false;
		if (c < 0 || c >= N) return false;
		if (GameBoard[r][c] == 0) return true;
	}
public:
	Point getPosition() const override {
		return currPos;
	}
	std::vector<Point> allowedMoves() override {
		std::vector<Point> result;
		if (isCorrect(currPos.row + 1, currPos.col)) {
			Point temp(currPos.row + 1, currPos.col);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row - 1, currPos.col)) {
			Point temp(currPos.row - 1, currPos.col);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row + 1, currPos.col + 1)) {
			Point temp(currPos.row + 1, currPos.col + 1);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row + 1, currPos.col - 1)) {
			Point temp(currPos.row + 1, currPos.col - 1);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row - 1, currPos.col + 1)) {
			Point temp(currPos.row - 1, currPos.col + 1);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row - 1, currPos.col - 1)) {
			Point temp(currPos.row + 1, currPos.col);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row, currPos.col + 1)) {
			Point temp(currPos.row + 1, currPos.col);
			result.push_back(temp);
		}
		if (isCorrect(currPos.row, currPos.col - 1)) {
			Point temp(currPos.row + 1, currPos.col);
			result.push_back(temp);
		}
	}
	bool wins(Point p) {
		std::vector<Point> temp = allowedMoves();
		for (Point elem : temp) {
			if (elem == p) return true;
		}
		return false;
	}
};
bool isStable(const Point& move) {
	//makes the move and checks the board
}
std::vector<Point>allMoves(std::vector<GamePlayer*> players) {
	std::vector<Point> result;
	for (GamePlayer* player : players) {
		for (Point move : player->allowedMoves()) {
			if (isStable(move)) {
				result.push_back(move);
			}
		}
	}
}
int main() {
	std::string s;
	std::cin >> s;
	std::cout << s;
	std::string  b;
}