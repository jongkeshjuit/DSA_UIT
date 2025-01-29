int length(NODE *p) {
    int i = 0;
    while (p) {
        i++;
        p = p->pNext;
    }
    return i;
}

void PrintList(NODE* p) {
	if (p == NULL) {
		cout << "Empty List.";
	}
	else {
        cout << length(p) << endl;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}

NODE* partition(NODE* low, NODE* high) {
    int pivot = high->info;
    NODE* i = low->pNext;
    NODE* j = low;
    
    while (j != high) {
        if (j->info <= pivot) {
            swap(i->info, j->info);
            i = i->pNext;
        }
        j = j->pNext;
    }
    swap(i->info, high->info);
    return i;
}

void quickSort(NODE* low, NODE* high) {
    if (low != NULL && high != NULL && low != high && low != high->pNext) {
        NODE* pivot = partition(low, high);
        quickSort(low, pivot);
        quickSort(pivot->pNext, high);
    }
}

void quicksort_ascending(LIST &L) {
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;
    
    NODE* tail = L.pHead;
    while (tail->pNext != NULL) {
        tail = tail->pNext;
    }
    
    quickSort(L.pHead, tail);
}