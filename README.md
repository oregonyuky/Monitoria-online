<img src="https://github.com/oregonyuky/Monitoria-online/assets/152916454/f1647032-2f0e-4df7-a582-a539fc096aa3" width="410"/>

<img src="https://github.com/oregonyuky/Monitoria-online/assets/152916454/91fb6e2b-8b86-4734-8394-540c34d851c5" width="410"/>

<p align="center">
    <img src="https://github.com/oregonyuky/Monitoria-online/assets/152916454/40b83298-cc71-42d9-bba9-3ef035010cb3" width="410">
  </p>

## Ex1
```c
#include <stdio.h>

int main ()
{
	/* Salario: 400 + Comissao
	Comissao: 5% do total de vendas
	
	Loja vende 10 objetos
		Quantidade Vendida
		Preco Unitario
		Valor da Venda de cada objeto
	Valor total das vendas = somatoria das vendas de cada objeto
	Valor Comissao: 5% do valor das vendas
	Encontrar o objeto MAIS VENDIDO e apresentar a posicao no vetor e o preco unitario.*/
	
	int VetQtdeVend[10], posmaior, i;
	float VetPrecoUnit[10], VendaObj, MaiorQtdeVend,VendaTot=0, Comissao;
	
	printf("Informe a Quantidade e o valor unitario de cada objeto:\n");
	for(i=0;i<10;i++)
	{
		printf("Objeto [%d]\n", i);
		printf("Quantidade Vendida: ");
		scanf("%d",&VetQtdeVend[i]);
		printf("Preco Unitario: ");
		scanf("%f", &VetPrecoUnit[i]);
	}
	
	MaiorQtdeVend = VetQtdeVend[0];
	posmaior = 0;
	
	for(i=0; i<10; i++)
	{
		if(VetQtdeVend[i] > MaiorQtdeVend)
		{
			MaiorQtdeVend = VetQtdeVend[i];
			posmaior = i;
		}
		
		VendaObj = VetQtdeVend[i]*VetPrecoUnit[i];
		VendaTot += VendaObj; // VendaTot = VendaTot + VendaObj;
		
		printf("Objeto [%d]\n",i);
		printf("Quantidade Vendida: %d\n", VetQtdeVend[i]);
		printf("Preco Unitario: R$%.2f\n", VetPrecoUnit[i]);
		printf("Valor da Venda do Objeto: R$%.2f\n", VendaObj);
	}
	
	printf("Valor Geral das Vendas: R$%.2f\n", VendaTot);
	Comissao = VendaTot * 0.05;
	printf("Comissao a ser paga ao vendedor: R$%.2f\n", Comissao);
	
	printf("Posicao do Objeto mais vendido: %d\n", posmaior);
	printf("Preco Unitario: R$%.2f\n", VetPrecoUnit[posmaior]);
}
```
## Ex2
```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TF 3

int main ()
{
	//Defini鈬o das variaveis
	int vetNum[TF],vetLugares[TF],num,pos;
	char vetOrigem[TF][20],vetDestino[TF][20],op,aux[20],op2;
	
	//Preenchimento dos vetores sem utiliza鈬o de TL
	for(int i=0;i<TF;i++)
	{
		printf("Digite o numero do voo\n");
		scanf("%d",&vetNum[i]);
		printf("Digite quantos lugares tem\n");
		scanf("%d",&vetLugares[i]);
		printf("Digite a origem do voo\n");
		fflush(stdin);
		gets(vetOrigem[i]);
		printf("Digite o destino do voo\n");
		fflush(stdin);
		gets(vetDestino[i]);
	}
	
	//Entra Lido
	printf("Digite a opcao que deseja\n");
	printf("CONSULTAR [C]\nRESERVAR[R]\nSAIR[S]\n");
	fflush(stdin);//Limpar o buffer
	scanf("%c",&op);
	op=toupper(op);
	
	//Repeticao do menu principal
	while(op!='S'){

		//Verificando qual opera鈬o ele quer fazer
		switch(op)
		{
			//Caso for consulta
			case 'C':
				printf("----------------------\nDeseja consultar pelo o que?\nORIGEM[O]\nDESTINO[D]\nNUMERO[N]\n");//Pergunto o que ele quer consultar
				fflush(stdin);//limpo o buffer
				scanf("%c",&op2);
				op2=toupper(op2);
				//Verificando qual tipo de consulta ele quer fazer
				switch(op2)
				{
					//Caso for pela origem
					case 'O':
						printf("Digite a origem para consultar\n");
						fflush(stdin);
						gets(aux);//Recebo a origem que ele digitar
						
						//Busco a origem no meu vetor de strings
						pos=0;
						while(pos<TF && strcmp(aux,vetOrigem[pos])!=0)
							pos++;
							
						//Verifico se achou o voo
						if(pos<TF)
						{
							printf("Voo de numero [%d]\nOrigem [%s]\nDestino [%s]\nLugares Disponiveis [%d]\n----------------\n",vetNum[pos],vetOrigem[pos],vetDestino[pos],vetLugares[pos]);
						}
						else//Caso nao achou o voo
						{
							printf("Voo com essa origem nao encontrado\n-------------------\n");
						}
						
						break;
					//Caso for por destino
					case 'D':
						printf("Digite o destino para consultar\n");
						fflush(stdin);
						gets(aux);//Recebo o destino
						
						//Busco o destino no vetor de destinos
						pos=0;
						while(pos<TF&& strcmp(aux,vetDestino[pos])!=0)
							pos++;
						
						//Verifico se achou o voo
						if(pos<TF)
						{
							printf("Voo de numero [%d]\nOrigem [%s]\nDestino [%s]\nLugares Disponiveis [%d]\n----------------\n",vetNum[pos],vetOrigem[pos],vetDestino[pos],vetLugares[pos]);
						}
						else//Caso nao achou
						{
							printf("Voo com essa origem nao encontrado\n-------------------\n");
						}
						
						break;
						
					//Caso for pelo numero do voo
					case 'N':
						printf("Digite o numero do voo para consultar\n");
						scanf("%d",&num);//Recebo o numero
						
						//Busco o numero no vetor de numeros de voo
						pos=0;
						while(pos<TF&&num!=vetNum[pos])
							pos++;
						
						//Verifico se achou
						if(pos<TF)
						{
							printf("Voo de numero [%d]\nOrigem [%s]\nDestino [%s]\nLugares Disponiveis [%d]\n----------------\n",vetNum[pos],vetOrigem[pos],vetDestino[pos],vetLugares[pos]);
						}
						else//Caso nao achou
						{
							printf("Voo com essa origem nao encontrado\n-------------------\n");
						}
						break;
				}
				break;
			//Caso queira reservar um voo
			case 'R':
					printf("----------\nDigite o numero do voo que deseja reservar um lugar\n");
					scanf("%d",&num);//Leio o numero do voo
					
					//Busco o numero no vetor de numeros de voo
					pos=0;
					while(pos<TF&&num!=vetNum[pos])
						pos++;
					
					//Verifico se achou
					if(pos<TF)
					{
						//Verifico se ainda tem lugares disponiveis
						if(vetLugares[pos]>0)
						{
							//Printo todas as informa鋏es sobre o voo
							printf("Voo encontrado\n");
							printf("Lugares Disponiveis : %d\n",vetLugares[pos]);
							printf("Origem : %s\n",vetOrigem[pos]);
							printf("Destino : %s\n",vetDestino[pos]);
							
							//Pergunto se ele realmente quer reservar
							printf("Confirma reserva?[S][N]\n");
							fflush(stdin);
							scanf("%c",&op2);//Leio a opera鈬o
							//Caso queira reservar
							if(toupper(op2)=='S')
							{
								printf("Reserva comprada com sucesso\n");
								vetLugares[pos]--;//Retiro um lugar desse voo
							}
							else//Cancelo a reserva
							{
								printf("Reserva cancelada\n");
							}
						}
						else//Caso nao tenha lugares
						{
							printf("Voo lotado\n");
						}

					}
					else//Caso nao tenha encontrado o numero do voo
					{
						printf("Voo nao encontrado\n");
					}
					
					
				break;
				
			//Caso a pessoa tenha digitado uma opcao invalida
			default:
				printf("ERRO, OPCAO INVALIDA\n");
				break;
		}
		//Sai Lido
		printf("Digite a opcao que deseja\n");
		printf("CONSULTAR [C]\nRESERVAR[R]\nSAIR[S]\n");
		fflush(stdin);
		scanf("%c",&op);
		op=toupper(op);		
	}
	
	return 0;
	
}//end
```
## Ex3
```c
#include <stdio.h>
#include <string.h>

#define TF 24

int main()
{
	int vetJane[TF], vetCorre[TF], i, j, opcao, poltrona;
	char setor[15];
	
	for(i = 0; i < TF; i++)//prrenchendo os dois vetores com 1, ou seja, poltronas livres
	{
		vetJane[i] = 1;
		vetCorre[i] = 1;
	}
	printf("### MENU DO ONIBUS ###\n");
	printf("1 - COMPRA DE PASSAGEM\n");
	printf("2 - MAPA DE OCUPACAO DO ONIBUS\n");
	printf("3 - ENCERRAR\n");
	printf("OPCAO:");
	scanf("%d", &opcao);
	while(opcao != 3)
	{
		switch(opcao)
		{
			case 1:
				i = 0;
				while(i < TF && vetJane[i] != 1)
					i++;
				j = 0;
				while(j < TF && vetCorre[j] != 1)
					j++;
				if(i < TF || j < TF)//existe alguma poltrona livre, ou seja, o onibus nao esta lotado
				{
					printf("Qual setor do onibus voce deseja comprar (janela ou corredor):\n");
					fflush(stdin);
					gets(setor);
					if(stricmp(setor, "janela") == 0)
					{
						if(i < TF)
						{
							printf("Qual poltrona voce deseja comprar?\n");
							scanf("%d", &poltrona);
							if(vetJane[poltrona - 1] == 1)
							{
								vetJane[poltrona - 1] = 0;
								printf("Venda efetivada!!!\n");
							}
							else
								printf("Poltrona ocupada!!!\n");
						}
						else
							printf("Todas as poltronas da janela estao ocupadas!!!\n");
					}
					else
					{
						if(j < TF)
						{
							printf("Qual poltrona voce deseja comprar?\n");
							scanf("%d", &poltrona);
							if(vetCorre[poltrona - 1] == 1)
							{
								vetCorre[poltrona - 1] = 0;
								printf("Venda efetivada!!!\n");
							}
							else
								printf("Poltrona ocupada!!!\n");
						}
						else
							printf("Todas as poltronas do corredor estao ocupadas!!!\n");
					}
				}
				else
					printf("ONIBUS LOTADO!!!\n");
				break;
			case 2:
				printf("JANELA\t\tCORREDOR:\n");
				for(i = 0; i < TF; i++)
				{				
					if(vetJane[i] == 0 && vetCorre[i] == 0)
						printf("%d- Ocupada\t%d- Ocupada\n", i+1, i+1);
					else
						if(vetJane[i] == 1 && vetCorre[i] == 0)
							printf("%d- Livre\t%d- Ocupada\n", i+1, i+1);
						else
							if(vetJane[i] == 0 && vetCorre[i] == 1)
								printf("%d- Ocupada\t%d- Livre\n", i+1, i+1);
							else
								printf("%d- Livre\t%d- Livre\n", i+1, i+1);
				}
				break;
		}
		printf("\n### MENU DO ONIBUS ###\n");
		printf("1 - COMPRA DE PASSAGEM\n");
		printf("2 - MAPA DE OCUPACAO DO ONIBUS\n");
		printf("3 - ENCERRAR\n");
		printf("OPCAO:");
		scanf("%d", &opcao);
	}
	
	printf("***PROGRAMA FINALIZADO***!!!\n");
	
	return 0;
}

```
## Ex4
```c
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
```
