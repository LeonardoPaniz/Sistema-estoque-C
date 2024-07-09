#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int opcao = 0, i = 0, j = 0;
    float tabela[50][3];

    printf("\n\n------------------------------------------------------------------------\n");    
    printf("Seja bem vindo ao INFINX, o melhor gerenciador de estoque.\n");
    printf("------------------------------------------------------------------------\n\n");    


    for (opcao = 0; opcao != 5;) {
    int codigo = 0, estoque = 0;
    float preco = 0;

        printf("----------- MENU -----------\n");
        printf("1) Cadastrar um novo produto\n");
        printf("2) Realizar consulta\n");
        printf("3) Registrar venda\n");
        printf("4) Relatório\n");
        printf("5) Sair\n");
        printf("-----------------------------\n\n");
        printf("Qual operação deseja realizar: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                printf("\n\n------------------------------------------------------------------------\n");    
                printf("Vamos cadastrar o produto:\n");
                printf("------------------------------------------------------------------------\n\n");    
                printf("Insira o código do produto:");
                scanf("%d", &codigo);
                tabela[i][0] = codigo;
                printf("------------------------------------------------------------------------\n");
                printf("Preço do produto deve ser cadastrado com virgula. EX: 2,50\n");
                printf("Insira o preço do produto:");
                scanf("%f", &preco);
                tabela[i][1] = preco;
                printf("------------------------------------------------------------------------\n");
                printf("Insira a quantidade do produto:");
                scanf("%d", &estoque);
                tabela[i][2] = estoque;
                i++;
                printf("------------------------------------------------------------------------\n\n");
                break;
            case 2:
                system("cls");
                printf("------------------------------------------------------------------------\n");    
                printf("Escreva o codigo do produto que deseja consultar:\n");
                printf("------------------------------------------------------------------------\n");    
                printf("O codigo:");
                scanf("%i", &codigo);
                for (j = 0; j < i; j++){
                    int produto_encontrado = 0;
                    if(tabela[j][0]==codigo){
                        produto_encontrado = 1;
                        printf("------------------------------------------------------------------------\n");
                        printf("Produto foi localizado\n");
                        printf("------------------------------------------------------------------------\n\n");
                         printf("Código: %.0f | Preço: %.2f | Quantidade: %.0f\n\n", tabela[j][0], tabela[j][1], tabela[j][2]);
                         break;
                    }if(!produto_encontrado){
                        printf("------------------------------------------------------------------------\n");
                        printf("Receio informar que não existe produto cadastrado com o codigo: %i\n", codigo);
                        printf("------------------------------------------------------------------------\n\n");
                    }
                }
                break;
            case 3:
                system("cls");
                printf("------------------------------------------------------------------------\n");    
                printf("Que bom te ver aqui, vamos cadastrar uma venda.\n");
                printf("Escreva o codigo do produto que deseja dar baixa:\n");
                printf("------------------------------------------------------------------------\n\n");    
                printf("O codigo:");
                scanf("%i", &codigo);
                int produto_encontrado = 0;
                for (j = 0; j < i; j++) {
                    if(tabela[j][0]==codigo){
                        produto_encontrado = 1;
                        printf("Quantidade de itens vendidos: ");
                        scanf("%i", &estoque);
                        if ((tabela[j][2] - estoque) < 0){
                            printf("Infelizmente a quantidade no seu estoque é inferior a quantidade vendida.\n\n");
                            break;
                        }else{
                        (tabela[j][2] -= estoque);
                        printf("------------------------------------------------------------------------\n");
                        printf("Realizei a baixa no estoque, o estoque deste produto esta assim agora:\n");
                        printf("------------------------------------------------------------------------\n\n");
                        printf("Código: %.0f | Preço: %.2f | Quantidade: %.0f\n", tabela[j][0], tabela[j][1], tabela[j][2]);
                        }
                        break;
                    }if(!produto_encontrado){
                        printf("------------------------------------------------------------------------\n");
                        printf("Receio informar que não existe produto cadastrado com o codigo: %i\n", codigo);
                        printf("------------------------------------------------------------------------\n\n");
                    }
                }
                break;
            case 4:
                system("cls");
                printf("\n------------------------------------------------------------------------\n");    
                printf("Seu estoque se encontra assim:\n");
                printf("------------------------------------------------------------------------\n\n");
                if (i == 0){
                printf("========================================================================\n");
                printf("------------------------------------------------------------------------\n");
                printf("------------------------------------------------------------------------\n");
                printf("-----------------------SEU ESTOQUE ESTÁ VAZIO---------------------------\n");
                printf("------------------------------------------------------------------------\n");
                printf("------------------------------------------------------------------------\n");
                printf("========================================================================\n\n");
                }else{
                for (j = 0; j < i; j++) {
                printf("Código: %.0f | Preço: %.2f | Quantidade: %.0f\n\n", tabela[j][0], tabela[j][1], tabela[j][2]);
                }
                }
                break;
            case 5:
                system("cls");
                printf("=======================================\n");
                printf("Muitoo obrigado por utlizar o INFINIX!\n");
                printf("=======================================\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n\n");
                break;
        }
    }
    return 0;
}
