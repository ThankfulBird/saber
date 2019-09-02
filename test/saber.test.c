#include "../lib/saber.h"
#define DEFAULT_SIZE 255

int add(int first_number, int second_number);
string  get_username();
int main(int argc, char const *argv[])
{
    int integer_function_value = add(1, 2);
    int integer_expected_value = 3;
    void_ptr integer_function_value_ptr = (void_ptr) &integer_function_value;
    void_ptr integer_expected_value_ptr = (void_ptr) &integer_expected_value;
    AssertionNode integer_assertion = create_assertion(IS_EQUAL, INTEGER, integer_function_value_ptr, integer_expected_value_ptr);
    printf("Does 1 + 2 equal 3? %s\n", test_assertion(integer_assertion) ? "YES!" : "NO!");
    integer_expected_value = 2;
    printf("Does 1 + 2 equal 2? %s\n", test_assertion(integer_assertion) ? "YES!" : "NO!");
    string string_function_value = get_username();
    string string_expected_value = (string) malloc(DEFAULT_SIZE);
    strcpy(string_expected_value, "Richard");
    void_ptr string_function_value_ptr = (void_ptr) string_function_value;
    void_ptr string_expected_value_ptr = (void_ptr) string_expected_value;
    AssertionNode string_assertion = create_assertion(IS_EQUAL, STRING, string_function_value_ptr, string_expected_value_ptr);
    printf("Is username Richard? %s\n", test_assertion(string_assertion) ? "YES!" : "NO!");
    strcpy(string_expected_value, "Jasmine");
    printf("Is username Jasmine? %s\n", test_assertion(string_assertion) ? "YES!" : "NO!");
    return EXIT_SUCCESS;
}

int add(int first_number, int second_number)
{
    return first_number + second_number;
}

string  get_username()
{
    return "Richard";
}