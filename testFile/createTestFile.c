/* Создание файла со всеми символами таблицы ASCII: с 0 по 127 */
#include <stdio.h>
#include <stdlib.h>

#define TEST_FILE "../testFile/test-e-t-n-v.txt"

void writeAllSymbolsToFile();

int main() {
	writeAllSymbolsToFile();
	printf("Тестовый файл со всеми символами таблицы ASCII создан.\n");
	//getchar();
	return 0;
}

void writeAllSymbolsToFile() {
	FILE *file = fopen(TEST_FILE, "w");
	for (int i = 0; i < 128; i++) {
		fprintf(file, "%-4d%c\n", i, i);
	}
	fclose(file);
}
