#include<stdio.h>

#define TF 3
#define TFC 3

int main(){
	int codigos[TF],estoque[TF],codClientes[TFC], qtdComprada[TFC],i,op,codAux,tlc=0,posc,posp,qtd;
	char nomeCliente[TFC][30];
	
	for(i=0;i<TF;i++){
		printf("Digite o codigo do produto %d: ",i+1);
		scanf("%d",&codigos[i]);
		printf("Digite a quantidade do respectivo produto: ");
		scanf("%d",&estoque[i]);
	}
	
	printf("######### MENU DE VENDAS #########\n\n");
	printf("[1] - Cadastrar Cliente\n");
	printf("[2] - Realizar Compra\n");
	printf("[0] - Finaliza o programa\n");
	printf("Opcao: ");
	scanf("%d",&op);
	while(op!=0){
		switch(op){
			case 1:
				if(tlc<TFC){
					printf("Digite o codigo do cliente: ");
					scanf("%d",&codAux);
						if(codAux!=0){
							//for(i=0;i<tlc && codAux!=codCliente[i];i++);
							i=0;
							while(i<tlc && codAux!=codClientes[i])
								i++;
							if(i==tlc)
							{
								codClientes[tlc]=codAux;
								printf("Digite o nome do cliente: ");
								fflush(stdin);
								gets(nomeCliente[tlc]);
								qtdComprada[tlc]=0;
								tlc++;
							}
							else
								printf("A lista de clientes ja esta cheia!\n");
						}	
				}	
				break;
			case 2:
				printf("Digite o codigo do cliente: ");
				scanf("%d",&codAux);
				i=0;
				while(i<tlc && codAux!=codClientes[i])
					i++;
				if(i<tlc){
					posc=i;
					printf("Digite codigo do produto que deseja comprar: ");
					scanf("%d",&codAux);
					i=0;
					while(i<TF && codAux!=codigos[i])
						i++;
					if(i<TF){
						posp=i;
						printf("Digite a quantidade a ser vendida: ");
						scanf("%d",&qtd);
						if(qtd<=estoque[posp]){
							estoque[posp]= estoque[posp]-qtd;
							qtdComprada[posc]=qtdComprada[posc]+qtd;
							printf("Compra efetivada!!\n");
						}
						else
							printf("Estoque insuficiente, a quantidade a que pode ser comprada %d\n",estoque[posp]);
					}
					else
						printf("O produto nao esta cadastrado!!\n");
				}
				else
					printf("Cliente nao esta cadastrado!!\n");
				break;
			default:
				printf("Opcao invalida!!\n");
				break;
		}
		printf("######### MENU DE VENDAS #########\n\n");
		printf("[1] - Cadastrar Cliente\n");
		printf("[2] - Realizar Compra\n");
		printf("[0] - Finaliza o programa\n");
		printf("Opcao: ");
		scanf("%d",&op);
	}
	printf("########## PRODUTOS ##########\n\n");
	for(i=0;i<TF;i++)
		printf("Produto: %d Estoque: %d\n",codigos[i],estoque[i]);
		
		
	printf("########## CLIENTES ##########\n\n");
	for(i=0;i<tlc;i++)
		printf("Nome: %s   cod: %d  qtd Comprada: %d\n",nomeCliente[i],codClientes[i],qtdComprada[i]);
}
