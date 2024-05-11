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