# Roteiro da apresentação | 5 a 8 minutos

Use o PowerPoint **Apresentacao_Biblioteca_Melhorada.pptx**.

- **Slides 1 a 3 (1 min):** tema, problema e cinco requisitos.
- **Slides 4 a 6 (1,5 min):** pastas, struct e menu.
- **Slides 7 a 10 (2 min):** cadastro, consulta/contagem, exclusão lógica e TXT.
- **Slide 11 (2 min):** demonstração prática do programa.
- **Slides 12 e 13 (1 min):** GitHub e conclusão.

## Sequência prática

Com a base vazia: cadastre três livros, consulte o primeiro, conte (3), exporte TXT, exclua o segundo, conte (2), consulte o segundo (não ativo). Exporte novamente depois da exclusão e mostre `data/livros.txt`, que inclui o registro excluído marcado com seu status. Se já houver dados, os números serão diferentes.

## Perguntas prováveis

**O que é struct?** Agrupa as informações de um livro em uma estrutura.
**Por que o binário?** Porque é a forma de armazenar registros persistentes exigida na atividade.
**Como grava?** `fwrite()` escreve o conteúdo de uma struct no arquivo.
**Como lê?** `fread()` recupera um registro por vez.
**O que faz fseek?** Reposiciona a leitura/escrita para atualizar um registro existente.
**O que é exclusão lógica?** Status vai de 1 para 0; o livro continua fisicamente no arquivo.
**Como gera o ID?** Busca o maior ID existente e soma 1.
**Onde ficam os dados?** Na pasta `data` do projeto.
**Os dados somem ao fechar?** Não. O `livros.dat` continua salvo.
**Por que o TXT?** Para produzir um relatório de leitura simples.

## Se for em grupo (até 4 pessoas)
- Pessoa 1: slides 1–3.
- Pessoa 2: slides 4–7.
- Pessoa 3: slides 8–10.
- Pessoa 4: slides 11–13.

Cada integrante deve conseguir explicar sua parte e responder perguntas básicas.
