# Makefile for Swift HPS Demo Project

# Default target architecture
TARGET ?= arm64-unknown-linux-gnu

# Swift build configuration
CONFIGURATION ?= release

# Swift build flags
SWIFT_BUILD_FLAGS = --configuration $(CONFIGURATION) --triple $(TARGET) -v

# Build directory
BUILD_DIR = .build

# Product name (from Package.swift)
PRODUCT_NAME = demohps

# Default target
.PHONY: all
all: build

# Build the Swift project
.PHONY: build
build:
	@echo "Building Swift project for target: $(TARGET)"
	swift build $(SWIFT_BUILD_FLAGS)

# Clean build artifacts
.PHONY: clean
clean:
	@echo "Cleaning build artifacts..."
	swift package clean
	rm -rf $(BUILD_DIR)

# Run the built executable (if applicable for the target)
.PHONY: run
run: build
	@echo "Running $(PRODUCT_NAME)..."
	$(BUILD_DIR)/$(TARGET)/$(CONFIGURATION)/$(PRODUCT_NAME)

# Show package dependencies
.PHONY: deps
deps:
	@echo "Showing package dependencies..."
	swift package show-dependencies

# Update package dependencies
.PHONY: update
update:
	@echo "Updating package dependencies..."
	swift package update

# Resolve package dependencies
.PHONY: resolve
resolve:
	@echo "Resolving package dependencies..."
	swift package resolve

# Show build configuration
.PHONY: config
config:
	@echo "Build Configuration:"
	@echo "  Target: $(TARGET)"
	@echo "  Configuration: $(CONFIGURATION)"
	@echo "  Build Flags: $(SWIFT_BUILD_FLAGS)"
	@echo "  Product Name: $(PRODUCT_NAME)"

# Test the project (if tests exist)
.PHONY: test
test:
	@echo "Running tests..."
	swift test --configuration $(CONFIGURATION)

# Generate Xcode project (for development)
.PHONY: xcode
xcode:
	@echo "Generating Xcode project..."
	swift package generate-xcodeproj

# Show help
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all        - Build the project (default)"
	@echo "  build      - Build the Swift project"
	@echo "  clean      - Clean build artifacts"
	@echo "  run        - Build and run the executable"
	@echo "  deps       - Show package dependencies"
	@echo "  update     - Update package dependencies"
	@echo "  resolve    - Resolve package dependencies"
	@echo "  config     - Show build configuration"
	@echo "  test       - Run tests"
	@echo "  xcode      - Generate Xcode project"
	@echo "  help       - Show this help message"
	@echo ""
	@echo "Variables:"
	@echo "  TARGET     - Target architecture (default: $(TARGET))"
	@echo "  CONFIGURATION - Build configuration (default: $(CONFIGURATION))"
	@echo ""
	@echo "Examples:"
	@echo "  make build TARGET=x86_64-unknown-linux-gnu"
	@echo "  make build CONFIGURATION=debug"
	@echo "  make clean && make build"
