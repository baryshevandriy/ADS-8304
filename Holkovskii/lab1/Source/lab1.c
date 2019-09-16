#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int counter=0;//для подсчета глубины рекурсии
static int flag=0;//для (не)вывода промежуточных значений

void test(int k){//для вывода глубины рекурсии и промежуточных значений
	for(int i=0;i<counter;i++)
		printf("	");
	printf("f(%d)\n",k);
}

int f(int n){//функция из условия
	int sum=0;
	if (n==1){
		counter--;
		return 1;
		}
	else{
		for(int i=2;i<=n;i++){
			if(flag)
				test(n/i);
			counter++;
			sum+=f(n/i);
			}
		counter--;
		}
	return sum;
}

int main(int argc,char* argv[]){
	int n;
	if(argc==1){
		printf("Введите n: ");
		if((scanf("%d",&n)==0)||(n<1)){
			printf("Incorrect n\n");
			return 0;
			}
		flag=1;
		test(n);
		counter++;
		printf("f(%d)=%d\n",n,f(n));
	}
	else{
		char* path=(char*)calloc(strlen(argv[1])+7,sizeof(char));//открыть файл
		strcat(path,"Tests/");
		strcat(path,argv[1]);
		FILE* file=fopen(path,"r");
		if(!file){
			printf("Incorrect file name\n");
			return 0;
			}
		while(fscanf(file,"%d\n",&n)==1){
			if(n>0)
				printf("f(%d)=%d\n\n",n,f(n));
			else
				printf("%d is Incorrect n\n\n",n);
			}
		fclose(file);
		free(path);
	}
	return 0;
}
