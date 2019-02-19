#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100000

int main()
{

    int array[SIZE],i,j,temp = 0,fR;
    srand(time(0));

    for(fR=0;fR<SIZE;fR++)
        {
            array[fR] = rand();
        }

    //Printing Inputs in a TXT File
    FILE *fp, *fw;
    fp = fopen("INSERTION_SORT_INPUT.txt", "w");

    for(fR=0;fR<SIZE;fR++)
        {
            fprintf(fp,"%d\n",array[fR]);
        }
    fclose(fp);

    //SORTING NUMBERS
    for(fR=1;fR<SIZE;fR++)
        {
        temp = array[fR];
        i = fR - 1;

        while(temp < array[i] && i >=0)
            {
                array[i+1] = array [i];
                i--;
            }
        array [i+1] = temp ;
        }

    printf("Numbers Inserted in the INSERTION_SORT_INPUT.TXT FILE & Sorted using\n");
    printf("Insertion Sort in the INSERTION_SORT_OUTPUT.TXT FILE Successfully\n");

    //Measuring The Time Taken for Insertion Sort to Execute
    printf("\nPress ENTER to see the Time Taken for Insertion Sort to Execute\n");
    getch();

    while(1)
    {
        if(getchar())
            break;
    }
    clock_t t;
    t = clock();
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("|--------------------------------------------------------|\n");
    printf("|  >>Insertion Sort took %f Seconds to Execute<<  |\n", time_taken);
    printf("|--------------------------------------------------------|\n");

    fw = fopen("INSERTION_SORT_OUTPUT.txt", "w");

    //Printing Output in a Separate TXT File
    for(fR=0;fR<SIZE;fR++)
        {
            fprintf(fw,"%d\n",array[fR]);
        }
     fclose(fw);
     return 0;
}
