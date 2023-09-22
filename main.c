#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static FILE *pont_arq;//chama o arquivo txt
static FILE *arquivo;//chama o arquivo bin
#include"horariosempresas.h"
#include"horariosempresaspt2.h"
#include"horariosempresaspt3.h"
#include"lugaraviao.h"
struct Clientes{
    char nome[50],telefone[18],rg[13];
    int flag;
};
typedef struct Clientes clientes;

int main() {
    clientes *puxa;
    clientes *cliente;
    int numClientes=0, i, escolha,num,opcao;
    cliente=(clientes*)malloc(numClientes*sizeof(clientes));
    puxa=(clientes*)malloc(numClientes*sizeof(clientes));
    do{
    printf(" -- MANTER CLIENTE -- AEROPORTO DE TOLEDO --\n");
    arquivo = fopen("clientes.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    fread(&num,sizeof(numClientes),1,arquivo);
    printf("\nLista de clientes:\n");
    if(numClientes==0){
        printf("Ainda nao existem clientes cadastrados\n");
    }else{
        for (i = 1; i < numClientes+1; i++) {
          //  fread(&puxa,sizeof(struct Clientes[i]),1,arquivo);
            if(cliente[i].flag!=1){
                printf("%d- %s\n", i , cliente[i].nome);
            }
        }
    }
    fclose(arquivo);
    printf("\nO que voce deseja fazer?\n 1- Cadastrar novo cliente\n 2- Comprar passagem com conta do referido cliente\n 3- Editar informacoes de cliente\n 4- Excluir cliente\n 0- Sair\n");
    scanf("%i",&escolha);//puxa uma opcao para o menu do que a pessoa deseja fazer com o cliente
    switch(escolha){
    case 1://cadastra um novo cliente
        arquivo = fopen("clientes.bin", "ab+");//abre o bin para escrever nele
        fread(&num,sizeof(numClientes),1,arquivo);//capta o numero de clientes
        numClientes++;//adiciona um cliente a mais
        printf("Digite o nome: ");
        fflush(stdin);
        gets(cliente[numClientes].nome);//recebe um nome para o novo cliente
        printf("Digite o RG: ");
        fflush(stdin);
        gets(cliente[numClientes].rg);//recebe um rg para o novo cliente
        printf("Digite o telefone: ");
        fflush(stdin);
        gets(cliente[numClientes].telefone);//recebe um telefone para o novo cliente
        fwrite(&puxa, sizeof(struct Clientes[numClientes]), 1, arquivo);//escreve o novo cliente no bin
        fwrite(&num,sizeof(numClientes),1,arquivo);//escreve o novo numero de clientes no bin
        fclose(arquivo);//fecha o bin
    break;
    case 2://incia a compra de uma passagem
        arquivo = fopen("clientes.bin", "rb");//abre o bin
        if (arquivo == NULL) {//verifica se bin existe
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
        printf("\nEscolha um dos clientes cadastrados para comprar uma passagem (1 a %d): ", numClientes);
        scanf("%i", &escolha);//escolhe um dos clientes disponiveis
        fflush(stdin);
        printf("\nCliente escolhido:\n Nome: %s\n Telefone: %s\n RG: %s\n\n", cliente[escolha].nome, cliente[escolha].telefone, cliente[escolha].rg);
        pont_arq = fopen("Bilhete.txt","w");//abre o bilhete
        if(pont_arq==NULL){//verifica se o arquivo do bilhete existe
            printf("ERRO NA CRIACAO DO ARQUIVO 'Bilhete.txt'\n\n\n");
            return 0;
        }
        fprintf(pont_arq,"---VIA DO CLIENTE---\n Cliente: %s \n Regristro geral: %s \n",cliente[escolha].nome,cliente[escolha].rg);//escreve no txt
        fclose(pont_arq);//fecha o txt
        fclose(arquivo);//fecha o bin
        printf("Selecione para onde deseja voar:\n 1 - Toledo -> Curitiba\n\n 2 - Toledo -> Palotina\n\n 3 - Toledo -> Foz do Iguacu\n\n 0 - Sair\n\n");
        fflush(stdin);
        scanf("%i",&opcao);
            switch(opcao){//escolhe o destino da viagem
            case 1:
                system("cls");
                hep();//leva o cliente para a pagina onde podem ser compradas as passagens para curitiba
            break;
            case 2:
                system("cls");
                heppt2();//leva o cliente para a pagina onde podem ser compradas as passagens de palotina
            break;
            case 3:
                system("cls");
                heppt3();//leva o cliente para a pagina onde podem ser compradas as passagens de foz
            break;
            case 0://fecha o programa
                return 0;
            break;
            default:
            printf("Opcao invalida! Tente novamente...");
            break;
            }
        pont_arq = fopen("Bilhete.txt","a");//abre o txt
        arquivo = fopen("clientes.bin", "rb");//abre o bin
        fprintf(pont_arq,"\n8<\n------------------------------------\n\n---COLE NA BAGAGEM---\n");
        fprintf(pont_arq," Nome do passageiro: %s \n Telefone: %s \n RG: %s",cliente[escolha].nome, cliente[escolha].telefone, cliente[escolha].rg);
        fclose(arquivo);//fecha o bin
        fclose(pont_arq);//fecha o txt
    break;
    case 3://edita informacoes do cliente
        arquivo = fopen("clientes.bin", "rb");//abre o bin
        if (arquivo == NULL) {//verifica se bin existe
        printf("Erro ao abrir o arquivo.\n");
        return 1;
        }
        printf("\nEscolha um cliente para editar (1 a %d): ", numClientes);
        scanf("%i", &escolha);//escolhe um cliente para editar
        fflush(stdin);
        printf("\nCliente escolhido:\n Nome: %s\n Telefone: %s\n RG: %s\n\n", cliente[escolha].nome, cliente[escolha].telefone, cliente[escolha].rg);
        fclose(arquivo);//fecha o bin
        printf("Qual informacao do cliente voce deseja editar?\n 1- Nome\n 2- Telefone\n 3- RG\n");
        scanf("%i",&opcao);//escolhe qual informacao do cliente vai ser editada
        switch(opcao){
            case 1://escolhe o nome
                arquivo = fopen("clientes.bin", "ab");//abre o bin
                printf("Digite o novo nome: ");
                fflush(stdin);
                gets(cliente[escolha].nome);//pega a nova informacao
                fwrite(&puxa, sizeof(cliente[escolha].nome), 1, arquivo);//salva a nova informacao
                printf("Nome alterado com sucesso!");
                fclose(arquivo);//fecha o bin
            break;
            case 2://escolhe telefone
                arquivo = fopen("clientes.bin", "ab");//abre o bin
                printf("Digite o novo telefone: ");
                fflush(stdin);
                gets(cliente[escolha].telefone);//pega a nova informacao
                fwrite(&puxa, sizeof(cliente[escolha].telefone), 1, arquivo);//salva a nova informacao
                printf("Telefone alterado com sucesso!");
                fclose(arquivo);//fecha bin
            break;
            case 3://escolhe rg
                arquivo = fopen("clientes.bin", "ab");//abre o bin
                printf("Digite o novo RG: ");
                fflush(stdin);
                gets(cliente[escolha].rg);//pega a nova informacao
                fwrite(&puxa, sizeof(cliente[escolha].rg), 1, arquivo);//salva a nova informacao
                printf("RG alterado com sucesso!");
                fclose(arquivo);//fecha o bin
            break;
            default:
            printf("Opcao invalida! Tente novamente...");
            break;
        }
    break;
    case 4://exclui um cliente
        arquivo = fopen("clientes.bin", "rb");//abre bin
        if (arquivo == NULL) {//verifica se bin existe
        printf("Erro ao abrir o arquivo.\n");
        return 1;
        }
        printf("\nEscolha um cliente para excluir (1 a %d): ", numClientes);
        scanf("%i", &escolha);//escolhe um cliente para excluir
        fflush(stdin);
        printf("\nCliente escolhido:\n Nome: %s\n Telefone: %s\n RG: %s\n\n", cliente[escolha].nome, cliente[escolha].telefone, cliente[escolha].rg);
        fclose(arquivo);//fecha o bin
        arquivo = fopen("clientes.bin", "ab");
        cliente[escolha].flag=1;//muda a flag do cliente para que ele nao seja exibido na lista de clientes
        fwrite(&puxa, sizeof(cliente[escolha].flag), 1, arquivo);//atribue o novo valor de flag no bin
        printf("Cliente ocultado com sucesso! Para evitar transtornos os clientes nao sao realmente excluidos do banco de dados.");
        system("pause");
    break;
    }
    system("pause");
    system("cls");
    }while(escolha!=0);
    printf("BILHETE SENDO IMPRESSO!!!");
}
