#include <stdio.h>
#include <stdlib.h>

/*
void aplicarFixo(){

}
*/

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
    

    printf("|ESCOLHA O DIA| \n");
    printf(">> ");
    scanf("%d", &dia);

    return dia;
}


//FUNÇÃO PARA ESCOLHER O VALOR QUE SERA ADICIONADO//
float escolherValor(int dia, int mes){

    float valor;

    printf("Digite o valor a ser adicionado no dia %02d/%02d: \n", dia,mes);

    printf(">> ");
    scanf("%f", &valor);

    return valor;
}

//FUNÇÃO PARA FAZER UM RELATORIO DO MES//
void resumoMes(float dias[31][2])
{
    printf("dia\tvalor\n");
    for(int l=0; l<31; l++){
        for(int c=0; c<2; c++){
            if(c==1){
                printf("%.2lf\t", dias[l][c]);
            }

            else{
                printf("[%.0lf]\t", dias[l][c]);
            } 
        }
        printf("\n");
    }
}

//FUNÇÃO PARA ADICIONAR VALOR AO DIA (nao ta adicionando)//
void adicionarCustoVariavel(int dia, float valor, float dias[31][2])
{
    for(int l=0; l<31; l++){
        for(int c=0; c<1; c++){

            if (c==dia){

                dias[l][2]+=valor;

                printf("\n|VALOR ADICIONADO COM SUCESSO|\n");

            }

        }
    }
    
}

//MENU PRA CADA MES//
void menuFuncionalidades(int mes, float dias[31][2]){

    int menu, dia;
    int qtdDias;
    float valor;

    printf("|MENU|\n");
    printf("1.Adicionar custo variavel\n2.Resumo do mes\n3.Excluir\n4.Voltar\n");
    printf(">> ");
    scanf("%d", &menu);
    
    switch(menu)
    {
        case 1:{
            qtdDias=31;

            dia=escolherDia(qtdDias, mes);

            printf("DIA ESCOLHIDO: %02d/%02d", dia, mes);

            printf("\n\n");

            valor=escolherValor(dia, mes);

            printf("VALOR ADICIONADO ESCOLHIDO: RS%.2f", valor);

            printf("\n\n");

            adicionarCustoVariavel(dia, valor, dias);
            
            break;
        }
        
        case 2:{
            printf("\n");

            resumoMes(dias);

            printf("\n");

            break;
        }
        
        case 3:{
        
            break;
        }
        
        case 4:{
            printf("\n");
            break;
        }
        
        default:{
        
        }
        
    }

}

//////////////
/////MAIN/////
//////////////

int main()
{

    //////VARIAVEIS//////

    int mes;
    //int meses[12];
    float dias[31][2];
    //float fixo;
    
    //////////////PREENCHER MATRIZ//////////////

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

    ////////////////////////////////////////////////

    printf("\n");
    
    //////PAGINA INICIAL//////

    printf("|TUTULO| \n\n");

    ////////custo fixo////////

    /*printf("|INFORME SEU CUSTO FIXO| \n");
    printf(">> ");
    scanf(" %f", &fixo);*/
    
    //aplicar custo fixo no valor final de todos os meses//

    //////////////////////////

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

                menuFuncionalidades(mes, dias);

                

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
                printf("Nao existe esse mes. \n");
                break;
            }

    	}

    }while(mes!=0);

    printf("Finalizando programa...\n");


    return 0;
}
