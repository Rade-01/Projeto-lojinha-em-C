#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int ano;
    float valor;
} livro;

void limparrole(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

livro cadastro(livro vetor, int i)
{
    printf("Digite o título do livro: ");
    fgets(vetor.titulo, 100, stdin);
    vetor.titulo[strcspn(vetor.titulo, "\n")] = '\0';

    printf("Digite o autor do livro: ");
    fgets(vetor.autor, 100, stdin);
    vetor.autor[strcspn(vetor.autor, "\n")] = '\0';

    printf("Digite o ano do livro: ");
    scanf("%d", &vetor.ano);
    limparrole();

    printf("Digite o valor do livro: ");
    scanf("%f", &vetor.valor);
    limparrole();

    return vetor;
}

void listar(livro vetor[], int total)
{
    for(int i = 0; i < total; i++)
    {
        printf("Título: %s\n", vetor[i].titulo);
    }
}

void buscar(char titulo_busca[], livro vetor[], int total)
{
    for(int i = 0; i < total; i++)
    {
        if (strcmp(vetor[i].titulo, titulo_busca) == 0)
        {
            printf("Livro encontrado:\n");
            printf("Título: %s\n", vetor[i].titulo);
            printf("Autor: %s\n", vetor[i].autor);
            printf("Ano: %d\n", vetor[i].ano);
            printf("Valor: %.2f\n", vetor[i].valor);
            return;
        }
    }
}

void editar(char titulo_edita[], livro vetor[], int total)
{
    for(int i = 0; i < total; i++)
    {
        if (strcmp(vetor[i].titulo, titulo_edita) == 0)
        {
            printf("Livro encontrado.\n");
            printf("Escolha uma opção: 1.Título 2.Autor 3.Ano 4.Valor 5.Sair\n");

            int selec_edita;
            scanf("%d", &selec_edita);
            limparrole();

            switch (selec_edita)
            {
                case 1:
                    printf("Digite o novo título do livro: ");
                    fgets(vetor[i].titulo, 100, stdin);
                    vetor[i].titulo[strcspn(vetor[i].titulo, "\n")] = '\0';
                    break;
                case 2:
                    printf("Digite o novo autor do livro: ");
                    fgets(vetor[i].autor, 100, stdin);
                    vetor[i].autor[strcspn(vetor[i].autor, "\n")] = '\0';
                    break;
                case 3:
                    printf("Digite o novo ano do livro: ");
                    scanf("%d", &vetor[i].ano);
                    limparrole();
                    break;
                case 4:
                    printf("Digite o novo valor do livro: ");
                    scanf("%f", &vetor[i].valor);
                    limparrole();
                    break;
                case 5:
                    printf("Saindo da edição...\n");
                    break;
                default:
                    printf("Opção inválida. Tente novamente.\n");
            }

            return;
        }
    }
}

int main ()
{
    int selec;
    int i = 0;


    int cap = 10;

    livro* vetor = malloc(sizeof(livro) * cap);
    if (vetor == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    
    do
    {
        printf("Escolha uma opção: 1.Cadastrar 2.Listar 3.Buscar 4.Editar 5.Sair\n");
        
        scanf("%d", &selec);
        limparrole(); 
        
        switch (selec)
        {
            case 1:
                if (i == cap)
                {
                    int nova_cap = cap + 10;

                    livro* aux = realloc(vetor, sizeof(livro) * nova_cap);
                    if (aux == NULL)
                    {
                        free(vetor);
                        return 1;
                    }

                    vetor = aux;
                    cap = nova_cap;
                }

                vetor[i] = cadastro(vetor[i], i);
                i++;

                break;
            case 2:
                listar(vetor, i);
                break;
            case 3:
                printf("Digite o título do livro a ser buscado: ");

                char titulo_busca[100];

                fgets(titulo_busca, 100, stdin);
                titulo_busca[strcspn(titulo_busca, "\n")] = '\0';

                buscar(titulo_busca, vetor, i);
                break;
            case 4:
                printf("Digite o título do livro a ser editado: ");

                char titulo_edita[100];

                fgets(titulo_edita, 100, stdin);
                titulo_edita[strcspn(titulo_edita, "\n")] = '\0';

                editar(titulo_edita, vetor, i);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (selec != 5);


    free(vetor);
    return 0;
}