#include <stdio.h>
#include <stdlib.h>

#include "ot_user_information.h"
#include "ot_linked_list.h"
#include "ot_hash_table.h"

void test_linked_list()
{
    ot_linked_list_t *ot_list = ot_linked_list_create();
    ot_linked_list_init(ot_list, 10);
    printf("max_list_size=%d\n", ot_linked_list_get_max_list_size(ot_list));

    ot_linked_list_set_display_function(ot_list, &ot_user_information_display_users);
    ot_linked_list_set_compare_function(ot_list, &ot_user_information_compare_users);
    ot_linked_list_set_destroy_function(ot_list, &ot_user_information_destroy);

    ot_user_information_t *user_1 = ot_user_information_create();
    ot_user_information_init(user_1);
    ot_user_information_set_sample_buffer(user_1, "sample_buffer");
    ot_user_information_set_name(user_1, "Onur");
    ot_user_information_set_surname(user_1, "Taslioglu");

    ot_user_information_t *user_2 = ot_user_information_create();
    ot_user_information_init(user_2);
    ot_user_information_set_sample_buffer(user_2, "sample_buffer");
    ot_user_information_set_name(user_2, "Onur");
    ot_user_information_set_surname(user_2, "Taslioglu");

    ot_linked_list_add_node(ot_list, user_1);
    ot_linked_list_add_node(ot_list, user_2);
    ot_linked_list_search_node(ot_list, "Taslioglu");
    ot_linked_list_display(ot_list);
    ot_linked_list_destroy(ot_list);
}

void test_hash_table()
{
    int key;
    ot_hash_table_t *ot_hash_table = ot_hash_table_create();
    ot_hash_table_init(ot_hash_table,10);

    ot_linked_list_t *ot_list[10];
    for (size_t i = 0; i < 10; i++)
    {
        ot_list[i] = ot_linked_list_create();
        ot_linked_list_init(ot_list[i], 10);
        printf("max_list_size=%d\n", ot_linked_list_get_max_list_size(ot_list[i]));

        ot_linked_list_set_display_function(ot_list[i], &ot_user_information_display_users);
        ot_linked_list_set_compare_function(ot_list[i], &ot_user_information_compare_users);
        ot_linked_list_set_destroy_function(ot_list[i], &ot_user_information_destroy);
        // add to hash table
        // Add linked list sequence
        ot_hash_table_add(ot_hash_table, ot_list[i], i);
    }

    // create user
    ot_user_information_t *user_1 = ot_user_information_create();
    ot_user_information_init(user_1);
    ot_user_information_set_sample_buffer(user_1, "sample_buffer");
    ot_user_information_set_name(user_1, "Onur");
    ot_user_information_set_surname(user_1, "Taslioglu");

    ot_user_information_t *user_2 = ot_user_information_create();
    ot_user_information_init(user_2);
    ot_user_information_set_sample_buffer(user_2, "sample_buffer");
    ot_user_information_set_name(user_2, "Onur_2");
    ot_user_information_set_surname(user_2, "Taslioglu_2");

    // calculate index

    // get linked list
    key = ot_user_information_hash_key_calculater(user_2);
    ot_linked_list_t *temp_list = ot_hash_table_general_get_data(ot_hash_table, key);

    // add user
    ot_linked_list_add_node(temp_list, user_1);
    ot_linked_list_add_node(temp_list, user_2);

    for (size_t i = 0; i < 10; i++)
    {
        ot_linked_list_display(ot_list[i]);
        ot_linked_list_destroy(ot_list[i]);
    }

    ot_hash_table_destroy(ot_hash_table);
}

int main(int argc, char *argv[])
{
    ot_user_information_test();
    ot_linked_list_test();
    test_hash_table();
}
