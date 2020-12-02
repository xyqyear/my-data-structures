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
    src/huffman_tree/encode_huffmanTree.cpp 
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
    writeHuffmanTreeToFile 
    app/writeHuffmanTreeToFile.cpp
    )
target_link_libraries(
    writeHuffmanTreeToFile 
    bin_tree 
    heap huffman_tree
    )
