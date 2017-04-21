#include<stdio.h>

int n, m;
int l[100];
int d[100];
int np[100];

int dp(){
	int c = 0, i = 0;
	while( c-1 <= m){
		d[i] = 0;
		i++;
		c += l[i] + 1;
		np[i] = i+1;
	}

	for(i = 0; i < n; i++){
		int menor = 0x7FFFFFFF;
		c = 0;
		int num = 0;
		for(int j = i; j >= 0; j--){
			c += l[j] + 1;
			if(c-1 > m) break;
			int custo = d[j-1] + ((m - c + 1)*(m - c + 1)*(m - c + 1));
			if(custo < menor){
				menor = custo;
				num = i - j + 1;
			}
		}
	
		np[i] = num;
		d[i] = menor;	
	}

	return d[n-1];
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i=n-1; i>=0; i--){
		scanf("%d", &l[i]);
	}
	
	printf("%d\n", dp());	
	
	for(int i = n-1, j = 1; i >= 0; j++){
		printf("Linha %d tem %d palavras\n", j, np[i]);
		i -= np[i];
	}

	return 0;
}
