redact-o-matic: redactMain.o strManip.o fileUtils.o
	c99 -o redact-o-matic redactMain.o strManip.o fileUtils.o

redactMain.o: redactMain.c strManip.h fileUtils.h
	c99 -c -g redactMain.c

strManip.o: strManip.c strManip.h
	c99 -c -g strManip.c

clean:
	rm redactMain.o strManip.o redact-o-matic