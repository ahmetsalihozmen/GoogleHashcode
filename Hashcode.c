#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//Question needs some kind of sorting algorithm I use the selection sort.
void selection(float *arrr,int u,int *yerr){
	float maks=-1,arr2[u] ;
	int indis,i=0,j=0;
	for(i=0;i<u;i++){
		arr2[i]=arrr[i];
	}
	for(i=0;i<u;i++){
		for(j=0;j<u;j++){
			if(arr2[j]>maks){
				maks=arr2[j];
				indis=j;
			}
		}
		arr2[indis]=-1;
		yerr[i]=indis;
		maks=-1;
	}
	for(i=0;i<u;i++){
		for(j=i;j<u;j++){
			if(arrr[j]>maks){
				maks=arrr[j];
				indis=j;
			}
		}
		maks=arrr[i];
		arrr[i]=arrr[indis];
		arrr[indis]=maks;
		maks=-1;

	}
}
//This function will give you most valuable book in that library
int max(int *mat,int n){
	int max=-1,i,id;
	for(i=0;i<n;i++){
		if(mat[i]>max && mat[i]>0){
			max=mat[i];
			id=i;
		}
	}
	mat[id]=-1;
	return id;
	

}
//This function will return how much book you can send from that library
int bookfunc(int *mat,int bookNum,int day,int send){
	int sum=0;
	int i=0;
	while(sum<day*send&&ii<bookNum){
		if(mat[ii]>0){
			sum++;
		}
		ii++;
	}
	return summ;
}

int main(){
	//I use
	FILE *a,*b;
	float *sum,top;
	int bookNum,libNum,day,*arr,i,j,k,**lib,*sign,*yer,cont=0,**lib2,z,book;
	a=fopen("a_example.txt","r+");

	fscanf(a,"%d%d%d",&bookNum,&libNum,&day);
		
	arr=(int*)calloc(bookNum,sizeof(int));


	for(i=0;i<bookNum;i++){
		fscanf(a,"%d",&arr[i]);
	}
	
	
	
	lib=(int**)calloc(libNum,sizeof(int*));	
	for(i=0;i<libNum;i++){
		lib[i]=(int*)calloc(3,sizeof(int));
	}
	lib2=(int**)calloc(libNum,sizeof(int*));	
	for(i=0;i<libNum;i++){
		lib2[i]=(int*)calloc(bookNum,sizeof(int));
	}


	sum=(float*)calloc(libNum,sizeof(float));
	sign=(int*)calloc(libNum,sizeof(int));
	yer=(int*)calloc(libNum,sizeof(int));
	
	
	
	for(i=0;i<libNum;i++){
		fscanf(a,"%d%d%d",&lib[i][0],&lib[i][1],&lib[i][2]);
		for(j=0;j<lib[i][0];j++){
			fscanf(a,"%d",&k);
			top=arr[k];
			//Changing this loop will effect the result
			sum[i]+=top/lib[i][0];
			lib2[i][k]=k+1;
		}

			
	}

	selection(sum,libNum,yer);

	i=0;j=0;
	
	
	int libday=day;
	int signNum=0;
	while (i<libNum){
		if((libday-lib[yer[i]][1])>=1){
			libday-=lib[yer[i]][1];
			sign[signNum]=yer[i];
			signNum++;
			if(libday==1){
				i=libNum;
			}
		}
		i++;
	}
	
	b=fopen("a.ou","w");
	fprintf(b,"%d\n",signNum);
	
	for(i=0;i<signNum;i++){

		day-=lib[yer[i]][1];
		book=bookfunc(lib2[yer[i]],bookNum,day,lib[yer[i]][2]);
		fprintf(b,"%d %d\n",yer[i],book);		
		
		for(j=0;j<book;j++){
			z=max(lib2[yer[i]],bookNum);
			fprintf(b,"%d ",z);
		}
		fprintf(b,"\n");
		
	}
	

	
}
