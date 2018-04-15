#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "cmd_parser.h"
#include "list.h"
#include "cuda.h"
#include "option_list.h"
void strip(char *s);
void error(const char *s);
void file_error(char *s);
char *fgetl(FILE *fp);
void malloc_error();
#endif