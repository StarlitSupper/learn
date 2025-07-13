#include "word.h"
#include <stdio.h>
#include <ctype.h>

int read_word(char* word, int max_length, FILE* fp) {
	int c, i = 0;
	// 跳过文件开头的空格与空行
	while ((c = fgetc(fp)) != EOF) {
		if (!isspace(c)) {
			ungetc(c, fp);
			break;
		}
	}
	
	if (c == EOF) {
		return EOF;
	}
	
	// 读取单词字符
	while ((c = fgetc(fp)) != EOF && !isspace(c)) {
		if (i < max_length - 1) {
			word[i++] = c;
		}
	}
	word[i] = '\0';	// 加入字符串终止符
	
	// 单词超长时，截断发出警告
	if (c != EOF && i >= max_length - 1) {
		printf("单词过长，已截断!\n");
		while((c = fgetc(fp)) != EOF && !isspace(c));	// 处理截断剩余部分
	}
	
	return i;
}
