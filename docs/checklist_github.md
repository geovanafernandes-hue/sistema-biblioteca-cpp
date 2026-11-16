# Checklist de entrega | GitHub + Classroom

## Pelo site GitHub (opção mais fácil para quem está começando)

1. Abra o repositório **público** já criado.
2. Clique em **Add file > Upload files**; se estiver vazio, use a opção inicial de upload.
3. Arraste o **conteúdo extraído** da pasta do projeto, incluindo `src`, `data`, `docs`, `README.md`, `.gitignore` e o PowerPoint.
4. Verifique que o upload preservou a estrutura.
5. Escreva `Projeto de biblioteca em C++` e confirme (Commit changes / Propose changes, conforme a tela).
6. Confira o arquivo `src/main.cpp` pelo navegador.
7. Copie o link do repositório e envie **individualmente** ao Classroom até **22/11/2026**.
8. Apresente o programa funcionando em **23/11/2026**.

Veja: https://docs.github.com/en/repositories/working-with-files/managing-files/adding-a-file-to-a-repository

## Opcional: Git pelo terminal (somente se souber usar Git)

Na pasta principal do projeto, caso o repositorio remoto esteja vazio:

```bash
git init
git add .
git commit -m "Projeto de biblioteca em C++"
git branch -M main
git remote add origin https://github.com/SEU_USUARIO/SEU_REPOSITORIO.git
git push -u origin main
```

Nao use os comandos acima sem verificar se o repositorio remoto ja tem commits/README, pois pode exigir integracao de historicos.
