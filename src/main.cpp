#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <clocale>
#include <limits>

char ARQUIVO_BINARIO[512] = "data/livros.dat";
char ARQUIVO_TEXTO[512] = "data/livros.txt";
const int TAM_TITULO = 100;
const int TAM_AUTOR = 100;

struct Livro {
    int id;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int ano;
    int status; // 1 = ativo, 0 = excluido logicamente
};

void pausar();
void limparTela();
void limparBuffer();
int lerInteiro(const char *mensagem, int minimo, int maximo);
void lerTexto(const char *mensagem, char *destino, int tamanho);
int contarRegistrosAtivos();
int gerarProximoId();
bool localizarLivro(int id, long *posicao, Livro *livro);
void cadastrarLivro();
void consultarLivro();
void listarLivros();
void exportarTxt();
void excluirLivro();
void mostrarQuantidade();
void mostrarMenu();
bool inicializarArquivos();

void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void limparTela() {
    // Em vez de depender do terminal, apenas adiciona espacos verticais.
    for (int i = 0; i < 30; ++i) {
        printf("\n");
    }
}

void limparBuffer() {
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

int lerInteiro(const char *mensagem, int minimo, int maximo) {
    int valor;

    while (true) {
        printf("%s", mensagem);

        if (scanf("%d", &valor) == 1) {
            limparBuffer();
            if (valor >= minimo && valor <= maximo) {
                return valor;
            }
        } else {
            limparBuffer();
        }

        printf("Valor invalido. Digite um numero entre %d e %d.\n", minimo, maximo);
    }
}

void lerTexto(const char *mensagem, char *destino, int tamanho) {
    while (true) {
        printf("%s", mensagem);
        if (fgets(destino, tamanho, stdin) == NULL) {
            printf("\nEntrada encerrada.\n");
            exit(EXIT_FAILURE);
        }

        size_t tamanhoLido = strlen(destino);
        if (tamanhoLido > 0 && destino[tamanhoLido - 1] == '\n') {
            destino[tamanhoLido - 1] = '\0';
            tamanhoLido--;
        } else {
            limparBuffer();
        }

        if (tamanhoLido > 0) {
            return;
        }

        printf("O campo nao pode ficar vazio.\n");
    }
}

// Tenta encontrar a pasta data na posicao correta.
// O Dev-C++ costuma iniciar em src; pelo terminal, no projeto raiz.
// A pasta data ja existe no ZIP enviado e contem .gitkeep.
bool tentarPastaDados(const char *pasta) {
    char binario[512];
    char texto[512];
    if (strlen(pasta) + strlen("/livros.dat") >= sizeof(binario)) {
        return false;
    }
    strcpy(binario, pasta);
    strcat(binario, "/livros.dat");
    strcpy(texto, pasta);
    strcat(texto, "/livros.txt");

    FILE *arquivo = fopen(binario, "ab");
    if (arquivo == NULL) {
        return false;
    }
    fclose(arquivo);
    strcpy(ARQUIVO_BINARIO, binario);
    strcpy(ARQUIVO_TEXTO, texto);
    return true;
}

bool inicializarArquivos() {
    // Locais mais comuns onde o programa e executado.
    const char *pastas[] = {"data", "../data", "../../data"};
    for (int i = 0; i < 3; ++i) {
        if (tentarPastaDados(pastas[i])) {
            return true;
        }
    }

    // Se o Dev-C++ usar outra pasta de trabalho, tenta a pasta
    // data ao lado de src, partindo da localizacao do codigo-fonte.
    char origem[512];
    strncpy(origem, __FILE__, sizeof(origem) - 1);
    origem[sizeof(origem) - 1] = '\0';
    char *barraDireita = strrchr(origem, '/');
    char *barraEsquerda = strrchr(origem, '\\');
    char *ultimaBarra = barraDireita;
    if (barraEsquerda != NULL &&
        (ultimaBarra == NULL || barraEsquerda > ultimaBarra)) {
        ultimaBarra = barraEsquerda;
    }
    if (ultimaBarra != NULL) {
        *ultimaBarra = '\0';
        char alternativa[512];
        if (strlen(origem) + strlen("/../data") < sizeof(alternativa)) {
            strcpy(alternativa, origem);
            strcat(alternativa, "/../data");
            if (tentarPastaDados(alternativa)) {
                return true;
            }
        }
    }
    return false;
}

int contarRegistrosAtivos() {
    FILE *arquivo = fopen(ARQUIVO_BINARIO, "rb");
    Livro livro;
    int quantidade = 0;

    if (arquivo == NULL) {
        return 0;
    }

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro.status == 1) {
            quantidade++;
        }
    }

    fclose(arquivo);
    return quantidade;
}

int gerarProximoId() {
    FILE *arquivo = fopen(ARQUIVO_BINARIO, "rb");
    Livro livro;
    int maiorId = 0;

    if (arquivo == NULL) {
        return 1;
    }

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro.id > maiorId) {
            maiorId = livro.id;
        }
    }

    fclose(arquivo);
    return maiorId + 1;
}

bool localizarLivro(int id, long *posicao, Livro *livro) {
    FILE *arquivo = fopen(ARQUIVO_BINARIO, "rb");

    if (arquivo == NULL) {
        return false;
    }

    while (fread(livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro->id == id && livro->status == 1) {
            long fimRegistro = ftell(arquivo);
            *posicao = fimRegistro - static_cast<long>(sizeof(Livro));
            fclose(arquivo);
            return true;
        }
    }

    fclose(arquivo);
    return false;
}

void cadastrarLivro() {
    Livro livro = {0, "", "", 0, 0};
    FILE *arquivo = fopen(ARQUIVO_BINARIO, "ab");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binario.\n");
        pausar();
        return;
    }

    livro.id = gerarProximoId();
    printf("\n=== CADASTRO DE LIVRO ===\n");
    printf("Codigo gerado: %d\n", livro.id);

    lerTexto("Titulo: ", livro.titulo, TAM_TITULO);
    lerTexto("Autor: ", livro.autor, TAM_AUTOR);
    livro.ano = lerInteiro("Ano de publicacao: ", 0, 3000);
    livro.status = 1;

    if (fwrite(&livro, sizeof(Livro), 1, arquivo) == 1) {
        printf("\nLivro cadastrado com sucesso!\n");
    } else {
        printf("\nErro ao gravar o livro.\n");
    }

    fclose(arquivo);
    pausar();
}

void consultarLivro() {
    int id = lerInteiro("Digite o codigo do livro: ", 1, 1000000000);
    Livro livro = {0, "", "", 0, 0};
    long posicao = 0;

    printf("\n=== CONSULTA POR CODIGO ===\n");

    if (localizarLivro(id, &posicao, &livro)) {
        printf("Codigo : %d\n", livro.id);
        printf("Titulo : %s\n", livro.titulo);
        printf("Autor  : %s\n", livro.autor);
        printf("Ano    : %d\n", livro.ano);
        printf("Status : Ativo\n");
    } else {
        printf("Livro ativo nao encontrado.\n");
    }

    pausar();
}

void listarLivros() {
    FILE *arquivo = fopen(ARQUIVO_BINARIO, "rb");
    Livro livro;
    bool encontrou = false;

    printf("\n=== LIVROS ATIVOS ===\n");

    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        pausar();
        return;
    }

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro.status == 1) {
            encontrou = true;
            printf("\n[%d] %s | %s | %d\n", livro.id, livro.titulo, livro.autor, livro.ano);
        }
    }

    if (!encontrou) {
        printf("Nenhum livro ativo cadastrado.\n");
    }

    fclose(arquivo);
    pausar();
}

void exportarTxt() {
    FILE *entrada = fopen(ARQUIVO_BINARIO, "rb");
    FILE *saida = fopen(ARQUIVO_TEXTO, "w");
    Livro livro;
    int total = 0;
    int ativos = 0;

    printf("\n=== EXPORTACAO PARA TXT ===\n");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao preparar os arquivos de exportacao.\n");
        if (entrada != NULL) fclose(entrada);
        if (saida != NULL) fclose(saida);
        pausar();
        return;
    }

    fprintf(saida, "RELATORIO DE LIVROS - BIBLIOTECA\n");
    fprintf(saida, "================================\n\n");

    // O enunciado pede TODOS os registros cadastrados.
    // Incluimos os excluidos logicamente, identificando o status.
    while (fread(&livro, sizeof(Livro), 1, entrada) == 1) {
        total++;
        if (livro.status == 1) {
            ativos++;
        }
        fprintf(saida, "Codigo: %d\n", livro.id);
        fprintf(saida, "Titulo: %s\n", livro.titulo);
        fprintf(saida, "Autor: %s\n", livro.autor);
        fprintf(saida, "Ano: %d\n", livro.ano);
        fprintf(saida, "Status: %s\n", livro.status == 1 ? "Ativo" : "Excluido logicamente");
        fprintf(saida, "--------------------------------\n");
    }

    fprintf(saida, "Total de registros cadastrados: %d\n", total);
    fprintf(saida, "Total de livros ativos: %d\n", ativos);
    fprintf(saida, "Total excluidos logicamente: %d\n", total - ativos);

    fclose(entrada);
    fclose(saida);

    printf("Arquivo TXT gerado em: %s\n", ARQUIVO_TEXTO);
    printf("Registros exportados (ativos e excluidos): %d\n", total);
    pausar();
}

void excluirLivro() {
    int id = lerInteiro("Digite o codigo do livro a excluir: ", 1, 1000000000);
    FILE *arquivo = fopen(ARQUIVO_BINARIO, "rb+");
    Livro livro;
    long posicao = 0;
    bool encontrado = false;

    printf("\n=== EXCLUSAO LOGICA ===\n");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        pausar();
        return;
    }

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro.id == id && livro.status == 1) {
            encontrado = true;
            posicao = ftell(arquivo) - static_cast<long>(sizeof(Livro));
            break;
        }
    }

    if (!encontrado) {
        printf("Livro ativo nao encontrado.\n");
        fclose(arquivo);
        pausar();
        return;
    }

    printf("Livro encontrado: %s - %s\n", livro.titulo, livro.autor);
    printf("Confirmar exclusao? (1-Sim / 0-Nao): ");
    int confirmar;
    if (scanf("%d", &confirmar) != 1) {
        limparBuffer();
        confirmar = 0;
    } else {
        limparBuffer();
    }

    if (confirmar == 1) {
        livro.status = 0;
        fseek(arquivo, posicao, SEEK_SET);

        if (fwrite(&livro, sizeof(Livro), 1, arquivo) == 1) {
            printf("Livro excluido logicamente. O registro continua no arquivo binario com status = 0.\n");
        } else {
            printf("Erro ao atualizar o registro.\n");
        }
    } else {
        printf("Operacao cancelada.\n");
    }

    fclose(arquivo);
    pausar();
}

void mostrarQuantidade() {
    printf("\n=== QUANTIDADE DE REGISTROS ===\n");
    printf("Livros ativos no sistema: %d\n", contarRegistrosAtivos());
    pausar();
}

void mostrarMenu() {
    printf("\n===============================================\n");
    printf("      SISTEMA DE GERENCIAMENTO DE BIBLIOTECA\n");
    printf("===============================================\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Consultar livro por codigo\n");
    printf("3 - Listar livros ativos\n");
    printf("4 - Exportar registros para TXT\n");
    printf("5 - Excluir livro (exclusao logica)\n");
    printf("6 - Contabilizar livros ativos\n");
    printf("0 - Sair\n");
    printf("===============================================\n");
}

int main() {
    setlocale(LC_ALL, "");
    if (!inicializarArquivos()) {
        printf("ERRO: Nao encontrei a pasta 'data' do projeto, ou nao tenho permissao de gravacao.\n");
        printf("Mantenha as pastas 'src' e 'data' juntas dentro de 'projeto-biblioteca'.\n");
        printf("Abra o arquivo src/main.cpp a partir dessa pasta e execute de novo.\n");
        pausar();
        return 1;
    }
    printf("Arquivo dos livros: %s\n", ARQUIVO_BINARIO);

    int opcao;

    do {
        limparTela();
        mostrarMenu();
        opcao = lerInteiro("Escolha uma opcao: ", 0, 6);
        limparTela();

        switch (opcao) {
            case 1:
                cadastrarLivro();
                break;
            case 2:
                consultarLivro();
                break;
            case 3:
                listarLivros();
                break;
            case 4:
                exportarTxt();
                break;
            case 5:
                excluirLivro();
                break;
            case 6:
                mostrarQuantidade();
                break;
            case 0:
                printf("\nPrograma encerrado. Ate a proxima!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
