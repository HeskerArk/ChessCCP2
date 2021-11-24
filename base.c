
/*
    V.1.0 
    GUIA DE pecas
    P - Peão
    T - Torre
    C - Cavalo
    B - Bispo
    K - Rei
    Q - Rainha
*/

#include <stdio.h>
#include <windows.h>
#include <locale.h>



void exibirTabuleiro(char tabuleiro[9][9], char JogadorPreto[], char JogadorBranco[])
{
    system("cls");
    printf("  %c   %c   %c   %c   %c   %c   %c   %c   %c", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2], tabuleiro[0][3], tabuleiro[0][4], tabuleiro[0][5], tabuleiro[0][6], tabuleiro[0][7], tabuleiro[0][8]);
    printf("\n   ___________________________________");
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  Jogador de pecas Pretas: pecas minusculas.", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2], tabuleiro[1][3], tabuleiro[1][4], tabuleiro[1][5], tabuleiro[1][6],
           tabuleiro[1][7], tabuleiro[1][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  Jogador de pecas Brancas: pecas maisculas.", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2], tabuleiro[2][3], tabuleiro[2][4], tabuleiro[2][5], tabuleiro[2][6],
           tabuleiro[2][7], tabuleiro[2][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  Tutorial de como jogar: insira o", tabuleiro[3][0], tabuleiro[3][1], tabuleiro[3][2], tabuleiro[3][3], tabuleiro[3][4], tabuleiro[3][5],
           tabuleiro[3][6], tabuleiro[3][7], tabuleiro[3][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  numero de uma linha, insira um espaco, em seguida insira", tabuleiro[4][0], tabuleiro[4][1], tabuleiro[4][2], tabuleiro[4][3], tabuleiro[4][4], tabuleiro[4][5],
           tabuleiro[4][6], tabuleiro[4][7], tabuleiro[4][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  o numero de uma coluna e aperte enter para finalizar.", tabuleiro[5][0], tabuleiro[5][1], tabuleiro[5][2], tabuleiro[5][3], tabuleiro[5][4], tabuleiro[5][5],
           tabuleiro[5][6], tabuleiro[5][7], tabuleiro[5][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |", tabuleiro[6][0], tabuleiro[6][1], tabuleiro[6][2], tabuleiro[6][3], tabuleiro[6][4], tabuleiro[6][5], tabuleiro[6][6], tabuleiro[6][7],
           tabuleiro[6][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  pecas capturadas pelo de cor PRETA 1: %s", tabuleiro[7][0], tabuleiro[7][1], tabuleiro[7][2], tabuleiro[7][3], tabuleiro[7][4], tabuleiro[7][5],
           tabuleiro[7][6], tabuleiro[7][7], tabuleiro[7][8], JogadorPreto);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  pecas capturadas pelo de cor BRANCA 2: %s", tabuleiro[8][0], tabuleiro[8][1], tabuleiro[8][2], tabuleiro[8][3], tabuleiro[8][4], tabuleiro[8][5],
           tabuleiro[8][6], tabuleiro[8][7], tabuleiro[8][8], JogadorBranco);
    printf("\n   ___________________________________\n");
}

void exibirMensagemDeErro()
{
    puts("\nNão é possivel fazer o movimento, Pressione qualquer tecla para continuar...\n");
            fflush(stdin);
            getchar();
}

int verificarMovimento (int x, int y, char peca, int jogador)
{
    int valor = 1;
    if (jogador == 1)
    {
        if(isalpha(x) || isalpha(y) || x <= 0 || y <= 0 || x > 8 || y > 8 || islower(peca))
        {
            exibirMensagemDeErro();
        }
        else
        {
            valor = 0;
        }
    }
    else
    {
        if (isalpha(x) || isalpha(y) || x <= 0 || y <= 0 || x > 8 || y > 8 || isupper(peca))
        {
            exibirMensagemDeErro();
        }
        else
        {
            valor = 0;
        }
    }
    return valor;
}

void realizarMovimento (char jogador[17], int *indice, int *qualJogador, char tabuleiro[9][9], int x, int y, int linha, int coluna)
{
    if (tabuleiro[x][y] == '.') 
    {
        tabuleiro[x][y] = tabuleiro[linha][coluna];
        tabuleiro[linha][coluna]='.';

        if (*qualJogador == 1)
        {
            (*qualJogador)++;
        }
        else
        {
            (*qualJogador)--;
        }
    }
    else 
    {
        if (*qualJogador == 1) 
        {
            jogador[*indice] = tabuleiro[x][y];
            tabuleiro[x][y] = tabuleiro[linha][coluna];
            tabuleiro[linha][coluna]='.';
            (*indice)++;
            (*qualJogador)++;
        }
        else 
        {
            jogador[*indice] = tabuleiro[x][y];
            tabuleiro[x][y] = tabuleiro[linha][coluna];
            tabuleiro[linha][coluna]='.';
            (*indice)++;
            (*qualJogador)--;
        }
    }
}

int verificarPeca (char peca, int linha, int coluna, int qualJogador)
{
    int valor = 1;
    if (qualJogador == 1)
    {
        if (isalpha(linha) || isalpha(coluna) || linha <= 0 || coluna <= 0 || linha > 8 || coluna > 8 || isupper(peca) || peca == '.')
        {
            exibirMensagemDeErro();
        }
        else
        {
            valor = 0;
        }
    }
    else
    {
        if (isalpha(linha) || isalpha(coluna) || linha <= 0 || coluna <= 0 || linha > 8 || coluna > 8 || islower(peca) || peca == '.')
        {
            exibirMensagemDeErro();
        }
        else
        {
            valor = 0;
        }
    }
    return valor;
}

void exibirVitoria (char jogador[])
{
    printf("\n\nXeque mate! Diferente dos iguais %s capturou o rei e venceu!\n\n", jogador);
    Beep(660,100);
    Sleep(50);
    Beep(660,100);
    Sleep(200);
    Beep(660,100);
    Sleep(200);
    Beep(510,100);
    Sleep(25);
    Beep(660,100);
    Sleep(200);
    Beep(770,100);
    Sleep(450);
    Beep(380,100);
    Sleep(475);
}

main ()
{

    setlocale(LC_ALL,"");
    int qualJogador=1, indiceUm=0, indiceDois=0, continua=1, linha=0, coluna=0, x=0, y=0;
    char JogadorPreto[17]= {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char JogadorBranco[17]= {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char tabuleiro[9][9] = {' ','1','2','3','4','5','6','7','8',
                            '1','t','c','b','q','k','b','c','t',
                            '2','p','p','p','p','p','p','p','p',
                            '3','.','.','.','.','.','.','.','.',
                            '4','.','.','.','.','.','.','.','.',
                            '5','.','.','.','.','.','.','.','.',
                            '6','.','.','.','.','.','.','.','.',
                            '7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
                            '8', 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T'
                           };


    while (continua == 1) 
    {

        exibirTabuleiro(tabuleiro, JogadorPreto, JogadorBranco);

        if (JogadorPreto[indiceUm-1]=='K')
        {
            exibirVitoria("Pecas Pretas");
            return(0);
        }
        else if (JogadorBranco[indiceDois-1]=='k')
        {
            exibirVitoria("Pecas Brancas");
            return(0);
        }

        do
        {
            exibirTabuleiro(tabuleiro, JogadorPreto, JogadorBranco);
            printf("\n\nJogador %i - digite qual peca deseja mover: ", qualJogador);
            fflush(stdin);
            scanf("%i%i", &linha, &coluna);

        }
        while(verificarPeca(tabuleiro[linha][coluna], linha, coluna, qualJogador));


        do
        {
            exibirTabuleiro(tabuleiro, JogadorPreto, JogadorBranco);
            printf("\nJogador %i - insira para deseja mover a peca da linha %i e coluna %i: ", qualJogador, linha, coluna);
            fflush(stdin);
            scanf("%i%i", &x, &y);

        }
        while(verificarMovimento(x, y, tabuleiro[x][y], qualJogador));


        if (qualJogador == 1)
        {
            realizarMovimento(JogadorPreto, &indiceUm, &qualJogador, tabuleiro, x, y, linha, coluna);
        }
        else
        {
            realizarMovimento(JogadorBranco, &indiceDois, &qualJogador, tabuleiro, x, y, linha, coluna);
        }
    }
}
