#clang -o test test.c c11serializer.c ops_binary.c ops_text.c -Wall -Wextra -std=c11 -pedantic -g3 -O0

####### Platform specifics

# cut is necessary for Cygwin
PLATFORM_OS := $(shell uname | cut -d_ -f1)

####### Makefile Conventions - Directory variables

prefix = /usr
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
sbindir = $(exec_prefix)/sbin
libexecdir = $(exec_prefix)/libexec
datarootdir = $(prefix)/share
datadir = $(datarootdir)
sysconfdir = $(prefix)/etc
localstatedir = $(prefix)/var
includedir = $(prefix)/include
docdir = $(datarootdir)/doc/c11serializer
infodir = $(datarootdir)/info
libdir = $(exec_prefix)/lib
localedir = $(datarootdir)/locale
mandir = $(datarootdir)/man
man1dir = $(mandir)/man1
manext = .1
man1ext = .1
srcdir = src
testdir = test

####### Makefile Conventions - Utilities

CC ?= clang
CXX ?= clang++
LINK = $(CC)
CHK_DIR_EXISTS = test -d
CHK_FILE_EXISTS = test -f
INSTALL = install
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = $(INSTALL)
SYMLINK = ln -sf
MKDIR = mkdir -p
RM = rm -f
RM_DIR = rm -rf
ifeq ($(PLATFORM_OS), Darwin)
	STRIP = strip -x
else
	STRIP = strip --strip-unneeded
endif

####### Compiler options

DEST = $(DESTDIR)$(libdir)
INCPATH = -Iinclude/c11serializer
override LFLAGS   +=
override CFLAGS   += -pipe -O0 -g3 -Wall -Wextra -pedantic -fmessage-length=0 -std=c11
override CPPFLAGS += -DDEBUG
ifeq ($(CC), gcc)
	override LFLAGS   += -rdynamic
endif

VERSION = 1.0
LIBNAME = libc11serializer
TESTNAME = run_tests

libc11serializer_BUILDDIR = $(CURDIR)/build
libc11serializer_SRCS_FILTER = $(wildcard ${dir}/*.c)
libc11serializer_SRCS = $(foreach dir, ${srcdir}, ${libc11serializer_SRCS_FILTER})
libc11serializer_OBJS = $(addprefix ${libc11serializer_BUILDDIR}/, $(addsuffix .o, $(basename ${libc11serializer_SRCS})))

test_SRCS_FILTER = $(wildcard ${dir}/*.c) $(wildcard ${dir}/*.cpp)
test_SRCS = $(foreach dir, ${testdir}, ${test_SRCS_FILTER})
test_OBJS = $(addprefix ${libc11serializer_BUILDDIR}/, $(addsuffix .o, $(basename ${test_SRCS})))

####### Build rules

.PHONY : libc11serializer test clean

all: libc11serializer test

test: libc11serializer
test: LFLAGS += -L$(libc11serializer_BUILDDIR) -lc11serializer
test: $(test_OBJS)
	@echo 'Building test binary: $(libc11serializer_BUILDDIR)/$(TESTNAME)'
	$(LINK) $(LFLAGS) -o $(libc11serializer_BUILDDIR)/$(TESTNAME) $(test_OBJS)

libc11serializer: CPPFLAGS += -DC11SERIALIZER_LIBRARY
libc11serializer: CFLAGS += -fPIC
libc11serializer: $(libc11serializer_OBJS)
	# @echo "Building static library: $(libc11serializer_BUILDDIR)/$(LIBNAME).a"
	# $(AR) cqv $(libc11serializer_BUILDDIR)/$(LIBNAME).a $^
	# $(RANLIB) $(libc11serializer_BUILDDIR)/$(LIBNAME).a
	# $(SYMLINK) $(libc11serializer_BUILDDIR)/$(LIBNAME).a $(libc11serializer_BUILDDIR)/$(LIBNAME).$(VERSION).a
ifeq ($(PLATFORM_OS), Linux)
	@echo 'Building shared library: $(libc11serializer_BUILDDIR)/$(LIBNAME).so'
	$(LINK) -shared -Wl,-soname,$(LIBNAME).so.1 $(LFLAGS) -o $(libc11serializer_BUILDDIR)/$(LIBNAME).so $^
	$(SYMLINK) $(libc11serializer_BUILDDIR)/$(LIBNAME).so $(libc11serializer_BUILDDIR)/$(LIBNAME).so.$(VERSION)
else ifeq ($(PLATFORM_OS), Darwin)
	@echo 'Building shared library: $(libc11serializer_BUILDDIR)/$(LIBNAME).dylib'
	$(LINK) -headerpad_max_install_names -dynamiclib \
		-flat_namespace -install_name $(LIBNAME).$(VERSION).dylib \
		-current_version $(VERSION) -compatibility_version $(VERSION) \
		$(LFLAGS) -o $(libc11serializer_BUILDDIR)/$(LIBNAME).dylib $^
	$(SYMLINK) $(libc11serializer_BUILDDIR)/$(LIBNAME).dylib $(libc11serializer_BUILDDIR)/$(LIBNAME).$(VERSION).dylib
else ifeq ($(PLATFORM_OS), CYGWIN)
	@echo 'Building shared library: $(libc11serializer_BUILDDIR)/$(LIBNAME).dll'
	$(LINK) -shared $(LFLAGS) -o $(libc11serializer_BUILDDIR)/$(LIBNAME).dll $^
	$(SYMLINK) $(libc11serializer_BUILDDIR)/$(LIBNAME).dll $(libc11serializer_BUILDDIR)/$(LIBNAME).$(VERSION).dll
endif

$(libc11serializer_BUILDDIR)/%.o: %.c
	@echo 'Building file: $<'
	@$(CHK_DIR_EXISTS) $(dir $@) || $(MKDIR) $(dir $@)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCPATH) -o $@ $<

clean:
	$(RM_DIR) $(libc11serializer_BUILDDIR)
