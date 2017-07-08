#include <stdio.h>
#include <stdlib.h>

FILE* AbreArquivo(char modo, char caminho[30]){ //Função que abri o arquivo, modo de abrir//caminho do arquivo)
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
    if(arquivo==NULL){//Erro
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}

void FechaArquivo(FILE *arquivo){//Função que fecha o arquivo
    fclose(arquivo);
}

void Cadastra(int dia, int mes, int ano, char nome[30], int cpf, float alcool){ //Função de Cadastro da ficha do motorista
    FILE *arquivo;
    arquivo = AbreArquivo('a', "relatorio.txt");
    fprintf(arquivo, "%d %d %d %s %d %f\n", dia, mes, ano, nome, cpf, alcool);
    FechaArquivo(arquivo);
}

void Listar(){ //Função que imprime e lista a ficha dos motoristas
    FILE *arquivo;
    int dia, mes, ano,cpf;
    char nome[30];
    float alcool;

    arquivo = AbreArquivo('l', "relatorio.txt");

    while(!feof(arquivo)){ //Enquanto nao for fim do arquivo ele vai ler
        fscanf(arquivo,"%d %d %d %s %d %f ", &dia, &mes, &ano, &nome, &cpf, &alcool);
        printf ("\n\n||----------------------------RELATORIO MOTORISTAS----------------------------||\n\n");
        printf("Data: %d/%d/%d - Nome: %s - CPF: %d - Nivel de Alcool: %.2f\n", dia, mes, ano, nome, cpf, alcool);
    }
    FechaArquivo(arquivo);
}

int menu(){ //Função do menu
    int opcao;
    printf("             ********          *                   **===\n");
    printf("             *        *        **                 ***====\n");
    printf("             *  **     *       * *               * **=====\n");
    printf("             *  **     *       *  *             *  **======\n");
    printf("             *        *        *   *           *   **=======\n");
    printf("             ********          *    *         *    **========\n");
    printf("             *        *        *     *       *     **=========\n");
    printf("             *  **     *       *      *     *      **==========\n");
    printf("             *  **     *       *       *   *       **===========\n");
    printf("             *        *        *        * *        **============\n");
    printf("             *********         *         *         **=============\n\n\n");
    printf("             ===============================================\t\n");
    printf("             ===================BAFOMETRO===================\t\n");
    printf("             ===============================================\t\n\n");
    printf("             [1] - INSERIR DADOS \t\n");
    printf("             [2] - IMPRIMIR RELATORIO \t\n");
    printf("             [3] - ESTATISTICAS \t\n");
    printf("             [4] - DESENVOLVEDORES \t\n");
    printf("             [5] - SAIR \t\n\n");
    printf("             Escolha uma opcao: ");
    scanf("              %d", &opcao);
    system("             cls");
    return opcao;
}

int desenvolvedores(){
    printf("===============================================\t\n");
    printf("==================DESENVOLVEDORES==============\t\n");
    printf("===============================================\t\n\n");
    printf("\tBruno Rodrigues Bueno\t\n");
    printf("\tIsabella Guimaraes Aguiar de Faria\t\n");
    printf("\tMateus Rocha Ferreira\t\n");
    printf("\tMiguel Fernandes Santos Barbosa\t\n");
    printf("\tPaulo Eduardo Furtado Lopes\t\n\n");
    printf("===============================================\t\n");
    printf("===================Copyright/2017==============\t\n");
    printf("===============================================\t\n\n");
}

int main(){
    char nome[30];
    int data, dia, mes, ano, cpf, quantFT = 0, i = 0, opcaoSelecionada, liberados = 0, teste, veiculos = 0, multa = 0, detento = 0, opcao, recusa = 0;
    float alcool , porcRecusa = 0, porcLiberados = 0, porcVeiculos = 0, porcMulta = 0, porcDetento = 0;
    do{
        system("cls");//Apaga
        opcaoSelecionada = menu();
        switch(opcaoSelecionada) {
             case 1:
                printf("Digite a quantidade de motoristas que fizeram o teste hoje: ");
                scanf("%d", &quantFT);
                for(i = 1; i <= quantFT; i++){
                    printf ("O individuo %d se recusou a fazer o teste? [1-SIM/2-NAO] ", i);
                    scanf ("%d", &teste);
                        if (teste==1)
                        {
                            recusa = recusa + 1;
                        }
                        else if (teste==2)
                        {
                            printf("\nDigite a data de hoje[dd/mm/aa]: ");
                            setbuf(stdin,NULL); //Apaga o buffer do teclado
                            scanf("%d/%d/%d", &dia, &mes, &ano);
                            printf("\nDigite o nome: ");
                            setbuf(stdin,NULL);
                            gets(nome);
                            printf("\nDigite os tres primeiros digitos do cpf: ");
                            setbuf(stdin,NULL);
                            scanf("%d", &cpf);
                            printf ("\nDigite a quantidade de alcool lida no bafometro: ");
                            setbuf(stdin,NULL);
                            scanf ("%f",&alcool);
                            setbuf(stdin,NULL);

                            if ((alcool  >= 0) && (alcool<= 50))//Sanções
                            {
                                printf ("Motorista liberado!\n");
                                liberados=liberados+1;
                            }
                            else if ((alcool >= 51) && (alcool <= 200))
                            {
                                printf ("Retenção do veículo e da carteira! O veiculo sera liberado assim que um condutor habilitado se apresentar");
                                veiculos=veiculos+1;
                            }
                            else if ((alcool >= 201) && (alcool <= 400))
                            {
                                printf ("Multa e sete pontos na carteira!");
                                setbuf(stdin,NULL);
                                multa=multa+1;
                            }
                             else if (alcool >= 401)
                            {
                                printf ("Motorista preso!");
                                setbuf(stdin,NULL);
                                detento=detento+1;
                            }
                            fflush(stdin);

                        }
                    }
                Cadastra(dia, mes, ano, nome, cpf, alcool);
                printf("\n==========DADOS GRAVADOS=============\n");
                system("pause");
                break;
             case 2:
                Listar();
                system("pause");
                break;
             case 3:
                porcRecusa=(recusa*100/quantFT); //Calculo das Estatisticas
                porcLiberados=(liberados*100/quantFT);
                porcVeiculos=(veiculos*100/quantFT);
                porcMulta=(multa*100/quantFT);
                porcDetento=(detento*100/quantFT);

                printf ("\n\n||---------------------------RELATORIO ESTATISTICAS----------------------------||\n\n");//Imprime Estatísticas
                printf ("      Quantidade de motoristas abordados: %d\n", quantFT);
                printf ("      Porcentagem dos que se recusaram a fazer o teste: %2.f por cento \n", porcRecusa);
                printf ("      Porcentagem de motoristas liberados: %.2f por cento\n", porcLiberados);
                printf ("      Porcentagem de medidas administrativas: %.2f por cento\n", porcVeiculos);
                printf ("      Porcentagem de multas aplicadas: %.2f por cento\n", porcMulta);
                printf ("      Porcentagem de motoristas presos: %.2f por cento\n", porcDetento);
                printf ("\n\n||--------------------------------FIM RELATORIO--------------------------------||\n\n");
                system("pause");
                break;
             case 4:
                desenvolvedores();
                system("pause");
                break;
            case 5:
                printf("Finalizando...");
                printf("\nObrigado!\n");//Sair
                system("pause");
                break;
             default:
                printf("----- Opcao Invalida -----");
             system("pause");
                break;
         }
     }while (opcaoSelecionada != 5);

system("pause");
return 0;
}
