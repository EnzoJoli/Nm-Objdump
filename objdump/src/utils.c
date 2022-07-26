/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "../include/my.h"

int open_file(char *str)
{
    int fd;

    fd = open(str, O_RDONLY);
    return fd;
}

stuff_t init_struct(Elf64_Ehdr *elf, int vers, char *str, Elf64_Shdr *qlf)
{
    stuff_t beans;

    beans.elf = elf;
    beans.version = vers;
    beans.filepath = str;
    beans.qlf = qlf;
    return beans;
}

stufff_t init_struct32(Elf32_Ehdr *elf, int vers, char *str, Elf32_Shdr *qlf)
{
    stufff_t beans;

    beans.elf = elf;
    beans.version = vers;
    beans.filepath = str;
    beans.qlf = qlf;
    return beans;
}

void flag_f(stuff_t utils)
{
    printf("\n%s:     file format elf64-x86-64\n", utils.filepath);
    printf("architecture: i386:x86-64, ");
    print_flags(utils);
    printf("start address 0x%016lx\n\n", utils.elf->e_entry);
}

void flag_f32(stufff_t utils)
{
    printf("\n%s:     file format elf32-i386\n", utils.filepath);
    printf("architecture: i386, ");
    print_flags32(utils);
    printf("start address 0x%08x\n\n", utils.elf->e_entry);
}
