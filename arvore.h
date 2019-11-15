typedef int Tipo;

typedef struct no NoArvore, *PontNo;

int max(int a, int b);

PontNo busca(Tipo chave, PontNo raiz);

PontNo criaNo(Tipo chave);

bool InserirNo(Tipo chave, PontNo no);

PontNo buscaRaiz(Tipo chave, PontNo no);

void ArvorePreOrdem(PontNo no);

void  ArvoreEmOrdem(PontNo no);

void ArvorePosOrdem(PontNo no);


