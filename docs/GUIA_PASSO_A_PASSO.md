# GUIA SIMPLES: projeto de biblioteca

## 1. O que voce tem em maos
O **main.cpp** e o codigo que o computador executa.
A pasta **src** guarda o codigo. A pasta **data** guarda os livros.
O **README.md** explica o projeto para quem abrir o GitHub.
A apresentacao PowerPoint e para demonstrar o que foi feito.

## 2. O erro mostrado
O codigo anterior tentava abrir `data/livros.dat` a partir de `src`, mas a pasta `data` fica ao lado de `src`, e nao dentro dela. A tentativa de abrir falhava. A versao corrigida identifica a pasta correta automaticamente.

## 3. Antes de abrir o Dev-C++
1. Feche o programa que esta dando erro.
2. Extraia o ZIP `Biblioteca_Projeto_Corrigido.zip` numa pasta normal do Windows.
3. Abra a pasta extraida, confira `src` e `data` no mesmo nivel.
4. Em `src`, abra `main.cpp` pelo Dev-C++ (Arquivo > Abrir).
5. Clique em **Executar > Compilar e Executar** (F11).
6. O programa deve exibir o menu, sem a mensagem de erro.

**Se aparecer warning de C++11:** no Dev-C++, use Ferramentas > Opcoes do Compilador > Configuracoes > Geracao de codigo > Padrao da linguagem C++ e selecione C++11, se essa opcao estiver disponivel. Esse aviso nao e o mesmo problema de arquivo.

## 4. Teste sem pular etapas
- Opcao **1**: titulo `O Cortico`, autor `Aluisio Azevedo`, ano `1890` (anote o codigo gerado).
- Opcao **1**: `Dom Casmurro`, `Machado de Assis`, `1899`.
- Opcao **1**: `O Pequeno Principe`, `Antoine de Saint-Exupery`, `1943`.
- Opcao **2**: digite o codigo do primeiro livro. Veja os detalhes.
- Opcao **6**: a contagem deve ser 3, se a base estava vazia.
- Opcao **4**: exporte e abra `data/livros.txt` para ver o relatorio.
- Opcao **5**: exclua o segundo livro, confirme com 1.
- Opcao **6**: a contagem passa a 2, se antes tinha 3.
- Opcao **2**: consulte o segundo livro. Ele nao aparece como ativo.
- Opcao **4** novamente: o TXT mostrara tambem o livro excluido, identificado pelo status.

**Se sua base ja tiver livros**, os IDs e quantidades podem ser diferentes. Para ensaiar do zero, feche o programa, faca copia de seguranca do arquivo `data/livros.dat` e depois retire apenas o `livros.dat` da pasta. O sistema cria outro arquivo vazio quando reiniciar.

## 5. Entenda o programa em linguagem simples
- `struct Livro`: uma ficha com as informacoes de um livro.
- `id`: o numero que identifica o livro.
- `titulo`, `autor`: textos escritos no cadastro.
- `ano`: numero do ano de publicacao.
- `status`: 1 quer dizer ativo; 0 quer dizer excluido.
- `main()`: ponto de entrada, que exibe o menu e escolhe a acao.
- `switch`: decide qual funcao executar quando se digita 1, 2, 3 etc.
- `cadastrarLivro()`: pede dados e grava o livro.
- `consultarLivro()`: procura um codigo e mostra seus dados.
- `contarRegistrosAtivos()`: percorre todos e conta so os ativos.
- `exportarTxt()`: cria um relatorio legivel.
- `excluirLivro()`: muda apenas o status para 0.
- `fopen()`: abre arquivo; `fclose()`: fecha.
- `fwrite()`: grava um bloco binario; `fread()`: le um bloco.
- `fseek()`: move a posicao de leitura/escrita dentro do arquivo.

## 6. Enviar ao GitHub pelo navegador (sem usar terminal)
1. Entre no repositorio publico que voce ja criou no GitHub.
2. Clique em **Add file > Upload files**. Se o repositorio estiver vazio, use a opcao inicial de upload.
3. Abra a pasta extraida do ZIP e arraste os itens **de dentro dela** para a area de upload (nao o arquivo ZIP unico). O GitHub aceita arrastar arquivos e pastas.
4. Confira na tela se a estrutura contem `src/main.cpp`, `README.md`, `.gitignore`, `docs/...` e `data/.gitkeep`. Caso a pasta `data` nao apareca, ela esta vazia, entao garanta que `.gitkeep` seja enviado.
5. Escreva a mensagem `Projeto de biblioteca em C++` e confirme o commit. Dependendo da tela, o botao pode ser **Commit changes** ou **Propose changes**.
6. Abra novamente o repositorio, confira os arquivos e copie o endereco da barra do navegador.
7. Cada integrante envia esse mesmo link individualmente no Google Classroom ate **22/11/2026**.

**Nao envie so o ZIP para o repositorio**: o avaliador deve enxergar o codigo-fonte diretamente.

## 7. No dia 23/11/2026
1. Leve o computador e os slides abertos.
2. Rode o programa antes de iniciar a apresentacao.
3. Explique brevemente `struct`, `main`, armazenamento binario e `status`.
4. Faca a demonstracao das 5 funcoes obrigatorias.
5. Mostre o arquivo TXT gerado.
6. Abra o GitHub se o professor pedir.

## 8. Se o erro continuar
- Garanta que esta abrindo **o main.cpp da pasta corrigida**, nao o da copia antiga.
- Confira se a pasta `data` realmente existe no projeto.
- Se houver bloqueio de permissao, mova a pasta para `Documentos` e tente novamente.
- Nao exclua `data` nem mova `main.cpp` para fora de `src`.
- Se o programa exibir erro de compilacao, envie a mensagem exata do painel de erros.
