#ifndef USER_H
#define USER_H

#include <stdint.h>

#define GENERAL_BUFFER_SIZE 16

typedef struct
{
    char *sample_buffer;
    char name[GENERAL_BUFFER_SIZE];
    char surname[GENERAL_BUFFER_SIZE];
} ot_user_information_t;

ot_user_information_t *ot_user_information_create();
void ot_user_information_init(ot_user_information_t *this);
void ot_user_information_set_sample_buffer(ot_user_information_t *this, char *sample_buffer);
char *ot_user_information_get_sample_buffer(ot_user_information_t *this);
void ot_user_information_set_name(ot_user_information_t *this, char *name);
char *ot_user_information_get_name(ot_user_information_t *this);
void ot_user_information_set_surname(ot_user_information_t *this, char *);
char *ot_user_information_get_surname(ot_user_information_t *this);
void ot_user_information_display_users(void *user);
int ot_user_information_compare_users(void *user_1, void *user_2);
int ot_user_information_hash_key_calculater(ot_user_information_t *this);
void ot_user_information_deinit(ot_user_information_t *this);
void ot_user_information_destroy(void *this);
void ot_user_information_test();

#endif
