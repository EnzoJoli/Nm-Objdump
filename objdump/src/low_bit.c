/*
** EPITECH PROJECT, 2021
** hello
** File description:
** be
*/

#include "../include/my.h"
#include "../include/flags.h"

void print_f32(stufff_t utils, int nb)
{
    unsigned char *beans = (unsigned char *)utils.elf + utils.qlf[nb].sh_offset;
    unsigned int koko = utils.qlf[nb].sh_addr;

    for (int y = 0; y < utils.qlf[nb].sh_size; y += 16) {
        printf(" %04x ", koko);
        koko += 16;
        print_hexa32(beans, y, utils, nb);
        print_ascii32(beans, y, utils, nb);
    }
}

void print_32(stufff_t utils)
{
    Elf32_Shdr *sh_strtab = &utils.qlf[utils.elf->e_shstrndx];
    char * sh_strtab_p = utils.mapp + sh_strtab->sh_offset;

    for (int i = 0; i < utils.elf->e_shnum; i++) {
        if (strcmp((sh_strtab_p + utils.qlf[i].sh_name), ".shstrtab") != 0 &&
            strcmp((sh_strtab_p + utils.qlf[i].sh_name), ".symtab") != 0 &&
            strcmp((sh_strtab_p + utils.qlf[i].sh_name), ".strtab") != 0 &&
            strcmp((sh_strtab_p + utils.qlf[i].sh_name), ".bss") != 0 &&
            strcmp((sh_strtab_p + utils.qlf[i].sh_name), "") != 0){
            if (i > 0)
                printf("\n");
            printf("Contents of section %s:\n", sh_strtab_p
                    + utils.qlf[i].sh_name);
            print_f32(utils, i);
        }
    }
}

