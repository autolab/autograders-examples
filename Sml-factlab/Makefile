# 
# Makefile to manage Fact Lab
# 

# Get the name of the lab directory
LAB = $(notdir $(PWD))

all: handout handout-tarfile

handout:
    # Rebuild the handout directory that students download
	(rm -rf $(LAB)-handout; mkdir $(LAB)-handout)
	cp -p src/Makefile-handout $(LAB)-handout/Makefile
    cp -p src/README-handout $(LAB)-handout/README
    cp -p src/factorial.sml-handout $(LAB)-handout/factorial.sml

handout-tarfile: handout
    # Build *-handout.tar and autograde.tar
    tar cvf $(LAB)-handout.tar $(LAB)-handout
    cp -p $(LAB)-handout.tar autograde.tar
clean:
    # Clean the entire lab directory tree.  Note that you can run
    # "make clean; make" at any time while the lab is live with no
    # adverse effects.
    rm -f *~ *.tar
    (cd src; make clean)
    (cd test-autograder; make clean)
    rm -rf $(LAB)-handout
    rm -f autograde.tar