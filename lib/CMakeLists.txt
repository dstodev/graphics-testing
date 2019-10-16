# 2019 Daniel Stotts

add_subdirectory(MSDL)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest EXCLUDE_FROM_ALL)
