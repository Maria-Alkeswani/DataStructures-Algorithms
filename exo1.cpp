#include <stdio.h>
#include<conio.h>
 void insert(int * array ,int  size){
 		for (int i = 0; i < size; i++){
		printf(" give element number  %d :  ",i) ;
		scanf("%d",&array[i]) ;
		}
 }
 void sortarray(int * array ,int  size){
 		for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (array[j] > array[i]){
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;}}}}
void affiche(int * array ,int  size){
	printf("\n-------------ARRAYLIST-------------------\n") ;
		for (int i = 0; i < size;i++)
		printf("%d\n",array[i]) ;
}
int main() {
	int array[1000],size;
	int tst ;
	while(true){
    	printf("\n-------------MENU-------------------\n") ;
    	printf(" 1- insert to arrayklist \n") ;
    	printf(" 2- sorting arraylist \n") ;
    	printf(" 3- affiche arraylist \n ") ;
    	scanf("%d",&tst) ;
    	if(tst==1){
        printf("Array size: ");
        scanf("%d",&size);
        insert(array,size) ;
		printf("\n succes \n") ;
		}
		if(tst==2){
		 sortarray(array,size);
		 printf("\n succes \n") ;
		}
     if(tst==3){
    	affiche(array,size);
		}
    }
	return 0;}
