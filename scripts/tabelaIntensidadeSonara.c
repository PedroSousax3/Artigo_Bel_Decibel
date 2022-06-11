#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char nome[200];
    char descricao[200];
    char peso[200];
} Intensidade;

Intensidade popular(char peso[200], char nome[200], char descricao[200]) {
    Intensidade intensidade;
    strcpy(intensidade.nome, nome);
    strcpy(intensidade.descricao, descricao);
    strcpy(intensidade.peso, peso);
    return intensidade;
}

int main(void) {
    Intensidade intensidades[4] = {
        popular(
            "Até 50", 
            "Nível confortável", 
            "Nenhum"
        ),
        popular(
            "Entre 50 e 65", 
            "Estado de alerta. \\\\Inibe o relaxamento.", 
            "Diminuição do poder\\\\ de concentração e \\\\rendimento."
        ),
        popular(
            "Entre 65 e 70", 
            "O organismo arma \\\\defesas para adequar o\\\\ corpo ao ambiente.", 
            "Aumento no nível de\\\\ cortisona, diminuição da \\\\resistência imunológica,\\\\ liberação de endorfinas,\\\\ aumento de colesterol."
        ),
        popular(
            "Acima de 70 dB", 
            "O organismo fica \\\\sujeito à grande estresse,\\\\ existe a possibilidade\\\\ de surgirem desequilíbrios\\\\ emocionais.", 
            "Riscos de enfarte,\\\\ infecções e lesões\\\\ no sistema auditivo."
        )
    };

    const char *arquivo = "tabela.tex";
    FILE * fp = fopen(arquivo,"wt");
    if (fp == NULL)
        return 0;

    fprintf(fp,"\\begin{table}[ht]\n");
    fprintf(fp,"\\begin{tabular}{|c|c|c|}\n");

    fprintf(fp,"\\hline\n");

    fprintf(fp, "Intensidade sonora (dB) & Reação do corpo & Efeitos negativos \\\\\n \\hline \n");
    for (int i = 0; i < 4; i++)
        fprintf(fp, "\\makecell{%s} & \\makecell{%s} & \\makecell{%s} \\\\\n \\hline \n", intensidades[i].peso, intensidades[i].nome, intensidades[i].descricao);

    fprintf(fp,"\\end{tabular}\n");
    fprintf(fp,"\\end{table}\n");

    fclose(fp);

    return 0;
}