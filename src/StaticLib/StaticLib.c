﻿#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

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
	if (l->header != NULL) {
		p->pNext = l->header;
		l->header->pPrev = p;
	}
	l->header = p;
	if (l->footer == NULL) {
		l->footer = p;
	}

}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (l->footer != NULL) {
		p->pPrev = l->footer;
		l->footer->pNext = p;
	}
	l->footer = p;
	if (l->header == NULL) {
		l->header = p;
	}
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (p->pPrev != NULL && p->pNext != NULL) {
		p->pNext->pPrev = p->pPrev;
		p->pPrev->pNext = p->pNext;
	}
	else if (p->pNext == NULL && p->pPrev != NULL) {
		p->pPrev->pNext = NULL;
		l->footer = p->pPrev;
	}
	else if (p->pPrev == NULL && p->pNext != NULL) {
		p->pNext->pPrev = NULL;
		l->header = p->pNext;
	}
	else {
		l->header = NULL;
		l->footer = NULL;
	}
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (p->pNext != NULL) {
		if (p->pNext->pNext != NULL) {
			p->pNext->pNext->pPrev = p;
			p->pNext = p->pNext->pNext;
		}
		else {
			p->pNext = NULL;
			l->footer = p;
		}
	}
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (p->pPrev != NULL) {
		if (p->pPrev->pPrev != NULL) {
			p->pPrev->pPrev->pNext = p;
			p->pPrev = p->pPrev->pPrev;
		}
		else {
			p->pPrev = NULL;
			l->header = p;
		}
	}
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
