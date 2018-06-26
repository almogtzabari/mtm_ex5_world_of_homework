//
// Created by ron on 28/05/18.
//

#ifndef CALLOFDUTY_TEST_UTILITIES_H
#define CALLOFDUTY_TEST_UTILITIES_H

#include <iostream>

#define ASSERT_TEST(b) do { \
        if (!(b)) { \
                std::cout << "\nAssertion failed at" << __FILE__ <<__LINE__ << std::endl; \
                return false; \
        } \
} while (0)

/**
 * Macro used for running a test from the main function
 */
#define RUN_TEST(test) do { \
        std::cout << "Running "#test"... "; \
        if (test()) { \
            std::cout << "[OK]\n"; \
        } else { \
        	std::cout << "[Failed]\n"; \
        } \
} while(0)

#define ASSERT_THROW(code, exception_type) do { \
        bool thrown = false; \
        try { \
                code\
        } catch (exception_type& ) { \
                thrown = true; \
        } catch (...) {} \
        if (!thrown) { \
                std::cout << "\nAssertion failed at" << __FILE__ <<__LINE__ << std::endl; \
                std::cout << "Expected to throw " << #exception_type << std::endl; \
                return false; \
        }\
} while (0)

#endif //CALLOFDUTY_TEST_UTILITIES_H