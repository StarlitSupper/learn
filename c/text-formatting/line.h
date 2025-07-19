#ifndef LINE_H
#define LINE_H

#define MAX_WORD 20

// 定义行缓冲区结构
typedef struct{
	char *words[MAX_WORD];	// 存储当前行的单词指针
	int word_count;		// 当前行的单词数量
	int cur_length;		// 当前行的字符(不包括空格)长度
	int line_width;		// 最大行宽
} Line;

extern Line line;

void init_line_buffer(void);
int add_word(const char* word);
void flush_line(int is_last_line);
void set_line_width(int width);

#endif
