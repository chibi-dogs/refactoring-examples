add_library(types STATIC)

target_sources(types
        PUBLIC
        FILE_SET CXX_MODULES FILES
        types.ixx
)

target_compile_features(types PUBLIC cxx_std_23)