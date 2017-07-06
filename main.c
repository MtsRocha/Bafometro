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

}
void Cadastra(char nome[30],int cpf, float valorMed){
     FILE *arquivo;
     arquivo = AbreArquivo('a', "Relatorio.txt");
     fprintf(arquivo, "%s %d %f\n", nome, cpf, valorMed);
     FechaArquivo(arquivo);
}
void Listar(){
     FILE *arquivo;
     char nome[30];
     int cpf;
     float valorMed;
     arquivo = AbreArquivo('l', "Relatorio.txt");
     while(!feof(arquivo)){ //Enquanto não chegar ao fim do arquivo ele vai ler
         fscanf(arquivo,"%s %d %f ", &nome, &cpf, &valorMed);
         printf("Nome: %s - Cpf: %d - Nivel de Alcool: %.2f\n", nome, cpf, valorMed);
     }
     FechaArquivo(arquivo);
}
int menu() {
     int opcao;
     printf("===============================================\t\n");
     printf("===================BAFOMETRO===================\t\n");
     printf("===============================================\t\n");
     printf("[1] - Inserir dados \n");
     printf("[2] - Relatorio \n");
     printf("[3] - Sair \n");
     printf("\nEscolha uma opcao: ");
     scanf("%d", &opcao);
     system("cls");
     return opcao;
}
int main()
{
     char nome[30];
     int cpf;
     float valorMed;
     int opcao_selecionada;
     do {
         system("cls");
         opcao_selecionada = menu();
         switch(opcao_selecionada) {
             case 1:
             printf("\nDigite o nome: ");
             setbuf(stdin,NULL);
             scanf("%s", &nome);
             printf("\nDigite o cpf: ");
             setbuf(stdin,NULL);
             scanf("%d", &cpf);
             printf("\nRealize a medicao: ");
             scanf("%f", &valorMed);
             Cadastra(nome,cpf, valorMed);
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
