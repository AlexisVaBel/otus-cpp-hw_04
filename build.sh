mkdir ./build
cd ./build
cmake ..
make -j4
doxygen ./docs/Doxyfile
./print_ip
#ltrace -e malloc -e free ./allocator > /dev/null
#valgrind --tool=memcheck ./allocator 
#valgrind --leak-check=full -v  ./allocator
