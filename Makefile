VERSION?=2.7.2

help:
	@echo "Targets: configure all clean format install package"

configure:

	rm -rf build

	mkdir build

	cd build ; cmake ..

all:
	make -C build all

install:
	make -C build install

clean:
	make -C build clean

format:
	clang-format -i $(wildcard src/*.cc)
	clang-format -i $(wildcard src/*.hh)

package:
	make -C build clean || echo -n

	tar -cvf temp.tar --exclude="*~" --exclude="*#" \
		--exclude=".svn" --exclude="*.orig" --exclude="*.rej" \
		AUTHORS \
		CMakeLists.txt \
		COPYING \
		Makefile \
		NEWS \
		README.md \
		TODO \
		cmake \
		jack_keyboard.png \
		man \
		pixmaps \
		src

	rm -rf jack-keyboard-${VERSION}

	mkdir jack-keyboard-${VERSION}

	tar -xvf temp.tar -C jack-keyboard-${VERSION}

	rm -rf temp.tar

	tar --gid 0 --uid 0 -zcvf jack-keyboard-${VERSION}.tar.gz jack-keyboard-${VERSION}
