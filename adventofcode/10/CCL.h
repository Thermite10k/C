#define COLOR_PRINT(BG, FG) \
for(\
    int temp = 1;\
    temp-- > 0 &&\
    printf("\033[%d;%dm", BG, FG);\
    printf("\033[0m")\
    )\


#define TEXT_EFFECT(EFFECT)\
  for(\
    int temp = 1;\
    temp-- > 0 && printf("\033[%dm", EFFECT);\
    printf("\033[0m")\
    )\


enum COLORS{
    BG_BLACK = 40, BG_RED = 41, BG_GREEN = 42, BG_YELLOW = 43, BG_BLUE = 44, BG_PURPLE = 45, BG_LIGHT_BLUE = 46, BG_WHITE = 47,
    FG_BLACK = 30, FG_RED = 31, FG_GREEN = 32, FG_YELLOW = 33, FG_BLUE = 34, FG_PURPLE = 35, FG_LIGHT_BLUE = 36, FG_WHITE = 37
};
enum EFFECTS{
    BLINK = 5,
};

#define MOVE_CURSOR_ABSOLUTE(ROW, COL) printf("\033[%d;%dH", ROW, COL)
#define MOVE_CURSOR_ZERO_ABSOLUTE(ROW, COL) printf("\033[%d;%dH", ROW+2, COL+1)
#define RESET_CURSOR() printf("\033[0;0h")
#define MOVE_CURSOR_RELATIVE(U, R, D, L) printf("\033[%dA\033[%dC\033[%dB\033[%dD", U, R, D, L)
#define MOVE_CURSOR_DOWN(D) printf("\033[%dB", D)
#define MOVE_CURSOR_UP(U) printf("\033[%dA", U)
#define MOVE_CURSOR_FORWARD(F) printf("\033[%dC", F)
#define MOVE_CURSOR_BACK(B) printf("\033[%dD", B)