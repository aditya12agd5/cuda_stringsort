default:
	nvcc -O2 -lrt -lm -o stringSortCvit stringSortCvit.cu
	gcc -o verify sortVerifier.c
sort:
	nvcc -O2 -lrt -lm -o stringSortCvit stringSortCvit.cu
verify:
	gcc -o verify sortVerifier.c
clean:
	rm -rf stringSortCvit
	rm -rf verify
