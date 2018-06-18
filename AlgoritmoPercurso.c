#include <stdio.h>
#include <string.h>


struct VetorOrdenado{

 int vetorInteiro[100];
 int meio;
 int primeiro;
 int ultimo;

};
int index_adicionar;
int vetorInteiro[100];
int main()
{
    index_adicionar = 0;
    alimentarVetor();

   // imprimirVetor();
    puts("Numero procurado: 50");
    puts("");
    printf("Consulta sequencial: \n");
    pesquisarNumero(50);
    printf("\nConsulta dividir e conquistar: \n");
    pesquisarNumeroBin(50);
     puts("");
    return 0;
}

void alimentarVetor()
{
    int index;
    for(index = 0; index < 100; index++)
    {
        inserirVetor(index+1);
    }
}

void inserirVetor(int numero)
{
  int tamanho = sizeof(vetorInteiro);
  if(index_adicionar == tamanho)
  {
      printf("Vetor cheio, não pode mais adicionar");
  }else{

    vetorInteiro[index_adicionar] = numero;
    ordernarVetor();
    index_adicionar++;
  }

}

void imprimirVetor()
{
    int index;
    for(index = 0; index < index_adicionar;index++)
    {
        printf("[ %d ]\n",vetorInteiro[index] );
    }
}

void pesquisarNumero(int numero)
{
    int index, passos, achou;
    passos = 0;
    achou = 0;
    for(index = 0; index < index_adicionar;index++)
    {
        passos +=1;
        if(numero == vetorInteiro[index])
        {
            achou = 1;
            break;
        }
    }
    printf("Quantidade de passos = %d, achou? %d \n", passos, achou);

}

void pesquisarNumeroBin(int numero)
{

    int inicio = 0;
    int fim = 99;
    int meio;

    int passos = 0;
    int achou = 0;

    while(inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        passos++;


        if(numero == vetorInteiro[meio])
        {
            achou = 1;
            break;
        }

        if(vetorInteiro[meio] < numero)
        {
            inicio = meio+1;

        }else
        {
           fim = meio -1;
        }
    }

        printf("Quantidade de passos = %d, achou? %d", passos, achou);


}
void ordernarVetor()
{

    int index, index_interno, menor, swap;


    for(index =0; index < index_adicionar; index++)
    {
       menor = index;
       for(index_interno = index +1 ; index_interno < index_adicionar+1; index_interno++)
       {
           if(vetorInteiro[index_interno] < vetorInteiro[menor])
           {
             menor = index_interno;
           }
       }
       if(index != menor)
       {
           swap = vetorInteiro[index];
           vetorInteiro[index] = vetorInteiro[menor];
           vetorInteiro[menor] = swap;
       }
    }


}

