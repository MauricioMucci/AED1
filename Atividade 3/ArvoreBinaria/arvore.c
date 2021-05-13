#include "bib.h"

int main(int argc, char const *argv[])
{
    Pointer* root;
    root = (Pointer*)malloc(sizeof(Pointer));
    if (!root)
    {        
        printf("ERROR: IMPOSSIVEL ALOCAR MEMORIA");
        exit(1);
    }
    
    reset(root);

    Variaveis* var;
    var = (Variaveis*)malloc(sizeof(Variaveis));
    if (!var)
    {
        printf("ERROR: IMPOSSIVEL ALOCAR MEMORIA");
        exit(1);
    }

    while (menu(root, var) == 1);

    free(var);
       
    return 0;
}