/* vi: set sw=4 ts=4: */
/*
 * SPDX-License-Identifier: GPL-2.0
 *
 * wrapper for target environment
 */

#ifndef UNLZMA_TINY_CONFIG_H_
#define UNLZMA_TINY_CONFIG_H_

#include <config.h>
#include <common.h>
#include <malloc.h>

#if DEBUG
# include <stdio.h>
# include <stdlib.h>
# define DBG(...) do { fprintf(stderr, __VA_ARGS__); fputc('\n', stderr);} while(0)
# define WARN(msg) do { fputs(msg "\n", stderr);} while(0)
#endif

#define ALLOC_PROBS(size) malloc(size)
#define FREE_PROBS(ptr) free(ptr)

#endif /* UNLZMA_TINY_CONFIG_H_ */
