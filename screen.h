#define ESC 0x1B
#define BAR "\u2590"
#define UNICODE

enum FGCOLORS{BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
// function prototypes
void clearScreen(void);
void gotoxy(int, int);
void bar(int, double);
void setColor(int);
