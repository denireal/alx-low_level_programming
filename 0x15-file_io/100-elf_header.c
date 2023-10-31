/*
* File: 100-elf_header.c
* Author: Denny Wari
*/

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void check_elf(unsigned char *e_ident);
void print_magic_and_class(unsigned char *e_ident);
void print_data_and_version(unsigned char *e_ident);
void print_osabi_and_abi(unsigned char *e_ident);
void print_type_and_entry(Elf64_Ehdr *header);

/**
* check_elf - Checks whether a file is an ELF file.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: If the file is not an ELF file, it exits with code 98.
*/
void check_elf(unsigned char *e_ident)
{
int index;

for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
e_ident[index] != 'E' &&
e_ident[index] != 'L' &&
e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* print_magic_and_class - Prints the magic numbers and class of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers and class.
*/
void print_magic_and_class(unsigned char *e_ident)
{
int index;

printf("  Magic:   ");
for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", e_ident[index]);

if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}

printf("  Class:                             ");
switch (e_ident[EI_CLASS])
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
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
* print_data_and_version - Prints the data and version of an ELF header.
* @e_ident: A pointer to an array containing the ELF data and version.
*/
void print_data_and_version(unsigned char *e_ident)
{
printf("  Data:                              ");
switch (e_ident[EI_DATA])
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
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

printf("  Version:                           %d", e_ident[EI_VERSION]);
switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
* print_osabi_and_abi - Prints the OS/ABI and ABI version of an ELF header.
* @e_ident: A pointer to an array containing the ELF OS/ABI and ABI version.
*/
void print_osabi_and_abi(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");
switch (e_ident[EI_OSABI])
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
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}

printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
* print_type_and_entry - Prints the type and entry point of an ELF header.
* @header: A pointer to the ELF header structure.
*/
void print_type_and_entry(Elf64_Ehdr *header)
{
if (header->e_ident[EI_DATA] == ELFDATA2MSB)
header->e_type >>= 8;

printf("  Type:                              ");
switch (header->e_type)
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
printf("<unknown: %x>\n", header->e_type);
}

printf("  Entry point address:               ");
if (header->e_ident[EI_DATA] == ELFDATA2MSB)
{
header->e_entry = ((header->e_entry << 8) & 0xFF00FF00) |
 ((header->e_entry >> 8) & 0xFF00FF);

header->e_entry = (header->e_entry << 16) | (header->e_entry >> 16);
}

if (header->e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)header->e_entry);
else
printf("%#lx\n", header->e_entry);
}

int main(int argc, char *argv[])
{
Elf64_Ehdr *header;
int fd, read_result;

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s <file>\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close(fd);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

read_result = read(fd, header, sizeof(Elf64_Ehdr));
if (read_result == -1)
{
free(header);
close(fd);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic_and_class(header->e_ident);
print_data_and_version(header->e_ident);
print_osabi_and_abi(header->e_ident);
print_type_and_entry(header);

free(header);
close(fd);
return (0);
}
