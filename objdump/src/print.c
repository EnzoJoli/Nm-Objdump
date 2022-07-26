/*
** EPITECH PROJECT, 2021
** print 64
** File description:
** print
*/

#include "../include/my.h"

void print_hexa64(unsigned char *beans, long unsigned int e, stuff_t utils
                    , int nb)
{
    for (long unsigned int y = e; y < e + 16;) {
        if (y  >= utils.qlf[nb].sh_size) {
            printf("  ");
            y++;
        } else {
            printf("%02x", beans[y++]);
        }
        if (y % 4 == 0)
            printf(" ");
    }
}

void print_ascii64(unsigned char *beans, long unsigned int e, stuff_t utils
                    , int nb)
{
    for (long unsigned int y = e; y < e + 16; y++) {
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

void print_f64(stuff_t utils, int nb)
{
    unsigned char *beans = (unsigned char *)utils.elf + utils.qlf[nb].sh_offset;
    unsigned int koko = utils.qlf[nb].sh_addr;

    for (int y = 0; y < utils.qlf[nb].sh_size; y += 16) {
        printf(" %04x ", koko);
        koko += 16;
        print_hexa64(beans, y, utils, nb);
        print_ascii64(beans, y, utils, nb);
    }
}

void print_64(stuff_t utils)
{
    Elf64_Shdr *sh_strtab = &utils.qlf[utils.elf->e_shstrndx];
    char * sh_strtab_p = utils.mapp + sh_strtab->sh_offset;

    for (int i = 0; i < utils.elf->e_shnum; i++) {
        if (strcmp((sh_strtab_p + utils.qlf[i].sh_name), ".shstrtab") != 0 &&
            strcmp((sh_strtab_p + utils.qlf[i].sh_name), ".symtab") != 0 &&
            strcmp((sh_strtab_p + utils.qlf[i].sh_name), ".strtab") != 0 &&
            strcmp((sh_strtab_p + utils.qlf[i].sh_name), ".bss") != 0 &&
            strcmp((sh_strtab_p + utils.qlf[i].sh_name), "") != 0){
            printf("Contents of section %s:\n", sh_strtab_p
                    + utils.qlf[i].sh_name);
            print_f64(utils, i);
        }
    }
}

void my_objdump64(Elf64_Ehdr *elf, char *str, Elf64_Shdr *qlf, void *buff)
{
    stuff_t utils = init_struct(elf, 64, str, qlf);
    utils.mapp = buff;

    flag_f(utils);
    print_64(utils);
}
