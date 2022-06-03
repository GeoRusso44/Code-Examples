#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int iErr = -1;

    FILE *f_words = fopen("words.dat", "r");
    FILE *f_matrix = fopen("matrix.dat", "r");

    int n = 0;
    iErr = fscanf(f_words, "%d", &n);

    if (iErr != 1)
    {
        return EXIT_FAILURE;
    }

    char vertex_names[n][50];

    char *pointer_array[n];

    //
    for (int i = 0; i < n; i++)
    {
        pointer_array[i] = &vertex_names[i][0];
    }

    //Scan the words;
    for (int i = 0; i < n; i++)
    {
        iErr = fscanf(f_words, " %s", pointer_array[i]);
        if (iErr <= 0)
        {
            return EXIT_FAILURE;
        }

        //printf("%s\n",pointer_array[i]);
    }
    fclose(f_words);

    //Scan the adjacency matrix:
    int matrix_n;
    iErr = fscanf(f_matrix, "%d", &matrix_n);
    if (iErr != 1 || matrix_n != n)
    {
        return EXIT_FAILURE;
    }

    int adjacencyMatrix[n * n];

    for (int i = 0; i < n * n; i++)
    {
        iErr = fscanf(f_matrix, "%d", &adjacencyMatrix[i]);

        if (iErr != 1)
        {
            return EXIT_FAILURE;
        }
    }
    fclose(f_matrix);

    //Write to .dot file
    FILE *fp = fopen("output.dot", "w");
    iErr = fputs("graph{\n\toverlap=scale",fp);
    if(iErr<=0){
        return EXIT_FAILURE;   
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adjacencyMatrix[i*n+j] == 1 ){
                iErr = fputs("\n\t\"",fp);
                iErr = fputs(pointer_array[i],fp);
                iErr = fputs("\"--\"",fp);
                iErr = fputs(pointer_array[j],fp);
                iErr = fputs("\"",fp);

                adjacencyMatrix[j*n+i] = -1;
            }
            

        }


    }

    iErr = fputs("\n}",fp);
    fclose(fp);

    return EXIT_SUCCESS;
}