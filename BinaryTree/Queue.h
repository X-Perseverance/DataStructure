#ifndef __Queue_h__
#define __Queue_h__

#include "BTree.h"

typedef BTNode* QDataType;

typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head; //队头指针
	QueueNode* _tail; //队尾指针
}Queue;

//初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->_head = q->_tail = (QueueNode*)malloc(sizeof(QueueNode));
	assert(q->_head&&q->_tail);
	q->_head->_next = NULL;
}

//销毁
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->_head)
	{
		q->_tail = q->_head->_next;
		free(q->_head);
		q->_head = q->_tail;
	}
}

//入队
void QueuePush(Queue* q, QDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);
	newnode->_data = x;
	newnode->_next = NULL;
	q->_tail->_next = newnode;
	q->_tail = newnode;
}

//出队
void QueuePop(Queue* q)
{
	if (q->_head == q->_tail)
	{
		return;
	}
	QueueNode* next = q->_head->_next;
	q->_head->_next = next->_next;
	if (q->_tail == next)
	{
		q->_tail = q->_head;
	}
	free(next);
}

//获取队头元素
QDataType QueueFront(Queue* q)
{
	if (q->_head == q->_tail)
	{
		return NULL;
	}
	else
	{
		return q->_head->_next->_data;
	}
}

//判空
int QueueEmpty(Queue* q)
{
	if (q->_head == q->_tail)
	{
		return 1;
	}
	return 0;
}

#endif __Queue_h__