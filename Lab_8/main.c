#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMARRAYS 6
#define MAXVAL 1000000

void randArray(int A[], int size, int maxVal);
void arrayCopy(int from[], int to[], int size);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
long timeDiff(clock_t start, clock_t end);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
int partition(int *vals, int low, int high);
void quickSort(int* numbers, int low, int high);
void swap(int* a, int* b);
void insertionMergeSort(int arr[], int l ,int r);
void mergeInterstionSort(int arr[], int l, int r);



int main(){

    int sizes[NUMARRAYS] = {10000, 20000, 30000, 40000, 50000, 60000};

    int *originialArray;
    int *sortedArray;
    int i, j;
    clock_t start, end;
    long elapsed;

    for(i = 0; i < NUMARRAYS; i++){
        originialArray = (int *)malloc(sizes[i] * sizeof(int));
        sortedArray = (int *)malloc(sizes[i] * sizeof(int));

        randArray(originialArray, sizes[i], MAXVAL);
        arrayCopy(originialArray, sortedArray, sizes[i]);
        
        start = clock();
        bubbleSort(sortedArray, sizes[i]);

        end = clock();
        elapsed = timeDiff(start, end);
        printf("Sorting %d values took %ld milliseconds for Bubble Sort\n", sizes[i], elapsed);

        arrayCopy(originialArray, sortedArray, sizes[i]);

        start = clock();
        insertionSort(sortedArray, sizes[i]);
        end = clock();
        elapsed = timeDiff(start, end);
        printf("Sorting %d values took %ld milliseconds for Insertion Sort\n", sizes[i], elapsed);

        arrayCopy(originialArray, sortedArray, sizes[i]);

        start = clock();
        selectionSort(sortedArray, sizes[i]);
        end = clock();
        elapsed = timeDiff(start, end);
        printf("Sorting %d values took %ld millisecond for Selection Sort\n", sizes[i], elapsed);

        
        arrayCopy(originialArray, sortedArray, sizes[i]);

        start = clock();
        mergeSort(sortedArray, 0, sizes[i]-1);
        end = clock();
        elapsed = timeDiff(start, end);
        printf("Sorting %d values took %ld milliseconds for Merge Sort\n", sizes[i], elapsed);

        arrayCopy(originialArray, sortedArray, sizes[i]);

        start = clock();
        quickSort(sortedArray, 0, sizes[i]-1);
        end = clock();
        elapsed = timeDiff(start, end);
        printf("Sorting %d values took %ld milliseconds for Quick Sort\n", sizes[i], elapsed);

        arrayCopy(originialArray, sortedArray, sizes[i]);

        start = clock();
        mergeInterstionSort(sortedArray, 0, sizes[i]-1);
        end = clock();
        elapsed = timeDiff(start, end);
        printf("Sorting %d values took %ld milliseconds for Merged Insertion Sort\n", sizes[i], elapsed);
        printf("\n");

        free(originialArray);
        free(sortedArray);
    }

    return 0;
}



void randArray(int A[], int size, int maxVal){
    
    for(int i = 0; i < size; i++){
        A[i] = rand() % maxVal + 1;
    }
}


void arrayCopy(int from[], int to[], int size){
    for(int i = 0; i < size; i++){
        to[i] = from[i];
    }
}



void bubbleSort(int arr[], int n)
{
  

   int i, j,temp;
   for (i = 0; i < n-1; i++)
   {
        
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1]){//then swap
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
}


void insertionSort(int arr[], int n)
{
    int i, item, j;
    for (i = 1; i < n; i++)
    {
         item = arr[i];

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
          for(j=i-1; j>=0; j--)
          {
              if(arr[j]>item)
                arr[j+1] = arr[j];
              else
                break;

          }
          arr[j+1] = item;
    }
}



void selectionSort(int arr[], int n)
{
	int i, j, min_idx, temp;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
	    
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;
		// Swap the found minimum element with the first element
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;

		
	}
}



long timeDiff(clock_t start, clock_t end){
    long elapsed = ((double)(end-start) / CLOCKS_PER_SEC) * 1000;
    return elapsed;
}



void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int *L = (int*) malloc(n1*sizeof(int));
    int *R = (int*) malloc(n2*sizeof(int));

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // get the mid point
        int m = (l+r)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

       // printf("Testing l=%d r=%d m=%d\n", l, r, m);

        merge(arr, l, m, r);
    }
}

void mergeInterstionSort(int arr[], int l, int r)
{
    if (l < r)
    {
        
        if(r-l + 1 <= 25)
        {
            insertionMergeSort(arr, l, r);
            return;
        }

        // get the mid point
        int m = (l+r)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

       // printf("Testing l=%d r=%d m=%d\n", l, r, m);

        merge(arr, l, m, r);
    }
}

void insertionMergeSort(int arr[], int l ,int r)
{
    int i, item, j;
    for (i = 1; i <= r; i++)
    {
         item = arr[i];

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
          for(j=i-1; j>=0; j--)
          {
              if(arr[j]>item)
                arr[j+1] = arr[j];
              else
                break;

          }
          arr[j+1] = item;
    }
}


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Pre-condition: low and high are valid indexes into values
// Post-condition: Returns the partition index such that all the values
//                 stored in vals from index low to until that index are
//                 less or equal to the value stored there and all the values
//                 after that index until index high are greater than that
//
int partition(int *vals, int low, int high)
{
  // Pick a random partition element and swap it into index low.
  int i = low + rand()%(high-low+1);
  swap(&vals[low], &vals[i]);

  int lowpos = low; //here is our pivot located.

  low++; //our starting point is after the pivot.

// Run the partition so long as the low and high counters don't cross.
  while(low<=high)
  {
    // Move the low pointer until we find a value too large for this side.
    while(low<=high && vals[low]<=vals[lowpos]) low++;

    // Move the high pointer until we find a value too small for this side.
    while(high>=low && vals[high] > vals[lowpos]) high--;

    // Now that we've identified two values on the wrong side, swap them.
    if (low<high)
     swap(&vals[low], &vals[high]);
  }

  // Swap the pivot element element into its correct location.
  swap(&vals[lowpos], &vals[high]);

  return high; //return the partition point
}

// Pre-condition: s and f are value indexes into numbers.
// Post-condition: The values in numbers will be sorted in between indexes s
//                 and f.
void quickSort(int* numbers, int low, int high) {

    // Only have to sort if we are sorting more than one number
    if (low < high) {
        int split = partition(numbers,low,high);
        quickSort(numbers,low,split-1);
        quickSort(numbers,split+1,high);
    }
}