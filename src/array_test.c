#include "unit_test/unit_test.h"
#include "array.h"


TEST(get_size, 
    int* a = array_create(int, 5);
    EXPECT_EQ(5, array_size(a));
    array_free(a);
)

TEST(assign_nth_element, 
    int* a = array_create(int, 5);
    a[3] = 3;
    EXPECT_EQ(3, a[3]);

    array_free(a);
)

struct my_struct {
    int a;
    char b;
};

TEST(complex_type_assignment, 
    int static_array[] = {2, 3, 5, 7, 11, 13, 17, 19};
    struct my_struct* a = array_create(struct my_struct, sizeof(static_array) / sizeof(*static_array));
    for (int i = 0; i < array_size(a); ++i) {
        a[i].a = static_array[i];
        a[i].b = i;
    }

    for (int i = 0; i < array_size(a); ++i) {
        EXPECT_EQ(static_array[i], a[i].a);
        EXPECT_EQ(i, a[i].b);
    }

    EXPECT_EQ(sizeof(static_array) / sizeof(*static_array), array_size(a));

    array_free(a);
)

static bool test_func(int* a)
{
    return 5 == array_size(a);
}

TEST(get_size_in_function_call, {
    int* a = array_create(int, 5);
    EXPECT_TRUE(test_func(a));
    array_free(a);
})

static void run_tests() {
    RUN_TEST(get_size);
    RUN_TEST(assign_nth_element);
    RUN_TEST(complex_type_assignment);
    RUN_TEST(get_size_in_function_call);
}


int main() {
    printf("Running Tests:\n\n");

    run_tests();

    VALIDATE();
    return 0;
}
