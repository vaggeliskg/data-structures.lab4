![run-tests](../../workflows/run-tests/badge.svg)

## Δομές Δεδομένων και Τεχνικές Προγραμματισμού

### Κώδικας Εργαστηρίου 4

Εκφώνηση: https://k08.chatzi.org/labs/lab4/ 

naive_heapify complexity is O(nlogn) (n inserts logn each because of bubble_up)
New complexity O(n) (because of bubble_down)


Πολυπλοκότητες για pq μέσω σωρού :

pqeueu_create is O(n) because of naive_heapify

pqeueu_size, pqueue_set_destroy_value, pqueue_destroy and pqeueu_max obviously O(1) (they just return)

pqeueu_insert is O(logn) because of bubble_up(O(h) but it's a complete tree so O(logn) )

pqueue_remove_max is O(logn) because of bubble_down(O(h) but it's a complete tree so O(logn) )


Πολυπλοκότητες για pq μέσω sorted list :

pqeueu_create is O(n) because of naive_initialize_list (n inserts logn each)

pqeueu_size, pqueue_set_destroy_value, pqueue_destroy and pqeueu_max obviously O(1) (they just return)

pqeueu_insert is O(n) because we cross the list

pqueue_remove_max is O(1) because the element for removal is always first(it just removes the first element)








