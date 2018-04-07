

#include "unit_test.h"

size_t number_of_tests = 0;

void ut_test_case(const char *desc, ut_test_block_t code)
{
    ut_status_t status = code();
    if (status == UT_SUCCESS)
    {
        printf("\033[32m\u2713\t%s\n\033[0m", desc);
    } else 
    {
        printf("\033[31m\u2717\t%s\n\033[0m", desc);
    }
    number_of_tests++;
}

ut_test_case_t ut_test_case_create(const char *desc, ut_test_block_t code)
{
    ut_test_case_t test_case;
    test_case.desc = desc;
    test_case.test_code = code;
    return test_case;
}

ut_test_unit_t ut_test_unit_init(const char *desc, ut_test_case_t test_cases[], size_t count)
{
    ut_test_unit_t test_unit;
    test_unit.desc = desc;
    test_unit.test_cases = test_cases;
    test_unit.test_cases_count = count;
    return test_unit;
}

ut_test_unit_t ut_test_unit_create(const char *desc)
{
    ut_test_unit_t test_unit;
    test_unit.desc = desc;
    test_unit.test_cases = NULL;
    test_unit.test_cases_count = 0;
    return test_unit;
}

ut_status_t ut_test_case_run(ut_test_case_t test_case)
{
    ut_status_t status = test_case.test_code();
    if (status == UT_SUCCESS)
    {
        printf("\033[32m\n\u2713\t%s\n\n\033[0m", test_case.desc);
    } else 
    {
        printf("\033[31m\n\u2717\t%s\n\n\033[0m", test_case.desc);
    }
    return status;
}

void ut_test_unit_run(ut_test_unit_t unit)
{
    printf("%s\n", unit.desc);
    size_t i, successful_tests = 0;

    timeinterval_t begin = now();

    for (i = 0; i < unit.test_cases_count; i++)
        successful_tests += ut_test_case_run(unit.test_cases[i]) == UT_SUCCESS;

    timeinterval_t end = now();
    
    putchar('\n');
    printf("%ld / %ld tests were successful! Time elapsed: %lld ms\n\n", unit.test_cases_count, successful_tests, time_elapsed(begin, end, MILLISECONDS));
}

void ut_test_unit_new_case(ut_test_unit_t *unit, const char *desc, ut_test_block_t code)
{
    ut_test_case_t new_case = ut_test_case_create(desc, code);
    unit->test_cases = salloc(unit->test_cases, (++unit->test_cases_count) * sizeof(ut_test_case_t));
    unit->test_cases[unit->test_cases_count - 1] = new_case;
}