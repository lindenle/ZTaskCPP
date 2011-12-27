#!/bin/sh
#this is a generic file - you never need to change this one
srcdir=`dirname $0`
test -z "$srcdir" && srcdir=.

(cd $srcdir; aclocal; libtoolize --force; automake -a --add-missing; autoconf)

$srcdir/configure "$@"
