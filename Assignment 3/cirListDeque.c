#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cirListDeque.h"

/* internal functions interface */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, struct DLink *newLnk);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);

/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void initCirListDeque (struct cirListDeque *q) 
{
	/* FIX ME*/
	assert(q != 0);

    q->size = 0;
    q->Sentinel = (struct DLink *) malloc(sizeof(struct DLink));
    assert(q->Sentinel != 0);
    q->Sentinel->next = q->Sentinel;
    q->Sentinel->prev = q->Sentinel;
}

/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIX ME*/
	struct DLink * newLink = malloc(sizeof(struct DLink));
	
	newLink->value = val;
	newLink->prev = NULL;
	newLink->next = NULL;
	
	return(newLink);	 /*returns the link to store the value*/  
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	newLnk	pointer to the new link to add after the existing link
	pre:	q is not null
	pre: 	lnk and newLnk are not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, struct DLink *newLnk)
{
	/* FIX ME*/
	newLnk->next = lnk->next;
    lnk->next = newLnk;
    newLnk->prev = lnk;
    newLnk->next->prev = newLnk;
	
	
    q->size++;

}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIX ME*/
	struct DLink* newLink = _createLink(val);
    assert(newLink != 0);
    _addLinkAfter(q, q->Sentinel->prev, newLink);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIX ME*/
	struct DLink* newLink = _createLink(val);
    assert(newLink != 0);
    _addLinkAfter(q, q->Sentinel, newLink);
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	/* FIX ME*/
	struct DLink *frontList = q->Sentinel->next;
	
    return frontList->value;
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIX ME*/
	struct DLink *backList = q->Sentinel->prev;
	
    return backList->value;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	pre:	lnk is in the deque 
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIX ME*/
	if(q!=NULL){
		if(q->size != 0){
			if(lnk != 0){
				lnk->prev->next = lnk->next;
				lnk->next->prev = lnk->prev;
				
				free(lnk); /*must free*/
				q->size--;/*decrease size of q*/
			}
		}
	}
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIX ME*/
	if(q!=NULL){
		if(q->size != 0){
			_removeLink(q,q->Sentinel->next);
		}
	}
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
	/* FIX ME*/
	if(q!=NULL){
		if(q->size != 0){
			_removeLink(q,q->Sentinel->prev);
		}
	}
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including backSentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIX ME*/
	struct DLink *org = q->Sentinel->next; /*for the one currently using*/
	struct DLink *proc = q->Sentinel->next->next; /*for the proceeding*/
	
	int i;
	for(i=0; i < q->size; i++){
        free(org);
        org = proc; /*the proceeding will now be in the org*/
	q->size--;
	}
	free(q->Sentinel);
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
	/* FIX ME*/
	if(q!=NULL){
		if(q->size == 0){
			return(1);
		}
	
	else{
		return(0);
	}
	}
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIX ME*/
	
    struct DLink *Prnt = q->Sentinel->next;

	int i;
    for(i = 0; i < q->size; i++){
        printf("%g,", Prnt->value);
        Prnt = Prnt->next;
    }
    printf("\n");	

}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIX ME*/
	struct DLink *org = q->Sentinel;
	struct DLink *flip = q->Sentinel->next;

    int i;
    for(i = 0; i <= q->size; i++){
        org->next = org->prev;
        org->prev = flip;
        org = flip;
        flip = flip->next;
    }
}
