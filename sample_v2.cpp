#include<stdio.h>
#include<string.h>

void LeftmostDerivation(char str[], int size){
    char virtual_str[size];
    strcpy(virtual_str, str);
    printf("LMD :\n");
    int counter = 0;
    Jump:
    printf("Step %d-> %s\n",++counter, virtual_str);
    for(int i=0; i<size ; i++){
        if(virtual_str[i] == 'A'){
            virtual_str[i]='b';
            goto Jump;
        }else if(virtual_str[i]== 'B'){
            virtual_str[i] = 'c';
            goto Jump;
        }

    }
}
void RightmostDerivation(char str[], int size){
    printf("RMD :\n");
    int counter = 0;
    Jump:
    printf("Step %d-> %s\n",++counter, str);
    for(int i=size-1; i >=0; i--){
        if(str[i] == 'A'){
            str[i]='b';
            goto Jump;
        }else if(str[i]== 'B'){
            str[i] = 'c';
            goto Jump;
        }
    }
}

int main(){
    char str[] = {};

    printf("Enter The Context Free Grammer S -> ");
    scanf("%s",&str);
    LeftmostDerivation(str, strlen(str));
    RightmostDerivation(str, strlen(str));
    free(str);
    return 0;
}
