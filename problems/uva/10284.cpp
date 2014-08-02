#include <cstdio>
#include <cstring>
#include <cctype>

#define SIZE 8

#define OCCUPIED 1
#define ATTACKED 2

char board[SIZE][SIZE];

inline bool inboard(int y, int x) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

inline void check_board(int dir[][2], int moves, int sign, int r, int c) {
    for (int j = 0; j < moves; j++) {
        if (inboard(r + sign * dir[j][0],
                    c + sign * dir[j][1])
                && board[r + sign * dir[j][0]]
                        [c + sign * dir[j][1]] != OCCUPIED) {
            board[r + sign * dir[j][0]]
                 [c + sign * dir[j][1]] = ATTACKED;
        }
    }

}

inline void check_board_across(int dir[][2], int moves, int r, int c) {
    for (int j = 0; j < moves; j++) {
        int k = 1;
        while (inboard(r + k * dir[j][0], 
                       c + k * dir[j][1])
                && board[r + k * dir[j][0]]
                        [c + k * dir[j][1]] != OCCUPIED) {
            board[r + k * dir[j][0]]
                 [c + k * dir[j][1]] = ATTACKED;
            ++k;
        }
    }
}

inline void check_board_bishop(int r, int c) {
    int bishop[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    check_board_across(bishop, 4, r, c);
}

inline void check_board_rook(int r, int c) {
    int rook[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    check_board_across(rook, 4, r, c);
}

inline void check_board_queen(int r, int c) {
    check_board_bishop(r, c);
    check_board_rook(r, c);
}

inline void check_board_pawn(int r, int c, int sign) {
    int pawn[2][2] = {{1, -1}, {1, 1}};

    check_board(pawn, 2, sign, r, c);
}

inline void check_board_knight(int r, int c) {
    int knight[8][2] = {{-2, -1}, {-2, 1},
                        {-1, 2}, {1, 2},
                        {2, 1}, {2, -1},
                        {1, -2}, {-1, -2}};
    check_board(knight, 8, 1, r, c);
}

inline void check_board_king(int r, int c) {
    int king[8][2] = {{-1, -1}, {-1, 0},
                      {-1, 1}, {0, 1},
                      {1, 1}, {1, 0},
                      {1, -1}, {0, -1}};
    check_board(king, 8, 1, r, c);
}

void set_board(char* line) {
    int r = 0, c = 0;
    memset(board, 0, sizeof(board));

    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == '/') {
            ++r;
            c = 0;
        } else {
            if (line[i] >= '1' && line[i] <= '0' + SIZE) {
                c += line[i] - '0';   
            } else {
                board[r][c] = OCCUPIED; 
                ++c;
            }
        }
    }
}

void mark_board(char *line) {
    int r = 0, c = 0;
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == '/') {
            ++r;
            c = 0;
        } else {
            if (line[i] >= '1' && line[i] <= '0' + SIZE) {
                c += line[i] - '0';   
            } else {
                char lower = tolower(line[i]);
                switch (lower) {
                    case 'p':
                        check_board_pawn(r, c, line[i] == 'P' ? -1 : 1);
                        break;
                    case 'n':
                        check_board_knight(r, c);
                        break;
                    case 'b':
                        check_board_bishop(r, c);
                        break;
                    case 'r':
                        check_board_rook(r, c);
                        break;
                    case 'q':
                        check_board_queen(r, c);
                        break;
                    case 'k':
                        check_board_king(r, c);
                        break;
                }
                ++c;
            }
        }
    }
}

int main() {
    char line[100];

    while (fgets(line, 100, stdin) != NULL) {
        line[strlen(line) -1] = '\0';

        set_board(line);

        mark_board(line);

        int unoccupied = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++){
                unoccupied += !board[i][j];
            }
        }

        printf("%d\n", unoccupied);
    }
    return 0;
}
