#pragma once

#define UACPI_ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define UACPI_UNUSED(x) (void)(x)

#ifdef __cplusplus
#define STATIC_ASSERT static_assert
#else
#define STATIC_ASSERT _Static_assert
#endif

#define UACPI_BUILD_BUG_ON_WITH_MSG(expr, msg) STATIC_ASSERT(!(expr), msg)

#define UACPI_BUILD_BUG_ON(expr) \
    UACPI_BUILD_BUG_ON_WITH_MSG(expr, "BUILD BUG: " #expr " evaluated to true")

#define UACPI_EXPECT_SIZEOF(type, size)                        \
    UACPI_BUILD_BUG_ON_WITH_MSG(sizeof(type) != size,          \
                                "BUILD BUG: invalid type size")
