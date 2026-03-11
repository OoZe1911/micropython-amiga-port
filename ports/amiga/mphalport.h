#ifndef MICROPY_INCLUDED_AMIGA_MPHALPORT_H
#define MICROPY_INCLUDED_AMIGA_MPHALPORT_H

#include <stdint.h>

// Time stubs — AmigaOS has no POSIX clock; all return 0 for now.
static inline mp_uint_t mp_hal_ticks_ms(void) { return 0; }
static inline mp_uint_t mp_hal_ticks_us(void) { return 0; }
static inline mp_uint_t mp_hal_ticks_cpu(void) { return 0; }
static inline void mp_hal_delay_ms(mp_uint_t ms) { (void)ms; }
static inline void mp_hal_delay_us(mp_uint_t us) { (void)us; }

static inline void mp_hal_set_interrupt_char(char c) { (void)c; }

// Line-buffered readline for the input() builtin.
// Defined as a macro so modbuiltins.c picks it up instead of shared readline.
char *amiga_prompt(const char *p);

#if MICROPY_PY_BUILTINS_INPUT
#include <stdlib.h>
#include "py/misc.h"
#define mp_hal_readline mp_hal_readline
static inline int mp_hal_readline(vstr_t *vstr, const char *p) {
    char *line = amiga_prompt(p);
    if (line == NULL) {
        return 4; // CHAR_CTRL_D
    }
    vstr_add_str(vstr, line);
    free(line);
    return 0;
}
#endif

#endif // MICROPY_INCLUDED_AMIGA_MPHALPORT_H
