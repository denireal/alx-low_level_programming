/*
* File: 100-elf_header.c
* Author: Denny Wari
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void verify_elf_file(unsigned char *e_ident);
void printElfHeaderDetails(Elf64_Ehdr *header);

/**
* verify_elf_file - Verifies whether a given file is a valid ELF file.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: If the file is not a valid ELF file, it exits with code 98.
*/
void verify_elf_file(unsigned char *e_ident)
{
int index = 0;

for (; index < 4; index++)
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
* print_elf_header_details - Displays details from the beginning of an ELF file's header.
* @header: A pointer to the ELF header structure.
*
* Description: Exits with code 98 if the function encounters an error.
*/
void print_elf_header_details(Elf64_Ehdr *header)
{
int index = 0;

printf("ELF Header:\n");
printf("  Magic:   ");
for (; index < EI_NIDENT; index++)
{
printf("%02x", header->e_ident[index]);
if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}

printf("  Class:                             ");
switch (header->e_ident[EI_CLASS])
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
printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
}

printf("  Data:                              ");
switch (header->e_ident[EI_DATA])
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
printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
}

printf("  Version:                           %d", header->e_ident[EI_VERSION]);
switch (header->e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}

printf("  OS/ABI:                            ");
switch (header->e_ident[EI_OSABI])
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
printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
}
}

/**
* main - Presents details from the beginning of an ELF file's header.
* @argc: The count of arguments provided to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 if successful.
*
* Description: Exits with code 98 if the file is not an ELF file or
* if the function encounters an error.
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int file_descriptor, read_result;

file_descriptor = open(argv[1], O_RDONLY);
if (file_descriptor == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close(file_descriptor);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

read_result = read(file_descriptor, header, sizeof(Elf64_Ehdr));
if (read_result == -1)
{
free(header);
close(file_descriptor);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

verify_elf_file(header->e_ident);
print_elf_header_details(header);

free(header);
close(file_descriptor);
return (0);
}
