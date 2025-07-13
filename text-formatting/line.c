#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

Line line;

void init_line_buffer(void) {
	line.word_count = 0;
	line.cur_length = 0;
}

void set_line_width(int width) {
	line.line_width = width;
}

int add_word(const char* word) {
	int word_length = strlen(word);
	
	// 计算添加单词后的总长度，要加空格
	int required_length = line.cur_length + word_length;
	if (line.word_count > 0) {
		required_length += line.word_count;	// 已有单词之间都有空格
	}
	
	// 检查一下行宽会不会超出
	if (required_length > line.line_width) {
		return 0;	// 剩余行宽不足
	}
	
	// 分配内存，把单词复制进去
	line.words[line.word_count] = malloc(word_length + 1);	// 字符串要多留一个位
	if (!line.words[line.word_count]) {
		printf("内存分配失败!\n");
		exit(EXIT_FAILURE);
	}
	strcpy(line.words[line.word_count], word);
	
	// 更新行的信息
	line.cur_length += word_length;
	line.word_count++;
	
	return 1;	// 单词成功添加
}

void flush_line(int is_last_line) {
	int i, spaces_needed, spaces_per_gap, remainder;
	
	// 计算需要的空格总数
	spaces_needed = line.line_width - line.cur_length;
	
	if (is_last_line || line.word_count == 1) {
		for (i = 0; i < line.word_count; i++) {
			printf("%s", line.words[i]);
			if (i <  line.word_count - 1) {
				putchar(' ');
			}
		}
	} else {
		spaces_per_gap = spaces_needed / (line.word_count - 1);
		remainder = spaces_needed % (line.word_count - 1);
		
		for (i = 0; i < line.word_count; i++) {
			printf("%s", line.words[i]);
			if (i < line.word_count - 1) {
				for (int j = 0; j < spaces_per_gap; j++) {
					putchar(' ');
				}
				if (remainder > 0) {
					putchar(' ');
					remainder--;
				}
			}
		}
		putchar('\n');
	}
	
	// 释放内存，重置行缓冲区
	for (i = 0; i < line.word_count; i++) {
		free(line.words[i]);
	}
	init_line_buffer();
}
