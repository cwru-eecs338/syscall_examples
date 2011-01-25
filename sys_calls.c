#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void print_time();
void env_variables();

int main() {
    print_time();
    puts("");
    env_variables();
    return 0;
}

void print_time() {
    // Time, in seconds, since the
    // Unix Epoch (00:00:00 UTC on 1 January 1970)
    time_t t = time(NULL);

    // Fun fact:
    // Unix time is currently represented
    // with a 32-bit integer on some systems,
    // which will overflow on January 19, 2038
    printf("Seconds since Jan. 1, 1970: %d\n", (int)t);

    // Time can be turned into a nice
    // string format using ctime:
    char *time_string = ctime(&t);
    printf("%s", time_string);
}

void env_variables() {

    // Construct a string from
    // a string and an integer:
    char *varname = "TEST";
    int value = 12345;
    char buffer[11];
    sprintf(buffer, "%s=%d", varname, value);
    
    // Set the variable
    if(putenv(buffer)) {
        perror("putenv");
        exit(1);
    }
    
    // Get the variable
    char *env_val_str = getenv("TEST");
    if(env_val_str == NULL) {
        perror("getenv");
        exit(1);
    }

    // Parse the value
    int env_val;
    if(!sscanf(env_val_str, "%d", &env_val)) {
        fprintf(stderr, "Couldn't parse value.\n");
        exit(1);
    }
    printf("The value is: %d\n", env_val);

    // Careful not to modify arguments to
    // putenv or return value of getenv, since
    // since they point to the actual
    // environment variable strings
    buffer[1] = 'O';
    env_val_str[0] = '2';

    env_val_str = getenv("TEST");
    if(env_val_str == NULL) {
        fprintf(stderr, "Can't find \"TEST\" now!\n");
    }

    env_val_str = getenv("TOST");
    if(env_val_str == NULL) {
        perror("getenv");
        exit(1);
    }
    puts("The value is under \"TOST\"");

    if(!sscanf(env_val_str, "%d", &env_val)) {
        fprintf(stderr, "Couldn't parse value.\n");
        exit(1);
    }
    printf("And the value is: %d\n", env_val);
}
