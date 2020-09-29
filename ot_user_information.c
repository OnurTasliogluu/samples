#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ot_user_information.h"

ot_user_information_t *ot_user_information_create()
{
    ot_user_information_t *this = malloc(sizeof(ot_user_information_t));

    if (this == NULL)
    {
        printf("Allocation Error!\n");
    }

    return this;
}

void ot_user_information_init(ot_user_information_t *this)
{
    this->sample_buffer = malloc(GENERAL_BUFFER_SIZE);

    memset(this->name, '\0', GENERAL_BUFFER_SIZE);
    memset(this->surname, '\0', GENERAL_BUFFER_SIZE);
    memset(this->sample_buffer, '\0', GENERAL_BUFFER_SIZE);
}

void ot_user_information_set_name(ot_user_information_t *this, char *name)
{
    // Important Rule - Memory Leak or Memory Corruption
    // For example name size=5
    // For example name size=15
    if (strlen(name) < GENERAL_BUFFER_SIZE)
    {
        strncpy(this->name, name, strlen(name));
    }
}

char *ot_user_information_get_name(ot_user_information_t *this)
{
    return this->name;
}

void ot_user_information_set_surname(ot_user_information_t *this, char *surname)
{
    // Important Rule - Memory Leak or Memory Corruption
    // For example name size=5
    // For example name size=15
    if (strlen(surname) < GENERAL_BUFFER_SIZE)
    {
        strncpy(this->surname, surname, strlen(surname));
    }
}

char *ot_user_information_get_surname(ot_user_information_t *this)
{
    return this->surname;
}

void ot_user_information_set_sample_buffer(ot_user_information_t *this, char *sample_buffer)
{
    if (strlen(sample_buffer) < GENERAL_BUFFER_SIZE)
    {
        strncpy(this->sample_buffer, sample_buffer, strlen(sample_buffer));
    }
}

char *ot_user_information_get_sample_buffer(ot_user_information_t *this)
{
    return this->sample_buffer;
}

void ot_user_information_display_users(void *user)
{
    ot_user_information_t *this = user;
    if (this != NULL)
    {
        printf("this->name = %s\n", this->name);
        printf("this->surname = %s\n", this->surname);
        printf("this->sample_buffer = %s\n", this->sample_buffer);
    }
}

int ot_user_information_compare_users(void *user_1, void *user_surname)
{
    if (!strcmp(ot_user_information_get_surname(user_1), user_surname))
    {
        printf("Users Equal\n");
        return 0;
    }
    return -1;
}

int ot_user_information_hash_key_calculater(ot_user_information_t *this)
{
    int key = 0;
    char *surname = ot_user_information_get_surname(this);

    for (size_t i = 0; i < strlen(ot_user_information_get_surname(this)); i++)
    {
        key += surname[i];
    }

    return key;
}

void ot_user_information_deinit(ot_user_information_t *this)
{
    memset(this->name, '\0', GENERAL_BUFFER_SIZE);
    memset(this->surname, '\0', GENERAL_BUFFER_SIZE);
    free(this->sample_buffer);
}

void ot_user_information_destroy(void *this)
{
    ot_user_information_deinit(this);
    free(this);
}

void ot_user_information_test()
{
    char *temp;
    ot_user_information_t *this = ot_user_information_create();
    ot_user_information_init(this);
    ot_user_information_set_sample_buffer(this, "sample_buffer");
    temp = ot_user_information_get_sample_buffer(this);
    printf("temp sample_buffer=%s\n", temp);
    ot_user_information_set_name(this, "Onur");
    temp = ot_user_information_get_name(this);
    printf("temp name=%s\n", temp);
    ot_user_information_set_surname(this, "Taslioglu");
    temp = ot_user_information_get_surname(this);
    printf("temp surname=%s\n", temp);
    ot_user_information_display_users(this);
    ot_user_information_deinit(this);
    ot_user_information_init(this);
    ot_user_information_set_name(this, "Joe");
    ot_user_information_set_surname(this, "Done");
    ot_user_information_set_sample_buffer(this, "sample_buffer");
    ot_user_information_display_users(this);
    ot_user_information_destroy(this);
}
