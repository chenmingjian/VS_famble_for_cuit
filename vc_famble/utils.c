#include "utils.h"
#include "limits.h"

void error(const char *s)
{
	perror(s);
	assert(0);
	exit(-1);
}
//ȥ���ַ���s�еĿո��Ʊ�����س�����
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

//���ļ��ж�ȡһ�У���Ҫʵ����512BΪ��λ��̬����������
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
//���malloc_error��Ϣ��
void malloc_error()
{
	fprintf(stderr, "Malloc error\n");
	exit(-1);
}