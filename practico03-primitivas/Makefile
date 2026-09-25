# ------------------------------------------------------------------------------
# Makefile - Practico 03: primitivas parametricas y matriz de modelo.
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Librerias de terceros
GLAD_DIR = ./third_party/glad
include $(GLAD_DIR)/glad.mk

# ------------------------------------------------------------------------------
# Configurar includes paths
INC_DIRS = \
    $(GLAD_INC_DIRS) \
    ./src

# ------------------------------------------------------------------------------
# Configurar dirs de librerias externas y dirs locales al proyecto
# (fuentes para compilar).
# Recoleccion automatica de fuentes. Mantener DISJUNTO de SRC_DIR
# (si no, main.o se linkearia dos veces).
#
# Recomendacion 1 de la guia: "solo hay que agregar el subdirectorio de los
# modulos a la variable LIB_DIRS". El wildcard NO es recursivo, asi que hay que
# listar cada subcarpeta con fuentes.
LIB_DIRS = \
    $(GLAD_LIB_DIRS) \
    ./src/resources \
    ./src/mesh \
    ./src/shader

# ------------------------------------------------------------------------------
# Dir del main de la aplicacion y nombre del archivo de codigo fuente
SRC_DIR  = \
    ./src                     # main.cpp

MAIN_CXX     = main

# ------------------------------------------------------------------------------
# Configurar salida el proyecto
PROJECT_NAME = ogl-app

# ------------------------------------------------------------------------------
# Configurar linkeo de librerias
ifeq ($(OS), Windows_NT)
        PROJECT_LDLIBS = -L/mingw64/lib -lglfw3 -lopengl32 -lgdi32 -lpthread
else
	PROJECT_LDLIBS = -lglfw -lGL -lX11 -lXrandr -ldl -lpthread
endif

# ------------------------------------------------------------------------------
# Configurar opciones de compilacion
# Para compilar con simbolos para debug usar: -g -Wall
USERCPPFLAGS = -O2 -Wall -Wextra

# ------------------------------------------------------------------------------
# Makefile.master
ifeq ($(wildcard ./Makefile.master),)
    $(error Makefile.master no encontrado: se espera symlink a \
    makefile-unified/Makefile.master o una copia local junto a este Makefile)
endif
include ./Makefile.master

# ------------------------------------------------------------------------------
# Verificacion pedida por la guia: "No hay un solo glDelete* en el main.cpp".
# Va DESPUES del include para no robarle el default goal a 'build'.
# Se quitan los comentarios antes de buscar (si no, el propio comentario que
# documenta la condicion daria un falso positivo) y se exige el parentesis de
# llamada, para no confundir una mencion con una invocacion.
.PHONY: check-main
check-main:
	@if sed 's://.*::' ./src/main.cpp | \
	    grep -nE 'glDelete[A-Za-z]*[[:space:]]*\(' ; then \
	    echo "FALLA: hay llamadas glDelete* en main.cpp"; exit 1; \
	else \
	    echo "OK: no hay ninguna llamada glDelete* en main.cpp"; \
	fi
