#pragma once

typedef struct tree{
	int *leaf;
	int n;
	int *parent;
	int *child;
	int *group;
	char **name;

	int groups;
	int *group_size;
	int *group_offset;
} tree;