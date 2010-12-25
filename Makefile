# UPDATE THIS:
CILKHOME=/home/sasho/minime/cilk

fft: fft.cilk
	$(CILKHOME)/bin/cilkc -O2 fft.cilk -o fft

clean:
	$(RM) fft
