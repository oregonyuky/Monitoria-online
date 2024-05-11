<img src="https://github.com/oregonyuky/Monitoria-online/assets/152916454/f1647032-2f0e-4df7-a582-a539fc096aa3" width="410"/>

<img src="https://github.com/oregonyuky/Monitoria-online/assets/152916454/91fb6e2b-8b86-4734-8394-540c34d851c5" width="410"/>

<p align="center">
    <img src="https://github.com/oregonyuky/Monitoria-online/assets/152916454/40b83298-cc71-42d9-bba9-3ef035010cb3" width="410">
  </p>

## Ex1
```c
#include <stdio.h>
int main()
{
    int VetQtdeVend[10], i, posmaior;
    float VetPrecoUnit[10], VendaObj, MaiorQtdeVend, VendaTot=0, Comissao;

    printf("Informe a Quantidade e o valor unitario de acda objeto:");
    for(i=0;i<10;i++)
    {
        printf("Objeto [%d]\n", i);
        printf("Quantidade vendida: ");
        scanf("%d", &VetQtdeVend[i]);
        printf("Preco Unitario: ");
        scanf("%f", &VetPrecoUnit[i]);
    }

    MaiorQtdeVend = VetQtdeVend[0];
    posmaior = 0;

    for(i=0;i<10;i++)
    {
        if(VetQtdeVend[i] > MaiorQtdeVend)
        {
            MaiorQtdeVend = VetQtdeVend[i];
            posmaior = i;
        }
        VendaObj = VetQtdeVend[i]*VetPrecoUnit[i];
        VendaTot += VendaObj; 
        printf("Objeto [%d]\n", i);
        printf("Quantidade Vendida: %d\n", VetQtdeVend[i]);
        printf("Preco Unitario: R$%.2f\n", VetPrecoUnit[i]);
        printf("Valor da Venda do Objeto: R$%.2f\n", VendaObj);
    }

    printf("Valor Geral das Vendas: R$%.2f\n", VendaTot);
    Comissao = VendaTot * 0.05;
    printf("Comisao a ser paga ao vendedor: R$%.2f\n", Comissao);

    printf("Posicao do Objeto mais vendido: %d\n", posmaior);
    printf("Preco Unitario: R$%.2f\n", VetPrecoUnit[posmaior]);
    return 0;

}
```
## Ex2
```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define TF 12
int main()
{
    int vetVoo[TF], vetLugares[TF], i, opcao, pos, num;
    char vetOrigem[TF][30], vetDestino[TF][30], op, op2, aux;

    for(i=0;i<TF;i++){
        printf("Digite o numero do voo\n");
        scanf("%d", &vetVoo[i]);
        printf("Digite os lugares disponiveis nesse voo\n");
        scanf("%d", &vetLugares[i]);
        printf("Digite a origem desse voo\n");
        fflush(stdin);
        gets(vetOrigem[i]);
        printf("Digite o destino desse voo\n");
        fflush(stdin);
        gets(vetDestino[i]);
    }

    printf("Digite o que deseja fazer\n");
    printf("[C] - Consultar\n[R] EFETUAR RESERVA\n[S] - SAIR");
    fflush(stdin);
    scanf("%c", &op);
    while(toupper(op)!='S')
    {
        switch(op)
        {
            case 'C':
            printf("Digite pel o que deseja consultar\n");
            printf("[O] - ORIGEM\n[N] - NUMERO DO VOO\n[D]-DESTINO\n");
            fflush(stdin);
            scanf("%c", &op2);
            switch(op2)
            {
                case 'O':
                printf("Digite a origem que deseja buscar\n");
                fflush(stdin);
                gets(aux);

                pos=0;
                while(pos<TF && strcmp(aux, vetOrigem[pos])!=0)
                    pos++;
                    if(pos<TF)
                    {
                        printf("Dados do voo\n");
                        printf("Numero: %d\n", vetVoo[pos]);
                        printf("Lugares: %d\n", vetLugares[pos]);
                        printf("Origem: %s\n", vetOrigem[pos]);
                        printf("Destino: %s\n", vetDestino[pos]);
                    }
                    else
                    {
                        printf("Voo nao encontrado\n");
                    }
                break;
                case 'D':
                printf("Digite o destino que deseja buscar\n");
                fflush(stdin);
                gets(aux);

                pos=0;
                while(pos<TF && strcmp(aux, vetDestino[pos])!=0)
                    pos++;
                if(pos<TF)
                {
                    printf("Dados do voo\n");
                    printf("Numero: %d\n", vetVoo[pos]);
                    printf("Lugares: %d\n", vetLugares[pos]);
                    printf("Origem: %s\n", vetOrigem[pos]);
                    printf("Destino: %s\n", vetDestino[pos]);
                }
                else
                {
                    printf("Voo nao encontrado\n");
                }
                break;
                case 'N':
                printf("Digite o numero do voo que deseja buscar\n");
                scanf("%d", &num);

                pos=0;
                while(pos<TF && num!=vetVoo[pos])
                    pos++;
                if(pos<TF)
                {
                    printf("Dados do voo\n");
                    printf("Numero: %d\n", vetVoo[pos]);
                    printf("Lugares: %d\n", vetLugares[pos]);
                    printf("Origem: %s\n", vetOrigem[pos]);
                    printf("Destino: %s\n", vetDestino[pos]);
                }
                else
                {
                    printF("Voo nao encontrado\n");
                }
                break;
            }
                break;
            case 'R':
                printf("Digite o numero do voo que deseja reservar\n");
                scanf("%d", &num);

                pos=0;
                while(pos<TF && num!=vetVoo[pos])
                    pos++;
                if(pos<TF)
                {
                    if(vetLugares[pos]>0)
                    {
                        printF("Voo encontrado\n");
                        printf("Deseja realiar a reserva? [S] [N]");
                        scanf("%c", &op2);
                        if(toupper(op2)=='S')
                        {
                            printf("Reserva confirmada\n");
                            vetLugares[pos]--;
                        }
                        else
                        {
                            printf("reserva cancelada");
                        }
                    }
                    else
                    {
                        printf("Voo lotado\n");
                    }
                }
                else
                {
                    printf("Voo inexistente\n");
                }
                break;
            default:
                printf("ERRO - OPCAO INVALIDA\n");
        }
        printf("Digite o que deseja fazer\n");
    printf("[C] - Consultar\n[R] EFETUAR RESERVA\n[S] - SAIR");
    fflush(stdin);
    scanf("%c", &op);
    }
}
```
## Ex3
```c
#include <stdio.h>
#include <string.h>
#define TF 24
int main(){
    int vetJane[TF], vetCorre[TF], i,j, opcao, poltrona;
    char setor[15];
    for(i=0;i<TF;i++)
    {
        vetJane[i]  = 1;
        vetCorre[i] = 1;
    }
    printf("### MEDU DO ONIBUS ###\n");
    printf("1 - COMPRA DE PASSAGEM\n");
    prinf("2 - MAPA DE OCUPACAO DO ONIBUS\n");
    printf("3 - ENCERRAR\n");
    printf("OPCAO:");
    scanf("%d", &opcao);
    while(opcao != 3)
    {
        switch(opcao)
        {
            case 1:
            i=0;
            while(i<TF && vetJane[i]!=1)
                i++;
            j=0;
            while(j<TF && vetCorre[j]!=1)
                j++;
            if(i<TF || j<TF)
            {
                printf("Qual setor do onibus veoce deseja comprar (janela ou corrdor):");
                fflush(stdin);
                gets(setor);
                if(strcmp(setor, "janela")==0)
                {
                    if(i<TF)
                    {
                        printf("qual poltrona voce deseja comprar?\n");
                        scanf("%d", &poltrona);
                        if(vetJane[poltrona - 1] == 1)
                        {
                            vetJane[poltrona - 1] = 0;
                            printf("Venda efetivada!!!\n");
                        }
                        else
                        {
                            printf("Poltrona ocupada!!!\n");
                        }
                    }
                    else
                    {
                        printf("Todas as poltronas da jenela estao oupadas!!!\n");
                    }
                }
                else
                {
                    if(j<TF)
                    {
                        printf("Qual poltrona voce deseja comprar?\n");
                        scanf("%d", &poltrona);
                        if(vetCorre[poltrona - 1] == 1)
                        {
                            vetCorre[poltrona - 1] = 0;
                            printf("Venda efetivada!!!\n");
                        }
                        else
                        {
                            printf("todas as poltronas estao ocupadas!!!\n");
                        }
                        
                    }
                    else
                    {
                        printf("Todas as poltronas do corredor estao ocupadas!!!\n");
                    }
                }
            }
            else
            {
                printf("ONIBUS LOTADO!!\n");
            }
            break;
            case 2:
            printf("JANELA\t\tCORREDOR:\n");
            for(i=0;i<TF;i++)
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
        printf("### MENU DO ONIBUS ###\n");
        printf("1 - COMPRA DE PASSAGEM\n");
        prinf("2 - MAPA DE OCUPACAO DO ONIBUS\n");
        printf("3 - ENCERRAR\n");
        printf("OPCAO:");
        scanf("%d", &opcao);
    }
    prinf("***Programa finalizado!!***");
}
```
## Ex4
```c
#include <stdio.h>
#include <string.h>
#define TF 10
#define TFC 20
int main(){
    int codigos[TF], estoque[TF], codCliente[TFC], qtdComprada[TFC], i, codAux, tlc, op, posc, posp, qtd;
    char nomeCliente[TFC][30];

    for(i=0;i<TF;i++){
        printf("Digite o codigo do %d produto: ", i+1);
        scanf("%d", &codigos[i]);
        printf("Digite a quantidade do respectivo produto: ");
        scanf("%d", &estoque[i]);
    }

    printf("######### MENU DE VENDAS #########\n\n");
    printf("[1] - Cadastrar Cliente\n");
    printf("[2] - Realizar Compra\n");
    printf("[0] - Finaliza o programa\n");
    printf("Opcao: ");
    scanf("%d", &op);
    while(op!=0){
        switch(op){
            case 1:
                if(tlc<TFC){
                printf("Digite o codigo do cliente: ");
                scanf("%d", &codAux);
                i=0;
                while(i<tlc && codAux!=codCliente[i])
                    i++;    
                if(i==tlc)
                {
                    codCliente[tlc]=codAux;
                    printf("Digite o nome do cliente: ");
                    fflush(stdin);
                    gets(nomeCliente[tlc]);
                    qtdComprada[tlc]=0;
                    tlc++;
                }
                }
                else
                    printf("A lista de clientes ja esta cheia!\n");
                break;
            case 2:
                printf("Digite o codigo do cliente: ");
                scanf("%d", &codAux);
                i=0;
                while(i<tlc && codAux != codCliente[i])
                    i++;
                if(i<tlc){
                    posc=i;
                    printf("Digite codigo do produto qaue deseja comprar: ");
                    scanf("%d", &codAux);
                    i=0;
                    while(i<TF && codAux!=codigos[i])
                        i++;
                    if(i<TF){
                        posp=i;
                        printf("Digite a quantidade a ser vendida: ");
                        scanf("%d", &qtd);
                        if(qtd<=estoque[posp]){
                            estoque[posp] = estoque[posp]-qtd;
                            qtdComprada[posc] = qtdComprada[posc]+qtd;
                            printf("Compra efetivada!!\n");
                        }
                        else
                            printf("Estoque insuficiente, a quantidade a que pode ser comprada %d\n", estoque[posp]);
                    }
                    else
                        printf("O produto nao seta cadastrado!!\n");
                }               
                else
                    printf("Cliente nao esta cadastrado!!\n");
                break;
            default:
                printf("Opcao invalida!!\n");
        }
         printf("######### MENU DE VENDAS #########\n\n");
        printf("[1] - Cadastrar Cliente\n");
        printf("[2] - Realizar Compra\n");
        printf("[0] - Finaliza o programa\n");
        printf("Opcao: ");
        scanf("%d", &op);
    }
    printf("######### PRODUTOS #########\n\n");
    for(i=0;i<TF;i++){
        printf("Produto: %d Estoque: %d\n", codigos[i], estoque[i]);
    }
    printf("######### CLIENTES #########\n\n");
    for(i=0;i<tlc;i++){
        printf("Nome: %s   cod: %d   qtd Comprada: %d\n", nomeCliente[i], codCliente[i], qtdComprada[i]);
    }
}
```
