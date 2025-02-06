#include <bits/stdc++.h>
using namespace std;

int flag = 0;

class Game
{
    char board[3][3];

    public:
    Game()
    {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                board[i][j] = ' ';
    }

    void printBoard()
    {
        for (int i = 0; i < 3; i++) 
        {    
            cout << "\t\t";     
            for (int j = 0; j < 3; j++) 
            {   
                cout << "  " << board[i][j] << "  ";
                if(j < 2) cout << "|";         
            }
            cout << "\n";
            if (i < 2) 
            cout << "\t\t-----+-----+-----\n";
        }
        cout << "\n";
    }

    void playMove(int &i)
    {
        int r, c;
        char ch = ((i%2) == 0) ? 'X' : 'O';

        cout << "Player " << (i%2) + 1 << "'s Turn : ";
        cin >> r >> c;
        cout << "\n";
        
        if(board[r][c] != ' ')
        {
            cout << "Invalid Move! Try Again!\n";
            i--;
        }

        else
        {
            board[r][c] = ch;
            if(i >= 4)
            checkWin(ch);
        }
    }

    void checkWin(char &ch)
    {
        //Horizontal and Vertical Check
        for(int i = 0; i < 3; i++)
        {
            int h_count = 0;
            int v_count = 0;

            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == ch)
                    h_count++;

                if(board[j][i] == ch)
                    v_count++;

                if(h_count == 3 || v_count == 3)
                {
                    cout << "\n" << ((ch == 'X') ? "\t\tPLAYER 1" : "\t\tPLAYER 2") << " WINS!! \n\n";
                    this -> ~Game();
                }
            }
        }

        //Diagonal Check
        int rd_count = 0;
        int ld_count = 0;
        for(int i = 0; i < 3; i++)
        {
            if(board[i][i] == ch)
                rd_count++;

            if(board[i][2-i] == ch)
                ld_count++;
        }

        if(ld_count == 3 || rd_count == 3)
        {
            cout << "\n" << ((ch == 'X') ? "\t\tPLAYER 1" : "\t\tPLAYER 2") << " WINS!! \n\n";
            this -> ~Game();
        }
    }

    ~Game()
    {
        flag = 1;
    }
};

int main()
{
    cout << "\n\n";
    cout << "\t\t   TIC-TAC-TOE \n";
    cout << "Play moves by entering row and column number (0-indexed), separated by space\nPlayer 1 : X \t\t\t Player 2 : O \n\n";

    while(true)
    {
        int play = 0;
        cout << "Press 1 to Play : ";
        cin >> play;
        cout << "\n";

        if(play != 1)
        break;

        Game g;
        g.printBoard();

        int i = 0;
        for(; i < 9; i++)
        {
            if(flag)
            break;
            g.playMove(i);
            g.printBoard();
        }

        if(i == 9)
        cout << "\t\t\tDRAW\n\n" << endl;
    }
    return 0;
}
