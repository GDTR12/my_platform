
aux_source_directory(./src DIRSRCS)
aux_source_directory(../../components/my_printf DIRSRCS)



add_executable(test ${DIRSRCS})

target_compile_features(test PRIVATE cxx_std_17)

target_link_libraries(test PUBLIC component_test_lib list_x cJSON)
target_link_directories(test PUBLIC ../../components/xui/build/lib)
target_link_libraries(test PUBLIC xui)


target_include_directories(test PUBLIC ../../components/ring_x_queue)
target_include_directories(test PUBLIC ../../components/my_printf)
target_include_directories(test PUBLIC ../../components/xui/includes)
