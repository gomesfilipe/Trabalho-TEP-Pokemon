#include "../include/utils.h"

int ehMaiuscula(char c){
    if(c >= 'A' && c <= 'Z'){
        return 1;
    }

    return 0;
}

int ehMinuscula(char c){
    if(c >= 'a' && c <= 'z'){
        return 1;
    }

    return 0;
}

int ehStringAlfabetica(char *str){
    for(int i = 0; i < strlen(str); i++){
        if(!ehMaiuscula(str[i]) && !ehMinuscula(str[i]) && str[i] != '_'){
            return 0;
        }
    }

    return 1;
}

