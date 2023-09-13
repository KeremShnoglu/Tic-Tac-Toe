#include <iostream>
#include <iomanip>

using namespace std;

 
char board[3][3] = { {'1','2','3' },{ '4','5','6' },{ '7','8','9' } };//Location in Game Board
int value;

//This function to show the board of Tic Tac Toe Game 
void Display_Board() {  
	cout<< "-----Game Board-----" << endl<<endl;
	cout<< " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout<<"___|___|___" <<endl;
	cout<< " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout<<"___|___|___" << endl;
	cout<< " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout<<"___|___|___" << endl;
}


//Player will make a move in this function  
char turn; //Player's turn ( X or O )
 
int location;
int row,column;
void Player_Turn() {
static int value = 0; //to understand whose turn.The turn player 1 if value % 2 = 0 .The turn player 2 if value % 2 = 1
a:
	if (value % 2 == 0) {
		cout << "Player 1 [X] choose location which you want (Enter between 1 and 9 ):";
		turn = 'X';
		cin >> location;
	}
	if (value % 2 == 1) {
		cout << "Player 2 [O] choose location which you want:";
		turn = 'O';
		cin >> location;
	}
	try
	{   
		if (location < 1 && location>9) {
			throw 101;
		}
	}
	catch (int e)
	{
		cout << "Error : "<<e<<" Location which you entered not between 1 and 9 ."<<endl;
		goto a;
	}
	

	switch (location)
	{
	default:
	case 1:
		row = 0;
		column = 0;
		if (board[0][0]=='1')
		{
            board[0][0] = turn;
		}
		else {
			cout << "Location is full,Please enter again"<<endl;
				goto a;
		}
		value++;
		break;
	case 2:
		row = 0;
		column = 1;
		if (board[0][1] == '2')
		{
			board[0][1] = turn;
		}
		else {
			cout << "Location is full,Please enter again"<<endl;
			goto a;
		}
		value++;
		break;
	case 3:
		row = 0;
		column = 2;
		if (board[0][2] == '3')
		{
			board[0][2] = turn;
		}
		else {
			cout << "Location is full,Please enter again"<<endl;
			goto a;
		}
		value++;
		break;
	case 4:
		row = 1;
		column = 0;
		if (board[1][0] = '4')
		{
			board[1][0] = turn;
		}
		else {
			cout << "Location is full,Please enter again"<<endl;
			goto a;
		}
		value++;
		break;
	case 5:
		row = 1;
		column = 1;
		if (board[1][1] == '5')
		{
			board[1][1] = turn;
		}
		else {
			cout << "Location is full,Please enter again"<<endl;
			goto a;
		}
		value++;
		break;
	case 6:
		row = 1;
		column = 2;
		if (board[1][2] == '6')
		{
			board[1][2] = turn;
		}
		else {
			cout << "Location is full,Please enter again"<<endl;
			goto a;
		}
		value++;
		break;
	case 7:
		row = 2;
		column = 0;
		if (board[2][0] == '7')
		{
			board[2][0] = turn;
		}
		else {
			cout << "Location is full,Please enter again"<<endl;
			goto a;
		}
		value++;
		break;
	case 8:
		row = 2;
		column = 1;
		if (board[2][1] == '8')
		{
			board[2][1] = turn;
		}
		else {
			cout << "Location is full,Please enter again"<<endl;
			goto a;
		}
		value++;
		break;
	case 9:
		row = 2;
		column = 2;
		if (board[2][2] == '9')
		{
			board[2][2] = turn;
		}
		else {
			cout << "Location is full,Please enter again"<<endl;
			goto a;
		}
		value++;
		break;
	}

	cout << endl<<endl<<endl;
}
int gameover() {
	row = 0, column = 0;
	int number=0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X' || board[i][j] == 'O')
			{
				number++;
			}
		}
	}
	if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
		(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
		(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')) {
		cout << "-----Player 1 Win-----";
		return -1;
	}
	if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
		(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
		(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')) {
		cout << "-----Player 2 Win-----";
		return -1;
	}
	if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
		(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')) {
		cout << "-----Player 1 Win-----";
		return -1;
	}
	if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
		(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')) {
		cout << "-----Player 2 Win-----";
		return -1;
	}
	if (number == 9) {
		cout << "-----GameOver-----";
        Display_Board();
		cout << "-----Draw-----";
	}
}

int main() {
	
	while (gameover()!=-1)
	{
		Display_Board();
		Player_Turn();
		gameover();
	}

	return 0;
}
