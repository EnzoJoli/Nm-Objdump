/*
** EPITECH PROJECT, 2021
** be
** File description:
** er
*/

#include "../include/flags.h"
#include "../include/my.h"

void my_objdump32(Elf32_Ehdr *elf, char *str, Elf32_Shdr *qlf, void *buff)
{
    stufff_t utils = init_struct32(elf, 32, str, qlf);
    utils.mapp = buff;

    flag_f32(utils);
    print_32(utils);
}

void hub_64(Elf64_Ehdr *elf, char *str, Elf64_Shdr *qlf, void *buff)
{
    my_objdump64(elf, str, qlf, buff);
}

void hub_32(char *str, void *buff)
{
    Elf32_Ehdr *elf = buff;
    Elf32_Shdr *qlf = (buff + elf->e_shoff);

    my_objdump32(elf, str, qlf, buff);
}

int main_function(int fd, char *str)
{
    void *buf;
    struct stat s;
    Elf64_Shdr *qlf;
    Elf64_Ehdr *elf;

    fstat(fd, &s);
    buf = mmap(NULL , s.st_size , PROT_READ , MAP_PRIVATE , fd, 0);
    if (buf !=  -1) {
        elf = buf;
        qlf = (buf + elf->e_shoff);
    } else{
        perror("mmap");
    }
    if (elf->e_ident[EI_CLASS] == 2)
        hub_64(elf, str, qlf, buf);
    else
        hub_32(str, buf);
    close(fd);
    return 0;
}

int main(int ac, char **av)
{
    int fd = -1;

    if (ac < 2) {
        fd = open_file("a.out");
        if (fd == -1)
            return 84;
        main_function(fd, "a.out");
    } else {
        for (int i = 1; i < ac; i++) {
            fd = open_file(av[i]);
            if (fd == -1)
                return 84;
            main_function(fd, av[i]);
        }
    }
    return 0;
}
