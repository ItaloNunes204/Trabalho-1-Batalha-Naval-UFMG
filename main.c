#include <stdio.h>
#include <stdlib.h>

int main()
{
    //cria matriz dos "mapas"
    int jogador1[10][10],jogador2[10][10];

    //completa a matrix do jogador 1 com 0
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            jogador1[i][j]=0;
        }
    }
    //completa a matrix do jogador 2 com 0
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            jogador2[i][j]=0;
        }
    }

//---------------cria variaveis para a coleta de dados-------------
    int tamanho=0,linha=0,coluna=0,quantidade_navios=0;
    char orientacao[1];

//---------------cria variaveis armazenamento de quantodade de navios vivos
    int vivos_jogador1=0,vivos_jogador2=0;

//---------------coleta dados jogador 1-------------

    //coleta a quantidade de navios
    scanf("%d",&quantidade_navios);
    //é criado um loop para coletar o mapa do jogador 1 com os navios
    while(quantidade_navios != 0){
        //coleta o tamanho do navio a orientação e as coordenadas
        scanf("%d %c %d %d",&tamanho,&orientacao[0],&linha,&coluna);
        //é adicionado a uma variavel a quantidade de navios do jogador 1
        vivos_jogador1+=tamanho;
        //verifica a orientação do jogador 1 vertical
        if(orientacao[0] == 'v'){
            for(int i=0;i<tamanho;i++){
                //se a linha e a coluna for igual a 10 os valores sao modificados para 0
                if(linha==10){
                    linha=0;
                }
                if(coluna==10){
                    coluna=0;
                }
                //navio criado
                jogador1[linha][coluna]=1;
                linha++;
            }
        }
        else{
            //orientação horizontal
            for(int i=0;i<tamanho;i++){
                //se a linha e a coluna for igual a 10 os valores sao modificados para 0
                if(linha==10){
                    linha=0;
                }
                if(coluna==10){
                    coluna=0;
                }
                //navio criado
                jogador1[linha][coluna]=1;
                coluna++;
            }
        }
        //diminui a quantidade de navios para sair do loop
        quantidade_navios--;
    }
    tamanho=0;
//------------------------coleta dados jogador 2-----------------
    //coleta o numero de navios do jogador 2
    scanf("%d",&quantidade_navios);
    //loop para a quantidade de navios
    while(quantidade_navios != 0){
        //coleta o tamanho orientação e as coordenadas
        scanf("%d %c %d %d",&tamanho,&orientacao[0],&linha,&coluna);
        //a quantidade de navios é adicionado a uma variavel
        vivos_jogador2+=tamanho;
        //verifica a orientação do navio (vertical)
        if(orientacao[0] == 'v'){
            for(int i=0;i<tamanho;i++){
                //se a linha e a coluna for igual a 10 os valores sao modificados para 0
                if(linha==10){
                    linha=0;
                }
                if(coluna==10){
                    coluna=0;
                }
                //mapa jogador 2 modificado
                jogador2[linha][coluna]=1;
                linha++;
            }
        }
        else{
            //orientação (horizontal)
            for(int i=0;i<tamanho;i++){
                //se a linha e a coluna for igual a 10 os valores sao modificados para 0
                if(linha==10){
                    linha=0;
                }
                if(coluna==10){
                    coluna=0;
                }
                //mapa jogador 2 modificado
                jogador2[linha][coluna]=1;
                coluna++;
            }
        }
        //quantidade de navios é diminuido para sair do loop
        quantidade_navios--;
    }

//---------------------- cria variveis de ataque-----------------------
    int ataque_linha=0,ataque_coluna=0,ataque_especial=0;
    int contador_especial1=0,contador_especial2=0;
    char tipo_ataque[1],orientacao_ataque[1];


//-------------numero de ataques-----------------------------------
    //coleta o numero de jogadas
    int numero_ataques=0;
    scanf("%d",&numero_ataques);
    //é calculado o numero de rodadas
    numero_ataques=numero_ataques/2;


//-----------------------ataques-------------------------------

    //entra em um loop para os ataques
    while(numero_ataques != 0){
    //----------------------ataque do jogador 1-----------------------
        //coleta o tipo de ataque(normal-n  ou especial-e)
        scanf("\n%c",&tipo_ataque[0]);
        //compara o tipo de ataque (normal)
        if(tipo_ataque[0] == 'n'){
            //coleta as coordenadas para o ataque do jogador 1
            scanf("%d %d",&ataque_linha,&ataque_coluna);
            //verifica se as coordenadas informadas tem um navio do jogador 2
            if(jogador2[ataque_linha][ataque_coluna] == 1){
                //o numero de navios vivos do jogador 2 é diminuido, as coordenadas é modificada para 0,é adicionado mais 1 ao ataque especial do jogador1
                vivos_jogador2--;
                jogador2[ataque_linha][ataque_coluna]=0;
                contador_especial1++;
            }
            else{
                // se a escolha acima não for realizada o ataque especial e modificado para 0
                contador_especial1=0;
            }
        }
        else{
            //é coletado a orientação e/ou a coluna ou linha do ataque
            scanf("\n%c %d",&orientacao_ataque[0],&ataque_especial);
            //verifica se o jogador 1 tem saldo para realizar o ataque especial
            if(contador_especial1>=2){
                //orientação (horizontal)
                if(orientacao_ataque[0] == 'h'){
                    //destroi a linha inteira, verificando de tem navios inimigos,reduzindo o numero de navios vivos do jogador 2 e o mapa e modificado
                    for(int i=0;i<10;i++){
                        if(jogador2[ataque_especial][i]==1){
                            vivos_jogador2--;
                            jogador2[ataque_especial][i]=0;
                        }
                    }
                }
                else{
                    //orientação (vertical)
                    for(int i=0;i<10;i++){
                        //destroi a coluna inteira, verificando de tem navios inimigos,reduzindo o numero de navios vivos do jogador 2 e o mapa e modificado
                        if(jogador2[i][ataque_especial]==1){
                            vivos_jogador2--;
                            jogador2[i][ataque_especial]=0;
                        }
                    }
                }
                //apos o ataque especial o contador do ataque é modificado para 0
                contador_especial1=0;
            }else{
                // caso o jogador não tenha saldo o contador é modificado para 0
                contador_especial1=0;
            }
        }

    //----------------------ataque jogador 2-----------------------
        //coleta o tipo de ataque do jogador 2
        scanf("\n%c",&tipo_ataque[0]);
        //verifica qual o tipo de ataque(normal-n ou especial-e)
        if(tipo_ataque[0] == 'n'){
            //coleta as coordenadas para o ataque normal
            scanf("%d %d",&ataque_linha,&ataque_coluna);
            //verifica se tem navios,diminui o numero de navios do jogador 1,e aumenta o saldo de ataques especias do jogador 2
            if(jogador1[ataque_linha][ataque_coluna] == 1){
                vivos_jogador1--;
                jogador1[ataque_linha][ataque_coluna]=0;
                contador_especial2++;
            }
            else{
                //caso erre o ataque o contador de ataque especial e modificado para 0
                contador_especial2=0;
            }
        }
        else{

            //tipo de ataque (especial)
            //coleta a orientação do ataque
            scanf("\n%c %d",&orientacao_ataque[0],&ataque_especial);
            //verifica se o jogador 2 tem saldo para o ataque
            if(contador_especial2>=2){
                //orientação do ataque (horizontal)
                if(orientacao_ataque[0] == 'h'){
                    //destroi toda a linha do mapa
                    for(int i=0;i<10;i++){
                        if(jogador1[ataque_especial][i]==1){
                            vivos_jogador1--;
                            jogador1[ataque_especial][i]=0;
                        }
                    }
                }
                else{
                    //destroi toda a coluna
                    for(int i=0;i<10;i++){
                        if(jogador1[i][ataque_especial]==1){
                            vivos_jogador1--;
                            jogador1[i][ataque_especial]=0;
                        }
                    }
                }
                //apos o ataque  especial o contador é modificado para 0
                contador_especial2=0;
            }else{
                //caso o jogador não tenha saldo o contador é modificado para 0
                contador_especial2=0;
            }

        }
        //diminui o numero de ataques para sair do loop
        numero_ataques--;
    }
//----------------saida do mapa do jogador 1--------------------
    //essa saida foi criada pelo professor
	printf("  |");
	for(int j=0;j<10;j++){
		printf(" %d",j);
	}
	printf("\n");
	printf("--+");
	for(int j=0;j<10;j++){
		printf("---");
	}
	putchar('\n');

		for (int j = 0;j < 10;j++){
			printf(" %d| ",j);
			for(int i = 0;i < 10;i++){
				printf(" %d",jogador1[j][i]);
			}
			putchar('\n');
		}
	putchar('\n');

//---------------------saida do mapa do jogador 2 ------------------------
    //saida criada pelo professor
	printf("  |");
	for(int j=0;j<10;j++){
		printf(" %d",j);
	}
	printf("\n");
	printf("--+");
	for(int j=0;j<10;j++){
		printf("---");
	}
	putchar('\n');

		for (int j = 0;j < 10;j++){
			printf(" %d| ",j);
			for(int i = 0;i < 10;i++){
				printf(" %d",jogador2[j][i]);
			}
			putchar('\n');
		}
	putchar('\n');
//---------------saida para verificar quem é o vencedor--------------------
    //empate
	if(vivos_jogador1 == vivos_jogador2){
        printf("0");
	}
	else{
        //jogador 1 venceu
        if(vivos_jogador1 > vivos_jogador2){
            printf("1");
        }
        //jogador 2 venceu
        else{
            printf("2");
        }
	}
    return 0;
}
