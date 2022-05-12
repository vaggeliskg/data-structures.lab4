///////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT Priority Queue μέσω ταξινομημένης λίστας.
//
///////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>

#include "ADTPriorityQueue.h"
#include "ADTList.h"			// Η υλοποίηση του PriorityQueue χρησιμοποιεί List


// Ενα PriorityQueue είναι pointer σε αυτό το struct
struct priority_queue {
	List list;		// η λίστα στην οποία αποθηκεύουμε τα στοιχεία
	CompareFunc compare;		
	DestroyFunc destroy_value;
};



// Βοηθητικές συναρτήσεις //////////////////////////////////////////////////////////////////

// Αρχικοποιεί την ταξινομημένη λίστα από τα στοιχεία του vector values.

static void naive_initialize_list(PriorityQueue pqueue, Vector values) {
	// Απλά κάνουμε insert τα στοιχεία ένα ένα (όπως η naive_heapify).
	int size = vector_size(values);
	for(int i = 0 ; i < size ; i++) {
		pqueue_insert(pqueue, vector_get_at(values, i));
	}


	// Προαιρετικά: sort τα στοιχεία και εισαγωγή όλα μαζί (πιο αποδοτικό).
	// ...
}


// Συναρτήσεις του ADTPriorityQueue ////////////////////////////////////////////////////////

PriorityQueue pqueue_create(CompareFunc compare, DestroyFunc destroy_value, Vector values) {
	PriorityQueue pqueue = malloc(sizeof(*pqueue));

	// Για την κλήση της συνάρτησης destroy_value, την περνάμε απλά στη list_create
	// οπότε θα καλείται αυτόματα όταν το στοιχείο αφαιρεθεί από τη λίστα.
	pqueue->list = list_create(destroy_value);
	pqueue->compare = compare;
	pqueue->destroy_value = destroy_value;
	// Αν values != NULL, αρχικοποιούμε την ταξινομημένη λίστα.
	if (values != NULL)
		naive_initialize_list(pqueue, values);

	return pqueue;
}

int pqueue_size(PriorityQueue pqueue) {
	return list_size(pqueue->list);
}

Pointer pqueue_max(PriorityQueue pqueue) {
	return list_node_value(pqueue->list,list_first(pqueue->list));
}

void pqueue_insert(PriorityQueue pqueue, Pointer value) {
	Pointer first_node_value;
	//ListNode last_node = LIST_BOF;
	if(list_size(pqueue->list) == 0) {
		list_insert_next(pqueue->list, LIST_BOF, value);
		return;
	}
	first_node_value = list_node_value(pqueue->list, list_first(pqueue->list));
	if(list_size(pqueue->list) == 1) {
		if(pqueue->compare(first_node_value,value) < 0 )
			list_insert_next(pqueue->list, LIST_BOF , value);
		else if(pqueue->compare(first_node_value,value) >= 0 ) {
			list_insert_next(pqueue->list, list_first(pqueue->list) , value);
			return;
		}
		//last_node = list_last(pqueue->list);
	}
	else if(list_size(pqueue->list) > 1) {
		for(ListNode node = list_first(pqueue->list);
		node != LIST_EOF;
		node = list_next(pqueue->list,node)) {
			if(pqueue->compare(list_node_value(pqueue->list,node),value) < 0) {
				list_insert_next(pqueue->list,LIST_BOF, value);
				return;
			}
			else if(pqueue->compare(list_node_value(pqueue->list,node),value) > 0) {
				ListNode next_node = list_next(pqueue->list, node );
				if(next_node == LIST_EOF) {
					list_insert_next(pqueue->list, node , value);
					return;
				}
				if(pqueue->compare(list_node_value(pqueue->list,next_node),value) < 0) {
					list_insert_next(pqueue->list, node , value);
					return;
				}
			}
			//last_node = node;
		}
	}
}

void pqueue_remove_max(PriorityQueue pqueue) {
	list_remove_next(pqueue->list, LIST_BOF);
}

DestroyFunc pqueue_set_destroy_value(PriorityQueue pqueue, DestroyFunc destroy_value) {
	// Απλά καλούμε την αντίστοιχη συνάρτηση της λίστας
	return list_set_destroy_value(pqueue->list, destroy_value);
}

void pqueue_destroy(PriorityQueue pqueue) {
	list_set_destroy_value(pqueue->list, pqueue->destroy_value);
	list_destroy(pqueue->list);

	free(pqueue);
}
