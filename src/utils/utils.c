#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif
#include <stdio.h>
#include <stdarg.h>

void get_window_size(size_t *rows, size_t *cols)
{
    #if defined(_WIN32) || defined(_WIN64)
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        *rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        *cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    #else
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        *rows = ws.ws_row;
        *cols = ws.ws_col;
    #endif
}

int red_printf(const char *format, ...)
{
    va_list arg;
    int done;
    va_start(arg, format);

    #if defined(_WIN32) || defined(_WIN64)
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        WORD saved_attributes;
        /* Save current attributes */
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        saved_attributes = consoleInfo.wAttributes;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        done = vfprintf(stderr, format, arg);
        /* Restore original attributes */
        SetConsoleTextAttribute(hConsole, saved_attributes);
    #else
        char *fmt = malloc(sizeof(char) * (strlen(format) + 10)); // \x1b[31m\x1b[0m = (9 + '\0')
        strcpy(fmt, "\x1b[31m");
        strcat(fmt, format);
        strcat(fmt, "\x1b[0m");
        done = vfprintf(stderr, fmt, arg);
    #endif

    va_end(arg);

    return done;
}
