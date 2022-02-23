replrootpath=$PWD

source_file=$replrootpath/'Workspace/main.cpp'
target_file=$replrootpath/'FeeshmoraEngine'

extra_file=$replrootpath/'Application.cpp'

export DISPLAY=:0.0

g++ -std=c++17 -o $target_file $source_file -lglfw -lGL -ldl

$target_file