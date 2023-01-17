## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project_1

project_1_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonction.c fonction.h \
	hebergement.c hebergement.h \
	capteur.c capteur.h \
	fonction1.c fonction1.h \
	repas.c repas.h

project_1_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

