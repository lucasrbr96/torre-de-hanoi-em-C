#include <stdio.h>
#include <stdlib.h>
#include "Pilha.c"
int main(){
	printf("\t\t\t Torre de hanoi desenvolvido por Lucas Ramos\n");
	printf("1 - inicializar\n");
	printf("2 - tutorial\n");
	printf("3 - sair\n");
	int resultado;
	scanf("%d", &resultado);
	
	while(resultado != 3){
			switch(resultado){
			case 1: 
				inicio();
			case 2:
				tutorial();
			
		}	
	exit(0);
		
	}
return 0;	
	
}
int inicio(){
		Pilha *pino1 = criar();
		Pilha *pino2 = criar();
		Pilha *pino3 = criar();
		printf("quantos discos?\n");
		int disco = 0;
		scanf("%d", &disco);
		if(disco>=3){
			int i;
			for(i =0; i<disco;i++){
				empilhar(pino1,i);
			}
			inverter3(pino1);
			imprimir(pino1);
			// jogo roda aqui
			while(tamanho(pino3) != disco){
				jogada(pino1,pino2,pino3);
				
			}
		printf("Deseja jogar novamente?\n digite 1 - sim\n digite 2 - não");
		int resultado2;
		scanf("%d",&resultado2);
			if(resultado2 == 1){
				free(pino1);
				free(pino2);
				free(pino3);
				inicio();
			}else if(resultado2==2){
				exit(0);
			}else{
			 printf("sem resposta"); exit(0);		
			}
	}
		else{
			printf("disco fora da faixa permitida(acima de 2 disco)\n");
		}
	
}
void jogada(Pilha* p1,Pilha* p2,Pilha* p3){
		printf("\t\t\tqual disco que mover \n");
		printf("opção 1: pino1-pino2\n");
		printf("opção 2: pino1-pino3\n");
		printf("opção 3: pino2-pino1\n");
		printf("opção 4: pino2-pino3\n");
		printf("opção 5: pino3-pino1\n");
		printf("opção 6: pino3-pino2\n");
		printf("opção 7: dicas\n");
		printf("opção 8: sair\n");
		int opcao =0;
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				mover(p1,p2);
				imprimir(p1);
				imprimir(p2);
				imprimir(p3);
				break;
			case 2:
				mover(p1,p3);
				imprimir(p1);
				imprimir(p2);
				imprimir(p3);
				break;
			case 3:
				mover(p2,p1);
				imprimir(p1);
				imprimir(p2);
				imprimir(p3);
				break;
			case 4:
				mover(p2,p3);
				imprimir(p1);
				imprimir(p2);
				imprimir(p3);
				break;
			case 5:
				mover(p3,p1);
				imprimir(p1);
				imprimir(p2);
				imprimir(p3);
				break;
			case 6:
				mover(p3,p2);
				imprimir(p1);
				imprimir(p2);
				imprimir(p3);
				break;
			case 7:
				dica(p1,p2,p3);
				break;
			case 8:
				exit(0);
				
		}
	
}
void mover(Pilha*origem, Pilha*destino){
	if(tamanho(origem)>0 && ( tamanho(destino)==0 || topo(destino)>topo(origem) )){
		empilhar(destino,desempilhar(origem));
		
		
	}else{
		printf("\t\t\tjogada invalida\n");
		
	}
	
}
void dica(Pilha*p1,Pilha*p2,Pilha*p3){
	//p1 - p2,p3
	printf("\t\t\t algumas dicas de jogadas\n");
	if(tamanho(p1)>0){
		if((tamanho(p2)>0 && topo(p2)>topo(p1)) || tamanho(p2) == 0 ){
			printf("opção 1: pino1-pino2\n");
		}
		if((tamanho(p3)>0 && topo(p3)>topo(p1)) || tamanho(p3) == 0 ){
			printf("opção 2: pino1-pino3\n");
		}
		
	}
	//p2 - p1,p3
	if(tamanho(p2)>0){
		if((tamanho(p1)>0 && topo(p1)>topo(p2)) || tamanho(p1) == 0 ){
			printf("opção 3: pino2-pino1\n");
		}
		if((tamanho(p3)>0 && topo(p3)>topo(p2)) || tamanho(p3) == 0 ){
			printf("opção 4: pino2-pino3\n");
		}
		
	}
	if(tamanho(p3)>0){
		if((tamanho(p1)>0 && topo(p1)>topo(p3)) || tamanho(p1) == 0 ){
			printf("opção 5: pino3-pino1\n");
		}
		if((tamanho(p2)>0 && topo(p2)>topo(p3)) || tamanho(p2) == 0 ){
			printf("opção 6: pino3-pino2\n");
		}
		
	}
}
void tutorial(){
	printf("\t\t\t tutorial \n\t\tO objectivo deste jogo consiste em deslocar todos os discos da haste onde se encontram para uma haste diferente, \nrespeitando as seguintes regras: deslocar um disco de cada vez, o qual deverá ser o do topo de uma das três hastes; cada disco nunca poderá ser colocado sobre outro de diâmetro mais pequeno.");
}



