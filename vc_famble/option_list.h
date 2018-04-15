#ifndef __OPTION_LIST_H__
#define __OPTION_LIST_H__

typedef struct {
	char *key;
	char *val;
	int used;
} kvp;

list* read_data_cfg(char *filename);
int read_option(char *s, list *options);
void option_insert(list *l, char *key, char *val);
char *option_find(list *l, char *key);
float option_find_float(list *l, char *key, float def);
float option_find_float_quiet(list *l, char *key, float def);

#endif