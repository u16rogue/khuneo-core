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

kh_bool kh_utf8_is_alpha(const kh_utf8 c);
kh_bool kh_utf8_is_num(const kh_utf8 c);
kh_bool kh_utf8_is_hex(const kh_utf8 c);
kh_bool kh_utf8_is_whitespace(const kh_utf8 c);

