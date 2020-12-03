cmake_minimum_required(VERSION 3.0)
project(dataStructure)

set(CMAKE_CXX_STANDARD 11)

# libs
add_library(
    bin_tree
    INTERFACE
    )
target_include_directories(
    bin_tree 
    INTERFACE 
    include
    )

add_library(
    heap 
    INTERFACE
    )
target_include_directories(
    heap 
    INTERFACE 
    include
    )

add_library(
    huffman_tree
    src/huffman_tree/huffmanTree.cpp
    )
target_include_directories(
    huffman_tree
    PUBLIC
    include
    )

add_library(
    libbitio
    src/bits/fileBitReader.cpp
    src/bits/fileBitWriter.cpp
)
target_include_directories(
    libbitio
    PUBLIC
    include
)

# tests
add_executable(
    test_basicBinaryTree 
    tests/test_basicBinaryTree.cpp
    )
target_link_libraries(
    test_basicBinaryTree 
    bin_tree
    )

add_executable(
    test_heap 
    tests/test_heap.cpp
    )
target_link_libraries(
    test_heap 
    heap
    )

add_executable(
    test_huffmanTree 
    tests/test_huffmanTree.cpp
    app/simpleCompressor/get_huffman_code.hpp
    app/simpleCompressor/get_huffman_code.cpp
    )
target_link_libraries(
    test_huffmanTree 
    bin_tree heap 
    huffman_tree
    )

add_executable(
    test_fileBitReaderAndWriter
    tests/test_fileBitReaderAndWriter.cpp
    )
target_link_libraries(
    test_fileBitReaderAndWriter
    libbitio
    )

add_executable(
    test_count_char
    tests/test_count_char.cpp
    app/simpleCompressor/count_char.hpp
    app/simpleCompressor/count_char.cpp
    )

add_executable(
    test_huffman_encoder_decoder
    tests/test_huffman_encoder_decoder.cpp
    app/simpleCompressor/huffman_encoder_decoder.cpp
    app/simpleCompressor/huffman_encoder_decoder.hpp
    app/simpleCompressor/get_huffman_code.hpp
    app/simpleCompressor/get_huffman_code.cpp
    app/simpleCompressor/count_char.hpp
    app/simpleCompressor/count_char.cpp
    )
target_link_libraries(
    test_huffman_encoder_decoder
    huffman_tree
    bin_tree
    libbitio
    )

aux_source_directory(app/simpleCompressor COMPRESSOR_DIR)
add_executable(
    simpleCompressor
    ${COMPRESSOR_DIR}
    )
target_link_libraries(
    simpleCompressor 
    bin_tree 
    heap
    huffman_tree
    libbitio
    )
