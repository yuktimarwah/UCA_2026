#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 40000

void randomArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

void ascendingArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

void descendingArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }

        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}




void merge(int arr[], int l, int m, int r)
{
    int n1=m-l+1;
    int n2=r-m;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];

    for(int i=0;i<n2;i++)
        R[i]=arr[m+1+i];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    while(i<n1)
        arr[k++]=L[i++];

    while(j<n2)
        arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}




int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;

            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;

    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}



int main()
{
    int sizes[] = {8000,12000,16000,20000,24000,28000,32000,36000};

    int original[40000];
    int temp[40000];

    clock_t start, end;
    double timeTaken;

    srand(time(NULL));

    for(int s=0; s<8; s++)
    {
        int n = sizes[s];

        printf("\n============================================\n");
        printf("INPUT SIZE = %d\n", n);
        printf("============================================\n");

        // ---------------- RANDOM ARRAY ----------------

        printf("\n----- RANDOM ARRAY -----\n");

        randomArray(original,n);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        selectionSort(temp,n);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Selection Sort : %.2f ms\n",timeTaken);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        bubbleSort(temp,n);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Bubble Sort    : %.2f ms\n",timeTaken);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        mergeSort(temp,0,n-1);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Merge Sort     : %.2f ms\n",timeTaken);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        quickSort(temp,0,n-1);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Quick Sort     : %.2f ms\n",timeTaken);


        // ---------------- ASCENDING ARRAY ----------------

        printf("\n----- ASCENDING ARRAY -----\n");

        ascendingArray(original,n);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        selectionSort(temp,n);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Selection Sort : %.2f ms\n",timeTaken);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        bubbleSort(temp,n);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Bubble Sort    : %.2f ms\n",timeTaken);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        mergeSort(temp,0,n-1);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Merge Sort     : %.2f ms\n",timeTaken);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        quickSort(temp,0,n-1);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Quick Sort     : %.2f ms\n",timeTaken);


        // ---------------- DESCENDING ARRAY ----------------

        printf("\n----- DESCENDING ARRAY -----\n");

        descendingArray(original,n);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        selectionSort(temp,n);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Selection Sort : %.2f ms\n",timeTaken);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        bubbleSort(temp,n);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Bubble Sort    : %.2f ms\n",timeTaken);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        mergeSort(temp,0,n-1);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Merge Sort     : %.2f ms\n",timeTaken);

        memcpy(temp,original,n*sizeof(int));
        start=clock();
        quickSort(temp,0,n-1);
        end=clock();
        timeTaken=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Quick Sort     : %.2f ms\n",timeTaken);
    }

    return 0;
}











