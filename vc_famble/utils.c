#include "utils.h"
#include "limits.h"

void error(const char *s)
{
	perror(s);
	assert(0);
	exit(-1);
}
//去掉字符串s中的空格、制表符、回车符。
void strip(char *s)
{
	size_t i;
	size_t len = strlen(s);
	size_t offset = 0;
	for (i = 0; i < len; ++i) {
		char c = s[i];
		if (c == ' ' || c == '\t' || c == '\n') ++offset;
		else s[i - offset] = c;
	}
	s[len - offset] = '\0';
}

void file_error(char *s)
{
	fprintf(stderr, "Couldn't open file: %s\n", s);
	exit(0);
}

//从文件中读取一行，主要实现以512B为单位动态增加容量。
char *fgetl(FILE *fp)
{
	if (feof(fp)) return 0;
	size_t size = 512;
	char *line = malloc(size * sizeof(char));
	if (!fgets(line, size, fp)) {
		free(line);
		return 0;
	}

	size_t curr = strlen(line);

	while ((line[curr - 1] != '\n') && !feof(fp)) {
		if (curr == size - 1) {
			size *= 2;
			line = realloc(line, size * sizeof(char));
			if (!line) {
				printf("%ld\n", size);
				malloc_error();
			}
		}
		size_t readsize = size - curr;
		if (readsize > INT_MAX) readsize = INT_MAX - 1;
		fgets(&line[curr], readsize, fp);
		curr = strlen(line);
	}
	if (line[curr - 1] == '\n') line[curr - 1] = '\0';

	return line;
}
//输出malloc_error信息。
void malloc_error()
{
	fprintf(stderr, "Malloc error\n");
	exit(-1);
}