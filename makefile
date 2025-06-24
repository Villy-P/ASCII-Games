.ONESHELL:

reset:
	rmdir build
	mkdir build
	cd build
	cmake -GNinja ..

run:
	ninja -C build
	.\C_SNAKE.exe

run-linux:
	ninja -C build
	./C_SNAKE