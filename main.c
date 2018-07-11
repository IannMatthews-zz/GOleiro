#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Digitar nome do arquivo txt (SEM A EXTENCAO):");


    /// PREPARA NOME ARQUIVO SEM GO
    char nomeArquivoSemExtensao[100];
    char nomeArquivo[100];
    scanf("%s", &nomeArquivoSemExtensao);
    strcpy(nomeArquivo, nomeArquivoSemExtensao);
    strcat(nomeArquivo, ".txt");

    /// ABRE ARQUIVO SEM GO
    FILE *arquivoLeitura;
    arquivoLeitura = fopen(nomeArquivo, "r");

    if (arquivoLeitura == NULL) {
        printf("Arquivo nao existe");
        return;
    }

    /// ABRIR ARQUIVO FINAL COM GO
    char nomeGoArquivo[100];
    strcpy(nomeGoArquivo, nomeArquivoSemExtensao);
    strcat(nomeGoArquivo, "GO.txt");
    FILE *arquivoGO;
    arquivoGO = fopen(nomeGoArquivo, "w");

    /// LER ARQUIVO E COPIAR AS LINHAS PARA O ARQUIVO FINAL

    char linha[1000];
    int quantLinhas = 0;
    while(!feof(arquivoLeitura)) {
        fgets(linha, 1000, arquivoLeitura);
        fputs(linha, arquivoGO);
        if(quantLinhas == 1000){
            fputs("GO\n", arquivoGO);
            quantLinhas = 0;
        }
        quantLinhas++;
    }

    /// FECHAMENTO ARQUIVOS
    fclose(arquivoGO);
    fclose(arquivoLeitura);

    printf("Pronto!");

    return 0;
}
