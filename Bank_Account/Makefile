.PHONY: all clean

BUILD_DIR := build

all:
	@if [ ! -d $(BUILD_DIR) ]; then \
		echo "Creating build directory..."; \
		mkdir $(BUILD_DIR); \
	fi
	cd $(BUILD_DIR) && cmake ..
	cd $(BUILD_DIR) && make

clean:
	rm -rf $(BUILD_DIR)
