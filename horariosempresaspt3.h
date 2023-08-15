int heppt3(){ //toledo para foz
    char opcao;//declara as vaiaveis necessarias
    int qtdpassgens,hora,valor;
    printf(" --ESCOLHA UMA DAS EMPRESAS ABAIXO QUE VOCE DESEJA VIAJAR--\n\n");
    printf(" 1 - Sorriso de Toledo - R$400,00\n\n 2 - Cesta - R$899,00\n\n 3 - Averde - R$1.800,00\n\n");
    fflush(stdin);
    scanf("%c",&opcao);//escolha uma das empresas com o valor
        switch(opcao){
        case '1'://escolhe sorriso de toledo
            printf("->Selecionado 'Sorriso de toledo'\n Deseja comprar quantas passagens? ");
            scanf("%i",&qtdpassgens);//pega a quantidade de passagens
            valor=400*qtdpassgens;//multiplica a quantidade de passagens
            pont_arq = fopen("Bilhete.txt","a");//abre o txt
            if(pont_arq==NULL){//verifica se o txt existe
                printf("ERRO NA CRIACAO DO ARQUIVO 'Bilhete.txt'\n\n\n");
                return 0;
            }
            fprintf(pont_arq," Valor da passagem: R$%i,00 \n Empresa: Sorriso de toledo\n",valor);
            fclose(pont_arq);//fecha o txt
            break;
        case '2'://escolhe a cesta
            printf("->Selecionado 'Cesta' \n Deseja comprar quantas passagens? ");
            scanf("%i",&qtdpassgens);//pega a qunatida de passagens
            valor=899*qtdpassgens;//multiplica a quantidade de passagens
            pont_arq = fopen("Bilhete.txt","a");//abre o txt
            if(pont_arq==NULL){//verifica se o txt existe
                printf("ERRO NA CRIACAO DO ARQUIVO 'Bilhete.txt'\n\n\n");
                return 0;
            }
            fprintf(pont_arq," Valor da passagem: R$%i,00 \n Empresa: Cesta\n",valor);
            fclose(pont_arq);//fecha o txt
            break;
        case '3'://escolhe a averde
            printf("->Selecionado 'Averde' \n Deseja comprar quantas passagens?  ");
            scanf("%i",&qtdpassgens);//pega a quantidade de passagens
            valor=1800*qtdpassgens;//multiplica a quantidade de passagens
            pont_arq = fopen("Bilhete.txt","a");//abre o txt
            if(pont_arq==NULL){//verifica se o txt existe
                printf("ERRO NA CRIACAO DO ARQUIVO 'Bilhete.txt'\n\n\n");
                return 0;
            }
            fprintf(pont_arq," Valor da passagem: R$%i,00 \n Empresa: Averde\n",valor);
            fclose(pont_arq);//fecha o txt
            break;
        default:
            printf("Opcao invalida! Tente novamente...\n");
            break;
        }
    system("cls");
    printf(" --ESCOLHA O HORARIO DO VOO--\n\n");
    printf(" 1 - 13:00 \n\n 2 - 18:00\n\n 3 - 23:00\n\n");
    fflush(stdin);
    scanf("%c",&opcao);//escolhe um horario para o voo
        switch(opcao){
        case '1'://escolhe 13 horas
            hora=13;
            system("cls");
            break;
        case '2'://escolhe 18 horas
            hora=18;
            system("cls");
            break;
        case '3'://escolhe 23 horas
            hora=23;
            system("cls");
            break;
        default:
            printf("Opcao invalida! Tente novamente...");
            break;
        }
        pont_arq = fopen("Bilhete.txt","a");//abre o txt
        if(pont_arq==NULL){//verifica se o txt existe
            printf("ERRO NA CRIACAO DO ARQUIVO 'Bilhete.txt'\n\n\n");
            return 0;
        }
        fprintf(pont_arq," Horario do voo: %i:00\n",hora);//escreve o horario do voo escolhido no bilhete
        fclose(pont_arq);//fecha o txt
    lugar(qtdpassgens);//vai para a pagina onde o cliente escolhe sua poltrona
}
