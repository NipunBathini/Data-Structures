#include "listbag.h"
#include "type.h"
#include <assert.h>
#include <stdlib.h>

/*
	function to initialize the list, set the sentinels and set the size
	param l the list
	pre: l is not null
	post: l size is 0
*/

void initList (struct list *l) {
	/* FIX ME*/
	assert(l != NULL);
	
	l->head = (struct DLink*)malloc(sizeof(struct DLink));
	assert(l->head != 0);
	
	l->tail = (struct DLink*)malloc(sizeof(struct DLink));
	assert(l->tail != 0);
	
	l->head->next = l->tail;
	l->tail->prev = l->head;
	l->head->prev = NULL;
	l->tail->next = NULL;
	l->size = 0;
}


/*
	_addLink
	Funtion to add a value v to the list before the link l
	param: l the list
	param: lnk the  link to add before
	param: v the value to add
	pre: l is not null
	pre: lnk is not null
	post: l is not empty
*/

void _addLink(struct list *l, struct DLink *lnk, TYPE v)
{
	/* FIX ME*/
	struct DLink *newlink = (struct DLink*)malloc(sizeof(struct DLink));
	assert(newlink != 0);
	
	newlink->value = v;
	newlink->prev = lnk->prev;
	newlink->next = lnk;
	lnk->prev->next = newlink;
	lnk->prev = newlink;
	l->size++;
}


/*
	addFrontList
	Function to add a value to the front of the list, can use _addLink()
	param: l the list
	param: e the element to be added
	pre: l is not null
	post: l is not empty, increased size by 1
*/

void addFrontList(struct list *l, TYPE e)
{
	/* FIX ME*/
	_addLink(l, l->head->next, e);
}

/*
	addBackList
	Function to add a value to the back of the list, can use _addlink()
	param: l the list
	pre: l is not null
	post: l is not empty
*/

void addBackList(struct list *l, TYPE e) {
	/* FIX ME*/
	_addLink(l, l->tail, e);
}

/*
	frontList
	function to return the element in the front of the  list
	param: l the list
	pre: l is not null
	pre: l is not empty
	post: none
*/

TYPE frontList (struct list *l) {
	/* FIX ME*/
	assert(l != 0);
	assert( l->size > 0);
	
	return l->head->next->value;
}

/*
	backList
	function to return the element in the back of the  list
	param: l the list
	pre: l is not null
	pre: l is not empty
	post: l is not empty
*/

TYPE backList(struct list *l)
{
	/* FIX ME*/
	assert(l != 0);
	assert(l->size > 0);
	
	return l->tail->prev->value;
}

/*
	_removeLink
	Function to remove a given link
	param: l the list
	param: lnk the linke to be removed
	pre: l is not null
	pre: lnk is not null
	post: l size is reduced by 1
*/

void _removeLink(struct list *l, struct DLink *lnk)
{
	/* FIX ME*/
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	free(lnk);
	l->size--;
}

/*
	removeFrontList
	Function to remove element from front of list, can use _removelink()
	param: l the list
	pre:l is not null
	pre: l is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct list *l) {
	/* FIX ME*/
	assert(isEmptyList(l) != 1);
	_removeLink(l, l->head->next);
}

/*
	removeBackList
	Function to remove element from back of list, can use _removelink()
	param: l the list
	pre: l is not null
	pre:l is not empty
	post: size reduced by 1
*/

void removeBackList(struct list *l)
{
	/* FIX ME*/
	assert(isEmptyList(l) != 1);
	_removeLink(l, l->tail->prev);
}

/*
	isEmptyList
	param: q the list
	pre: q is not null
	post: none
*/

int isEmptyList(struct list *l) {
	/* FIX ME*/
	if(l->head->next == l->tail && l->tail->prev == l->head){
		return 1;
	}
	return 0;
	
}



/* Recursive implementation of contains()
 Pre: current is not null
 Post: 1 if found, 0 otherwise
 */
int _contains_recursive(struct DLink* current, TYPE e){
	/* FIX ME*/
	if(current->next->value == e){
		return 1;
	}
	else if(current->next->next == NULL){
		return 0;
	}
	else{
		return(_contains_recursive(current->next,e));
	}
}

/* Wrapper function for contains
 Pre: l is not null
 Post: 1 if found, 0 otherwise
 */
int listContains (struct list *l, TYPE e) {
	assert(!isEmptyList(l));
	return _contains_recursive(l->head, e);
}

/* Recursive implementation of remove()*/
void _remove_recursive(struct DLink* current, TYPE e, int* sz){
	/* FIX ME*/
		if(current->value == e){
	    

		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(current);
		*sz = *sz-1;  /* decrease the size by one*/ 
	}
	else if(current->next == NULL){
		return;
	}
	else{
	

		_remove_recursive(current->next, e, sz);
		
	}


}
/* Wrapper for remove()*/
void listRemove (struct list *l, TYPE e) {
	/* FIX ME*/
	assert(!isEmptyList(l));
	return _remove_recursive(l->head, e, &(l->size));

}


void freeList(struct list *q)
{
    /* FIX ME*/
	free(q);
}



