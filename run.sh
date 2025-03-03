if [[ $(clang++ -o main src/main.cpp -I $RAYLIB -L $RAYLIB -lraylib -lGL -lm -lpthread -ldl -lrt) -eq 0 ]]; then
    ./main
fi
