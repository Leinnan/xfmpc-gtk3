link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )
    
    
file(GLOB_RECURSE SRCS ./*)

add_executable(../xfmpc # name of the executable on Windows will be example.exe 
    main.cpp 
    ${SRCS} )

target_link_libraries(../xfmpc 
    ${GTKMM_LIBRARIES}  )
