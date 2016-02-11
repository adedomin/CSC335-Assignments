DOC=pandoc
DOCFLAGS=
DOCNAME=hw2.pdf
DOCOBJ=hw2.md

PACK=zip
PACKFLAGS=-r
PACKNAME=HW2-dedominica.zip
PACKDIR=../HW2

all: make_doc
	
make_doc:
	$(DOC) $(DOCOBJ) -o $(DOCNAME) $(DOCFLAGS)

remove_doc:
	rm $(DOCNAME)

make_package:
	$(PACK) $(PACKFLAGS) $(PACKNAME) $(PACKDIR)

remove_package:
	rm $(PACKNAME)
