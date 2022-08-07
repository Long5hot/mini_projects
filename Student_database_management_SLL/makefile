all = main.o add_record.o display_record.o save.o

gcc = cc

outfile = $(all)
	$(gcc)	$(all)	-outfile

main.o : main.c
	$(gcc) -c main.c

add_record.o : add_record.c
	$(gcc) -c add_record.c

save.o : save.c
	$(gcc) -c save.c 

display_record.o : display_record.c 
	$(gcc) -c display_record.c 

clean : @rm *.o 
	@echo "Cleaning Up"
