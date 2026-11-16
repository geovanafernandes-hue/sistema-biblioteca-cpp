# Sistema de Gerenciamento de Biblioteca em C++

Projeto da atividade avaliativa de Programacao Estruturada em C / C++.

## O que o sistema faz

- **1. Cadastrar livro:** le titulo, autor, ano; gera ID e grava registro no arquivo binario.
- **2. Consultar por codigo:** busca um livro ativo pelo ID.
- **3. Listar livros ativos:** extra para facilitar testes.
- **4. Exportar TXT:** gera relatorio de todos os registros, com status ativo ou excluido, em `data/livros.txt`.
- **5. Excluir logicamente:** muda `status` de 1 para 0, sem apagar fisicamente o registro.
- **6. Contabilizar ativos:** conta livros com `status == 1`.

## Estrutura da pasta

```text
projeto-biblioteca-corrigido/
  src/main.cpp                  <- CODIGO-FONTE
  data/.gitkeep                 <- mantenha esta pasta
  docs/                         <- roteiros, instrucoes e falas
  Apresentacao_Biblioteca_Melhorada.pptx
  Guia_Iniciante_Biblioteca.pdf
  README.md
  build.bat
  build.sh
  Makefile
  .gitignore
```

**Importante:** o arquivo `livros.dat` nao vem pronto; ele e criado pelo programa quando executado. Ao exportar, o arquivo `livros.txt` e criado. Eles sao arquivos de dados, e normalmente nao devem ser enviados ao GitHub.

## Rodar no Dev-C++ (Windows)

1. Extraia o ZIP completo. Nao abra um `main.cpp` isolado fora das pastas.
2. Confira se `src` e `data` estao lado a lado.
3. No Dev-C++, use **Arquivo > Abrir**, selecione `src/main.cpp`.
4. Use **Executar > Compilar e Executar** (normalmente F11).
5. No menu preto, digite **1** para cadastrar.
6. Para testar, cadastre 3 livros e use as outras opcoes.

O programa tenta localizar `data` partindo da pasta raiz, de `src` e, se necessario, do caminho do arquivo-fonte. Isso corrige o erro comum de abrir `src/main.cpp` diretamente no Dev-C++.

## Compilar no terminal (opcional)

Na pasta principal do projeto:

```bash
g++ -std=c++11 -Wall -Wextra -o biblioteca.exe src/main.cpp
```

No Windows, execute `biblioteca.exe`. Alternativamente, clique duas vezes em `build.bat` se `g++` estiver disponivel no PATH.

## Como funciona o armazenamento

Cada livro e uma `struct` com `id`, `titulo`, `autor`, `ano`, `status`. `fwrite` grava um registro em `livros.dat`; `fread` le; `fseek` volta a uma posicao para alterar `status`. Se `status = 1`, o livro esta ativo; se `status = 0`, foi excluido logicamente.

## GitHub

Envie o **conteudo** desta pasta para seu repositorio publico. O site GitHub permite: **Add file > Upload files**, arrastar arquivos/pastas, inserir mensagem do commit e confirmar. Mantenha `src/main.cpp` e `README.md` no repositorio.

- Entrega do link individualmente no Google Classroom: **22/11/2026**.
- Apresentacao pratica: **23/11/2026**.

Para os passos completos, veja `docs/GUIA_PASSO_A_PASSO.md` e o PDF na raiz.
