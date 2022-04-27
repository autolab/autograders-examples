# 
# Makefile to manage Fact Lab
# 

all: autograde handout handout-tarfile

handout:
    # Rebuild the handout directory that students download
	(rm -rf factlab-handout; mkdir factlab-handout)
	cp -p src/README-handout factlab-handout/README
	cp -p src/factorial.sml-handout factlab-handout/factorial.sml

.PHONY: autograde
autograde:
    # Rebuild the autograde tar file
	(rm -f autograde.tar; tar cvf autograde.tar autograde)

handout-tarfile: handout
    # Build factlab-handout.tar
	tar cvf factlab-handout.tar factlab-handout

clean:
    # Clean the entire lab directory tree.  Note that you can run
    # "make clean; make" at any time while the lab is live with no
    # adverse effects.
	rm -f *~ *.tar
	# (cd test-autograder; make clean)
	rm -rf factlab-handout
	rm -f autograde.tar