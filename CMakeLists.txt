cmake_minimum_required(VERSION 3.29)
project(sn_code_scraper_in_c C)

set(CMAKE_C_STANDARD 11)

find_package(CURL REQUIRED)

add_executable(sn_code_scraper_in_c
    main.c)

target_link_libraries(sn_code_scraper_in_c CURL::libcurl)
