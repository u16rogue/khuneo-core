#include <kh-core/utf8.h>

kh_sz kh_utf8_char_len(const kh_utf8 c) {
  kh_u8 mask = *(kh_u8 *)&c & 0xF0;
  if (~mask & 0x80)
    return 1;

#if 0
  // mask & 1100.0000 == 1000.0000 // Checks if the byte is 1000.0000 which means its not the starting byte
  if ((mask & 0xC0) == 0x80) {
    return -1; // Invalid starting character (not head)
  }
#endif

  kh_sz sz = -1;
  while (mask & 0x80) {
    mask <<= 1;
    ++sz;
  }

  if (!sz)
    return KH_U8_INVALID;
  return sz + 1;
}

kh_u8 kh_utf8_char_to_num(const kh_utf8 c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  return KH_U8_INVALID;
}

kh_u8 kh_utf8_hexchar_to_nibble(const kh_utf8 c) {
  kh_u8 v = kh_utf8_char_to_num(c);
  if (v != KH_U8_INVALID)
    return v;
  if (c >= 'A' && c <= 'F') {
    return c - 'A' + 0xA;
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 0xa;
  }

  return KH_U8_INVALID;
}

kh_bool kh_utf8_strcmp(const kh_utf8 * a, const kh_utf8 * b) {
  while (*a == *b) {
    if (!*a)
      return 1;
    ++a;
    ++b;
  }
  return 0;
}

kh_bool kh_utf8_strcpy(kh_utf8 * dst, const kh_utf8 * src) {
  while (*src) {
    *dst = *src;
    ++dst;
    ++src;
  }
  *dst = '\0';
  return 1;
}

#if 0
kh_bool kh_utf8_u32_str(const kh_u32 n, kh_utf8 * out, kh_sz sz) {
  if (sz < 2)
    return 0;

  if (n == 0) {
    out[0] = '0';
    out[1] = '\0';
    return 1;
  }

  kh_utf8 tmp[11]; // 2^10 + null term
  kh_u32 mod = 10;
  kh_u32 div = 0;
  kh_u32 res = 0;

  kh_u32 i = 0;

  while (div < n) {
    if (div == 0) {
      res = n % mod;
      mod = 100;
      div = 10;
    } else {
      res = n % mod / div;
      mod *= 10;
      div *= 10;
    }

    tmp[i] = '0' + res;

    ++i;
    --sz;

    if (sz < 1 || i > 10) // shouldnt exceed 10 since that's way off the maximum u32
      return 0;
  }

  --i;
  for (;;) {
    *out = tmp[i];
    if (i == 0)
      break;
    --i;
    ++out;
  }

  return 1;
}
#endif

kh_bool kh_utf8_is_alpha(const kh_utf8 c) {
  return c >= 'A' && c <= 'Z' ||
         c >= 'a' && c <= 'z';
}

kh_bool kh_utf8_is_num(const kh_utf8 c) {
  return c >= '0' && c <= '9';
}

kh_bool kh_utf8_is_hex(const kh_utf8 c) {
  return kh_utf8_is_num(c) || c >= 'A' && c <= 'F' || c >= 'a' && c <= 'f';
}

kh_bool kh_utf8_is_whitespace(const kh_utf8 c) {
  return c == '\r' || c == '\t' || c == '\n';
}
