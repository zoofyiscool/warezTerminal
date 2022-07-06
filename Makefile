CC = g++
buildDir = build
srcDir = src
installPath = /usr/bin
target = warezTerminal

all:
	if [[ ! -d "$(buildDir)" ]]; then \
		mkdir $(buildDir); \
	fi; \
	$(CC) $(srcDir)/main.cpp $(srcDir)/test.cpp -o ${buildDir}/$(target)
	@echo "Please run 'make install' as root to install"
	@echo "Or run 'make test' to run"

test:
	@$(buildDir)/$(target)

install:
	@cp $(buildDir)/$(target) $(installPath)
	@echo "Installed! Type '$(target)'"

clean:
	rm -rf $(buildDir)

