#pragma once
//����ʲôtree��������ʲô�ģ�
typedef struct tree{
	int *leaf;//Ҷ�ӣ���child�Ĺ�ϵ��
	int n; 
	int *parent;
	int *child;
	int *group;
	char **name;

	int groups;
	int *group_size;
	int *group_offset;
} tree;