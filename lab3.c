#include <stdio.h>

int main(void){
	int C, N; // C é o número de caixas
	scanf("%d %d", &C, &N); // N é o número de pessoas atendidas
	int Cai[C]; // vetor que guarda o tempo atual de atendimento de cada caixa
	for(int i = 0; i<C; i++) // setamos as entradas de cai em 0 
		Cai[i] = 0; // (não estão atendendo ninguém)
	int num_total = 0; // pessoas que demoraram mais de 20min pra serem atendidas
	int fila = N-1; // pessoas a serem atendidas
	int c_ut;  // caixa mais rápido
	int T; // chegada
	int D; // tempo de atendimento
	while(fila >= 0){ // atendendo cada pessoa da fila
		c_ut = 0;
		scanf("%d %d", &T, &D);
		for(int i = 0; i<C; i++) // procurar o caixa mais rápido
			if (Cai[c_ut]>Cai[i])
				c_ut = i;
		if (Cai[c_ut]-T > 20) // adicionar a contagem se for +20min
			num_total += 1;
		if (Cai[c_ut]-T<=0) // se a pessoa chega e o caixa já está livre
			Cai[c_ut] = T;
		Cai[c_ut] += D; // adiciona o tempo de atendimento nesse caixa
		fila -= 1;
	}
	
	printf("%d\n", num_total);

	return 0;


}
