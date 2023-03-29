#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criado por Mateus Fernandes de Quadros
//Para a disciplina "Laboratório de Programação II"

typedef struct {
        int codigo;
        char nome[81];
        char endereco[81];
        float peso;
        int altura;
        char sexo;
        float salario;
        } pessoas;

void dadostodos(int i, pessoas* Pessoa){
   int j;
    for(j = 0; j < i; j++){
        printf("%s  ID  %d - %s %g kg %d cm Sexo: %c R$ %g \n", Pessoa[j].nome, Pessoa[j].codigo, Pessoa[j].endereco, Pessoa[j].peso, Pessoa[j].altura, Pessoa[j].sexo, Pessoa[j].salario);
    }
}

float mediapeso(int i, pessoas* Pessoa){
   int j, soma = 0, med, contador = 0;
    for(j = 0; j < i; j++){
        if((Pessoa[j].sexo == 'F') || (Pessoa[j].sexo == 'f') ){
            soma += Pessoa[j].peso;
            contador++;
        }
    }
        if(contador == 0){
        printf("Erro: Não há mulheres! \n");
    } else{
        med = soma/contador;
        printf("A Média do peso das mulheres é %d \n", med);
        return med;
    }
}

void mediasalarial(int i, pessoas* Pessoa){
   int j;
   float soma = 0, med, contador = 0;
    for(j = 0; j < i; j++){
        if((Pessoa[j].sexo == 'M') || (Pessoa[j].sexo == 'm') ){
            soma += Pessoa[j].salario;
            contador++;
        }
    }

    if(contador == 0){
        printf("Erro: Não há Homens! \n");
    } else{
    med = soma/contador;
    printf("A Média do salário dos homens é R$ %g \n", med);
    }
}

void imctodos(int i, pessoas* Pessoa){
   int j;
   float imc, alturam;
    for(j = 0; j < i; j++){
        alturam = ((float)Pessoa[j].altura / 100);
        imc = Pessoa[j].peso / (alturam * alturam);
        printf("%s - IMC de %.1f \n", Pessoa[j].nome, imc);
    }
}

void maisalto(int i, pessoas* Pessoa){
   int j = 0;
   int max = Pessoa[j].altura;
   char nomemaisalto[81];
    for(j = 1; j < i; j++){
        if(Pessoa[j].altura > max){
            max = Pessoa[j].altura;
            strcpy(nomemaisalto, Pessoa[j].nome);
        }
    }
    printf("A pessoa mais alta se chama: %s \n", nomemaisalto);
}

void maisbaixo(int i, pessoas* Pessoa){
   int j = 0;
   int min = Pessoa[j].altura;
   int IDmin = 0;
    for(j = 0; j < i; j++){
        if(Pessoa[j].altura < min){
            min = Pessoa[j].altura;
            IDmin = Pessoa[j].codigo;
        }
    }
    printf("O ID da pessoa mais baixa é: %d \n", IDmin);
}

void salarioacimamedia(int i, pessoas* Pessoa){
   int j = 0, contador = 0, soma = 0, med = 0;
    for(j = 0; j < i; j++){
        soma += Pessoa[j].salario;
    }
        med = soma/i;

    for(j = 0; j < i; j++){
        if(Pessoa[j].salario > med){
            contador++;
        }
    }
    printf("Um total de %d pessoas possuem salários acima da média \n", contador);
}

void medpesofem(int i, pessoas* Pessoa){
   int j = 0;
   float soma = 0, med = 0, contador = 0;
        med = mediapeso(i, Pessoa);
        contador = 0;
    for(j = 0; j < i; j++){
        if((Pessoa[j].sexo == 'F') || (Pessoa[j].sexo == 'f') ){
            if(Pessoa[j].peso < med){
            contador++;
            }
        }
    }
    printf("Portando há um total de %.0f mulheres com o peso abaixo da média feminina \n", contador);
}

void salarioatemil(int i, pessoas* Pessoa){
   int j = 0;
    for(j = 0; j < i; j++){
        if(Pessoa[j].salario < 1000){
            printf("%s - %s", Pessoa[j].nome, Pessoa[j].endereco);
        }
    }
}

void ledados(int i, pessoas* Pessoa){
    int j, l;
    char temp; // Criado para limpar o buffer e facilitar leitura de strings.
    for(j = 0; j < i; j++){
    printf("Insira o ID da pessoa %d: ", j+1);
    scanf("%d", &Pessoa[j].codigo);
    scanf("%c",&temp);

    printf("Insira o Nome da pessoa %d: ", j+1);
    scanf("%[^\n]", &Pessoa[j].nome);
    scanf("%c",&temp);

    printf("Insira o endereço da pessoa %d: ", j+1);
    fgets(Pessoa[j].endereco, 81, stdin);

    printf("Insira o peso da pessoa %d (em kg): ", j+1);

    scanf("%f", &Pessoa[j].peso);


    printf("Insira a altura da pessoa %d (em cm): ", j+1);
    scanf("%d", &Pessoa[j].altura);

    printf("Insira o sexo da pessoa (F/M) %d: ", j+1);
    scanf("%c",&temp);
    scanf("%c", &Pessoa[j].sexo);

    printf("Insira o salário da pessoa %d: ", j+1);
    scanf("%c",&temp);
    scanf("%f", &Pessoa[j].salario);

    }
}

int main (){

    int i, selecao;
    printf("Insira a quantidade de pessoas: ");
    scanf("%d", &i);
    pessoas Pessoa[i];
    ledados(i, Pessoa);

    printf("1 - Dados de todas as pessoas; \n");
    printf("2 - Média de peso das mulheres; \n");
    printf("3 - Média de salário dos homens; \n");
    printf("4 - IMC de todas as pessoas; \n");
    printf("5 - O nome da pessoa mais alta; \n");
    printf("6 - O ID da pessoa mais baixa; \n");
    printf("7 - A quantidade de pessoas que ganham acima da média de salários; \n");
    printf("8 - A quantidade de pessoas do sexo feminino que estão abaixo da média de peso das pessoas de mesmo sexo; \n");
    printf("9 - O nome e endereço das pessoas que ganham menos de R$ 1000; \n");
    printf("Escolha o tipo de Relatório (1-9) ou insira 0 para sair: \n");


    refaz1:
    scanf("%d", &selecao);

    switch ( selecao ){

    case 0:
    exit(0);
    break;

    case 1 :
    dadostodos(i, Pessoa);
    goto refaz;
    break;

    case 2 :
    mediapeso(i, Pessoa);
    goto refaz;
    break;

    case 3 :
    mediasalarial(i, Pessoa);
    goto refaz;
    break;

    case 4 :
    imctodos(i, Pessoa);
    goto refaz;
    break;

    case 5 :
    maisalto(i, Pessoa);
    goto refaz;
    break;

    case 6 :
    maisbaixo(i, Pessoa);
    goto refaz;
    break;

    case 7 :
    salarioacimamedia(i, Pessoa);
    goto refaz;
    break;

    case 8 :
    medpesofem(i, Pessoa);
    goto refaz;
    break;

    case 9 :
    salarioatemil(i, Pessoa);
    goto refaz;
    break;

    default :
    printf ("Por favor selecione uma operação válida (1-9) ou insira 0 para sair:\n");
    goto refaz1;

    refaz:
    printf("Selecione Outra operação (1-9) ou insira 0 para sair: ");
    goto refaz1;

  }
}
