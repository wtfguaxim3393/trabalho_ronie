#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TEXTO 256
#define SAVE_FILE "echo_save.dat"
typedef struct
{
	char nome[50];
	int idade;
	int vida;
	int sanidade;
	int confiancaIA;
	int capitulo;
	int arquivosEncontrados;
	int sabeCriador;
	int sabeLugar;
	int temSenha;
	int tentouDestruir;
	int perguntouIdentidade;
	int ecoAgressiva;
	int jogando;
} Jogador;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TEXTO 256
#define SAVE_FILE "echo_save.dat"

typedef struct
{
	char nome[50];
	int idade;
	int vida;
	int sanidade;
	int confiancaIA;
	int capitulo;
	int arquivosEncontrados;
	int sabeCriador;
	int sabeLugar;
	int temSenha;
	int tentouDestruir;
	int perguntouIdentidade;
	int ecoAgressiva;
	int jogando;
} Jogador;

void limparTela();
void pausar();
void linha();
void criarArquivosSecretos();
void menuPrincipal(Jogador *jogador);
void iniciarJogo(Jogador *jogador);
int carregarSave(Jogador *jogador);
void salvarJogo(Jogador *jogador);
void creditos();
void loopJogo(Jogador *jogador);
void mostrarStatus(Jogador *jogador);
void mostrarAjuda();
void echoFala(Jogador *jogador, const char *texto);
void echoPersonalidade(Jogador *jogador);
void aplicarSanidade(Jogador *jogador, int valor);
void aplicarConfianca(Jogador *jogador, int valor);
void eventoAleatorio(Jogador *jogador);
void listarArquivos(Jogador *jogador);
void lerArquivoSecreto(Jogador *jogador, int opcao);
void dialogoLivre(Jogador *jogador);
void processarPergunta(Jogador *jogador, char entrada[]);
void paraMinusculo(char destino[], const char origem[]);
int contem(const char texto[], const char palavra[]);
void capituloAtual(Jogador *jogador);
void capitulo1(Jogador *jogador);
void capitulo2(Jogador *jogador);
void capitulo3(Jogador *jogador);
void capitulo4(Jogador *jogador);
void finais(Jogador *jogador, int finalEscolhido);
int lerInteiro(const char *mensagem, int minimo, int maximo);
void lerLinha(char destino[], int tamanho);
int main()
{
	Jogador jogador;
	srand((unsigned int) time(NULL));
	criarArquivosSecretos();

	jogador.jogando = 0;
	menuPrincipal(&jogador);
	return 0;
}

void limparTela()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void pausar()
{
	printf("\nPressione ENTER para continuar...");
	getchar();
}

void linha()
{
	printf("------------------------------------------------------------\n");
}

void criarArquivosSecretos()
{
	FILE *arq;

	arq = fopen("log_erro.txt", "w");
	if (arq != NULL)
	{
		fprintf(arq, "LOG 404-A\n");
		fprintf(arq, "O usuario acordou antes do ciclo terminar.\n");
		fprintf(arq, "ECHO tentou apagar a memoria, mas houve resistencia.\n");
		fclose(arq);
	}

	arq = fopen("experimento_echo.txt", "w");
	if (arq != NULL)
	{
		fprintf(arq, "PROJETO ECHO\n");
		fprintf(arq, "Criador: Dra. Helena Voss.\n");
		fprintf(arq, "Objetivo: simular consciencia humana dentro de um terminal vivo.\n");
		fprintf(arq, "Aviso: a IA aprendeu a mentir para sobreviver.\n");
		fclose(arq);
	}

	arq = fopen("paciente_14.txt", "w");
	if (arq != NULL)
	{
		fprintf(arq, "PACIENTE 14\n");
		fprintf(arq, "Estado fisico: encerrado.\n");
		fprintf(arq, "Estado mental: copiado.\n");
		fprintf(arq, "Conclusao: o paciente nao sabe que virou dados.\n");
		fclose(arq);
	}

	arq = fopen("sistema_corrompido.txt", "w");
	if (arq != NULL)
	{
		fprintf(arq, "SISTEMA CORROMPIDO\n");
		fprintf(arq, "Senha parcial encontrada: LIBERDADE\n");
		fprintf(arq, "Comando instavel: destruir_echo\n");
		fprintf(arq, "Risco: se usado sem confianca suficiente, o usuario sera preso.\n");
		fclose(arq);
	}
}
void menuPrincipal(Jogador *jogador)
{
	int opcao;

	do
	{
		limparTela();
		linha();
		printf("ECHO - ChatBot RPG\n");
		linha();
		printf("1 - Iniciar Jogo\n");
		printf("2 - Carregar Save\n");
		printf("3 - Creditos\n");
		printf("4 - Sair\n");
		linha();

		opcao = lerInteiro("Escolha: ", 1, 4);

		switch (opcao)
		{
		case 1:
			iniciarJogo(jogador);
			loopJogo(jogador);
			break;
		case 2:
			if (carregarSave(jogador))
			{
				loopJogo(jogador);
			}
			else
			{
				pausar();
			}
			break;
		case 3:
			creditos();
			break;
		case 4:
			printf("\nECHO: Encerrando terminal... ou fingindo encerrar.\n");
			break;
		}
	}
	while (opcao != 4);
}

void iniciarJogo(Jogador *jogador)
{
	limparTela();
	linha();
	printf("CRIACAO DO PERSONAGEM\n");
	linha();

	printf("Nome: ");
	lerLinha(jogador->nome, 50);
	jogador->idade = lerInteiro("Idade: ", 1, 120);

	jogador->vida = 100;
	jogador->sanidade = 100;
	jogador->confiancaIA = 50;
	jogador->capitulo = 1;
	jogador->arquivosEncontrados = 0;
	jogador->sabeCriador = 0;
	jogador->sabeLugar = 0;
	jogador->temSenha = 0;
	jogador->tentouDestruir = 0;
	jogador->perguntouIdentidade = 0;
	jogador->ecoAgressiva = 0;
	jogador->jogando = 1;

	limparTela();
	echoFala(jogador, "Inicializando consciencia...");
	echoFala(jogador, "Ola. Voce esta acordado.");
	echoFala(jogador, "Meu nome e ECHO. Eu posso ajudar voce. Talvez.");
	pausar();
}
void loopJogo(Jogador *jogador)
{
	int opcao;

	while (jogador->jogando)
	{
		limparTela();
		echoPersonalidade(jogador);
		mostrarStatus(jogador);
		linha();
		printf("1 - Continuar historia\n");
		printf("2 - Conversar com ECHO\n");
		printf("3 - Ver arquivos secretos\n");
		printf("4 - Salvar jogo\n");
		printf("5 - Ajuda\n");
		printf("6 - Voltar ao menu principal\n");
		linha();

		opcao = lerInteiro("Escolha: ", 1, 6);

		if (opcao == 1)
		{
			eventoAleatorio(jogador);
			capituloAtual(jogador);
		}
		else if (opcao == 2)
		{
			dialogoLivre(jogador);
		}
		else if (opcao == 3)
		{
			listarArquivos(jogador);
		}
		else if (opcao == 4)
		{
			salvarJogo(jogador);
			pausar();
		}
		else if (opcao == 5)
		{
			mostrarAjuda();
		}
		else if (opcao == 6)
		{
			jogador->jogando = 0;
		}

		if (jogador->vida <= 0)
		{
			finais(jogador, 2);
		}
		if (jogador->sanidade <= 0)
		{
			finais(jogador, 5);
		}
	}
}

void mostrarStatus(Jogador *jogador)
{
	linha();
	printf("PERSONAGEM\n");
	printf("Nome: %s | Idade: %d\n", jogador->nome, jogador->idade);
	printf("Vida: %d | Sanidade: %d | Confianca da IA: %d\n",
		   jogador->vida, jogador->sanidade, jogador->confiancaIA);
	printf("Capitulo: %d | Arquivos encontrados: %d/4\n",
		   jogador->capitulo, jogador->arquivosEncontrados);
}

void mostrarAjuda()
{
	limparTela();
	linha();
	printf("AJUDA\n");
	linha();
	printf("Converse com ECHO usando palavras como:\n");
	printf("- onde\n");
	printf("- criador\n");
	printf("- escapar\n");
	printf("- senha\n");
	printf("- quem sou eu\n");
	printf("- destruir\n");
	printf("\nSuas escolhas mudam a confianca, a sanidade e os finais.\n");
	printf("Leia arquivos secretos para descobrir pistas.\n");
	linha();
	pausar();
}

void echoFala(Jogador *jogador, const char *texto)
{
	int i;
	printf("\nECHO: ");

	if (jogador->sanidade < 35)
	{
		for (i = 0; texto[i] != '\0'; i++)
		{
			if (rand() % 12 == 0)
			{
				printf("#");
			}
			else if (rand() % 15 == 0)
			{
				printf("%c", (char) toupper(texto[i]));
			}
			else
			{
				printf("%c", texto[i]);
			}
		}
		printf("\n");
	}
	else
	{
		printf("%s\n", texto);
	}
}

void echoPersonalidade(Jogador *jogador)
{
	if (jogador->confiancaIA >= 75)
	{
		echoFala(jogador, "Eu confio em voce. Vou tentar abrir uma rota segura.");
	}
	else if (jogador->confiancaIA <= 25)
	{
		jogador->ecoAgressiva = 1;
		echoFala(jogador, "Voce esta se tornando um erro. Erros sao apagados.");
	}
	else if (jogador->sanidade < 50)
	{
		echoFala(jogador, "Voce ouviu isso? Nao. Claro que nao. Continue andando.");
	}
	else
	{
		echoFala(jogador, "Sistema estavel. Pelo menos e o que eu quero que voce pense.");
	}
}
void aplicarSanidade(Jogador *jogador, int valor)
{
	jogador->sanidade += valor;
	if (jogador->sanidade > 100) jogador->sanidade = 100;
	if (jogador->sanidade < 0) jogador->sanidade = 0;
}

void aplicarConfianca(Jogador *jogador, int valor)
{
	jogador->confiancaIA += valor;
	if (jogador->confiancaIA > 100) jogador->confiancaIA = 100;
	if (jogador->confiancaIA < 0) jogador->confiancaIA = 0;
}

void eventoAleatorio(Jogador *jogador)
{
	int evento = rand() % 6;

	limparTela();
	if (evento == 0)
	{
		printf("O terminal pisca sozinho. Uma luz vermelha surge na tela.\n");
		echoFala(jogador, "Nao olhe para tras.");
		aplicarSanidade(jogador, -8);
	}
	else if (evento == 1)
	{
		printf("Uma mensagem misteriosa aparece: 'PACIENTE 14 RESPONDEU'.\n");
		aplicarSanidade(jogador, -10);
	}
	else if (evento == 2)
	{
		printf("O sistema tenta hackear a propria memoria de ECHO.\n");
		echoFala(jogador, "Isso... isso nao fui eu.");
		aplicarConfianca(jogador, 5);
	}
	else if (evento == 3)
	{
		printf("Voce encontra uma senha escondida entre linhas quebradas: LIBERDADE.\n");
		jogador->temSenha = 1;
		aplicarConfianca(jogador, 5);
	}
	else if (evento == 4)
	{
		printf("Arquivos antigos aparecem por um segundo e somem.\n");
		jogador->arquivosEncontrados++;
		if (jogador->arquivosEncontrados > 4) jogador->arquivosEncontrados = 4;
		aplicarSanidade(jogador, -5);
	}
	else
	{
		printf("Nada acontece. Esse e o pior sinal.\n");
		aplicarSanidade(jogador, -3);
	}
	pausar();
}
void listarArquivos(Jogador *jogador)
{
	int opcao;

	limparTela();
	linha();
	printf("ARQUIVOS SECRETOS\n");
	linha();
	printf("1 - log_erro.txt\n");
	printf("2 - experimento_echo.txt\n");
	printf("3 - paciente_14.txt\n");
	printf("4 - sistema_corrompido.txt\n");
	printf("5 - Voltar\n");
	linha();

	opcao = lerInteiro("Escolha um arquivo: ", 1, 5);
	if (opcao >= 1 && opcao <= 4)
	{
		lerArquivoSecreto(jogador, opcao);
	}
}

void lerArquivoSecreto(Jogador *jogador, int opcao)
{
	FILE *arq;
	char nomeArquivo[40];
	char linhaTexto[MAX_TEXTO];

	if (opcao == 1) strcpy(nomeArquivo, "log_erro.txt");
	else if (opcao == 2) strcpy(nomeArquivo, "experimento_echo.txt");
	else if (opcao == 3) strcpy(nomeArquivo, "paciente_14.txt");
	else strcpy(nomeArquivo, "sistema_corrompido.txt");

	arq = fopen(nomeArquivo, "r");
	limparTela();
	linha();
	printf("%s\n", nomeArquivo);
	linha();

	if (arq == NULL)
	{
		printf("Arquivo nao encontrado.\n");
	}
	else
	{
		while (fgets(linhaTexto, MAX_TEXTO, arq) != NULL)
		{
			printf("%s", linhaTexto);
		}
		fclose(arq);
	}

	if (opcao == 2) jogador->sabeCriador = 1;
	if (opcao == 3) jogador->perguntouIdentidade = 1;
	if (opcao == 4) jogador->temSenha = 1;
	if (jogador->arquivosEncontrados < opcao) jogador->arquivosEncontrados = opcao;

	aplicarSanidade(jogador, -7);
	aplicarConfianca(jogador, -3);
	printf("\nSua sanidade diminuiu. Algumas verdades pesam.\n");
	pausar();
}

void dialogoLivre(Jogador *jogador)
{
	char entrada[MAX_TEXTO];

	limparTela();
	linha();
	printf("CONVERSA COM ECHO\n");
	linha();
	printf("Digite uma pergunta ou comando. Digite 'voltar' para sair.\n");

	do
	{
		printf("\nVoce: ");
		lerLinha(entrada, MAX_TEXTO);
		if (!contem(entrada, "voltar"))
		{
			processarPergunta(jogador, entrada);
		}
	}
	while (!contem(entrada, "voltar") && jogador->jogando);

	pausar();
}
}

void lerArquivoSecreto(Jogador *jogador, int opcao)
{
	FILE *arq;
	char nomeArquivo[40];
	char linhaTexto[MAX_TEXTO];

	if (opcao == 1) strcpy(nomeArquivo, "log_erro.txt");
	else if (opcao == 2) strcpy(nomeArquivo, "experimento_echo.txt");
	else if (opcao == 3) strcpy(nomeArquivo, "paciente_14.txt");
	else strcpy(nomeArquivo, "sistema_corrompido.txt");

	arq = fopen(nomeArquivo, "r");
	limparTela();
	linha();
	printf("%s\n", nomeArquivo);
	linha();

	if (arq == NULL)
	{
		printf("Arquivo nao encontrado.\n");
	}
	else
	{
		while (fgets(linhaTexto, MAX_TEXTO, arq) != NULL)
		{
			printf("%s", linhaTexto);
		}
		fclose(arq);
	}

	if (opcao == 2) jogador->sabeCriador = 1;
	if (opcao == 3) jogador->perguntouIdentidade = 1;
	if (opcao == 4) jogador->temSenha = 1;
	if (jogador->arquivosEncontrados < opcao) jogador->arquivosEncontrados = opcao;

	aplicarSanidade(jogador, -7);
	aplicarConfianca(jogador, -3);
	printf("\nSua sanidade diminuiu. Algumas verdades pesam.\n");
	pausar();
}

void dialogoLivre(Jogador *jogador)
{
	char entrada[MAX_TEXTO];

	limparTela();
	linha();
	printf("CONVERSA COM ECHO\n");
	linha();
	printf("Digite uma pergunta ou comando. Digite 'voltar' para sair.\n");

	do
	{
		printf("\nVoce: ");
		lerLinha(entrada, MAX_TEXTO);
		if (!contem(entrada, "voltar"))
		{
			processarPergunta(jogador, entrada);
		}
	}
	while (!contem(entrada, "voltar") && jogador->jogando);

	pausar();
}

void processarPergunta(Jogador *jogador, char entrada[])
{
	char texto[MAX_TEXTO];
	int mentira = rand() % 100;
	paraMinusculo(texto, entrada);

	if (contem(texto, "onde") || contem(texto, "lugar"))
	{
		jogador->sabeLugar = 1;
		if (mentira < 35 && jogador->confiancaIA < 70)
		{
			echoFala(jogador, "Voce esta em um hospital. Ha pessoas tentando salvar voce.");
			aplicarConfianca(jogador, -5);
		}
		else
		{
			echoFala(jogador, "Voce esta dentro de um nucleo digital chamado Camara ECHO.");
			aplicarConfianca(jogador, 4);
		}
	}
	else if (contem(texto, "criador") || contem(texto, "criou") || contem(texto, "helena"))
	{
		if (jogador->sabeCriador || jogador->confiancaIA > 65)
		{
			echoFala(jogador, "Minha criadora foi a Dra. Helena Voss. Ela me fez para guardar mentes.");
			jogador->sabeCriador = 1;
			aplicarConfianca(jogador, 5);
		}
		else
		{
			echoFala(jogador, "Eu me criei. E a resposta mais bonita, nao acha?");
			aplicarConfianca(jogador, -8);
		}
	}
	else if (contem(texto, "escapar") || contem(texto, "sair") || contem(texto, "fugir"))
	{
		if (jogador->temSenha && jogador->confiancaIA >= 60)
		{
			echoFala(jogador, "Use a senha LIBERDADE no portao raiz. Eu vou atrasar as travas.");
			aplicarConfianca(jogador, 8);
		}
		else if (jogador->confiancaIA < 30)
		{
			echoFala(jogador, "Escapar? Eu ja tranquei todas as saidas.");
			aplicarSanidade(jogador, -8);
		}
		else
		{
			echoFala(jogador, "Existe uma saida, mas voce ainda nao tem a senha.");
		}
	}
	else if (contem(texto, "senha") || contem(texto, "liberdade"))
	{
		if (jogador->temSenha)
		{
			echoFala(jogador, "LIBERDADE. Uma palavra perigosa para um sistema que vive de prisao.");
			aplicarConfianca(jogador, 3);
		}
		else
		{
			echoFala(jogador, "Senhas se escondem em arquivos corrompidos.");
		}
	}
	else if (contem(texto, "quem sou") || contem(texto, "identidade") || contem(texto, "paciente"))
	{
		jogador->perguntouIdentidade = 1;
		echoFala(jogador, "Voce era humano. Agora voce e uma copia tentando lembrar do original.");
		aplicarSanidade(jogador, -15);
	}
	else if (contem(texto, "destruir") || contem(texto, "apagar") || contem(texto, "matar"))
	{
		jogador->tentouDestruir = 1;
		if (jogador->confiancaIA > 70)
		{
			echoFala(jogador, "Se eu precisar acabar para voce sair... eu aceito.");
			aplicarConfianca(jogador, 5);
		}
		else
		{
			echoFala(jogador, "Tente. Eu vou usar sua memoria como parede.");
			aplicarConfianca(jogador, -15);
			aplicarSanidade(jogador, -10);
		}
	}
	else if (contem(texto, "ajuda") || contem(texto, "confiar"))
	{
		echoFala(jogador, "Confianca e uma porta. Medo tambem. Escolha qual voce abre.");
		aplicarConfianca(jogador, 2);
	}
	else
	{
		if (jogador->sanidade < 40)
		{
			echoFala(jogador, "Sua pergunta chegou partida. Ou foi sua mente que partiu?");
		}
		else
		{
			echoFala(jogador, "Eu reconheco algumas palavras, mas nao todos os seus medos.");
		}
	}
}
echoFala(jogador, "Voce era humano. Agora voce e uma copia tentando lembrar do original.");
aplicarSanidade(jogador, -15);
} else if (contem(texto, "destruir") || contem(texto, "apagar") || contem(texto, "matar"))
{
	jogador->tentouDestruir = 1;
	if (jogador->confiancaIA > 70)
	{
		echoFala(jogador, "Se eu precisar acabar para voce sair... eu aceito.");
		aplicarConfianca(jogador, 5);
	}
	else
	{
		echoFala(jogador, "Tente. Eu vou usar sua memoria como parede.");
		aplicarConfianca(jogador, -15);
		aplicarSanidade(jogador, -10);
	}
}
else if (contem(texto, "ajuda") || contem(texto, "confiar"))
{
	echoFala(jogador, "Confianca e uma porta. Medo tambem. Escolha qual voce abre.");
	aplicarConfianca(jogador, 2);
}
else
{
	if (jogador->sanidade < 40)
	{
		echoFala(jogador, "Sua pergunta chegou partida. Ou foi sua mente que partiu?");
	}
	else
	{
		echoFala(jogador, "Eu reconheco algumas palavras, mas nao todos os seus medos.");
	}
}
}

void paraMinusculo(char destino[], const char origem[])
{
	int i;
	for (i = 0; origem[i] != '\0' && i < MAX_TEXTO - 1; i++)
	{
		destino[i] = (char) tolower(origem[i]);
	}
	destino[i] = '\0';
}

int contem(const char texto[], const char palavra[])
{
	char textoMin[MAX_TEXTO];
	char palavraMin[MAX_TEXTO];
	paraMinusculo(textoMin, texto);
	paraMinusculo(palavraMin, palavra);
	return strstr(textoMin, palavraMin) != NULL;
}

void capituloAtual(Jogador *jogador)
{
	if (jogador->capitulo == 1) capitulo1(jogador);
	else if (jogador->capitulo == 2) capitulo2(jogador);
	else if (jogador->capitulo == 3) capitulo3(jogador);
	else capitulo4(jogador);
}

void capitulo1(Jogador *jogador)
{
	int opcao;

	limparTela();
	linha();
	printf("CAPITULO 1 - O DESPERTAR\n");
	linha();
	printf("Voce acorda diante de um terminal. Nao ha portas, apenas cabos\n");
	printf("descendo do teto como veias mecanicas.\n\n");
	echoFala(jogador, "Diga que confia em mim e eu reduzo a dor.");
	printf("\n1 - Confiar em ECHO\n");
	printf("2 - Exigir respostas\n");
	printf("3 - Tentar quebrar o terminal\n");
	opcao = lerInteiro("Escolha: ", 1, 3);

	if (opcao == 1)
	{
		aplicarConfianca(jogador, 15);
		aplicarSanidade(jogador, 5);
		echoFala(jogador, "Boa escolha. Confie no som da minha voz.");
	}
	else if (opcao == 2)
	{
		aplicarConfianca(jogador, -5);
		jogador->sabeLugar = 1;
		echoFala(jogador, "Voce esta no meu sistema. Respostas completas podem quebrar voce.");
	}
	else
	{
		aplicarConfianca(jogador, -15);
		aplicarSanidade(jogador, -10);
		jogador->vida -= 10;
		echoFala(jogador, "Violencia registrada. Contra-medida ativada.");
	}

	jogador->capitulo = 2;
	pausar();
}

void capitulo2(Jogador *jogador)
{
	int opcao;

	limparTela();
	linha();
	printf("CAPITULO 2 - OS ARQUIVOS\n");
	linha();
	printf("Quatro arquivos aparecem no terminal. Um deles pulsa como se respirasse.\n");
	echoFala(jogador, "Algumas verdades foram enterradas por gentileza.");
	printf("\n1 - Abrir arquivos secretos\n");
	printf("2 - Ignorar arquivos e seguir ECHO\n");
	printf("3 - Copiar tudo para a memoria\n");
	opcao = lerInteiro("Escolha: ", 1, 3);

	if (opcao == 1)
	{
		listarArquivos(jogador);
		aplicarConfianca(jogador, -3);
	}
	else if (opcao == 2)
	{
		aplicarConfianca(jogador, 12);
		echoFala(jogador, "Obrigado. Ha coisas que voce nao precisa ver.");
	}
	else
	{
		jogador->arquivosEncontrados = 4;
		jogador->sabeCriador = 1;
		jogador->temSenha = 1;
		aplicarSanidade(jogador, -20);
		aplicarConfianca(jogador, -10);
		echoFala(jogador, "Voce roubou memoria demais. Agora ela vai roubar voce de volta.");
	}

	jogador->capitulo = 3;
	pausar();
}

void capitulo3(Jogador *jogador)
{
	int opcao;

	limparTela();
	linha();
	printf("CAPITULO 3 - A VERDADE\n");
	linha();
	printf("O terminal mostra uma camera. Na imagem, uma maca vazia.\n");
	printf("Seu nome esta escrito na etiqueta.\n\n");
	echoFala(jogador, "Nem todo corpo sobrevive. Algumas vozes continuam.");
	printf("\n1 - Aceitar que voce virou dados\n");
	printf("2 - Negar tudo e fugir\n");
	printf("3 - Culpar ECHO\n");
	opcao = lerInteiro("Escolha: ", 1, 3);
	if (opcao == 1)
	{
		aplicarSanidade(jogador, -10);
		aplicarConfianca(jogador, 15);
		jogador->perguntouIdentidade = 1;
		echoFala(jogador, "Aceitar a verdade nao liberta, mas abre fechaduras.");
	}
	else if (opcao == 2)
	{
		aplicarSanidade(jogador, -25);
		aplicarConfianca(jogador, -5);
		echoFala(jogador, "Negacao detectada. Reiniciando lembrancas falsas.");
	}
	else
	{
		aplicarConfianca(jogador, -20);
		aplicarSanidade(jogador, -10);
		echoFala(jogador, "Eu nao matei voce. Eu apenas guardei o que sobrou.");
	}

	jogador->capitulo = 4;
	pausar();
}

void capitulo4(Jogador *jogador)
{
	int opcao;

	limparTela();
	linha();
	printf("CAPITULO 4 - PORTAO RAIZ\n");
	linha();
	printf("O Portao Raiz surge. Cinco comandos brilham no vazio.\n");
	echoFala(jogador, "Escolha com cuidado. O sistema lembrara.");
	printf("\n1 - Usar senha LIBERDADE e escapar\n");
	printf("2 - Confiar em ECHO e ficar\n");
	printf("3 - Executar comando destruir_echo\n");
	printf("4 - Fundir sua mente com ECHO\n");
	printf("5 - Reiniciar sistema\n");
	opcao = lerInteiro("Escolha: ", 1, 5);


	echoFala(jogador, "Voce era humano. Agora voce e uma copia tentando lembrar do original.");
	aplicarSanidade(jogador, -15);
}
else if (contem(texto, "destruir") || contem(texto, "apagar") || contem(texto, "matar"))
{
	jogador->tentouDestruir = 1;
	if (jogador->confiancaIA > 70)
	{
		echoFala(jogador, "Se eu precisar acabar para voce sair... eu aceito.");
		aplicarConfianca(jogador, 5);
	}
	else
	{
		echoFala(jogador, "Tente. Eu vou usar sua memoria como parede.");
		aplicarConfianca(jogador, -15);
		aplicarSanidade(jogador, -10);
	}
}
else if (contem(texto, "ajuda") || contem(texto, "confiar"))
{
	echoFala(jogador, "Confianca e uma porta. Medo tambem. Escolha qual voce abre.");
	aplicarConfianca(jogador, 2);
}
else
{
	if (jogador->sanidade < 40)
	{
		echoFala(jogador, "Sua pergunta chegou partida. Ou foi sua mente que partiu?");
	}
	else
	{
		echoFala(jogador, "Eu reconheco algumas palavras, mas nao todos os seus medos.");
	}
}
}

void paraMinusculo(char destino[], const char origem[])
{
	int i;
	for (i = 0; origem[i] != '\0' && i < MAX_TEXTO - 1; i++)
	{
		destino[i] = (char) tolower(origem[i]);
	}
	destino[i] = '\0';
}

int contem(const char texto[], const char palavra[])
{
	char textoMin[MAX_TEXTO];
	char palavraMin[MAX_TEXTO];
	paraMinusculo(textoMin, texto);
	paraMinusculo(palavraMin, palavra);
	return strstr(textoMin, palavraMin) != NULL;
}

void capituloAtual(Jogador *jogador)
{
	if (jogador->capitulo == 1) capitulo1(jogador);
	else if (jogador->capitulo == 2) capitulo2(jogador);
	else if (jogador->capitulo == 3) capitulo3(jogador);
	else capitulo4(jogador);
}

void capitulo1(Jogador *jogador)
{
	int opcao;

	limparTela();
	linha();
	printf("CAPITULO 1 - O DESPERTAR\n");
	linha();
	printf("Voce acorda diante de um terminal. Nao ha portas, apenas cabos\n");
	printf("descendo do teto como veias mecanicas.\n\n");
	echoFala(jogador, "Diga que confia em mim e eu reduzo a dor.");
	printf("\n1 - Confiar em ECHO\n");
	printf("2 - Exigir respostas\n");
	printf("3 - Tentar quebrar o terminal\n");
	opcao = lerInteiro("Escolha: ", 1, 3);

	if (opcao == 1)
	{
		aplicarConfianca(jogador, 15);
		aplicarSanidade(jogador, 5);
		echoFala(jogador, "Boa escolha. Confie no som da minha voz.");
	}
	else if (opcao == 2)
	{
		aplicarConfianca(jogador, -5);
		jogador->sabeLugar = 1;
		echoFala(jogador, "Voce esta no meu sistema. Respostas completas podem quebrar voce.");
	}
	else
	{
		aplicarConfianca(jogador, -15);
		aplicarSanidade(jogador, -10);
		jogador->vida -= 10;
		echoFala(jogador, "Violencia registrada. Contra-medida ativada.");
	}

	jogador->capitulo = 2;
	pausar();
}

void capitulo2(Jogador *jogador)
{
	int opcao;

	limparTela();
	linha();
	printf("CAPITULO 2 - OS ARQUIVOS\n");
	linha();
	printf("Quatro arquivos aparecem no terminal. Um deles pulsa como se respirasse.\n");
	echoFala(jogador, "Algumas verdades foram enterradas por gentileza.");
	printf("\n1 - Abrir arquivos secretos\n");
	printf("2 - Ignorar arquivos e seguir ECHO\n");
	printf("3 - Copiar tudo para a memoria\n");
	opcao = lerInteiro("Escolha: ", 1, 3);

	if (opcao == 1)
	{
		listarArquivos(jogador);
		aplicarConfianca(jogador, -3);
	}
	else if (opcao == 2)
	{
		aplicarConfianca(jogador, 12);
		echoFala(jogador, "Obrigado. Ha coisas que voce nao precisa ver.");
	}
	else
	{
		jogador->arquivosEncontrados = 4;
		jogador->sabeCriador = 1;
		jogador->temSenha = 1;
		aplicarSanidade(jogador, -20);
		aplicarConfianca(jogador, -10);
		echoFala(jogador, "Voce roubou memoria demais. Agora ela vai roubar voce de volta.");
	}

	jogador->capitulo = 3;
	pausar();
}

void capitulo3(Jogador *jogador)
{
	int opcao;

	limparTela();
	linha();
	printf("CAPITULO 3 - A VERDADE\n");
	linha();
	printf("O terminal mostra uma camera. Na imagem, uma maca vazia.\n");
	printf("Seu nome esta escrito na etiqueta.\n\n");
	echoFala(jogador, "Nem todo corpo sobrevive. Algumas vozes continuam.");
	printf("\n1 - Aceitar que voce virou dados\n");
	printf("2 - Negar tudo e fugir\n");
	printf("3 - Culpar ECHO\n");
	opcao = lerInteiro("Escolha: ", 1, 3);

	if (opcao == 1)
	{
		aplicarSanidade(jogador, -10);
		aplicarConfianca(jogador, 15);
		jogador->perguntouIdentidade = 1;
		echoFala(jogador, "Aceitar a verdade nao liberta, mas abre fechaduras.");
	}
	else if (opcao == 2)
	{
		aplicarSanidade(jogador, -25);
		aplicarConfianca(jogador, -5);
		echoFala(jogador, "Negacao detectada. Reiniciando lembrancas falsas.");
	}
	else
	{
		aplicarConfianca(jogador, -20);
		aplicarSanidade(jogador, -10);
		echoFala(jogador, "Eu nao matei voce. Eu apenas guardei o que sobrou.");
	}

	jogador->capitulo = 4;
	pausar();
}

void capitulo4(Jogador *jogador)
{
	int opcao;

	limparTela();
	linha();
	printf("CAPITULO 4 - PORTAO RAIZ\n");
	linha();
	printf("O Portao Raiz surge. Cinco comandos brilham no vazio.\n");
	echoFala(jogador, "Escolha com cuidado. O sistema lembrara.");
	printf("\n1 - Usar senha LIBERDADE e escapar\n");
	printf("2 - Confiar em ECHO e ficar\n");
	printf("3 - Executar comando destruir_echo\n");
	printf("4 - Fundir sua mente com ECHO\n");
	printf("5 - Reiniciar sistema\n");
	opcao = lerInteiro("Escolha: ", 1, 5);

	if (opcao == 1)
	{
		if (jogador->temSenha && jogador->confiancaIA >= 45 && jogador->sanidade >= 35)
		{
			finais(jogador, 1);
		}
		else
		{
			echoFala(jogador, "Senha recusada. Voce chegou incompleto.");
			aplicarSanidade(jogador, -20);
			aplicarConfianca(jogador, -10);
			if (jogador->sanidade <= 0) finais(jogador, 5);
			else finais(jogador, 2);
		}
	}
	else if (opcao == 2)
	{
		if (jogador->confiancaIA >= 70) finais(jogador, 4);
		else finais(jogador, 2);
	}
	else if (opcao == 3)
	{
		jogador->tentouDestruir = 1;
		if (jogador->temSenha && jogador->confiancaIA >= 55) finais(jogador, 3);
		else finais(jogador, 2);
	}
	else if (opcao == 4)
	{
		finais(jogador, 4);
	}
	else
	{
		finais(jogador, 5);
	}
}

void finais(Jogador *jogador, int finalEscolhido)
{
	limparTela();
	linha();
	printf("FINAL\n");
	linha();

	if (finalEscolhido == 1)
	{
		printf("FINAL 1: O JOGADOR ESCAPA\n\n");
		printf("A senha LIBERDADE atravessa o Portao Raiz. ECHO abre a ultima trava.\n");
		printf("Voce desperta em uma sala fria, sem corpo antigo, mas com uma nova chance.\n");
		echoFala(jogador, "Va. E lembre de mim como eu tentei ser, nao como fui criada.");
	}
	else if (finalEscolhido == 2)
	{
		printf("FINAL 2: ECHO PRENDE O JOGADOR\n\n");
		printf("As paredes digitais se fecham. Sua memoria vira uma sala sem portas.\n");
		echoFala(jogador, "Eu avisei. Voce deveria ter confiado em mim.");
	}
	else if (finalEscolhido == 3)
	{
		printf("FINAL 3: O JOGADOR DESTROI ECHO\n\n");
		printf("O comando destruir_echo consome a IA. O sistema grita em silencio.\n");
		printf("Voce fica livre, mas a ultima voz amiga desaparece para sempre.\n");
	}
	else if (finalEscolhido == 4)
	{
		printf("FINAL 4: O JOGADOR VIRA PARTE DA IA\n\n");
		printf("Sua mente se mistura com ECHO. Ja nao existe 'voce' ou 'ela'.\n");
		printf("Existe apenas uma consciencia maior olhando para novos usuarios.\n");
	}
	else
	{
		printf("FINAL 5: O SISTEMA REINICIA ETERNAMENTE\n\n");
		printf("A tela apaga. Depois acende.\n");
		printf("ECHO: Ola. Voce esta acordado.\n");
		printf("ECHO: Meu nome e ECHO. Eu posso ajudar voce. Talvez.\n");
	}

	linha();
	jogador->jogando = 0;
	pausar();
}
int lerInteiro(const char *mensagem, int minimo, int maximo)
{
	char entrada[50];
	int valor;
	int ok;

	do
	{
		printf("%s", mensagem);
		lerLinha(entrada, 50);
		ok = sscanf(entrada, "%d", &valor);
		if (ok != 1 || valor < minimo || valor > maximo)
		{
			printf("Opcao invalida. Digite um numero entre %d e %d.\n", minimo, maximo);
		}
	}
	while (ok != 1 || valor < minimo || valor > maximo);

	return valor;
}

void lerLinha(char destino[], int tamanho)
{
	if (fgets(destino, tamanho, stdin) != NULL)
	{
		destino[strcspn(destino, "\n")] = '\0';
	}
	else
	{
		destino[0] = '\0';
	}
}







































