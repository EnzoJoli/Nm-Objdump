/*
** EPITECH PROJECT, 2021
** flag
** File description:
** fag
*/

#include "../include/my.h"
#include "../include/flags.h"

int print_flags(stuff_t utils)
{
    if  (utils.elf->e_type == ET_REL) {
        printf("flags 0x%08x:\nHAS_RELOC, HAS_SYMS\n", HAS_RELOC + HAS_SYMS);
    }
    if  (utils.elf->e_type == ET_EXEC) {
        printf("flags 0x%08x:\nEXEC_P, HAS_SYMS, D_PAGED\n"
                , EXEC_P + HAS_SYMS + D_PAGED);
    }
    return 0;
}

int print_flags32(stufff_t utils)
{
    if  (utils.elf->e_type == ET_REL) {
        printf("flags 0x%08x:\nHAS_RELOC, HAS_SYMS\n", HAS_RELOC + HAS_SYMS);
    }
    if  (utils.elf->e_type == ET_EXEC) {
        printf("flags 0x%08x:\nEXEC_P, HAS_SYMS, D_PAGED\n"
                , EXEC_P + HAS_SYMS + D_PAGED);
    }
    return 0;
}

void print_hexa32(unsigned char *beans, long unsigned int e, stufff_t utils
                    , int nb)
{
    for (long unsigned int y = e; y <= e + 16;) {
        if (y  >= utils.qlf[nb].sh_size) {
            printf("  ");
            y++;
        } else {
            printf("%02x", beans[y++]);
        }
        if (y % 4 == 0)
            printf(" ");
    }
    printf(" ");
}

void print_ascii32(unsigned char *beans, long unsigned int e, stufff_t utils
                    , int nb)
{
    for (long unsigned int y = e; y <= e + 16; y++) {
        if (y  >= utils.qlf[nb].sh_size) {
            printf("  ");
            y++;
        } else {
            if (isprint(beans[y]) != 0)
                printf("%c", beans[y]);
            else printf(".");
        }
    }
    printf("\n");
}

