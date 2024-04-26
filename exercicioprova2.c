/*
2) Em uma empresa esta ocorrendo avaliação para possiveis mudanças estratêgicas. para isso será necessário alguns requisitos.
-entrada:
sexo
salario
idade
depto.

a empresa quer saber:
a) o nome do funcionario de maior idade, depto e salario;

b) Quantidade de homens que possuem salario acima de 1500.
c) porcentagem de pessoas com idade acima de 30 anos e salario abaixo de 2000.
d) O depto que possui o menor salario*/

#include <stdio.h>

int qtFuncionarios = 0;
char nome[50][50];
char sexo[50];
float salario[50];
int idade[50];
int dep[50];
int maiorIdade = 0;
int qtHomensSalario = 0;
float qtFunIdadeMaior30SalBaixo2000 = 0;
float menorSalario = 0;
int depMenorSalario = 0;

void Coleta()
{
    printf("Digite a quantidade de funcionarios: ");
    scanf("%i", &qtFuncionarios);
    for(int i = 0; i < qtFuncionarios; i++)
    {
        printf("Digite o nome do funcionario: ");
        scanf("%s", &nome[i]);
        printf("Digite o sexo do funcionario %s : ", nome[i]);
        scanf(" %c", &sexo[i]);
        printf("Digite a idade do funcionario %s : ", nome[i]);
        scanf("%i", &idade[i]);
        printf("Digite o departamento do funcionario %s :", nome[i]);
        scanf("%i", &dep[i]);
        printf("Digite o salario do funcionario %s :", nome[i]);
        scanf("%f", &salario[i]);
    }
}

void Comparacao()
{
    menorSalario = salario[0];
    for(int i = 0; i < qtFuncionarios; i++)
    {
        if(idade[i] > idade[maiorIdade])
        {
            maiorIdade = i;
        }
        if(sexo[i] == 'M' && salario[i] > 1500)
        {
            qtHomensSalario++;
        }
        if(idade[i] > 30 && salario[i] < 2000)
        {
            qtFunIdadeMaior30SalBaixo2000++;
        }
        if(salario[i] < menorSalario) {
            menorSalario = salario[i];
            depMenorSalario = dep[i];
        }
    }
}


void ExibindoResultado()
{
    printf("Funcionario maior idade: %s\nIdade: %i\nDepartamento: %i\nSalario: %.2f\n", nome[maiorIdade], idade[maiorIdade], dep[maiorIdade], salario[maiorIdade]);
    printf("\nQuantidade de homens com salario > 1500: %i\n", qtHomensSalario);
    qtFunIdadeMaior30SalBaixo2000 = (qtFunIdadeMaior30SalBaixo2000 / qtFuncionarios) * 100;
    printf("\nPoncentagem de funcionarios idade >30 salario <2000: %.2f%%\n", qtFunIdadeMaior30SalBaixo2000);
    printf("Departamento que possui o menor salario: %i\n", depMenorSalario);
}

int main()
{
    Coleta();
    Comparacao();
    ExibindoResultado();
    return 0;
}

