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
	// ...
};



// Βοηθητικές συναρτήσεις //////////////////////////////////////////////////////////////////

// Αρχικοποιεί την ταξινομημένη λίστα από τα στοιχεία του vector values.

static void naive_initialize_list(PriorityQueue pqueue, Vector values) {
	// Απλά κάνουμε insert τα στοιχεία ένα ένα (όπως η naive_heapify).
	// Προαιρετικά: sort τα στοιχεία και εισαγωγή όλα μαζί (πιο αποδοτικό).
	// ...
}


// Συναρτήσεις του ADTPriorityQueue ////////////////////////////////////////////////////////

PriorityQueue pqueue_create(CompareFunc compare, DestroyFunc destroy_value, Vector values) {
	PriorityQueue pqueue = malloc(sizeof(*pqueue));

	// Για την κλήση της συνάρτησης destroy_value, την περνάμε απλά στη list_create
	// οπότε θα καλείται αυτόματα όταν το στοιχείο αφαιρεθεί από τη λίστα.
	pqueue->list = list_create(destroy_value);
	// ...

	// Αν values != NULL, αρχικοποιούμε την ταξινομημένη λίστα.
	if (values != NULL)
		naive_initialize_list(pqueue, values);

	return pqueue;
}

int pqueue_size(PriorityQueue pqueue) {
	return 0;
}

Pointer pqueue_max(PriorityQueue pqueue) {
	return NULL;
}

void pqueue_insert(PriorityQueue pqueue, Pointer value) {

}

void pqueue_remove_max(PriorityQueue pqueue) {

}

DestroyFunc pqueue_set_destroy_value(PriorityQueue pqueue, DestroyFunc destroy_value) {
	// Απλά καλούμε την αντίστοιχη συνάρτηση της λίστας
	return list_set_destroy_value(pqueue->list, destroy_value);
}

void pqueue_destroy(PriorityQueue pqueue) {

}
