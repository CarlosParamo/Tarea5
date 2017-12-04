Results_hw5.pdf : Resultados_hw5.tex  plots.png
	pdflatex $< && rm *.aux *.log

plots.png : Plots.py
	python $<

$dataout.dat : a.out
	./a.out

a.out : CurvaRotacion.c
	gcc -lm -g CurvaRotacion.c

clean :
	rm a.out plots.png dataout.dat
