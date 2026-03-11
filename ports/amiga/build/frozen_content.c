//
// Content for MICROPY_MODULE_FROZEN_STR
//
#include <stdint.h>
#define MP_FROZEN_STR_NAMES \

const uint32_t mp_frozen_str_sizes[] = { 0 };
const char mp_frozen_str_content[] = {
"\0"
};

//
// Content for MICROPY_MODULE_FROZEN_MPY
//
#include "py/mpconfig.h"
#include "py/objint.h"
#include "py/objstr.h"
#include "py/emitglue.h"
#include "py/nativeglue.h"

#if MICROPY_LONGINT_IMPL != 2
#error "incompatible MICROPY_LONGINT_IMPL"
#endif

#if MPZ_DIG_SIZE != 16
#error "incompatible MPZ_DIG_SIZE"
#endif

#if MICROPY_PY_BUILTINS_FLOAT
typedef struct _mp_obj_float_t {
    mp_obj_base_t base;
    mp_float_t value;
} mp_obj_float_t;
#endif

#if MICROPY_PY_BUILTINS_COMPLEX
typedef struct _mp_obj_complex_t {
    mp_obj_base_t base;
    mp_float_t real;
    mp_float_t imag;
} mp_obj_complex_t;
#endif

enum {
    MP_QSTR__bang_HHB = MP_QSTRnumber_of,
    MP_QSTR__percent_010x,
    MP_QSTR__percent_04d_hyphen__percent_02d_hyphen__percent_02d,
    MP_QSTR__plus_,
    MP_QSTR__plus__hyphen_,
    MP_QSTR__hyphen_,
    MP_QSTR__hyphen_d,
    MP_QSTR__hyphen_e,
    MP_QSTR__hyphen_t,
    MP_QSTR__hyphen_u,
    MP_QSTR__dot_,
    MP_QSTR__dot__brace_open__colon_03d_brace_close_,
    MP_QSTR__colon_,
    MP_QSTR__colon__brace_open__colon_02d_brace_close_,
    MP_QSTR_DeprecationWarning,
    MP_QSTR_EPOCH,
    MP_QSTR_Error,
    MP_QSTR_Incorrect_space_padding,
    MP_QSTR_MAXBINSIZE,
    MP_QSTR_MAXLINESIZE,
    MP_QSTR_MAXYEAR,
    MP_QSTR_MINYEAR,
    MP_QSTR_Non_hyphen_base16_space_digit_space_found,
    MP_QSTR_Non_hyphen_base32_space_digit_space_found,
    MP_QSTR_Non_hyphen_base64_space_digit_space_found,
    MP_QSTR_NotImplemented,
    MP_QSTR_T,
    MP_QSTR_UTC,
    MP_QSTR___abs__,
    MP_QSTR___all__,
    MP_QSTR___divmod__,
    MP_QSTR___floordiv__,
    MP_QSTR___mod__,
    MP_QSTR___mul__,
    MP_QSTR___neg__,
    MP_QSTR___pos__,
    MP_QSTR___rmul__,
    MP_QSTR___truediv__,
    MP_QSTR__b32alphabet,
    MP_QSTR__b32rev,
    MP_QSTR__b32tab,
    MP_QSTR__bytes_from_decode_data,
    MP_QSTR__cmp,
    MP_QSTR__d,
    MP_QSTR__d2iso,
    MP_QSTR__date,
    MP_QSTR__dbm,
    MP_QSTR__dim,
    MP_QSTR__epoch_time,
    MP_QSTR__fd,
    MP_QSTR__fmt,
    MP_QSTR__gmtime,
    MP_QSTR__hash,
    MP_QSTR__iso2d,
    MP_QSTR__iso2t,
    MP_QSTR__leap,
    MP_QSTR__localtime,
    MP_QSTR__maketrans,
    MP_QSTR__mktime,
    MP_QSTR__name,
    MP_QSTR__o2ymd,
    MP_QSTR__offset,
    MP_QSTR__ord,
    MP_QSTR__sub,
    MP_QSTR__t,
    MP_QSTR__t2iso,
    MP_QSTR__td,
    MP_QSTR__time,
    MP_QSTR__tmod,
    MP_QSTR__translate,
    MP_QSTR__tuple,
    MP_QSTR__tz,
    MP_QSTR__us,
    MP_QSTR_altchars,
    MP_QSTR_ascii,
    MP_QSTR_astimezone,
    MP_QSTR_auto,
    MP_QSTR_b16decode,
    MP_QSTR_b16encode,
    MP_QSTR_b32decode,
    MP_QSTR_b32encode,
    MP_QSTR_b64decode,
    MP_QSTR_b64encode,
    MP_QSTR_base64_dot_py,
    MP_QSTR_buffer,
    MP_QSTR_bytes_types,
    MP_QSTR_casefold,
    MP_QSTR_cls,
    MP_QSTR_combine,
    MP_QSTR_d,
    MP_QSTR_date,
    MP_QSTR_datetime,
    MP_QSTR_datetime_dot_py,
    MP_QSTR_day,
    MP_QSTR_days,
    MP_QSTR_decodebytes,
    MP_QSTR_decodestring,
    MP_QSTR_deut,
    MP_QSTR_dst,
    MP_QSTR_dt,
    MP_QSTR_encodebytes,
    MP_QSTR_encodestring,
    MP_QSTR_error,
    MP_QSTR_expected_space_bytes_comma__space_not_space__percent_s,
    MP_QSTR_f,
    MP_QSTR_fold,
    MP_QSTR_fromisoformat,
    MP_QSTR_fromordinal,
    MP_QSTR_fromtimestamp,
    MP_QSTR_fromutc,
    MP_QSTR_getopt,
    MP_QSTR_h,
    MP_QSTR_hour,
    MP_QSTR_hours,
    MP_QSTR_input_bytes,
    MP_QSTR_isoformat,
    MP_QSTR_isoweekday,
    MP_QSTR_local,
    MP_QSTR_m,
    MP_QSTR_map01,
    MP_QSTR_microsecond,
    MP_QSTR_microseconds,
    MP_QSTR_milliseconds,
    MP_QSTR_minute,
    MP_QSTR_minutes,
    MP_QSTR_month,
    MP_QSTR_n,
    MP_QSTR_now,
    MP_QSTR_o,
    MP_QSTR_offset,
    MP_QSTR_other,
    MP_QSTR_output,
    MP_QSTR_rb,
    MP_QSTR_resolution,
    MP_QSTR_s,
    MP_QSTR_second,
    MP_QSTR_seconds,
    MP_QSTR_spec,
    MP_QSTR_standard_b64decode,
    MP_QSTR_standard_b64encode,
    MP_QSTR_stderr,
    MP_QSTR_stdin,
    MP_QSTR_stdout,
    MP_QSTR_t,
    MP_QSTR_td,
    MP_QSTR_test,
    MP_QSTR_timedelta,
    MP_QSTR_timespec,
    MP_QSTR_timestamp,
    MP_QSTR_timetuple,
    MP_QSTR_timetz,
    MP_QSTR_timezone,
    MP_QSTR_today,
    MP_QSTR_toordinal,
    MP_QSTR_total_seconds,
    MP_QSTR_trans_table,
    MP_QSTR_ts,
    MP_QSTR_tz,
    MP_QSTR_tzinfo,
    MP_QSTR_tzname,
    MP_QSTR_u,
    MP_QSTR_urlsafe_b64decode,
    MP_QSTR_urlsafe_b64encode,
    MP_QSTR_us,
    MP_QSTR_utc,
    MP_QSTR_utcoffset,
    MP_QSTR_validate,
    MP_QSTR_warn,
    MP_QSTR_warnings,
    MP_QSTR_weekday,
    MP_QSTR_weeks,
    MP_QSTR_y,
    MP_QSTR_year,
    MP_QSTR__brace_open__colon_02d_brace_close_,
    MP_QSTR__brace_open__colon_03d_brace_close_,
    MP_QSTR__brace_open__brace_close__brace_open__brace_close_,
    MP_QSTR__brace_open__brace_close__brace_open__brace_close__space_day_brace_open__brace_close__comma__space_,
};

const qstr_hash_t mp_qstr_frozen_const_hashes[] = {
    8262,
    64969,
    2336,
    46478,
    26467,
    46472,
    26348,
    26349,
    26364,
    26365,
    46475,
    62384,
    46495,
    44453,
    17559,
    39764,
    4573,
    25229,
    37681,
    43386,
    19934,
    8128,
    48788,
    7762,
    61105,
    50750,
    46577,
    59495,
    54933,
    50116,
    4472,
    24390,
    14179,
    16945,
    54633,
    61481,
    355,
    61320,
    28062,
    61464,
    2190,
    27734,
    8932,
    30046,
    441,
    30446,
    20625,
    20538,
    48417,
    8376,
    13989,
    34981,
    57928,
    50489,
    50473,
    1154,
    62626,
    16770,
    51817,
    56669,
    54071,
    31159,
    4099,
    57854,
    30030,
    425,
    8042,
    37135,
    33096,
    5852,
    28962,
    8052,
    8028,
    36087,
    22356,
    42012,
    47274,
    61772,
    24998,
    2442,
    39648,
    9513,
    38339,
    54485,
    41189,
    48136,
    40976,
    19545,
    64484,
    46529,
    56337,
    1252,
    10819,
    7673,
    56682,
    51248,
    64540,
    60645,
    8102,
    28053,
    56410,
    16950,
    4541,
    22029,
    46531,
    11204,
    30053,
    54048,
    36125,
    59889,
    760,
    46541,
    13925,
    886,
    62709,
    27219,
    55024,
    38984,
    46536,
    6200,
    57967,
    12348,
    27083,
    49771,
    4024,
    61813,
    46539,
    22451,
    46538,
    15432,
    39073,
    27034,
    28885,
    18315,
    46550,
    19221,
    44486,
    17984,
    33325,
    62151,
    22691,
    1057,
    33544,
    46545,
    28565,
    44851,
    32360,
    5173,
    48235,
    18792,
    61566,
    43758,
    3330,
    3309,
    15707,
    21886,
    28546,
    28555,
    20453,
    52908,
    46544,
    32140,
    3814,
    28579,
    25671,
    62346,
    22467,
    21167,
    21756,
    34661,
    2122,
    46556,
    40778,
    7487,
    14910,
    30021,
    34579,
};

const qstr_len_t mp_qstr_frozen_const_lengths[] = {
    4,
    5,
    14,
    1,
    2,
    1,
    2,
    2,
    2,
    2,
    1,
    7,
    1,
    7,
    18,
    5,
    5,
    17,
    10,
    11,
    7,
    7,
    22,
    22,
    22,
    14,
    1,
    3,
    7,
    7,
    10,
    12,
    7,
    7,
    7,
    7,
    8,
    11,
    12,
    7,
    7,
    23,
    4,
    2,
    6,
    5,
    4,
    4,
    11,
    3,
    4,
    7,
    5,
    6,
    6,
    5,
    10,
    10,
    7,
    5,
    6,
    7,
    4,
    4,
    2,
    6,
    3,
    5,
    5,
    10,
    6,
    3,
    3,
    8,
    5,
    10,
    4,
    9,
    9,
    9,
    9,
    9,
    9,
    9,
    6,
    11,
    8,
    3,
    7,
    1,
    4,
    8,
    11,
    3,
    4,
    11,
    12,
    4,
    3,
    2,
    11,
    12,
    5,
    22,
    1,
    4,
    13,
    11,
    13,
    7,
    6,
    1,
    4,
    5,
    11,
    9,
    10,
    5,
    1,
    5,
    11,
    12,
    12,
    6,
    7,
    5,
    1,
    3,
    1,
    6,
    5,
    6,
    2,
    10,
    1,
    6,
    7,
    4,
    18,
    18,
    6,
    5,
    6,
    1,
    2,
    4,
    9,
    8,
    9,
    9,
    6,
    8,
    5,
    9,
    13,
    11,
    2,
    2,
    6,
    6,
    1,
    17,
    17,
    2,
    3,
    9,
    8,
    4,
    8,
    7,
    5,
    1,
    4,
    6,
    6,
    4,
    12,
};

extern const qstr_pool_t mp_qstr_const_pool;
const qstr_pool_t mp_qstr_frozen_const_pool = {
    &mp_qstr_const_pool, // previous pool
    MP_QSTRnumber_of, // previous pool size
    true, // is_sorted
    10, // allocated entries
    177, // used entries
    (qstr_hash_t *)mp_qstr_frozen_const_hashes,
    (qstr_len_t *)mp_qstr_frozen_const_lengths,
    {
        "!HHB",
        "%010x",
        "%04d-%02d-%02d",
        "+",
        "+-",
        "-",
        "-d",
        "-e",
        "-t",
        "-u",
        ".",
        ".{:03d}",
        ":",
        ":{:02d}",
        "DeprecationWarning",
        "EPOCH",
        "Error",
        "Incorrect padding",
        "MAXBINSIZE",
        "MAXLINESIZE",
        "MAXYEAR",
        "MINYEAR",
        "Non-base16 digit found",
        "Non-base32 digit found",
        "Non-base64 digit found",
        "NotImplemented",
        "T",
        "UTC",
        "__abs__",
        "__all__",
        "__divmod__",
        "__floordiv__",
        "__mod__",
        "__mul__",
        "__neg__",
        "__pos__",
        "__rmul__",
        "__truediv__",
        "_b32alphabet",
        "_b32rev",
        "_b32tab",
        "_bytes_from_decode_data",
        "_cmp",
        "_d",
        "_d2iso",
        "_date",
        "_dbm",
        "_dim",
        "_epoch_time",
        "_fd",
        "_fmt",
        "_gmtime",
        "_hash",
        "_iso2d",
        "_iso2t",
        "_leap",
        "_localtime",
        "_maketrans",
        "_mktime",
        "_name",
        "_o2ymd",
        "_offset",
        "_ord",
        "_sub",
        "_t",
        "_t2iso",
        "_td",
        "_time",
        "_tmod",
        "_translate",
        "_tuple",
        "_tz",
        "_us",
        "altchars",
        "ascii",
        "astimezone",
        "auto",
        "b16decode",
        "b16encode",
        "b32decode",
        "b32encode",
        "b64decode",
        "b64encode",
        "base64.py",
        "buffer",
        "bytes_types",
        "casefold",
        "cls",
        "combine",
        "d",
        "date",
        "datetime",
        "datetime.py",
        "day",
        "days",
        "decodebytes",
        "decodestring",
        "deut",
        "dst",
        "dt",
        "encodebytes",
        "encodestring",
        "error",
        "expected bytes, not %s",
        "f",
        "fold",
        "fromisoformat",
        "fromordinal",
        "fromtimestamp",
        "fromutc",
        "getopt",
        "h",
        "hour",
        "hours",
        "input_bytes",
        "isoformat",
        "isoweekday",
        "local",
        "m",
        "map01",
        "microsecond",
        "microseconds",
        "milliseconds",
        "minute",
        "minutes",
        "month",
        "n",
        "now",
        "o",
        "offset",
        "other",
        "output",
        "rb",
        "resolution",
        "s",
        "second",
        "seconds",
        "spec",
        "standard_b64decode",
        "standard_b64encode",
        "stderr",
        "stdin",
        "stdout",
        "t",
        "td",
        "test",
        "timedelta",
        "timespec",
        "timestamp",
        "timetuple",
        "timetz",
        "timezone",
        "today",
        "toordinal",
        "total_seconds",
        "trans_table",
        "ts",
        "tz",
        "tzinfo",
        "tzname",
        "u",
        "urlsafe_b64decode",
        "urlsafe_b64encode",
        "us",
        "utc",
        "utcoffset",
        "validate",
        "warn",
        "warnings",
        "weekday",
        "weeks",
        "y",
        "year",
        "{:02d}",
        "{:03d}",
        "{}{}",
        "{}{} day{}, ",
    },
};

////////////////////////////////////////////////////////////////////////////////
// frozen module base64
// - original source file: build/frozen_mpy/base64.mpy
// - frozen file name: base64.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file base64.py, scope base64__lt_module_gt_
static const byte fun_data_base64__lt_module_gt_[453] = {
    0x68,0xc6,0x02, // prelude
    0x01, // names: <module>
    0x40,0x60,0x60,0x26,0x26,0x66,0x64,0x20,0x22,0x8e,0x09,0x22,0x62,0x40,0x22,0x66,0x20,0x68,0x84,0x0d,0x84,0x08,0x84,0x0e,0x88,0x16,0x89,0x18,0x84,0x08,0x84,0x0f,0x84,0x0b,0x84,0x11,0x22,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x66,0x30,0x70,0x84,0x2e,0x89,0x4d,0x84,0x0a,0x88,0x17,0x25,0x68,0x84,0x0f,0x84,0x0a,0x84,0x0c,0x84,0x08,0x84,0x07,0x84,0x09,0x84,0x23,0x84,0x0a,0x27, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x02, // IMPORT_NAME 're'
    0x16,0x02, // STORE_NAME 're'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x03, // IMPORT_NAME 'struct'
    0x16,0x03, // STORE_NAME 'struct'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x04, // IMPORT_NAME 'binascii'
    0x16,0x04, // STORE_NAME 'binascii'
    0x10,0x05, // LOAD_CONST_STRING 'encode'
    0x10,0x06, // LOAD_CONST_STRING 'decode'
    0x23,0x00, // LOAD_CONST_OBJ 0
    0x23,0x01, // LOAD_CONST_OBJ 1
    0x10,0x07, // LOAD_CONST_STRING 'b64encode'
    0x10,0x08, // LOAD_CONST_STRING 'b64decode'
    0x10,0x09, // LOAD_CONST_STRING 'b32encode'
    0x10,0x0a, // LOAD_CONST_STRING 'b32decode'
    0x10,0x0b, // LOAD_CONST_STRING 'b16encode'
    0x10,0x0c, // LOAD_CONST_STRING 'b16decode'
    0x23,0x02, // LOAD_CONST_OBJ 2
    0x23,0x03, // LOAD_CONST_OBJ 3
    0x23,0x04, // LOAD_CONST_OBJ 4
    0x23,0x05, // LOAD_CONST_OBJ 5
    0x2b,0x0e, // BUILD_LIST 14
    0x16,0x46, // STORE_NAME '__all__'
    0x11,0x47, // LOAD_NAME 'bytes'
    0x11,0x48, // LOAD_NAME 'bytearray'
    0x2a,0x02, // BUILD_TUPLE 2
    0x16,0x49, // STORE_NAME 'bytes_types'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x0f, // STORE_NAME '_bytes_from_decode_data'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x13, // STORE_NAME '_maketrans'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x14, // STORE_NAME '_translate'
    0x51, // LOAD_CONST_NONE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x03, // MAKE_FUNCTION_DEFARGS 3
    0x16,0x07, // STORE_NAME 'b64encode'
    0x51, // LOAD_CONST_NONE
    0x50, // LOAD_CONST_FALSE
    0x2a,0x02, // BUILD_TUPLE 2
    0x53, // LOAD_NULL
    0x33,0x04, // MAKE_FUNCTION_DEFARGS 4
    0x16,0x08, // STORE_NAME 'b64decode'
    0x32,0x05, // MAKE_FUNCTION 5
    0x16,0x1c, // STORE_NAME 'standard_b64encode'
    0x32,0x06, // MAKE_FUNCTION 6
    0x16,0x1d, // STORE_NAME 'standard_b64decode'
    0x32,0x07, // MAKE_FUNCTION 7
    0x16,0x1e, // STORE_NAME 'urlsafe_b64encode'
    0x32,0x08, // MAKE_FUNCTION 8
    0x16,0x20, // STORE_NAME 'urlsafe_b64decode'
    0x2c,0x20, // BUILD_MAP 32
    0x23,0x06, // LOAD_CONST_OBJ 6
    0x80, // LOAD_CONST_SMALL_INT 0
    0x62, // STORE_MAP
    0x23,0x07, // LOAD_CONST_OBJ 7
    0x89, // LOAD_CONST_SMALL_INT 9
    0x62, // STORE_MAP
    0x23,0x08, // LOAD_CONST_OBJ 8
    0x92, // LOAD_CONST_SMALL_INT 18
    0x62, // STORE_MAP
    0x23,0x09, // LOAD_CONST_OBJ 9
    0x9b, // LOAD_CONST_SMALL_INT 27
    0x62, // STORE_MAP
    0x23,0x0a, // LOAD_CONST_OBJ 10
    0x81, // LOAD_CONST_SMALL_INT 1
    0x62, // STORE_MAP
    0x23,0x0b, // LOAD_CONST_OBJ 11
    0x8a, // LOAD_CONST_SMALL_INT 10
    0x62, // STORE_MAP
    0x23,0x0c, // LOAD_CONST_OBJ 12
    0x93, // LOAD_CONST_SMALL_INT 19
    0x62, // STORE_MAP
    0x23,0x0d, // LOAD_CONST_OBJ 13
    0x9c, // LOAD_CONST_SMALL_INT 28
    0x62, // STORE_MAP
    0x23,0x0e, // LOAD_CONST_OBJ 14
    0x82, // LOAD_CONST_SMALL_INT 2
    0x62, // STORE_MAP
    0x23,0x0f, // LOAD_CONST_OBJ 15
    0x8b, // LOAD_CONST_SMALL_INT 11
    0x62, // STORE_MAP
    0x23,0x10, // LOAD_CONST_OBJ 16
    0x94, // LOAD_CONST_SMALL_INT 20
    0x62, // STORE_MAP
    0x23,0x11, // LOAD_CONST_OBJ 17
    0x9d, // LOAD_CONST_SMALL_INT 29
    0x62, // STORE_MAP
    0x23,0x12, // LOAD_CONST_OBJ 18
    0x83, // LOAD_CONST_SMALL_INT 3
    0x62, // STORE_MAP
    0x23,0x13, // LOAD_CONST_OBJ 19
    0x8c, // LOAD_CONST_SMALL_INT 12
    0x62, // STORE_MAP
    0x23,0x14, // LOAD_CONST_OBJ 20
    0x95, // LOAD_CONST_SMALL_INT 21
    0x62, // STORE_MAP
    0x23,0x15, // LOAD_CONST_OBJ 21
    0x9e, // LOAD_CONST_SMALL_INT 30
    0x62, // STORE_MAP
    0x23,0x16, // LOAD_CONST_OBJ 22
    0x84, // LOAD_CONST_SMALL_INT 4
    0x62, // STORE_MAP
    0x23,0x17, // LOAD_CONST_OBJ 23
    0x8d, // LOAD_CONST_SMALL_INT 13
    0x62, // STORE_MAP
    0x23,0x18, // LOAD_CONST_OBJ 24
    0x96, // LOAD_CONST_SMALL_INT 22
    0x62, // STORE_MAP
    0x23,0x19, // LOAD_CONST_OBJ 25
    0x9f, // LOAD_CONST_SMALL_INT 31
    0x62, // STORE_MAP
    0x23,0x1a, // LOAD_CONST_OBJ 26
    0x85, // LOAD_CONST_SMALL_INT 5
    0x62, // STORE_MAP
    0x23,0x1b, // LOAD_CONST_OBJ 27
    0x8e, // LOAD_CONST_SMALL_INT 14
    0x62, // STORE_MAP
    0x23,0x1c, // LOAD_CONST_OBJ 28
    0x97, // LOAD_CONST_SMALL_INT 23
    0x62, // STORE_MAP
    0x23,0x1d, // LOAD_CONST_OBJ 29
    0x86, // LOAD_CONST_SMALL_INT 6
    0x62, // STORE_MAP
    0x23,0x1e, // LOAD_CONST_OBJ 30
    0x8f, // LOAD_CONST_SMALL_INT 15
    0x62, // STORE_MAP
    0x23,0x1f, // LOAD_CONST_OBJ 31
    0x98, // LOAD_CONST_SMALL_INT 24
    0x62, // STORE_MAP
    0x23,0x20, // LOAD_CONST_OBJ 32
    0x87, // LOAD_CONST_SMALL_INT 7
    0x62, // STORE_MAP
    0x23,0x21, // LOAD_CONST_OBJ 33
    0x90, // LOAD_CONST_SMALL_INT 16
    0x62, // STORE_MAP
    0x23,0x22, // LOAD_CONST_OBJ 34
    0x99, // LOAD_CONST_SMALL_INT 25
    0x62, // STORE_MAP
    0x23,0x23, // LOAD_CONST_OBJ 35
    0x88, // LOAD_CONST_SMALL_INT 8
    0x62, // STORE_MAP
    0x23,0x24, // LOAD_CONST_OBJ 36
    0x91, // LOAD_CONST_SMALL_INT 17
    0x62, // STORE_MAP
    0x23,0x25, // LOAD_CONST_OBJ 37
    0x9a, // LOAD_CONST_SMALL_INT 26
    0x62, // STORE_MAP
    0x16,0x4a, // STORE_NAME '_b32alphabet'
    0x32,0x09, // MAKE_FUNCTION 9
    0x11,0x4b, // LOAD_NAME 'sorted'
    0x11,0x4a, // LOAD_NAME '_b32alphabet'
    0x14,0x0d, // LOAD_METHOD 'items'
    0x36,0x00, // CALL_METHOD 0
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x4c, // STORE_NAME '_b32tab'
    0x11,0x4d, // LOAD_NAME 'dict'
    0x32,0x0a, // MAKE_FUNCTION 10
    0x11,0x4a, // LOAD_NAME '_b32alphabet'
    0x14,0x0d, // LOAD_METHOD 'items'
    0x36,0x00, // CALL_METHOD 0
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x4e, // STORE_NAME '_b32rev'
    0x32,0x0b, // MAKE_FUNCTION 11
    0x16,0x09, // STORE_NAME 'b32encode'
    0x50, // LOAD_CONST_FALSE
    0x51, // LOAD_CONST_NONE
    0x2a,0x02, // BUILD_TUPLE 2
    0x53, // LOAD_NULL
    0x33,0x0c, // MAKE_FUNCTION_DEFARGS 12
    0x16,0x0a, // STORE_NAME 'b32decode'
    0x32,0x0d, // MAKE_FUNCTION 13
    0x16,0x0b, // STORE_NAME 'b16encode'
    0x50, // LOAD_CONST_FALSE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x0e, // MAKE_FUNCTION_DEFARGS 14
    0x16,0x0c, // STORE_NAME 'b16decode'
    0x22,0x80,0x4c, // LOAD_CONST_SMALL_INT 76
    0x16,0x4f, // STORE_NAME 'MAXLINESIZE'
    0x11,0x4f, // LOAD_NAME 'MAXLINESIZE'
    0x84, // LOAD_CONST_SMALL_INT 4
    0xf6, // BINARY_OP 31 __floordiv__
    0x83, // LOAD_CONST_SMALL_INT 3
    0xf4, // BINARY_OP 29 __mul__
    0x16,0x50, // STORE_NAME 'MAXBINSIZE'
    0x32,0x0f, // MAKE_FUNCTION 15
    0x16,0x05, // STORE_NAME 'encode'
    0x32,0x10, // MAKE_FUNCTION 16
    0x16,0x06, // STORE_NAME 'decode'
    0x32,0x11, // MAKE_FUNCTION 17
    0x16,0x2e, // STORE_NAME 'encodebytes'
    0x32,0x12, // MAKE_FUNCTION 18
    0x16,0x2f, // STORE_NAME 'encodestring'
    0x32,0x13, // MAKE_FUNCTION 19
    0x16,0x32, // STORE_NAME 'decodebytes'
    0x32,0x14, // MAKE_FUNCTION 20
    0x16,0x33, // STORE_NAME 'decodestring'
    0x32,0x15, // MAKE_FUNCTION 21
    0x16,0x34, // STORE_NAME 'main'
    0x32,0x16, // MAKE_FUNCTION 22
    0x16,0x45, // STORE_NAME 'test'
    0x11,0x12, // LOAD_NAME '__name__'
    0x10,0x0e, // LOAD_CONST_STRING '__main__'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x45, // POP_JUMP_IF_FALSE 5
    0x11,0x34, // LOAD_NAME 'main'
    0x34,0x00, // CALL_FUNCTION 0
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64__bytes_from_decode_data
static const byte fun_data_base64__bytes_from_decode_data[68] = {
    0x2d,0x14, // prelude
    0x0f,0x51, // names: _bytes_from_decode_data, s
    0x80,0x2a,0x29,0x22,0x69,0x2a,0x29,0x42, // code info
    0x12,0x52, // LOAD_GLOBAL 'isinstance'
    0xb0, // LOAD_FAST 0
    0x12,0x53, // LOAD_GLOBAL 'str'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x55, // POP_JUMP_IF_FALSE 21
    0x48,0x08, // SETUP_EXCEPT 8
    0xb0, // LOAD_FAST 0
    0x14,0x05, // LOAD_METHOD 'encode'
    0x10,0x10, // LOAD_CONST_STRING 'ascii'
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
    0x59, // POP_TOP
    0x12,0x54, // LOAD_GLOBAL 'ValueError'
    0x23,0x26, // LOAD_CONST_OBJ 38
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x5d, // END_FINALLY
    0x42,0x58, // JUMP 24
    0x12,0x52, // LOAD_GLOBAL 'isinstance'
    0xb0, // LOAD_FAST 0
    0x12,0x49, // LOAD_GLOBAL 'bytes_types'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb0, // LOAD_FAST 0
    0x63, // RETURN_VALUE
    0x12,0x55, // LOAD_GLOBAL 'TypeError'
    0x23,0x27, // LOAD_CONST_OBJ 39
    0xb0, // LOAD_FAST 0
    0x13,0x11, // LOAD_ATTR '__class__'
    0x13,0x12, // LOAD_ATTR '__name__'
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64__bytes_from_decode_data = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64__bytes_from_decode_data,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 68,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 15,
        .line_info = fun_data_base64__bytes_from_decode_data + 4,
        .line_info_top = fun_data_base64__bytes_from_decode_data + 12,
        .opcodes = fun_data_base64__bytes_from_decode_data + 12,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64__bytes_from_decode_data fun_data_base64__bytes_from_decode_data[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64__maketrans
static const byte fun_data_base64__maketrans[44] = {
    0x32,0x12, // prelude
    0x13,0x56,0x57, // names: _maketrans, f, t
    0x80,0x37,0x20,0x2d,0x27,0x2b, // code info
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0x12,0x54, // LOAD_GLOBAL 'ValueError'
    0x23,0x28, // LOAD_CONST_OBJ 40
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x4d, // LOAD_GLOBAL 'dict'
    0x12,0x59, // LOAD_GLOBAL 'zip'
    0xb0, // LOAD_FAST 0
    0xb1, // LOAD_FAST 1
    0x34,0x02, // CALL_FUNCTION 2
    0x34,0x01, // CALL_FUNCTION 1
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64__maketrans = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64__maketrans,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 44,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 19,
        .line_info = fun_data_base64__maketrans + 5,
        .line_info_top = fun_data_base64__maketrans + 11,
        .opcodes = fun_data_base64__maketrans + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64__maketrans fun_data_base64__maketrans[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64__translate
static const byte fun_data_base64__translate[45] = {
    0x62,0x14, // prelude
    0x14,0x5a,0x5b, // names: _translate, input_bytes, trans_table
    0x80,0x3f,0x20,0x45,0x25,0x28,0x49, // code info
    0x12,0x48, // LOAD_GLOBAL 'bytearray'
    0x34,0x00, // CALL_FUNCTION 0
    0xc2, // STORE_FAST 2
    0xb0, // LOAD_FAST 0
    0x5f, // GET_ITER_STACK
    0x4b,0x12, // FOR_ITER 18
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0x14,0x15, // LOAD_METHOD 'get'
    0xb3, // LOAD_FAST 3
    0xb3, // LOAD_FAST 3
    0x36,0x02, // CALL_METHOD 2
    0xc4, // STORE_FAST 4
    0xb2, // LOAD_FAST 2
    0x14,0x16, // LOAD_METHOD 'append'
    0xb4, // LOAD_FAST 4
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x2c, // JUMP -20
    0x12,0x47, // LOAD_GLOBAL 'bytes'
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64__translate = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64__translate,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 45,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 20,
        .line_info = fun_data_base64__translate + 5,
        .line_info_top = fun_data_base64__translate + 12,
        .opcodes = fun_data_base64__translate + 12,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64__translate fun_data_base64__translate[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_b64encode
static const byte fun_data_base64_b64encode[115] = {
    0xba,0x01,0x1e, // prelude
    0x07,0x51,0x5c, // names: b64encode, s, altchars
    0x80,0x4d,0x80,0x09,0x29,0x4d,0x2d,0x26,0x29,0x2d,0x33,0x2d, // code info
    0x12,0x52, // LOAD_GLOBAL 'isinstance'
    0xb0, // LOAD_FAST 0
    0x12,0x49, // LOAD_GLOBAL 'bytes_types'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x4d, // POP_JUMP_IF_TRUE 13
    0x12,0x55, // LOAD_GLOBAL 'TypeError'
    0x23,0x29, // LOAD_CONST_OBJ 41
    0xb0, // LOAD_FAST 0
    0x13,0x11, // LOAD_ATTR '__class__'
    0x13,0x12, // LOAD_ATTR '__name__'
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x17, // LOAD_METHOD 'b2a_base64'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0x51, // LOAD_CONST_NONE
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xc2, // STORE_FAST 2
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x76, // POP_JUMP_IF_FALSE 54
    0x12,0x52, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x49, // LOAD_GLOBAL 'bytes_types'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x4d, // POP_JUMP_IF_TRUE 13
    0x12,0x55, // LOAD_GLOBAL 'TypeError'
    0x23,0x29, // LOAD_CONST_OBJ 41
    0xb1, // LOAD_FAST 1
    0x13,0x11, // LOAD_ATTR '__class__'
    0x13,0x12, // LOAD_ATTR '__name__'
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0xd9, // BINARY_OP 2 __eq__
    0x43,0x4a, // POP_JUMP_IF_TRUE 10
    0x12,0x18, // LOAD_GLOBAL 'AssertionError'
    0x12,0x5d, // LOAD_GLOBAL 'repr'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x14, // LOAD_GLOBAL '_translate'
    0xb2, // LOAD_FAST 2
    0x12,0x13, // LOAD_GLOBAL '_maketrans'
    0x23,0x2a, // LOAD_CONST_OBJ 42
    0xb1, // LOAD_FAST 1
    0x34,0x02, // CALL_FUNCTION 2
    0x34,0x02, // CALL_FUNCTION 2
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_b64encode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_b64encode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 115,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 7,
        .line_info = fun_data_base64_b64encode + 6,
        .line_info_top = fun_data_base64_b64encode + 18,
        .opcodes = fun_data_base64_b64encode + 18,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_b64encode fun_data_base64_b64encode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_b64decode
static const byte fun_data_base64_b64decode[100] = {
    0xbb,0x80,0x01,0x1e, // prelude
    0x08,0x51,0x5c,0x5e, // names: b64decode, s, altchars, validate
    0x80,0x63,0x80,0x0d,0x26,0x26,0x26,0x33,0x2d,0x2e,0x29, // code info
    0x12,0x0f, // LOAD_GLOBAL '_bytes_from_decode_data'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0xc0, // STORE_FAST 0
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x66, // POP_JUMP_IF_FALSE 38
    0x12,0x0f, // LOAD_GLOBAL '_bytes_from_decode_data'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xc1, // STORE_FAST 1
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0xd9, // BINARY_OP 2 __eq__
    0x43,0x4a, // POP_JUMP_IF_TRUE 10
    0x12,0x18, // LOAD_GLOBAL 'AssertionError'
    0x12,0x5d, // LOAD_GLOBAL 'repr'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x14, // LOAD_GLOBAL '_translate'
    0xb0, // LOAD_FAST 0
    0x12,0x13, // LOAD_GLOBAL '_maketrans'
    0xb1, // LOAD_FAST 1
    0x23,0x2a, // LOAD_CONST_OBJ 42
    0x34,0x02, // CALL_FUNCTION 2
    0x34,0x02, // CALL_FUNCTION 2
    0xc0, // STORE_FAST 0
    0xb2, // LOAD_FAST 2
    0x44,0x54, // POP_JUMP_IF_FALSE 20
    0x12,0x02, // LOAD_GLOBAL 're'
    0x14,0x19, // LOAD_METHOD 'match'
    0x23,0x2b, // LOAD_CONST_OBJ 43
    0xb0, // LOAD_FAST 0
    0x36,0x02, // CALL_METHOD 2
    0x43,0x49, // POP_JUMP_IF_TRUE 9
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x1a, // LOAD_METHOD 'Error'
    0x23,0x2c, // LOAD_CONST_OBJ 44
    0x36,0x01, // CALL_METHOD 1
    0x65, // RAISE_OBJ
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x1b, // LOAD_METHOD 'a2b_base64'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_b64decode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_b64decode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 100,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name_idx = 8,
        .line_info = fun_data_base64_b64decode + 8,
        .line_info_top = fun_data_base64_b64decode + 19,
        .opcodes = fun_data_base64_b64decode + 19,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_b64decode fun_data_base64_b64decode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_standard_b64encode
static const byte fun_data_base64_standard_b64encode[14] = {
    0x11,0x0c, // prelude
    0x1c,0x51, // names: standard_b64encode, s
    0x80,0x7b,0x60,0x20, // code info
    0x12,0x07, // LOAD_GLOBAL 'b64encode'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_standard_b64encode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_standard_b64encode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 28,
        .line_info = fun_data_base64_standard_b64encode + 4,
        .line_info_top = fun_data_base64_standard_b64encode + 8,
        .opcodes = fun_data_base64_standard_b64encode + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_standard_b64encode fun_data_base64_standard_b64encode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_standard_b64decode
static const byte fun_data_base64_standard_b64decode[14] = {
    0x11,0x0c, // prelude
    0x1d,0x51, // names: standard_b64decode, s
    0x80,0x83,0x80,0x07, // code info
    0x12,0x08, // LOAD_GLOBAL 'b64decode'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_standard_b64decode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_standard_b64decode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 29,
        .line_info = fun_data_base64_standard_b64decode + 4,
        .line_info_top = fun_data_base64_standard_b64decode + 8,
        .opcodes = fun_data_base64_standard_b64decode + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_standard_b64decode fun_data_base64_standard_b64decode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_urlsafe_b64encode
static const byte fun_data_base64_urlsafe_b64encode[22] = {
    0x19,0x0c, // prelude
    0x1e,0x51, // names: urlsafe_b64encode, s
    0x80,0x92,0x80,0x07, // code info
    0x12,0x07, // LOAD_GLOBAL 'b64encode'
    0xb0, // LOAD_FAST 0
    0x23,0x2d, // LOAD_CONST_OBJ 45
    0x34,0x02, // CALL_FUNCTION 2
    0x14,0x1f, // LOAD_METHOD 'rstrip'
    0x23,0x2e, // LOAD_CONST_OBJ 46
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_urlsafe_b64encode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_urlsafe_b64encode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 22,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 30,
        .line_info = fun_data_base64_urlsafe_b64encode + 4,
        .line_info_top = fun_data_base64_urlsafe_b64encode + 8,
        .opcodes = fun_data_base64_urlsafe_b64encode + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_urlsafe_b64encode fun_data_base64_urlsafe_b64encode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_urlsafe_b64decode
static const byte fun_data_base64_urlsafe_b64decode[13] = {
    0x09,0x0c, // prelude
    0x20,0x51, // names: urlsafe_b64decode, s
    0x80,0x9d,0x80,0x0c, // code info
    0x12,0x5f, // LOAD_GLOBAL 'NotImplementedError'
    0x34,0x00, // CALL_FUNCTION 0
    0x65, // RAISE_OBJ
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_urlsafe_b64decode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_urlsafe_b64decode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 13,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 32,
        .line_info = fun_data_base64_urlsafe_b64decode + 4,
        .line_info_top = fun_data_base64_urlsafe_b64decode + 8,
        .opcodes = fun_data_base64_urlsafe_b64decode + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_urlsafe_b64decode fun_data_base64_urlsafe_b64decode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64__lt_listcomp_gt_
static const byte fun_data_base64__lt_listcomp_gt_[24] = {
    0x49,0x08, // prelude
    0x21,0x60, // names: <listcomp>, *
    0x80,0xd0, // code info
    0x2b,0x00, // BUILD_LIST 0
    0xb0, // LOAD_FAST 0
    0x5f, // GET_ITER_STACK
    0x4b,0x0b, // FOR_ITER 11
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc1, // STORE_FAST 1
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x2f,0x14, // STORE_COMP 20
    0x42,0x33, // JUMP -13
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64__lt_listcomp_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64__lt_listcomp_gt_,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 24,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 33,
        .line_info = fun_data_base64__lt_listcomp_gt_ + 4,
        .line_info_top = fun_data_base64__lt_listcomp_gt_ + 6,
        .opcodes = fun_data_base64__lt_listcomp_gt_ + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64__lt_listcomp_gt_ fun_data_base64__lt_listcomp_gt_[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64__lt_listcomp_gt_2
static const byte fun_data_base64__lt_listcomp_gt_2[27] = {
    0x49,0x08, // prelude
    0x21,0x60, // names: <listcomp>, *
    0x80,0xd1, // code info
    0x2b,0x00, // BUILD_LIST 0
    0xb0, // LOAD_FAST 0
    0x5f, // GET_ITER_STACK
    0x4b,0x0e, // FOR_ITER 14
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc1, // STORE_FAST 1
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xb1, // LOAD_FAST 1
    0x2a,0x02, // BUILD_TUPLE 2
    0x2f,0x14, // STORE_COMP 20
    0x42,0x30, // JUMP -16
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64__lt_listcomp_gt_2 = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64__lt_listcomp_gt_2,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 27,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 33,
        .line_info = fun_data_base64__lt_listcomp_gt_2 + 4,
        .line_info_top = fun_data_base64__lt_listcomp_gt_2 + 6,
        .opcodes = fun_data_base64__lt_listcomp_gt_2 + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64__lt_listcomp_gt_2 fun_data_base64__lt_listcomp_gt_2[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_b32encode
static const byte fun_data_base64_b32encode[295] = {
    0xa9,0x10,0x4a, // prelude
    0x09,0x51, // names: b32encode, s
    0x80,0xd5,0x60,0x20,0x29,0x2d,0x4e,0x23,0x2a,0x24,0x25,0x67,0x60,0x39,0x28,0x28,0x23,0x20,0x26,0x28,0x28,0x26,0x28,0x28,0x26,0x76,0x20,0x25,0x2c,0x25,0x2c,0x25,0x2c,0x25,0x2c, // code info
    0x12,0x52, // LOAD_GLOBAL 'isinstance'
    0xb0, // LOAD_FAST 0
    0x12,0x49, // LOAD_GLOBAL 'bytes_types'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x4d, // POP_JUMP_IF_TRUE 13
    0x12,0x55, // LOAD_GLOBAL 'TypeError'
    0x23,0x29, // LOAD_CONST_OBJ 41
    0xb0, // LOAD_FAST 0
    0x13,0x11, // LOAD_ATTR '__class__'
    0x13,0x12, // LOAD_ATTR '__name__'
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x61, // LOAD_GLOBAL 'divmod'
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x85, // LOAD_CONST_SMALL_INT 5
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc1, // STORE_FAST 1
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x44,0x4e, // POP_JUMP_IF_FALSE 14
    0xb0, // LOAD_FAST 0
    0x12,0x47, // LOAD_GLOBAL 'bytes'
    0x85, // LOAD_CONST_SMALL_INT 5
    0xb2, // LOAD_FAST 2
    0xf3, // BINARY_OP 28 __sub__
    0x34,0x01, // CALL_FUNCTION 1
    0xf2, // BINARY_OP 27 __add__
    0xc0, // STORE_FAST 0
    0xb1, // LOAD_FAST 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0xe5, // BINARY_OP 14 __iadd__
    0xc1, // STORE_FAST 1
    0x12,0x48, // LOAD_GLOBAL 'bytearray'
    0x34,0x00, // CALL_FUNCTION 0
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x42,0xee,0x80, // JUMP 110
    0x57, // DUP_TOP
    0xc4, // STORE_FAST 4
    0x12,0x03, // LOAD_GLOBAL 'struct'
    0x14,0x22, // LOAD_METHOD 'unpack'
    0x10,0x23, // LOAD_CONST_STRING '!HHB'
    0xb0, // LOAD_FAST 0
    0xb4, // LOAD_FAST 4
    0x85, // LOAD_CONST_SMALL_INT 5
    0xf4, // BINARY_OP 29 __mul__
    0xb4, // LOAD_FAST 4
    0x81, // LOAD_CONST_SMALL_INT 1
    0xf2, // BINARY_OP 27 __add__
    0x85, // LOAD_CONST_SMALL_INT 5
    0xf4, // BINARY_OP 29 __mul__
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x36,0x02, // CALL_METHOD 2
    0x30,0x03, // UNPACK_SEQUENCE 3
    0xc5, // STORE_FAST 5
    0xc6, // STORE_FAST 6
    0xc7, // STORE_FAST 7
    0xb6, // LOAD_FAST 6
    0xb5, // LOAD_FAST 5
    0x81, // LOAD_CONST_SMALL_INT 1
    0xef, // BINARY_OP 24 __and__
    0x90, // LOAD_CONST_SMALL_INT 16
    0xf0, // BINARY_OP 25 __lshift__
    0xe5, // BINARY_OP 14 __iadd__
    0xc6, // STORE_FAST 6
    0xb7, // LOAD_FAST 7
    0xb6, // LOAD_FAST 6
    0x83, // LOAD_CONST_SMALL_INT 3
    0xef, // BINARY_OP 24 __and__
    0x88, // LOAD_CONST_SMALL_INT 8
    0xf0, // BINARY_OP 25 __lshift__
    0xe5, // BINARY_OP 14 __iadd__
    0xc7, // STORE_FAST 7
    0xb3, // LOAD_FAST 3
    0x12,0x47, // LOAD_GLOBAL 'bytes'
    0x12,0x4c, // LOAD_GLOBAL '_b32tab'
    0xb5, // LOAD_FAST 5
    0x8b, // LOAD_CONST_SMALL_INT 11
    0xf1, // BINARY_OP 26 __rshift__
    0x55, // LOAD_SUBSCR
    0x12,0x4c, // LOAD_GLOBAL '_b32tab'
    0xb5, // LOAD_FAST 5
    0x86, // LOAD_CONST_SMALL_INT 6
    0xf1, // BINARY_OP 26 __rshift__
    0x9f, // LOAD_CONST_SMALL_INT 31
    0xef, // BINARY_OP 24 __and__
    0x55, // LOAD_SUBSCR
    0x12,0x4c, // LOAD_GLOBAL '_b32tab'
    0xb5, // LOAD_FAST 5
    0x81, // LOAD_CONST_SMALL_INT 1
    0xf1, // BINARY_OP 26 __rshift__
    0x9f, // LOAD_CONST_SMALL_INT 31
    0xef, // BINARY_OP 24 __and__
    0x55, // LOAD_SUBSCR
    0x12,0x4c, // LOAD_GLOBAL '_b32tab'
    0xb6, // LOAD_FAST 6
    0x8c, // LOAD_CONST_SMALL_INT 12
    0xf1, // BINARY_OP 26 __rshift__
    0x55, // LOAD_SUBSCR
    0x12,0x4c, // LOAD_GLOBAL '_b32tab'
    0xb6, // LOAD_FAST 6
    0x87, // LOAD_CONST_SMALL_INT 7
    0xf1, // BINARY_OP 26 __rshift__
    0x9f, // LOAD_CONST_SMALL_INT 31
    0xef, // BINARY_OP 24 __and__
    0x55, // LOAD_SUBSCR
    0x12,0x4c, // LOAD_GLOBAL '_b32tab'
    0xb6, // LOAD_FAST 6
    0x82, // LOAD_CONST_SMALL_INT 2
    0xf1, // BINARY_OP 26 __rshift__
    0x9f, // LOAD_CONST_SMALL_INT 31
    0xef, // BINARY_OP 24 __and__
    0x55, // LOAD_SUBSCR
    0x12,0x4c, // LOAD_GLOBAL '_b32tab'
    0xb7, // LOAD_FAST 7
    0x85, // LOAD_CONST_SMALL_INT 5
    0xf1, // BINARY_OP 26 __rshift__
    0x55, // LOAD_SUBSCR
    0x12,0x4c, // LOAD_GLOBAL '_b32tab'
    0xb7, // LOAD_FAST 7
    0x9f, // LOAD_CONST_SMALL_INT 31
    0xef, // BINARY_OP 24 __and__
    0x55, // LOAD_SUBSCR
    0x2b,0x08, // BUILD_LIST 8
    0x34,0x01, // CALL_FUNCTION 1
    0xe5, // BINARY_OP 14 __iadd__
    0xc3, // STORE_FAST 3
    0x81, // LOAD_CONST_SMALL_INT 1
    0xe5, // BINARY_OP 14 __iadd__
    0x58, // DUP_TOP_TWO
    0x5a, // ROT_TWO
    0xd7, // BINARY_OP 0 __lt__
    0x43,0x8c,0x7f, // POP_JUMP_IF_TRUE -116
    0x59, // POP_TOP
    0x59, // POP_TOP
    0xb2, // LOAD_FAST 2
    0x81, // LOAD_CONST_SMALL_INT 1
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0x7a, // LOAD_CONST_SMALL_INT -6
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x23,0x2f, // LOAD_CONST_OBJ 47
    0xf2, // BINARY_OP 27 __add__
    0xc3, // STORE_FAST 3
    0x42,0x73, // JUMP 51
    0xb2, // LOAD_FAST 2
    0x82, // LOAD_CONST_SMALL_INT 2
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0x7c, // LOAD_CONST_SMALL_INT -4
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x23,0x30, // LOAD_CONST_OBJ 48
    0xf2, // BINARY_OP 27 __add__
    0xc3, // STORE_FAST 3
    0x42,0x62, // JUMP 34
    0xb2, // LOAD_FAST 2
    0x83, // LOAD_CONST_SMALL_INT 3
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0x7d, // LOAD_CONST_SMALL_INT -3
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x23,0x31, // LOAD_CONST_OBJ 49
    0xf2, // BINARY_OP 27 __add__
    0xc3, // STORE_FAST 3
    0x42,0x51, // JUMP 17
    0xb2, // LOAD_FAST 2
    0x84, // LOAD_CONST_SMALL_INT 4
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x23,0x32, // LOAD_CONST_OBJ 50
    0xf2, // BINARY_OP 27 __add__
    0xc3, // STORE_FAST 3
    0x42,0x40, // JUMP 0
    0x12,0x47, // LOAD_GLOBAL 'bytes'
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_b32encode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_b32encode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 295,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 22,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 9,
        .line_info = fun_data_base64_b32encode + 5,
        .line_info_top = fun_data_base64_b32encode + 40,
        .opcodes = fun_data_base64_b32encode + 40,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_b32encode fun_data_base64_b32encode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_b32decode
static const byte fun_data_base64_b32decode[365] = {
    0xb3,0x90,0x01,0x66, // prelude
    0x0a,0x51,0x62,0x63, // names: b32decode, s, casefold, map01
    0x90,0x03,0x80,0x12,0x26,0x2e,0x23,0x69,0x20,0x26,0x26,0x33,0x30,0x23,0x66,0x20,0x28,0x25,0x28,0x4a,0x62,0x23,0x22,0x22,0x25,0x28,0x25,0x29,0x29,0x24,0x25,0x36,0x22,0x45,0x31,0x25,0x26,0x25,0x29,0x25,0x29,0x25,0x29,0x25,0x49,0x29,0x27, // code info
    0x12,0x0f, // LOAD_GLOBAL '_bytes_from_decode_data'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0xc0, // STORE_FAST 0
    0x12,0x61, // LOAD_GLOBAL 'divmod'
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x88, // LOAD_CONST_SMALL_INT 8
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc3, // STORE_FAST 3
    0xc4, // STORE_FAST 4
    0xb4, // LOAD_FAST 4
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x1a, // LOAD_METHOD 'Error'
    0x23,0x33, // LOAD_CONST_OBJ 51
    0x36,0x01, // CALL_METHOD 1
    0x65, // RAISE_OBJ
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x69, // POP_JUMP_IF_FALSE 41
    0x12,0x0f, // LOAD_GLOBAL '_bytes_from_decode_data'
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0xc2, // STORE_FAST 2
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0xd9, // BINARY_OP 2 __eq__
    0x43,0x4a, // POP_JUMP_IF_TRUE 10
    0x12,0x18, // LOAD_GLOBAL 'AssertionError'
    0x12,0x5d, // LOAD_GLOBAL 'repr'
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x14, // LOAD_GLOBAL '_translate'
    0xb0, // LOAD_FAST 0
    0x12,0x13, // LOAD_GLOBAL '_maketrans'
    0x23,0x34, // LOAD_CONST_OBJ 52
    0x23,0x1b, // LOAD_CONST_OBJ 27
    0xb2, // LOAD_FAST 2
    0xf2, // BINARY_OP 27 __add__
    0x34,0x02, // CALL_FUNCTION 2
    0x34,0x02, // CALL_FUNCTION 2
    0xc0, // STORE_FAST 0
    0xb1, // LOAD_FAST 1
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0xb0, // LOAD_FAST 0
    0x14,0x24, // LOAD_METHOD 'upper'
    0x36,0x00, // CALL_METHOD 0
    0xc0, // STORE_FAST 0
    0xb0, // LOAD_FAST 0
    0x14,0x25, // LOAD_METHOD 'find'
    0x23,0x32, // LOAD_CONST_OBJ 50
    0x36,0x01, // CALL_METHOD 1
    0xc5, // STORE_FAST 5
    0xb5, // LOAD_FAST 5
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x52, // POP_JUMP_IF_FALSE 18
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0xb5, // LOAD_FAST 5
    0xf3, // BINARY_OP 28 __sub__
    0xc5, // STORE_FAST 5
    0xb0, // LOAD_FAST 0
    0x51, // LOAD_CONST_NONE
    0xb5, // LOAD_FAST 5
    0xd1, // UNARY_OP 1 __neg__
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xc0, // STORE_FAST 0
    0x42,0x42, // JUMP 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc5, // STORE_FAST 5
    0x2b,0x00, // BUILD_LIST 0
    0xc6, // STORE_FAST 6
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc7, // STORE_FAST 7
    0xa3, // LOAD_CONST_SMALL_INT 35
    0xc8, // STORE_FAST 8
    0xb0, // LOAD_FAST 0
    0x5f, // GET_ITER_STACK
    0x4b,0x46, // FOR_ITER 70
    0xc9, // STORE_FAST 9
    0x12,0x4e, // LOAD_GLOBAL '_b32rev'
    0x14,0x15, // LOAD_METHOD 'get'
    0xb9, // LOAD_FAST 9
    0x36,0x01, // CALL_METHOD 1
    0xca, // STORE_FAST 10
    0xba, // LOAD_FAST 10
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x1a, // LOAD_METHOD 'Error'
    0x23,0x35, // LOAD_CONST_OBJ 53
    0x36,0x01, // CALL_METHOD 1
    0x65, // RAISE_OBJ
    0xb7, // LOAD_FAST 7
    0x12,0x4e, // LOAD_GLOBAL '_b32rev'
    0xb9, // LOAD_FAST 9
    0x55, // LOAD_SUBSCR
    0xb8, // LOAD_FAST 8
    0xf0, // BINARY_OP 25 __lshift__
    0xe5, // BINARY_OP 14 __iadd__
    0xc7, // STORE_FAST 7
    0xb8, // LOAD_FAST 8
    0x85, // LOAD_CONST_SMALL_INT 5
    0xe6, // BINARY_OP 15 __isub__
    0xc8, // STORE_FAST 8
    0xb8, // LOAD_FAST 8
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x5a, // POP_JUMP_IF_FALSE 26
    0xb6, // LOAD_FAST 6
    0x14,0x16, // LOAD_METHOD 'append'
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x26, // LOAD_METHOD 'unhexlify'
    0x12,0x47, // LOAD_GLOBAL 'bytes'
    0x10,0x27, // LOAD_CONST_STRING '%010x'
    0xb7, // LOAD_FAST 7
    0xf8, // BINARY_OP 33 __mod__
    0x10,0x10, // LOAD_CONST_STRING 'ascii'
    0x34,0x02, // CALL_FUNCTION 2
    0x36,0x01, // CALL_METHOD 1
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc7, // STORE_FAST 7
    0xa3, // LOAD_CONST_SMALL_INT 35
    0xc8, // STORE_FAST 8
    0x42,0xb8,0x7f, // JUMP -72
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x26, // LOAD_METHOD 'unhexlify'
    0x12,0x47, // LOAD_GLOBAL 'bytes'
    0x10,0x27, // LOAD_CONST_STRING '%010x'
    0xb7, // LOAD_FAST 7
    0xf8, // BINARY_OP 33 __mod__
    0x10,0x10, // LOAD_CONST_STRING 'ascii'
    0x34,0x02, // CALL_FUNCTION 2
    0x36,0x01, // CALL_METHOD 1
    0xcb, // STORE_FAST 11
    0xb5, // LOAD_FAST 5
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x23,0x36, // LOAD_CONST_OBJ 54
    0xcb, // STORE_FAST 11
    0x42,0xc1,0x80, // JUMP 65
    0xb5, // LOAD_FAST 5
    0x81, // LOAD_CONST_SMALL_INT 1
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0xbb, // LOAD_FAST 11
    0x51, // LOAD_CONST_NONE
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xcb, // STORE_FAST 11
    0x42,0x73, // JUMP 51
    0xb5, // LOAD_FAST 5
    0x83, // LOAD_CONST_SMALL_INT 3
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0xbb, // LOAD_FAST 11
    0x51, // LOAD_CONST_NONE
    0x7e, // LOAD_CONST_SMALL_INT -2
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xcb, // STORE_FAST 11
    0x42,0x65, // JUMP 37
    0xb5, // LOAD_FAST 5
    0x84, // LOAD_CONST_SMALL_INT 4
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0xbb, // LOAD_FAST 11
    0x51, // LOAD_CONST_NONE
    0x7d, // LOAD_CONST_SMALL_INT -3
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xcb, // STORE_FAST 11
    0x42,0x57, // JUMP 23
    0xb5, // LOAD_FAST 5
    0x86, // LOAD_CONST_SMALL_INT 6
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0xbb, // LOAD_FAST 11
    0x51, // LOAD_CONST_NONE
    0x7c, // LOAD_CONST_SMALL_INT -4
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xcb, // STORE_FAST 11
    0x42,0x49, // JUMP 9
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x1a, // LOAD_METHOD 'Error'
    0x23,0x33, // LOAD_CONST_OBJ 51
    0x36,0x01, // CALL_METHOD 1
    0x65, // RAISE_OBJ
    0xb6, // LOAD_FAST 6
    0x14,0x16, // LOAD_METHOD 'append'
    0xbb, // LOAD_FAST 11
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x23,0x36, // LOAD_CONST_OBJ 54
    0x14,0x28, // LOAD_METHOD 'join'
    0xb6, // LOAD_FAST 6
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_b32decode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_b32decode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 365,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 23,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name_idx = 10,
        .line_info = fun_data_base64_b32decode + 8,
        .line_info_top = fun_data_base64_b32decode + 55,
        .opcodes = fun_data_base64_b32decode + 55,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_b32decode fun_data_base64_b32decode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_b16encode
static const byte fun_data_base64_b16encode[44] = {
    0x19,0x10, // prelude
    0x0b,0x51, // names: b16encode, s
    0x90,0x50,0x60,0x20,0x29,0x2d, // code info
    0x12,0x52, // LOAD_GLOBAL 'isinstance'
    0xb0, // LOAD_FAST 0
    0x12,0x49, // LOAD_GLOBAL 'bytes_types'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x4d, // POP_JUMP_IF_TRUE 13
    0x12,0x55, // LOAD_GLOBAL 'TypeError'
    0x23,0x29, // LOAD_CONST_OBJ 41
    0xb0, // LOAD_FAST 0
    0x13,0x11, // LOAD_ATTR '__class__'
    0x13,0x12, // LOAD_ATTR '__name__'
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x29, // LOAD_METHOD 'hexlify'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0x14,0x24, // LOAD_METHOD 'upper'
    0x36,0x00, // CALL_METHOD 0
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_b16encode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_b16encode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 44,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 11,
        .line_info = fun_data_base64_b16encode + 4,
        .line_info_top = fun_data_base64_b16encode + 10,
        .opcodes = fun_data_base64_b16encode + 10,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_b16encode fun_data_base64_b16encode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_b16decode
static const byte fun_data_base64_b16decode[58] = {
    0xaa,0x01,0x18, // prelude
    0x0c,0x51,0x62, // names: b16decode, s, casefold
    0x90,0x5a,0x80,0x0a,0x26,0x23,0x26,0x2b,0x29, // code info
    0x12,0x0f, // LOAD_GLOBAL '_bytes_from_decode_data'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0xc0, // STORE_FAST 0
    0xb1, // LOAD_FAST 1
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0xb0, // LOAD_FAST 0
    0x14,0x24, // LOAD_METHOD 'upper'
    0x36,0x00, // CALL_METHOD 0
    0xc0, // STORE_FAST 0
    0x12,0x02, // LOAD_GLOBAL 're'
    0x14,0x2a, // LOAD_METHOD 'search'
    0x23,0x37, // LOAD_CONST_OBJ 55
    0xb0, // LOAD_FAST 0
    0x36,0x02, // CALL_METHOD 2
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x1a, // LOAD_METHOD 'Error'
    0x23,0x38, // LOAD_CONST_OBJ 56
    0x36,0x01, // CALL_METHOD 1
    0x65, // RAISE_OBJ
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x26, // LOAD_METHOD 'unhexlify'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_b16decode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_b16decode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 58,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 12,
        .line_info = fun_data_base64_b16decode + 6,
        .line_info_top = fun_data_base64_b16decode + 15,
        .opcodes = fun_data_base64_b16decode + 15,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_b16decode fun_data_base64_b16decode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_encode
static const byte fun_data_base64_encode[86] = {
    0x4a,0x20, // prelude
    0x05,0x64,0x65, // names: encode, input, output
    0x90,0x75,0x20,0x20,0x28,0x23,0x22,0x22,0x2e,0x23,0x22,0x2e,0x28, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x2b, // LOAD_METHOD 'read'
    0x12,0x50, // LOAD_GLOBAL 'MAXBINSIZE'
    0x36,0x01, // CALL_METHOD 1
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x43,0x42, // POP_JUMP_IF_TRUE 2
    0x42,0x75, // JUMP 53
    0x42,0x57, // JUMP 23
    0xb0, // LOAD_FAST 0
    0x14,0x2b, // LOAD_METHOD 'read'
    0x12,0x50, // LOAD_GLOBAL 'MAXBINSIZE'
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0xf3, // BINARY_OP 28 __sub__
    0x36,0x01, // CALL_METHOD 1
    0xc3, // STORE_FAST 3
    0xb3, // LOAD_FAST 3
    0x43,0x42, // POP_JUMP_IF_TRUE 2
    0x42,0x4e, // JUMP 14
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xe5, // BINARY_OP 14 __iadd__
    0xc2, // STORE_FAST 2
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0x12,0x50, // LOAD_GLOBAL 'MAXBINSIZE'
    0xd7, // BINARY_OP 0 __lt__
    0x43,0x1f, // POP_JUMP_IF_TRUE -33
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x17, // LOAD_METHOD 'b2a_base64'
    0xb2, // LOAD_FAST 2
    0x36,0x01, // CALL_METHOD 1
    0xc4, // STORE_FAST 4
    0xb1, // LOAD_FAST 1
    0x14,0x2c, // LOAD_METHOD 'write'
    0xb4, // LOAD_FAST 4
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0xbe,0x7f, // JUMP -66
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_encode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_encode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 86,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 5,
        .line_info = fun_data_base64_encode + 5,
        .line_info_top = fun_data_base64_encode + 18,
        .opcodes = fun_data_base64_encode + 18,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_encode fun_data_base64_encode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_decode
static const byte fun_data_base64_decode[43] = {
    0x32,0x16, // prelude
    0x06,0x64,0x65, // names: decode, input, output
    0x90,0x84,0x20,0x20,0x26,0x23,0x22,0x28, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x2d, // LOAD_METHOD 'readline'
    0x36,0x00, // CALL_METHOD 0
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x43,0x42, // POP_JUMP_IF_TRUE 2
    0x42,0x51, // JUMP 17
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x1b, // LOAD_METHOD 'a2b_base64'
    0xb2, // LOAD_FAST 2
    0x36,0x01, // CALL_METHOD 1
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0x14,0x2c, // LOAD_METHOD 'write'
    0xb3, // LOAD_FAST 3
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x24, // JUMP -28
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_decode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_decode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 43,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 6,
        .line_info = fun_data_base64_decode + 5,
        .line_info_top = fun_data_base64_decode + 13,
        .opcodes = fun_data_base64_decode + 13,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_decode fun_data_base64_decode[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_encodebytes
static const byte fun_data_base64_encodebytes[87] = {
    0x61,0x16, // prelude
    0x2e,0x51, // names: encodebytes, s
    0x90,0x8e,0x40,0x29,0x2d,0x23,0x30,0x2a,0x2f, // code info
    0x12,0x52, // LOAD_GLOBAL 'isinstance'
    0xb0, // LOAD_FAST 0
    0x12,0x49, // LOAD_GLOBAL 'bytes_types'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x4d, // POP_JUMP_IF_TRUE 13
    0x12,0x55, // LOAD_GLOBAL 'TypeError'
    0x23,0x29, // LOAD_CONST_OBJ 41
    0xb0, // LOAD_FAST 0
    0x13,0x11, // LOAD_ATTR '__class__'
    0x13,0x12, // LOAD_ATTR '__name__'
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x2b,0x00, // BUILD_LIST 0
    0xc1, // STORE_FAST 1
    0x12,0x66, // LOAD_GLOBAL 'range'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x12,0x58, // LOAD_GLOBAL 'len'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x12,0x50, // LOAD_GLOBAL 'MAXBINSIZE'
    0x34,0x03, // CALL_FUNCTION 3
    0x5f, // GET_ITER_STACK
    0x4b,0x1a, // FOR_ITER 26
    0xc2, // STORE_FAST 2
    0xb0, // LOAD_FAST 0
    0xb2, // LOAD_FAST 2
    0xb2, // LOAD_FAST 2
    0x12,0x50, // LOAD_GLOBAL 'MAXBINSIZE'
    0xf2, // BINARY_OP 27 __add__
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0x14,0x16, // LOAD_METHOD 'append'
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x17, // LOAD_METHOD 'b2a_base64'
    0xb3, // LOAD_FAST 3
    0x36,0x01, // CALL_METHOD 1
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x24, // JUMP -28
    0x23,0x36, // LOAD_CONST_OBJ 54
    0x14,0x28, // LOAD_METHOD 'join'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_encodebytes = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_encodebytes,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 87,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 46,
        .line_info = fun_data_base64_encodebytes + 4,
        .line_info_top = fun_data_base64_encodebytes + 13,
        .opcodes = fun_data_base64_encodebytes + 13,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_encodebytes fun_data_base64_encodebytes[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_encodestring
static const byte fun_data_base64_encodestring[31] = {
    0x31,0x0e, // prelude
    0x2f,0x51, // names: encodestring, s
    0x90,0x9a,0x20,0x45,0x2b, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x30, // IMPORT_NAME 'warnings'
    0xc1, // STORE_FAST 1
    0xb1, // LOAD_FAST 1
    0x14,0x31, // LOAD_METHOD 'warn'
    0x23,0x39, // LOAD_CONST_OBJ 57
    0x12,0x67, // LOAD_GLOBAL 'DeprecationWarning'
    0x82, // LOAD_CONST_SMALL_INT 2
    0x36,0x03, // CALL_METHOD 3
    0x59, // POP_TOP
    0x12,0x2e, // LOAD_GLOBAL 'encodebytes'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_encodestring = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_encodestring,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 31,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 47,
        .line_info = fun_data_base64_encodestring + 4,
        .line_info_top = fun_data_base64_encodestring + 9,
        .opcodes = fun_data_base64_encodestring + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_encodestring fun_data_base64_encodestring[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_decodebytes
static const byte fun_data_base64_decodebytes[39] = {
    0x19,0x0e, // prelude
    0x32,0x51, // names: decodebytes, s
    0x90,0xa2,0x20,0x29,0x2d, // code info
    0x12,0x52, // LOAD_GLOBAL 'isinstance'
    0xb0, // LOAD_FAST 0
    0x12,0x49, // LOAD_GLOBAL 'bytes_types'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x4d, // POP_JUMP_IF_TRUE 13
    0x12,0x55, // LOAD_GLOBAL 'TypeError'
    0x23,0x29, // LOAD_CONST_OBJ 41
    0xb0, // LOAD_FAST 0
    0x13,0x11, // LOAD_ATTR '__class__'
    0x13,0x12, // LOAD_ATTR '__name__'
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x04, // LOAD_GLOBAL 'binascii'
    0x14,0x1b, // LOAD_METHOD 'a2b_base64'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_decodebytes = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_decodebytes,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 39,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 50,
        .line_info = fun_data_base64_decodebytes + 4,
        .line_info_top = fun_data_base64_decodebytes + 9,
        .opcodes = fun_data_base64_decodebytes + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_decodebytes fun_data_base64_decodebytes[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_decodestring
static const byte fun_data_base64_decodestring[31] = {
    0x31,0x0e, // prelude
    0x33,0x51, // names: decodestring, s
    0x90,0xa9,0x20,0x45,0x2b, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x30, // IMPORT_NAME 'warnings'
    0xc1, // STORE_FAST 1
    0xb1, // LOAD_FAST 1
    0x14,0x31, // LOAD_METHOD 'warn'
    0x23,0x3a, // LOAD_CONST_OBJ 58
    0x12,0x67, // LOAD_GLOBAL 'DeprecationWarning'
    0x82, // LOAD_CONST_SMALL_INT 2
    0x36,0x03, // CALL_METHOD 3
    0x59, // POP_TOP
    0x12,0x32, // LOAD_GLOBAL 'decodebytes'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_decodestring = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_decodestring,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 31,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 51,
        .line_info = fun_data_base64_decodestring + 4,
        .line_info_top = fun_data_base64_decodestring + 9,
        .opcodes = fun_data_base64_decodestring + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_decodestring fun_data_base64_decodestring[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_main
static const byte fun_data_base64_main[223] = {
    0xf8,0x02,0x3a, // prelude
    0x34, // names: main
    0x90,0xb2,0x20,0x4a,0x22,0x36,0x29,0x26,0x26,0x22,0x62,0x20,0x49,0x30,0x23,0x28,0x26,0x23,0x26,0x23,0x26,0x23,0x26,0x25,0x24,0x2b,0x2c,0x4f, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x35, // IMPORT_NAME 'sys'
    0xc0, // STORE_FAST 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x36, // IMPORT_NAME 'getopt'
    0xc1, // STORE_FAST 1
    0x48,0x15, // SETUP_EXCEPT 21
    0xb1, // LOAD_FAST 1
    0x14,0x36, // LOAD_METHOD 'getopt'
    0xb0, // LOAD_FAST 0
    0x13,0x37, // LOAD_ATTR 'argv'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x10,0x38, // LOAD_CONST_STRING 'deut'
    0x36,0x02, // CALL_METHOD 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0x4a,0x33, // POP_EXCEPT_JUMP 51
    0x57, // DUP_TOP
    0xb1, // LOAD_FAST 1
    0x13,0x39, // LOAD_ATTR 'error'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x6b, // POP_JUMP_IF_FALSE 43
    0xc4, // STORE_FAST 4
    0x49,0x21, // SETUP_FINALLY 33
    0xb0, // LOAD_FAST 0
    0x13,0x3a, // LOAD_ATTR 'stderr'
    0xb0, // LOAD_FAST 0
    0x18,0x3b, // STORE_ATTR 'stdout'
    0x12,0x68, // LOAD_GLOBAL 'print'
    0xb4, // LOAD_FAST 4
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x12,0x68, // LOAD_GLOBAL 'print'
    0x23,0x3b, // LOAD_CONST_OBJ 59
    0xb0, // LOAD_FAST 0
    0x13,0x37, // LOAD_ATTR 'argv'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x14,0x3c, // LOAD_METHOD 'exit'
    0x82, // LOAD_CONST_SMALL_INT 2
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0xc4, // STORE_FAST 4
    0x28,0x04, // DELETE_FAST 4
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0x12,0x05, // LOAD_GLOBAL 'encode'
    0xc5, // STORE_FAST 5
    0xb2, // LOAD_FAST 2
    0x5f, // GET_ITER_STACK
    0x4b,0x2e, // FOR_ITER 46
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc6, // STORE_FAST 6
    0xc7, // STORE_FAST 7
    0xb6, // LOAD_FAST 6
    0x10,0x3d, // LOAD_CONST_STRING '-e'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x12,0x05, // LOAD_GLOBAL 'encode'
    0xc5, // STORE_FAST 5
    0xb6, // LOAD_FAST 6
    0x10,0x3e, // LOAD_CONST_STRING '-d'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x12,0x06, // LOAD_GLOBAL 'decode'
    0xc5, // STORE_FAST 5
    0xb6, // LOAD_FAST 6
    0x10,0x3f, // LOAD_CONST_STRING '-u'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x12,0x06, // LOAD_GLOBAL 'decode'
    0xc5, // STORE_FAST 5
    0xb6, // LOAD_FAST 6
    0x10,0x40, // LOAD_CONST_STRING '-t'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0x12,0x45, // LOAD_GLOBAL 'test'
    0x34,0x00, // CALL_FUNCTION 0
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0x42,0x10, // JUMP -48
    0xb3, // LOAD_FAST 3
    0x44,0x63, // POP_JUMP_IF_FALSE 35
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x10,0x41, // LOAD_CONST_STRING '-'
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x5b, // POP_JUMP_IF_FALSE 27
    0x12,0x69, // LOAD_GLOBAL 'open'
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x10,0x42, // LOAD_CONST_STRING 'rb'
    0x34,0x02, // CALL_FUNCTION 2
    0x47,0x0c, // SETUP_WITH 12
    0xc8, // STORE_FAST 8
    0xb5, // LOAD_FAST 5
    0xb8, // LOAD_FAST 8
    0xb0, // LOAD_FAST 0
    0x13,0x3b, // LOAD_ATTR 'stdout'
    0x13,0x43, // LOAD_ATTR 'buffer'
    0x34,0x02, // CALL_FUNCTION 2
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x5c, // WITH_CLEANUP
    0x5d, // END_FINALLY
    0x42,0x4e, // JUMP 14
    0xb5, // LOAD_FAST 5
    0xb0, // LOAD_FAST 0
    0x13,0x44, // LOAD_ATTR 'stdin'
    0x13,0x43, // LOAD_ATTR 'buffer'
    0xb0, // LOAD_FAST 0
    0x13,0x3b, // LOAD_ATTR 'stdout'
    0x13,0x43, // LOAD_ATTR 'buffer'
    0x34,0x02, // CALL_FUNCTION 2
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_main = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_main,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 223,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 16,
        .n_exc_stack = 2,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 52,
        .line_info = fun_data_base64_main + 4,
        .line_info_top = fun_data_base64_main + 32,
        .opcodes = fun_data_base64_main + 32,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_main fun_data_base64_main[0]
#endif

// child of base64__lt_module_gt_
// frozen bytecode for file base64.py, scope base64_test
static const byte fun_data_base64_test[66] = {
    0x28,0x12, // prelude
    0x45, // names: test
    0x90,0xd5,0x23,0x2a,0x26,0x2a,0x26,0x2a, // code info
    0x23,0x3c, // LOAD_CONST_OBJ 60
    0xc0, // STORE_FAST 0
    0x12,0x68, // LOAD_GLOBAL 'print'
    0x12,0x5d, // LOAD_GLOBAL 'repr'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x12,0x2e, // LOAD_GLOBAL 'encodebytes'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0xc1, // STORE_FAST 1
    0x12,0x68, // LOAD_GLOBAL 'print'
    0x12,0x5d, // LOAD_GLOBAL 'repr'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x12,0x32, // LOAD_GLOBAL 'decodebytes'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xc2, // STORE_FAST 2
    0x12,0x68, // LOAD_GLOBAL 'print'
    0x12,0x5d, // LOAD_GLOBAL 'repr'
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0xb2, // LOAD_FAST 2
    0xd9, // BINARY_OP 2 __eq__
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0x12,0x18, // LOAD_GLOBAL 'AssertionError'
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_base64_test = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64_test,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 66,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 69,
        .line_info = fun_data_base64_test + 3,
        .line_info_top = fun_data_base64_test + 11,
        .opcodes = fun_data_base64_test + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_base64_test fun_data_base64_test[0]
#endif

static const mp_raw_code_t *const children_base64__lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_base64__bytes_from_decode_data,
    (const mp_raw_code_t *)&proto_fun_base64__maketrans,
    (const mp_raw_code_t *)&proto_fun_base64__translate,
    (const mp_raw_code_t *)&proto_fun_base64_b64encode,
    (const mp_raw_code_t *)&proto_fun_base64_b64decode,
    (const mp_raw_code_t *)&proto_fun_base64_standard_b64encode,
    (const mp_raw_code_t *)&proto_fun_base64_standard_b64decode,
    (const mp_raw_code_t *)&proto_fun_base64_urlsafe_b64encode,
    (const mp_raw_code_t *)&proto_fun_base64_urlsafe_b64decode,
    (const mp_raw_code_t *)&proto_fun_base64__lt_listcomp_gt_,
    (const mp_raw_code_t *)&proto_fun_base64__lt_listcomp_gt_2,
    (const mp_raw_code_t *)&proto_fun_base64_b32encode,
    (const mp_raw_code_t *)&proto_fun_base64_b32decode,
    (const mp_raw_code_t *)&proto_fun_base64_b16encode,
    (const mp_raw_code_t *)&proto_fun_base64_b16decode,
    (const mp_raw_code_t *)&proto_fun_base64_encode,
    (const mp_raw_code_t *)&proto_fun_base64_decode,
    (const mp_raw_code_t *)&proto_fun_base64_encodebytes,
    (const mp_raw_code_t *)&proto_fun_base64_encodestring,
    (const mp_raw_code_t *)&proto_fun_base64_decodebytes,
    (const mp_raw_code_t *)&proto_fun_base64_decodestring,
    (const mp_raw_code_t *)&proto_fun_base64_main,
    (const mp_raw_code_t *)&proto_fun_base64_test,
};

static const mp_raw_code_truncated_t proto_fun_base64__lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_base64__lt_module_gt_,
    .children = (void *)&children_base64__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 453,
    .n_children = 23,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 14,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_base64__lt_module_gt_ + 4,
        .line_info_top = fun_data_base64__lt_module_gt_ + 102,
        .opcodes = fun_data_base64__lt_module_gt_ + 102,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_base64[106] = {
    MP_QSTR_base64_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_re,
    MP_QSTR_struct,
    MP_QSTR_binascii,
    MP_QSTR_encode,
    MP_QSTR_decode,
    MP_QSTR_b64encode,
    MP_QSTR_b64decode,
    MP_QSTR_b32encode,
    MP_QSTR_b32decode,
    MP_QSTR_b16encode,
    MP_QSTR_b16decode,
    MP_QSTR_items,
    MP_QSTR___main__,
    MP_QSTR__bytes_from_decode_data,
    MP_QSTR_ascii,
    MP_QSTR___class__,
    MP_QSTR___name__,
    MP_QSTR__maketrans,
    MP_QSTR__translate,
    MP_QSTR_get,
    MP_QSTR_append,
    MP_QSTR_b2a_base64,
    MP_QSTR_AssertionError,
    MP_QSTR_match,
    MP_QSTR_Error,
    MP_QSTR_a2b_base64,
    MP_QSTR_standard_b64encode,
    MP_QSTR_standard_b64decode,
    MP_QSTR_urlsafe_b64encode,
    MP_QSTR_rstrip,
    MP_QSTR_urlsafe_b64decode,
    MP_QSTR__lt_listcomp_gt_,
    MP_QSTR_unpack,
    MP_QSTR__bang_HHB,
    MP_QSTR_upper,
    MP_QSTR_find,
    MP_QSTR_unhexlify,
    MP_QSTR__percent_010x,
    MP_QSTR_join,
    MP_QSTR_hexlify,
    MP_QSTR_search,
    MP_QSTR_read,
    MP_QSTR_write,
    MP_QSTR_readline,
    MP_QSTR_encodebytes,
    MP_QSTR_encodestring,
    MP_QSTR_warnings,
    MP_QSTR_warn,
    MP_QSTR_decodebytes,
    MP_QSTR_decodestring,
    MP_QSTR_main,
    MP_QSTR_sys,
    MP_QSTR_getopt,
    MP_QSTR_argv,
    MP_QSTR_deut,
    MP_QSTR_error,
    MP_QSTR_stderr,
    MP_QSTR_stdout,
    MP_QSTR_exit,
    MP_QSTR__hyphen_e,
    MP_QSTR__hyphen_d,
    MP_QSTR__hyphen_u,
    MP_QSTR__hyphen_t,
    MP_QSTR__hyphen_,
    MP_QSTR_rb,
    MP_QSTR_buffer,
    MP_QSTR_stdin,
    MP_QSTR_test,
    MP_QSTR___all__,
    MP_QSTR_bytes,
    MP_QSTR_bytearray,
    MP_QSTR_bytes_types,
    MP_QSTR__b32alphabet,
    MP_QSTR_sorted,
    MP_QSTR__b32tab,
    MP_QSTR_dict,
    MP_QSTR__b32rev,
    MP_QSTR_MAXLINESIZE,
    MP_QSTR_MAXBINSIZE,
    MP_QSTR_s,
    MP_QSTR_isinstance,
    MP_QSTR_str,
    MP_QSTR_ValueError,
    MP_QSTR_TypeError,
    MP_QSTR_f,
    MP_QSTR_t,
    MP_QSTR_len,
    MP_QSTR_zip,
    MP_QSTR_input_bytes,
    MP_QSTR_trans_table,
    MP_QSTR_altchars,
    MP_QSTR_repr,
    MP_QSTR_validate,
    MP_QSTR_NotImplementedError,
    MP_QSTR__star_,
    MP_QSTR_divmod,
    MP_QSTR_casefold,
    MP_QSTR_map01,
    MP_QSTR_input,
    MP_QSTR_output,
    MP_QSTR_range,
    MP_QSTR_DeprecationWarning,
    MP_QSTR_print,
    MP_QSTR_open,
};

// constants
static const mp_obj_str_t const_obj_base64_6 = {{&mp_type_bytes}, 46564, 1, (const byte*)"\x41"};
static const mp_obj_str_t const_obj_base64_7 = {{&mp_type_bytes}, 46575, 1, (const byte*)"\x4a"};
static const mp_obj_str_t const_obj_base64_8 = {{&mp_type_bytes}, 46582, 1, (const byte*)"\x53"};
static const mp_obj_str_t const_obj_base64_9 = {{&mp_type_bytes}, 46486, 1, (const byte*)"\x33"};
static const mp_obj_str_t const_obj_base64_10 = {{&mp_type_bytes}, 46567, 1, (const byte*)"\x42"};
static const mp_obj_str_t const_obj_base64_11 = {{&mp_type_bytes}, 46574, 1, (const byte*)"\x4b"};
static const mp_obj_str_t const_obj_base64_12 = {{&mp_type_bytes}, 46577, 1, (const byte*)"\x54"};
static const mp_obj_str_t const_obj_base64_13 = {{&mp_type_bytes}, 46481, 1, (const byte*)"\x34"};
static const mp_obj_str_t const_obj_base64_14 = {{&mp_type_bytes}, 46566, 1, (const byte*)"\x43"};
static const mp_obj_str_t const_obj_base64_15 = {{&mp_type_bytes}, 46569, 1, (const byte*)"\x4c"};
static const mp_obj_str_t const_obj_base64_16 = {{&mp_type_bytes}, 46576, 1, (const byte*)"\x55"};
static const mp_obj_str_t const_obj_base64_17 = {{&mp_type_bytes}, 46480, 1, (const byte*)"\x35"};
static const mp_obj_str_t const_obj_base64_18 = {{&mp_type_bytes}, 46561, 1, (const byte*)"\x44"};
static const mp_obj_str_t const_obj_base64_19 = {{&mp_type_bytes}, 46568, 1, (const byte*)"\x4d"};
static const mp_obj_str_t const_obj_base64_20 = {{&mp_type_bytes}, 46579, 1, (const byte*)"\x56"};
static const mp_obj_str_t const_obj_base64_21 = {{&mp_type_bytes}, 46483, 1, (const byte*)"\x36"};
static const mp_obj_str_t const_obj_base64_22 = {{&mp_type_bytes}, 46560, 1, (const byte*)"\x45"};
static const mp_obj_str_t const_obj_base64_23 = {{&mp_type_bytes}, 46571, 1, (const byte*)"\x4e"};
static const mp_obj_str_t const_obj_base64_24 = {{&mp_type_bytes}, 46578, 1, (const byte*)"\x57"};
static const mp_obj_str_t const_obj_base64_25 = {{&mp_type_bytes}, 46482, 1, (const byte*)"\x37"};
static const mp_obj_str_t const_obj_base64_26 = {{&mp_type_bytes}, 46563, 1, (const byte*)"\x46"};
static const mp_obj_str_t const_obj_base64_27 = {{&mp_type_bytes}, 46570, 1, (const byte*)"\x4f"};
static const mp_obj_str_t const_obj_base64_28 = {{&mp_type_bytes}, 46589, 1, (const byte*)"\x58"};
static const mp_obj_str_t const_obj_base64_29 = {{&mp_type_bytes}, 46562, 1, (const byte*)"\x47"};
static const mp_obj_str_t const_obj_base64_30 = {{&mp_type_bytes}, 46581, 1, (const byte*)"\x50"};
static const mp_obj_str_t const_obj_base64_31 = {{&mp_type_bytes}, 46588, 1, (const byte*)"\x59"};
static const mp_obj_str_t const_obj_base64_32 = {{&mp_type_bytes}, 46573, 1, (const byte*)"\x48"};
static const mp_obj_str_t const_obj_base64_33 = {{&mp_type_bytes}, 46580, 1, (const byte*)"\x51"};
static const mp_obj_str_t const_obj_base64_34 = {{&mp_type_bytes}, 46591, 1, (const byte*)"\x5a"};
static const mp_obj_str_t const_obj_base64_35 = {{&mp_type_bytes}, 46572, 1, (const byte*)"\x49"};
static const mp_obj_str_t const_obj_base64_36 = {{&mp_type_bytes}, 46583, 1, (const byte*)"\x52"};
static const mp_obj_str_t const_obj_base64_37 = {{&mp_type_bytes}, 46487, 1, (const byte*)"\x32"};
static const mp_obj_str_t const_obj_base64_38 = {{&mp_type_str}, 51189, 52, (const byte*)"\x73\x74\x72\x69\x6e\x67\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x73\x68\x6f\x75\x6c\x64\x20\x63\x6f\x6e\x74\x61\x69\x6e\x20\x6f\x6e\x6c\x79\x20\x41\x53\x43\x49\x49\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x73"};
static const mp_obj_str_t const_obj_base64_39 = {{&mp_type_str}, 8599, 48, (const byte*)"\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x73\x68\x6f\x75\x6c\x64\x20\x62\x65\x20\x62\x79\x74\x65\x73\x20\x6f\x72\x20\x41\x53\x43\x49\x49\x20\x73\x74\x72\x69\x6e\x67\x2c\x20\x6e\x6f\x74\x20\x25\x73"};
static const mp_obj_str_t const_obj_base64_40 = {{&mp_type_str}, 10366, 41, (const byte*)"\x6d\x61\x6b\x65\x74\x72\x61\x6e\x73\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x6d\x75\x73\x74\x20\x68\x61\x76\x65\x20\x73\x61\x6d\x65\x20\x6c\x65\x6e\x67\x74\x68"};
static const mp_obj_str_t const_obj_base64_42 = {{&mp_type_bytes}, 26465, 2, (const byte*)"\x2b\x2f"};
static const mp_obj_str_t const_obj_base64_43 = {{&mp_type_bytes}, 61284, 18, (const byte*)"\x5e\x5b\x41\x2d\x5a\x61\x2d\x7a\x30\x2d\x39\x2b\x2f\x5d\x2a\x3d\x2a\x24"};
static const mp_obj_str_t const_obj_base64_45 = {{&mp_type_bytes}, 26327, 2, (const byte*)"\x2d\x5f"};
static const mp_obj_str_t const_obj_base64_46 = {{&mp_type_bytes}, 46511, 1, (const byte*)"\x0a"};
static const mp_obj_str_t const_obj_base64_47 = {{&mp_type_bytes}, 20453, 6, (const byte*)"\x3d\x3d\x3d\x3d\x3d\x3d"};
static const mp_obj_str_t const_obj_base64_48 = {{&mp_type_bytes}, 11333, 4, (const byte*)"\x3d\x3d\x3d\x3d"};
static const mp_obj_str_t const_obj_base64_49 = {{&mp_type_bytes}, 32120, 3, (const byte*)"\x3d\x3d\x3d"};
static const mp_obj_str_t const_obj_base64_50 = {{&mp_type_bytes}, 46488, 1, (const byte*)"\x3d"};
static const mp_obj_str_t const_obj_base64_52 = {{&mp_type_bytes}, 26628, 2, (const byte*)"\x30\x31"};
static const mp_obj_str_t const_obj_base64_55 = {{&mp_type_bytes}, 24691, 9, (const byte*)"\x5b\x5e\x30\x2d\x39\x41\x2d\x46\x5d"};
static const mp_obj_str_t const_obj_base64_57 = {{&mp_type_str}, 17498, 55, (const byte*)"\x65\x6e\x63\x6f\x64\x65\x73\x74\x72\x69\x6e\x67\x28\x29\x20\x69\x73\x20\x61\x20\x64\x65\x70\x72\x65\x63\x61\x74\x65\x64\x20\x61\x6c\x69\x61\x73\x2c\x20\x75\x73\x65\x20\x65\x6e\x63\x6f\x64\x65\x62\x79\x74\x65\x73\x28\x29"};
static const mp_obj_str_t const_obj_base64_58 = {{&mp_type_str}, 54874, 55, (const byte*)"\x64\x65\x63\x6f\x64\x65\x73\x74\x72\x69\x6e\x67\x28\x29\x20\x69\x73\x20\x61\x20\x64\x65\x70\x72\x65\x63\x61\x74\x65\x64\x20\x61\x6c\x69\x61\x73\x2c\x20\x75\x73\x65\x20\x64\x65\x63\x6f\x64\x65\x62\x79\x74\x65\x73\x28\x29"};
static const mp_obj_str_t const_obj_base64_59 = {{&mp_type_str}, 17350, 143, (const byte*)"\x75\x73\x61\x67\x65\x3a\x20\x25\x73\x20\x5b\x2d\x64\x7c\x2d\x65\x7c\x2d\x75\x7c\x2d\x74\x5d\x20\x5b\x66\x69\x6c\x65\x7c\x2d\x5d\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x2d\x64\x2c\x20\x2d\x75\x3a\x20\x64\x65\x63\x6f\x64\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x2d\x65\x3a\x20\x65\x6e\x63\x6f\x64\x65\x20\x28\x64\x65\x66\x61\x75\x6c\x74\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x2d\x74\x3a\x20\x65\x6e\x63\x6f\x64\x65\x20\x61\x6e\x64\x20\x64\x65\x63\x6f\x64\x65\x20\x73\x74\x72\x69\x6e\x67\x20\x27\x41\x6c\x61\x64\x64\x69\x6e\x3a\x6f\x70\x65\x6e\x20\x73\x65\x73\x61\x6d\x65\x27"};
static const mp_obj_str_t const_obj_base64_60 = {{&mp_type_bytes}, 42156, 19, (const byte*)"\x41\x6c\x61\x64\x64\x69\x6e\x3a\x6f\x70\x65\x6e\x20\x73\x65\x73\x61\x6d\x65"};

// constant table
static const mp_rom_obj_t const_obj_table_data_base64[61] = {
    MP_ROM_QSTR(MP_QSTR_encodebytes),
    MP_ROM_QSTR(MP_QSTR_decodebytes),
    MP_ROM_QSTR(MP_QSTR_standard_b64encode),
    MP_ROM_QSTR(MP_QSTR_standard_b64decode),
    MP_ROM_QSTR(MP_QSTR_urlsafe_b64encode),
    MP_ROM_QSTR(MP_QSTR_urlsafe_b64decode),
    MP_ROM_PTR(&const_obj_base64_6),
    MP_ROM_PTR(&const_obj_base64_7),
    MP_ROM_PTR(&const_obj_base64_8),
    MP_ROM_PTR(&const_obj_base64_9),
    MP_ROM_PTR(&const_obj_base64_10),
    MP_ROM_PTR(&const_obj_base64_11),
    MP_ROM_PTR(&const_obj_base64_12),
    MP_ROM_PTR(&const_obj_base64_13),
    MP_ROM_PTR(&const_obj_base64_14),
    MP_ROM_PTR(&const_obj_base64_15),
    MP_ROM_PTR(&const_obj_base64_16),
    MP_ROM_PTR(&const_obj_base64_17),
    MP_ROM_PTR(&const_obj_base64_18),
    MP_ROM_PTR(&const_obj_base64_19),
    MP_ROM_PTR(&const_obj_base64_20),
    MP_ROM_PTR(&const_obj_base64_21),
    MP_ROM_PTR(&const_obj_base64_22),
    MP_ROM_PTR(&const_obj_base64_23),
    MP_ROM_PTR(&const_obj_base64_24),
    MP_ROM_PTR(&const_obj_base64_25),
    MP_ROM_PTR(&const_obj_base64_26),
    MP_ROM_PTR(&const_obj_base64_27),
    MP_ROM_PTR(&const_obj_base64_28),
    MP_ROM_PTR(&const_obj_base64_29),
    MP_ROM_PTR(&const_obj_base64_30),
    MP_ROM_PTR(&const_obj_base64_31),
    MP_ROM_PTR(&const_obj_base64_32),
    MP_ROM_PTR(&const_obj_base64_33),
    MP_ROM_PTR(&const_obj_base64_34),
    MP_ROM_PTR(&const_obj_base64_35),
    MP_ROM_PTR(&const_obj_base64_36),
    MP_ROM_PTR(&const_obj_base64_37),
    MP_ROM_PTR(&const_obj_base64_38),
    MP_ROM_PTR(&const_obj_base64_39),
    MP_ROM_PTR(&const_obj_base64_40),
    MP_ROM_QSTR(MP_QSTR_expected_space_bytes_comma__space_not_space__percent_s),
    MP_ROM_PTR(&const_obj_base64_42),
    MP_ROM_PTR(&const_obj_base64_43),
    MP_ROM_QSTR(MP_QSTR_Non_hyphen_base64_space_digit_space_found),
    MP_ROM_PTR(&const_obj_base64_45),
    MP_ROM_PTR(&const_obj_base64_46),
    MP_ROM_PTR(&const_obj_base64_47),
    MP_ROM_PTR(&const_obj_base64_48),
    MP_ROM_PTR(&const_obj_base64_49),
    MP_ROM_PTR(&const_obj_base64_50),
    MP_ROM_QSTR(MP_QSTR_Incorrect_space_padding),
    MP_ROM_PTR(&const_obj_base64_52),
    MP_ROM_QSTR(MP_QSTR_Non_hyphen_base32_space_digit_space_found),
    MP_ROM_PTR(&mp_const_empty_bytes_obj),
    MP_ROM_PTR(&const_obj_base64_55),
    MP_ROM_QSTR(MP_QSTR_Non_hyphen_base16_space_digit_space_found),
    MP_ROM_PTR(&const_obj_base64_57),
    MP_ROM_PTR(&const_obj_base64_58),
    MP_ROM_PTR(&const_obj_base64_59),
    MP_ROM_PTR(&const_obj_base64_60),
};

static const mp_frozen_module_t frozen_module_base64 = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_base64,
        .obj_table = (mp_obj_t *)&const_obj_table_data_base64,
    },
    .proto_fun = &proto_fun_base64__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module datetime
// - original source file: build/frozen_mpy/datetime.mpy
// - frozen file name: datetime.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file datetime.py, scope datetime__lt_module_gt_
static const byte fun_data_datetime__lt_module_gt_[361] = {
    0x50,0x68, // prelude
    0x01, // names: <module>
    0x40,0x28,0x26,0x26,0x26,0x62,0x64,0x20,0x84,0x07,0x64,0x40,0x84,0x14,0x23,0x66,0x89,0x99,0x31,0x1f,0x23,0x6c,0x89,0x1c,0x8b,0x26,0x6d,0x84,0x0d,0x64,0x60,0x64,0x20,0x89,0x65,0x2c,0x2c,0x6c,0x84,0x0d,0x84,0x43,0x84,0x09,0x89,0x74,0x29,0x31,0x68,0x99,0x24, // code info
    0x11,0x71, // LOAD_NAME '__import__'
    0x10,0x02, // LOAD_CONST_STRING 'time'
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x72, // STORE_NAME '_tmod'
    0x11,0x72, // LOAD_NAME '_tmod'
    0x13,0x03, // LOAD_ATTR 'gmtime'
    0x16,0x73, // STORE_NAME '_gmtime'
    0x11,0x72, // LOAD_NAME '_tmod'
    0x13,0x04, // LOAD_ATTR 'localtime'
    0x16,0x74, // STORE_NAME '_localtime'
    0x11,0x72, // LOAD_NAME '_tmod'
    0x13,0x02, // LOAD_ATTR 'time'
    0x16,0x75, // STORE_NAME '_epoch_time'
    0x19,0x72, // DELETE_NAME '_tmod'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x14, // STORE_NAME '_leap'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x15, // STORE_NAME '_dim'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x16, // STORE_NAME '_dbm'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x17, // STORE_NAME '_o2ymd'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x16,0x76, // STORE_NAME 'MINYEAR'
    0x22,0x80,0xce,0x0f, // LOAD_CONST_SMALL_INT 9999
    0x16,0x77, // STORE_NAME 'MAXYEAR'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x04, // MAKE_FUNCTION 4
    0x10,0x05, // LOAD_CONST_STRING 'timedelta'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x05, // STORE_NAME 'timedelta'
    0x11,0x05, // LOAD_NAME 'timedelta'
    0x10,0x06, // LOAD_CONST_STRING 'days'
    0x22,0xfc,0xa3,0x94,0xec,0x01, // LOAD_CONST_SMALL_INT -999999999
    0x34,0x82,0x00, // CALL_FUNCTION 256
    0x11,0x05, // LOAD_NAME 'timedelta'
    0x18,0x07, // STORE_ATTR 'min'
    0x11,0x05, // LOAD_NAME 'timedelta'
    0x10,0x06, // LOAD_CONST_STRING 'days'
    0x22,0x83,0xdc,0xeb,0x93,0x7f, // LOAD_CONST_SMALL_INT 999999999
    0x10,0x08, // LOAD_CONST_STRING 'hours'
    0x97, // LOAD_CONST_SMALL_INT 23
    0x10,0x09, // LOAD_CONST_STRING 'minutes'
    0x22,0x3b, // LOAD_CONST_SMALL_INT 59
    0x10,0x0a, // LOAD_CONST_STRING 'seconds'
    0x22,0x3b, // LOAD_CONST_SMALL_INT 59
    0x10,0x0b, // LOAD_CONST_STRING 'microseconds'
    0x22,0xbd,0x84,0x3f, // LOAD_CONST_SMALL_INT 999999
    0x34,0x8a,0x00, // CALL_FUNCTION 1280
    0x11,0x05, // LOAD_NAME 'timedelta'
    0x18,0x0c, // STORE_ATTR 'max'
    0x11,0x05, // LOAD_NAME 'timedelta'
    0x10,0x0b, // LOAD_CONST_STRING 'microseconds'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x34,0x82,0x00, // CALL_FUNCTION 256
    0x11,0x05, // LOAD_NAME 'timedelta'
    0x18,0x0d, // STORE_ATTR 'resolution'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x05, // MAKE_FUNCTION 5
    0x10,0x0e, // LOAD_CONST_STRING 'tzinfo'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x0e, // STORE_NAME 'tzinfo'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x06, // MAKE_FUNCTION 6
    0x10,0x0f, // LOAD_CONST_STRING 'timezone'
    0x11,0x0e, // LOAD_NAME 'tzinfo'
    0x34,0x03, // CALL_FUNCTION 3
    0x16,0x0f, // STORE_NAME 'timezone'
    0x11,0x0f, // LOAD_NAME 'timezone'
    0x11,0x05, // LOAD_NAME 'timedelta'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x11,0x0f, // LOAD_NAME 'timezone'
    0x18,0x10, // STORE_ATTR 'utc'
    0x32,0x07, // MAKE_FUNCTION 7
    0x16,0x18, // STORE_NAME '_date'
    0x32,0x08, // MAKE_FUNCTION 8
    0x16,0x19, // STORE_NAME '_iso2d'
    0x32,0x09, // MAKE_FUNCTION 9
    0x16,0x1b, // STORE_NAME '_d2iso'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x0a, // MAKE_FUNCTION 10
    0x10,0x11, // LOAD_CONST_STRING 'date'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x11, // STORE_NAME 'date'
    0x11,0x11, // LOAD_NAME 'date'
    0x11,0x76, // LOAD_NAME 'MINYEAR'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0x34,0x03, // CALL_FUNCTION 3
    0x11,0x11, // LOAD_NAME 'date'
    0x18,0x07, // STORE_ATTR 'min'
    0x11,0x11, // LOAD_NAME 'date'
    0x11,0x77, // LOAD_NAME 'MAXYEAR'
    0x8c, // LOAD_CONST_SMALL_INT 12
    0x9f, // LOAD_CONST_SMALL_INT 31
    0x34,0x03, // CALL_FUNCTION 3
    0x11,0x11, // LOAD_NAME 'date'
    0x18,0x0c, // STORE_ATTR 'max'
    0x11,0x05, // LOAD_NAME 'timedelta'
    0x10,0x06, // LOAD_CONST_STRING 'days'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x34,0x82,0x00, // CALL_FUNCTION 256
    0x11,0x11, // LOAD_NAME 'date'
    0x18,0x0d, // STORE_ATTR 'resolution'
    0x32,0x0b, // MAKE_FUNCTION 11
    0x16,0x1c, // STORE_NAME '_time'
    0x32,0x0c, // MAKE_FUNCTION 12
    0x16,0x1d, // STORE_NAME '_iso2t'
    0x32,0x0d, // MAKE_FUNCTION 13
    0x16,0x23, // STORE_NAME '_t2iso'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x0e, // MAKE_FUNCTION 14
    0x10,0x02, // LOAD_CONST_STRING 'time'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x02, // STORE_NAME 'time'
    0x11,0x02, // LOAD_NAME 'time'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x34,0x01, // CALL_FUNCTION 1
    0x11,0x02, // LOAD_NAME 'time'
    0x18,0x07, // STORE_ATTR 'min'
    0x11,0x02, // LOAD_NAME 'time'
    0x97, // LOAD_CONST_SMALL_INT 23
    0x22,0x3b, // LOAD_CONST_SMALL_INT 59
    0x22,0x3b, // LOAD_CONST_SMALL_INT 59
    0x22,0xbd,0x84,0x3f, // LOAD_CONST_SMALL_INT 999999
    0x34,0x04, // CALL_FUNCTION 4
    0x11,0x02, // LOAD_NAME 'time'
    0x18,0x0c, // STORE_ATTR 'max'
    0x11,0x05, // LOAD_NAME 'timedelta'
    0x13,0x0d, // LOAD_ATTR 'resolution'
    0x11,0x02, // LOAD_NAME 'time'
    0x18,0x0d, // STORE_ATTR 'resolution'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x0f, // MAKE_FUNCTION 15
    0x10,0x12, // LOAD_CONST_STRING 'datetime'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x12, // STORE_NAME 'datetime'
    0x11,0x12, // LOAD_NAME 'datetime'
    0x11,0x73, // LOAD_NAME '_gmtime'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x34,0x01, // CALL_FUNCTION 1
    0x51, // LOAD_CONST_NONE
    0x86, // LOAD_CONST_SMALL_INT 6
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x10,0x0e, // LOAD_CONST_STRING 'tzinfo'
    0x11,0x0f, // LOAD_NAME 'timezone'
    0x13,0x10, // LOAD_ATTR 'utc'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x82,0x01, // CALL_FUNCTION_VAR_KW 257
    0x11,0x12, // LOAD_NAME 'datetime'
    0x18,0x13, // STORE_ATTR 'EPOCH'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime__leap
static const byte fun_data_datetime__leap[30] = {
    0x11,0x08, // prelude
    0x14,0x78, // names: _leap, y
    0x80,0x0a, // code info
    0xb0, // LOAD_FAST 0
    0x84, // LOAD_CONST_SMALL_INT 4
    0xf8, // BINARY_OP 33 __mod__
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x46,0x10, // JUMP_IF_FALSE_OR_POP 16
    0xb0, // LOAD_FAST 0
    0x22,0x80,0x64, // LOAD_CONST_SMALL_INT 100
    0xf8, // BINARY_OP 33 __mod__
    0x80, // LOAD_CONST_SMALL_INT 0
    0xdc, // BINARY_OP 5 __ne__
    0x45,0x07, // JUMP_IF_TRUE_OR_POP 7
    0xb0, // LOAD_FAST 0
    0x22,0x83,0x10, // LOAD_CONST_SMALL_INT 400
    0xf8, // BINARY_OP 33 __mod__
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime__leap = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__leap,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 30,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 20,
        .line_info = fun_data_datetime__leap + 4,
        .line_info_top = fun_data_datetime__leap + 6,
        .opcodes = fun_data_datetime__leap + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime__leap fun_data_datetime__leap[0]
#endif

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime__dim
static const byte fun_data_datetime__dim[28] = {
    0x1a,0x0e, // prelude
    0x15,0x78,0x79, // names: _dim, y, m
    0x80,0x0f,0x2c,0x22, // code info
    0xb1, // LOAD_FAST 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0x12,0x14, // LOAD_GLOBAL '_leap'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x9d, // LOAD_CONST_SMALL_INT 29
    0x63, // RETURN_VALUE
    0x23,0x00, // LOAD_CONST_OBJ 0
    0xb1, // LOAD_FAST 1
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime__dim = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__dim,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 28,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 21,
        .line_info = fun_data_datetime__dim + 5,
        .line_info_top = fun_data_datetime__dim + 9,
        .opcodes = fun_data_datetime__dim + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime__dim fun_data_datetime__dim[0]
#endif

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime__dbm
static const byte fun_data_datetime__dbm[23] = {
    0x22,0x0a, // prelude
    0x16,0x78,0x79, // names: _dbm, y, m
    0x80,0x16, // code info
    0x23,0x01, // LOAD_CONST_OBJ 1
    0xb1, // LOAD_FAST 1
    0x55, // LOAD_SUBSCR
    0xb1, // LOAD_FAST 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0xd8, // BINARY_OP 1 __gt__
    0x46,0x05, // JUMP_IF_FALSE_OR_POP 5
    0x12,0x14, // LOAD_GLOBAL '_leap'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0xf2, // BINARY_OP 27 __add__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime__dbm = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__dbm,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 22,
        .line_info = fun_data_datetime__dbm + 5,
        .line_info_top = fun_data_datetime__dbm + 7,
        .opcodes = fun_data_datetime__dbm + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime__dbm fun_data_datetime__dbm[0]
#endif

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime__o2ymd
static const byte fun_data_datetime__o2ymd[159] = {
    0x59,0x26, // prelude
    0x17,0x7a, // names: _o2ymd, n
    0x80,0x1b,0x24,0x2d,0x28,0x2d,0x2c,0x2c,0x2e,0x2a,0x28,0x27,0x27,0x25,0x24,0x29,0x24, // code info
    0xb0, // LOAD_FAST 0
    0x81, // LOAD_CONST_SMALL_INT 1
    0xe6, // BINARY_OP 15 __isub__
    0xc0, // STORE_FAST 0
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb0, // LOAD_FAST 0
    0x22,0x88,0xf5,0x31, // LOAD_CONST_SMALL_INT 146097
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc1, // STORE_FAST 1
    0xc0, // STORE_FAST 0
    0xb1, // LOAD_FAST 1
    0x22,0x83,0x10, // LOAD_CONST_SMALL_INT 400
    0xf4, // BINARY_OP 29 __mul__
    0x81, // LOAD_CONST_SMALL_INT 1
    0xf2, // BINARY_OP 27 __add__
    0xc2, // STORE_FAST 2
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb0, // LOAD_FAST 0
    0x22,0x82,0x9d,0x2c, // LOAD_CONST_SMALL_INT 36524
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc3, // STORE_FAST 3
    0xc0, // STORE_FAST 0
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb0, // LOAD_FAST 0
    0x22,0x8b,0x35, // LOAD_CONST_SMALL_INT 1461
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc4, // STORE_FAST 4
    0xc0, // STORE_FAST 0
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb0, // LOAD_FAST 0
    0x22,0x82,0x6d, // LOAD_CONST_SMALL_INT 365
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc5, // STORE_FAST 5
    0xc0, // STORE_FAST 0
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0x22,0x80,0x64, // LOAD_CONST_SMALL_INT 100
    0xf4, // BINARY_OP 29 __mul__
    0xb4, // LOAD_FAST 4
    0x84, // LOAD_CONST_SMALL_INT 4
    0xf4, // BINARY_OP 29 __mul__
    0xf2, // BINARY_OP 27 __add__
    0xb5, // LOAD_FAST 5
    0xf2, // BINARY_OP 27 __add__
    0xe5, // BINARY_OP 14 __iadd__
    0xc2, // STORE_FAST 2
    0xb5, // LOAD_FAST 5
    0x84, // LOAD_CONST_SMALL_INT 4
    0xd9, // BINARY_OP 2 __eq__
    0x43,0x45, // POP_JUMP_IF_TRUE 5
    0xb3, // LOAD_FAST 3
    0x84, // LOAD_CONST_SMALL_INT 4
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb2, // LOAD_FAST 2
    0x81, // LOAD_CONST_SMALL_INT 1
    0xf3, // BINARY_OP 28 __sub__
    0x8c, // LOAD_CONST_SMALL_INT 12
    0x9f, // LOAD_CONST_SMALL_INT 31
    0x2a,0x03, // BUILD_TUPLE 3
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x22,0x32, // LOAD_CONST_SMALL_INT 50
    0xf2, // BINARY_OP 27 __add__
    0x85, // LOAD_CONST_SMALL_INT 5
    0xf1, // BINARY_OP 26 __rshift__
    0xc6, // STORE_FAST 6
    0x12,0x16, // LOAD_GLOBAL '_dbm'
    0xb2, // LOAD_FAST 2
    0xb6, // LOAD_FAST 6
    0x34,0x02, // CALL_FUNCTION 2
    0xc7, // STORE_FAST 7
    0xb7, // LOAD_FAST 7
    0xb0, // LOAD_FAST 0
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x4d, // POP_JUMP_IF_FALSE 13
    0xb6, // LOAD_FAST 6
    0x81, // LOAD_CONST_SMALL_INT 1
    0xe6, // BINARY_OP 15 __isub__
    0xc6, // STORE_FAST 6
    0xb7, // LOAD_FAST 7
    0x12,0x15, // LOAD_GLOBAL '_dim'
    0xb2, // LOAD_FAST 2
    0xb6, // LOAD_FAST 6
    0x34,0x02, // CALL_FUNCTION 2
    0xe6, // BINARY_OP 15 __isub__
    0xc7, // STORE_FAST 7
    0xb0, // LOAD_FAST 0
    0xb7, // LOAD_FAST 7
    0xe6, // BINARY_OP 15 __isub__
    0xc0, // STORE_FAST 0
    0xb2, // LOAD_FAST 2
    0xb6, // LOAD_FAST 6
    0xb0, // LOAD_FAST 0
    0x81, // LOAD_CONST_SMALL_INT 1
    0xf2, // BINARY_OP 27 __add__
    0x2a,0x03, // BUILD_TUPLE 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime__o2ymd = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__o2ymd,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 159,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 12,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 23,
        .line_info = fun_data_datetime__o2ymd + 4,
        .line_info_top = fun_data_datetime__o2ymd + 21,
        .opcodes = fun_data_datetime__o2ymd + 21,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime__o2ymd fun_data_datetime__o2ymd[0]
#endif

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime_timedelta
static const byte fun_data_datetime_timedelta[196] = {
    0x30,0x52, // prelude
    0x05, // names: timedelta
    0x88,0x32,0x6e,0x60,0x64,0x64,0x68,0x20,0x68,0x20,0x68,0x20,0x84,0x07,0x64,0x64,0x64,0x64,0x64,0x45,0x64,0x60,0x64,0x60,0x64,0x64,0x20,0x64,0x64,0x64,0x64,0x64,0x64,0x64,0x64,0x40,0x64,0x88,0x29,0x64, // code info
    0x11,0x7c, // LOAD_NAME '__name__'
    0x16,0x7d, // STORE_NAME '__module__'
    0x10,0x05, // LOAD_CONST_STRING 'timedelta'
    0x16,0x7e, // STORE_NAME '__qualname__'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x2a,0x07, // BUILD_TUPLE 7
    0x53, // LOAD_NULL
    0x33,0x00, // MAKE_FUNCTION_DEFARGS 0
    0x16,0x2a, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x2c, // STORE_NAME '__repr__'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x2e, // STORE_NAME 'total_seconds'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x03, // MAKE_FUNCTION 3
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x06, // STORE_NAME 'days'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x04, // MAKE_FUNCTION 4
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x0a, // STORE_NAME 'seconds'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x05, // MAKE_FUNCTION 5
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x0b, // STORE_NAME 'microseconds'
    0x32,0x06, // MAKE_FUNCTION 6
    0x16,0x30, // STORE_NAME '__add__'
    0x32,0x07, // MAKE_FUNCTION 7
    0x16,0x31, // STORE_NAME '__sub__'
    0x32,0x08, // MAKE_FUNCTION 8
    0x16,0x32, // STORE_NAME '__neg__'
    0x32,0x09, // MAKE_FUNCTION 9
    0x16,0x33, // STORE_NAME '__pos__'
    0x32,0x0a, // MAKE_FUNCTION 10
    0x16,0x34, // STORE_NAME '__abs__'
    0x32,0x0b, // MAKE_FUNCTION 11
    0x16,0x35, // STORE_NAME '__mul__'
    0x11,0x35, // LOAD_NAME '__mul__'
    0x16,0x81,0x00, // STORE_NAME '__rmul__'
    0x32,0x0c, // MAKE_FUNCTION 12
    0x16,0x36, // STORE_NAME '__truediv__'
    0x32,0x0d, // MAKE_FUNCTION 13
    0x16,0x37, // STORE_NAME '__floordiv__'
    0x32,0x0e, // MAKE_FUNCTION 14
    0x16,0x38, // STORE_NAME '__mod__'
    0x32,0x0f, // MAKE_FUNCTION 15
    0x16,0x39, // STORE_NAME '__divmod__'
    0x32,0x10, // MAKE_FUNCTION 16
    0x16,0x3a, // STORE_NAME '__eq__'
    0x32,0x11, // MAKE_FUNCTION 17
    0x16,0x3b, // STORE_NAME '__le__'
    0x32,0x12, // MAKE_FUNCTION 18
    0x16,0x3c, // STORE_NAME '__lt__'
    0x32,0x13, // MAKE_FUNCTION 19
    0x16,0x3d, // STORE_NAME '__ge__'
    0x32,0x14, // MAKE_FUNCTION 20
    0x16,0x3e, // STORE_NAME '__gt__'
    0x32,0x15, // MAKE_FUNCTION 21
    0x16,0x3f, // STORE_NAME '__bool__'
    0x32,0x16, // MAKE_FUNCTION 22
    0x16,0x40, // STORE_NAME '__str__'
    0x32,0x17, // MAKE_FUNCTION 23
    0x16,0x41, // STORE_NAME '__hash__'
    0x32,0x18, // MAKE_FUNCTION 24
    0x16,0x26, // STORE_NAME 'isoformat'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x19, // MAKE_FUNCTION_DEFARGS 25
    0x16,0x24, // STORE_NAME '_fmt'
    0x32,0x1a, // MAKE_FUNCTION 26
    0x16,0x4a, // STORE_NAME 'tuple'
    0x32,0x1b, // MAKE_FUNCTION 27
    0x16,0x2f, // STORE_NAME '_tuple'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___init__
static const byte fun_data_datetime_timedelta___init__[63] = {
    0xd8,0x81,0x85,0x01,0x1e, // prelude
    0x2a,0x81,0x0d,0x06,0x0a,0x0b,0x81,0x0e,0x09,0x08,0x81,0x0f, // names: __init__, self, days, seconds, microseconds, milliseconds, minutes, hours, weeks
    0x80,0x35,0x34, // code info
    0xb7, // LOAD_FAST 7
    0x87, // LOAD_CONST_SMALL_INT 7
    0xf4, // BINARY_OP 29 __mul__
    0xb1, // LOAD_FAST 1
    0xf2, // BINARY_OP 27 __add__
    0x98, // LOAD_CONST_SMALL_INT 24
    0xf4, // BINARY_OP 29 __mul__
    0xb6, // LOAD_FAST 6
    0xf2, // BINARY_OP 27 __add__
    0x22,0x3c, // LOAD_CONST_SMALL_INT 60
    0xf4, // BINARY_OP 29 __mul__
    0xb5, // LOAD_FAST 5
    0xf2, // BINARY_OP 27 __add__
    0x22,0x3c, // LOAD_CONST_SMALL_INT 60
    0xf4, // BINARY_OP 29 __mul__
    0xb2, // LOAD_FAST 2
    0xf2, // BINARY_OP 27 __add__
    0xc8, // STORE_FAST 8
    0x12,0x81,0x10, // LOAD_GLOBAL 'round'
    0xb8, // LOAD_FAST 8
    0x22,0x87,0x68, // LOAD_CONST_SMALL_INT 1000
    0xf4, // BINARY_OP 29 __mul__
    0xb4, // LOAD_FAST 4
    0xf2, // BINARY_OP 27 __add__
    0x22,0x87,0x68, // LOAD_CONST_SMALL_INT 1000
    0xf4, // BINARY_OP 29 __mul__
    0xb3, // LOAD_FAST 3
    0xf2, // BINARY_OP 27 __add__
    0x34,0x01, // CALL_FUNCTION 1
    0xb0, // LOAD_FAST 0
    0x18,0x2b, // STORE_ATTR '_us'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 63,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 12,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 8,
        .n_kwonly_args = 0,
        .n_def_pos_args = 7,
        .qstr_block_name_idx = 42,
        .line_info = fun_data_datetime_timedelta___init__ + 17,
        .line_info_top = fun_data_datetime_timedelta___init__ + 20,
        .opcodes = fun_data_datetime_timedelta___init__ + 20,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___init__ fun_data_datetime_timedelta___init__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___repr__
static const byte fun_data_datetime_timedelta___repr__[17] = {
    0x19,0x0a, // prelude
    0x2c,0x81,0x0d, // names: __repr__, self
    0x80,0x39, // code info
    0x23,0x05, // LOAD_CONST_OBJ 5
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___repr__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___repr__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 44,
        .line_info = fun_data_datetime_timedelta___repr__ + 5,
        .line_info_top = fun_data_datetime_timedelta___repr__ + 7,
        .opcodes = fun_data_datetime_timedelta___repr__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___repr__ fun_data_datetime_timedelta___repr__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta_total_seconds
static const byte fun_data_datetime_timedelta_total_seconds[16] = {
    0x11,0x0a, // prelude
    0x2e,0x81,0x0d, // names: total_seconds, self
    0x80,0x3c, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0x22,0xbd,0x84,0x40, // LOAD_CONST_SMALL_INT 1000000
    0xf7, // BINARY_OP 32 __truediv__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta_total_seconds = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta_total_seconds,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 46,
        .line_info = fun_data_datetime_timedelta_total_seconds + 5,
        .line_info_top = fun_data_datetime_timedelta_total_seconds + 7,
        .opcodes = fun_data_datetime_timedelta_total_seconds + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta_total_seconds fun_data_datetime_timedelta_total_seconds[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta_days
static const byte fun_data_datetime_timedelta_days[14] = {
    0x19,0x0a, // prelude
    0x06,0x81,0x0d, // names: days, self
    0x80,0x40, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x2f, // LOAD_METHOD '_tuple'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta_days = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta_days,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 6,
        .line_info = fun_data_datetime_timedelta_days + 5,
        .line_info_top = fun_data_datetime_timedelta_days + 7,
        .opcodes = fun_data_datetime_timedelta_days + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta_days fun_data_datetime_timedelta_days[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta_seconds
static const byte fun_data_datetime_timedelta_seconds[16] = {
    0x19,0x0a, // prelude
    0x0a,0x81,0x0d, // names: seconds, self
    0x80,0x44, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x2f, // LOAD_METHOD '_tuple'
    0x83, // LOAD_CONST_SMALL_INT 3
    0x36,0x01, // CALL_METHOD 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta_seconds = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta_seconds,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 10,
        .line_info = fun_data_datetime_timedelta_seconds + 5,
        .line_info_top = fun_data_datetime_timedelta_seconds + 7,
        .opcodes = fun_data_datetime_timedelta_seconds + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta_seconds fun_data_datetime_timedelta_seconds[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta_microseconds
static const byte fun_data_datetime_timedelta_microseconds[16] = {
    0x19,0x0a, // prelude
    0x0b,0x81,0x0d, // names: microseconds, self
    0x80,0x48, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x2f, // LOAD_METHOD '_tuple'
    0x83, // LOAD_CONST_SMALL_INT 3
    0x36,0x01, // CALL_METHOD 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta_microseconds = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta_microseconds,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 11,
        .line_info = fun_data_datetime_timedelta_microseconds + 5,
        .line_info_top = fun_data_datetime_timedelta_microseconds + 7,
        .opcodes = fun_data_datetime_timedelta_microseconds + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta_microseconds fun_data_datetime_timedelta_microseconds[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___add__
static const byte fun_data_datetime_timedelta___add__[45] = {
    0x3a,0x14, // prelude
    0x30,0x81,0x0d,0x81,0x11, // names: __add__, self, other
    0x80,0x4b,0x2a,0x47,0x24, // code info
    0x12,0x81,0x12, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0xb1, // LOAD_FAST 1
    0x14,0x30, // LOAD_METHOD '__add__'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xc2, // STORE_FAST 2
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb2, // LOAD_FAST 2
    0xf2, // BINARY_OP 27 __add__
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___add__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___add__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 45,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 48,
        .line_info = fun_data_datetime_timedelta___add__ + 7,
        .line_info_top = fun_data_datetime_timedelta___add__ + 12,
        .opcodes = fun_data_datetime_timedelta___add__ + 12,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___add__ fun_data_datetime_timedelta___add__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___sub__
static const byte fun_data_datetime_timedelta___sub__[23] = {
    0x32,0x0e, // prelude
    0x31,0x81,0x0d,0x81,0x11, // names: __sub__, self, other
    0x80,0x52, // code info
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xf3, // BINARY_OP 28 __sub__
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___sub__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___sub__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 49,
        .line_info = fun_data_datetime_timedelta___sub__ + 7,
        .line_info_top = fun_data_datetime_timedelta___sub__ + 9,
        .opcodes = fun_data_datetime_timedelta___sub__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___sub__ fun_data_datetime_timedelta___sub__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___neg__
static const byte fun_data_datetime_timedelta___neg__[18] = {
    0x21,0x0a, // prelude
    0x32,0x81,0x0d, // names: __neg__, self
    0x80,0x55, // code info
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xd1, // UNARY_OP 1 __neg__
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___neg__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___neg__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 50,
        .line_info = fun_data_datetime_timedelta___neg__ + 5,
        .line_info_top = fun_data_datetime_timedelta___neg__ + 7,
        .opcodes = fun_data_datetime_timedelta___neg__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___neg__ fun_data_datetime_timedelta___neg__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___pos__
static const byte fun_data_datetime_timedelta___pos__[9] = {
    0x09,0x0a, // prelude
    0x33,0x81,0x0d, // names: __pos__, self
    0x80,0x58, // code info
    0xb0, // LOAD_FAST 0
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___pos__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___pos__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 9,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 51,
        .line_info = fun_data_datetime_timedelta___pos__ + 5,
        .line_info_top = fun_data_datetime_timedelta___pos__ + 7,
        .opcodes = fun_data_datetime_timedelta___pos__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___pos__ fun_data_datetime_timedelta___pos__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___abs__
static const byte fun_data_datetime_timedelta___abs__[19] = {
    0x11,0x0a, // prelude
    0x34,0x81,0x0d, // names: __abs__, self
    0x80,0x5b, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0xb0, // LOAD_FAST 0
    0xd1, // UNARY_OP 1 __neg__
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___abs__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___abs__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 19,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 52,
        .line_info = fun_data_datetime_timedelta___abs__ + 5,
        .line_info_top = fun_data_datetime_timedelta___abs__ + 7,
        .opcodes = fun_data_datetime_timedelta___abs__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___abs__ fun_data_datetime_timedelta___abs__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___mul__
static const byte fun_data_datetime_timedelta___mul__[26] = {
    0x3a,0x0e, // prelude
    0x35,0x81,0x0d,0x81,0x11, // names: __mul__, self, other
    0x80,0x5e, // code info
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x12,0x81,0x10, // LOAD_GLOBAL 'round'
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xf4, // BINARY_OP 29 __mul__
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___mul__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___mul__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 26,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 53,
        .line_info = fun_data_datetime_timedelta___mul__ + 7,
        .line_info_top = fun_data_datetime_timedelta___mul__ + 9,
        .opcodes = fun_data_datetime_timedelta___mul__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___mul__ fun_data_datetime_timedelta___mul__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___truediv__
static const byte fun_data_datetime_timedelta___truediv__[48] = {
    0x3a,0x12, // prelude
    0x36,0x81,0x0d,0x81,0x11, // names: __truediv__, self, other
    0x80,0x63,0x2a,0x48, // code info
    0x12,0x81,0x12, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xf7, // BINARY_OP 32 __truediv__
    0x63, // RETURN_VALUE
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x12,0x81,0x10, // LOAD_GLOBAL 'round'
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0xf7, // BINARY_OP 32 __truediv__
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___truediv__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___truediv__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 48,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 54,
        .line_info = fun_data_datetime_timedelta___truediv__ + 7,
        .line_info_top = fun_data_datetime_timedelta___truediv__ + 11,
        .opcodes = fun_data_datetime_timedelta___truediv__ + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___truediv__ fun_data_datetime_timedelta___truediv__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___floordiv__
static const byte fun_data_datetime_timedelta___floordiv__[48] = {
    0x3a,0x12, // prelude
    0x37,0x81,0x0d,0x81,0x11, // names: __floordiv__, self, other
    0x80,0x69,0x2a,0x48, // code info
    0x12,0x81,0x12, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xf6, // BINARY_OP 31 __floordiv__
    0x63, // RETURN_VALUE
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0xf6, // BINARY_OP 31 __floordiv__
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___floordiv__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___floordiv__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 48,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 55,
        .line_info = fun_data_datetime_timedelta___floordiv__ + 7,
        .line_info_top = fun_data_datetime_timedelta___floordiv__ + 11,
        .opcodes = fun_data_datetime_timedelta___floordiv__ + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___floordiv__ fun_data_datetime_timedelta___floordiv__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___mod__
static const byte fun_data_datetime_timedelta___mod__[23] = {
    0x32,0x0e, // prelude
    0x38,0x81,0x0d,0x81,0x11, // names: __mod__, self, other
    0x80,0x6f, // code info
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___mod__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___mod__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 56,
        .line_info = fun_data_datetime_timedelta___mod__ + 7,
        .line_info_top = fun_data_datetime_timedelta___mod__ + 9,
        .opcodes = fun_data_datetime_timedelta___mod__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___mod__ fun_data_datetime_timedelta___mod__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___divmod__
static const byte fun_data_datetime_timedelta___divmod__[35] = {
    0x42,0x10, // prelude
    0x39,0x81,0x0d,0x81,0x11, // names: __divmod__, self, other
    0x80,0x72,0x2e, // code info
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0xb2, // LOAD_FAST 2
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb3, // LOAD_FAST 3
    0x34,0x03, // CALL_FUNCTION 3
    0x2a,0x02, // BUILD_TUPLE 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___divmod__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___divmod__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 35,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 9,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 57,
        .line_info = fun_data_datetime_timedelta___divmod__ + 7,
        .line_info_top = fun_data_datetime_timedelta___divmod__ + 10,
        .opcodes = fun_data_datetime_timedelta___divmod__ + 10,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___divmod__ fun_data_datetime_timedelta___divmod__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___eq__
static const byte fun_data_datetime_timedelta___eq__[17] = {
    0x1a,0x0e, // prelude
    0x3a,0x81,0x0d,0x81,0x11, // names: __eq__, self, other
    0x80,0x76, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xd9, // BINARY_OP 2 __eq__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___eq__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___eq__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 58,
        .line_info = fun_data_datetime_timedelta___eq__ + 7,
        .line_info_top = fun_data_datetime_timedelta___eq__ + 9,
        .opcodes = fun_data_datetime_timedelta___eq__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___eq__ fun_data_datetime_timedelta___eq__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___le__
static const byte fun_data_datetime_timedelta___le__[17] = {
    0x1a,0x0e, // prelude
    0x3b,0x81,0x0d,0x81,0x11, // names: __le__, self, other
    0x80,0x79, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xda, // BINARY_OP 3 __le__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___le__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___le__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 59,
        .line_info = fun_data_datetime_timedelta___le__ + 7,
        .line_info_top = fun_data_datetime_timedelta___le__ + 9,
        .opcodes = fun_data_datetime_timedelta___le__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___le__ fun_data_datetime_timedelta___le__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___lt__
static const byte fun_data_datetime_timedelta___lt__[17] = {
    0x1a,0x0e, // prelude
    0x3c,0x81,0x0d,0x81,0x11, // names: __lt__, self, other
    0x80,0x7c, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xd7, // BINARY_OP 0 __lt__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___lt__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___lt__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 60,
        .line_info = fun_data_datetime_timedelta___lt__ + 7,
        .line_info_top = fun_data_datetime_timedelta___lt__ + 9,
        .opcodes = fun_data_datetime_timedelta___lt__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___lt__ fun_data_datetime_timedelta___lt__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___ge__
static const byte fun_data_datetime_timedelta___ge__[17] = {
    0x1a,0x0e, // prelude
    0x3d,0x81,0x0d,0x81,0x11, // names: __ge__, self, other
    0x80,0x7f, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xdb, // BINARY_OP 4 __ge__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___ge__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___ge__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 61,
        .line_info = fun_data_datetime_timedelta___ge__ + 7,
        .line_info_top = fun_data_datetime_timedelta___ge__ + 9,
        .opcodes = fun_data_datetime_timedelta___ge__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___ge__ fun_data_datetime_timedelta___ge__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___gt__
static const byte fun_data_datetime_timedelta___gt__[17] = {
    0x1a,0x0e, // prelude
    0x3e,0x81,0x0d,0x81,0x11, // names: __gt__, self, other
    0x80,0x82, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xd8, // BINARY_OP 1 __gt__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___gt__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___gt__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 62,
        .line_info = fun_data_datetime_timedelta___gt__ + 7,
        .line_info_top = fun_data_datetime_timedelta___gt__ + 9,
        .opcodes = fun_data_datetime_timedelta___gt__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___gt__ fun_data_datetime_timedelta___gt__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___bool__
static const byte fun_data_datetime_timedelta___bool__[13] = {
    0x11,0x0a, // prelude
    0x3f,0x81,0x0d, // names: __bool__, self
    0x80,0x85, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0x80, // LOAD_CONST_SMALL_INT 0
    0xdc, // BINARY_OP 5 __ne__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___bool__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___bool__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 13,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 63,
        .line_info = fun_data_datetime_timedelta___bool__ + 5,
        .line_info_top = fun_data_datetime_timedelta___bool__ + 7,
        .opcodes = fun_data_datetime_timedelta___bool__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___bool__ fun_data_datetime_timedelta___bool__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___str__
static const byte fun_data_datetime_timedelta___str__[16] = {
    0x19,0x0a, // prelude
    0x40,0x81,0x0d, // names: __str__, self
    0x80,0x88, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x24, // LOAD_METHOD '_fmt'
    0x22,0x80,0x40, // LOAD_CONST_SMALL_INT 64
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___str__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___str__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 64,
        .line_info = fun_data_datetime_timedelta___str__ + 5,
        .line_info_top = fun_data_datetime_timedelta___str__ + 7,
        .opcodes = fun_data_datetime_timedelta___str__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___str__ fun_data_datetime_timedelta___str__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta___hash__
static const byte fun_data_datetime_timedelta___hash__[34] = {
    0x19,0x0e, // prelude
    0x41,0x81,0x0d, // names: __hash__, self
    0x80,0x8b,0x2a,0x2b, // code info
    0x12,0x81,0x13, // LOAD_GLOBAL 'hasattr'
    0xb0, // LOAD_FAST 0
    0x10,0x42, // LOAD_CONST_STRING '_hash'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x4b, // POP_JUMP_IF_TRUE 11
    0x12,0x81,0x14, // LOAD_GLOBAL 'hash'
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0x34,0x01, // CALL_FUNCTION 1
    0xb0, // LOAD_FAST 0
    0x18,0x42, // STORE_ATTR '_hash'
    0xb0, // LOAD_FAST 0
    0x13,0x42, // LOAD_ATTR '_hash'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta___hash__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta___hash__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 34,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 65,
        .line_info = fun_data_datetime_timedelta___hash__ + 5,
        .line_info_top = fun_data_datetime_timedelta___hash__ + 9,
        .opcodes = fun_data_datetime_timedelta___hash__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta___hash__ fun_data_datetime_timedelta___hash__[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta_isoformat
static const byte fun_data_datetime_timedelta_isoformat[14] = {
    0x19,0x0a, // prelude
    0x26,0x81,0x0d, // names: isoformat, self
    0x80,0x90, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x24, // LOAD_METHOD '_fmt'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta_isoformat = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta_isoformat,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 38,
        .line_info = fun_data_datetime_timedelta_isoformat + 5,
        .line_info_top = fun_data_datetime_timedelta_isoformat + 7,
        .opcodes = fun_data_datetime_timedelta_isoformat + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta_isoformat fun_data_datetime_timedelta_isoformat[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta__fmt
static const byte fun_data_datetime_timedelta__fmt[300] = {
    0x92,0x11,0x56, // prelude
    0x24,0x81,0x0d,0x81,0x15, // names: _fmt, self, spec
    0x80,0x93,0x27,0x22,0x45,0x23,0x23,0x2d,0x2c,0x23,0x27,0x26,0x49,0x28,0x25,0x25,0x24,0x25,0x25,0x25,0x23,0x23,0x23,0x2c,0x2c,0x23,0x25,0x2b,0x29,0x2b,0x29,0x2a,0x28,0x2a,0x28,0x2a,0x28,0x2a, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0x80, // LOAD_CONST_SMALL_INT 0
    0xdb, // BINARY_OP 4 __ge__
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0xb0, // LOAD_FAST 0
    0xc2, // STORE_FAST 2
    0x10,0x1e, // LOAD_CONST_STRING ''
    0xc3, // STORE_FAST 3
    0x42,0x46, // JUMP 6
    0xb0, // LOAD_FAST 0
    0xd1, // UNARY_OP 1 __neg__
    0xc2, // STORE_FAST 2
    0x10,0x1a, // LOAD_CONST_STRING '-'
    0xc3, // STORE_FAST 3
    0xb2, // LOAD_FAST 2
    0x14,0x2f, // LOAD_METHOD '_tuple'
    0x85, // LOAD_CONST_SMALL_INT 5
    0x36,0x01, // CALL_METHOD 1
    0x30,0x05, // UNPACK_SEQUENCE 5
    0xc4, // STORE_FAST 4
    0xc5, // STORE_FAST 5
    0xc6, // STORE_FAST 6
    0xc7, // STORE_FAST 7
    0xc8, // STORE_FAST 8
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb8, // LOAD_FAST 8
    0x22,0x87,0x68, // LOAD_CONST_SMALL_INT 1000
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc9, // STORE_FAST 9
    0xc8, // STORE_FAST 8
    0x10,0x1e, // LOAD_CONST_STRING ''
    0xca, // STORE_FAST 10
    0xb1, // LOAD_FAST 1
    0x22,0x80,0x40, // LOAD_CONST_SMALL_INT 64
    0xef, // BINARY_OP 24 __and__
    0x44,0x4f, // POP_JUMP_IF_FALSE 15
    0xb1, // LOAD_FAST 1
    0x22,0xff,0x3f, // LOAD_CONST_SMALL_INT -65
    0xe2, // BINARY_OP 11 __iand__
    0xc1, // STORE_FAST 1
    0x12,0x81,0x16, // LOAD_GLOBAL 'str'
    0xb5, // LOAD_FAST 5
    0x34,0x01, // CALL_FUNCTION 1
    0xcb, // STORE_FAST 11
    0x42,0x48, // JUMP 8
    0x10,0x43, // LOAD_CONST_STRING '{:02d}'
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb5, // LOAD_FAST 5
    0x36,0x01, // CALL_METHOD 1
    0xcb, // STORE_FAST 11
    0xb1, // LOAD_FAST 1
    0xa0, // LOAD_CONST_SMALL_INT 32
    0xef, // BINARY_OP 24 __and__
    0x44,0x4e, // POP_JUMP_IF_FALSE 14
    0xb1, // LOAD_FAST 1
    0x22,0x5f, // LOAD_CONST_SMALL_INT -33
    0xe2, // BINARY_OP 11 __iand__
    0xc1, // STORE_FAST 1
    0xb1, // LOAD_FAST 1
    0x90, // LOAD_CONST_SMALL_INT 16
    0xe0, // BINARY_OP 9 __ior__
    0xc1, // STORE_FAST 1
    0xba, // LOAD_FAST 10
    0x10,0x44, // LOAD_CONST_STRING 'UTC'
    0xe5, // BINARY_OP 14 __iadd__
    0xca, // STORE_FAST 10
    0xb1, // LOAD_FAST 1
    0x90, // LOAD_CONST_SMALL_INT 16
    0xef, // BINARY_OP 24 __and__
    0x44,0x4b, // POP_JUMP_IF_FALSE 11
    0xb1, // LOAD_FAST 1
    0x22,0x6f, // LOAD_CONST_SMALL_INT -17
    0xe2, // BINARY_OP 11 __iand__
    0xc1, // STORE_FAST 1
    0xb3, // LOAD_FAST 3
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0x10,0x21, // LOAD_CONST_STRING '+'
    0xc3, // STORE_FAST 3
    0xb4, // LOAD_FAST 4
    0x44,0x5b, // POP_JUMP_IF_FALSE 27
    0xb4, // LOAD_FAST 4
    0x81, // LOAD_CONST_SMALL_INT 1
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x10,0x45, // LOAD_CONST_STRING 's'
    0x42,0x42, // JUMP 2
    0x10,0x1e, // LOAD_CONST_STRING ''
    0xcc, // STORE_FAST 12
    0xba, // LOAD_FAST 10
    0x23,0x06, // LOAD_CONST_OBJ 6
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0xbc, // LOAD_FAST 12
    0x36,0x03, // CALL_METHOD 3
    0xe5, // BINARY_OP 14 __iadd__
    0xca, // STORE_FAST 10
    0x10,0x1e, // LOAD_CONST_STRING ''
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x4b, // POP_JUMP_IF_FALSE 11
    0xb9, // LOAD_FAST 9
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0xb8, // LOAD_FAST 8
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x85, // LOAD_CONST_SMALL_INT 5
    0x42,0x41, // JUMP 1
    0x83, // LOAD_CONST_SMALL_INT 3
    0xc1, // STORE_FAST 1
    0xb1, // LOAD_FAST 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0xdb, // BINARY_OP 4 __ge__
    0x43,0x44, // POP_JUMP_IF_TRUE 4
    0xb5, // LOAD_FAST 5
    0x44,0xd4,0x80, // POP_JUMP_IF_FALSE 84
    0xba, // LOAD_FAST 10
    0x10,0x46, // LOAD_CONST_STRING '{}{}'
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb3, // LOAD_FAST 3
    0xbb, // LOAD_FAST 11
    0x36,0x02, // CALL_METHOD 2
    0xe5, // BINARY_OP 14 __iadd__
    0xca, // STORE_FAST 10
    0xb1, // LOAD_FAST 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0xdb, // BINARY_OP 4 __ge__
    0x43,0x44, // POP_JUMP_IF_TRUE 4
    0xb6, // LOAD_FAST 6
    0x44,0xc0,0x80, // POP_JUMP_IF_FALSE 64
    0xba, // LOAD_FAST 10
    0x10,0x47, // LOAD_CONST_STRING ':{:02d}'
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb6, // LOAD_FAST 6
    0x36,0x01, // CALL_METHOD 1
    0xe5, // BINARY_OP 14 __iadd__
    0xca, // STORE_FAST 10
    0xb1, // LOAD_FAST 1
    0x83, // LOAD_CONST_SMALL_INT 3
    0xdb, // BINARY_OP 4 __ge__
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0xb7, // LOAD_FAST 7
    0x44,0x6e, // POP_JUMP_IF_FALSE 46
    0xba, // LOAD_FAST 10
    0x10,0x47, // LOAD_CONST_STRING ':{:02d}'
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb7, // LOAD_FAST 7
    0x36,0x01, // CALL_METHOD 1
    0xe5, // BINARY_OP 14 __iadd__
    0xca, // STORE_FAST 10
    0xb1, // LOAD_FAST 1
    0x84, // LOAD_CONST_SMALL_INT 4
    0xdb, // BINARY_OP 4 __ge__
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0xb9, // LOAD_FAST 9
    0x44,0x5c, // POP_JUMP_IF_FALSE 28
    0xba, // LOAD_FAST 10
    0x10,0x48, // LOAD_CONST_STRING '.{:03d}'
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb9, // LOAD_FAST 9
    0x36,0x01, // CALL_METHOD 1
    0xe5, // BINARY_OP 14 __iadd__
    0xca, // STORE_FAST 10
    0xb1, // LOAD_FAST 1
    0x85, // LOAD_CONST_SMALL_INT 5
    0xdb, // BINARY_OP 4 __ge__
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0xb8, // LOAD_FAST 8
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0xba, // LOAD_FAST 10
    0x10,0x49, // LOAD_CONST_STRING '{:03d}'
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb8, // LOAD_FAST 8
    0x36,0x01, // CALL_METHOD 1
    0xe5, // BINARY_OP 14 __iadd__
    0xca, // STORE_FAST 10
    0xba, // LOAD_FAST 10
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta__fmt = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta__fmt,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 300,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 19,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 36,
        .line_info = fun_data_datetime_timedelta__fmt + 8,
        .line_info_top = fun_data_datetime_timedelta__fmt + 46,
        .opcodes = fun_data_datetime_timedelta__fmt + 46,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta__fmt fun_data_datetime_timedelta__fmt[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta_tuple
static const byte fun_data_datetime_timedelta_tuple[14] = {
    0x19,0x0a, // prelude
    0x4a,0x81,0x0d, // names: tuple, self
    0x80,0xbc, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x2f, // LOAD_METHOD '_tuple'
    0x85, // LOAD_CONST_SMALL_INT 5
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta_tuple = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta_tuple,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 74,
        .line_info = fun_data_datetime_timedelta_tuple + 5,
        .line_info_top = fun_data_datetime_timedelta_tuple + 7,
        .opcodes = fun_data_datetime_timedelta_tuple + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta_tuple fun_data_datetime_timedelta_tuple[0]
#endif

// child of datetime_timedelta
// frozen bytecode for file datetime.py, scope datetime_timedelta__tuple
static const byte fun_data_datetime_timedelta__tuple[91] = {
    0x5a,0x1c, // prelude
    0x2f,0x81,0x0d,0x7a, // names: _tuple, self, n
    0x80,0xbf,0x2d,0x25,0x22,0x2d,0x25,0x26,0x2c,0x2b, // code info
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0x23,0x03, // LOAD_CONST_OBJ 3
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb2, // LOAD_FAST 2
    0x63, // RETURN_VALUE
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb3, // LOAD_FAST 3
    0x22,0xbd,0x84,0x40, // LOAD_CONST_SMALL_INT 1000000
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc4, // STORE_FAST 4
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0x83, // LOAD_CONST_SMALL_INT 3
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0xb2, // LOAD_FAST 2
    0xb4, // LOAD_FAST 4
    0xb3, // LOAD_FAST 3
    0x2a,0x03, // BUILD_TUPLE 3
    0x63, // RETURN_VALUE
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb4, // LOAD_FAST 4
    0x22,0x9c,0x10, // LOAD_CONST_SMALL_INT 3600
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc5, // STORE_FAST 5
    0xc4, // STORE_FAST 4
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb4, // LOAD_FAST 4
    0x22,0x3c, // LOAD_CONST_SMALL_INT 60
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc6, // STORE_FAST 6
    0xc4, // STORE_FAST 4
    0xb2, // LOAD_FAST 2
    0xb5, // LOAD_FAST 5
    0xb6, // LOAD_FAST 6
    0xb4, // LOAD_FAST 4
    0xb3, // LOAD_FAST 3
    0x2a,0x05, // BUILD_TUPLE 5
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timedelta__tuple = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta__tuple,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 91,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 12,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 47,
        .line_info = fun_data_datetime_timedelta__tuple + 6,
        .line_info_top = fun_data_datetime_timedelta__tuple + 16,
        .opcodes = fun_data_datetime_timedelta__tuple + 16,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timedelta__tuple fun_data_datetime_timedelta__tuple[0]
#endif

static const mp_raw_code_t *const children_datetime_timedelta[] = {
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___init__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___repr__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta_total_seconds,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta_days,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta_seconds,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta_microseconds,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___add__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___sub__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___neg__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___pos__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___abs__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___mul__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___truediv__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___floordiv__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___mod__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___divmod__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___eq__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___le__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___lt__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___ge__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___gt__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___bool__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___str__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta___hash__,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta_isoformat,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta__fmt,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta_tuple,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta__tuple,
};

static const mp_raw_code_truncated_t proto_fun_datetime_timedelta = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timedelta,
    .children = (void *)&children_datetime_timedelta,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 196,
    .n_children = 28,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 5,
        .line_info = fun_data_datetime_timedelta + 3,
        .line_info_top = fun_data_datetime_timedelta + 43,
        .opcodes = fun_data_datetime_timedelta + 43,
    },
    #endif
    #endif
};

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime_tzinfo
static const byte fun_data_datetime_tzinfo[40] = {
    0x00,0x10, // prelude
    0x0e, // names: tzinfo
    0x88,0xd1,0x64,0x64,0x64,0x84,0x0d, // code info
    0x11,0x7c, // LOAD_NAME '__name__'
    0x16,0x7d, // STORE_NAME '__module__'
    0x10,0x0e, // LOAD_CONST_STRING 'tzinfo'
    0x16,0x7e, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x4b, // STORE_NAME 'tzname'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x4c, // STORE_NAME 'utcoffset'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x4d, // STORE_NAME 'dst'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x4e, // STORE_NAME 'fromutc'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x26, // STORE_NAME 'isoformat'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of datetime_tzinfo
// frozen bytecode for file datetime.py, scope datetime_tzinfo_tzname
static const byte fun_data_datetime_tzinfo_tzname[13] = {
    0x12,0x0e, // prelude
    0x4b,0x81,0x0d,0x81,0x0b, // names: tzname, self, dt
    0x80,0xd2, // code info
    0x12,0x81,0x17, // LOAD_GLOBAL 'NotImplementedError'
    0x65, // RAISE_OBJ
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_tzinfo_tzname = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_tzinfo_tzname,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 13,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 75,
        .line_info = fun_data_datetime_tzinfo_tzname + 7,
        .line_info_top = fun_data_datetime_tzinfo_tzname + 9,
        .opcodes = fun_data_datetime_tzinfo_tzname + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_tzinfo_tzname fun_data_datetime_tzinfo_tzname[0]
#endif

// child of datetime_tzinfo
// frozen bytecode for file datetime.py, scope datetime_tzinfo_utcoffset
static const byte fun_data_datetime_tzinfo_utcoffset[13] = {
    0x12,0x0e, // prelude
    0x4c,0x81,0x0d,0x81,0x0b, // names: utcoffset, self, dt
    0x80,0xd5, // code info
    0x12,0x81,0x17, // LOAD_GLOBAL 'NotImplementedError'
    0x65, // RAISE_OBJ
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_tzinfo_utcoffset = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_tzinfo_utcoffset,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 13,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 76,
        .line_info = fun_data_datetime_tzinfo_utcoffset + 7,
        .line_info_top = fun_data_datetime_tzinfo_utcoffset + 9,
        .opcodes = fun_data_datetime_tzinfo_utcoffset + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_tzinfo_utcoffset fun_data_datetime_tzinfo_utcoffset[0]
#endif

// child of datetime_tzinfo
// frozen bytecode for file datetime.py, scope datetime_tzinfo_dst
static const byte fun_data_datetime_tzinfo_dst[13] = {
    0x12,0x0e, // prelude
    0x4d,0x81,0x0d,0x81,0x0b, // names: dst, self, dt
    0x80,0xd8, // code info
    0x12,0x81,0x17, // LOAD_GLOBAL 'NotImplementedError'
    0x65, // RAISE_OBJ
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_tzinfo_dst = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_tzinfo_dst,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 13,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 77,
        .line_info = fun_data_datetime_tzinfo_dst + 7,
        .line_info_top = fun_data_datetime_tzinfo_dst + 9,
        .opcodes = fun_data_datetime_tzinfo_dst + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_tzinfo_dst fun_data_datetime_tzinfo_dst[0]
#endif

// child of datetime_tzinfo
// frozen bytecode for file datetime.py, scope datetime_tzinfo_fromutc
static const byte fun_data_datetime_tzinfo_fromutc[62] = {
    0x32,0x1e, // prelude
    0x4e,0x81,0x0d,0x81,0x0b, // names: fromutc, self, dt
    0x80,0xdb,0x28,0x64,0x26,0x26,0x24,0x23,0x24,0x26, // code info
    0xb1, // LOAD_FAST 1
    0x13,0x4f, // LOAD_ATTR '_tz'
    0xb0, // LOAD_FAST 0
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0xb1, // LOAD_FAST 1
    0x14,0x4c, // LOAD_METHOD 'utcoffset'
    0x36,0x00, // CALL_METHOD 0
    0xc2, // STORE_FAST 2
    0xb1, // LOAD_FAST 1
    0x14,0x4d, // LOAD_METHOD 'dst'
    0x36,0x00, // CALL_METHOD 0
    0xc3, // STORE_FAST 3
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xf3, // BINARY_OP 28 __sub__
    0xc4, // STORE_FAST 4
    0xb4, // LOAD_FAST 4
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0xb1, // LOAD_FAST 1
    0xb4, // LOAD_FAST 4
    0xe5, // BINARY_OP 14 __iadd__
    0xc1, // STORE_FAST 1
    0xb1, // LOAD_FAST 1
    0x14,0x4d, // LOAD_METHOD 'dst'
    0x36,0x00, // CALL_METHOD 0
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0xb3, // LOAD_FAST 3
    0xf2, // BINARY_OP 27 __add__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_tzinfo_fromutc = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_tzinfo_fromutc,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 62,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 78,
        .line_info = fun_data_datetime_tzinfo_fromutc + 7,
        .line_info_top = fun_data_datetime_tzinfo_fromutc + 17,
        .opcodes = fun_data_datetime_tzinfo_fromutc + 17,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_tzinfo_fromutc fun_data_datetime_tzinfo_fromutc[0]
#endif

// child of datetime_tzinfo
// frozen bytecode for file datetime.py, scope datetime_tzinfo_isoformat
static const byte fun_data_datetime_tzinfo_isoformat[21] = {
    0x22,0x0e, // prelude
    0x26,0x81,0x0d,0x81,0x0b, // names: isoformat, self, dt
    0x80,0xe8, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4c, // LOAD_METHOD 'utcoffset'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x14,0x24, // LOAD_METHOD '_fmt'
    0x92, // LOAD_CONST_SMALL_INT 18
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_tzinfo_isoformat = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_tzinfo_isoformat,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 21,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 38,
        .line_info = fun_data_datetime_tzinfo_isoformat + 7,
        .line_info_top = fun_data_datetime_tzinfo_isoformat + 9,
        .opcodes = fun_data_datetime_tzinfo_isoformat + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_tzinfo_isoformat fun_data_datetime_tzinfo_isoformat[0]
#endif

static const mp_raw_code_t *const children_datetime_tzinfo[] = {
    (const mp_raw_code_t *)&proto_fun_datetime_tzinfo_tzname,
    (const mp_raw_code_t *)&proto_fun_datetime_tzinfo_utcoffset,
    (const mp_raw_code_t *)&proto_fun_datetime_tzinfo_dst,
    (const mp_raw_code_t *)&proto_fun_datetime_tzinfo_fromutc,
    (const mp_raw_code_t *)&proto_fun_datetime_tzinfo_isoformat,
};

static const mp_raw_code_truncated_t proto_fun_datetime_tzinfo = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_tzinfo,
    .children = (void *)&children_datetime_tzinfo,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 40,
    .n_children = 5,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 14,
        .line_info = fun_data_datetime_tzinfo + 3,
        .line_info_top = fun_data_datetime_tzinfo + 10,
        .opcodes = fun_data_datetime_tzinfo + 10,
    },
    #endif
    #endif
};

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime_timezone
static const byte fun_data_datetime_timezone[67] = {
    0x08,0x1e, // prelude
    0x0f, // names: timezone
    0x88,0xec,0x68,0x60,0x64,0x64,0x40,0x64,0x64,0x40,0x64,0x64,0x64,0x40, // code info
    0x11,0x7c, // LOAD_NAME '__name__'
    0x16,0x7d, // STORE_NAME '__module__'
    0x10,0x0f, // LOAD_CONST_STRING 'timezone'
    0x16,0x7e, // STORE_NAME '__qualname__'
    0x51, // LOAD_CONST_NONE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x00, // MAKE_FUNCTION_DEFARGS 0
    0x16,0x2a, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x2c, // STORE_NAME '__repr__'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x3a, // STORE_NAME '__eq__'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x40, // STORE_NAME '__str__'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x41, // STORE_NAME '__hash__'
    0x32,0x05, // MAKE_FUNCTION 5
    0x16,0x4c, // STORE_NAME 'utcoffset'
    0x32,0x06, // MAKE_FUNCTION 6
    0x16,0x4d, // STORE_NAME 'dst'
    0x32,0x07, // MAKE_FUNCTION 7
    0x16,0x4b, // STORE_NAME 'tzname'
    0x32,0x08, // MAKE_FUNCTION 8
    0x16,0x4e, // STORE_NAME 'fromutc'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of datetime_timezone
// frozen bytecode for file datetime.py, scope datetime_timezone___init__
static const byte fun_data_datetime_timezone___init__[42] = {
    0xa3,0x01,0x18, // prelude
    0x2a,0x81,0x0d,0x81,0x18,0x81,0x19, // names: __init__, self, offset, name
    0x80,0xed,0x2d,0x24,0x24, // code info
    0x12,0x81,0x1a, // LOAD_GLOBAL 'abs'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0x34,0x01, // CALL_FUNCTION 1
    0x23,0x03, // LOAD_CONST_OBJ 3
    0xd7, // BINARY_OP 0 __lt__
    0x43,0x44, // POP_JUMP_IF_TRUE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x18,0x50, // STORE_ATTR '_offset'
    0xb2, // LOAD_FAST 2
    0xb0, // LOAD_FAST 0
    0x18,0x51, // STORE_ATTR '_name'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timezone___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timezone___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 42,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 42,
        .line_info = fun_data_datetime_timezone___init__ + 10,
        .line_info_top = fun_data_datetime_timezone___init__ + 15,
        .opcodes = fun_data_datetime_timezone___init__ + 15,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timezone___init__ fun_data_datetime_timezone___init__[0]
#endif

// child of datetime_timezone
// frozen bytecode for file datetime.py, scope datetime_timezone___repr__
static const byte fun_data_datetime_timezone___repr__[30] = {
    0x29,0x0a, // prelude
    0x2c,0x81,0x0d, // names: __repr__, self
    0x80,0xf3, // code info
    0x23,0x07, // LOAD_CONST_OBJ 7
    0x14,0x2d, // LOAD_METHOD 'format'
    0x12,0x81,0x1b, // LOAD_GLOBAL 'repr'
    0xb0, // LOAD_FAST 0
    0x13,0x50, // LOAD_ATTR '_offset'
    0x34,0x01, // CALL_FUNCTION 1
    0x12,0x81,0x1b, // LOAD_GLOBAL 'repr'
    0xb0, // LOAD_FAST 0
    0x13,0x51, // LOAD_ATTR '_name'
    0x34,0x01, // CALL_FUNCTION 1
    0x36,0x02, // CALL_METHOD 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timezone___repr__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timezone___repr__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 30,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 44,
        .line_info = fun_data_datetime_timezone___repr__ + 5,
        .line_info_top = fun_data_datetime_timezone___repr__ + 7,
        .opcodes = fun_data_datetime_timezone___repr__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timezone___repr__ fun_data_datetime_timezone___repr__[0]
#endif

// child of datetime_timezone
// frozen bytecode for file datetime.py, scope datetime_timezone___eq__
static const byte fun_data_datetime_timezone___eq__[33] = {
    0x22,0x12, // prelude
    0x3a,0x81,0x0d,0x81,0x11, // names: __eq__, self, other
    0x80,0xf6,0x2a,0x28, // code info
    0x12,0x81,0x12, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x0f, // LOAD_GLOBAL 'timezone'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb0, // LOAD_FAST 0
    0x13,0x50, // LOAD_ATTR '_offset'
    0xb1, // LOAD_FAST 1
    0x13,0x50, // LOAD_ATTR '_offset'
    0xd9, // BINARY_OP 2 __eq__
    0x63, // RETURN_VALUE
    0x12,0x81,0x1c, // LOAD_GLOBAL 'NotImplemented'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timezone___eq__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timezone___eq__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 33,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 58,
        .line_info = fun_data_datetime_timezone___eq__ + 7,
        .line_info_top = fun_data_datetime_timezone___eq__ + 11,
        .opcodes = fun_data_datetime_timezone___eq__ + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timezone___eq__ fun_data_datetime_timezone___eq__[0]
#endif

// child of datetime_timezone
// frozen bytecode for file datetime.py, scope datetime_timezone___str__
static const byte fun_data_datetime_timezone___str__[14] = {
    0x19,0x0a, // prelude
    0x40,0x81,0x0d, // names: __str__, self
    0x80,0xfb, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4b, // LOAD_METHOD 'tzname'
    0x51, // LOAD_CONST_NONE
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timezone___str__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timezone___str__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 64,
        .line_info = fun_data_datetime_timezone___str__ + 5,
        .line_info_top = fun_data_datetime_timezone___str__ + 7,
        .opcodes = fun_data_datetime_timezone___str__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timezone___str__ fun_data_datetime_timezone___str__[0]
#endif

// child of datetime_timezone
// frozen bytecode for file datetime.py, scope datetime_timezone___hash__
static const byte fun_data_datetime_timezone___hash__[39] = {
    0x19,0x0e, // prelude
    0x41,0x81,0x0d, // names: __hash__, self
    0x80,0xfe,0x2a,0x30, // code info
    0x12,0x81,0x13, // LOAD_GLOBAL 'hasattr'
    0xb0, // LOAD_FAST 0
    0x10,0x42, // LOAD_CONST_STRING '_hash'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x50, // POP_JUMP_IF_TRUE 16
    0x12,0x81,0x14, // LOAD_GLOBAL 'hash'
    0xb0, // LOAD_FAST 0
    0x13,0x50, // LOAD_ATTR '_offset'
    0xb0, // LOAD_FAST 0
    0x13,0x51, // LOAD_ATTR '_name'
    0x2a,0x02, // BUILD_TUPLE 2
    0x34,0x01, // CALL_FUNCTION 1
    0xb0, // LOAD_FAST 0
    0x18,0x42, // STORE_ATTR '_hash'
    0xb0, // LOAD_FAST 0
    0x13,0x42, // LOAD_ATTR '_hash'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timezone___hash__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timezone___hash__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 39,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 65,
        .line_info = fun_data_datetime_timezone___hash__ + 5,
        .line_info_top = fun_data_datetime_timezone___hash__ + 9,
        .opcodes = fun_data_datetime_timezone___hash__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timezone___hash__ fun_data_datetime_timezone___hash__[0]
#endif

// child of datetime_timezone
// frozen bytecode for file datetime.py, scope datetime_timezone_utcoffset
static const byte fun_data_datetime_timezone_utcoffset[13] = {
    0x12,0x0e, // prelude
    0x4c,0x81,0x0d,0x81,0x0b, // names: utcoffset, self, dt
    0x90,0x03, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x50, // LOAD_ATTR '_offset'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timezone_utcoffset = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timezone_utcoffset,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 13,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 76,
        .line_info = fun_data_datetime_timezone_utcoffset + 7,
        .line_info_top = fun_data_datetime_timezone_utcoffset + 9,
        .opcodes = fun_data_datetime_timezone_utcoffset + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timezone_utcoffset fun_data_datetime_timezone_utcoffset[0]
#endif

// child of datetime_timezone
// frozen bytecode for file datetime.py, scope datetime_timezone_dst
static const byte fun_data_datetime_timezone_dst[11] = {
    0x12,0x0e, // prelude
    0x4d,0x81,0x0d,0x81,0x0b, // names: dst, self, dt
    0x90,0x06, // code info
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timezone_dst = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timezone_dst,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 11,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 77,
        .line_info = fun_data_datetime_timezone_dst + 7,
        .line_info_top = fun_data_datetime_timezone_dst + 9,
        .opcodes = fun_data_datetime_timezone_dst + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timezone_dst fun_data_datetime_timezone_dst[0]
#endif

// child of datetime_timezone
// frozen bytecode for file datetime.py, scope datetime_timezone_tzname
static const byte fun_data_datetime_timezone_tzname[29] = {
    0x22,0x12, // prelude
    0x4b,0x81,0x0d,0x81,0x0b, // names: tzname, self, dt
    0x90,0x09,0x25,0x24, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x51, // LOAD_ATTR '_name'
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0xb0, // LOAD_FAST 0
    0x13,0x51, // LOAD_ATTR '_name'
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x13,0x50, // LOAD_ATTR '_offset'
    0x14,0x24, // LOAD_METHOD '_fmt'
    0xa2, // LOAD_CONST_SMALL_INT 34
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timezone_tzname = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timezone_tzname,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 29,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 75,
        .line_info = fun_data_datetime_timezone_tzname + 7,
        .line_info_top = fun_data_datetime_timezone_tzname + 11,
        .opcodes = fun_data_datetime_timezone_tzname + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timezone_tzname fun_data_datetime_timezone_tzname[0]
#endif

// child of datetime_timezone
// frozen bytecode for file datetime.py, scope datetime_timezone_fromutc
static const byte fun_data_datetime_timezone_fromutc[15] = {
    0x1a,0x0e, // prelude
    0x4e,0x81,0x0d,0x81,0x0b, // names: fromutc, self, dt
    0x90,0x0e, // code info
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x13,0x50, // LOAD_ATTR '_offset'
    0xf2, // BINARY_OP 27 __add__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_timezone_fromutc = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timezone_fromutc,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 78,
        .line_info = fun_data_datetime_timezone_fromutc + 7,
        .line_info_top = fun_data_datetime_timezone_fromutc + 9,
        .opcodes = fun_data_datetime_timezone_fromutc + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_timezone_fromutc fun_data_datetime_timezone_fromutc[0]
#endif

static const mp_raw_code_t *const children_datetime_timezone[] = {
    (const mp_raw_code_t *)&proto_fun_datetime_timezone___init__,
    (const mp_raw_code_t *)&proto_fun_datetime_timezone___repr__,
    (const mp_raw_code_t *)&proto_fun_datetime_timezone___eq__,
    (const mp_raw_code_t *)&proto_fun_datetime_timezone___str__,
    (const mp_raw_code_t *)&proto_fun_datetime_timezone___hash__,
    (const mp_raw_code_t *)&proto_fun_datetime_timezone_utcoffset,
    (const mp_raw_code_t *)&proto_fun_datetime_timezone_dst,
    (const mp_raw_code_t *)&proto_fun_datetime_timezone_tzname,
    (const mp_raw_code_t *)&proto_fun_datetime_timezone_fromutc,
};

static const mp_raw_code_truncated_t proto_fun_datetime_timezone = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_timezone,
    .children = (void *)&children_datetime_timezone,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 67,
    .n_children = 9,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 15,
        .line_info = fun_data_datetime_timezone + 3,
        .line_info_top = fun_data_datetime_timezone + 17,
        .opcodes = fun_data_datetime_timezone + 17,
    },
    #endif
    #endif
};

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime__date
static const byte fun_data_datetime__date[143] = {
    0x43,0x1c, // prelude
    0x18,0x78,0x79,0x81,0x01, // names: _date, y, m, d
    0x90,0x15,0x1f,0x56,0x24,0x56,0x2b,0x3d,0x42, // code info
    0x12,0x76, // LOAD_GLOBAL 'MINYEAR'
    0xb0, // LOAD_FAST 0
    0x57, // DUP_TOP
    0x5b, // ROT_THREE
    0xda, // BINARY_OP 3 __le__
    0x46,0x05, // JUMP_IF_FALSE_OR_POP 5
    0x12,0x77, // LOAD_GLOBAL 'MAXYEAR'
    0xda, // BINARY_OP 3 __le__
    0x42,0x42, // JUMP 2
    0x5a, // ROT_TWO
    0x59, // POP_TOP
    0x44,0xc8,0x80, // POP_JUMP_IF_FALSE 72
    0x81, // LOAD_CONST_SMALL_INT 1
    0xb1, // LOAD_FAST 1
    0x57, // DUP_TOP
    0x5b, // ROT_THREE
    0xda, // BINARY_OP 3 __le__
    0x46,0x04, // JUMP_IF_FALSE_OR_POP 4
    0x8c, // LOAD_CONST_SMALL_INT 12
    0xda, // BINARY_OP 3 __le__
    0x42,0x42, // JUMP 2
    0x5a, // ROT_TWO
    0x59, // POP_TOP
    0x44,0x79, // POP_JUMP_IF_FALSE 57
    0x81, // LOAD_CONST_SMALL_INT 1
    0xb2, // LOAD_FAST 2
    0x57, // DUP_TOP
    0x5b, // ROT_THREE
    0xda, // BINARY_OP 3 __le__
    0x46,0x09, // JUMP_IF_FALSE_OR_POP 9
    0x12,0x15, // LOAD_GLOBAL '_dim'
    0xb0, // LOAD_FAST 0
    0xb1, // LOAD_FAST 1
    0x34,0x02, // CALL_FUNCTION 2
    0xda, // BINARY_OP 3 __le__
    0x42,0x42, // JUMP 2
    0x5a, // ROT_TWO
    0x59, // POP_TOP
    0x44,0x65, // POP_JUMP_IF_FALSE 37
    0xb0, // LOAD_FAST 0
    0x81, // LOAD_CONST_SMALL_INT 1
    0xf3, // BINARY_OP 28 __sub__
    0xc3, // STORE_FAST 3
    0xb3, // LOAD_FAST 3
    0x22,0x82,0x6d, // LOAD_CONST_SMALL_INT 365
    0xf4, // BINARY_OP 29 __mul__
    0xb3, // LOAD_FAST 3
    0x84, // LOAD_CONST_SMALL_INT 4
    0xf6, // BINARY_OP 31 __floordiv__
    0xf2, // BINARY_OP 27 __add__
    0xb3, // LOAD_FAST 3
    0x22,0x80,0x64, // LOAD_CONST_SMALL_INT 100
    0xf6, // BINARY_OP 31 __floordiv__
    0xf3, // BINARY_OP 28 __sub__
    0xb3, // LOAD_FAST 3
    0x22,0x83,0x10, // LOAD_CONST_SMALL_INT 400
    0xf6, // BINARY_OP 31 __floordiv__
    0xf2, // BINARY_OP 27 __add__
    0xc4, // STORE_FAST 4
    0xb4, // LOAD_FAST 4
    0x12,0x16, // LOAD_GLOBAL '_dbm'
    0xb0, // LOAD_FAST 0
    0xb1, // LOAD_FAST 1
    0x34,0x02, // CALL_FUNCTION 2
    0xf2, // BINARY_OP 27 __add__
    0xb2, // LOAD_FAST 2
    0xf2, // BINARY_OP 27 __add__
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x5a, // POP_JUMP_IF_FALSE 26
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x55, // POP_JUMP_IF_FALSE 21
    0x81, // LOAD_CONST_SMALL_INT 1
    0xb2, // LOAD_FAST 2
    0x57, // DUP_TOP
    0x5b, // ROT_THREE
    0xda, // BINARY_OP 3 __le__
    0x46,0x08, // JUMP_IF_FALSE_OR_POP 8
    0x22,0x81,0xde,0xf3,0x5b, // LOAD_CONST_SMALL_INT 3652059
    0xda, // BINARY_OP 3 __le__
    0x42,0x42, // JUMP 2
    0x5a, // ROT_TWO
    0x59, // POP_TOP
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb2, // LOAD_FAST 2
    0x63, // RETURN_VALUE
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime__date = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__date,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 143,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 9,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 24,
        .line_info = fun_data_datetime__date + 7,
        .line_info_top = fun_data_datetime__date + 16,
        .opcodes = fun_data_datetime__date + 16,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime__date fun_data_datetime__date[0]
#endif

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime__iso2d
static const byte fun_data_datetime__iso2d[74] = {
    0x31,0x0c, // prelude
    0x19,0x45, // names: _iso2d, s
    0x90,0x22,0x3a,0x24, // code info
    0x12,0x81,0x03, // LOAD_GLOBAL 'len'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x8a, // LOAD_CONST_SMALL_INT 10
    0xd7, // BINARY_OP 0 __lt__
    0x43,0x50, // POP_JUMP_IF_TRUE 16
    0xb0, // LOAD_FAST 0
    0x84, // LOAD_CONST_SMALL_INT 4
    0x55, // LOAD_SUBSCR
    0x10,0x1a, // LOAD_CONST_STRING '-'
    0xdc, // BINARY_OP 5 __ne__
    0x43,0x48, // POP_JUMP_IF_TRUE 8
    0xb0, // LOAD_FAST 0
    0x87, // LOAD_CONST_SMALL_INT 7
    0x55, // LOAD_SUBSCR
    0x10,0x1a, // LOAD_CONST_STRING '-'
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x84, // LOAD_CONST_SMALL_INT 4
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0x85, // LOAD_CONST_SMALL_INT 5
    0x87, // LOAD_CONST_SMALL_INT 7
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0x88, // LOAD_CONST_SMALL_INT 8
    0x8a, // LOAD_CONST_SMALL_INT 10
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0x2a,0x03, // BUILD_TUPLE 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime__iso2d = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__iso2d,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 74,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 25,
        .line_info = fun_data_datetime__iso2d + 4,
        .line_info_top = fun_data_datetime__iso2d + 8,
        .opcodes = fun_data_datetime__iso2d + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime__iso2d fun_data_datetime__iso2d[0]
#endif

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime__d2iso
static const byte fun_data_datetime__d2iso[16] = {
    0x19,0x0a, // prelude
    0x1b,0x81,0x05, // names: _d2iso, o
    0x90,0x28, // code info
    0x23,0x02, // LOAD_CONST_OBJ 2
    0x12,0x17, // LOAD_GLOBAL '_o2ymd'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0xf8, // BINARY_OP 33 __mod__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime__d2iso = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__d2iso,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 27,
        .line_info = fun_data_datetime__d2iso + 5,
        .line_info_top = fun_data_datetime__d2iso + 7,
        .opcodes = fun_data_datetime__d2iso + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime__d2iso fun_data_datetime__d2iso[0]
#endif

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime_date
static const byte fun_data_datetime_date[190] = {
    0x10,0x50, // prelude
    0x11, // names: date
    0x98,0x2c,0x64,0x69,0x20,0x69,0x20,0x69,0x20,0x69,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x64,0x64,0x40,0x8a,0x0a,0x64,0x64,0x60,0x64,0x60,0x64,0x64,0x64,0x64,0x64,0x64,0x64,0x64,0x20,0x44,0x64,0x40, // code info
    0x11,0x7c, // LOAD_NAME '__name__'
    0x16,0x7d, // STORE_NAME '__module__'
    0x10,0x11, // LOAD_CONST_STRING 'date'
    0x16,0x7e, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x2a, // STORE_NAME '__init__'
    0x11,0x81,0x06, // LOAD_NAME 'classmethod'
    0x32,0x01, // MAKE_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x53, // STORE_NAME 'fromtimestamp'
    0x11,0x81,0x06, // LOAD_NAME 'classmethod'
    0x32,0x02, // MAKE_FUNCTION 2
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x54, // STORE_NAME 'today'
    0x11,0x81,0x06, // LOAD_NAME 'classmethod'
    0x32,0x03, // MAKE_FUNCTION 3
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x55, // STORE_NAME 'fromordinal'
    0x11,0x81,0x06, // LOAD_NAME 'classmethod'
    0x32,0x04, // MAKE_FUNCTION 4
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x56, // STORE_NAME 'fromisoformat'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x05, // MAKE_FUNCTION 5
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x57, // STORE_NAME 'year'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x06, // MAKE_FUNCTION 6
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x58, // STORE_NAME 'month'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x07, // MAKE_FUNCTION 7
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x59, // STORE_NAME 'day'
    0x32,0x08, // MAKE_FUNCTION 8
    0x16,0x5a, // STORE_NAME 'toordinal'
    0x32,0x09, // MAKE_FUNCTION 9
    0x16,0x5b, // STORE_NAME 'timetuple'
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x2a,0x03, // BUILD_TUPLE 3
    0x53, // LOAD_NULL
    0x33,0x0a, // MAKE_FUNCTION_DEFARGS 10
    0x16,0x5d, // STORE_NAME 'replace'
    0x32,0x0b, // MAKE_FUNCTION 11
    0x16,0x30, // STORE_NAME '__add__'
    0x32,0x0c, // MAKE_FUNCTION 12
    0x16,0x31, // STORE_NAME '__sub__'
    0x32,0x0d, // MAKE_FUNCTION 13
    0x16,0x3a, // STORE_NAME '__eq__'
    0x32,0x0e, // MAKE_FUNCTION 14
    0x16,0x3b, // STORE_NAME '__le__'
    0x32,0x0f, // MAKE_FUNCTION 15
    0x16,0x3c, // STORE_NAME '__lt__'
    0x32,0x10, // MAKE_FUNCTION 16
    0x16,0x3d, // STORE_NAME '__ge__'
    0x32,0x11, // MAKE_FUNCTION 17
    0x16,0x3e, // STORE_NAME '__gt__'
    0x32,0x12, // MAKE_FUNCTION 18
    0x16,0x5c, // STORE_NAME 'weekday'
    0x32,0x13, // MAKE_FUNCTION 19
    0x16,0x5e, // STORE_NAME 'isoweekday'
    0x32,0x14, // MAKE_FUNCTION 20
    0x16,0x26, // STORE_NAME 'isoformat'
    0x32,0x15, // MAKE_FUNCTION 21
    0x16,0x2c, // STORE_NAME '__repr__'
    0x11,0x26, // LOAD_NAME 'isoformat'
    0x16,0x40, // STORE_NAME '__str__'
    0x32,0x16, // MAKE_FUNCTION 22
    0x16,0x41, // STORE_NAME '__hash__'
    0x32,0x17, // MAKE_FUNCTION 23
    0x16,0x4a, // STORE_NAME 'tuple'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date___init__
static const byte fun_data_datetime_date___init__[23] = {
    0xb8,0x04,0x10, // prelude
    0x2a,0x81,0x0d,0x57,0x58,0x59, // names: __init__, self, year, month, day
    0x90,0x2d, // code info
    0x12,0x18, // LOAD_GLOBAL '_date'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0x34,0x03, // CALL_FUNCTION 3
    0xb0, // LOAD_FAST 0
    0x18,0x52, // STORE_ATTR '_ord'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 4,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 42,
        .line_info = fun_data_datetime_date___init__ + 9,
        .line_info_top = fun_data_datetime_date___init__ + 11,
        .opcodes = fun_data_datetime_date___init__ + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date___init__ fun_data_datetime_date___init__[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_fromtimestamp
static const byte fun_data_datetime_date_fromtimestamp[24] = {
    0x2a,0x0e, // prelude
    0x53,0x81,0x1d,0x81,0x1e, // names: fromtimestamp, cls, ts
    0x90,0x31, // code info
    0xb0, // LOAD_FAST 0
    0x12,0x74, // LOAD_GLOBAL '_localtime'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x51, // LOAD_CONST_NONE
    0x83, // LOAD_CONST_SMALL_INT 3
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_fromtimestamp = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_fromtimestamp,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 24,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 83,
        .line_info = fun_data_datetime_date_fromtimestamp + 7,
        .line_info_top = fun_data_datetime_date_fromtimestamp + 9,
        .opcodes = fun_data_datetime_date_fromtimestamp + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_fromtimestamp fun_data_datetime_date_fromtimestamp[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_today
static const byte fun_data_datetime_date_today[21] = {
    0x21,0x0a, // prelude
    0x54,0x81,0x1d, // names: today, cls
    0x90,0x35, // code info
    0xb0, // LOAD_FAST 0
    0x12,0x74, // LOAD_GLOBAL '_localtime'
    0x34,0x00, // CALL_FUNCTION 0
    0x51, // LOAD_CONST_NONE
    0x83, // LOAD_CONST_SMALL_INT 3
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_today = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_today,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 21,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 84,
        .line_info = fun_data_datetime_date_today + 5,
        .line_info_top = fun_data_datetime_date_today + 7,
        .opcodes = fun_data_datetime_date_today + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_today fun_data_datetime_date_today[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_fromordinal
static const byte fun_data_datetime_date_fromordinal[15] = {
    0x2a,0x0c, // prelude
    0x55,0x81,0x1d,0x7a, // names: fromordinal, cls, n
    0x90,0x39, // code info
    0xb0, // LOAD_FAST 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb1, // LOAD_FAST 1
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_fromordinal = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_fromordinal,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 85,
        .line_info = fun_data_datetime_date_fromordinal + 6,
        .line_info_top = fun_data_datetime_date_fromordinal + 8,
        .opcodes = fun_data_datetime_date_fromordinal + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_fromordinal fun_data_datetime_date_fromordinal[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_fromisoformat
static const byte fun_data_datetime_date_fromisoformat[18] = {
    0x22,0x0c, // prelude
    0x56,0x81,0x1d,0x45, // names: fromisoformat, cls, s
    0x90,0x3d, // code info
    0xb0, // LOAD_FAST 0
    0x12,0x19, // LOAD_GLOBAL '_iso2d'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_fromisoformat = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_fromisoformat,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 86,
        .line_info = fun_data_datetime_date_fromisoformat + 6,
        .line_info_top = fun_data_datetime_date_fromisoformat + 8,
        .opcodes = fun_data_datetime_date_fromisoformat + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_fromisoformat fun_data_datetime_date_fromisoformat[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_year
static const byte fun_data_datetime_date_year[15] = {
    0x11,0x0a, // prelude
    0x57,0x81,0x0d, // names: year, self
    0x90,0x41, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_year = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_year,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 87,
        .line_info = fun_data_datetime_date_year + 5,
        .line_info_top = fun_data_datetime_date_year + 7,
        .opcodes = fun_data_datetime_date_year + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_year fun_data_datetime_date_year[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_month
static const byte fun_data_datetime_date_month[15] = {
    0x11,0x0a, // prelude
    0x58,0x81,0x0d, // names: month, self
    0x90,0x45, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_month = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_month,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 88,
        .line_info = fun_data_datetime_date_month + 5,
        .line_info_top = fun_data_datetime_date_month + 7,
        .opcodes = fun_data_datetime_date_month + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_month fun_data_datetime_date_month[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_day
static const byte fun_data_datetime_date_day[15] = {
    0x11,0x0a, // prelude
    0x59,0x81,0x0d, // names: day, self
    0x90,0x49, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x82, // LOAD_CONST_SMALL_INT 2
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_day = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_day,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 89,
        .line_info = fun_data_datetime_date_day + 5,
        .line_info_top = fun_data_datetime_date_day + 7,
        .opcodes = fun_data_datetime_date_day + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_day fun_data_datetime_date_day[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_toordinal
static const byte fun_data_datetime_date_toordinal[11] = {
    0x09,0x0a, // prelude
    0x5a,0x81,0x0d, // names: toordinal, self
    0x90,0x4c, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_toordinal = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_toordinal,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 11,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 90,
        .line_info = fun_data_datetime_date_toordinal + 5,
        .line_info_top = fun_data_datetime_date_toordinal + 7,
        .opcodes = fun_data_datetime_date_toordinal + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_toordinal fun_data_datetime_date_toordinal[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_timetuple
static const byte fun_data_datetime_date_timetuple[44] = {
    0x69,0x0e, // prelude
    0x5b,0x81,0x0d, // names: timetuple, self
    0x90,0x4f,0x2a,0x29, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x30,0x03, // UNPACK_SEQUENCE 3
    0xc1, // STORE_FAST 1
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0x12,0x16, // LOAD_GLOBAL '_dbm'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0x34,0x02, // CALL_FUNCTION 2
    0xb3, // LOAD_FAST 3
    0xf2, // BINARY_OP 27 __add__
    0xc4, // STORE_FAST 4
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x14,0x5c, // LOAD_METHOD 'weekday'
    0x36,0x00, // CALL_METHOD 0
    0xb4, // LOAD_FAST 4
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x2a,0x09, // BUILD_TUPLE 9
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_timetuple = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_timetuple,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 44,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 14,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 91,
        .line_info = fun_data_datetime_date_timetuple + 5,
        .line_info_top = fun_data_datetime_date_timetuple + 9,
        .opcodes = fun_data_datetime_date_timetuple + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_timetuple fun_data_datetime_date_timetuple[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_replace
static const byte fun_data_datetime_date_replace[58] = {
    0xd0,0x85,0x01,0x1e, // prelude
    0x5d,0x81,0x0d,0x57,0x58,0x59, // names: replace, self, year, month, day
    0x90,0x54,0x2a,0x25,0x22,0x25,0x22,0x25,0x22, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x30,0x03, // UNPACK_SEQUENCE 3
    0xc4, // STORE_FAST 4
    0xc5, // STORE_FAST 5
    0xc6, // STORE_FAST 6
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb4, // LOAD_FAST 4
    0xc1, // STORE_FAST 1
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb5, // LOAD_FAST 5
    0xc2, // STORE_FAST 2
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb6, // LOAD_FAST 6
    0xc3, // STORE_FAST 3
    0x12,0x11, // LOAD_GLOBAL 'date'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_replace = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_replace,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 58,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 11,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 4,
        .n_kwonly_args = 0,
        .n_def_pos_args = 3,
        .qstr_block_name_idx = 93,
        .line_info = fun_data_datetime_date_replace + 10,
        .line_info_top = fun_data_datetime_date_replace + 19,
        .opcodes = fun_data_datetime_date_replace + 19,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_replace fun_data_datetime_date_replace[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date___add__
static const byte fun_data_datetime_date___add__[23] = {
    0x2a,0x0e, // prelude
    0x30,0x81,0x0d,0x81,0x11, // names: __add__, self, other
    0x90,0x5e, // code info
    0x12,0x11, // LOAD_GLOBAL 'date'
    0x14,0x55, // LOAD_METHOD 'fromordinal'
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0xb1, // LOAD_FAST 1
    0x13,0x06, // LOAD_ATTR 'days'
    0xf2, // BINARY_OP 27 __add__
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date___add__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date___add__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 48,
        .line_info = fun_data_datetime_date___add__ + 7,
        .line_info_top = fun_data_datetime_date___add__ + 9,
        .opcodes = fun_data_datetime_date___add__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date___add__ fun_data_datetime_date___add__[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date___sub__
static const byte fun_data_datetime_date___sub__[52] = {
    0x2a,0x12, // prelude
    0x31,0x81,0x0d,0x81,0x11, // names: __sub__, self, other
    0x90,0x61,0x2a,0x4f, // code info
    0x12,0x81,0x12, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x11, // LOAD_GLOBAL 'date'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x4f, // POP_JUMP_IF_FALSE 15
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x10,0x06, // LOAD_CONST_STRING 'days'
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0xb1, // LOAD_FAST 1
    0x13,0x52, // LOAD_ATTR '_ord'
    0xf3, // BINARY_OP 28 __sub__
    0x34,0x82,0x00, // CALL_FUNCTION 256
    0x63, // RETURN_VALUE
    0x12,0x11, // LOAD_GLOBAL 'date'
    0x14,0x55, // LOAD_METHOD 'fromordinal'
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0xb1, // LOAD_FAST 1
    0x13,0x06, // LOAD_ATTR 'days'
    0xf3, // BINARY_OP 28 __sub__
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date___sub__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date___sub__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 52,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 49,
        .line_info = fun_data_datetime_date___sub__ + 7,
        .line_info_top = fun_data_datetime_date___sub__ + 11,
        .opcodes = fun_data_datetime_date___sub__ + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date___sub__ fun_data_datetime_date___sub__[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date___eq__
static const byte fun_data_datetime_date___eq__[33] = {
    0x22,0x12, // prelude
    0x3a,0x81,0x0d,0x81,0x11, // names: __eq__, self, other
    0x90,0x67,0x2a,0x48, // code info
    0x12,0x81,0x12, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x11, // LOAD_GLOBAL 'date'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0xb1, // LOAD_FAST 1
    0x13,0x52, // LOAD_ATTR '_ord'
    0xd9, // BINARY_OP 2 __eq__
    0x63, // RETURN_VALUE
    0x50, // LOAD_CONST_FALSE
    0x63, // RETURN_VALUE
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date___eq__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date___eq__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 33,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 58,
        .line_info = fun_data_datetime_date___eq__ + 7,
        .line_info_top = fun_data_datetime_date___eq__ + 11,
        .opcodes = fun_data_datetime_date___eq__ + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date___eq__ fun_data_datetime_date___eq__[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date___le__
static const byte fun_data_datetime_date___le__[17] = {
    0x1a,0x0e, // prelude
    0x3b,0x81,0x0d,0x81,0x11, // names: __le__, self, other
    0x90,0x6d, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0xb1, // LOAD_FAST 1
    0x13,0x52, // LOAD_ATTR '_ord'
    0xda, // BINARY_OP 3 __le__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date___le__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date___le__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 59,
        .line_info = fun_data_datetime_date___le__ + 7,
        .line_info_top = fun_data_datetime_date___le__ + 9,
        .opcodes = fun_data_datetime_date___le__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date___le__ fun_data_datetime_date___le__[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date___lt__
static const byte fun_data_datetime_date___lt__[17] = {
    0x1a,0x0e, // prelude
    0x3c,0x81,0x0d,0x81,0x11, // names: __lt__, self, other
    0x90,0x70, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0xb1, // LOAD_FAST 1
    0x13,0x52, // LOAD_ATTR '_ord'
    0xd7, // BINARY_OP 0 __lt__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date___lt__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date___lt__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 60,
        .line_info = fun_data_datetime_date___lt__ + 7,
        .line_info_top = fun_data_datetime_date___lt__ + 9,
        .opcodes = fun_data_datetime_date___lt__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date___lt__ fun_data_datetime_date___lt__[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date___ge__
static const byte fun_data_datetime_date___ge__[17] = {
    0x1a,0x0e, // prelude
    0x3d,0x81,0x0d,0x81,0x11, // names: __ge__, self, other
    0x90,0x73, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0xb1, // LOAD_FAST 1
    0x13,0x52, // LOAD_ATTR '_ord'
    0xdb, // BINARY_OP 4 __ge__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date___ge__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date___ge__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 61,
        .line_info = fun_data_datetime_date___ge__ + 7,
        .line_info_top = fun_data_datetime_date___ge__ + 9,
        .opcodes = fun_data_datetime_date___ge__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date___ge__ fun_data_datetime_date___ge__[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date___gt__
static const byte fun_data_datetime_date___gt__[17] = {
    0x1a,0x0e, // prelude
    0x3e,0x81,0x0d,0x81,0x11, // names: __gt__, self, other
    0x90,0x76, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0xb1, // LOAD_FAST 1
    0x13,0x52, // LOAD_ATTR '_ord'
    0xd8, // BINARY_OP 1 __gt__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date___gt__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date___gt__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 62,
        .line_info = fun_data_datetime_date___gt__ + 7,
        .line_info_top = fun_data_datetime_date___gt__ + 9,
        .opcodes = fun_data_datetime_date___gt__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date___gt__ fun_data_datetime_date___gt__[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_weekday
static const byte fun_data_datetime_date_weekday[15] = {
    0x11,0x0a, // prelude
    0x5c,0x81,0x0d, // names: weekday, self
    0x90,0x79, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0x86, // LOAD_CONST_SMALL_INT 6
    0xf2, // BINARY_OP 27 __add__
    0x87, // LOAD_CONST_SMALL_INT 7
    0xf8, // BINARY_OP 33 __mod__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_weekday = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_weekday,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 92,
        .line_info = fun_data_datetime_date_weekday + 5,
        .line_info_top = fun_data_datetime_date_weekday + 7,
        .opcodes = fun_data_datetime_date_weekday + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_weekday fun_data_datetime_date_weekday[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_isoweekday
static const byte fun_data_datetime_date_isoweekday[16] = {
    0x11,0x0a, // prelude
    0x5e,0x81,0x0d, // names: isoweekday, self
    0x90,0x7c, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0x87, // LOAD_CONST_SMALL_INT 7
    0xf8, // BINARY_OP 33 __mod__
    0x45,0x01, // JUMP_IF_TRUE_OR_POP 1
    0x87, // LOAD_CONST_SMALL_INT 7
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_isoweekday = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_isoweekday,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 94,
        .line_info = fun_data_datetime_date_isoweekday + 5,
        .line_info_top = fun_data_datetime_date_isoweekday + 7,
        .opcodes = fun_data_datetime_date_isoweekday + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_isoweekday fun_data_datetime_date_isoweekday[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_isoformat
static const byte fun_data_datetime_date_isoformat[15] = {
    0x11,0x0a, // prelude
    0x26,0x81,0x0d, // names: isoformat, self
    0x90,0x7f, // code info
    0x12,0x1b, // LOAD_GLOBAL '_d2iso'
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_isoformat = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_isoformat,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 38,
        .line_info = fun_data_datetime_date_isoformat + 5,
        .line_info_top = fun_data_datetime_date_isoformat + 7,
        .opcodes = fun_data_datetime_date_isoformat + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_isoformat fun_data_datetime_date_isoformat[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date___repr__
static const byte fun_data_datetime_date___repr__[28] = {
    0x41,0x0c, // prelude
    0x2c,0x81,0x0d, // names: __repr__, self
    0x90,0x82,0x2a, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x30,0x03, // UNPACK_SEQUENCE 3
    0xc1, // STORE_FAST 1
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0x23,0x08, // LOAD_CONST_OBJ 8
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0x36,0x03, // CALL_METHOD 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date___repr__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date___repr__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 28,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 9,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 44,
        .line_info = fun_data_datetime_date___repr__ + 5,
        .line_info_top = fun_data_datetime_date___repr__ + 8,
        .opcodes = fun_data_datetime_date___repr__ + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date___repr__ fun_data_datetime_date___repr__[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date___hash__
static const byte fun_data_datetime_date___hash__[34] = {
    0x19,0x0e, // prelude
    0x41,0x81,0x0d, // names: __hash__, self
    0x90,0x88,0x2a,0x2b, // code info
    0x12,0x81,0x13, // LOAD_GLOBAL 'hasattr'
    0xb0, // LOAD_FAST 0
    0x10,0x42, // LOAD_CONST_STRING '_hash'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x4b, // POP_JUMP_IF_TRUE 11
    0x12,0x81,0x14, // LOAD_GLOBAL 'hash'
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0x34,0x01, // CALL_FUNCTION 1
    0xb0, // LOAD_FAST 0
    0x18,0x42, // STORE_ATTR '_hash'
    0xb0, // LOAD_FAST 0
    0x13,0x42, // LOAD_ATTR '_hash'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date___hash__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date___hash__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 34,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 65,
        .line_info = fun_data_datetime_date___hash__ + 5,
        .line_info_top = fun_data_datetime_date___hash__ + 9,
        .opcodes = fun_data_datetime_date___hash__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date___hash__ fun_data_datetime_date___hash__[0]
#endif

// child of datetime_date
// frozen bytecode for file datetime.py, scope datetime_date_tuple
static const byte fun_data_datetime_date_tuple[15] = {
    0x11,0x0a, // prelude
    0x4a,0x81,0x0d, // names: tuple, self
    0x90,0x8d, // code info
    0x12,0x17, // LOAD_GLOBAL '_o2ymd'
    0xb0, // LOAD_FAST 0
    0x13,0x52, // LOAD_ATTR '_ord'
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_date_tuple = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date_tuple,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 74,
        .line_info = fun_data_datetime_date_tuple + 5,
        .line_info_top = fun_data_datetime_date_tuple + 7,
        .opcodes = fun_data_datetime_date_tuple + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_date_tuple fun_data_datetime_date_tuple[0]
#endif

static const mp_raw_code_t *const children_datetime_date[] = {
    (const mp_raw_code_t *)&proto_fun_datetime_date___init__,
    (const mp_raw_code_t *)&proto_fun_datetime_date_fromtimestamp,
    (const mp_raw_code_t *)&proto_fun_datetime_date_today,
    (const mp_raw_code_t *)&proto_fun_datetime_date_fromordinal,
    (const mp_raw_code_t *)&proto_fun_datetime_date_fromisoformat,
    (const mp_raw_code_t *)&proto_fun_datetime_date_year,
    (const mp_raw_code_t *)&proto_fun_datetime_date_month,
    (const mp_raw_code_t *)&proto_fun_datetime_date_day,
    (const mp_raw_code_t *)&proto_fun_datetime_date_toordinal,
    (const mp_raw_code_t *)&proto_fun_datetime_date_timetuple,
    (const mp_raw_code_t *)&proto_fun_datetime_date_replace,
    (const mp_raw_code_t *)&proto_fun_datetime_date___add__,
    (const mp_raw_code_t *)&proto_fun_datetime_date___sub__,
    (const mp_raw_code_t *)&proto_fun_datetime_date___eq__,
    (const mp_raw_code_t *)&proto_fun_datetime_date___le__,
    (const mp_raw_code_t *)&proto_fun_datetime_date___lt__,
    (const mp_raw_code_t *)&proto_fun_datetime_date___ge__,
    (const mp_raw_code_t *)&proto_fun_datetime_date___gt__,
    (const mp_raw_code_t *)&proto_fun_datetime_date_weekday,
    (const mp_raw_code_t *)&proto_fun_datetime_date_isoweekday,
    (const mp_raw_code_t *)&proto_fun_datetime_date_isoformat,
    (const mp_raw_code_t *)&proto_fun_datetime_date___repr__,
    (const mp_raw_code_t *)&proto_fun_datetime_date___hash__,
    (const mp_raw_code_t *)&proto_fun_datetime_date_tuple,
};

static const mp_raw_code_truncated_t proto_fun_datetime_date = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_date,
    .children = (void *)&children_datetime_date,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 190,
    .n_children = 24,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 17,
        .line_info = fun_data_datetime_date + 3,
        .line_info_top = fun_data_datetime_date + 42,
        .opcodes = fun_data_datetime_date + 42,
    },
    #endif
    #endif
};

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime__time
static const byte fun_data_datetime__time[144] = {
    0xd9,0x04,0x24, // prelude
    0x1c,0x81,0x07,0x79,0x45,0x81,0x08,0x27, // names: _time, h, m, s, us, fold
    0x90,0x96,0x20,0x2f,0x30,0x30,0x32,0x2a,0x3f,0x4b, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x57, // DUP_TOP
    0x5b, // ROT_THREE
    0xda, // BINARY_OP 3 __le__
    0x46,0x04, // JUMP_IF_FALSE_OR_POP 4
    0x98, // LOAD_CONST_SMALL_INT 24
    0xd7, // BINARY_OP 0 __lt__
    0x42,0x42, // JUMP 2
    0x5a, // ROT_TWO
    0x59, // POP_TOP
    0x44,0x7c, // POP_JUMP_IF_FALSE 60
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb1, // LOAD_FAST 1
    0x57, // DUP_TOP
    0x5b, // ROT_THREE
    0xda, // BINARY_OP 3 __le__
    0x46,0x05, // JUMP_IF_FALSE_OR_POP 5
    0x22,0x3c, // LOAD_CONST_SMALL_INT 60
    0xd7, // BINARY_OP 0 __lt__
    0x42,0x42, // JUMP 2
    0x5a, // ROT_TWO
    0x59, // POP_TOP
    0x44,0x6c, // POP_JUMP_IF_FALSE 44
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb2, // LOAD_FAST 2
    0x57, // DUP_TOP
    0x5b, // ROT_THREE
    0xda, // BINARY_OP 3 __le__
    0x46,0x05, // JUMP_IF_FALSE_OR_POP 5
    0x22,0x3c, // LOAD_CONST_SMALL_INT 60
    0xd7, // BINARY_OP 0 __lt__
    0x42,0x42, // JUMP 2
    0x5a, // ROT_TWO
    0x59, // POP_TOP
    0x44,0x5c, // POP_JUMP_IF_FALSE 28
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb3, // LOAD_FAST 3
    0x57, // DUP_TOP
    0x5b, // ROT_THREE
    0xda, // BINARY_OP 3 __le__
    0x46,0x07, // JUMP_IF_FALSE_OR_POP 7
    0x22,0xbd,0x84,0x40, // LOAD_CONST_SMALL_INT 1000000
    0xd7, // BINARY_OP 0 __lt__
    0x42,0x42, // JUMP 2
    0x5a, // ROT_TWO
    0x59, // POP_TOP
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0xb4, // LOAD_FAST 4
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x43,0x64, // POP_JUMP_IF_TRUE 36
    0xb4, // LOAD_FAST 4
    0x81, // LOAD_CONST_SMALL_INT 1
    0xd9, // BINARY_OP 2 __eq__
    0x43,0x5f, // POP_JUMP_IF_TRUE 31
    0xb0, // LOAD_FAST 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x65, // POP_JUMP_IF_FALSE 37
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x60, // POP_JUMP_IF_FALSE 32
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x5b, // POP_JUMP_IF_FALSE 27
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb3, // LOAD_FAST 3
    0x57, // DUP_TOP
    0x5b, // ROT_THREE
    0xd7, // BINARY_OP 0 __lt__
    0x46,0x05, // JUMP_IF_FALSE_OR_POP 5
    0x23,0x03, // LOAD_CONST_OBJ 3
    0xd7, // BINARY_OP 0 __lt__
    0x42,0x42, // JUMP 2
    0x5a, // ROT_TWO
    0x59, // POP_TOP
    0x44,0x4b, // POP_JUMP_IF_FALSE 11
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x34,0x06, // CALL_FUNCTION 6
    0x63, // RETURN_VALUE
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime__time = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__time,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 144,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 12,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 5,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 28,
        .line_info = fun_data_datetime__time + 11,
        .line_info_top = fun_data_datetime__time + 21,
        .opcodes = fun_data_datetime__time + 21,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime__time fun_data_datetime__time[0]
#endif

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime__iso2t
static const byte fun_data_datetime__iso2t[516] = {
    0xb1,0x10,0x84,0x02, // prelude
    0x1d,0x45, // names: _iso2t, s
    0x90,0xa3,0x22,0x22,0x22,0x22,0x23,0x22,0x22,0x22,0x22,0x27,0x22,0x25,0x24,0x24,0x2e,0x2f,0x24,0x27,0x24,0x2e,0x2f,0x24,0x27,0x24,0x2e,0x2f,0x24,0x27,0x24,0x32,0x2d,0x24,0x27,0x24,0x30,0x26,0x29,0x24,0x24,0x24,0x27,0x24,0x30,0x2e,0x2f,0x24,0x27,0x24,0x2e,0x2d,0x24,0x27,0x24,0x2e,0x25,0x24,0x23,0x32,0x26,0x23,0x48,0x22, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc1, // STORE_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc2, // STORE_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc3, // STORE_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc4, // STORE_FAST 4
    0x10,0x1e, // LOAD_CONST_STRING ''
    0xc5, // STORE_FAST 5
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc6, // STORE_FAST 6
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc7, // STORE_FAST 7
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc8, // STORE_FAST 8
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc9, // STORE_FAST 9
    0x12,0x81,0x03, // LOAD_GLOBAL 'len'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0xca, // STORE_FAST 10
    0x80, // LOAD_CONST_SMALL_INT 0
    0xcb, // STORE_FAST 11
    0xba, // LOAD_FAST 10
    0x82, // LOAD_CONST_SMALL_INT 2
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0xbb, // LOAD_FAST 11
    0x82, // LOAD_CONST_SMALL_INT 2
    0xe5, // BINARY_OP 14 __iadd__
    0xcb, // STORE_FAST 11
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x82, // LOAD_CONST_SMALL_INT 2
    0xf3, // BINARY_OP 28 __sub__
    0xbb, // LOAD_FAST 11
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0xc1, // STORE_FAST 1
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xd8, // BINARY_OP 1 __gt__
    0x44,0xae,0x81, // POP_JUMP_IF_FALSE 174
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x55, // LOAD_SUBSCR
    0x10,0x1f, // LOAD_CONST_STRING ':'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0xa5,0x81, // POP_JUMP_IF_FALSE 165
    0xbb, // LOAD_FAST 11
    0x83, // LOAD_CONST_SMALL_INT 3
    0xe5, // BINARY_OP 14 __iadd__
    0xcb, // STORE_FAST 11
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xf3, // BINARY_OP 28 __sub__
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x82, // LOAD_CONST_SMALL_INT 2
    0xf3, // BINARY_OP 28 __sub__
    0xbb, // LOAD_FAST 11
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0xc2, // STORE_FAST 2
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x82,0x81, // POP_JUMP_IF_FALSE 130
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x55, // LOAD_SUBSCR
    0x10,0x1f, // LOAD_CONST_STRING ':'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0xf9,0x80, // POP_JUMP_IF_FALSE 121
    0xbb, // LOAD_FAST 11
    0x83, // LOAD_CONST_SMALL_INT 3
    0xe5, // BINARY_OP 14 __iadd__
    0xcb, // STORE_FAST 11
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xf3, // BINARY_OP 28 __sub__
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x82, // LOAD_CONST_SMALL_INT 2
    0xf3, // BINARY_OP 28 __sub__
    0xbb, // LOAD_FAST 11
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0xc3, // STORE_FAST 3
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xd8, // BINARY_OP 1 __gt__
    0x44,0xd6,0x80, // POP_JUMP_IF_FALSE 86
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x55, // LOAD_SUBSCR
    0x10,0x20, // LOAD_CONST_STRING '.'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0xcd,0x80, // POP_JUMP_IF_FALSE 77
    0xbb, // LOAD_FAST 11
    0x84, // LOAD_CONST_SMALL_INT 4
    0xe5, // BINARY_OP 14 __iadd__
    0xcb, // STORE_FAST 11
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xf3, // BINARY_OP 28 __sub__
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0x22,0x87,0x68, // LOAD_CONST_SMALL_INT 1000
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x83, // LOAD_CONST_SMALL_INT 3
    0xf3, // BINARY_OP 28 __sub__
    0xbb, // LOAD_FAST 11
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0xf4, // BINARY_OP 29 __mul__
    0xc4, // STORE_FAST 4
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x67, // POP_JUMP_IF_FALSE 39
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x55, // LOAD_SUBSCR
    0x10,0x21, // LOAD_CONST_STRING '+'
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x5f, // POP_JUMP_IF_FALSE 31
    0xbb, // LOAD_FAST 11
    0x83, // LOAD_CONST_SMALL_INT 3
    0xe5, // BINARY_OP 14 __iadd__
    0xcb, // STORE_FAST 11
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xf3, // BINARY_OP 28 __sub__
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0xb4, // LOAD_FAST 4
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x83, // LOAD_CONST_SMALL_INT 3
    0xf3, // BINARY_OP 28 __sub__
    0xbb, // LOAD_FAST 11
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0xe5, // BINARY_OP 14 __iadd__
    0xc4, // STORE_FAST 4
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x94,0x81, // POP_JUMP_IF_FALSE 148
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x55, // LOAD_SUBSCR
    0x10,0x22, // LOAD_CONST_STRING '+-'
    0xdd, // BINARY_OP 6 <in>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x55, // LOAD_SUBSCR
    0xc5, // STORE_FAST 5
    0xbb, // LOAD_FAST 11
    0x86, // LOAD_CONST_SMALL_INT 6
    0xe5, // BINARY_OP 14 __iadd__
    0xcb, // STORE_FAST 11
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xf3, // BINARY_OP 28 __sub__
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x85, // LOAD_CONST_SMALL_INT 5
    0xf3, // BINARY_OP 28 __sub__
    0xbb, // LOAD_FAST 11
    0x83, // LOAD_CONST_SMALL_INT 3
    0xf3, // BINARY_OP 28 __sub__
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0xc6, // STORE_FAST 6
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x82, // LOAD_CONST_SMALL_INT 2
    0xf3, // BINARY_OP 28 __sub__
    0xbb, // LOAD_FAST 11
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0xc7, // STORE_FAST 7
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xd8, // BINARY_OP 1 __gt__
    0x44,0xd0,0x80, // POP_JUMP_IF_FALSE 80
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x55, // LOAD_SUBSCR
    0x10,0x1f, // LOAD_CONST_STRING ':'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0xc7,0x80, // POP_JUMP_IF_FALSE 71
    0xbb, // LOAD_FAST 11
    0x83, // LOAD_CONST_SMALL_INT 3
    0xe5, // BINARY_OP 14 __iadd__
    0xcb, // STORE_FAST 11
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xf3, // BINARY_OP 28 __sub__
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x82, // LOAD_CONST_SMALL_INT 2
    0xf3, // BINARY_OP 28 __sub__
    0xbb, // LOAD_FAST 11
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0xc8, // STORE_FAST 8
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x65, // POP_JUMP_IF_FALSE 37
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x55, // LOAD_SUBSCR
    0x10,0x20, // LOAD_CONST_STRING '.'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x5d, // POP_JUMP_IF_FALSE 29
    0xbb, // LOAD_FAST 11
    0x87, // LOAD_CONST_SMALL_INT 7
    0xe5, // BINARY_OP 14 __iadd__
    0xcb, // STORE_FAST 11
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xf3, // BINARY_OP 28 __sub__
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0xbb, // LOAD_FAST 11
    0x86, // LOAD_CONST_SMALL_INT 6
    0xf3, // BINARY_OP 28 __sub__
    0xbb, // LOAD_FAST 11
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0xc9, // STORE_FAST 9
    0xba, // LOAD_FAST 10
    0xbb, // LOAD_FAST 11
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x02, // LOAD_GLOBAL 'ValueError'
    0x65, // RAISE_OBJ
    0xb5, // LOAD_FAST 5
    0x44,0x63, // POP_JUMP_IF_FALSE 35
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x10,0x08, // LOAD_CONST_STRING 'hours'
    0xb6, // LOAD_FAST 6
    0x10,0x09, // LOAD_CONST_STRING 'minutes'
    0xb7, // LOAD_FAST 7
    0x10,0x0a, // LOAD_CONST_STRING 'seconds'
    0xb8, // LOAD_FAST 8
    0x10,0x0b, // LOAD_CONST_STRING 'microseconds'
    0xb9, // LOAD_FAST 9
    0x34,0x88,0x00, // CALL_FUNCTION 1024
    0xcc, // STORE_FAST 12
    0xb5, // LOAD_FAST 5
    0x10,0x1a, // LOAD_CONST_STRING '-'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0xbc, // LOAD_FAST 12
    0xd1, // UNARY_OP 1 __neg__
    0xcc, // STORE_FAST 12
    0x12,0x0f, // LOAD_GLOBAL 'timezone'
    0xbc, // LOAD_FAST 12
    0x34,0x01, // CALL_FUNCTION 1
    0xcd, // STORE_FAST 13
    0x42,0x42, // JUMP 2
    0x51, // LOAD_CONST_NONE
    0xcd, // STORE_FAST 13
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0xbd, // LOAD_FAST 13
    0x2a,0x05, // BUILD_TUPLE 5
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime__iso2t = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__iso2t,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 516,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 23,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 29,
        .line_info = fun_data_datetime__iso2t + 6,
        .line_info_top = fun_data_datetime__iso2t + 70,
        .opcodes = fun_data_datetime__iso2t + 70,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime__iso2t fun_data_datetime__iso2t[0]
#endif

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime__t2iso
static const byte fun_data_datetime__t2iso[48] = {
    0xc8,0x04,0x1e, // prelude
    0x23,0x81,0x09,0x81,0x0a,0x81,0x0b,0x81,0x0c, // names: _t2iso, td, timespec, dt, tz
    0x90,0xe6,0x23,0x4a,0x26,0x29, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x24, // LOAD_METHOD '_fmt'
    0x23,0x04, // LOAD_CONST_OBJ 4
    0x14,0x25, // LOAD_METHOD 'index'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x36,0x01, // CALL_METHOD 1
    0xc4, // STORE_FAST 4
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0xb4, // LOAD_FAST 4
    0xb3, // LOAD_FAST 3
    0x14,0x26, // LOAD_METHOD 'isoformat'
    0xb2, // LOAD_FAST 2
    0x36,0x01, // CALL_METHOD 1
    0xe5, // BINARY_OP 14 __iadd__
    0xc4, // STORE_FAST 4
    0xb4, // LOAD_FAST 4
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime__t2iso = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__t2iso,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 48,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 4,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 35,
        .line_info = fun_data_datetime__t2iso + 12,
        .line_info_top = fun_data_datetime__t2iso + 18,
        .opcodes = fun_data_datetime__t2iso + 18,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime__t2iso fun_data_datetime__t2iso[0]
#endif

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime_time
static const byte fun_data_datetime_time[208] = {
    0x20,0x50, // prelude
    0x02, // names: time
    0x98,0xef,0x71,0x40,0x69,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x71,0x80,0x0f,0x69,0x64,0x40,0x44,0x64,0x64,0x40,0x64,0x64,0x64,0x64,0x84,0x0e,0x64,0x60,0x64,0x64,0x64, // code info
    0x11,0x7c, // LOAD_NAME '__name__'
    0x16,0x7d, // STORE_NAME '__module__'
    0x10,0x02, // LOAD_CONST_STRING 'time'
    0x16,0x7e, // STORE_NAME '__qualname__'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x2a,0x05, // BUILD_TUPLE 5
    0x2c,0x00, // BUILD_MAP 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x10,0x27, // LOAD_CONST_STRING 'fold'
    0x62, // STORE_MAP
    0x33,0x00, // MAKE_FUNCTION_DEFARGS 0
    0x16,0x2a, // STORE_NAME '__init__'
    0x11,0x81,0x06, // LOAD_NAME 'classmethod'
    0x32,0x01, // MAKE_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x56, // STORE_NAME 'fromisoformat'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x02, // MAKE_FUNCTION 2
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x61, // STORE_NAME 'hour'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x03, // MAKE_FUNCTION 3
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x62, // STORE_NAME 'minute'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x04, // MAKE_FUNCTION 4
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x63, // STORE_NAME 'second'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x05, // MAKE_FUNCTION 5
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x64, // STORE_NAME 'microsecond'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x06, // MAKE_FUNCTION 6
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x0e, // STORE_NAME 'tzinfo'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x07, // MAKE_FUNCTION 7
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x27, // STORE_NAME 'fold'
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x52, // LOAD_CONST_TRUE
    0x2a,0x05, // BUILD_TUPLE 5
    0x2c,0x00, // BUILD_MAP 0
    0x51, // LOAD_CONST_NONE
    0x10,0x27, // LOAD_CONST_STRING 'fold'
    0x62, // STORE_MAP
    0x33,0x08, // MAKE_FUNCTION_DEFARGS 8
    0x16,0x5d, // STORE_NAME 'replace'
    0x10,0x28, // LOAD_CONST_STRING 'auto'
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x09, // MAKE_FUNCTION_DEFARGS 9
    0x16,0x26, // STORE_NAME 'isoformat'
    0x32,0x0a, // MAKE_FUNCTION 10
    0x16,0x2c, // STORE_NAME '__repr__'
    0x11,0x26, // LOAD_NAME 'isoformat'
    0x16,0x40, // STORE_NAME '__str__'
    0x32,0x0b, // MAKE_FUNCTION 11
    0x16,0x3f, // STORE_NAME '__bool__'
    0x32,0x0c, // MAKE_FUNCTION 12
    0x16,0x3a, // STORE_NAME '__eq__'
    0x32,0x0d, // MAKE_FUNCTION 13
    0x16,0x3b, // STORE_NAME '__le__'
    0x32,0x0e, // MAKE_FUNCTION 14
    0x16,0x3c, // STORE_NAME '__lt__'
    0x32,0x0f, // MAKE_FUNCTION 15
    0x16,0x3d, // STORE_NAME '__ge__'
    0x32,0x10, // MAKE_FUNCTION 16
    0x16,0x3e, // STORE_NAME '__gt__'
    0x32,0x11, // MAKE_FUNCTION 17
    0x16,0x65, // STORE_NAME '_sub'
    0x32,0x12, // MAKE_FUNCTION 18
    0x16,0x41, // STORE_NAME '__hash__'
    0x32,0x13, // MAKE_FUNCTION 19
    0x16,0x4c, // STORE_NAME 'utcoffset'
    0x32,0x14, // MAKE_FUNCTION 20
    0x16,0x4d, // STORE_NAME 'dst'
    0x32,0x15, // MAKE_FUNCTION 21
    0x16,0x4b, // STORE_NAME 'tzname'
    0x32,0x16, // MAKE_FUNCTION 22
    0x16,0x4a, // STORE_NAME 'tuple'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time___init__
static const byte fun_data_datetime_time___init__[41] = {
    0xe2,0x8d,0x80,0x81,0x40,0x1a, // prelude
    0x2a,0x81,0x0d,0x61,0x62,0x63,0x64,0x0e,0x27, // names: __init__, self, hour, minute, second, microsecond, tzinfo, fold
    0x90,0xf0,0x2c,0x24, // code info
    0x12,0x1c, // LOAD_GLOBAL '_time'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0xb6, // LOAD_FAST 6
    0x34,0x05, // CALL_FUNCTION 5
    0xb0, // LOAD_FAST 0
    0x18,0x5f, // STORE_ATTR '_td'
    0xb5, // LOAD_FAST 5
    0xb0, // LOAD_FAST 0
    0x18,0x4f, // STORE_ATTR '_tz'
    0xb6, // LOAD_FAST 6
    0xb0, // LOAD_FAST 0
    0x18,0x60, // STORE_ATTR '_fd'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 41,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 0,
        .scope_flags = 8,
        .n_pos_args = 6,
        .n_kwonly_args = 1,
        .n_def_pos_args = 5,
        .qstr_block_name_idx = 42,
        .line_info = fun_data_datetime_time___init__ + 15,
        .line_info_top = fun_data_datetime_time___init__ + 19,
        .opcodes = fun_data_datetime_time___init__ + 19,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time___init__ fun_data_datetime_time___init__[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_fromisoformat
static const byte fun_data_datetime_time_fromisoformat[18] = {
    0x22,0x0c, // prelude
    0x56,0x81,0x1d,0x45, // names: fromisoformat, cls, s
    0x90,0xf6, // code info
    0xb0, // LOAD_FAST 0
    0x12,0x1d, // LOAD_GLOBAL '_iso2t'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_fromisoformat = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_fromisoformat,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 86,
        .line_info = fun_data_datetime_time_fromisoformat + 6,
        .line_info_top = fun_data_datetime_time_fromisoformat + 8,
        .opcodes = fun_data_datetime_time_fromisoformat + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_fromisoformat fun_data_datetime_time_fromisoformat[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_hour
static const byte fun_data_datetime_time_hour[15] = {
    0x11,0x0a, // prelude
    0x61,0x81,0x0d, // names: hour, self
    0x90,0xfa, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_hour = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_hour,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 97,
        .line_info = fun_data_datetime_time_hour + 5,
        .line_info_top = fun_data_datetime_time_hour + 7,
        .opcodes = fun_data_datetime_time_hour + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_hour fun_data_datetime_time_hour[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_minute
static const byte fun_data_datetime_time_minute[15] = {
    0x11,0x0a, // prelude
    0x62,0x81,0x0d, // names: minute, self
    0x90,0xfe, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_minute = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_minute,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 98,
        .line_info = fun_data_datetime_time_minute + 5,
        .line_info_top = fun_data_datetime_time_minute + 7,
        .opcodes = fun_data_datetime_time_minute + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_minute fun_data_datetime_time_minute[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_second
static const byte fun_data_datetime_time_second[15] = {
    0x11,0x0a, // prelude
    0x63,0x81,0x0d, // names: second, self
    0xa0,0x02, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x82, // LOAD_CONST_SMALL_INT 2
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_second = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_second,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 99,
        .line_info = fun_data_datetime_time_second + 5,
        .line_info_top = fun_data_datetime_time_second + 7,
        .opcodes = fun_data_datetime_time_second + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_second fun_data_datetime_time_second[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_microsecond
static const byte fun_data_datetime_time_microsecond[15] = {
    0x11,0x0a, // prelude
    0x64,0x81,0x0d, // names: microsecond, self
    0xa0,0x06, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x83, // LOAD_CONST_SMALL_INT 3
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_microsecond = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_microsecond,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 100,
        .line_info = fun_data_datetime_time_microsecond + 5,
        .line_info_top = fun_data_datetime_time_microsecond + 7,
        .opcodes = fun_data_datetime_time_microsecond + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_microsecond fun_data_datetime_time_microsecond[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_tzinfo
static const byte fun_data_datetime_time_tzinfo[11] = {
    0x09,0x0a, // prelude
    0x0e,0x81,0x0d, // names: tzinfo, self
    0xa0,0x0a, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_tzinfo = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_tzinfo,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 11,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 14,
        .line_info = fun_data_datetime_time_tzinfo + 5,
        .line_info_top = fun_data_datetime_time_tzinfo + 7,
        .opcodes = fun_data_datetime_time_tzinfo + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_tzinfo fun_data_datetime_time_tzinfo[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_fold
static const byte fun_data_datetime_time_fold[11] = {
    0x09,0x0a, // prelude
    0x27,0x81,0x0d, // names: fold, self
    0xa0,0x0e, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x60, // LOAD_ATTR '_fd'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_fold = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_fold,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 11,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 39,
        .line_info = fun_data_datetime_time_fold + 5,
        .line_info_top = fun_data_datetime_time_fold + 7,
        .opcodes = fun_data_datetime_time_fold + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_fold fun_data_datetime_time_fold[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_replace
static const byte fun_data_datetime_time_replace[99] = {
    0xa2,0x9d,0x80,0x81,0x40,0x30, // prelude
    0x5d,0x81,0x0d,0x61,0x62,0x63,0x64,0x0e,0x27, // names: replace, self, hour, minute, second, microsecond, tzinfo, fold
    0xa0,0x13,0x2d,0x25,0x22,0x25,0x22,0x25,0x22,0x25,0x22,0x25,0x22,0x25,0x22, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x30,0x06, // UNPACK_SEQUENCE 6
    0xc7, // STORE_FAST 7
    0xc8, // STORE_FAST 8
    0xc9, // STORE_FAST 9
    0xca, // STORE_FAST 10
    0xcb, // STORE_FAST 11
    0xcc, // STORE_FAST 12
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb7, // LOAD_FAST 7
    0xc1, // STORE_FAST 1
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb8, // LOAD_FAST 8
    0xc2, // STORE_FAST 2
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb9, // LOAD_FAST 9
    0xc3, // STORE_FAST 3
    0xb4, // LOAD_FAST 4
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xba, // LOAD_FAST 10
    0xc4, // STORE_FAST 4
    0xb5, // LOAD_FAST 5
    0x52, // LOAD_CONST_TRUE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xbb, // LOAD_FAST 11
    0xc5, // STORE_FAST 5
    0xb6, // LOAD_FAST 6
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xbc, // LOAD_FAST 12
    0xc6, // STORE_FAST 6
    0x12,0x02, // LOAD_GLOBAL 'time'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0xb5, // LOAD_FAST 5
    0x10,0x27, // LOAD_CONST_STRING 'fold'
    0xb6, // LOAD_FAST 6
    0x34,0x82,0x05, // CALL_FUNCTION 261
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_replace = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_replace,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 99,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 21,
        .n_exc_stack = 0,
        .scope_flags = 8,
        .n_pos_args = 6,
        .n_kwonly_args = 1,
        .n_def_pos_args = 5,
        .qstr_block_name_idx = 93,
        .line_info = fun_data_datetime_time_replace + 15,
        .line_info_top = fun_data_datetime_time_replace + 30,
        .opcodes = fun_data_datetime_time_replace + 30,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_replace fun_data_datetime_time_replace[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_isoformat
static const byte fun_data_datetime_time_isoformat[23] = {
    0xb2,0x01,0x0e, // prelude
    0x26,0x81,0x0d,0x81,0x0a, // names: isoformat, self, timespec
    0xa0,0x23, // code info
    0x12,0x23, // LOAD_GLOBAL '_t2iso'
    0xb0, // LOAD_FAST 0
    0x13,0x5f, // LOAD_ATTR '_td'
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x34,0x04, // CALL_FUNCTION 4
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_isoformat = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_isoformat,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 38,
        .line_info = fun_data_datetime_time_isoformat + 8,
        .line_info_top = fun_data_datetime_time_isoformat + 10,
        .opcodes = fun_data_datetime_time_isoformat + 10,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_isoformat fun_data_datetime_time_isoformat[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time___repr__
static const byte fun_data_datetime_time___repr__[31] = {
    0x29,0x0c, // prelude
    0x2c,0x81,0x0d, // names: __repr__, self
    0xa0,0x26,0x24, // code info
    0x23,0x09, // LOAD_CONST_OBJ 9
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb0, // LOAD_FAST 0
    0x13,0x5f, // LOAD_ATTR '_td'
    0x13,0x2b, // LOAD_ATTR '_us'
    0x12,0x81,0x1b, // LOAD_GLOBAL 'repr'
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x34,0x01, // CALL_FUNCTION 1
    0xb0, // LOAD_FAST 0
    0x13,0x60, // LOAD_ATTR '_fd'
    0x36,0x03, // CALL_METHOD 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time___repr__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time___repr__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 31,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 44,
        .line_info = fun_data_datetime_time___repr__ + 5,
        .line_info_top = fun_data_datetime_time___repr__ + 8,
        .opcodes = fun_data_datetime_time___repr__ + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time___repr__ fun_data_datetime_time___repr__[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time___bool__
static const byte fun_data_datetime_time___bool__[9] = {
    0x09,0x0a, // prelude
    0x3f,0x81,0x0d, // names: __bool__, self
    0xa0,0x2d, // code info
    0x52, // LOAD_CONST_TRUE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time___bool__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time___bool__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 9,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 63,
        .line_info = fun_data_datetime_time___bool__ + 5,
        .line_info_top = fun_data_datetime_time___bool__ + 7,
        .opcodes = fun_data_datetime_time___bool__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time___bool__ fun_data_datetime_time___bool__[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time___eq__
static const byte fun_data_datetime_time___eq__[35] = {
    0x22,0x12, // prelude
    0x3a,0x81,0x0d,0x81,0x11, // names: __eq__, self, other
    0xa0,0x30,0x2d,0x22, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xd9, // BINARY_OP 2 __eq__
    0xb1, // LOAD_FAST 1
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xd9, // BINARY_OP 2 __eq__
    0xee, // BINARY_OP 23 __xor__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x50, // LOAD_CONST_FALSE
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x14,0x65, // LOAD_METHOD '_sub'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time___eq__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time___eq__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 35,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 58,
        .line_info = fun_data_datetime_time___eq__ + 7,
        .line_info_top = fun_data_datetime_time___eq__ + 11,
        .opcodes = fun_data_datetime_time___eq__ + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time___eq__ fun_data_datetime_time___eq__[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time___le__
static const byte fun_data_datetime_time___le__[18] = {
    0x22,0x0e, // prelude
    0x3b,0x81,0x0d,0x81,0x11, // names: __le__, self, other
    0xa0,0x35, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x65, // LOAD_METHOD '_sub'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xda, // BINARY_OP 3 __le__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time___le__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time___le__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 59,
        .line_info = fun_data_datetime_time___le__ + 7,
        .line_info_top = fun_data_datetime_time___le__ + 9,
        .opcodes = fun_data_datetime_time___le__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time___le__ fun_data_datetime_time___le__[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time___lt__
static const byte fun_data_datetime_time___lt__[18] = {
    0x22,0x0e, // prelude
    0x3c,0x81,0x0d,0x81,0x11, // names: __lt__, self, other
    0xa0,0x38, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x65, // LOAD_METHOD '_sub'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time___lt__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time___lt__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 60,
        .line_info = fun_data_datetime_time___lt__ + 7,
        .line_info_top = fun_data_datetime_time___lt__ + 9,
        .opcodes = fun_data_datetime_time___lt__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time___lt__ fun_data_datetime_time___lt__[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time___ge__
static const byte fun_data_datetime_time___ge__[18] = {
    0x22,0x0e, // prelude
    0x3d,0x81,0x0d,0x81,0x11, // names: __ge__, self, other
    0xa0,0x3b, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x65, // LOAD_METHOD '_sub'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xdb, // BINARY_OP 4 __ge__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time___ge__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time___ge__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 61,
        .line_info = fun_data_datetime_time___ge__ + 7,
        .line_info_top = fun_data_datetime_time___ge__ + 9,
        .opcodes = fun_data_datetime_time___ge__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time___ge__ fun_data_datetime_time___ge__[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time___gt__
static const byte fun_data_datetime_time___gt__[18] = {
    0x22,0x0e, // prelude
    0x3e,0x81,0x0d,0x81,0x11, // names: __gt__, self, other
    0xa0,0x3e, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x65, // LOAD_METHOD '_sub'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd8, // BINARY_OP 1 __gt__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time___gt__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time___gt__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 62,
        .line_info = fun_data_datetime_time___gt__ + 7,
        .line_info_top = fun_data_datetime_time___gt__ + 9,
        .opcodes = fun_data_datetime_time___gt__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time___gt__ fun_data_datetime_time___gt__[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time__sub
static const byte fun_data_datetime_time__sub[90] = {
    0x4a,0x24, // prelude
    0x65,0x81,0x0d,0x81,0x11, // names: _sub, self, other
    0xa0,0x41,0x24,0x2b,0x24,0x26,0x26,0x26,0x28,0x28,0x25,0x24,0x24, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xb1, // LOAD_FAST 1
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xee, // BINARY_OP 23 __xor__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x1f, // LOAD_GLOBAL 'TypeError'
    0x65, // RAISE_OBJ
    0xb0, // LOAD_FAST 0
    0x13,0x5f, // LOAD_ATTR '_td'
    0x13,0x2b, // LOAD_ATTR '_us'
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0x13,0x5f, // LOAD_ATTR '_td'
    0x13,0x2b, // LOAD_ATTR '_us'
    0xc4, // STORE_FAST 4
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x5d, // POP_JUMP_IF_FALSE 29
    0xb0, // LOAD_FAST 0
    0x14,0x4c, // LOAD_METHOD 'utcoffset'
    0x36,0x00, // CALL_METHOD 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xc5, // STORE_FAST 5
    0xb1, // LOAD_FAST 1
    0x14,0x4c, // LOAD_METHOD 'utcoffset'
    0x36,0x00, // CALL_METHOD 0
    0x13,0x2b, // LOAD_ATTR '_us'
    0xc6, // STORE_FAST 6
    0xb5, // LOAD_FAST 5
    0xb6, // LOAD_FAST 6
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb3, // LOAD_FAST 3
    0xb5, // LOAD_FAST 5
    0xe6, // BINARY_OP 15 __isub__
    0xc3, // STORE_FAST 3
    0xb4, // LOAD_FAST 4
    0xb6, // LOAD_FAST 6
    0xe6, // BINARY_OP 15 __isub__
    0xc4, // STORE_FAST 4
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0xf3, // BINARY_OP 28 __sub__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time__sub = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time__sub,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 90,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 101,
        .line_info = fun_data_datetime_time__sub + 7,
        .line_info_top = fun_data_datetime_time__sub + 20,
        .opcodes = fun_data_datetime_time__sub + 20,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time__sub fun_data_datetime_time__sub[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time___hash__
static const byte fun_data_datetime_time___hash__[39] = {
    0x19,0x0e, // prelude
    0x41,0x81,0x0d, // names: __hash__, self
    0xa0,0x4f,0x4a,0x30, // code info
    0x12,0x81,0x13, // LOAD_GLOBAL 'hasattr'
    0xb0, // LOAD_FAST 0
    0x10,0x42, // LOAD_CONST_STRING '_hash'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x50, // POP_JUMP_IF_TRUE 16
    0x12,0x81,0x14, // LOAD_GLOBAL 'hash'
    0xb0, // LOAD_FAST 0
    0x13,0x5f, // LOAD_ATTR '_td'
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x2a,0x02, // BUILD_TUPLE 2
    0x34,0x01, // CALL_FUNCTION 1
    0xb0, // LOAD_FAST 0
    0x18,0x42, // STORE_ATTR '_hash'
    0xb0, // LOAD_FAST 0
    0x13,0x42, // LOAD_ATTR '_hash'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time___hash__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time___hash__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 39,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 65,
        .line_info = fun_data_datetime_time___hash__ + 5,
        .line_info_top = fun_data_datetime_time___hash__ + 9,
        .opcodes = fun_data_datetime_time___hash__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time___hash__ fun_data_datetime_time___hash__[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_utcoffset
static const byte fun_data_datetime_time_utcoffset[25] = {
    0x19,0x0a, // prelude
    0x4c,0x81,0x0d, // names: utcoffset, self
    0xa0,0x55, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x14,0x4c, // LOAD_METHOD 'utcoffset'
    0x51, // LOAD_CONST_NONE
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_utcoffset = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_utcoffset,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 76,
        .line_info = fun_data_datetime_time_utcoffset + 5,
        .line_info_top = fun_data_datetime_time_utcoffset + 7,
        .opcodes = fun_data_datetime_time_utcoffset + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_utcoffset fun_data_datetime_time_utcoffset[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_dst
static const byte fun_data_datetime_time_dst[25] = {
    0x19,0x0a, // prelude
    0x4d,0x81,0x0d, // names: dst, self
    0xa0,0x58, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x14,0x4d, // LOAD_METHOD 'dst'
    0x51, // LOAD_CONST_NONE
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_dst = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_dst,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 77,
        .line_info = fun_data_datetime_time_dst + 5,
        .line_info_top = fun_data_datetime_time_dst + 7,
        .opcodes = fun_data_datetime_time_dst + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_dst fun_data_datetime_time_dst[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_tzname
static const byte fun_data_datetime_time_tzname[25] = {
    0x19,0x0a, // prelude
    0x4b,0x81,0x0d, // names: tzname, self
    0xa0,0x5b, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x14,0x4b, // LOAD_METHOD 'tzname'
    0x51, // LOAD_CONST_NONE
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_tzname = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_tzname,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 75,
        .line_info = fun_data_datetime_time_tzname + 5,
        .line_info_top = fun_data_datetime_time_tzname + 7,
        .opcodes = fun_data_datetime_time_tzname + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_tzname fun_data_datetime_time_tzname[0]
#endif

// child of datetime_time
// frozen bytecode for file datetime.py, scope datetime_time_tuple
static const byte fun_data_datetime_time_tuple[35] = {
    0x59,0x0c, // prelude
    0x4a,0x81,0x0d, // names: tuple, self
    0xa0,0x5e,0x2e, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x5f, // LOAD_ATTR '_td'
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x30,0x05, // UNPACK_SEQUENCE 5
    0xc1, // STORE_FAST 1
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0xc4, // STORE_FAST 4
    0xc5, // STORE_FAST 5
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0xb5, // LOAD_FAST 5
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0xb0, // LOAD_FAST 0
    0x13,0x60, // LOAD_ATTR '_fd'
    0x2a,0x06, // BUILD_TUPLE 6
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_time_tuple = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time_tuple,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 35,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 12,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 74,
        .line_info = fun_data_datetime_time_tuple + 5,
        .line_info_top = fun_data_datetime_time_tuple + 8,
        .opcodes = fun_data_datetime_time_tuple + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_time_tuple fun_data_datetime_time_tuple[0]
#endif

static const mp_raw_code_t *const children_datetime_time[] = {
    (const mp_raw_code_t *)&proto_fun_datetime_time___init__,
    (const mp_raw_code_t *)&proto_fun_datetime_time_fromisoformat,
    (const mp_raw_code_t *)&proto_fun_datetime_time_hour,
    (const mp_raw_code_t *)&proto_fun_datetime_time_minute,
    (const mp_raw_code_t *)&proto_fun_datetime_time_second,
    (const mp_raw_code_t *)&proto_fun_datetime_time_microsecond,
    (const mp_raw_code_t *)&proto_fun_datetime_time_tzinfo,
    (const mp_raw_code_t *)&proto_fun_datetime_time_fold,
    (const mp_raw_code_t *)&proto_fun_datetime_time_replace,
    (const mp_raw_code_t *)&proto_fun_datetime_time_isoformat,
    (const mp_raw_code_t *)&proto_fun_datetime_time___repr__,
    (const mp_raw_code_t *)&proto_fun_datetime_time___bool__,
    (const mp_raw_code_t *)&proto_fun_datetime_time___eq__,
    (const mp_raw_code_t *)&proto_fun_datetime_time___le__,
    (const mp_raw_code_t *)&proto_fun_datetime_time___lt__,
    (const mp_raw_code_t *)&proto_fun_datetime_time___ge__,
    (const mp_raw_code_t *)&proto_fun_datetime_time___gt__,
    (const mp_raw_code_t *)&proto_fun_datetime_time__sub,
    (const mp_raw_code_t *)&proto_fun_datetime_time___hash__,
    (const mp_raw_code_t *)&proto_fun_datetime_time_utcoffset,
    (const mp_raw_code_t *)&proto_fun_datetime_time_dst,
    (const mp_raw_code_t *)&proto_fun_datetime_time_tzname,
    (const mp_raw_code_t *)&proto_fun_datetime_time_tuple,
};

static const mp_raw_code_truncated_t proto_fun_datetime_time = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_time,
    .children = (void *)&children_datetime_time,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 208,
    .n_children = 23,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 2,
        .line_info = fun_data_datetime_time + 3,
        .line_info_top = fun_data_datetime_time + 42,
        .opcodes = fun_data_datetime_time + 42,
    },
    #endif
    #endif
};

// child of datetime__lt_module_gt_
// frozen bytecode for file datetime.py, scope datetime_datetime
static const byte fun_data_datetime_datetime[372] = {
    0x38,0x94,0x02, // prelude
    0x12, // names: datetime
    0xa8,0x68,0x71,0x60,0x40,0x8d,0x10,0x6d,0x20,0x69,0x20,0x89,0x08,0x6d,0x60,0x68,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x68,0x20,0x64,0x60,0x84,0x09,0x84,0x12,0x64,0x40,0x64,0x64,0x64,0x64,0x84,0x0f,0x64,0x64,0x64,0x74,0x80,0x1f,0x88,0x0d,0x84,0x1f,0x64,0x64,0x64,0x84,0x09,0x64,0x64,0x60,0x64,0x64,0x6b,0x84,0x07,0x64,0x64,0x40, // code info
    0x11,0x7c, // LOAD_NAME '__name__'
    0x16,0x7d, // STORE_NAME '__module__'
    0x10,0x12, // LOAD_CONST_STRING 'datetime'
    0x16,0x7e, // STORE_NAME '__qualname__'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x2a,0x05, // BUILD_TUPLE 5
    0x2c,0x00, // BUILD_MAP 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x10,0x27, // LOAD_CONST_STRING 'fold'
    0x62, // STORE_MAP
    0x33,0x00, // MAKE_FUNCTION_DEFARGS 0
    0x16,0x2a, // STORE_NAME '__init__'
    0x11,0x81,0x06, // LOAD_NAME 'classmethod'
    0x51, // LOAD_CONST_NONE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x01, // MAKE_FUNCTION_DEFARGS 1
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x53, // STORE_NAME 'fromtimestamp'
    0x11,0x81,0x06, // LOAD_NAME 'classmethod'
    0x51, // LOAD_CONST_NONE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x02, // MAKE_FUNCTION_DEFARGS 2
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x68, // STORE_NAME 'now'
    0x11,0x81,0x06, // LOAD_NAME 'classmethod'
    0x32,0x03, // MAKE_FUNCTION 3
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x55, // STORE_NAME 'fromordinal'
    0x11,0x81,0x06, // LOAD_NAME 'classmethod'
    0x32,0x04, // MAKE_FUNCTION 4
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x56, // STORE_NAME 'fromisoformat'
    0x11,0x81,0x06, // LOAD_NAME 'classmethod'
    0x51, // LOAD_CONST_NONE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x05, // MAKE_FUNCTION_DEFARGS 5
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x69, // STORE_NAME 'combine'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x06, // MAKE_FUNCTION 6
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x57, // STORE_NAME 'year'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x07, // MAKE_FUNCTION 7
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x58, // STORE_NAME 'month'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x08, // MAKE_FUNCTION 8
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x59, // STORE_NAME 'day'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x09, // MAKE_FUNCTION 9
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x61, // STORE_NAME 'hour'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x0a, // MAKE_FUNCTION 10
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x62, // STORE_NAME 'minute'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x0b, // MAKE_FUNCTION 11
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x63, // STORE_NAME 'second'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x0c, // MAKE_FUNCTION 12
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x64, // STORE_NAME 'microsecond'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x0d, // MAKE_FUNCTION 13
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x0e, // STORE_NAME 'tzinfo'
    0x11,0x7f, // LOAD_NAME 'property'
    0x32,0x0e, // MAKE_FUNCTION 14
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x27, // STORE_NAME 'fold'
    0x32,0x0f, // MAKE_FUNCTION 15
    0x16,0x30, // STORE_NAME '__add__'
    0x32,0x10, // MAKE_FUNCTION 16
    0x16,0x31, // STORE_NAME '__sub__'
    0x32,0x11, // MAKE_FUNCTION 17
    0x16,0x65, // STORE_NAME '_sub'
    0x32,0x12, // MAKE_FUNCTION 18
    0x16,0x3a, // STORE_NAME '__eq__'
    0x32,0x13, // MAKE_FUNCTION 19
    0x16,0x3b, // STORE_NAME '__le__'
    0x32,0x14, // MAKE_FUNCTION 20
    0x16,0x3c, // STORE_NAME '__lt__'
    0x32,0x15, // MAKE_FUNCTION 21
    0x16,0x3d, // STORE_NAME '__ge__'
    0x32,0x16, // MAKE_FUNCTION 22
    0x16,0x3e, // STORE_NAME '__gt__'
    0x32,0x17, // MAKE_FUNCTION 23
    0x16,0x6a, // STORE_NAME '_cmp'
    0x32,0x18, // MAKE_FUNCTION 24
    0x16,0x11, // STORE_NAME 'date'
    0x32,0x19, // MAKE_FUNCTION 25
    0x16,0x02, // STORE_NAME 'time'
    0x32,0x1a, // MAKE_FUNCTION 26
    0x16,0x6b, // STORE_NAME 'timetz'
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x52, // LOAD_CONST_TRUE
    0x2a,0x08, // BUILD_TUPLE 8
    0x2c,0x00, // BUILD_MAP 0
    0x51, // LOAD_CONST_NONE
    0x10,0x27, // LOAD_CONST_STRING 'fold'
    0x62, // STORE_MAP
    0x33,0x1b, // MAKE_FUNCTION_DEFARGS 27
    0x16,0x5d, // STORE_NAME 'replace'
    0x51, // LOAD_CONST_NONE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x1c, // MAKE_FUNCTION_DEFARGS 28
    0x16,0x6c, // STORE_NAME 'astimezone'
    0x32,0x1d, // MAKE_FUNCTION 29
    0x16,0x6d, // STORE_NAME '_mktime'
    0x32,0x1e, // MAKE_FUNCTION 30
    0x16,0x4c, // STORE_NAME 'utcoffset'
    0x32,0x1f, // MAKE_FUNCTION 31
    0x16,0x4d, // STORE_NAME 'dst'
    0x32,0x20, // MAKE_FUNCTION 32
    0x16,0x4b, // STORE_NAME 'tzname'
    0x32,0x21, // MAKE_FUNCTION 33
    0x16,0x5b, // STORE_NAME 'timetuple'
    0x32,0x22, // MAKE_FUNCTION 34
    0x16,0x5a, // STORE_NAME 'toordinal'
    0x32,0x23, // MAKE_FUNCTION 35
    0x16,0x6e, // STORE_NAME 'timestamp'
    0x32,0x24, // MAKE_FUNCTION 36
    0x16,0x5c, // STORE_NAME 'weekday'
    0x32,0x25, // MAKE_FUNCTION 37
    0x16,0x5e, // STORE_NAME 'isoweekday'
    0x10,0x29, // LOAD_CONST_STRING 'T'
    0x10,0x28, // LOAD_CONST_STRING 'auto'
    0x2a,0x02, // BUILD_TUPLE 2
    0x53, // LOAD_NULL
    0x33,0x26, // MAKE_FUNCTION_DEFARGS 38
    0x16,0x26, // STORE_NAME 'isoformat'
    0x32,0x27, // MAKE_FUNCTION 39
    0x16,0x2c, // STORE_NAME '__repr__'
    0x32,0x28, // MAKE_FUNCTION 40
    0x16,0x40, // STORE_NAME '__str__'
    0x32,0x29, // MAKE_FUNCTION 41
    0x16,0x41, // STORE_NAME '__hash__'
    0x32,0x2a, // MAKE_FUNCTION 42
    0x16,0x4a, // STORE_NAME 'tuple'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___init__
static const byte fun_data_datetime_datetime___init__[55] = {
    0xf9,0x89,0x84,0x81,0x40,0x22, // prelude
    0x2a,0x81,0x0d,0x57,0x58,0x59,0x61,0x62,0x63,0x64,0x0e,0x27, // names: __init__, self, year, month, day, hour, minute, second, microsecond, tzinfo, fold
    0xa0,0x6b,0x2a,0x2c,0x24, // code info
    0x12,0x18, // LOAD_GLOBAL '_date'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0x34,0x03, // CALL_FUNCTION 3
    0xb0, // LOAD_FAST 0
    0x18,0x66, // STORE_ATTR '_d'
    0x12,0x1c, // LOAD_GLOBAL '_time'
    0xb4, // LOAD_FAST 4
    0xb5, // LOAD_FAST 5
    0xb6, // LOAD_FAST 6
    0xb7, // LOAD_FAST 7
    0xb9, // LOAD_FAST 9
    0x34,0x05, // CALL_FUNCTION 5
    0xb0, // LOAD_FAST 0
    0x18,0x67, // STORE_ATTR '_t'
    0xb8, // LOAD_FAST 8
    0xb0, // LOAD_FAST 0
    0x18,0x4f, // STORE_ATTR '_tz'
    0xb9, // LOAD_FAST 9
    0xb0, // LOAD_FAST 0
    0x18,0x60, // STORE_ATTR '_fd'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 55,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 16,
        .n_exc_stack = 0,
        .scope_flags = 8,
        .n_pos_args = 9,
        .n_kwonly_args = 1,
        .n_def_pos_args = 5,
        .qstr_block_name_idx = 42,
        .line_info = fun_data_datetime_datetime___init__ + 18,
        .line_info_top = fun_data_datetime_datetime___init__ + 23,
        .opcodes = fun_data_datetime_datetime___init__ + 23,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___init__ fun_data_datetime_datetime___init__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_fromtimestamp
static const byte fun_data_datetime_datetime_fromtimestamp[187] = {
    0xe3,0x01,0x28, // prelude
    0x53,0x81,0x1d,0x81,0x1e,0x81,0x0c, // names: fromtimestamp, cls, ts, tz
    0xa0,0x72,0x2b,0x59,0x22,0x26,0x36,0x1f,0x24,0x3a,0x46,0x36,0x27, // code info
    0x12,0x81,0x12, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x81,0x20, // LOAD_GLOBAL 'float'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x59, // POP_JUMP_IF_FALSE 25
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0x12,0x81,0x10, // LOAD_GLOBAL 'round'
    0xb1, // LOAD_FAST 1
    0x22,0xbd,0x84,0x40, // LOAD_CONST_SMALL_INT 1000000
    0xf4, // BINARY_OP 29 __mul__
    0x34,0x01, // CALL_FUNCTION 1
    0x22,0xbd,0x84,0x40, // LOAD_CONST_SMALL_INT 1000000
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc1, // STORE_FAST 1
    0xc3, // STORE_FAST 3
    0x42,0x42, // JUMP 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc3, // STORE_FAST 3
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0xd9,0x80, // POP_JUMP_IF_FALSE 89
    0xb0, // LOAD_FAST 0
    0x12,0x74, // LOAD_GLOBAL '_localtime'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x51, // LOAD_CONST_NONE
    0x86, // LOAD_CONST_SMALL_INT 6
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x10,0x64, // LOAD_CONST_STRING 'microsecond'
    0xb3, // LOAD_FAST 3
    0x10,0x0e, // LOAD_CONST_STRING 'tzinfo'
    0xb2, // LOAD_FAST 2
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x84,0x01, // CALL_FUNCTION_VAR_KW 513
    0xc4, // STORE_FAST 4
    0xb4, // LOAD_FAST 4
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x12,0x74, // LOAD_GLOBAL '_localtime'
    0xb1, // LOAD_FAST 1
    0x22,0x85,0xa3,0x00, // LOAD_CONST_SMALL_INT 86400
    0xf3, // BINARY_OP 28 __sub__
    0x34,0x01, // CALL_FUNCTION 1
    0x51, // LOAD_CONST_NONE
    0x86, // LOAD_CONST_SMALL_INT 6
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0xf3, // BINARY_OP 28 __sub__
    0x13,0x2b, // LOAD_ATTR '_us'
    0x22,0xbd,0x84,0x40, // LOAD_CONST_SMALL_INT 1000000
    0xf6, // BINARY_OP 31 __floordiv__
    0x22,0x85,0xa3,0x00, // LOAD_CONST_SMALL_INT 86400
    0xf3, // BINARY_OP 28 __sub__
    0xc5, // STORE_FAST 5
    0xb5, // LOAD_FAST 5
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x59, // POP_JUMP_IF_FALSE 25
    0xb4, // LOAD_FAST 4
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x12,0x74, // LOAD_GLOBAL '_localtime'
    0xb1, // LOAD_FAST 1
    0xb5, // LOAD_FAST 5
    0xf2, // BINARY_OP 27 __add__
    0x34,0x01, // CALL_FUNCTION 1
    0x51, // LOAD_CONST_NONE
    0x86, // LOAD_CONST_SMALL_INT 6
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x81, // LOAD_CONST_SMALL_INT 1
    0xb4, // LOAD_FAST 4
    0x18,0x60, // STORE_ATTR '_fd'
    0x42,0x5d, // JUMP 29
    0xb0, // LOAD_FAST 0
    0x12,0x73, // LOAD_GLOBAL '_gmtime'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x51, // LOAD_CONST_NONE
    0x86, // LOAD_CONST_SMALL_INT 6
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x10,0x64, // LOAD_CONST_STRING 'microsecond'
    0xb3, // LOAD_FAST 3
    0x10,0x0e, // LOAD_CONST_STRING 'tzinfo'
    0xb2, // LOAD_FAST 2
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x84,0x01, // CALL_FUNCTION_VAR_KW 513
    0xc4, // STORE_FAST 4
    0xb2, // LOAD_FAST 2
    0x14,0x4e, // LOAD_METHOD 'fromutc'
    0xb4, // LOAD_FAST 4
    0x36,0x01, // CALL_METHOD 1
    0xc4, // STORE_FAST 4
    0xb4, // LOAD_FAST 4
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_fromtimestamp = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_fromtimestamp,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 187,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 83,
        .line_info = fun_data_datetime_datetime_fromtimestamp + 10,
        .line_info_top = fun_data_datetime_datetime_fromtimestamp + 23,
        .opcodes = fun_data_datetime_datetime_fromtimestamp + 23,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_fromtimestamp fun_data_datetime_datetime_fromtimestamp[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_now
static const byte fun_data_datetime_datetime_now[21] = {
    0xaa,0x01,0x0e, // prelude
    0x68,0x81,0x1d,0x81,0x0c, // names: now, cls, tz
    0xa0,0x82, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x53, // LOAD_METHOD 'fromtimestamp'
    0x12,0x75, // LOAD_GLOBAL '_epoch_time'
    0x34,0x00, // CALL_FUNCTION 0
    0xb1, // LOAD_FAST 1
    0x36,0x02, // CALL_METHOD 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_now = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_now,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 21,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 104,
        .line_info = fun_data_datetime_datetime_now + 8,
        .line_info_top = fun_data_datetime_datetime_now + 10,
        .opcodes = fun_data_datetime_datetime_now + 10,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_now fun_data_datetime_datetime_now[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_fromordinal
static const byte fun_data_datetime_datetime_fromordinal[15] = {
    0x2a,0x0c, // prelude
    0x55,0x81,0x1d,0x7a, // names: fromordinal, cls, n
    0xa0,0x86, // code info
    0xb0, // LOAD_FAST 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb1, // LOAD_FAST 1
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_fromordinal = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_fromordinal,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 85,
        .line_info = fun_data_datetime_datetime_fromordinal + 6,
        .line_info_top = fun_data_datetime_datetime_fromordinal + 8,
        .opcodes = fun_data_datetime_datetime_fromordinal + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_fromordinal fun_data_datetime_datetime_fromordinal[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_fromisoformat
static const byte fun_data_datetime_datetime_fromisoformat[53] = {
    0x3a,0x14, // prelude
    0x56,0x81,0x1d,0x45, // names: fromisoformat, cls, s
    0xa0,0x8a,0x26,0x2a,0x26,0x2b, // code info
    0x12,0x19, // LOAD_GLOBAL '_iso2d'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xc2, // STORE_FAST 2
    0x12,0x81,0x03, // LOAD_GLOBAL 'len'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x8c, // LOAD_CONST_SMALL_INT 12
    0xda, // BINARY_OP 3 __le__
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0xb0, // LOAD_FAST 0
    0xb2, // LOAD_FAST 2
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0x63, // RETURN_VALUE
    0x12,0x1d, // LOAD_GLOBAL '_iso2t'
    0xb1, // LOAD_FAST 1
    0x8b, // LOAD_CONST_SMALL_INT 11
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0xc3, // STORE_FAST 3
    0xb0, // LOAD_FAST 0
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xf2, // BINARY_OP 27 __add__
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_fromisoformat = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_fromisoformat,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 53,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 86,
        .line_info = fun_data_datetime_datetime_fromisoformat + 6,
        .line_info_top = fun_data_datetime_datetime_fromisoformat + 12,
        .opcodes = fun_data_datetime_datetime_fromisoformat + 12,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_fromisoformat fun_data_datetime_datetime_fromisoformat[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_combine
static const byte fun_data_datetime_datetime_combine[43] = {
    0xf0,0x05,0x12, // prelude
    0x69,0x81,0x1d,0x11,0x02,0x0e, // names: combine, cls, date, time, tzinfo
    0xa0,0x92,0x23, // code info
    0xb0, // LOAD_FAST 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb1, // LOAD_FAST 1
    0x14,0x5a, // LOAD_METHOD 'toordinal'
    0x36,0x00, // CALL_METHOD 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb2, // LOAD_FAST 2
    0x13,0x5f, // LOAD_ATTR '_td'
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb3, // LOAD_FAST 3
    0x45,0x03, // JUMP_IF_TRUE_OR_POP 3
    0xb2, // LOAD_FAST 2
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x10,0x27, // LOAD_CONST_STRING 'fold'
    0xb2, // LOAD_FAST 2
    0x13,0x60, // LOAD_ATTR '_fd'
    0x34,0x82,0x08, // CALL_FUNCTION 264
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_combine = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_combine,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 43,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 15,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 4,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 105,
        .line_info = fun_data_datetime_datetime_combine + 9,
        .line_info_top = fun_data_datetime_datetime_combine + 12,
        .opcodes = fun_data_datetime_datetime_combine + 12,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_combine fun_data_datetime_datetime_combine[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_year
static const byte fun_data_datetime_datetime_year[17] = {
    0x11,0x0a, // prelude
    0x57,0x81,0x0d, // names: year, self
    0xa0,0x98, // code info
    0x12,0x17, // LOAD_GLOBAL '_o2ymd'
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0x34,0x01, // CALL_FUNCTION 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_year = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_year,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 87,
        .line_info = fun_data_datetime_datetime_year + 5,
        .line_info_top = fun_data_datetime_datetime_year + 7,
        .opcodes = fun_data_datetime_datetime_year + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_year fun_data_datetime_datetime_year[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_month
static const byte fun_data_datetime_datetime_month[17] = {
    0x11,0x0a, // prelude
    0x58,0x81,0x0d, // names: month, self
    0xa0,0x9c, // code info
    0x12,0x17, // LOAD_GLOBAL '_o2ymd'
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0x34,0x01, // CALL_FUNCTION 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_month = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_month,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 88,
        .line_info = fun_data_datetime_datetime_month + 5,
        .line_info_top = fun_data_datetime_datetime_month + 7,
        .opcodes = fun_data_datetime_datetime_month + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_month fun_data_datetime_datetime_month[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_day
static const byte fun_data_datetime_datetime_day[17] = {
    0x11,0x0a, // prelude
    0x59,0x81,0x0d, // names: day, self
    0xa0,0xa0, // code info
    0x12,0x17, // LOAD_GLOBAL '_o2ymd'
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0x34,0x01, // CALL_FUNCTION 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_day = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_day,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 89,
        .line_info = fun_data_datetime_datetime_day + 5,
        .line_info_top = fun_data_datetime_datetime_day + 7,
        .opcodes = fun_data_datetime_datetime_day + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_day fun_data_datetime_datetime_day[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_hour
static const byte fun_data_datetime_datetime_hour[17] = {
    0x11,0x0a, // prelude
    0x61,0x81,0x0d, // names: hour, self
    0xa0,0xa4, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x67, // LOAD_ATTR '_t'
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_hour = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_hour,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 97,
        .line_info = fun_data_datetime_datetime_hour + 5,
        .line_info_top = fun_data_datetime_datetime_hour + 7,
        .opcodes = fun_data_datetime_datetime_hour + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_hour fun_data_datetime_datetime_hour[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_minute
static const byte fun_data_datetime_datetime_minute[17] = {
    0x11,0x0a, // prelude
    0x62,0x81,0x0d, // names: minute, self
    0xa0,0xa8, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x67, // LOAD_ATTR '_t'
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x82, // LOAD_CONST_SMALL_INT 2
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_minute = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_minute,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 98,
        .line_info = fun_data_datetime_datetime_minute + 5,
        .line_info_top = fun_data_datetime_datetime_minute + 7,
        .opcodes = fun_data_datetime_datetime_minute + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_minute fun_data_datetime_datetime_minute[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_second
static const byte fun_data_datetime_datetime_second[17] = {
    0x11,0x0a, // prelude
    0x63,0x81,0x0d, // names: second, self
    0xa0,0xac, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x67, // LOAD_ATTR '_t'
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x83, // LOAD_CONST_SMALL_INT 3
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_second = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_second,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 99,
        .line_info = fun_data_datetime_datetime_second + 5,
        .line_info_top = fun_data_datetime_datetime_second + 7,
        .opcodes = fun_data_datetime_datetime_second + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_second fun_data_datetime_datetime_second[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_microsecond
static const byte fun_data_datetime_datetime_microsecond[17] = {
    0x11,0x0a, // prelude
    0x64,0x81,0x0d, // names: microsecond, self
    0xa0,0xb0, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x67, // LOAD_ATTR '_t'
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x84, // LOAD_CONST_SMALL_INT 4
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_microsecond = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_microsecond,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 100,
        .line_info = fun_data_datetime_datetime_microsecond + 5,
        .line_info_top = fun_data_datetime_datetime_microsecond + 7,
        .opcodes = fun_data_datetime_datetime_microsecond + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_microsecond fun_data_datetime_datetime_microsecond[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_tzinfo
static const byte fun_data_datetime_datetime_tzinfo[11] = {
    0x09,0x0a, // prelude
    0x0e,0x81,0x0d, // names: tzinfo, self
    0xa0,0xb4, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_tzinfo = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_tzinfo,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 11,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 14,
        .line_info = fun_data_datetime_datetime_tzinfo + 5,
        .line_info_top = fun_data_datetime_datetime_tzinfo + 7,
        .opcodes = fun_data_datetime_datetime_tzinfo + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_tzinfo fun_data_datetime_datetime_tzinfo[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_fold
static const byte fun_data_datetime_datetime_fold[11] = {
    0x09,0x0a, // prelude
    0x27,0x81,0x0d, // names: fold, self
    0xa0,0xb8, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x60, // LOAD_ATTR '_fd'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_fold = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_fold,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 11,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 39,
        .line_info = fun_data_datetime_datetime_fold + 5,
        .line_info_top = fun_data_datetime_datetime_fold + 7,
        .opcodes = fun_data_datetime_datetime_fold + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_fold fun_data_datetime_datetime_fold[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___add__
static const byte fun_data_datetime_datetime___add__[54] = {
    0x62,0x14, // prelude
    0x30,0x81,0x0d,0x81,0x11, // names: __add__, self, other
    0xa0,0xbb,0x2a,0x2b,0x26, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x67, // LOAD_ATTR '_t'
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb1, // LOAD_FAST 1
    0x13,0x2b, // LOAD_ATTR '_us'
    0xf2, // BINARY_OP 27 __add__
    0xc2, // STORE_FAST 2
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb2, // LOAD_FAST 2
    0x23,0x03, // LOAD_CONST_OBJ 3
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc3, // STORE_FAST 3
    0xc2, // STORE_FAST 2
    0xb3, // LOAD_FAST 3
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0xe5, // BINARY_OP 14 __iadd__
    0xc3, // STORE_FAST 3
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb2, // LOAD_FAST 2
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x34,0x08, // CALL_FUNCTION 8
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___add__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___add__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 54,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 48,
        .line_info = fun_data_datetime_datetime___add__ + 7,
        .line_info_top = fun_data_datetime_datetime___add__ + 12,
        .opcodes = fun_data_datetime_datetime___add__ + 12,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___add__ fun_data_datetime_datetime___add__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___sub__
static const byte fun_data_datetime_datetime___sub__[66] = {
    0x3a,0x18, // prelude
    0x31,0x81,0x0d,0x81,0x11, // names: __sub__, self, other
    0xa0,0xc1,0x2a,0x28,0x2a,0x2a,0x48, // code info
    0x12,0x81,0x12, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb0, // LOAD_FAST 0
    0x14,0x30, // LOAD_METHOD '__add__'
    0xb1, // LOAD_FAST 1
    0xd1, // UNARY_OP 1 __neg__
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
    0x12,0x81,0x12, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x52, // POP_JUMP_IF_FALSE 18
    0xb0, // LOAD_FAST 0
    0x14,0x65, // LOAD_METHOD '_sub'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0x12,0x05, // LOAD_GLOBAL 'timedelta'
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb3, // LOAD_FAST 3
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
    0x12,0x81,0x1f, // LOAD_GLOBAL 'TypeError'
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___sub__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___sub__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 66,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 49,
        .line_info = fun_data_datetime_datetime___sub__ + 7,
        .line_info_top = fun_data_datetime_datetime___sub__ + 14,
        .opcodes = fun_data_datetime_datetime___sub__ + 14,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___sub__ fun_data_datetime_datetime___sub__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime__sub
static const byte fun_data_datetime_datetime__sub[115] = {
    0x62,0x2a, // prelude
    0x65,0x81,0x0d,0x81,0x11, // names: _sub, self, other
    0xa0,0xcb,0x24,0x2b,0x24,0x22,0x22,0x26,0x26,0x26,0x25,0x24,0x24,0x28,0x2c,0x2b, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xb1, // LOAD_FAST 1
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xee, // BINARY_OP 23 __xor__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x81,0x1f, // LOAD_GLOBAL 'TypeError'
    0x65, // RAISE_OBJ
    0xb0, // LOAD_FAST 0
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0xc4, // STORE_FAST 4
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x59, // POP_JUMP_IF_FALSE 25
    0xb3, // LOAD_FAST 3
    0x14,0x4c, // LOAD_METHOD 'utcoffset'
    0x36,0x00, // CALL_METHOD 0
    0xc5, // STORE_FAST 5
    0xb4, // LOAD_FAST 4
    0x14,0x4c, // LOAD_METHOD 'utcoffset'
    0x36,0x00, // CALL_METHOD 0
    0xc6, // STORE_FAST 6
    0xb5, // LOAD_FAST 5
    0xb6, // LOAD_FAST 6
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb3, // LOAD_FAST 3
    0xb5, // LOAD_FAST 5
    0xe6, // BINARY_OP 15 __isub__
    0xc3, // STORE_FAST 3
    0xb4, // LOAD_FAST 4
    0xb6, // LOAD_FAST 6
    0xe6, // BINARY_OP 15 __isub__
    0xc4, // STORE_FAST 4
    0xb3, // LOAD_FAST 3
    0x13,0x66, // LOAD_ATTR '_d'
    0xb4, // LOAD_FAST 4
    0x13,0x66, // LOAD_ATTR '_d'
    0xf3, // BINARY_OP 28 __sub__
    0xc7, // STORE_FAST 7
    0xb3, // LOAD_FAST 3
    0x13,0x67, // LOAD_ATTR '_t'
    0x13,0x2b, // LOAD_ATTR '_us'
    0xb4, // LOAD_FAST 4
    0x13,0x67, // LOAD_ATTR '_t'
    0x13,0x2b, // LOAD_ATTR '_us'
    0xf3, // BINARY_OP 28 __sub__
    0xc8, // STORE_FAST 8
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb8, // LOAD_FAST 8
    0x23,0x03, // LOAD_CONST_OBJ 3
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc9, // STORE_FAST 9
    0xc8, // STORE_FAST 8
    0xb7, // LOAD_FAST 7
    0xb9, // LOAD_FAST 9
    0xf2, // BINARY_OP 27 __add__
    0xb8, // LOAD_FAST 8
    0x2a,0x02, // BUILD_TUPLE 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime__sub = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime__sub,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 115,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 101,
        .line_info = fun_data_datetime_datetime__sub + 7,
        .line_info_top = fun_data_datetime_datetime__sub + 23,
        .opcodes = fun_data_datetime_datetime__sub + 23,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime__sub fun_data_datetime_datetime__sub[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___eq__
static const byte fun_data_datetime_datetime___eq__[35] = {
    0x22,0x12, // prelude
    0x3a,0x81,0x0d,0x81,0x11, // names: __eq__, self, other
    0xa0,0xdc,0x2d,0x22, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xd9, // BINARY_OP 2 __eq__
    0xb1, // LOAD_FAST 1
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xd9, // BINARY_OP 2 __eq__
    0xee, // BINARY_OP 23 __xor__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x50, // LOAD_CONST_FALSE
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x14,0x6a, // LOAD_METHOD '_cmp'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___eq__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___eq__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 35,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 58,
        .line_info = fun_data_datetime_datetime___eq__ + 7,
        .line_info_top = fun_data_datetime_datetime___eq__ + 11,
        .opcodes = fun_data_datetime_datetime___eq__ + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___eq__ fun_data_datetime_datetime___eq__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___le__
static const byte fun_data_datetime_datetime___le__[18] = {
    0x22,0x0e, // prelude
    0x3b,0x81,0x0d,0x81,0x11, // names: __le__, self, other
    0xa0,0xe1, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x6a, // LOAD_METHOD '_cmp'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xda, // BINARY_OP 3 __le__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___le__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___le__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 59,
        .line_info = fun_data_datetime_datetime___le__ + 7,
        .line_info_top = fun_data_datetime_datetime___le__ + 9,
        .opcodes = fun_data_datetime_datetime___le__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___le__ fun_data_datetime_datetime___le__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___lt__
static const byte fun_data_datetime_datetime___lt__[18] = {
    0x22,0x0e, // prelude
    0x3c,0x81,0x0d,0x81,0x11, // names: __lt__, self, other
    0xa0,0xe4, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x6a, // LOAD_METHOD '_cmp'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___lt__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___lt__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 60,
        .line_info = fun_data_datetime_datetime___lt__ + 7,
        .line_info_top = fun_data_datetime_datetime___lt__ + 9,
        .opcodes = fun_data_datetime_datetime___lt__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___lt__ fun_data_datetime_datetime___lt__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___ge__
static const byte fun_data_datetime_datetime___ge__[18] = {
    0x22,0x0e, // prelude
    0x3d,0x81,0x0d,0x81,0x11, // names: __ge__, self, other
    0xa0,0xe7, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x6a, // LOAD_METHOD '_cmp'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xdb, // BINARY_OP 4 __ge__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___ge__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___ge__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 61,
        .line_info = fun_data_datetime_datetime___ge__ + 7,
        .line_info_top = fun_data_datetime_datetime___ge__ + 9,
        .opcodes = fun_data_datetime_datetime___ge__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___ge__ fun_data_datetime_datetime___ge__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___gt__
static const byte fun_data_datetime_datetime___gt__[18] = {
    0x22,0x0e, // prelude
    0x3e,0x81,0x0d,0x81,0x11, // names: __gt__, self, other
    0xa0,0xea, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x6a, // LOAD_METHOD '_cmp'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd8, // BINARY_OP 1 __gt__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___gt__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___gt__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 62,
        .line_info = fun_data_datetime_datetime___gt__ + 7,
        .line_info_top = fun_data_datetime_datetime___gt__ + 9,
        .opcodes = fun_data_datetime_datetime___gt__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___gt__ fun_data_datetime_datetime___gt__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime__cmp
static const byte fun_data_datetime_datetime__cmp[58] = {
    0x32,0x20, // prelude
    0x6a,0x81,0x0d,0x81,0x11, // names: _cmp, self, other
    0xa0,0xee,0x2a,0x25,0x22,0x25,0x42,0x25,0x22,0x25,0x42, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x65, // LOAD_METHOD '_sub'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x63, // RETURN_VALUE
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x81, // LOAD_CONST_SMALL_INT 1
    0x63, // RETURN_VALUE
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x63, // RETURN_VALUE
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x81, // LOAD_CONST_SMALL_INT 1
    0x63, // RETURN_VALUE
    0x80, // LOAD_CONST_SMALL_INT 0
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime__cmp = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime__cmp,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 58,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 106,
        .line_info = fun_data_datetime_datetime__cmp + 7,
        .line_info_top = fun_data_datetime_datetime__cmp + 18,
        .opcodes = fun_data_datetime_datetime__cmp + 18,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime__cmp fun_data_datetime_datetime__cmp[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_date
static const byte fun_data_datetime_datetime_date[17] = {
    0x19,0x0a, // prelude
    0x11,0x81,0x0d, // names: date, self
    0xa0,0xfc, // code info
    0x12,0x11, // LOAD_GLOBAL 'date'
    0x14,0x55, // LOAD_METHOD 'fromordinal'
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_date = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_date,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 17,
        .line_info = fun_data_datetime_datetime_date + 5,
        .line_info_top = fun_data_datetime_datetime_date + 7,
        .opcodes = fun_data_datetime_datetime_date + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_date fun_data_datetime_datetime_date[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_time
static const byte fun_data_datetime_datetime_time[25] = {
    0x29,0x0a, // prelude
    0x02,0x81,0x0d, // names: time, self
    0xa0,0xff, // code info
    0x12,0x02, // LOAD_GLOBAL 'time'
    0x10,0x64, // LOAD_CONST_STRING 'microsecond'
    0xb0, // LOAD_FAST 0
    0x13,0x67, // LOAD_ATTR '_t'
    0x13,0x2b, // LOAD_ATTR '_us'
    0x10,0x27, // LOAD_CONST_STRING 'fold'
    0xb0, // LOAD_FAST 0
    0x13,0x60, // LOAD_ATTR '_fd'
    0x34,0x84,0x00, // CALL_FUNCTION 512
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_time = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_time,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 2,
        .line_info = fun_data_datetime_datetime_time + 5,
        .line_info_top = fun_data_datetime_datetime_time + 7,
        .opcodes = fun_data_datetime_datetime_time + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_time fun_data_datetime_datetime_time[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_timetz
static const byte fun_data_datetime_datetime_timetz[30] = {
    0x39,0x0a, // prelude
    0x6b,0x81,0x0d, // names: timetz, self
    0xb0,0x02, // code info
    0x12,0x02, // LOAD_GLOBAL 'time'
    0x10,0x64, // LOAD_CONST_STRING 'microsecond'
    0xb0, // LOAD_FAST 0
    0x13,0x67, // LOAD_ATTR '_t'
    0x13,0x2b, // LOAD_ATTR '_us'
    0x10,0x0e, // LOAD_CONST_STRING 'tzinfo'
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x10,0x27, // LOAD_CONST_STRING 'fold'
    0xb0, // LOAD_FAST 0
    0x13,0x60, // LOAD_ATTR '_fd'
    0x34,0x86,0x00, // CALL_FUNCTION 768
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_timetz = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_timetz,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 30,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 107,
        .line_info = fun_data_datetime_datetime_timetz + 5,
        .line_info_top = fun_data_datetime_datetime_timetz + 7,
        .opcodes = fun_data_datetime_datetime_timetz + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_timetz fun_data_datetime_datetime_timetz[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_replace
static const byte fun_data_datetime_datetime_replace[141] = {
    0xe9,0x98,0x84,0x80,0x41,0x42, // prelude
    0x5d,0x81,0x0d,0x57,0x58,0x59,0x61,0x62,0x63,0x64,0x0e,0x27, // names: replace, self, year, month, day, hour, minute, second, microsecond, tzinfo, fold
    0xb0,0x11,0x33,0x25,0x22,0x25,0x22,0x25,0x22,0x25,0x22,0x25,0x22,0x25,0x22,0x25,0x23,0x25,0x23,0x25,0x23, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x30,0x09, // UNPACK_SEQUENCE 9
    0xca, // STORE_FAST 10
    0xcb, // STORE_FAST 11
    0xcc, // STORE_FAST 12
    0xcd, // STORE_FAST 13
    0xce, // STORE_FAST 14
    0xcf, // STORE_FAST 15
    0x26,0x10, // STORE_FAST_N 16
    0x26,0x11, // STORE_FAST_N 17
    0x26,0x12, // STORE_FAST_N 18
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xba, // LOAD_FAST 10
    0xc1, // STORE_FAST 1
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xbb, // LOAD_FAST 11
    0xc2, // STORE_FAST 2
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xbc, // LOAD_FAST 12
    0xc3, // STORE_FAST 3
    0xb4, // LOAD_FAST 4
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xbd, // LOAD_FAST 13
    0xc4, // STORE_FAST 4
    0xb5, // LOAD_FAST 5
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xbe, // LOAD_FAST 14
    0xc5, // STORE_FAST 5
    0xb6, // LOAD_FAST 6
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xbf, // LOAD_FAST 15
    0xc6, // STORE_FAST 6
    0xb7, // LOAD_FAST 7
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x24,0x10, // LOAD_FAST_N 16
    0xc7, // STORE_FAST 7
    0xb8, // LOAD_FAST 8
    0x52, // LOAD_CONST_TRUE
    0xde, // BINARY_OP 7 <is>
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x24,0x11, // LOAD_FAST_N 17
    0xc8, // STORE_FAST 8
    0xb9, // LOAD_FAST 9
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x24,0x12, // LOAD_FAST_N 18
    0xc9, // STORE_FAST 9
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0xb5, // LOAD_FAST 5
    0xb6, // LOAD_FAST 6
    0xb7, // LOAD_FAST 7
    0xb8, // LOAD_FAST 8
    0x10,0x27, // LOAD_CONST_STRING 'fold'
    0xb9, // LOAD_FAST 9
    0x34,0x82,0x08, // CALL_FUNCTION 264
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_replace = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_replace,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 141,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 30,
        .n_exc_stack = 0,
        .scope_flags = 8,
        .n_pos_args = 9,
        .n_kwonly_args = 1,
        .n_def_pos_args = 8,
        .qstr_block_name_idx = 93,
        .line_info = fun_data_datetime_datetime_replace + 18,
        .line_info_top = fun_data_datetime_datetime_replace + 39,
        .opcodes = fun_data_datetime_datetime_replace + 39,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_replace fun_data_datetime_datetime_replace[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_astimezone
static const byte fun_data_datetime_datetime_astimezone[111] = {
    0xd2,0x01,0x22, // prelude
    0x6c,0x81,0x0d,0x81,0x0c, // names: astimezone, self, tz
    0xb0,0x27,0x27,0x22,0x24,0x25,0x2b,0x1f,0x43,0x27,0x24,0x2a, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0xb1, // LOAD_FAST 1
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb0, // LOAD_FAST 0
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x6d, // POP_JUMP_IF_FALSE 45
    0x12,0x81,0x04, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0x14,0x6d, // LOAD_METHOD '_mktime'
    0x36,0x00, // CALL_METHOD 0
    0x34,0x01, // CALL_FUNCTION 1
    0xc3, // STORE_FAST 3
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x12,0x74, // LOAD_GLOBAL '_localtime'
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0x51, // LOAD_CONST_NONE
    0x86, // LOAD_CONST_SMALL_INT 6
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x12,0x73, // LOAD_GLOBAL '_gmtime'
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0x51, // LOAD_CONST_NONE
    0x86, // LOAD_CONST_SMALL_INT 6
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0xf3, // BINARY_OP 28 __sub__
    0xc4, // STORE_FAST 4
    0x42,0x47, // JUMP 7
    0xb2, // LOAD_FAST 2
    0x14,0x4c, // LOAD_METHOD 'utcoffset'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0xc4, // STORE_FAST 4
    0xb0, // LOAD_FAST 0
    0xb4, // LOAD_FAST 4
    0xf3, // BINARY_OP 28 __sub__
    0xc5, // STORE_FAST 5
    0xb5, // LOAD_FAST 5
    0x14,0x5d, // LOAD_METHOD 'replace'
    0x10,0x0e, // LOAD_CONST_STRING 'tzinfo'
    0xb1, // LOAD_FAST 1
    0x36,0x82,0x00, // CALL_METHOD 256
    0xc5, // STORE_FAST 5
    0xb1, // LOAD_FAST 1
    0x14,0x4e, // LOAD_METHOD 'fromutc'
    0xb5, // LOAD_FAST 5
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_astimezone = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_astimezone,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 111,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 11,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 108,
        .line_info = fun_data_datetime_datetime_astimezone + 8,
        .line_info_top = fun_data_datetime_datetime_astimezone + 20,
        .opcodes = fun_data_datetime_datetime_astimezone + 20,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_astimezone fun_data_datetime_datetime_astimezone[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime__mktime
static const byte fun_data_datetime_datetime__mktime[191] = {
    0x79,0x39, // prelude
    0x6d,0x81,0x0d, // names: _mktime, self
    0xb0,0x34,0x65,0x2e,0x32,0x42,0x27,0x24,0x25,0x25,0x32,0x27,0x25,0x44,0x24,0x25,0x24,0x25,0x25,0x24,0x25,0x24,0x25,0x49,0x27,0x0b, // code info
    0xbb, // LOAD_FAST 11
    0x20,0x00,0x01, // MAKE_CLOSURE 0
    0xc1, // STORE_FAST 1
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x13,0x13, // LOAD_ATTR 'EPOCH'
    0x14,0x5d, // LOAD_METHOD 'replace'
    0x10,0x0e, // LOAD_CONST_STRING 'tzinfo'
    0x51, // LOAD_CONST_NONE
    0x36,0x82,0x00, // CALL_METHOD 256
    0x27,0x0b, // STORE_DEREF 11
    0x12,0x7b, // LOAD_GLOBAL 'divmod'
    0xb0, // LOAD_FAST 0
    0x25,0x0b, // LOAD_DEREF 11
    0xf3, // BINARY_OP 28 __sub__
    0x13,0x2b, // LOAD_ATTR '_us'
    0x22,0xbd,0x84,0x40, // LOAD_CONST_SMALL_INT 1000000
    0x34,0x02, // CALL_FUNCTION 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0x51, // LOAD_CONST_NONE
    0xc4, // STORE_FAST 4
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0xb2, // LOAD_FAST 2
    0xf3, // BINARY_OP 28 __sub__
    0xc5, // STORE_FAST 5
    0xb2, // LOAD_FAST 2
    0xb5, // LOAD_FAST 5
    0xf3, // BINARY_OP 28 __sub__
    0xc6, // STORE_FAST 6
    0xb1, // LOAD_FAST 1
    0xb6, // LOAD_FAST 6
    0x34,0x01, // CALL_FUNCTION 1
    0xc7, // STORE_FAST 7
    0xb7, // LOAD_FAST 7
    0xb2, // LOAD_FAST 2
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x62, // POP_JUMP_IF_FALSE 34
    0xb6, // LOAD_FAST 6
    0xb0, // LOAD_FAST 0
    0x13,0x27, // LOAD_ATTR 'fold'
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x22,0x85,0xa3,0x00, // LOAD_CONST_SMALL_INT 86400
    0x42,0x44, // JUMP 4
    0x22,0xfa,0xdd,0x00, // LOAD_CONST_SMALL_INT -86400
    0xf2, // BINARY_OP 27 __add__
    0xc8, // STORE_FAST 8
    0xb1, // LOAD_FAST 1
    0xb8, // LOAD_FAST 8
    0x34,0x01, // CALL_FUNCTION 1
    0xb8, // LOAD_FAST 8
    0xf3, // BINARY_OP 28 __sub__
    0xc9, // STORE_FAST 9
    0xb5, // LOAD_FAST 5
    0xb9, // LOAD_FAST 9
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb6, // LOAD_FAST 6
    0xc4, // STORE_FAST 4
    0x42,0x44, // JUMP 4
    0xb7, // LOAD_FAST 7
    0xb6, // LOAD_FAST 6
    0xf3, // BINARY_OP 28 __sub__
    0xc9, // STORE_FAST 9
    0xb4, // LOAD_FAST 4
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x70, // POP_JUMP_IF_FALSE 48
    0xb2, // LOAD_FAST 2
    0xb9, // LOAD_FAST 9
    0xf3, // BINARY_OP 28 __sub__
    0xc8, // STORE_FAST 8
    0xb1, // LOAD_FAST 1
    0xb8, // LOAD_FAST 8
    0x34,0x01, // CALL_FUNCTION 1
    0xca, // STORE_FAST 10
    0xba, // LOAD_FAST 10
    0xb2, // LOAD_FAST 2
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0xb8, // LOAD_FAST 8
    0xc4, // STORE_FAST 4
    0x42,0x5e, // JUMP 30
    0xb7, // LOAD_FAST 7
    0xb2, // LOAD_FAST 2
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0xb6, // LOAD_FAST 6
    0xc4, // STORE_FAST 4
    0x42,0x55, // JUMP 21
    0xb0, // LOAD_FAST 0
    0x13,0x27, // LOAD_ATTR 'fold'
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0x12,0x07, // LOAD_GLOBAL 'min'
    0xb6, // LOAD_FAST 6
    0xb8, // LOAD_FAST 8
    0x34,0x02, // CALL_FUNCTION 2
    0xc4, // STORE_FAST 4
    0x42,0x47, // JUMP 7
    0x12,0x0c, // LOAD_GLOBAL 'max'
    0xb6, // LOAD_FAST 6
    0xb8, // LOAD_FAST 8
    0x34,0x02, // CALL_FUNCTION 2
    0xc4, // STORE_FAST 4
    0xb4, // LOAD_FAST 4
    0xb3, // LOAD_FAST 3
    0x22,0xbd,0x84,0x40, // LOAD_CONST_SMALL_INT 1000000
    0xf7, // BINARY_OP 32 __truediv__
    0xf2, // BINARY_OP 27 __add__
    0x63, // RETURN_VALUE
};
// child of datetime_datetime__mktime
// frozen bytecode for file datetime.py, scope datetime_datetime__mktime_local
static const byte fun_data_datetime_datetime__mktime_local[35] = {
    0x2a,0x0e, // prelude
    0x70,0x81,0x22,0x81,0x23, // names: local, *, u
    0xb0,0x35, // code info
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x12,0x74, // LOAD_GLOBAL '_localtime'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x51, // LOAD_CONST_NONE
    0x86, // LOAD_CONST_SMALL_INT 6
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0x25,0x00, // LOAD_DEREF 0
    0xf3, // BINARY_OP 28 __sub__
    0x13,0x2b, // LOAD_ATTR '_us'
    0x22,0xbd,0x84,0x40, // LOAD_CONST_SMALL_INT 1000000
    0xf6, // BINARY_OP 31 __floordiv__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime__mktime_local = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime__mktime_local,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 35,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 112,
        .line_info = fun_data_datetime_datetime__mktime_local + 7,
        .line_info_top = fun_data_datetime_datetime__mktime_local + 9,
        .opcodes = fun_data_datetime_datetime__mktime_local + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime__mktime_local fun_data_datetime_datetime__mktime_local[0]
#endif

static const mp_raw_code_t *const children_datetime_datetime__mktime[] = {
    (const mp_raw_code_t *)&proto_fun_datetime_datetime__mktime_local,
};

static const mp_raw_code_truncated_t proto_fun_datetime_datetime__mktime = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime__mktime,
    .children = (void *)&children_datetime_datetime__mktime,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 191,
    .n_children = 1,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 16,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 109,
        .line_info = fun_data_datetime_datetime__mktime + 5,
        .line_info_top = fun_data_datetime_datetime__mktime + 30,
        .opcodes = fun_data_datetime_datetime__mktime + 31,
    },
    #endif
    #endif
};

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_utcoffset
static const byte fun_data_datetime_datetime_utcoffset[25] = {
    0x19,0x0a, // prelude
    0x4c,0x81,0x0d, // names: utcoffset, self
    0xb0,0x53, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x14,0x4c, // LOAD_METHOD 'utcoffset'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_utcoffset = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_utcoffset,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 76,
        .line_info = fun_data_datetime_datetime_utcoffset + 5,
        .line_info_top = fun_data_datetime_datetime_utcoffset + 7,
        .opcodes = fun_data_datetime_datetime_utcoffset + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_utcoffset fun_data_datetime_datetime_utcoffset[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_dst
static const byte fun_data_datetime_datetime_dst[25] = {
    0x19,0x0a, // prelude
    0x4d,0x81,0x0d, // names: dst, self
    0xb0,0x56, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x14,0x4d, // LOAD_METHOD 'dst'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_dst = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_dst,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 77,
        .line_info = fun_data_datetime_datetime_dst + 5,
        .line_info_top = fun_data_datetime_datetime_dst + 7,
        .opcodes = fun_data_datetime_datetime_dst + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_dst fun_data_datetime_datetime_dst[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_tzname
static const byte fun_data_datetime_datetime_tzname[25] = {
    0x19,0x0a, // prelude
    0x4b,0x81,0x0d, // names: tzname, self
    0xb0,0x59, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x14,0x4b, // LOAD_METHOD 'tzname'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_tzname = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_tzname,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 75,
        .line_info = fun_data_datetime_datetime_tzname + 5,
        .line_info_top = fun_data_datetime_datetime_tzname + 7,
        .opcodes = fun_data_datetime_datetime_tzname + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_tzname fun_data_datetime_datetime_tzname[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_timetuple
static const byte fun_data_datetime_datetime_timetuple[61] = {
    0x31,0x14, // prelude
    0x5b,0x81,0x0d, // names: timetuple, self
    0xb0,0x5c,0x27,0x23,0x4f,0x23,0x25, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x52, // POP_JUMP_IF_FALSE 18
    0x12,0x73, // LOAD_GLOBAL '_gmtime'
    0xc1, // STORE_FAST 1
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x13,0x13, // LOAD_ATTR 'EPOCH'
    0x14,0x5d, // LOAD_METHOD 'replace'
    0x10,0x0e, // LOAD_CONST_STRING 'tzinfo'
    0x51, // LOAD_CONST_NONE
    0x36,0x82,0x00, // CALL_METHOD 256
    0xc2, // STORE_FAST 2
    0x42,0x48, // JUMP 8
    0x12,0x74, // LOAD_GLOBAL '_localtime'
    0xc1, // STORE_FAST 1
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x13,0x13, // LOAD_ATTR 'EPOCH'
    0xc2, // STORE_FAST 2
    0xb1, // LOAD_FAST 1
    0x12,0x81,0x10, // LOAD_GLOBAL 'round'
    0xb0, // LOAD_FAST 0
    0xb2, // LOAD_FAST 2
    0xf3, // BINARY_OP 28 __sub__
    0x14,0x2e, // LOAD_METHOD 'total_seconds'
    0x36,0x00, // CALL_METHOD 0
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_timetuple = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_timetuple,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 61,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 91,
        .line_info = fun_data_datetime_datetime_timetuple + 5,
        .line_info_top = fun_data_datetime_datetime_timetuple + 12,
        .opcodes = fun_data_datetime_datetime_timetuple + 12,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_timetuple fun_data_datetime_datetime_timetuple[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_toordinal
static const byte fun_data_datetime_datetime_toordinal[11] = {
    0x09,0x0a, // prelude
    0x5a,0x81,0x0d, // names: toordinal, self
    0xb0,0x65, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_toordinal = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_toordinal,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 11,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 90,
        .line_info = fun_data_datetime_datetime_toordinal + 5,
        .line_info_top = fun_data_datetime_datetime_toordinal + 7,
        .opcodes = fun_data_datetime_datetime_toordinal + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_toordinal fun_data_datetime_datetime_toordinal[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_timestamp
static const byte fun_data_datetime_datetime_timestamp[35] = {
    0x11,0x0e, // prelude
    0x6e,0x81,0x0d, // names: timestamp, self
    0xb0,0x68,0x27,0x46, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0xb0, // LOAD_FAST 0
    0x14,0x6d, // LOAD_METHOD '_mktime'
    0x36,0x00, // CALL_METHOD 0
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x12,0x12, // LOAD_GLOBAL 'datetime'
    0x13,0x13, // LOAD_ATTR 'EPOCH'
    0xf3, // BINARY_OP 28 __sub__
    0x14,0x2e, // LOAD_METHOD 'total_seconds'
    0x36,0x00, // CALL_METHOD 0
    0x63, // RETURN_VALUE
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_timestamp = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_timestamp,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 35,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 110,
        .line_info = fun_data_datetime_datetime_timestamp + 5,
        .line_info_top = fun_data_datetime_datetime_timestamp + 9,
        .opcodes = fun_data_datetime_datetime_timestamp + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_timestamp fun_data_datetime_datetime_timestamp[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_weekday
static const byte fun_data_datetime_datetime_weekday[15] = {
    0x11,0x0a, // prelude
    0x5c,0x81,0x0d, // names: weekday, self
    0xb0,0x6e, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0x86, // LOAD_CONST_SMALL_INT 6
    0xf2, // BINARY_OP 27 __add__
    0x87, // LOAD_CONST_SMALL_INT 7
    0xf8, // BINARY_OP 33 __mod__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_weekday = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_weekday,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 92,
        .line_info = fun_data_datetime_datetime_weekday + 5,
        .line_info_top = fun_data_datetime_datetime_weekday + 7,
        .opcodes = fun_data_datetime_datetime_weekday + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_weekday fun_data_datetime_datetime_weekday[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_isoweekday
static const byte fun_data_datetime_datetime_isoweekday[16] = {
    0x11,0x0a, // prelude
    0x5e,0x81,0x0d, // names: isoweekday, self
    0xb0,0x71, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0x87, // LOAD_CONST_SMALL_INT 7
    0xf8, // BINARY_OP 33 __mod__
    0x45,0x01, // JUMP_IF_TRUE_OR_POP 1
    0x87, // LOAD_CONST_SMALL_INT 7
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_isoweekday = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_isoweekday,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 94,
        .line_info = fun_data_datetime_datetime_isoweekday + 5,
        .line_info_top = fun_data_datetime_datetime_isoweekday + 7,
        .opcodes = fun_data_datetime_datetime_isoweekday + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_isoweekday fun_data_datetime_datetime_isoweekday[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_isoformat
static const byte fun_data_datetime_datetime_isoformat[36] = {
    0xc3,0x80,0x01,0x12, // prelude
    0x26,0x81,0x0d,0x81,0x21,0x81,0x0a, // names: isoformat, self, sep, timespec
    0xb0,0x74, // code info
    0x12,0x1b, // LOAD_GLOBAL '_d2iso'
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0x34,0x01, // CALL_FUNCTION 1
    0xb1, // LOAD_FAST 1
    0xf2, // BINARY_OP 27 __add__
    0x12,0x23, // LOAD_GLOBAL '_t2iso'
    0xb0, // LOAD_FAST 0
    0x13,0x67, // LOAD_ATTR '_t'
    0xb2, // LOAD_FAST 2
    0xb0, // LOAD_FAST 0
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x34,0x04, // CALL_FUNCTION 4
    0xf2, // BINARY_OP 27 __add__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_isoformat = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_isoformat,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 36,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 9,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name_idx = 38,
        .line_info = fun_data_datetime_datetime_isoformat + 11,
        .line_info_top = fun_data_datetime_datetime_isoformat + 13,
        .opcodes = fun_data_datetime_datetime_isoformat + 13,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_isoformat fun_data_datetime_datetime_isoformat[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___repr__
static const byte fun_data_datetime_datetime___repr__[49] = {
    0xa1,0x10,0x0e, // prelude
    0x2c,0x81,0x0d, // names: __repr__, self
    0xb0,0x77,0x30,0x27, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x30,0x09, // UNPACK_SEQUENCE 9
    0xc1, // STORE_FAST 1
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0xc4, // STORE_FAST 4
    0xc5, // STORE_FAST 5
    0xc6, // STORE_FAST 6
    0xc7, // STORE_FAST 7
    0xc8, // STORE_FAST 8
    0xc9, // STORE_FAST 9
    0x12,0x81,0x1b, // LOAD_GLOBAL 'repr'
    0xb8, // LOAD_FAST 8
    0x34,0x01, // CALL_FUNCTION 1
    0xc8, // STORE_FAST 8
    0x23,0x0a, // LOAD_CONST_OBJ 10
    0x14,0x2d, // LOAD_METHOD 'format'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0xb5, // LOAD_FAST 5
    0xb6, // LOAD_FAST 6
    0xb7, // LOAD_FAST 7
    0xb8, // LOAD_FAST 8
    0xb9, // LOAD_FAST 9
    0x36,0x09, // CALL_METHOD 9
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___repr__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___repr__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 49,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 21,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 44,
        .line_info = fun_data_datetime_datetime___repr__ + 6,
        .line_info_top = fun_data_datetime_datetime___repr__ + 10,
        .opcodes = fun_data_datetime_datetime___repr__ + 10,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___repr__ fun_data_datetime_datetime___repr__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___str__
static const byte fun_data_datetime_datetime___str__[15] = {
    0x19,0x0a, // prelude
    0x40,0x81,0x0d, // names: __str__, self
    0xb0,0x7e, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x26, // LOAD_METHOD 'isoformat'
    0x10,0x6f, // LOAD_CONST_STRING ' '
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___str__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___str__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 64,
        .line_info = fun_data_datetime_datetime___str__ + 5,
        .line_info_top = fun_data_datetime_datetime___str__ + 7,
        .opcodes = fun_data_datetime_datetime___str__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___str__ fun_data_datetime_datetime___str__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime___hash__
static const byte fun_data_datetime_datetime___hash__[42] = {
    0x21,0x0e, // prelude
    0x41,0x81,0x0d, // names: __hash__, self
    0xb0,0x81,0x2a,0x33, // code info
    0x12,0x81,0x13, // LOAD_GLOBAL 'hasattr'
    0xb0, // LOAD_FAST 0
    0x10,0x42, // LOAD_CONST_STRING '_hash'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x53, // POP_JUMP_IF_TRUE 19
    0x12,0x81,0x14, // LOAD_GLOBAL 'hash'
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0xb0, // LOAD_FAST 0
    0x13,0x67, // LOAD_ATTR '_t'
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0x2a,0x03, // BUILD_TUPLE 3
    0x34,0x01, // CALL_FUNCTION 1
    0xb0, // LOAD_FAST 0
    0x18,0x42, // STORE_ATTR '_hash'
    0xb0, // LOAD_FAST 0
    0x13,0x42, // LOAD_ATTR '_hash'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime___hash__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime___hash__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 42,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 65,
        .line_info = fun_data_datetime_datetime___hash__ + 5,
        .line_info_top = fun_data_datetime_datetime___hash__ + 9,
        .opcodes = fun_data_datetime_datetime___hash__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime___hash__ fun_data_datetime_datetime___hash__[0]
#endif

// child of datetime_datetime
// frozen bytecode for file datetime.py, scope datetime_datetime_tuple
static const byte fun_data_datetime_datetime_tuple[43] = {
    0x29,0x0e, // prelude
    0x4a,0x81,0x0d, // names: tuple, self
    0xb0,0x86,0x28,0x2d, // code info
    0x12,0x17, // LOAD_GLOBAL '_o2ymd'
    0xb0, // LOAD_FAST 0
    0x13,0x66, // LOAD_ATTR '_d'
    0x34,0x01, // CALL_FUNCTION 1
    0xc1, // STORE_FAST 1
    0xb0, // LOAD_FAST 0
    0x13,0x67, // LOAD_ATTR '_t'
    0x14,0x4a, // LOAD_METHOD 'tuple'
    0x36,0x00, // CALL_METHOD 0
    0x81, // LOAD_CONST_SMALL_INT 1
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xc2, // STORE_FAST 2
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xf2, // BINARY_OP 27 __add__
    0xb0, // LOAD_FAST 0
    0x13,0x4f, // LOAD_ATTR '_tz'
    0xb0, // LOAD_FAST 0
    0x13,0x60, // LOAD_ATTR '_fd'
    0x2a,0x02, // BUILD_TUPLE 2
    0xf2, // BINARY_OP 27 __add__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_datetime_datetime_tuple = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime_tuple,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 43,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 74,
        .line_info = fun_data_datetime_datetime_tuple + 5,
        .line_info_top = fun_data_datetime_datetime_tuple + 9,
        .opcodes = fun_data_datetime_datetime_tuple + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_datetime_datetime_tuple fun_data_datetime_datetime_tuple[0]
#endif

static const mp_raw_code_t *const children_datetime_datetime[] = {
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___init__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_fromtimestamp,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_now,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_fromordinal,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_fromisoformat,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_combine,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_year,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_month,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_day,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_hour,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_minute,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_second,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_microsecond,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_tzinfo,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_fold,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___add__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___sub__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime__sub,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___eq__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___le__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___lt__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___ge__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___gt__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime__cmp,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_date,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_time,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_timetz,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_replace,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_astimezone,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime__mktime,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_utcoffset,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_dst,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_tzname,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_timetuple,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_toordinal,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_timestamp,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_weekday,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_isoweekday,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_isoformat,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___repr__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___str__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime___hash__,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime_tuple,
};

static const mp_raw_code_truncated_t proto_fun_datetime_datetime = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime_datetime,
    .children = (void *)&children_datetime_datetime,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 372,
    .n_children = 43,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 18,
        .line_info = fun_data_datetime_datetime + 4,
        .line_info_top = fun_data_datetime_datetime + 77,
        .opcodes = fun_data_datetime_datetime + 77,
    },
    #endif
    #endif
};

static const mp_raw_code_t *const children_datetime__lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_datetime__leap,
    (const mp_raw_code_t *)&proto_fun_datetime__dim,
    (const mp_raw_code_t *)&proto_fun_datetime__dbm,
    (const mp_raw_code_t *)&proto_fun_datetime__o2ymd,
    (const mp_raw_code_t *)&proto_fun_datetime_timedelta,
    (const mp_raw_code_t *)&proto_fun_datetime_tzinfo,
    (const mp_raw_code_t *)&proto_fun_datetime_timezone,
    (const mp_raw_code_t *)&proto_fun_datetime__date,
    (const mp_raw_code_t *)&proto_fun_datetime__iso2d,
    (const mp_raw_code_t *)&proto_fun_datetime__d2iso,
    (const mp_raw_code_t *)&proto_fun_datetime_date,
    (const mp_raw_code_t *)&proto_fun_datetime__time,
    (const mp_raw_code_t *)&proto_fun_datetime__iso2t,
    (const mp_raw_code_t *)&proto_fun_datetime__t2iso,
    (const mp_raw_code_t *)&proto_fun_datetime_time,
    (const mp_raw_code_t *)&proto_fun_datetime_datetime,
};

static const mp_raw_code_truncated_t proto_fun_datetime__lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_datetime__lt_module_gt_,
    .children = (void *)&children_datetime__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 361,
    .n_children = 16,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 11,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_datetime__lt_module_gt_ + 3,
        .line_info_top = fun_data_datetime__lt_module_gt_ + 54,
        .opcodes = fun_data_datetime__lt_module_gt_ + 54,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_datetime[164] = {
    MP_QSTR_datetime_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_time,
    MP_QSTR_gmtime,
    MP_QSTR_localtime,
    MP_QSTR_timedelta,
    MP_QSTR_days,
    MP_QSTR_min,
    MP_QSTR_hours,
    MP_QSTR_minutes,
    MP_QSTR_seconds,
    MP_QSTR_microseconds,
    MP_QSTR_max,
    MP_QSTR_resolution,
    MP_QSTR_tzinfo,
    MP_QSTR_timezone,
    MP_QSTR_utc,
    MP_QSTR_date,
    MP_QSTR_datetime,
    MP_QSTR_EPOCH,
    MP_QSTR__leap,
    MP_QSTR__dim,
    MP_QSTR__dbm,
    MP_QSTR__o2ymd,
    MP_QSTR__date,
    MP_QSTR__iso2d,
    MP_QSTR__hyphen_,
    MP_QSTR__d2iso,
    MP_QSTR__time,
    MP_QSTR__iso2t,
    MP_QSTR_,
    MP_QSTR__colon_,
    MP_QSTR__dot_,
    MP_QSTR__plus_,
    MP_QSTR__plus__hyphen_,
    MP_QSTR__t2iso,
    MP_QSTR__fmt,
    MP_QSTR_index,
    MP_QSTR_isoformat,
    MP_QSTR_fold,
    MP_QSTR_auto,
    MP_QSTR_T,
    MP_QSTR___init__,
    MP_QSTR__us,
    MP_QSTR___repr__,
    MP_QSTR_format,
    MP_QSTR_total_seconds,
    MP_QSTR__tuple,
    MP_QSTR___add__,
    MP_QSTR___sub__,
    MP_QSTR___neg__,
    MP_QSTR___pos__,
    MP_QSTR___abs__,
    MP_QSTR___mul__,
    MP_QSTR___truediv__,
    MP_QSTR___floordiv__,
    MP_QSTR___mod__,
    MP_QSTR___divmod__,
    MP_QSTR___eq__,
    MP_QSTR___le__,
    MP_QSTR___lt__,
    MP_QSTR___ge__,
    MP_QSTR___gt__,
    MP_QSTR___bool__,
    MP_QSTR___str__,
    MP_QSTR___hash__,
    MP_QSTR__hash,
    MP_QSTR__brace_open__colon_02d_brace_close_,
    MP_QSTR_UTC,
    MP_QSTR_s,
    MP_QSTR__brace_open__brace_close__brace_open__brace_close_,
    MP_QSTR__colon__brace_open__colon_02d_brace_close_,
    MP_QSTR__dot__brace_open__colon_03d_brace_close_,
    MP_QSTR__brace_open__colon_03d_brace_close_,
    MP_QSTR_tuple,
    MP_QSTR_tzname,
    MP_QSTR_utcoffset,
    MP_QSTR_dst,
    MP_QSTR_fromutc,
    MP_QSTR__tz,
    MP_QSTR__offset,
    MP_QSTR__name,
    MP_QSTR__ord,
    MP_QSTR_fromtimestamp,
    MP_QSTR_today,
    MP_QSTR_fromordinal,
    MP_QSTR_fromisoformat,
    MP_QSTR_year,
    MP_QSTR_month,
    MP_QSTR_day,
    MP_QSTR_toordinal,
    MP_QSTR_timetuple,
    MP_QSTR_weekday,
    MP_QSTR_replace,
    MP_QSTR_isoweekday,
    MP_QSTR__td,
    MP_QSTR__fd,
    MP_QSTR_hour,
    MP_QSTR_minute,
    MP_QSTR_second,
    MP_QSTR_microsecond,
    MP_QSTR__sub,
    MP_QSTR__d,
    MP_QSTR__t,
    MP_QSTR_now,
    MP_QSTR_combine,
    MP_QSTR__cmp,
    MP_QSTR_timetz,
    MP_QSTR_astimezone,
    MP_QSTR__mktime,
    MP_QSTR_timestamp,
    MP_QSTR__space_,
    MP_QSTR_local,
    MP_QSTR___import__,
    MP_QSTR__tmod,
    MP_QSTR__gmtime,
    MP_QSTR__localtime,
    MP_QSTR__epoch_time,
    MP_QSTR_MINYEAR,
    MP_QSTR_MAXYEAR,
    MP_QSTR_y,
    MP_QSTR_m,
    MP_QSTR_n,
    MP_QSTR_divmod,
    MP_QSTR___name__,
    MP_QSTR___module__,
    MP_QSTR___qualname__,
    MP_QSTR_property,
    MP_QSTR___rmul__,
    MP_QSTR_d,
    MP_QSTR_ValueError,
    MP_QSTR_len,
    MP_QSTR_int,
    MP_QSTR_o,
    MP_QSTR_classmethod,
    MP_QSTR_h,
    MP_QSTR_us,
    MP_QSTR_td,
    MP_QSTR_timespec,
    MP_QSTR_dt,
    MP_QSTR_tz,
    MP_QSTR_self,
    MP_QSTR_milliseconds,
    MP_QSTR_weeks,
    MP_QSTR_round,
    MP_QSTR_other,
    MP_QSTR_isinstance,
    MP_QSTR_hasattr,
    MP_QSTR_hash,
    MP_QSTR_spec,
    MP_QSTR_str,
    MP_QSTR_NotImplementedError,
    MP_QSTR_offset,
    MP_QSTR_name,
    MP_QSTR_abs,
    MP_QSTR_repr,
    MP_QSTR_NotImplemented,
    MP_QSTR_cls,
    MP_QSTR_ts,
    MP_QSTR_TypeError,
    MP_QSTR_float,
    MP_QSTR_sep,
    MP_QSTR__star_,
    MP_QSTR_u,
};

// constants
static const mp_rom_obj_tuple_t const_obj_datetime_0 = {{&mp_type_tuple}, 13, {
    MP_ROM_INT(0),
    MP_ROM_INT(31),
    MP_ROM_INT(28),
    MP_ROM_INT(31),
    MP_ROM_INT(30),
    MP_ROM_INT(31),
    MP_ROM_INT(30),
    MP_ROM_INT(31),
    MP_ROM_INT(31),
    MP_ROM_INT(30),
    MP_ROM_INT(31),
    MP_ROM_INT(30),
    MP_ROM_INT(31),
}};
static const mp_rom_obj_tuple_t const_obj_datetime_1 = {{&mp_type_tuple}, 13, {
    MP_ROM_INT(0),
    MP_ROM_INT(0),
    MP_ROM_INT(31),
    MP_ROM_INT(59),
    MP_ROM_INT(90),
    MP_ROM_INT(120),
    MP_ROM_INT(151),
    MP_ROM_INT(181),
    MP_ROM_INT(212),
    MP_ROM_INT(243),
    MP_ROM_INT(273),
    MP_ROM_INT(304),
    MP_ROM_INT(334),
}};
static const mp_obj_int_t const_obj_datetime_3 = {{&mp_type_int}, {.neg=0, .fixed_dig=1, .alloc=3, .len=3, .dig=(uint16_t*)(const uint16_t[]){0x6000,0x1dd7,0x14}}};
static const mp_rom_obj_tuple_t const_obj_datetime_4 = {{&mp_type_tuple}, 6, {
    MP_ROM_QSTR(MP_QSTR_auto),
    MP_ROM_QSTR(MP_QSTR_hours),
    MP_ROM_QSTR(MP_QSTR_minutes),
    MP_ROM_QSTR(MP_QSTR_seconds),
    MP_ROM_QSTR(MP_QSTR_milliseconds),
    MP_ROM_QSTR(MP_QSTR_microseconds),
}};
static const mp_obj_str_t const_obj_datetime_5 = {{&mp_type_str}, 33124, 35, (const byte*)"\x64\x61\x74\x65\x74\x69\x6d\x65\x2e\x74\x69\x6d\x65\x64\x65\x6c\x74\x61\x28\x6d\x69\x63\x72\x6f\x73\x65\x63\x6f\x6e\x64\x73\x3d\x7b\x7d\x29"};
static const mp_obj_str_t const_obj_datetime_7 = {{&mp_type_str}, 36012, 25, (const byte*)"\x64\x61\x74\x65\x74\x69\x6d\x65\x2e\x74\x69\x6d\x65\x7a\x6f\x6e\x65\x28\x7b\x7d\x2c\x20\x7b\x7d\x29"};
static const mp_obj_str_t const_obj_datetime_8 = {{&mp_type_str}, 18617, 25, (const byte*)"\x64\x61\x74\x65\x74\x69\x6d\x65\x2e\x64\x61\x74\x65\x28\x7b\x7d\x2c\x20\x7b\x7d\x2c\x20\x7b\x7d\x29"};
static const mp_obj_str_t const_obj_datetime_9 = {{&mp_type_str}, 64590, 49, (const byte*)"\x64\x61\x74\x65\x74\x69\x6d\x65\x2e\x74\x69\x6d\x65\x28\x6d\x69\x63\x72\x6f\x73\x65\x63\x6f\x6e\x64\x3d\x7b\x7d\x2c\x20\x74\x7a\x69\x6e\x66\x6f\x3d\x7b\x7d\x2c\x20\x66\x6f\x6c\x64\x3d\x7b\x7d\x29"};
static const mp_obj_str_t const_obj_datetime_10 = {{&mp_type_str}, 43248, 58, (const byte*)"\x64\x61\x74\x65\x74\x69\x6d\x65\x2e\x64\x61\x74\x65\x74\x69\x6d\x65\x28\x7b\x7d\x2c\x20\x7b\x7d\x2c\x20\x7b\x7d\x2c\x20\x7b\x7d\x2c\x20\x7b\x7d\x2c\x20\x7b\x7d\x2c\x20\x7b\x7d\x2c\x20\x7b\x7d\x2c\x20\x66\x6f\x6c\x64\x3d\x7b\x7d\x29"};

// constant table
static const mp_rom_obj_t const_obj_table_data_datetime[11] = {
    MP_ROM_PTR(&const_obj_datetime_0),
    MP_ROM_PTR(&const_obj_datetime_1),
    MP_ROM_QSTR(MP_QSTR__percent_04d_hyphen__percent_02d_hyphen__percent_02d),
    MP_ROM_PTR(&const_obj_datetime_3),
    MP_ROM_PTR(&const_obj_datetime_4),
    MP_ROM_PTR(&const_obj_datetime_5),
    MP_ROM_QSTR(MP_QSTR__brace_open__brace_close__brace_open__brace_close__space_day_brace_open__brace_close__comma__space_),
    MP_ROM_PTR(&const_obj_datetime_7),
    MP_ROM_PTR(&const_obj_datetime_8),
    MP_ROM_PTR(&const_obj_datetime_9),
    MP_ROM_PTR(&const_obj_datetime_10),
};

static const mp_frozen_module_t frozen_module_datetime = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_datetime,
        .obj_table = (mp_obj_t *)&const_obj_table_data_datetime,
    },
    .proto_fun = &proto_fun_datetime__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// collection of all frozen modules

const char mp_frozen_names[] = {
    #ifdef MP_FROZEN_STR_NAMES
    MP_FROZEN_STR_NAMES
    #endif
    "base64.py\0"
    "datetime.py\0"
    "\0"
};

const mp_frozen_module_t *const mp_frozen_mpy_content[] = {
    &frozen_module_base64,
    &frozen_module_datetime,
};

#ifdef MICROPY_FROZEN_LIST_ITEM
MICROPY_FROZEN_LIST_ITEM("base64", "base64.py")
MICROPY_FROZEN_LIST_ITEM("datetime", "datetime.py")
#endif

/*
byte sizes:
qstr content: 177 unique, 2126 bytes
bc content: 9343
const str content: 685
const int content: 6
const obj content: 880
const table qstr content: 0 entries, 0 bytes
const table ptr content: 72 entries, 288 bytes
raw code content: 174 * 4 = 2784
mp_frozen_mpy_names_content: 23
mp_frozen_mpy_content_size: 8
total: 16143
*/
