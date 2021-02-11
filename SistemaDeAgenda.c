#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define PESSOAS 5

FILE* file;

//Definição da Struct
struct informacoes{
    char nomes[PESSOAS][30];
    char enderecos[PESSOAS][30];
    char bairro[PESSOAS][30];
    char cidade[PESSOAS][30];
    char estado[PESSOAS][30];
    int ceps[PESSOAS];
    int telefones[PESSOAS];
    int celulares[PESSOAS];
};
//Declaração da Struct
struct informacoes pessoa;

void menu(){
    printf("===========================\n");
    printf("--- SISTEMA DE CADASTRO ---\n");
    printf("===========================\n\n");
    printf("1 - CADASTRAR\n");
    printf("2 - ALTERAR DADOS\n");
    printf("3 - EXCLUIR CADASTRO\n");
    printf("4 - CONSULTAR DADOS\n");
    printf("5 - SAIR\n\n");
}

void menuAlt(){
    printf("--- Menu de Alteração ---\n");
    printf("1 - NOME\n2 - ENDEREÇO\n3 - BAIRRO\n4 - CIDADE\n5 - ESTADO\n6 - CEP\n7 - TELEFONE\n8 - CELULAR\n");
    printf("O que deseja alterar? ");
}

int get_size(){
    file = fopen("agenda.txt", "r");

    if(file == NULL){
        return 0;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

void zerarArq(){
    file = fopen("agenda.txt", "w");
    fclose(file);
}

void atualArq(int cont){
    file = fopen("agenda.txt", "a");
    for(int j=0; j<cont ; j++){
        fprintf(file, "%s  %s  %s  %s  %s  %i  %i  %i\n", pessoa.nomes[j], pessoa.enderecos[j], pessoa.bairro[j], pessoa.cidade[j], pessoa.estado[j], pessoa.ceps[j], pessoa.telefones[j], pessoa.celulares[j]);
    }
    fclose(file);
}

void cadastrar(){
    file = fopen("agenda.txt", "a");

    if(file == 0){
        printf("Banco de dados não encontrado!\n");
        exit(1);
    }
    printf("Iniciando cadastro...\n\n");

    printf("Nome: ");
    scanf("%s", pessoa.nomes[0]);

    printf("Endereço: ");
    scanf("%s", pessoa.enderecos[0]);

    printf("Bairro: ");
    scanf("%s", pessoa.bairro[0]);

    printf("Cidade: ");
    scanf("%s", pessoa.cidade[0]);

    printf("Estado: ");
    scanf("%s", pessoa.estado[0]);

    printf("Cep: ");
    scanf("%i", &pessoa.ceps[0]);

    printf("Telefone: ");
    scanf("%i",&pessoa.telefones[0]);

    printf("Celular: ");
    scanf("%i", &pessoa.celulares[0]);

    fprintf(file, "%s  %s  %s  %s  %s  %i  %i  %i\n", pessoa.nomes[0], pessoa.enderecos[0], pessoa.bairro[0], pessoa.cidade[0], pessoa.estado[0], pessoa.ceps[0], pessoa.telefones[0], pessoa.celulares[0]);

    printf("Cadastro realizado...\n");
    sleep(1);
    fclose(file);
}

void alterar(){
    file = fopen("agenda.txt", "r");
    if(file == 0){
        printf("Bando de dados não encontrado!.\n");
    }

    int num;     //variavel para armazenar o numero de celular.
    int cont=0;  //Variavel para contar quantos cadastros existem no meu arquivo.
    int escolha; //Variavel para armazenar a opcao que desejo alterar.

    printf("Informe o número de seu celular para alterar dados: ");
    scanf("%i", &num);

    for(int i=0;fscanf(file, "%s %s %s %s %s %i %i %i\n",pessoa.nomes[i], pessoa.enderecos[i], pessoa.bairro[i], pessoa.cidade[i], pessoa.estado[i], &pessoa.ceps[i], &pessoa.telefones[i], &pessoa.celulares[i]) != EOF; i++){
        cont++;
        if(pessoa.celulares[i] == num){
            menuAlt();
            scanf("%i", &escolha);
            if(escolha == 1){
                printf("Novo Nome: ");
                scanf("%s", pessoa.nomes[i]);
            }else if(escolha == 2){
                printf("Novo Endereço: ");
                scanf("%s", pessoa.enderecos[i]);
            }else if(escolha == 3){
                printf("Novo Bairro: ");
                scanf("%s", pessoa.bairro[i]);
            }else if(escolha == 4){
                printf("Nova Cidade: ");
                scanf("%s", pessoa.cidade[i]);
            }else if(escolha == 5){
                printf("Novo Estado: ");
                scanf("%s", pessoa.estado[i]);
            }else if(escolha == 6){
                printf("Novo Cep: ");
                scanf("%i", &pessoa.ceps[i]);
            }else if(escolha == 7){
                printf("Novo Telefone: ");
                scanf("%i", &pessoa.telefones[i]);
            }else if(escolha == 8){
                printf("Novo Celular: ");
                scanf("%i", &pessoa.celulares[i]);
            }
        }
    }
    fclose(file);
    //Limpa meu arquivo
    zerarArq();
    //Atualiza arquivo com os novos dados
    atualArq(cont); //cont é a quantidade de cadastros.

    printf("Alterações feitas com sucesso...\n");
    system("pause");
}

void excluir(){
    int num;
    int cont = 0;
    file = fopen("agenda.txt", "r");
    if(file == 0){
        printf("Arquivo de não encontrado!\n");
        exit(1);
    }
    for(int i=0;fscanf(file, "%s %s %s %s %s %i %i %i\n",pessoa.nomes[i], pessoa.enderecos[i], pessoa.bairro[i], pessoa.cidade[i], pessoa.estado[i], &pessoa.ceps[i], &pessoa.telefones[i], &pessoa.celulares[i]) != EOF; i++){
        cont++;
    }
    fclose(file);

    zerarArq();

    printf("Digite seu número de Celular para excluir cadastro: ");
    scanf("%i",&num);

    file = fopen("agenda.txt", "a");
    for(int j=0; j<cont ; j++){
        if(pessoa.celulares[j] == num){
            continue;
        }else{
            fprintf(file, "%s  %s  %s  %s  %s  %i  %i  %i\n", pessoa.nomes[j], pessoa.enderecos[j], pessoa.bairro[j], pessoa.cidade[j], pessoa.estado[j], pessoa.ceps[j], pessoa.telefones[j], pessoa.celulares[j]);
        }
    }
    fclose(file);
    printf("Cadastro Excluído...\n\n");
    system("pause");
}

void consultarDados(){
    file = fopen("agenda.txt", "r");
    if(file == 0){
        printf("Banco de dados não encontrado!\n");
    }
    int cont = 0;
    for(int i=0;fscanf(file, "%s %s %s %s %s %i %i %i\n",pessoa.nomes[i], pessoa.enderecos[i], pessoa.bairro[i], pessoa.cidade[i], pessoa.estado[i], &pessoa.ceps[i], &pessoa.telefones[i], &pessoa.celulares[i]) != EOF; i++){
        cont++;
    }
    fclose(file);

    int opc;
    char consulta[50];
    //int cel;
    printf("Como deseja acessar seus dados?\n1 - Pelo Nome\n2 - Pela cidade\n3 - Pelo Estado\n");

    printf("Sua escolha: ");
    scanf("%i", &opc);

    if(opc == 1){
        printf("Seu nome: ");
        scanf("%s", consulta);
    }else if(opc == 2){
        printf("Sua cidade: ");
        scanf("%s", consulta);
    }else if(opc == 3){
        printf("Seu Estado: ");
        scanf("%s", consulta);
    }
    for(int j=0;j<cont;j++){
        if( !(strcmpi(pessoa.nomes[j], consulta)) || !(strcmpi(pessoa.cidade[j], consulta)) || !(strcmpi(pessoa.estado[j], consulta))){
            printf("\nNome: %s\nEndereço: %s\nBairro: %s\nCidade: %s\nEstado: %s\nCep: %i\nTelefone: %i\nCelular: %i\n\n", pessoa.nomes[j], pessoa.enderecos[j], pessoa.bairro[j], pessoa.cidade[j], pessoa.estado[j], pessoa.ceps[j], pessoa.telefones[j], pessoa.celulares[j]);
        }
    }
    system("pause");
}

int main()
{
    setlocale(LC_ALL,"");
    int opc;

    do{
        if(get_size() == 0){
            printf("O arquivo de cadastro está vazio , realize um primeiro cadastro para inicializar o programa.\n");
            goto cad;
        }

        retorna:
        menu();

        printf("Digite um opção: ");
        scanf("%i", &opc);

        if(opc == 1){
            cad:
            cadastrar();
        }else if(opc == 2){
            alterar();
        }else if(opc == 3){
            excluir();
        }else if(opc == 4){
            consultarDados();
        }else if(opc != 5){
            printf("Opção inválida, tente novamente...\n");
            goto retorna;
        }
        system("cls");
    }while(opc != 5);

    return 0;
}
