NAME = demohps

.PHONY: all build test info clean run status help
all: build

info: build
	@echo "Binary info:"
	@file .build/$(TARGET)/$(BUILD_TYPE)/$(NAME)
	@echo ""
	@ls -la .build/$(TARGET)/$(BUILD_TYPE)/$(NAME)

config:
	@echo "Build Configuration:"
	@echo "  Target: $(TARGET)"
	@echo "  Configuration: $(BUILD_TYPE)"
	@echo "  Product Name: $(NAME)"

resolve:
	@echo "Resolving package dependencies..."
	swift package resolve

update:
	@echo "Updating package dependencies..."
	swift package update

test: build
	@echo "Binary built for: $(TARGET)"
	@file .build/$(TARGET)/$(BUILD_TYPE)/$(NAME)

clean:
	@echo "Cleaning build artifacts..."
	swift package clean

build:
	@echo "Building Swift HPS project for ARM ($(TARGET))..."
	swift build --configuration $(BUILD_TYPE) --triple $(TARGET) --toolset toolset.json

run: build
	@echo "Running ARM binary with QEMU..."
	qemu-armel-static .build/$(TARGET)/$(BUILD_TYPE)/$(NAME)

xcode:
	@echo "Generating Xcode project..."
	swift package generate-xcodeproj

status:
	@echo "=== Swift HPS Project Status ==="
	@echo ""
	@echo "Target: $(TARGET)"
	@echo "Configuration: $(BUILD_TYPE)"
	@echo ""
	@echo "Swift Implementation (main.swift):"
	@wc -l Sources/demohps/main.swift | awk '{print "  " $$1 " lines - Swift 6 ownership model, pure I/O"}'
	@echo ""
	@echo "ARM Runtime (runtime.c):"
	@wc -l Sources/CHPSRuntime/runtime.c | awk '{print "  " $$1 " lines - Standard C library + ARM EABI"}'
	@echo ""
	@echo "Architecture: ARM embedded (no x86_64)"
	@echo "Approach: Swift 6 Embedded + standard C library"
	@echo "Evaluation: Swift for ARM HPS systems"

help:
	@echo "Available targets:"
	@echo "  all/build  - Build for ARM target ($(TARGET))"
	@echo "  clean      - Clean build artifacts"
	@echo "  config     - Show build configuration"
	@echo "  info       - Show built binary information"
	@echo "  resolve    - Resolve package dependencies"
	@echo "  run        - Run ARM binary with QEMU"
	@echo "  status     - Show project status"
	@echo "  test       - Show ARM binary info (can't run on x86_64)"
	@echo "  update     - Update package dependencies"
	@echo "  xcode      - Generate Xcode project"
	@echo "  help       - Show this help message"
