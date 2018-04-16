#pragma once
#include  "tree.h"
//好多激活函数认不到。
typedef enum ACTIVATION {
	LOGISTIC, RELU, RELIE, LINEAR, RAMP, TANH, PLSE, LEAKY, ELU, LOGGY, STAIR, HARDTAN, LHTAN
} ACTIVATION;
//什么叫做二进制激活？
typedef enum BINARY_ACTIVATION {
	MULT, ADD, SUB, DIV
} BINARY_ACTIVATION;

typedef enum LAYER_TYPE {
	CONVOLUTIONAL,
	DECONVOLUTIONAL,
	CONNECTED,
	MAXPOOL,
	SOFTMAX,
	DETECTION,
	DROPOUT,
	CROP,
	ROUTE,
	COST,
	NORMALIZATION,
	AVGPOOL,
	LOCAL,
	SHORTCUT,
	ACTIVE,
	RNN,
	GRU,
	LSTM,
	CRNN,
	BATCHNORM,
	NETWORK,
	XNOR,
	REGION,
	YOLO,
	REORG,
	UPSAMPLE,
	LOGXENT,
	L2NORM,
	BLANK
} LAYER_TYPE;

typedef enum COST_TYPE {
	SSE, MASKED, L1, SEG, SMOOTH, WGAN
} COST_TYPE;

typedef struct update_args {
	int batch;
	float learning_rate; //学习率
	float momentum;//动量
	float decay;//衰减:调节模型复杂度对损失函数的影响,防止过拟合。
				//weight dacay is one kind of regularization.
	int adam; //一个优化算法。
	float B1; //pass
	float B2; //pass
	float eps;//pass
	int t;//pass
} update_args;

typedef struct layer {
	LAYER_TYPE type;
	ACTIVATION activation;
	COST_TYPE cost_type; //每一层都有不同的cost函数么，不是一个网络的cost是相同的吗？
	void(*forward)   (struct layer, struct network);
	void(*backward)  (struct layer, struct network);
	void(*update)    (struct layer, update_args);
	void(*forward_gpu)   (struct layer, struct network);
	void(*backward_gpu)  (struct layer, struct network);
	void(*update_gpu)    (struct layer, update_args);
	int batch_normalize; //bn
	int shortcut;//pass，可能类似于残差网络的F(x)+x。
	int batch;
	int forced; //pass
	int flipped;//pass
	int inputs;
	int outputs;
	int nweights;
	int nbiases;
	int extra; //pass
	int truths;//pass
	int h, w, c;
	int out_h, out_w, out_c;
	int n;
	int max_boxes;//pass
	int groups;//pass
	int size;//pass
	int side;//pass
	int stride;
	int reverse;
	int flatten;
	int spatial;
	int pad;
	int sqrt;
	int flip;
	int index;
	int binary;
	int xnor;//pass
	int steps;
	int hidden;
	int truth;//pass
	float smooth;//pass
	float dot;//pass
	float angle;//角度
	float jitter;//抖动
	float saturation;//饱和度
	float exposure;//曝光度。
	float shift;
	float ratio;//pass,比率？
	float learning_rate_scale;//pass
	float clip;//pass，修剪？
	int softmax;
	int classes;
	int coords;
	int background;
	int rescore; //pass
	int objectness;
	int joint;//pass
	int noadjust;
	int reorg;
	int log;
	int tanh;
	int *mask;//pass
	int total;

	float alpha;//pass
	float beta;//pass
	float kappa;//pass

	float coord_scale;//pass
	float object_scale;//pass
	float noobject_scale;//pass
	float mask_scale;//pass
	float class_scale;//pass
	int bias_match;
	int random;
	float ignore_thresh;
	float truth_thresh;
	float thresh;
	float focus;//pass
	int classfix;
	int absolute;

	int onlyforward;
	int stopbackward;
	int dontload;
	int dontsave;
	int dontloadscales;

	float temperature;
	float probability;
	float scale;

	char  * cweights;
	int   * indexes;
	int   * input_layers;
	int   * input_sizes;
	int   * map;
	float * rand;
	float * cost;
	float * state;
	float * prev_state;
	float * forgot_state;
	float * forgot_delta;
	float * state_delta;
	float * combine_cpu;
	float * combine_delta_cpu;

	float * concat;
	float * concat_delta;

	float * binary_weights;

	float * biases;
	float * bias_updates;

	float * scales;
	float * scale_updates;

	float * weights;
	float * weight_updates;

	float * delta;
	float * output;
	float * loss;
	float * squared;
	float * norms;

	float * spatial_mean;
	float * mean;
	float * variance;

	float * mean_delta;
	float * variance_delta;

	float * rolling_mean;//pass
	float * rolling_variance;//pass

	float * x;
	float * x_norm;

	float * m;//pass
	float * v;//pass

	float * bias_m;
	float * bias_v;
	float * scale_m;
	float * scale_v;


	float *z_cpu;
	float *r_cpu;
	float *h_cpu;
	float * prev_state_cpu;

	float *temp_cpu;
	float *temp2_cpu;
	float *temp3_cpu;

	float *dh_cpu;
	float *hh_cpu;
	float *prev_cell_cpu;
	float *cell_cpu;
	float *f_cpu;
	float *i_cpu;
	float *g_cpu;
	float *o_cpu;
	float *c_cpu;
	float *dc_cpu;

	float * binary_input;

	struct layer *input_layer;
	struct layer *self_layer;
	struct layer *output_layer;

	struct layer *reset_layer;
	struct layer *update_layer;
	struct layer *state_layer;

	struct layer *input_gate_layer;
	struct layer *state_gate_layer;
	struct layer *input_save_layer;
	struct layer *state_save_layer;
	struct layer *input_state_layer;
	struct layer *state_state_layer;

	struct layer *input_z_layer;
	struct layer *state_z_layer;

	struct layer *input_r_layer;
	struct layer *state_r_layer;

	struct layer *input_h_layer;
	struct layer *state_h_layer;

	struct layer *wz;
	struct layer *uz;
	struct layer *wr;
	struct layer *ur;
	struct layer *wh;
	struct layer *uh;
	struct layer *uo;
	struct layer *wo;
	struct layer *uf;
	struct layer *wf;
	struct layer *ui;
	struct layer *wi;
	struct layer *ug;
	struct layer *wg;

	tree *softmax_tree;

	size_t workspace_size;

#ifdef GPU
	int *indexes_gpu;

	float *z_gpu;
	float *r_gpu;
	float *h_gpu;

	float *temp_gpu;
	float *temp2_gpu;
	float *temp3_gpu;

	float *dh_gpu;
	float *hh_gpu;
	float *prev_cell_gpu;
	float *cell_gpu;
	float *f_gpu;
	float *i_gpu;
	float *g_gpu;
	float *o_gpu;
	float *c_gpu;
	float *dc_gpu;

	float *m_gpu;
	float *v_gpu;
	float *bias_m_gpu;
	float *scale_m_gpu;
	float *bias_v_gpu;
	float *scale_v_gpu;

	float * combine_gpu;
	float * combine_delta_gpu;

	float * prev_state_gpu;
	float * forgot_state_gpu;
	float * forgot_delta_gpu;
	float * state_gpu;
	float * state_delta_gpu;
	float * gate_gpu;
	float * gate_delta_gpu;
	float * save_gpu;
	float * save_delta_gpu;
	float * concat_gpu;
	float * concat_delta_gpu;

	float * binary_input_gpu;
	float * binary_weights_gpu;

	float * mean_gpu;
	float * variance_gpu;

	float * rolling_mean_gpu;
	float * rolling_variance_gpu;

	float * variance_delta_gpu;
	float * mean_delta_gpu;

	float * x_gpu;
	float * x_norm_gpu;
	float * weights_gpu;
	float * weight_updates_gpu;
	float * weight_change_gpu;

	float * biases_gpu;
	float * bias_updates_gpu;
	float * bias_change_gpu;

	float * scales_gpu;
	float * scale_updates_gpu;
	float * scale_change_gpu;

	float * output_gpu;
	float * loss_gpu;
	float * delta_gpu;
	float * rand_gpu;
	float * squared_gpu;
	float * norms_gpu;
#ifdef CUDNN
	cudnnTensorDescriptor_t srcTensorDesc, dstTensorDesc;
	cudnnTensorDescriptor_t dsrcTensorDesc, ddstTensorDesc;
	cudnnTensorDescriptor_t normTensorDesc;
	cudnnFilterDescriptor_t weightDesc;
	cudnnFilterDescriptor_t dweightDesc;
	cudnnConvolutionDescriptor_t convDesc;
	cudnnConvolutionFwdAlgo_t fw_algo;
	cudnnConvolutionBwdDataAlgo_t bd_algo;
	cudnnConvolutionBwdFilterAlgo_t bf_algo;
#endif
#endif
}layer;