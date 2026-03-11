#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <proto/dos.h>
#include <dos/dos.h>

// usleep() is provided by libnix but not declared under -std=c99
extern int usleep(unsigned long);

#include "py/mpconfig.h"
#include "py/mphal.h"

// Read a single character from stdin
int mp_hal_stdin_rx_chr(void) {
    int c = fgetc(stdin);
    if (c == EOF) {
        return 0;
    }
    // AmigaOS sends CR as line ending; convert to LF
    if (c == '\r') {
        c = '\n';
    }
    return c;
}

// Write a string to stdout
mp_uint_t mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {
    mp_uint_t written = fwrite(str, 1, len, stdout);
    fflush(stdout);
    return written;
}

// Read a full line using fgets (cooked/line-buffered input from AmigaOS console).
// Returns a malloc'd string with the trailing newline stripped, or NULL on EOF.
char *amiga_prompt(const char *p) {
    static char buf[256];
    fputs(p, stdout);
    fflush(stdout);
    char *s = fgets(buf, sizeof(buf), stdin);
    if (!s) {
        return NULL;
    }
    int l = strlen(buf);
    // Strip trailing CR or LF
    while (l > 0 && (buf[l - 1] == '\n' || buf[l - 1] == '\r')) {
        buf[--l] = '\0';
    }
    char *line = malloc(l + 1);
    if (line) {
        memcpy(line, buf, l + 1);
    }
    return line;
}

// Delay functions using usleep() from libnix
void mp_hal_delay_ms(mp_uint_t ms) {
    usleep(ms * 1000UL);
}

void mp_hal_delay_us(mp_uint_t us) {
    usleep(us);
}
