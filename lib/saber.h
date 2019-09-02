#if !defined(SABER)
#define SABER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int * integer_ptr;
typedef char * string;
typedef void * void_ptr;
typedef enum
{
    FALSE, TRUE
} Boolean;

typedef enum
{
    IS_EQUAL
} AssertionType;

typedef enum
{
    INTEGER, STRING
} ValueType;

typedef struct AssertionNode AssertionNode;
typedef AssertionNode * _AssertionNode;

struct AssertionNode
{
    AssertionType assertion_type;
    ValueType value_type;
    void_ptr function_value;
    void_ptr expected_value;
};

AssertionNode create_assertion(AssertionType assertion_type, ValueType value_type,
    void_ptr function_value, void_ptr expected_value)
{
    _AssertionNode assertion_node_ptr = (_AssertionNode) malloc(sizeof(AssertionNode));
    if (assertion_node_ptr != NULL)
    {
        assertion_node_ptr->assertion_type = assertion_type;
        assertion_node_ptr->value_type = value_type;
        assertion_node_ptr->function_value = function_value;
        assertion_node_ptr->expected_value = expected_value;
        return *assertion_node_ptr;
    }
    else
    {
        create_assertion(assertion_type, value_type, function_value, expected_value);
    }
}

Boolean test_assertion(AssertionNode assertion_node)
{
    switch(assertion_node.assertion_type)
    {
        case IS_EQUAL:
        {
            switch(assertion_node.value_type)
            {
                case INTEGER:
                {
                    if (*(integer_ptr) assertion_node.function_value == *(integer_ptr) assertion_node.expected_value)
                    {
                        return TRUE;
                    }
                    else
                    {
                        return FALSE;
                    }
                }
                case STRING:
                {
                    if (!strcmp((string) assertion_node.function_value, (string) assertion_node.expected_value))
                    {
                        return TRUE;
                    }
                    else 
                    {
                        return FALSE;
                    }
                }
            }
        }
    }
}

#endif // SABER