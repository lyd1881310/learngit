#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

char x[N], y[N];
int c[N][N], b[N][N];
//数组b: 1表示相等；2表示向上； 3表示向左 

void PrintLCS(i, j){
	if(i==0 || j==0){
		
	}
	else if(b[i][j]==1){
		PrintLCS(i-1, j-1);
		printf("%c", x[i-1]);
	}
	else if(b[i][j]==2){
		PrintLCS(i-1, j);
	}
	else{
		PrintLCS(i, j-1);
	}
}

int main(){
	
	int lx, ly, i, j;
	scanf("%s", x);
	scanf("%s", y);
	lx=strlen(x);
	ly=strlen(y);
	for(i=0; i<=lx; i++){
		c[i][0]=0;
	}
	for(j=0; j<=ly; j++){
		c[0][j]=0;
	}
	for(i=1; i<=lx; i++){
		for(j=1; j<=ly; j++){
			if(x[i-1]==y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			} 
		}
	}
	printf("LCS: %d\n", c[lx][ly]);
	PrintLCS(lx, ly);
	return 0;
}
