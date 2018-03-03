#pragma once
#include "stdio.h" 
#include <malloc.h>
#include <time.h>
#include<memory.h>
#ifndef __HEAD_H__
#define __HEAD_H__
#define OK            0  
#define ERROR        -1  
#define MALLOC_ERROR -2   
#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}

typedef int ElementType;
typedef struct ListNode
{
	ElementType data;
	struct ListNode *next;
}Node;
typedef Node *PNode;

#pragma region Definition

int* twoSum(int* nums, int numsSize, int target);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
int lengthOfLongestSubstring(char* s);
void spiralArray(int n);
void personalRate();
void horseChess();
void horseChess1();
#pragma endregion


#pragma region Lib

//创建链表
int Create_List_Head(PNode h, ElementType data);
//展示链表
void DisPlay(PNode h);
//获取数组长度
int Get_Length_Of_Array(int array[]);

#pragma endregion

#endif