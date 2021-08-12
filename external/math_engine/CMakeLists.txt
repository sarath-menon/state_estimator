add_library(math_engine 
src/backward_difference.cpp
)

target_link_libraries(math_engine
Eigen3::Eigen
)

target_include_directories(math_engine PUBLIC include)