all: build_hysteria build_sandbox

# Hysteria
H_SRC_DIR=Hysteria/Source
H_INC_DIR=Hysteria/Include
H_VND_DIR=$(H_INC_DIR)/Vendor
H_LIB_DIR=$(H_VND_DIR)/Lib

H_BIN_DIR=Bin/Hysteria

H_SRC_FILES=$(H_VND_DIR)/GLAD/glad.c \
			$(H_SRC_DIR)/Core/Window.c \
			$(H_SRC_DIR)/Graphics/Shader.c \
			$(H_SRC_DIR)/Graphics/Buffer.c

build_hysteria:
	gcc -shared $(H_SRC_FILES) -o $(H_BIN_DIR)/hysteria.dll -I$(H_INC_DIR) -L$(H_LIB_DIR) \
	-lglfw3 -lopengl32 -lgdi32

# Sandbox

S_SRC_DIR=Sandbox
S_INC_DIR=Hysteria/Include
S_LIB_DIR=$(H_BIN_DIR)

S_BIN_DIR=Bin/Sandbox

S_SRC_FILES=$(S_SRC_DIR)/Main.c

build_sandbox:
	gcc $(S_SRC_FILES) -o $(S_BIN_DIR)/Sandbox.exe -I$(S_INC_DIR) -L$(H_BIN_DIR) \
	-lhysteria