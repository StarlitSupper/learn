# learn-c
使用c语言实现的一些内容：
## ./linked-list
实现简单的用户管理，主要是通过命令行菜单选择功能，使用单链表实现从CSV文件中读取数据创建链表，增删查改等功能。
## ./text-formatting
实现文本格式化功能，将输入的文本转换为一定行宽的格式化文本，可以通过重定向达到处理文件内文本的效果。
使用 `./fmt < sourcefile > newfile` 可以生成文件 `newfile`，内有格式化处理好的文本。
### 设计思路
- 单词处理
  - 跳过开头的空格与空行
  - 读取单词字符
  - 判断是否超长，截断处理
- 行缓冲区处理
  ```c
  typedef struct{
	char *words[MAX_WORD];	// 存储当前行的单词指针
	int word_count;		// 当前行的单词数量
	int cur_length;		// 当前行的字符(不包括空格)长度
	int line_width;		// 最大行宽
  } Line;
  ```
  - 初始化行缓冲区
  - 设置行宽
  - 将单词添加进行缓冲区
  - 刷新行缓冲区
