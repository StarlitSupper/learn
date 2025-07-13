#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

void initList(LinkList* L) {
	(*L) = (Node*)malloc(sizeof(Node));
	if ((*L) == NULL) {
		printf("Failed to initList!\n");
		return;
	}
	(*L)->next = NULL;
}

void CreateList(LinkList L, char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Failed to open file!\n");
		return;
	}
	char head[100] = "";
	Node *s, *r;

	r = L;  // 尾指针
	fgets(head, 100, fp);	// 用来跳过表头
	while (1) {
		s = (Node*)malloc(sizeof(Node));
		s->next = NULL;
		if (fscanf(fp, "%d,%[^,],%[^,],%s", &s->user.id, s->user.name, s->user.pwd, s->user.tel) != 4) {
			free(s);
			break;
		}
		r->next = s;
		r = s;
		
	}
	
	fclose(fp);
}

int listLength(LinkList L) {
	Node *p;
	int count = 0;
	
	p = L->next;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

void printList(LinkList L) {
	Node *p;
	p = L->next;
	int count = 1;
	while (p) {
		printf("记录 %d\n", count++);
		printf("用户ID: %d\n", p->user.id);
		printf("用户名: %s\n", p->user.name);
		printf("用户密码: %s\n", p->user.pwd);
		printf("联系方式: %s\n", p->user.tel);
		printf("\n");
		
		p = p->next;
	}
}

void insertList(LinkList L) {
	int length = listLength(L) + 1;
	int k = 0;
	int i = 0;
	Node *pre, *s;
	pre = L;
	
	printf("请输入插入的位置 (1-%d): ", length);
	scanf(" %d", &i);
	while (pre != NULL && k < (i-1)) {
		pre = pre->next;
		k++;
	}
	if (pre == NULL) {
		printf("插入位置不合理!\n");
		return;
	}
	
	s =(Node*)malloc(sizeof(Node));
	printf("请输入用户ID: ");
	scanf(" %d", &s->user.id);
	printf("请输入用户名: ");
	scanf("%s", s->user.name);
	printf("请输入用户密码: ");
	scanf("%s", s->user.pwd);
	printf("请输入联系方式: ");
	scanf("%s", s->user.tel);
	s->next = pre->next;
	pre->next = s;
}
	

void deleteList(LinkList L) {
	int length = listLength(L);
	int i = 0;
	int k = 0;
	Node *pre, *s;
	pre = L;
	
	printf("请输入删除位置 (1-%d): ", length);
	scanf(" %d", &i);
	while (pre != NULL && k < (i-1)) {
		pre = pre->next;
		k++;
	}
	if (pre->next == NULL) {
		printf("删除结点的位置不合理!\n");
		return;
	}
	s = pre->next;
	pre->next = pre->next->next;
	free(s);
	printf("成功删除记录 %d!\n", i);
	printf("\n");
}

void updateList(LinkList L) {
	int length = listLength(L);
	int i = 0;
	int k = 0;
	char c;
	Node *cur;
	cur = L;
	
	printf("请输入修改记录 (1-%d): ", length);
	scanf(" %d", &i);
	while (cur != NULL && k < i) {
		cur = cur->next;
		k++;
	}
	if (cur == NULL) {
		printf("修改位置不合理!\n");
		return;
	}
	printf("当前记录信息:\n");
	printf("  用户ID: %d\n", cur->user.id);
	printf("  用户名: %s\n", cur->user.name);
	printf("  用户密码: %s\n", cur->user.pwd);
	printf("  联系电话: %s\n", cur->user.tel); 
	printf("\n");
	
	while ((c = getchar()) != '\n' && c != EOF);	// 清除输入缓存
	printf("修改用户ID(Y/N): ");
	c = getchar();
	if (c == 'Y' || c == 'y') {
		printf("请输入用户ID: ");
		scanf(" %d", &cur->user.id);
	}
	while ((c = getchar()) != '\n' && c != EOF);
	printf("修改用户名(Y/N): ");
	c = getchar();
	if (c == 'Y' || c == 'y') {
		printf("请输入用户名: ");
		scanf("%s", cur->user.name);
	}
	while ((c = getchar()) != '\n' && c != EOF);
	printf("修改用户密码(Y/N): ");
	c = getchar();
	if (c == 'Y' || c == 'y') {
		printf("请输入用户密码: ");
		scanf("%s", cur->user.pwd);
	}
	while ((c = getchar()) != '\n' && c != EOF);
	printf("修改联系方式(Y/N): ");
	c = getchar();
	if (c == 'Y' || c == 'y') {
		printf("请输入联系方式: ");
		scanf("%s", cur->user.tel);
	}
	while ((c = getchar()) != '\n' && c != EOF);
	printf("记录更新成功!\n\n");
}

void searchList(LinkList L) {
	char scan[20];
	int count = 0;
	Node *p;
	p = L->next;
	
	printf("请输入要搜索的用户名: ");
	scanf("%s", scan);
	while (p != NULL) {
		count++;
		if (strcmp(p->user.name, scan) == 0) {
			printf("记录 %d\n",count);
			printf("用户id: %d\n", p->user.id);
			printf("用户名: %s\n", p->user.name);
			printf("用户密码: %s\n", p->user.pwd);
			printf("联系方式: %s\n", p->user.tel);
			printf("\n");
		}
		p = p->next;
	}		
}

void destroyList(LinkList L) {
	Node *p;
	
	while (L) {
		p = L;
		L = L->next;
		free(p);
	}
}


void writeToFile(LinkList L, char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Failed to open file!\n");
		return;
	}
	Node *p;
	p = L->next;
	
	fprintf(fp, "id,name,pwd,tel\n");
	while (p) {
		fprintf(fp, "%d,%s,%s,%s\n", p->user.id, p->user.name, p->user.pwd, p->user.tel);
		p = p->next;
	}
		
	fclose(fp);
}
