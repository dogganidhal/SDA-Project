

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h"
#include "ordered_set_tests.h"
#include "string_analyzer_tests.h"
#include "bst_tests.h"
#include "bst_ops_tests.h"
#include "problem_tests.h"

#define BST_TEST "bst"
#define ORDERED_SET_TEST "ordset"
#define ANALYZER_TEST "analyzer"
#define BST_OPS_TEST "bstops"
#define ALL_TESTS "all"

void run_test_units(int argc, char *argv[])
{
    index_t index;
    for (index = 1; index < argc; index++)
    {
        if (strcmp(argv[index], BST_TEST) == 0)
            run_bst_test_unit();
        else if (strcmp(argv[index], ORDERED_SET_TEST) == 0)
            run_ordered_set_test_unit();
        else if (strcmp(argv[index], ANALYZER_TEST) == 0)
            run_string_analyzer_test_unit();
        else if (strcmp(argv[index], BST_OPS_TEST) == 0)
            run_bst_ops_test_unit();
        else if (strcmp(argv[index], ALL_TESTS) == 0)
        {
            run_bst_test_unit();
            printf("\033[34m\t-----------------------------------------------\033[0m\n\n");
            run_ordered_set_test_unit();
            printf("\033[34m\t-----------------------------------------------\033[0m\n\n");
            run_string_analyzer_test_unit();
            printf("\033[34m\t-----------------------------------------------\033[0m\n\n");
            run_bst_ops_test_unit();
            break;
        }
        else
        {
            fprintf(stderr, "Unreconized test unit %s\n", argv[index]);
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char *argv[])
{

    if (argc == 1)
        run_problem_test_unit();
    else
        run_test_units(argc, argv);

    return EXIT_SUCCESS;
}