BEGIN {
	if (ENVIRON["AUPSRC"] == "") {
		print "#############################################################"
		print "# AUPSRC should be defined in environment; $HOME/aup assumed."
		print "#############################################################"
		root = ENVIRON["HOME"] " /aup/"
	}
	else
		root = ENVIRON["AUPSRC"] "/"
}


NR == 1 {
	if (!SUBMAKE) {
		print "# Do not edit this makefile. It was generated automatically "
		print "# with commands like"
		print "#"
		print "#     $ AUPSRC=/aup # (for example)"
		print "#     $ export AUPSRC"
		print "#     $ awk -f $AUPSRC/makebuild.awk $AUPSRC/c1/makebuild.spec >$AUPSRC/c1/Makefile"
		print "#"
		print "# It is incomplete in the sense that there are no header-file"
		print "# dependencies."
		print "#"
		print "# Use the shell-procedure makebuild to run awk. Then compile"
		print "# with a shell-procedure like this one for Linux:"
		print "#"
		print "# 	AUPSRC=/aup # (for example)"
		print "# 	OS=LINUX"
		print "# 	LIBS=\"-lncurses -lutil\""
		print "# 	TLIBS=-pthread"
		print "# 	export OS LIBS TLIBS"
		print "# 	make $2 -f $AUPSRC/$1/Makefile $3"
		print "#"
		printf "\ndefaulttarget: all\n"
	}
}

/^!basepath/ {
	root = $2 "/"
	next
}

/^!include/ {
	system("awk -f " root "makebuild.awk SUBMAKE=1 " root $2)
	next
}

/^!echo/ {
	print substr($0, 7)
	next
}

/^#/ {
	print $0
	next
}

/^[\t ]*$/ {
	next
}

{
	objlist = ""
	if (NF > 1) {
		printf "\n" $1 ":"
		pgmarray[$1] = 1
		if ($2 == "-t") {
			libraries = "$(LIBS) $(TLIBS)"
			pthreadstub = ""
			start = 3
		}
		else {
			libraries = "$(LIBS)"
			pthreadstub = "$(PTHREADSTUB)"
			start = 2
		}
		if (substr($2, 1, 2) == "-D") {
			symbol = " " $2
			start = 3
		}
		else
			symbol = ""
	}
	else
		start = 1
	for (i = start; i <= NF; i++) {
		obj = $i
		sub(/.*\//, "", obj)
		sub(/\.c$/, ".o", obj)
		sub(/\.cpp$/, ".o", obj)
		objlist = objlist " " obj
		objarray[obj] = $i symbol
	}
	if (NF > 1) {
		printf objlist " $(AUPOBJS) " pthreadstub "\n"
		printf "\t$(CCLINK) -o " $1 objlist " $(AUPOBJS) " libraries " " pthreadstub "\n"
	}
}

END {
	for (obj in objarray) {
		split(objarray[obj], obja)
		printf "\n" obj ": " root obja[1] "\n"
		if (obja[1] ~ /\.c$/)
			printf "\t$(CC) $(CFLAGS) " obja[2] " -c -o " obj " " root obja[1] "\n"
		else
			printf "\t$(CCPP) $(CFLAGS) " obja[2] " -c -o " obj " " root obja[1] "\n"
	}
	if (!SUBMAKE) {
		pgmlist = ""
		for (pgm in pgmarray)
			pgmlist = pgmlist " " pgm
		printf "\nall: " pgmlist
		printf "\nclean:\n"
		printf "\trm " pgmlist " *.o\n"
	}
}
