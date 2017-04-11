/*
 * Count the frequency of words in the .txt file provided
 * as a command line argument.
 *
 * @author: jovanduy
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

void iterator(gpointer key, gpointer value, gpointer user_data) {
    printf(user_data, key, *(gint*)value);
}

int main(int argc, char** argv) {
    char buff[100];
    int word_count;

    if (argc != 2) {
        fprintf(stderr, "Include one .txt file as input.");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    GHashTable *hash = g_hash_table_new(g_str_hash, g_str_equal);

    while (fscanf(fp, "%s", buff) != EOF) {
        word_count = GPOINTER_TO_INT(g_hash_table_lookup(hash, buff));
        g_hash_table_insert(hash, g_strdup(buff), GINT_TO_POINTER(word_count + 1));
    }
    g_hash_table_foreach(hash, (GHFunc)iterator, "The count of %s is %d\n");
}
