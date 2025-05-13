CFLAGS=-O2 -Wall -target bpf -g

bpf_mark.o:	bpf-mark.c
	clang $(CFLAGS) -c $<

clean:
	rm -f *.o
