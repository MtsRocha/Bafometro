#include <stdio.h>
#include <stdlib.h>

FILE* AbreArquivo(char modo, char caminho[30]){
    FILE *arquivo;
    switch(modo){
        case 'g':
            arquivo = fopen(caminho, "wt");
            break;
        case 'l':
            arquivo = fopen(caminho, "rt");
            break;
        case 'a':
            arquivo = fopen(caminho, "a");
            break;
    }
    if(arquivo==NULL){
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}

void FechaArquivo(FILE *arquivo){
    fclose(arquivo);
}

void Cadastra(char nome[30], int cpf, float nivA){
    FILE *arquivo;
    arquivo = AbreArquivo('a', "relatorio.txt");
    fprintf(arquivo, "%s %d %f\n", nome, cpf, nivA);
    FechaArquivo(arquivo);
}
void Listar(){
    FILE *arquivo;
    char nome[30];
    int cpf;
    float nivA;

    arquivo = AbreArquivo('l', "relatorio.txt");

    while(!feof(arquivo)){ //Enquanto nao for fir do arquivo ele vai ler
        fscanf(arquivo,"%s %d %f ", &nome, &cpf, &nivA);
        printf("Nome: %s - CPF: %d - Nivel de Alcool: %.2f\n", nome, cpf, nivA);
    }
    FechaArquivo(arquivo);
}
int menu() {
    int opcao;
    printf("===============================================\t\n");
    printf("===================BAFOMETRO===================\t\n");
    printf("===============================================\t\n");
    printf("[1] - INSERIR DADOS \n");
    printf("[2] - IMPRIMIR RELATORIO \n");
    printf("[3] - SAIR \n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    system("cls");
    return opcao;
}

int main(){
    char nome[30];
    int cpf;
    float nivA;
    int opcao_selecionada;
    do{
        system("cls");
        opcao_selecionada = menu();
        switch(opcao_selecionada) {
             case 1:
             printf("\nDigite o nome: ");
             setbuf(stdin,NULL);
             gets(nome);
             printf("\nDigite os tres primeiros digitos do cpf: ");
             setbuf(stdin,NULL);
             scanf("%d", &cpf);
             printf("\nRealize a medicao: ");
             scanf("%f", &nivA);
             Cadastra(nome,cpf,nivA);
             system("pause");
             break;
             case 2:
             Listar();
             system("pause");
             break;
             case 3:
             printf("\nObrigado!\n");
             system("pause");
             break;
             default:
             printf("----- Opcao Invalida -----");
             system("pause");
             break;
         }
     }while (opcao_selecionada != 3);

system("pause");
return 0;
}
