#
# Makefile to manage the example Hello Lab
#

# Get the name of the lab directory
LAB = $(notdir $(PWD))

all: handout handout-tarfile

handout:
	# Rebuild the handout directory that students download
	(rm -rf $(LAB)-handout; mkdir $(LAB)-handout)
	cp -rp src/* $(LAB)-handout

handout-tarfile: handout
	# Build *-handout.tar and autograde.tar
	tar cvf autograde.tar $(LAB)-handout
	rm -f $(LAB)-handout/src/tests.c
	rm -f $(LAB)-handout/src/main.c
	rm -f $(LAB)-handout/inc/tests.h
	mv $(LAB)-handout/Makefile-handout $(LAB)-handout/Makefile
	mv $(LAB)-handout/src/main-handout.c $(LAB)-handout/src/main.c
	tar cvf $(LAB)-handout.tar $(LAB)-handout

clean:
	# Clean the entire lab directory tree.  Note that you can run
	# "make clean; make" at any time while the lab is live with no
	# adverse effects.
	-rm -f *~ *.tar
	-(cd src; make clean)
	-(cd test-autograder; make clean)
	-rm -rf $(LAB)-handout
	-rm -f autograde.tar

#
# CAREFULL!!! This will delete all student records in the logfile and
# in the handin directory. Don't run this once the lab has started.
# Use it to clean the directory when you are starting a new version
# of the lab from scratch, or when you are debugging the lab prior
# to releasing it to the students.
#
cleanallfiles:
	# Reset the lab from scratch.
	make clean
	rm -f log.txt
	rm -rf handin/*