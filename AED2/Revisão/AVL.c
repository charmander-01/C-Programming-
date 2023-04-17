/**
 * @file avl.c
 * @authors Laura Martins, Luis Miguel, Wevton. 
 * @brief Desenvolvimento do codigo da arvore AVL.
 */

// Bibliotecas:
#include <stdio.h>  
#include <stdlib.h> 

// Definicoes:
#define false 0
#define true 1

// Estrutura do no:
typedef struct Node
{
    int key;
    int data;
    struct Node * left;
    struct Node * right;
    int height;
} Node;

// Funcoes essenciais:
int max(int a, int b);
int Create_Tree_Root(Node ** root);
Node * createNode(int key, int data);
int height(Node * node);
int getBalance(Node * node);
Node * rightRotation(Node * y);
Node * leftRotation(Node * x);
Node * insertNode(Node * node, int key, int data);
Node *deleteNode(Node *root, int key);
Node * Search_Key(Node * node, int key);
Node *minValueNode(Node *node);
int Delete_Tree(Node ** root);

// Funcoes acessorias:
void menu();
void Print_Tree(Node * Tree_Root);

// Variaveis globais

// Funcao principal
int main()
{
    int loop_control = true;
    int option;
    int chave, dado;
    int del_tree;

    Node * root;
    Node * user_node = NULL;

    printf("\n");
    printf("AVL\n");

    while(loop_control == true)
    {
        menu();
        scanf("%d", &option);

        switch(option)
        {
            case 0:
            {
                loop_control = false;

                Delete_Tree(&root);

                printf("Programa encerrado.\n");

                break;  
            }
            case 1:
                Create_Tree_Root(&root);
                break;
            case 2:
            {
                printf("Entre com o valor da chave: ");
                scanf("%d", &chave);
                printf("Entre com o valor do dado: ");
                scanf("%d", &dado);

                root = insertNode(root, chave, dado);

                break;
            }
            case 3:
            {
                printf("Entre com o valor da chave: ");
                scanf("%d", &chave);

                root = deleteNode(root, chave); 

                break;
            }
            case 4:
            {
                printf("Entre com o valor da chave: ");
                scanf("%d", &chave);

                user_node = Search_Key(root, chave);

                if(user_node != NULL)
                {
                    printf("O dado da chave x e: %d\n", user_node->data);                
                }
                
                break;
            }
            case 5:
            {
                Print_Tree(root);
                break;
            }
            case 6:
            {
                del_tree = Delete_Tree(&root);
                if(del_tree == false)
                {
                    printf("A arvore ja foi deletada.\n");
                }
                else
                {
                    printf("A arvore foi deletada com sucesso!\n");
                }

                break;
            }
            default:
            {
                printf("Insira uma opcao valida (entre 1 a 6).\n");
                break;
            }
        }

    }

    return 0;
}


// Implementacao das funcoes:

void menu()
{
    printf("\n");
    printf("Operacoes disponiveis:\n");
    printf("[ 1]: Criar a raiz da arvore\n");
    printf("[ 2]: inserir um elemento\n");
    printf("[ 3]: remover um elemento\n");
    printf("[ 4]: buscar o dado da chave x\n");
    printf("[ 5]: imprimir a arvore\n");
    printf("[ 6]: deletar a arvore anteriormente criada\n");
    printf("[ 0]: encerrar o programa\n");
    printf("\n");
    printf("Digite o numero de acordo com a operacao escolhida:\n");
}

void Print_Tree(Node * node)
{
    if(node != NULL)
    {
        printf("No: (%d)\n", node->key);
        Print_Tree(node->left);
        Print_Tree(node->right);
    }
}

int max(int a, int b)
{
    if(a>b) return a;
    else return b;
}

int Create_Tree_Root(Node ** root)
{
    if((*root) != NULL)
    {
        (*root) = NULL;
        printf("Raiz da arvore criada com sucesso!");
    }
    else
    {
        printf("Raiz da arvore ja criada!");
    }
}

int Delete_Tree(Node ** root)
{
    if((*root) == NULL)
    {
        return false;
    }
    else
    {
        while((*root) != NULL)
        {
            *root = deleteNode(*root, (*root)->key);
        }
        return true;
    }
}

Node * createNode(int key, int data)
{
    Node * new_node = NULL;
    new_node = (Node *) malloc(sizeof(struct Node));

    if(new_node == NULL){
        return NULL;
    }
    new_node->key = key;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    
    return new_node;
}

int height(Node * node)
{
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        return node->height;
    }
}

int getBalance(Node * node)
{
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        return (height(node->right) - height(node->left));
    }
}

Node * rightRotation(Node * y)
{
    Node * x = y->left;
    Node * T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node * leftRotation(Node * x)
{
    Node * y = x->right;
    Node * T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return y;
}

Node * insertNode(Node * node, int key, int data)
{
    if(node != NULL)
    {
        if(key<node->key)
        {
            node->left = insertNode(node->left, key, data);
        }
        else if(key>node->key)
        {
            node->right = insertNode(node->right, key, data);
        }
        else
        {
            printf("Chave invalida de insercao.\n");
            return node;
        }
    }
    else
    {
        return (createNode(key, data));
    }

    // return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int bf = getBalance(node);

    // Rotacao dupla a esquerda
        if(bf>1 && key <  node->right->key)
        {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }

    // Rotacao a esquerda
        if(bf>1 && key > node->right->key)
        {
            return leftRotation(node);
        }

    // Rotacao dupla a direita
        if(bf<-1 && key > node->left->key)
        {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }

    //  Rotacao a direita
        if(bf<-1 && key < node->left->key)
        {
            return rightRotation(node);
        }

    return node;                 
}

Node * Search_Key(Node * node, int key)
{
    if(key < node->key && node->left!=NULL)
    {
        return Search_Key(node->left, key);
    }
    else if(key > node->key && node->right!=NULL)
    {
        return Search_Key(node->right, key);
    }
    else if(key == node->key)
    {
        printf("No encontrado!\n");
        return node;
    }
    else
    {
        printf("No nao encontrado.\n");
        return NULL;
    }
}

Node *deleteNode(Node *root, int key) {
  // Encontrar o no e fazer a delecao
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else *root = *temp;
        
      free(temp);
    } else {
      Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Atualizar o fator de balanceamento de cada no e
  // balancear a arvore
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);

  if (balance > 1 && getBalance(root->right) < 0) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }

  if (balance > 1 && getBalance(root->right) >= 0)
    return leftRotation(root);

  if (balance <-1 && getBalance(root->left) > 0) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }

  if (balance <-1 && getBalance(root->left) <= 0)
    return rightRotation(root);

  return root;
}

Node *minValueNode(Node *node) {
  Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}
