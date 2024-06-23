#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];

    FILE *datei = fopen(file_path, "r");

    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei: %s\n", file_path);
        return 1;
    }

    fseek(datei, 0, SEEK_END);
    long file_size = ftell(datei);
    fseek(datei, 0, SEEK_SET);

    char *content = malloc(file_size + 1);
    if (content == NULL) {
        printf("Fehler bei der Speicherallokierung\n");
        fclose(datei);
        return 1;
    }

    size_t read_size = fread(content, 1, file_size, datei);
    content[read_size] = '\0';

    fclose(datei);

    printf("Dateiinhalt:\n%s\n", content);

    free(content);

    return 0;
}

