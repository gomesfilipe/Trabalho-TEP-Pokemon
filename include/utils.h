#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Verifica se um caractere é letra maiúscula.
 * @param c Caractere a ser analisado.
 * @return 1, caso seja maiúscula e 0, caso contrário.
 **/
int ehMaiuscula(char c);

/**
 * @brief Verifica se um caractere é letra minúscula.
 * @param c Caractere a ser analisado.
 * @return 1, caso seja minúscula e 0, caso contrário.
 **/
int ehMinuscula(char c);

/**
 * @brief Verifica se uma string é alfabética e contem underlines ou não.
 * @param str String a ser analisada.
 * @return 1, caso a string seja válida e 0, caso contrário.
 **/
int ehStringAlfabetica(char *str);

#endif
