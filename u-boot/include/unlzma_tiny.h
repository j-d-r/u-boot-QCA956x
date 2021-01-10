/* vi: set sw=4 ts=4: */
/*
 * SPDX-License-Identifier: GPL-2.0
 */
#ifndef UNLZMA_TINY_H_
#define UNLZMA_TINY_H_

#include <stdint.h>
#include <stddef.h>

/* Inflate LZMA in_ptr buffer into out_ptr buffer.
 * return decompressed size or (size_t)-1 if failed */

size_t lzma_inflate(const uint8_t *in_ptr, size_t in_size, uint8_t *restrict out_ptr, size_t out_size);

#endif /* UNLZMA_TINY_H_ */
