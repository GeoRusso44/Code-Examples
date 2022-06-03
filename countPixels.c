#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
int row;
int col;
int **arr;

int pixelCount(int r, int c, int** temp){
	if((r<0||r>row-1)||(c<0||c>col-1)){
		return 0;
	}
	if(temp[r][c]==0){
		return 0;
	}
	if(temp[r][c]==1){
		temp[r][c]=0;
		return pixelCount(r+1,c+1, temp)+pixelCount(r,c+1, temp)+pixelCount(r,c-1, temp)+pixelCount(r+1, c, temp)+pixelCount(r-1, c, temp)+pixelCount(r-1,c+1, temp)+pixelCount(r+1, c-1, temp)+pixelCount(r-1, c-1, temp)+1;
		
	}
}

int main(int argc, char** argv){
	if(argc!=3){
		printf("Invalid input");
		return 1;
	}
	row=atoi(argv[1]);
	col=atoi(argv[2]);
	int** temp;
	arr=malloc(row*sizeof(int*));
	temp=malloc(row*sizeof(int*));
	for(int i=0;i<row;i++){
		arr[i]=malloc(col*sizeof(int));
		temp[i]=malloc(col*sizeof(int));
	}
	srand(time(NULL));
	int countOf1=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			arr[i][j]=rand()%2;
			printf("%d ",arr[i][j]);
			if(arr[i][j]==1){
				countOf1++;
			}
		}
		printf("\n");
	}
	bool stat=true;
	int icor, jcor; 
	double percentage;
	int count;
	do{
		printf("enter coordinate i,j (non-numeric to quit): ");
		if(scanf("%d,%d",&icor,&jcor)!=2){
			stat=false;
			return 1;
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				temp[i][j]=arr[i][j];
			}
		}
		if((icor<0||icor>row-1)||(jcor<0||jcor>col-1)){
			printf("invalid coordinate\n");
		}
		else{
		count=pixelCount(icor,jcor, temp);
		percentage=(double)count/countOf1*100;
		printf("Blob size: %d (%.lf  %% of all 1's)\n", count, percentage);
	}}while(stat);	
}		

