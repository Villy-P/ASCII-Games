.ONESHELL:

snake-reset:
	rmdir snake/build
	mkdir snake/build
	cd snake/build
	cmake -GNinja ..

snake-run:
	ninja -C snake/build
	.\snake\build\C_SNAKE.exe

ms-run:
	cd ms
	dotnet run