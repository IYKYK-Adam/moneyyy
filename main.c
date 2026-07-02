#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNÇÃO PARA META DE CONSUMO//
float metaConsumo(int mes)
{
    float meta=0;

    do{
        printf("|INFORME SUA META DO MES %02d| \n", mes);
        printf(">> ");
        scanf(" %f", &meta);

        if(meta<0){
            printf("Valor invalido! Digite novamente...\n\n");
        }
    }while (meta<0);

    printf("\n");

    return meta;
}

//FUNÇÃO PARA SELECIONAR O DIA//
int escolherDia(int qtdDias, int mes)
{
    int dia, sn;

    do{
        printf("\n");
        printf("deseja vizualizar os dias desse mes? \n");
        printf("[1]SIM  [2]NAO \n");
        printf(">> ");
        scanf("%d", &sn);

        switch (sn)
        {
            case 1:{

                printf("|DIAS DO MES %02d|\n", mes);
                for(int i=1; i<=qtdDias; i++){
                    printf("[%d] ", i);
                }
                printf("\n\n");

                break;
            }

            case 2:{
                printf("\n");
                break;
            }

            default:{
                printf("Opcao invalida! \n");
                break;
            }
        }
    }while (sn!=1 && sn!=2);

    do{
        printf("|ESCOLHA O DIA| \n");
        printf(">> ");
        scanf("%d", &dia);

        if(dia<1||dia>qtdDias){
            printf("\nERRO: dia selecionado nao compativel! \nDigite novamente...\n\n");
        }

    }while (dia<1||dia>qtdDias);


    return dia;
}


//FUNÇÃO PARA ESCOLHER O VALOR QUE SERA ADICIONADO//
float escolherValor(int dia, int mes)
{
    float valor;

    do{
        printf("Digite o valor: \n");
        printf(">> RS");
        scanf("%f", &valor);

        if(valor<0){
            printf("ERRO: valor digitado invalido! \nDigite novamente...\n\n");
        }
    }while (valor<0);

    return valor;
}


//FUNÇÃO PARA FAZER UM RELATORIO DO MES//
void resumoMes(float dias[31][2], float fixo, char string[100], int qtdDias, int mes, float meta[])
{

    float total=0;

    //calcular o total gasto no mes (sem valor fixo)
    for (int l=0; l<qtdDias-1; l++){
            total+=dias[l][1];
    }

    //relatorio do mes
    printf("|META DO MES: RS%.2f| \n\n", meta[mes-1]);
    
    printf("|CUSTO FIXO| \n");
    printf("valor\t\tdescricao\n");
    printf("RS%.2f\t\t%s", fixo, string);

    printf("\n\n");

    printf("|RELATORIO DO MES| \n");
    printf("dia\tvalor\n");
    for(int l=0; l<qtdDias; l++){
        for(int c=0; c<2; c++){
            if(c==0){
                printf("%.0f/%02d", dias[l][c], mes);
            }
            else{
                printf("\tRS%.2f\t", dias[l][c]);
            }
        }
        printf("\n");
    }

    printf("\n");

    printf("|TOTAL DO MES: RS%.2f| \n\n", total+fixo);
    
    printf("||");

}


//FUNÇÃO PARA ADICIONAR VALOR AO DIA//
void adicionarCustoVariavel(int dia, float valor, float dias[31][2], float meta[])
{
    dias[dia-1][1]+=valor;

    printf("|VALOR ADICIONADO COM SUCESSO|\n\n");
}


//FUNÇÃO PARA DESCONTAR VALOR AO DIA//
void descontarCustoVariavel(int dia, float valor, float dias[31][2])
{


        dias[dia-1][1]-=valor;

        //piso 0
        if(dias[dia-1][1]<0){
            dias[dia-1][1]=0;
        }


    printf("|VALOR DESCONTADO COM SUCESSO|\n\n");
}


//MENU PRA CADA MES//
void menuFuncionalidades(int mes, float dias[31][2], float fixo, char string[100], int qtdDias, float meta[]){

    int menu, dia, aux;
    float valor;

    do{

        printf("|MENU|\n");
        printf("1.Adicionar custo variavel\n2.Resumo do mes\n3.Remover custo variavel\n4.Voltar\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:{

                dia=escolherDia(qtdDias, mes);

                printf("DIA ESCOLHIDO: %02d/%02d", dia, mes);

                printf("\n\n");

                valor=escolherValor(dia, mes);

                printf("VALOR ADICIONADO ESCOLHIDO: RS%.2f", valor);

                printf("\n\n");

                adicionarCustoVariavel(dia, valor, dias, meta); //add meta

                break;
            }

            case 2:{
                printf("\n");

                resumoMes(dias, fixo, string, qtdDias, mes, meta); //add meta

                printf("\n");

                break;
            }

            case 3:{

                dia=escolherDia(qtdDias, mes);

                printf("DIA ESCOLHIDO: %02d/%02d", dia, mes);

                //verificar se n tem nada no dia

                if(dias[dia-1][1]==0){
                    printf("\nEsse dia nao tem valor adicionado!\n");

                    aux=1;
                }

                else{
                    aux=0;
                }

                printf("\n\n");

                if(aux==1){
                    break;
                }

                else{
                    valor=escolherValor(dia, mes);

                    printf("VALOR A SER DESCONTADO: RS%.2f", valor);

                    //verificar se o valor q selecionou eh maior q oq ele tem

                    if(dias[dia-1][1]>valor){

                        printf("\n\n");

                        descontarCustoVariavel(dia, valor, dias);

                        break;

                    }

                    else{
                        printf("\nEsse dia nao tem valor sufuciente pra ser descontado!\n\n");
                        break;
                    }

                }
            }

            case 4:{
                printf("\n");
                break;
            }

            default:{
                printf("\nOpcao invalida! Digite novamente.\n\n");
            }

        }

    }while(menu!=4);



}



//////////////
/////MAIN/////
//////////////

int main()
{

    //////VARIAVEIS//////

    int mes, menu;

    //int meses[12];
    float dias[31][2];

    float fixo=0, meta[12];

    int qtdDias;

    int desc;
    char string[100];

    //////////////PREENCHER MATRIZES//////////////

    for(int c=0; c<2; c++){

        for(int l=0; l<31; l++){
            if (c==0){
                dias[l][c]=l+1;
            }
            else{
                dias[l][c]=0;
            }
        }
    }

    for(int i=0; i<12; i++){
        meta[i]=-1;
    }

    ////////////////////////////////////////////////

    printf("\n");

    //////PAGINA INICIAL//////

    printf("|TITULO| \n\n");

    //////MENU INICIAL//////

    do{
        printf("|MENU INICIAL| \n");
        printf("\n[1]Adicionar custo fixo \n[2]pular \n[ATENCAO]informacao nao editavel! \n>> ");
        scanf("%d", &menu);

        printf("\n");

        switch (menu)
        {
            case 1:{

                ////////////custo fixo////////////

                do{
                    printf("|INFORME SEU CUSTO FIXO| \n");
                    printf(">> ");
                    scanf(" %f", &fixo);

                    if(fixo<0){
                        printf("Valor invalido! Digite novamente...\n\n");
                    }
                }while (fixo<0);

                printf("\n");

                do{
                    printf("Deseja adicionar uma descricao para o custo fixo? \n[1]sim\n[2]nao\n>> ");
                    scanf("%d", &desc);

                    switch(desc){
                        case 1:{
                            printf("\nDescricao: ");
                            scanf(" %[^\n]s", string);
                            break;
                        }

                        case 2:{
                            strcpy(string, "---");
                            break;
                        }

                        default:{
                            printf("Opcao Invalida!\n\n");
                        }

                    }
                }while(desc!=1 && desc!=2);

                printf("\n");

                break;
            }

            case 2:{
                strcpy(string, "---");
                break;
            }

            default:
                printf("Opcao Invalida!\n\n");
                break;
        }

    }while(menu!=1 && menu!=2);
    ///////////////////////////////

    //////////MENU DE MES//////////

    do{
        printf("|SELECIONE O MES| \n");
        printf("1.Janeiro \n2.Fevereiro \n3.Marco \n4.Abril \n5.Maio \n6.Junho \n7.Julho \n8.Agosto \n9.Setembro \n10.Outubro \n11.Novembro \n12.Dezembro \n0.Sair \n\n");
        printf(">> ");
        scanf("%d", &mes);

        printf("\n");

        switch(mes)

        {
            case 1:{

                printf("|JANEIRO| \n\n");
                qtdDias=31;

                //meta de consumo
                if (meta[mes-1]<0){
                    meta[mes-1]=metaConsumo(mes);
                }

                //menu
                menuFuncionalidades(mes, dias, fixo, string, qtdDias, meta);

                break;
            }



            case 2:{
                printf("|FEVEREIRO| \n");


                break;
            }

            case 3:{
                printf("|MARCO| \n");


                break;
            }

            case 4:{
                printf("|ABRIL| \n");


                break;
            }

            case 5:{
                printf("|MAIO| \n");


                break;
            }

            case 6:{
                printf("|JUNHO| \n");


                break;
            }

            case 7:{
                printf("|JULHO| \n");


                break;
            }

            case 8:{
                printf("|AGOSTO| \n");


                break;
            }

            case 9:{
                printf("|SETEMBRO| \n");


                break;
            }

            case 10:{
                printf("|OUTUBRO| \n");


                break;
            }

            case 11:{
                printf("|NOVEMBRO| \n");


                break;
            }

            case 12:{
                printf("|DEZEMBRO| \n");


                break;
            }

            case 0:{
                break;
            }

            default:{
                printf("Nao existe esse mes. \n\n");
                break;
            }

    	}

    }while(mes!=0);

    printf("Finalizando programa...\n");


    return 0;
}
