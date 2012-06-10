#!/bin/sh
## This Script should be located inside the root project directory.
## by Kevin Morris

SRCDIR='./src'
BUILDDIR='./build'
SRCFILE='main.cpp'
BINFILE='k91-bits'

if [ -d "${BUILDDIR}" ]; then
    echo "${BUILDDIR} exists, okay"
else
    echo "${BUILDDIR} doesn't exist, creating"
    mkdir -v $BUILDDIR
fi

if [ -d "${SRCDIR}" ]; then
    echo "${SRCDIR} exists, okay"
    cd $SRCDIR
    if [ -f "${SRCFILE}" ]; then
        echo "${SRCFILE} exists, okay"
        cd ..
    else
        echo "${SRCFILE} doesn't exist, there is something wrong with your project folder"
        echo "clone this project using 'git clone https://github.com/kevr91/k91-bits.git'"
        exit 1
    fi
else
    echo "${SRCDIR} doesn't exist, there is something wrong with your project folder"
    echo "clone this project using 'git clone https://github.com/kevr91/k91-bits.git'"
    exit 2
fi

cd $BUILDDIR

if [ -f "${BINFILE}" ]; then
    echo "Cleaning ${BINFILE}"
    rm -v $BINFILE
fi

cd ..

echo "Building ${BINFILE}"

g++ $SRCDIR/$SRCFILE -o $BUILDDIR/$BINFILE 2> latest-build.log

cd $BUILDDIR

if [ -f "${BINFILE}" ]; then
    echo "Successfully compiled binary"
    echo "Binary resides in ${BUILDDIR}"
else
    echo "Failed to compile binary"
    echo "You may see g++'s output for this session in latest-build.log in the root directory"
    exit 3
fi

exit 0

