#include <unistd.h>

int main() {
    char c;
    while (read(STDIN_FILENO, &c, 1))
    {
        sleep(1);
        write(STDOUT_FILENO, &c, 1);
    }

    write(STDOUT_FILENO, "over.\n", 6);
    return 0;
}