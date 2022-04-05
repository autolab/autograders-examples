LAB = $(notdir $(PWD))

all: clean handout autograde

handout:
	(rm -rf $(LAB)-handout; mkdir $(LAB)-handout)
	cp -p src/cat.bf-handout $(LAB)-handout/cat.bf
	tar cvf $(LAB)-handout.tar $(LAB)-handout

autograde:
	(rm -rf $(LAB)-autograde; mkdir $(LAB)-autograde)
	cp -p src/cat-sol.bf $(LAB)-autograde
	cp -p src/driver.py $(LAB)-autograde
	cp -pR src/inputs $(LAB)-autograde
	tar cvf autograde.tar $(LAB)-autograde

clean:
	rm -f *~ *.tar
	rm -rf $(LAB)-handout
	rm -rf $(LAB)-autograde