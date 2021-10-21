all:
	tar xvf autograde.tar
	cp sort.js test_submission
	# some languages don’t need compiling and it’s not necessary
	# to have a Makefile for every assessment
	(cd test_submission; make clean; make;)
clean:
	rm -rf *~ test_submission
