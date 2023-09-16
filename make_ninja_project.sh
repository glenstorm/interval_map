mkdir build
cd build
#cmake -GNinja -DCMAKE_BUILD_TYPE=Debug ../
cmake -GNinja ../
ninja
# cgdb interval_map
./interval_map
