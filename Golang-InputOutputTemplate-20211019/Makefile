all:
	tar xvf autograde.tar
	cp fib.go test_assessment
	
	(cd test_assessment; make clean; make; \
		./feed_and_log.sh; \
		./compare_and_grade.sh)

clean:
	rm -rf *~ test_assessment
