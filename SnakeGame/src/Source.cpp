#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int WIDTH = 20;
const int HEIGHT = 20;
int x, y, fruitX, fruitY, score;
int tailX[100];
int tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
void checkBounds() {

	if (x < 0) {
		gameOver = true;

	}
	if( x > WIDTH-1){
		gameOver = true;
	}
	if (y < 0) {
		gameOver = true;
	}
	if (y > HEIGHT-1) {
		gameOver = true;
}


}
void drawFruit(){
	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;
}
void setup() {
	gameOver = false;
	dir = STOP;	
	x = WIDTH / 2;
	y = HEIGHT / 2;
	nTail = 1;
	drawFruit();
	tailX[0] = x;
	tailY[0] = y;
}
void checkFruit() {
	if (x == fruitX) {
		if (y == fruitY) {

			score += 10;
			nTail++;
			drawFruit();
		}

	}


}

void draw(){
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prevX2, prevY2;
	tailX[0] = x;
	tailY[0] = y;
	for(int i = 1; i < nTail; i++){
		
		prevX2 = tailX[i];
		prevY2 = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prevX2;
		prevY = prevY2;	
	
	}
	//to clean the terminal screen	
	system("cls");  
	for (int i = 0; i < WIDTH +2; i++) {
		cout << "#";
		 
	}
	cout << endl;
	
	for (int i = 0; i < HEIGHT; i++) {

		for (int j = 0; j < WIDTH; j++) {

			if (j == 0) {

				cout <<  "#";
			}
			
			if (x == j && y == i) {

				cout << "O";

			}
			else if (fruitX == j && fruitY == i) {

				cout << "F";

			}
			
			else {
				bool print = false;
				for (int k = 0; k < nTail;k++) {

					
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print) {
					cout << " ";

				}
			;
			}
			if (j == WIDTH - 1) {

				cout << "#";

			}

		}
		cout << endl;
	}
	
	
	for (int i = 0; i < WIDTH + 2; i++) {
		cout << "#";
		
}
	cout << endl;
	cout << endl;
	cout << endl << "                              Score: " << score;
}

void input() {
	if (_kbhit()){
	
		switch (_getch()) {

		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'd':
			dir = RIGHT;
		break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;

	}


	}

}
void logic(){

	switch(dir) {
		
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	checkFruit();
	checkBounds();
	
}

int main() {
	setup();
	
	while (!gameOver) {
		draw();
		input();
		logic();
	}
}
