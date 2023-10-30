/*
* File: 100-elf_header.c
* Auth: Denyefa Wari
*/

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

void check_elf(unsigned char *ident)
{
int i;
for (i = 0; i < 4; i++)
{
if (ident[i] != 127 && ident[i] != 'E' && ident[i] != 'L' && ident[i] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

void print_magic(unsigned char *ident)
{
int i;
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", ident[i]);
if (i == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

void print_class(unsigned char *ident)
{
printf("  Class:                             ");
switch (ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", ident[EI_CLASS]);
}
}

void print_data(unsigned char *ident)
{
printf("  Data:                              ");
switch (ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", ident[EI_DATA]);
}
}

void print_version(unsigned char *ident)
{
printf("  Version:                           %d", ident[EI_VERSION]);
switch (ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

void print_osabi(unsigned char *ident)
{
printf("  OS/ABI:                            ");
switch (ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", ident[EI_OSABI]);
}
}

void print_abi(unsigned char *ident)
{
printf("  ABI Version:                       %d\n", ident[EI_ABIVERSION]);
}

void print_type(unsigned int type, unsigned char *ident)
{
if (ident[EI_DATA] == ELFDATA2MSB)
type >>= 8;

printf("  Type:                              ");
switch (type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", type);
}
}

void print_entry(unsigned long int entry, unsigned char *ident)
{
printf("  Entry point address:               ");
if (ident[EI_DATA] == ELFDATA2MSB)
{
entry = ((entry << 8) & 0xFF00FF00) | ((entry >> 8) & 0xFF00FF);
entry = (entry << 16) | (entry >> 16);
}

if (ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)entry);
else
printf("%#lx\n", entry);
}

void close_elf(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(98);
}
}

int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *hdr;
int fd, n;

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

hdr = malloc(sizeof(Elf64_Ehdr));
if (hdr == NULL)
{
close_elf(fd);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

n = read(fd, hdr, sizeof(Elf64_Ehdr));
if (n == -1)
{
free(hdr);
close_elf(fd);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

check_elf(hdr->e_ident);
printf("ELF Header:\n");
print_magic(hdr->e_ident);
print_class(hdr->e_ident);
print_data(hdr->e_ident);
print_version(hdr->e_ident);
print_osabi(hdr->e_ident);
print_abi(hdr->e_ident);
print_type(hdr->e_type, hdr->e_ident);
print_entry(hdr->e_entry, hdr->e_ident);

free(hdr);
close_elf(fd);
return (0);
}
