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