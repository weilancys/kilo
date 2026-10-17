#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <ctype.h>



int main() {
    // turn off canonical mode and echoing
    struct termios original_termios;
    tcgetattr(STDIN_FILENO, &original_termios);
    struct termios raw_termios = original_termios;

    raw_termios.c_iflag &= ~(IXON | ICRNL);
    raw_termios.c_lflag &= ~(ICANON | ECHO | ISIG | IEXTEN);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_termios);
    
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
        if (iscntrl(c)) {
            printf("%d\n", c);
        } else {
            printf("%d ('%c')\n", c, c);
        }
    }

    
    // turn on canonical mode and echoing
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
    return 0;
}