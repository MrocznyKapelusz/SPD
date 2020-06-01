#include "Kopiec.h"
#include <algorithm>



void Job::showJob() {
	std::cout << "R: " << R << " P: " << P << " Q: " << Q << " init index: " << initialIndex + 1 << "\n";
}

void Build_Heap(Job* tab, int *size, char op)//last arg - M for MinHeap, X for MaxHeap
{
	switch (op)
	{
	case 'M':
	{
		for (int i = (*size / 2); i >= 1; i--)
		{
			Heapify_Min(tab,size,i);
		}
		break;
	}
	case 'X':
	{
		for (int i = (*size / 2); i >= 1; i--)
		{
			Heapify_Max(tab,size,i);
		}
		break;
	}
	default:
		break;
	}
	
}

void SwapJobArr(Job* tab,int a,int b)
{
	Job* tmp = new Job;
	*tmp = *(tab + a);
	*(tab + a) = *(tab + b);
	*(tab + b) = *tmp;
	delete tmp;
}

void Heapify_Min(Job *tab,int *heap_size, int root) //do zbioru zadań niedostępnych N. W korzeniu ma być element o najmniejszym R
{
	int smallest = root; // Zakładamy że korzeń najmniejszy
	int l = 2 * root + 1; // left = 2*root + 1 
	int r = 2 * root + 2; // right = 2*root + 2

	// Jeśli lewe dziecko wieksze 
	if (l < *heap_size && (*(tab + l)).R < (*(tab+smallest)).R)//tab[smallest].R)
		smallest = l;

	// Jeśli prawe dziecko wieksze 
	if (r < *heap_size && (*(tab + r)).R < (*(tab + smallest)).R)
		smallest = r;

	// Jeśli najwieksze to nie korzeń
	if (smallest != root)
	{
		SwapJobArr(tab, root, smallest); //Wartość najmniejsza idzie do korzenia

		// Rekursywnie należy sprawdzić, czy "stary" korzeń spełnia warunki kopca dla swoich "nowych" dzieci
		Heapify_Min(tab, heap_size, smallest);
	}
}

void Heapify_Max(Job* tab, int *heap_size, int root) //do zbioru zadań dostępnych N. W korzeniu ma być element o największym Q
{
	int biggest = root; // Zakładamy że korzeń najmniejszy
	int l = 2 * root + 1; // left = 2*root + 1 
	int r = 2 * root + 2; // right = 2*root + 2

	// Jeśli lewe dziecko wieksze 
	if (l < *heap_size && (*(tab + l)).Q > (*(tab + biggest)).Q)//tab[smallest].R)
		biggest = l;

	// Jeśli prawe dziecko wieksze 
	if (r < *heap_size && (*(tab + r)).Q > (*(tab + biggest)).Q)
		biggest = r;

	// Jeśli najwieksze to nie korzeń
	if (biggest != root)
	{
		SwapJobArr(tab, root, biggest); //Wartość najmniejsza idzie do korzenia

		// Rekursywnie należy sprawdzić, czy "stary" korzeń spełnia warunki kopca dla swoich "nowych" dzieci
		Heapify_Max(tab, heap_size, biggest);
	}
}

void Pop_MinHeap(Job* tab, int* size, int root)
{
	(*(tab + root)).R = INT_MAX;
	Build_Heap(tab, size, 'M'); //aby przywrócić warunek kopca

}
void Pop_MaxHeap(Job* tab, int* size,int root)
{
	(*(tab + root)).R = INT_MIN;
	Build_Heap(tab, size, 'X'); //aby przywrócić warunek kopca
}

