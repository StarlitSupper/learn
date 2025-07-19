#include <stdio.h>
#include <stdlib.h>
#include "word.h"
#include "line.h"

#define MAX_WORD_LENGTH 300
#define DEFAULT_LINE_WIDTH 65

int main(void) {
	char word[MAX_WORD_LENGTH];
	int is_last_line = 0;
	
	set_line_width(DEFAULT_LINE_WIDTH);
	init_line_buffer();
	
	// 读取数据 (可以通过<sourcefile重定向)
	while (read_word(word, MAX_WORD_LENGTH, stdin) != EOF) {
		if (!add_word(word)) {	// 单词未成功添加，超出行宽
			flush_line(0);	// 非最后一行
			add_word(word);	// 单词添加到新行
		}
	}
		
		// 输出最后一行
	if (line.word_count > 0) {
		flush_line(1);
	}
		
	return 0;
}
