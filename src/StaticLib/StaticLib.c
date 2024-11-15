#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include<stdlib.h>

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->pPrev = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
	l->footer = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p)
{
	if (l->header == NULL) {
		l->header = p;
		l->footer = p;
	}
	else {
		l->header->pPrev = p;
		p->pNext = l->header;
		l->header = p;
	}
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (l->header == NULL) {
		l->header = p;
		l->footer = p;
	}
	else {
		l->footer->pNext = p;
		p->pPrev = l->footer;
		l->footer = p;
	}
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (l->header == NULL || p == NULL) return;

	if (p->pPrev != NULL) {
		p->pPrev->pNext = p->pNext;
	}
	else {
		l->header = p->pNext;
	}

	if (p->pNext != NULL) {
		p->pNext->pPrev = p->pPrev;
	}
	else {
		l->footer = p->pPrev;
	}

	p->pNext = NULL;
	p->pPrev = NULL;
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	node* next_node = p->pNext;

	if (l->header == NULL || next_node == NULL) return;

	if (next_node->pPrev != NULL) {
		next_node->pPrev->pNext = next_node->pNext;
	}
	else {
		l->header = next_node->pNext;
	}

	if (next_node->pNext != NULL) {
		next_node->pNext->pPrev = next_node->pPrev;
	}
	else {
		l->footer = next_node->pPrev;
	}

	next_node->pNext = NULL;
	next_node->pPrev = NULL;
	
}


// pの前のノードを削除
void remove_prev(list* l, node* p)
{

	node* ahead_node = p->pPrev;

	if (l->header == NULL || ahead_node == NULL) return;

	if (ahead_node->pPrev != NULL) {
		ahead_node->pPrev->pNext = ahead_node->pNext;
	}
	else {
		l->header = ahead_node->pNext;
	}

	if (ahead_node->pNext != NULL) {
		ahead_node->pNext->pPrev = ahead_node->pPrev;
	}
	else {
		l->footer = ahead_node->pPrev;
	}

	ahead_node->pNext = NULL;
	ahead_node->pPrev = NULL;

}


// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}

// pの前のノードを取得
node* get_prev(list* l, node* p)
{
	if (!p) return NULL;
	return p->pPrev;

	return NULL;
}
