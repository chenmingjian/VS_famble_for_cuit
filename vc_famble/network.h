#ifndef __NETWORK_H__
#define __NETWORK_H__
#include "layer.h"
#include "activations.h"
typedef enum learning_rate_policy {
	CONSTANT, STEP, EXP, POLY, STEPS, SIG, RANDOM
} learning_rate_policy;

typedef struct network {
	int n;
	int batch;//batch大小。
	size_t *seen;
	int *t;
	float epoch;//epoch的个数，为什么是float？
	int subdivisions;
	layer *layers;
	float *output;
	learning_rate_policy policy;

	float learning_rate;
	float momentum;
	float decay;
	float gamma;
	float scale;
	float power;
	int time_steps;
	int step;
	int max_batches;
	float *scales;
	int   *steps;
	int num_steps;
	int burn_in;

	int adam;
	float B1;
	float B2;
	float eps;

	int inputs;
	int outputs;
	int truths;
	int notruth;
	int h, w, c;
	int max_crop;
	int min_crop;
	float max_ratio;
	float min_ratio;
	int center;
	float angle;
	float aspect;
	float exposure;
	float saturation;
	float hue;
	int random;

	int gpu_index;
	tree *hierarchy;

	float *input;
	float *truth;
	float *delta;
	float *workspace;
	int train;
	int index;
	float *cost;
	float clip;

#ifdef GPU
	float *input_gpu;
	float *truth_gpu;
	float *delta_gpu;
	float *output_gpu;
#endif
} network;


network *load_network(char *cfg, char *weights, int clear);
#endif