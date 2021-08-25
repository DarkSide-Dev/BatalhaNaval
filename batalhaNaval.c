#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Atacante{

    char Nome[50];
    int Tiros[8][8];
    int Municao;
    int Acertos;

};

struct Defensor{

    char Nome[50];
    int Gabarito[8][8];

};


int main(){

    struct Atacante jogador1;
    struct Defensor jogador2;
    int i = 0, j = 0;
    char posicao[3], posicao2[3];

    printf("Digite o nome do atacante: ");
    fgets(jogador1.Nome, 50, stdin);
    jogador1.Municao = 6;
    jogador1.Acertos = 0;

    printf("\nDigite o nome do defensor: ");
    fgets(jogador2.Nome, 50, stdin);

    system("cls");
    printf("Agora aparecera o tabuleiro para que o %s escolha a posicao dos navios, entao %s vire-se!!\n\n", jogador2.Nome, jogador1.Nome);
    system("pause");

    for(int qt = 0; qt < 5; qt++){

        a:
        system("cls");

        for(i = 0; i < 9; i++){

            for(j = 0; j < 8; j++){
                
                if(i == 0){
            
                    switch (j){

                        case 0:
                        printf("\t");
                            printf("  A    ");
                            break;
                        
                        case 1:
                            printf("\t  B  ");
                            break;

                        case 2:
                            printf("\t  C  ");
                            break;

                        case 3:
                            printf("\t  D  ");
                            break;

                        case 4:
                            printf("\t  E  ");
                            break;

                        case 5:
                            printf("\t  F  ");
                            break;

                        case 6:
                            printf("\t  G  ");
                            break;

                        case 7:
                            printf("\t  H  ");
                            break;
                        
                        default:
                            break;
                    }
                }
                else{

                    if(jogador2.Gabarito[j][i-1] == 5){
                        printf("\t  5  ");
                    }
                    else{
                        printf("\t  *  ");
                    }
                    
                }

            }
            if(i == 8){
                printf("\t\n\n");
            }
            else{
                printf("\t\n\n  %d  ", i+1);
            }

        }

        printf("Legenda: \n[*] - Espaco disponivel\n[5] - Barco\n\n\nDigite a posicao para inserir um barco[%d/5] (ex. B3): ", qt+1);
        fflush(stdin);
        fgets(posicao, 3, stdin);

        switch(tolower(posicao[0])){

            case 'a':
                i = 0;
                break;
            
            case 'b':
                i = 1;
                break;

            case 'c':
                i = 2;
                break;

            case 'd':
                i = 3;
                break;

            case 'e':
                i = 4;
                break;

            case 'f':
                i = 5;
                break;

            case 'g':
                i = 6;
                break;

            case 'h':
                i = 7;
                break;
            
            default:
                system("cls");
                printf("Voce digitou errado, tente novamente!!\n");
                system("pause");
                goto a;
                break;
        }

        switch(posicao[1]){

            case '1':
                j = 0;
                break;
            
            case '2':
                j = 1;
                break;

            case '3':
                j = 2;
                break;

            case '4':
                j = 3;
                break;

            case '5':
                j = 4;
                break;

            case '6':
                j = 5;
                break;

            case '7':
                j = 6;
                break;

            case '8':
                j = 7;
                break;
            
            default:
                system("cls");
                printf("Voce digitou errado, tente novamente!!\n");
                system("pause");
                goto a;
                break;
        }

        if(jogador2.Gabarito[i][j] == 5){
            system("cls");
            printf("Lugar ja ocupado, tente novamente!!\n");
            system("pause");
            goto a;
        }
        else{
            jogador2.Gabarito[i][j] = 5;
        }

    }

    system("cls");
    printf("Agora chegou a vez do %s tentar achar os barcos!!\n", jogador1.Nome);
    system("pause");

    for(; jogador1.Municao > 0; jogador1.Municao--){
        b:
        system("cls");
        for(i = 0; i < 9; i++){

            for(j = 0; j < 8; j++){
                
                if(i == 0){
            
                    switch (j){

                        case 0:
                        printf("\t");
                            printf("  A    ");
                            break;
                        
                        case 1:
                            printf("\t  B  ");
                            break;

                        case 2:
                            printf("\t  C  ");
                            break;

                        case 3:
                            printf("\t  D  ");
                            break;

                        case 4:
                            printf("\t  E  ");
                            break;

                        case 5:
                            printf("\t  F  ");
                            break;

                        case 6:
                            printf("\t  G  ");
                            break;

                        case 7:
                            printf("\t  H  ");
                            break;
                        
                        default:
                            break;
                    }
                }
                else{

                   if(jogador1.Tiros[j][i-1] == 5){
                        printf("\t  5  ");
                    }
                    else if(jogador1.Tiros[j][i-1] == 2){
                        printf("\t  2  ");
                    }
                    else{
                        printf("\t  *  ");
                    }

                }

            }
            if(i == 8){
                printf("\t\n\n");
            }
            else{
                printf("\t\n\n  %d  ", i+1);
            }

        }

        printf("Legenda: \n[5] - Tiro acertado\n[2] - Tiro errado\nMunicao restante: %d\n\nDigite a posicao para atirar (ex. B3): ", jogador1.Municao);
        fflush(stdin);
        fgets(posicao2, 3, stdin);

        switch(tolower(posicao2[0])){

            case 'a':
                i = 0;
                break;
            
            case 'b':
                i = 1;
                break;

            case 'c':
                i = 2;
                break;

            case 'd':
                i = 3;
                break;

            case 'e':
                i = 4;
                break;

            case 'f':
                i = 5;
                break;

            case 'g':
                i = 6;
                break;

            case 'h':
                i = 7;
                break;
            
            default:
                system("cls");
                printf("Voce digitou errado, tente novamente!!\n");
                system("pause");
                goto b;
                break;
        }

        switch(posicao2[1]){

            case '1':
                j = 0;
                break;
            
            case '2':
                j = 1;
                break;

            case '3':
                j = 2;
                break;

            case '4':
                j = 3;
                break;

            case '5':
                j = 4;
                break;

            case '6':
                j = 5;
                break;

            case '7':
                j = 6;
                break;

            case '8':
                j = 7;
                break;
            
            default:
                system("cls");
                printf("Voce digitou errado, tente novamente!!\n");
                system("pause");
                goto b;
                break;
        }

        if(jogador1.Tiros[i][j] == 5 || jogador1.Tiros[i][j] == 2){
            system("cls");
            printf("Voce ja atirou nessa posicao");
            _sleep(2000);
            goto b;
        }
        else if(jogador2.Gabarito[i][j] == 5){
            system("cls");
            _sleep(1000);
            printf(".");
            _sleep(1000);
            printf(".");
            _sleep(1000);
            printf(".");
            _sleep(1000);
            system("cls");
            printf("Voce acertou um barco!!");
            _sleep(2000);
            jogador1.Municao += 2;
            jogador1.Tiros[i][j] = 5;
            jogador1.Acertos += 1;

            if(jogador1.Acertos == 5){
                system("cls");
                printf("Todas as embarcacoes destruidas!!\n\nO jogador %s e o vencedor!!", jogador1.Nome);
                return 0;
            }
            
        } 
        else{
            system("cls");
            _sleep(1000);
            printf(".");
            _sleep(1000);
            printf(".");
            _sleep(1000);
            printf(".");
            _sleep(1000);
            system("cls");
            printf("Voce errou!!");
            _sleep(2000);
            jogador1.Tiros[i][j] = 2;
        }

    }

    if(jogador1.Acertos != 5 && jogador1.Municao == 0){

        system("cls");
        printf("Ainda restaram embarcacoes!!\n\nO jogador %s e o vencedor!!", jogador2.Nome);
        return 0;

    }
}