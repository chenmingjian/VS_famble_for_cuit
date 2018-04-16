#pragma once
//这是什么tree，用来做什么的？
typedef struct tree{
	int *leaf;//叶子？和child的关系？
	int n; 
	int *parent;
	int *child;
	int *group;
	char **name;

	int groups;
	int *group_size;
	int *group_offset;
} tree;