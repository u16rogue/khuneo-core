#pragma once

#include "types.h"

/*
 *  Determine the size of a character by providing a character
 *
 *  Returns a KH_U8_INVALID on an invalid utf8 character.
 */
kh_sz kh_utf8_char_len(const kh_utf8 c);

/*
 *  Converts a character representing a number to its
 *  numerical value
 *
 *  Returns a KH_U8_INVALID on failure.
 */
kh_u8 kh_utf8_char_to_num(const kh_utf8 c);

/*
 *  Converts a character representing a hex value to its
 *  4 bit / nibble numerical value.
 *
 *  Returns a KH_U8_INVALID on failure.
 */
kh_u8 kh_utf8_hexchar_to_nibble(const kh_utf8 c);

kh_bool kh_utf8_strcmp(const kh_utf8 * a, const kh_utf8 * b);

/*
 *  Copies a kh_utf8 string from src to dst
 *  NOTE: Intentionally straight forward implementation for perf
 *  HIGHLY UNSAFE! Only use where buffer checks are done.
 */
kh_bool kh_utf8_strcpy(kh_utf8 * dst, const kh_utf8 * src);

#if 0
/*
 *  Converts a u32 value to a string
 */
kh_bool kh_utf8_u32_str(const kh_u32 n, kh_utf8 * out, kh_sz sz);
#endif

kh_bool kh_utf8_is_alpha(const kh_utf8 c);
kh_bool kh_utf8_is_num(const kh_utf8 c);
kh_bool kh_utf8_is_hex(const kh_utf8 c);
kh_bool kh_utf8_is_whitespace(const kh_utf8 c);

