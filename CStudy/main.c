#pragma once
#include "head.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>
void c_test_for_study();

void fn1()
{
	extern int x;
	printf("fn1(): x=%d\n", x);
}

//文件读写,链表排序
typedef struct Grade {
	char *name;
	float score;
	struct Grade* next;
}SGrade;
void file_read_write()
{
	//从文件中读取学生姓名和对应成绩，按照学生成绩高低建立链表，然后将学生信息按照成绩大小输出到另外一个文件中。
	//原始文件路径:"D:\99Workspace\90Test\学生成绩.txt"
	//格式:沈金龙:99  或者 沈金龙,99
	//目标文件路径:"D:\99Workspace\90Test\学生成绩排序.txt"
	/*
	name:沈金龙,score:99.00
	name:韦小宝,score:96.00
	name:张无忌,score:92.00
	name:阳顶天,score:89.00
	name:卢俊义,score:87.00
	name:佐佐木小次郎,score:59.00
	*/	
	FILE* file_r, *file_d;
	file_r = fopen("D:\\99Workspace\\90Test\\学生成绩.txt", "r");//以只读模式打开文件
	file_d = fopen("D:\\99Workspace\\90Test\\学生成绩排序.txt", "w+");//以读写模式,不存在则新建
	if (file_r == NULL) //如果文件打开失败
	{
		printf("cannot open file!\n");
		return;
	}
	char t_name[20];
	float t_score;
	int i;
	fscanf(file_r,"%s",&t_name);
	fscanf(file_r, "%f", &t_score);
	SGrade* head = (SGrade*)malloc(sizeof(SGrade));
	//fread(&head, sizeof(SGrade), 1, file_r);	
	SGrade* p = head;
	if (t_name != NULL && t_score >= 0)//先处理头指针
	{
		head->name =strdup(t_name);//strdup函数会计算出字符串的长度，然后调用malloc函数在堆上申请相应的空间，最后把字符串的所有字符复制到堆上
		head->score = t_score;
		head->next = NULL;
	}		
	while (!feof(file_r)) //如果不是文件的结尾
	{
		char _name[20];
		float _score;
		fscanf(file_r, "%s", &_name);
		fscanf(file_r, "%f", &_score);
		SGrade* node = (SGrade*)malloc(sizeof(SGrade));//声明新结点
		node->name = strdup(_name);;
		node->score = _score;
		node->next = NULL;
		SGrade* pre=NULL;//前驱结点
		while (p!=NULL)
		{			
			if (node->score > p->score)//如果分数大于当前结点
			{
				if (pre == NULL)//如果当前结点为头结点
				{
					node->next = p;
					head = node;					
				}
				else
				{
					node->next = pre->next;
					pre->next = node;				
				}	
				break;
			}
			else
			{
				if (p->next == NULL)//如果当前结点为尾结点,即next为空
				{
					p->next = node;
					break;
				}
				else
				{
					pre = p;
					p = p->next;
				}				
			}
		}		
		p = head;
	}	
	while (p != NULL)
	{
		printf("name:%s,score:%.2f\n", p->name, p->score);
		fprintf(file_d, "%s %.2f\n", p->name, p->score);
		p = p->next;

	}
		
	int is_close_r = fclose(file_r);
	int is_cloes_d = fclose(file_d);
	return;
}

int main() 
{
	file_read_write();

	system("pause");
	return 0;
#pragma region History

	//printf("Hello World!\n");

	//printf("%d年%s闰年\n",1900,is_leap_year(1900)==1?"是":"不是");

	//triangle_print(10);

	//multi_9();

	//su_shu(1000);

	//the_day_of_year(2008, 8, 8);

	//monkey_eat_peach(1);	

	//printf("第5个人的年龄是%d岁\n", factorial_test(5));

	//xiaoming_dache(12, 9, 18);

	//array_test();

	//paixu_maopao();

	//my_test1();

	//printf("hello world!\n");

	//c_test_for_study();

#pragma endregion	
}

//语法测试校验
void c_test_for_study() 
{
	int x = 10;
	if (x>0)
	{
		int  x = 100;
		x /= 2;
		printf("if语句内, x=%d\n", x);
	}
	printf("main方法内, x=%d\n", x);
	fn1();
	return 0;

//	int input;
//	scanf("%d", &input);
//	if (input > 10) goto OVER10;
//	else goto LESS10;
//OVER10:
//	printf(">10\n"); c_test_for_study(); return;
//LESS10:
//	printf("<10\n"); c_test_for_study(); return;
}

int x = 77;





