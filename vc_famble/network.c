#include "network.h"

network *load_network(char *cfg, char *weights, int clear)
{
	network *net = parse_network_cfg(cfg);
	if (weights && weights[0] != 0) {
		load_weights(net, weights);
	}
	if (clear) (*net->seen) = 0;
	return net;
}