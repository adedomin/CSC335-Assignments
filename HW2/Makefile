DOC=pandoc
DOCFLAGS=
DOCNAME=hw2.pdf
DOCOBJ=hw2.md

PACK=zip
PACKFLAGS=-r
PACKNAME=HW2-dedominica.zip
PACKDIR=HW2/

all: doc
	
doc:
	$(DOC) $(DOCOBJ) -o $(DOCNAME) $(DOCFLAGS)

remove_doc:
	rm $(DOCNAME)

package: doc
	mkdir $(PACKDIR)
	cp $(DOCNAME) $(DOCOBJ) ./Makefile ./HW2/
	$(PACK) $(PACKFLAGS) $(PACKNAME) $(PACKDIR)
	rm -rf $(PACKDIR) $(DOCNAME)

remove_package:
	rm $(PACKNAME)
