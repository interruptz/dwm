# dwm version
VERSION = 6.0

# Customize below to fit your system

# paths
PREFIX = /usr
MANPREFIX = ${PREFIX}/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# Xinerama
XINERAMALIBS = -L${X11LIB} -lXinerama
XINERAMAFLAGS = -DXINERAMA

# Xft
XFTLIBS = `pkg-config --libs xft`
XFTFLAGS = `pkg-config --cflags xft`

# Freetype2
FREETYPELIBS = `pkg-config --libs freetype2`
FREETYPEFLAGS = `pkg-config --cflags freetype2`

# includes and libs
INCS = -I. -I/usr/include -I${X11INC} ${XFTFLAGS} ${FREETYPEFLAGS} 
LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS} ${XFTLIBS} ${FREETYPELIBS}

# flags
CPPFLAGS = -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
#CFLAGS = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
#LDFLAGS = -g ${LIBS}
LDFLAGS = -s ${LIBS}

# Solaris
#CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
#LDFLAGS = ${LIBS}

# compiler and linker
CC = cc
