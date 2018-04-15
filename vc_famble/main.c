#include <stdio.h>
#include "utils.h"
#include "network.h"

int gpu_index = 0;

void train(char *datacfg, char *cfgfile, char* weightfile, int *gpus, int ngpus, int clear)
{
	list *options = read_data_cfg(datacfg);
	char *train_images = option_find_str(options, "train", "data/train_addr.txt");
	char *backup_directory = option_find_str(options, "backup", "backup/");
	
	srand(time(0));
	float avg_loss = -1;
	network **nets = calloc(ngpus, sizeof(network));
}



int main(int argc, int **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "usage : %s <function>\n", argv[0]);
		return 1;
	}

	char *prefix = find_char_arg(argc, argv, "-prefix", 0);
	float thresh = find_float_arg(argc, argv, "-thresh", .5);
	float hier_thresh = find_float_arg(argc, argv, "-hier", .5);
	int cam_index = find_int_arg(argc, argv, "-c", 0);
	int frame_skip = find_int_arg(argc, argv, "-s", 0);
	int avg = find_int_arg(argc, argv, "-avg", 3);
	char *outfile = find_char_arg(argc, argv, "-out", 0);
	int clear = find_arg(argc, argv, "-clear");
	int fullscreen = find_arg(argc, argv, "-fullscreen");
	int width = find_int_arg(argc, argv, "-w", 0);
	int height = find_int_arg(argc, argv, "-h", 0);
	int fps = find_int_arg(argc, argv, "-fps", 0);
	char *datacfg = argv[2];
	char *cfg = argv[3];
	char *weights = (argc > 4) ? argv[4] : 0;
	char *filename = (argc > 5) ? argv[5] : 0;

	if (argc < 3) {
		fprintf(stderr, "usage: %s [train/test/valid] [cfg] [weights (optional)]\n", argv[0]);
		return;
	}
	int gpu = 0;
	int *gpus = &gpu;
	int ngpus = 1;

	if (0 == strcmp(argv[1], "train")) train(datacfg, cfg, weights, gpus, ngpus, clear);
	//else if (0 == strcmp(argv[1], "valid")) validate_detector(datacfg, cfg, weights, outfile);
	//else if (0 == strcmp(argv[1], "valid2")) validate_detector_flip(datacfg, cfg, weights, outfile);
	//else if (0 == strcmp(argv[1], "recall")) validate_detector_recall(cfg, weights);
	/*else if (0 == strcmp(argv[1], "demo")) {
		list *options = read_data_cfg(datacfg);
		int classes = option_find_int(options, "classes", 20);
		char *name_list = option_find_str(options, "names", "data/names.list");
		char **names = get_labels(name_list);
		demo(cfg, weights, thresh, cam_index, filename, names, classes, frame_skip, prefix, avg, hier_thresh, width, height, fps, fullscreen);
	}*/
	return 0;
}