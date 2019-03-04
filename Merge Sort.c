#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 100000
int arr[SIZE];
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

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
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{

    int j,k,l;

    for(j= 0;j<SIZE;j++)
    {
        arr[j] = rand();
    }

    FILE *fp, *fw ;
    fp = fopen("MERGE_SORT_INPUT.txt", "w");

    // Printing Inputs in a TXT File
    for(k=0;k<SIZE;k++)
    {
        fprintf(fp, "%d\n", arr[k]);
    }
    fclose(fp);
    printf("Numbers Inserted in the MERGE_SORT_INPUT.TXT FILE & Sorted using\n");
    printf("Insertion Sort in the MERGE_SORT_OUTPUT.TXT FILE Successfully\n");

    //Measuring The Time Taken for Insertion Sort to Execute

    //Printing Output in a Separate TXT File
     mergeSort(arr,0,SIZE-1);
    fw = fopen ("MERGE_SORT_OUTPUT.txt", "w");
    for(l=0;l<SIZE;l++)
    {
        fprintf(fw, "%d\n", arr[l]);
    }

    fclose(fw);
    return 0;
}
