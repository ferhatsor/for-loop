#include <stdio.h>

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

    printf("Datei %s erfolgreich geöffnet.\n", file_path);

    fclose(datei);

    return 0;
}

