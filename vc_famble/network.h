#ifndef __NETWORK_H__
#define __NETWORK_H__
#include "layer.h"
typedef enum learning_rate_policy {
	CONSTANT, STEP, EXP, POLY, STEPS, SIG, RANDOM
} learning_rate_policy;

typedef struct network {
	int n;
	int batch;//batch��С��
	size_t *seen;
	int *t;
	float epoch;//epoch�ĸ�����Ϊʲô��float��
	int subdivisions;
	layer *layers;
	float *output;
	learning_rate_policy policy;
} network;
#endif