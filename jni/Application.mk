#NDK_TOOLCHAIN_VERSION := 4.8
NDK_TOOLCHAIN_VERSION := clang
APP_STL := gnustl_shared  #gnustl_static #stlport_static

# Enable c++11 extentions in source code
# APP_CPPFLAGS += -std=c++11