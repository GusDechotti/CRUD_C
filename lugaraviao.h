int lugar(int qtdpss){
    int i=0,j=0,a,b,cont=0,rds=0;//cria as variaveis necessarias
    char vet[9][9],J;
 do{//cria um loop para que possam ser escolhidas a quantidade de poltronas necessarias
 printf("AGORA ESCOLHA SEU LUGAR NO AVIAO:\n");
 printf("    A   B   C      D   E   F      G   H   I\n0- ");
 for(i=0;i<9;i++){//gera o loop onde todas as poltronas seram printas
    for(j=0;j<9;j++){
        if(vet[i][j]!='X'){//verifica se a poltrona esta ocupada
        printf("|_| ");//printa poltrona vazia
        cont++;
        }else{//se poltrona ocupada entra aqui
        printf("|X| ");//printa poltrona vazia
        cont++;
        }
        if(cont>=3){//coloca os espacos entre os bancos
        printf("   ");
        cont=0;
        }
    }
    if(i!=8){//nao printa um numero a mais
    printf("\n\n%i- ",i+1);}
    else{
    printf("\n\n");}
 }
 printf("Escolha a linha (numero):");
 scanf("%i",&a);//recebe a linha da poltrona
 printf("Escolha a coluna (letra):");
 fflush(stdin);
 scanf("%c",&J);//recebe a coluna da poltrona
 switch(J){//transforma um numero em uma letra para que o codigo possa usa-la
    case 'a':
        b=0;
        break;
    case 'b':
        b=1;
        break;
    case 'c':
        b=2;
        break;
    case 'd':
        b=3;
        break;
    case 'e':
        b=4;
        break;
    case 'f':
        b=5;
        break;
    case 'g':
        b=6;
        break;
    case 'h':
        b=7;
        break;
    case 'i':
        b=8;
        break;
    default:
        printf("ERRO");
        break;
 }
    vet[a][b]='X';//coloca a poltrona como ocupada no vetor
    pont_arq = fopen("Bilhete.txt","a");//abre o txt
    if(pont_arq==NULL){//verifica se o txt existe
        printf("ERRO NA CRIACAO DO ARQUIVO 'Bilhete.txt'\n\n\n");
        return 0;
    }
    fprintf(pont_arq," Poltrona: %c %i\n",J,a);
    fclose(pont_arq);//fecha o txt
    system("cls");
    rds++;
 }while(rds!=qtdpss);//finaliza os loops de quantas passagens foram compradas
 printf("   -- SEUS LUGARES SAO: --\n");
 printf("    A   B   C      D   E   F      G   H   I\n0- ");
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        if(vet[i][j]!='X'){
        printf("|_| ");
        cont++;
        }else{
        printf("|X| ");
        cont++;
        }
        if(cont>=3){
        printf("   ");
        cont=0;
        }
    }
    if(i!=8){
    printf("\n\n%i- ",i+1);}
    else{
    printf("\n\n");}
 }
}//volta para main
