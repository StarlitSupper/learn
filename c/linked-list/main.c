#include <stdio.h>
#include "list.h"

int main(void) {
	LinkList L = NULL;
	initList(&L);
	CreateList(L, "user.csv");
	
	int choice = 0;
	
	while (choice != 6) {
		printf("用户管理\n");
		printf("1: 打印用户信息\n");
		printf("2: 新增用户\n");
		printf("3: 删除用户\n");
		printf("4: 修改用户信息\n");
		printf("5: 查找用户\n");
		printf("6: 退出并保存\n");
		printf("\n");
		printf("请输入你的选择: ");
		scanf(" %d", &choice);
		printf("\n");
	
		switch (choice) {
			case 1: printList(L);
			break;
			case 2: insertList(L);
			break;
			case 3: deleteList(L);
			break;
			case 4: updateList(L);
			break;
			case 5: searchList(L);
			break;
			case 6: writeToFile(L, "output.csv");
			break;
		}
	}
	
	destroyList(L);
	
	return 0;
}
