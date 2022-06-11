PHONY: all

all: clean gerarTabela gerarPDF
	make clean

gerarTabela: scripts/tabelaIntensidadeSonara.c
	gcc ./scripts/tabelaIntensidadeSonara.c -o ./scripts/gerarTabela -std=c11 -W -Wall -pedantic
	./scripts/gerarTabela

limparGeracaoDeTabela: 
	rm -f scripts/gerarTabela
	rm -f tabela.tex

gerarPDF: gerarTabela
	tectonic main.tex
	mv main.pdf Artigo.pdf

PHONY: clean

clean: limparGeracaoDeTabela