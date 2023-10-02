#include <elf.h>
#include "main.h"

/**
* check_elf - Checks if a file is an ELF file.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*/
void check_elf(unsigned char *e_ident)
{
for (int i = 0; i < 4; i++) {
if (e_ident[i] != 127 && e_ident[i] != 'E' && e_ident[i] != 'L' && e_ident[i] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* print_magic - Prints the magic numbers of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*/
void print_magic(unsigned char *e_ident)
{
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
{
printf("%02x%s", e_ident[i], (i == EI_NIDENT - 1) ? "\n" : " ");
}
}

/**
* print_class - Prints the class of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_class(unsigned char *e_ident)
{
const char *class_str;
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE: class_str = "none"; break;
case ELFCLASS32:   class_str = "ELF32"; break;
case ELFCLASS64:   class_str = "ELF64"; break;
default:           class_str = "<unknown>";
}
printf("  Class:   %s\n", class_str);
}

/**
* print_data - Prints the data of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_data(unsigned char *e_ident)
{
const char *data_str;
switch (e_ident[EI_DATA])
{
case ELFDATANONE:   data_str = "none"; break;
case ELFDATA2LSB:   data_str = "2's complement, little endian"; break;
case ELFDATA2MSB:   data_str = "2's complement, big endian"; break;
default:            data_str = "<unknown>";
}
printf("  Data:    %s\n", data_str);
}

/**
* print_version - Prints the version of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/
void print_version(unsigned char *e_ident) {
int version = e_ident[EI_VERSION];
printf("  Version: %d%s\n", version, (version == EV_CURRENT) ? " (current)" : "");
}

/**
* print_osabi - Prints the OS/ABI of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/
void print_osabi(unsigned char *e_ident)
{
const char *osabi_str;
switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:        osabi_str = "UNIX - System V"; break;
case ELFOSABI_HPUX:        osabi_str = "UNIX - HP-UX"; break;
case ELFOSABI_NETBSD:      osabi_str = "UNIX - NetBSD"; break;
case ELFOSABI_LINUX:       osabi_str = "UNIX - Linux"; break;
case ELFOSABI_SOLARIS:     osabi_str = "UNIX - Solaris"; break;
case ELFOSABI_IRIX:        osabi_str = "UNIX - IRIX"; break;
case ELFOSABI_FREEBSD:     osabi_str = "UNIX - FreeBSD"; break;
case ELFOSABI_TRU64:       osabi_str = "UNIX - TRU64"; break;
case ELFOSABI_ARM:         osabi_str = "ARM"; break;
case ELFOSABI_STANDALONE:  osabi_str = "Standalone App"; break;
default:                   osabi_str = "<unknown>";
}
printf("  OS/ABI:  %s\n", osabi_str);
}

/**
* print_abi - Prints the ABI version of an ELF header.
* @e_ident: A pointer to an array containing the ELF ABI version.
*/
void print_abi(unsigned char *e_ident) {
printf("  ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
* print_type - Prints the type of an ELF header.
* @e_type: The ELF type.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB) e_type >>= 8;
const char *type_str;
switch (e_type) {
case ET_NONE: type_str = "NONE (None)"; break;
case ET_REL:  type_str = "REL (Relocatable file)"; break;
case ET_EXEC: type_str = "EXEC (Executable file)"; break;
case ET_DYN:  type_str = "DYN (Shared object file)"; break;
case ET_CORE: type_str = "CORE (Core file)"; break;
default:      type_str = "<unknown>";
}
printf("  Type:    %s\n", type_str);
}

/**
* print_entry - Prints the entry point of an ELF header.
* @e_entry: The address of the ELF entry point.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address: ");
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
if (e_ident[EI_CLASS] == ELFCLASS32)
{
printf("%#x\n", (unsigned int)e_entry);
} else {
printf("%#lx\n", e_entry);
}
}

/**
* close_elf - Closes an ELF file.
* @elf: The file descriptor of the ELF file.
*
* Description: If the file cannot be closed - exit code 98.
*/
void close_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
exit(98);
}
}

/**
* main - Displays the information contained in the
* ELF header at the start of an ELF file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description: If the file is not an ELF File or
* the function fails - exit code 98.
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

int elf_fd = open(argv[1], O_RDONLY);
if (elf_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

Elf64_Ehdr *header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_elf(elf_fd);
dprintf(STDERR_FILENO, "Error: Memory allocation failure\n");
exit(98);
}

ssize_t read_result = read(elf_fd, header, sizeof(Elf64_Ehdr));
if (read_result == -1)
{
free(header);
close_elf(elf_fd);
dprintf(STDERR_FILENO, "Error: Unable to read file %s\n", argv[1]);
exit(98);
}

check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);
print_class(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);

free(header);
close_elf(elf_fd);

return (0);
}
