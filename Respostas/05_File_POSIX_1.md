1. Considerando a biblioteca-padr�o da linguagem C, responda:

(a) Quais s�o as fun��es (e seus prot�tipos) para abrir e fechar arquivos?
Para abrir: FILE *fopen (char *nome_do_arquivo, *modo);
Para fechar: FILE *fclose (char *nome_do_arquivo, *modo);

(b) Quais s�o as fun��es (e seus prot�tipos) para escrever em arquivos?
Para escrever: size_t fwrite (const void *pointer, size_t size, size_t number_menb, FILE *stream);

(c) Quais s�o as fun��es (e seus prot�tipos) para ler arquivos?
Para ler: size_t fread (void *pointer, size_t size, size_t number_menb, FILE *stream);

(d) Quais s�o as fun��es (e seus prot�tipos) para reposicionar um ponteiro para arquivo?
int fseek(FILE *stream, long int offset, int whence);

(e) Quais bibliotecas devem ser inclu�das no c�digo para poder utilizar as fun��es acima?
� necess�rio adicionar as bibliotecas stdio.h e stdlib.h.

2. O que � a norma POSIX?
� uma norma da IEEE que define a interface programa��o de aplica��es (API), juntamente com shells (interpretador de linhas de comando) e interfaces utilit�rias.

3. Considerando a norma POSIX, responda:

(a) Quais s�o as fun��es (e seus prot�tipos) para abrir e fechar arquivos?
Para abrir: open, int open(const char* path, int oflag);
Para fechar: close, int close(int file);

(b) Quais s�o as fun��es (e seus prot�tipos) para escrever em arquivos?
Para escrever: write, ssize_t write(int file, const void *buf, size_t nbyte);

(c) Quais s�o as fun��es (e seus prot�tipos) para ler arquivos?
Para ler: read, ssize_t read(int file, void *buf, size_t nbyte);

(d) Quais s�o as fun��es (e seus prot�tipos) para reposicionar um ponteiro para arquivo?
Reposicionar: lseek, off_t lseek(int file, off_t offset, int whence);

(e) Quais bibliotecas devem ser inclu�das no c�digo para poder utilizar as fun��es acima?
� necess�rio adicionar as bibliotecas stdio.h, stdlib.h, sys/types.h, fcntl.h, unistd.h.