#ifndef SELECTION_H
#define SELECTON_H

/***********************************************************************
 * Justin Pulido
 * Selection.h
 * January 28th, 2018
 * The Selection.h file holds the objects for each comparable 
***********************************************************************/
using namespace std;

template <typename Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right)
{
	int center = (left +  right)/2;

	if(a[center] < a[left]) {
		swap(a[left], a[center]);
	}
	if(a[right] < a[left]) {
		swap(a[left], a[right]);
	}
	if(a[right] < a[center]) {
		swap(a[center], a[right]);
	}

	//place pivot at position right - 1
	swap(a[center], a[right - 1]);
	return a[right - 1];
}


template <typename Iterator, typename Comparator>
void insertionSort(const Iterator & begin, const Iterator & end, Comparator lessThan)
{
	if(begin == end) {
		return;
	}

	Iterator j = 0;
	for(Iterator p = begin + 1; p != end; ++p) {
		auto temp = move(*p);
		for(j = p; j != begin && lessThan(temp, *(j-1)); --j) {
			*j = move(*(j-1));
		}
		*j = move(temp);
	}
}


template <typename Comparable>
void quickSelect(vector<Comparable> & a, int left, int right, int k)
{
    if( left + 10 <= right) {
        const Comparable & pivot = median3(a, left, right);
    
        //begin partitioning
        int i = left;
        int j = right -1;
        for( ; ; ) {
            while(a[i] < pivot) i++;
            while(pivot < a[j]) j--;
            if (i < j) {
                swap(a[i],a[j]);
            }
            else {
                break;
            }
        }

        swap(a[i], a[right - 1]); //restore Pivot
    
        //recurse, only this part changes 
        if(k <= i) {
            quickSelect(a, left, i - 1, k);
        }
        else if (k > i + 1) {
            quickSelect(a, i + 1, right, k);
        }
    }
    else {
        insertionSort(a, left, right);
    }
}

#endif
                
