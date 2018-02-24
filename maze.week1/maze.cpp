#include<iostream>
#define MAX_SIZE 4

void printMaze(int Maze[][MAX_SIZE]) {
	for (int row = 0; row < MAX_SIZE; row++) {
		for (int col = 0; col < MAX_SIZE; col++) {
			std::cout << Maze[row][col] << " ";
		}
		std::cout << std::endl;
	}
}
bool correctIndxs(int x, int y) {
	if (x < 0 || y < 0 || x >= MAX_SIZE || y >= MAX_SIZE) return false;
	return true;
}
bool hasPath(int Maze[][MAX_SIZE], int startRow, int startCol, int endRow, int endCol) {
	printMaze(Maze);
	std::cout << std::endl;
	if (Maze[startRow][startCol] == 0 || Maze[endRow][endCol] == 0) return false; //startPos or endPos are inaccessible
	if (startRow == endRow && startCol == endCol) return true;//we've reached the end
	bool leftTurn=false, rightTurn = false, upTurn=false, downTurn = false;
	Maze[startRow][startCol] = 0;//making current position as inaccessible
	if (correctIndxs(startRow + 1, startCol) && Maze[startRow + 1][startCol] == 1) downTurn = hasPath(Maze,startRow + 1, startCol, endRow, endCol);
	if (correctIndxs(startRow -1, startCol) && Maze[startRow - 1][startCol] == 1) upTurn = hasPath(Maze,startRow -1, startCol, endRow, endCol);
	if (correctIndxs(startRow, startCol+1) && Maze[startRow][startCol+1] == 1) rightTurn = hasPath(Maze,startRow, startCol+1, endRow, endCol);
	if (correctIndxs(startRow, startCol-1) && Maze[startRow][startCol-1] == 1) leftTurn = hasPath(Maze,startRow, startCol-1, endRow, endCol);
	Maze[startRow][startCol] = 1;//returning initial value
	return leftTurn || rightTurn || upTurn || downTurn;
}
int main() {
	//printMaze();
	int Maze[MAX_SIZE][MAX_SIZE] =
	{
		{ 1,1,0,0 },
		{ 0,1,0,0 },
		{ 1,1,1,0 },
		{ 1,0,1,0 }
	};
	std::cout << std::endl;
	std::cout << std::boolalpha << hasPath(Maze,0, 0, 3, 2);
	std::cout << std::endl;
	return 0;
}