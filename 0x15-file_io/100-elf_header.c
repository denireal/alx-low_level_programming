#include "main.h"

/**
* is_elf_file - Checks if a file is an ELF file.
* @ident: Pointer to an array containing the ELF magic numbers.
*
* Return: 1 if it's an ELF file, 0 otherwise.
*/
int is_elf_file(unsigned char *ident)
{
int i;

for (i = 0; i < 4; i++)
{
if (ident[i] != 127 &&
ident[i] != 'E' &&
ident[i] != 'L' &&
ident[i] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
return (1);
}

/**
* print_magic_numbers - Prints the magic numbers of an ELF header.
* @ident: Pointer to an array containing the ELF magic numbers.
*/
void print_magic_numbers(unsigned char *ident)
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

/**
* print_header_field - Prints an ELF header field.
* @name: Field name.
* @value: Field value.
*/
void print_header_field(const char *name, const char *value)
{
printf("  %-34s%s\n", name, value);
}

/**
* close_file - Closes a file descriptor.
* @fd: File descriptor to close.
*/
void close_file(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(98);
}
}

/**
* main - Displays the information contained in the ELF header
*        at the start of an ELF file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success, 98 on failure.
*/
int main(int argc, char *argv[])
{
Elf64_Ehdr *header;
int fd, s;

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_file(fd);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
s = read(fd, header, sizeof(Elf64_Ehdr));
if (s == -1)
{
free(header);
close_file(fd);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

if (!is_elf_file(header->e_ident))
exit(0);

printf("ELF Header:\n");
print_magic_numbers(header->e_ident);
print_header_field("Class:", (header->e_ident[EI_CLASS] == ELFCLASS32) ?
"ELF32" : "ELF64");
print_header_field("Data:", (header->e_ident[EI_DATA] == ELFDATA2LSB) ?
"2's complement, little endian" :
(header->e_ident[EI_DATA] == ELFDATA2MSB) ?
"2's complement, big endian" : "Invalid");
print_header_field("Version:", (header->e_ident[EI_VERSION] == EV_CURRENT) ?
"1 (current)" : "Invalid");
print_header_field("OS/ABI:", (header->e_ident[EI_OSABI] == ELFOSABI_NONE) ?
"UNIX - System V" :
(header->e_ident[EI_OSABI] == ELFOSABI_HPUX) ? "UNIX - HP-UX" :
(header->e_ident[EI_OSABI] == ELFOSABI_NETBSD) ? "UNIX - NetBSD" :
(header->e_ident[EI_OSABI] == ELFOSABI_LINUX) ? "UNIX - Linux" :
(header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS) ? "UNIX - Solaris" :
(header->e_ident[EI_OSABI] == ELFOSABI_IRIX) ? "UNIX - IRIX" :
(header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD) ? "UNIX - FreeBSD" :
(header->e_ident[EI_OSABI] == ELFOSABI_TRU64) ? "UNIX - TRU64" :
(header->e_ident[EI_OSABI] == ELFOSABI_ARM) ? "ARM" :
(header->e_ident[EI_OSABI] == ELFOSABI_STANDALONE) ?
"Standalone App" : "Invalid");
print_header_field("ABI Version:",
(char *)(&(header->e_ident[EI_ABIVERSION])));
print_header_field("Type:", (header->e_type == ET_NONE) ? "NONE (None)" :
(header->e_type == ET_REL) ? "REL (Relocatable file)" :
(header->e_type == ET_EXEC) ? "EXEC (Executable file)" :
(header->e_type == ET_DYN) ? "DYN (Shared object file)" :
(header->e_type == ET_CORE) ? "CORE (Core file)" : "Invalid");
print_header_field("Entry point address:", (char *)(&(header->e_entry)));
free(header);
close_file(fd);
return (0);
}
