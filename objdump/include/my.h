/*
** EPITECH PROJECT, 2021
** un .h
** File description:
** rien a voir ici circuler
*/

#ifndef OBJDUMP_H
#define OBJDUMP_H

#include <fcntl.h>
#include <stdio.h>
#include <elf.h>
#include "flags.h"
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/mman.h>
#include <sys/stat.h>

typedef struct stuff
{
    int version;
    Elf64_Ehdr *elf;
    Elf64_Shdr *qlf;
    char *filepath;
    void *mapp;
} stuff_t;

typedef struct stufff
{
    int version;
    Elf32_Ehdr *elf;
    Elf32_Shdr *qlf;
    char *filepath;
    void *mapp;
} stufff_t;

void print_f32(stufff_t utils, int nb);
void print_32(stufff_t utils);
void print_ascii32(unsigned char *beans, long unsigned int e, stufff_t utils
                    , int nb);
void print_hexa32(unsigned char *beans, long unsigned int e, stufff_t utils
                    , int nb);
int print_flags(stuff_t utils);
int print_flags32(stufff_t utils);
int open_file(char *str);
void my_objdump64(Elf64_Ehdr *elf, char *str, Elf64_Shdr *qlf, void *buff);
stuff_t init_struct(Elf64_Ehdr *elf, int vers, char *str, Elf64_Shdr *qlf);
void flag_f(stuff_t utils);
void flag_f32(stufff_t utils);
stufff_t init_struct32(Elf32_Ehdr *elf, int vers, char *str, Elf32_Shdr *qlf);
#endif
